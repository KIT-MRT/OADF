#ifndef FTR_H
#define FTR_H

#define _USE_MATH_DEFINES
//#define RUN_ON_R5
#define RUN_ON_LINUX



#include "../r5_common/common_functions.h"
#include "../r5_common/common_parameters.h"

#include "Lib/ALGLIB/stdafx.h"
#include "Lib/ALGLIB/interpolation.h"
#include <iostream>
#include <algorithm>
#include <complex>
#include <math.h>
#include <stdint.h>

#include "../unicar-definitions/UNICAR_definitions.h"

#include "Lib/LowPassFilter/LowPassFilter.hpp"
#include "FTRparameter.h"
#include "ftr_definitions.h"
#include "ringbuffer.hpp"
#include "ftr_interface.h"

#include "GeographicLib/NormalGravity.hpp"
#include "GeographicLib/Math.hpp"
#include "GeographicLib/LocalCartesian.hpp"
#include "GeographicLib/Geocentric.hpp"

// Linux mutex
#ifdef RUN_ON_LINUX
#include <mutex>
#endif // RUN_ON_LINUX

// Time synchronization
#ifdef RUN_ON_R5
#include "ptpd.h"
#include "sleep.h"
#include "time.h"
#endif // RUN_ON_R5


namespace ftr {

	// Tag definitions for interface assignments
	static const char tagVR[] = "VR";
	static const char tagVL[] = "VL";
	static const char tagHR[] = "HR";
	static const char tagHL[] = "HL";
	static const char tagFTR[] = "FTR";


	// Array copy function
	template <typename T>
	void array2array(T array[], uint32_t array_size, T ext_array[]) {

		for (uint32_t i = 0; i<array_size; i++) {

			ext_array[i] = array[i];

		}
	}


	// Calculate difference between two angles and account for wraparounds
	template <typename T>
	T angleDiff(T angle1, T angle2) {
		T diff = angle1 - angle2;

		while (std::abs(diff) > M_PI) {
			if (diff > M_PI) {
				diff = diff - 2 * M_PI;
			}
			if (diff < -M_PI) {
				diff = diff + 2 * M_PI;
			}
		}

		return diff;
	}


	/**
	 * convert [x, y] in cartesian coordinate to [r, theta] in polar coordinate
	 *
	 * @param x:        x in cartesian coordinate
	 * @param y:        y in cartesian coordinate
	 * @param r:        radiance in polar coordinate
	 * @param theta:    Theta in polar coordinate, unit: rad
	 */
	template <typename T>
	void cartesian2polar(T &x, T &y, T &r, T &theta) {

		std::complex<T>cartesian(x, y);
		r = std::abs(cartesian);
		theta = std::arg(cartesian);

	}


	/**
	 * Polar to catesian [r, theta] to [x, y]
	 *
	 * @param r
	 * @param theta: angle in rad
	 * @param x
	 * @param y
	 */
	template <typename T>
	void polar2cartesian(T &r, T &theta, T &x, T &y) {

		std::complex<T>cartesian = std::polar(r, theta);
		x = cartesian.real();
		y = cartesian.imag();

	}


	/**
	 * limits in between [lower, upper]
	 *
	 * @param in:       input value
	 * @param upper:    up boundary
	 * @param lower:    low boundary
	 * @return value in [lower, upper]
	 */
	template <typename T>
	T saturation(T &in, T upper, T lower) {
		return std::max(lower, std::min(in, upper));
	}



	/**
	 * Interpolate the local traj point from trajENU according the time in unicarState
	 *
	 * @param traj:             traj trajectory for interpolation
	 * @param state:            vehicle state in current time
	 * @param traj_int:       Extract trajectory information from trajENU, only contains necessary information for FTR(...)
	 */
	void trajInterpolation(trajENU_array& traj, trajInterpolated& traj_int);


	/**
	 * Main calculation for Fahrzeug Trajectory Regelung
	 * @param traj:             Trajectory in ENU system
	 * @param state:            Vehicle state in current time step
	 * @param DMValues:         Dynamic movement value: pedal, break, steering
	 */
	void FTR(trajENU_array& traj, unicarState& state, setpointDM& DMValues, poseOffset& pose_Offset, controlDiff& controlDiff, dynState& dyn_StateVL, dynState& dyn_StateVR, dynState& dyn_StateHL, dynState& dyn_StateHR, trajInterpolated &traj_int);


	/**
	 * Calculate the required wheel direction without the influence of lateral force from trajectory and
	 * determinate the vehicle moving direction (forward or backward)
	 *
	 * @param traj:             local traj that extracts from trajENU
	 * @param state:            state contains the vehicle information, such as pos, vel and acc
	 * @param velDir:           an array saved wheel direction in rad, the last entry is the mean of 4 wheels
	 */
	void wheelVel(trajInterpolated& traj, unicarState& state, double velDir[4], controlDiff& controlDiff);


	/**
	 * Vehicle controller, involves PID controller and look ahead controller.
	 * In this controller we will calculate the required force according to given traj point and the vehicle state
	 *
	 * @param traj:             local trajectory that extracts from trajENU according to current time stamp in UnicarState
	 * @param state:            vehicle state, pos, vel and acc etc...
	 * @param forceDemand:      required force to track trajInterpolated
	 */
	void controller(trajInterpolated& traj, unicarState& state, forces& forceDemand, controlDiff& controlDiff);


	/**
	 * Part of controller, responses for PID control
	 * @param traj:             local trajectory that extracts from trajENU according to current time stamp in UnicarState
	 * @param state:            vehicle state, pos, vel and acc etc...
	 * @param forceDemandSF:    required force from PID controller, vehicle coordinate
	 */
	void stateFeedback(trajInterpolated& traj, unicarState& state, forces& forceDemandSF, controlDiff& controlDiff);


	/**
	 * Part of controller (look ahead controller), calculate the force demand according to trajectory point in the fucture
	 * (saved in trajInterpolated.la)
	 *
	 * @param traj:             local trajectory that extracts from trajENU according to current time stamp in UnicarState
	 * @param state:            vehicle state, pos, vel and acc etc...
	 * @param forceDemandFF:    required force from look ahead controller
	 */
	void feedForward(trajInterpolated& traj, forces& forceDemandFF);


	/**
	 * allocate the force demand of the whole vehicle to 4 wheels
	 *
	 * @param forceDemand:      Force demand of the whole vehicle (vehicle coordinate)
	 * @param velDir:           Wheel direction without the consideration of wheel force
	 * @param wheelForce:       Required force in 4 wheels
	 */
	void controlAlloc(forces& forceDemand, wheelForces& wheelForce, trajInterpolated& traj, unicarState& state);


	/**
	 * calculate DMvalues from wheelForce and velDir, traj and state only provide some parameters
	 *
	 * @param wheelForce:       allocated force in 4 wheels
	 * @param traj:             local traj, we only need flags: standstill, run_direction and side parking
	 * @param state:            vehicle state, we only need wheel dynamic radius
	 * @param velDir:           wheel direction without the consideration of lateral force
	 * @param DMValues:         dynamic movement values, such as pedal, break and steering
	 */
	void setpointCalc(wheelForces& wheelForce, trajInterpolated& traj, unicarState& state, double velDir[4], setpointDM& DMValues, dynState& dyn_StateVL, dynState& dyn_StateVR, dynState& dyn_StateHL, dynState& dyn_StateHR);


	/**
	 * dynamic module for single wheel, calculates DMvalue for each wheel
	 *
	 * @param wheelForce:       allocated force in 4 wheels
	 * @param state:            vehicle state, we only need wheel dynamic radius
	 * @param velDir:           wheel direction without the consideration of lateral force
	 * @param DMValues:         dynamic movement values, such as pedal, break and steering
	 * @param DMnumber:         indicate which wheel we are using
	 * @param standstill:       1 for standstill, 0 for moving
	 * @param run_direction:    1 for forward, -1 for backward
	 */
	void dynModule(wheelForces& wheelForce, unicarState& state, double velDir[4], setpointDM& DMValues, int& DMnumber, trajInterpolated& traj, dynState& dyn_StateVL, dynState& dyn_StateVR, dynState& dyn_StateHL, dynState& dyn_StateHR, float total_velocity);


	/**
	 * calculate slop resistance
	 *
	 * @param traj:             local trajectory that extracts from trajENU according to current time stamp in UnicarState
	 * @param state:            vehicle state, pos, vel and acc etc...
	 * @param force_slope:      Required force to overcome slop resistance
	 */
	void slopRes(trajInterpolated& traj, forces& force_slope);


	/**
	 * driving resistance such as wind resistance
	 * @param state:            vehicle state, pos, vel and acc etc...
	 * @param F_x:              required force to overcome driving resistance
	 */
	void drivingRes(trajInterpolated& traj, forces& force_drivRes);


	/**
	 * transform the global polar coordinate to vehicle cartesian coordinate (local coordinate depends on reference angle)
	 *
	 * @param velAngleRad:      theta in global polar coordinate
	 * @param velMag:           r in global polar coordinate
	 * @param angle:            reference angle
	 * @param velX:             x in vehicle coordinate
	 * @param velY:             y in vehicle coordinate
	 */
	void rotateCartesianCoordinateSystem(double& initLon, double& initLat, double& rotAngle, double& resLon, double& resLat);


	/**
	 * Perform 2D coordinate transformation by simple rotation.
	 *
	 * @param initLon:       Initial longitudinal value
	 * @param initLat:       Initial lateral value
	 * @param rotAngle:      Rotation angle between both coordinate systems
	 * @param resLon:        Resulting longitudinal value
	 * @param resLat:        Resulting lateral value
	 */
	void rotatePolar2Cartesian(double& initAngle, double& initMag, double& rotAngle, double& resLon, double& resLat);


	/**
	 * dynamic module for side parking
	 *
	 * @param wheelForce:       allocated force in 4 wheels
	 * @param state:            vehicle state, we only need wheel dynamic radius
	 * @param velDir:           wheel direction without the consideration of lateral force
	 * @param DMValues:         dynamic movement values, such as pedal, break and steering
	 * @param DMnumber:         indicate which wheel we are using
	 * @param standstill:       1 for standstill, 0 for moving
	 * @param run_direction:    1 for left moving, -1 for right moving
	 */
	void dynModuleSideParking(wheelForces& wheelForce, unicarState& state, double velDir[4], setpointDM& DMValues, int& DMnumber, trajInterpolated& traj, dynState& dyn_StateVL, dynState& dyn_StateVR, dynState& dyn_StateHL, dynState& dyn_StateHR, float total_velocity);


	/**
	 * Transform current position of vehicle from GCS to ENU coordinate system, based on planning pose of current trajectory
	 *
	 * @param traj:				Current target trajectory
	 * @param state:			Vehicle state
	 */
	void stateGCS2ENU(trajENU_array& traj, unicarState& state);


	/**
	 * Perform offset correction of current state by comparison with planning pose within target trajectory
	 *
	 * @param traj:				Current target trajectory
	 * @param state:			Vehicle state
	 */
	void offsetCorrection(unicarState& state, poseOffset& offset);


	/**
	 * Calculate pose offset of current state by comparison with planning pose within target trajectory
	 *
	 * @param traj:				Current target trajectory
	 * @param state:			Vehicle state
	 */
	void offsetCalculation(trajENU_array& traj, offsetState& state, poseOffset& offset);


	/**
	 * Calculate pose offset of current state by comparison with planning pose within target trajectory
	 *
	 * @param traj:				Current target trajectory
	 * @param state:			Vehicle state
	 */
	void getStateFromBuffer(offsetState& stateForCorrection, trajENU_array& traj, unicarState& state);


	// Update the pose offset by finding a match between the trajectory planning pose and the FZS state at the same time
	void updatePoseOffset(trajENU_array& ext_trajENU, offsetState& stateForCorrection, poseOffset& pose_Offset, unicarState& state);


	// Unwrap angles (continuous angles without jumps)
	void unwrap(double arr_orig[], int size_orig);


	// Wrap angles (Jump at -pi/pi)
	void wrap(double &angle);

	// Calculate steering limits based on current speed and lateral acceleration limits
	void calcSteeringLimits(unicarState& state, trajInterpolated& traj, float& delta_max,  float& delta_min);


	GeographicLib::Geocentric initgrs80ell();


}

#endif
