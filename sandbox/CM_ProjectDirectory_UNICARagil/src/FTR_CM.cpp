#include "FTR_CM.h"


void Vector2Array(trajENU& traj_ENU, trajENU_array& traj_ENU_array) {

	std::copy(traj_ENU.acc_enu_angle_rad.begin(), traj_ENU.acc_enu_angle_rad.end(), traj_ENU_array.acc_enu_angle_rad);
	std::copy(traj_ENU.tai_seconds.begin(), traj_ENU.tai_seconds.end(), traj_ENU_array.tai_seconds);
	std::copy(traj_ENU.tai_nanoseconds.begin(), traj_ENU.tai_nanoseconds.end(), traj_ENU_array.tai_nanoseconds);
	std::copy(traj_ENU.standstill.begin(), traj_ENU.standstill.end(), traj_ENU_array.standstill);
	std::copy(traj_ENU.parking.begin(), traj_ENU.parking.end(), traj_ENU_array.parking);
	std::copy(traj_ENU.pos_enu_east_m.begin(), traj_ENU.pos_enu_east_m.end(), traj_ENU_array.pos_enu_east_m);
	std::copy(traj_ENU.pos_enu_north_m.begin(), traj_ENU.pos_enu_north_m.end(), traj_ENU_array.pos_enu_north_m);
	std::copy(traj_ENU.slope_long.begin(), traj_ENU.slope_long.end(), traj_ENU_array.slope_long);
	std::copy(traj_ENU.slope_lat.begin(), traj_ENU.slope_lat.end(), traj_ENU_array.slope_lat);
	std::copy(traj_ENU.vel_enu_mag_m_s.begin(), traj_ENU.vel_enu_mag_m_s.end(), traj_ENU_array.vel_enu_mag_m_s);
	std::copy(traj_ENU.vel_enu_angle_rad.begin(), traj_ENU.vel_enu_angle_rad.end(), traj_ENU_array.vel_enu_angle_rad);
	std::copy(traj_ENU.acc_enu_mag_m_s2.begin(), traj_ENU.acc_enu_mag_m_s2.end(), traj_ENU_array.acc_enu_mag_m_s2);
	std::copy(traj_ENU.ori_enu_psi_rad.begin(), traj_ENU.ori_enu_psi_rad.end(), traj_ENU_array.ori_enu_psi_rad);
	std::copy(traj_ENU.ori_vel_enu_psi_rad_s.begin(), traj_ENU.ori_vel_enu_psi_rad_s.end(), traj_ENU_array.ori_vel_enu_psi_rad_s);
	std::copy(traj_ENU.ori_acc_enu_psi_rad_s2.begin(), traj_ENU.ori_acc_enu_psi_rad_s2.end(), traj_ENU_array.ori_acc_enu_psi_rad_s2);
	traj_ENU_array.send_tai_seconds = traj_ENU.send_tai_seconds;
	traj_ENU_array.send_tai_nanoseconds = traj_ENU.send_tai_nanoseconds;
	traj_ENU_array.plan_pos_ell_lat_rad = traj_ENU.plan_pos_ell_lat_rad;
	traj_ENU_array.plan_pos_ell_lon_rad = traj_ENU.plan_pos_ell_lon_rad;
	traj_ENU_array.plan_pos_ell_h_m = traj_ENU.plan_pos_ell_h_m;
	traj_ENU_array.plan_ori_enu_psi_rad = traj_ENU.plan_ori_enu_psi_rad;
	traj_ENU_array.plan_tai_seconds = traj_ENU.plan_tai_seconds;
	traj_ENU_array.plan_tai_nanoseconds = traj_ENU.plan_tai_nanoseconds;
	traj_ENU_array.use_atlatec = traj_ENU.use_atlatec;
	traj_ENU_array.use_previous_trj = traj_ENU.use_previous_trj;


}


// Function to write the setpoint actuator values to the corresponding UAQ
void writeDM(setpointDM& DMValues) {

		// Check for sideways parking
		// Normal driving:
		if (DMValues.sideways_parking_active == 0) {

			// Allow front and backwards driving when standing still
			if (std::abs(Vehicle.PoI_Vel_1[0]) <= 0.01) {
				DynMod.Drive.setpoint_Trq_1 = DMValues.drive.trq_DM_1 * ftr::gear_ratio_drive;
				DynMod.Drive.setpoint_Trq_2 = DMValues.drive.trq_DM_2 * ftr::gear_ratio_drive;
				DynMod.Drive.setpoint_Trq_3 = DMValues.drive.trq_DM_3 * ftr::gear_ratio_drive;
				DynMod.Drive.setpoint_Trq_4 = DMValues.drive.trq_DM_4 * ftr::gear_ratio_drive;
			}
			// No change of direction during driving
			else {

				// Front left
				if (DMValues.drive.trq_DM_1 * ftr_cm::sgn(Vehicle.PoI_Vel_1[0]) >= 0) {

					DynMod.Drive.setpoint_Trq_1 = DMValues.drive.trq_DM_1 * ftr::gear_ratio_drive;
					DynMod.Brk.setpoint_Trq_1 = 0;

				}
				else {

					DynMod.Drive.setpoint_Trq_1 = 0;
					DynMod.Brk.setpoint_Trq_1 = std::abs(DMValues.drive.trq_DM_1) * ftr::gear_ratio_drive;
				}

				// Front right
				if (DMValues.drive.trq_DM_2 * ftr_cm::sgn(Vehicle.PoI_Vel_1[0]) >= 0) {

					DynMod.Drive.setpoint_Trq_2 = DMValues.drive.trq_DM_2 * ftr::gear_ratio_drive;
					DynMod.Brk.setpoint_Trq_2 = 0;

				}
				else {

					DynMod.Drive.setpoint_Trq_2 = 0;
					DynMod.Brk.setpoint_Trq_2 = std::abs(DMValues.drive.trq_DM_2) * ftr::gear_ratio_drive;
				}

				// Rear left
				if (DMValues.drive.trq_DM_3 * ftr_cm::sgn(Vehicle.PoI_Vel_1[0]) >= 0) {

					DynMod.Drive.setpoint_Trq_3 = DMValues.drive.trq_DM_3 * ftr::gear_ratio_drive;
					DynMod.Brk.setpoint_Trq_3 = 0;

				}
				else {

					DynMod.Drive.setpoint_Trq_3 = 0;
					DynMod.Brk.setpoint_Trq_3 = std::abs(DMValues.drive.trq_DM_3) * ftr::gear_ratio_drive;
				}

				// Rear right
				if (DMValues.drive.trq_DM_4 * ftr_cm::sgn(Vehicle.PoI_Vel_1[0]) >= 0) {

					DynMod.Drive.setpoint_Trq_4 = DMValues.drive.trq_DM_4 * ftr::gear_ratio_drive;
					DynMod.Brk.setpoint_Trq_4 = 0;

				}
				else {

					DynMod.Drive.setpoint_Trq_4 = 0;
					DynMod.Brk.setpoint_Trq_4 = std::abs(DMValues.drive.trq_DM_4) * ftr::gear_ratio_drive;
				}
			}

		}

		// Sideways parking:
		else {

			// Allow front and backwards driving when standing still
			if (std::abs(Vehicle.PoI_Vel_1[1]) <= 0.01) {
				DynMod.Drive.setpoint_Trq_1 = DMValues.drive.trq_DM_1 * ftr::gear_ratio_drive;
				DynMod.Drive.setpoint_Trq_2 = DMValues.drive.trq_DM_2 * ftr::gear_ratio_drive;
				DynMod.Drive.setpoint_Trq_3 = DMValues.drive.trq_DM_3 * ftr::gear_ratio_drive;
				DynMod.Drive.setpoint_Trq_4 = DMValues.drive.trq_DM_4 * ftr::gear_ratio_drive;
			}
			// No change of direction during driving
			else {

				// Front left
				if (DMValues.drive.trq_DM_1 * ftr_cm::sgn(Vehicle.PoI_Vel_1[1]) >= 0) {

					DynMod.Drive.setpoint_Trq_1 = DMValues.drive.trq_DM_1 * ftr::gear_ratio_drive;
					DynMod.Brk.setpoint_Trq_1 = 0;

				}
				else {

					DynMod.Drive.setpoint_Trq_1 = 0;
					DynMod.Brk.setpoint_Trq_1 = std::abs(DMValues.drive.trq_DM_1) * ftr::gear_ratio_drive;
				}

				// Front right
				if (DMValues.drive.trq_DM_2 * ftr_cm::sgn(Vehicle.PoI_Vel_1[1]) >= 0) {

					DynMod.Drive.setpoint_Trq_2 = 0;
					DynMod.Brk.setpoint_Trq_2 = std::abs(DMValues.drive.trq_DM_2) * ftr::gear_ratio_drive;

				}
				else {

					DynMod.Drive.setpoint_Trq_2 = DMValues.drive.trq_DM_2 * ftr::gear_ratio_drive;
					DynMod.Brk.setpoint_Trq_2 = 0;

				}

				// Rear left
				if (DMValues.drive.trq_DM_3 * ftr_cm::sgn(Vehicle.PoI_Vel_1[1]) >= 0) {

					DynMod.Drive.setpoint_Trq_3 = 0;
					DynMod.Brk.setpoint_Trq_3 = std::abs(DMValues.drive.trq_DM_3) * ftr::gear_ratio_drive;

				}
				else {

					DynMod.Drive.setpoint_Trq_3 = DMValues.drive.trq_DM_3 * ftr::gear_ratio_drive;
					DynMod.Brk.setpoint_Trq_3 = 0;

				}

				// Rear right
				if (DMValues.drive.trq_DM_4 * ftr_cm::sgn(Vehicle.PoI_Vel_1[1]) >= 0) {

					DynMod.Drive.setpoint_Trq_4 = DMValues.drive.trq_DM_4 * ftr::gear_ratio_drive;
					DynMod.Brk.setpoint_Trq_4 = 0;

				}
				else {

					DynMod.Drive.setpoint_Trq_4 = 0;
					DynMod.Brk.setpoint_Trq_4 = std::abs(DMValues.drive.trq_DM_4) * ftr::gear_ratio_drive;
				}

			}

		}


	// Steer commands
	DynMod.Steer.setpoint_Angle_1 = DMValues.steering.angle_DM_1;
	DynMod.Steer.setpoint_Angle_2 = DMValues.steering.angle_DM_2;
	DynMod.Steer.setpoint_Angle_3 = DMValues.steering.angle_DM_3;
	DynMod.Steer.setpoint_Angle_4 = DMValues.steering.angle_DM_4;

	// Rotation limits for electric drives (static value as of yet)
	DynMod.Drive.RotLim_1 = 200;
	DynMod.Drive.RotLim_2 = 200;
	DynMod.Drive.RotLim_3 = 200;
	DynMod.Drive.RotLim_4 = 200;

}


/**
 * read state from CM
 * @param state: state of vehicle (unprocessed)
 */
void getState(unicarState& state) {

	state.pos.lat = Vehicle.PoI_GCS.Lat;
	state.pos.lon = Vehicle.PoI_GCS.Long;
	state.pos.h = Vehicle.PoI_GCS.Elev;
	state.pos.yaw = Vehicle.Yaw;

	state.vel.east = Vehicle.PoI_Vel[0];
	state.vel.north = Vehicle.PoI_Vel[1];
	state.vel.yaw = Vehicle.YawRate;

	state.acc.east = Vehicle.PoI_Acc[0];
	state.acc.north = Vehicle.PoI_Acc[1];


	double gpssow = GNavSensor.Receiver.Time_secsOfWeek;
	uint16_t gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

	GPStoTAI(gpsweek, gpssow, state.misc.time.tai_seconds, state.misc.time.tai_nanoseconds);

	ftr_global::curr_time = state.misc.time.tai_seconds + state.misc.time.tai_nanoseconds / 1e9;
}


void stateConvertFTR(unicarState& state, struct_FZS& stateFZS) {

	state.misc.frame = stateFZS.frame_counter;
	state.misc.time.tai_nanoseconds = stateFZS.tai_nanoseconds;
	state.misc.time.tai_seconds = stateFZS.tai_seconds;
	state.misc.status = stateFZS.status;
	state.pos.lat = stateFZS.pos_ell_lat_rad;
	state.pos.lon = stateFZS.pos_ell_lon_rad;
	state.pos.h = stateFZS.pos_ell_h_m;
	state.pos.yaw = stateFZS.rpy_rad[2];
	state.vel.east = stateFZS.vel_enu_m_s[0];
	state.vel.north = stateFZS.vel_enu_m_s[1];
	state.vel.yaw = stateFZS.omg_enu_rad_s[2];
	state.acc.east = stateFZS.acc_enu_m_s2[0];
	state.acc.north = stateFZS.acc_enu_m_s2[1];
	state.misc.time.tai_seconds = stateFZS.tai_seconds;
	state.misc.time.tai_nanoseconds = stateFZS.tai_nanoseconds;

}


void offsetCorrectionCM(unicarState& state, trajENU_array& traj_ENU_array, offsetState& stateForCorrection) {

	offsetState ext_offsetState;

	// Fill ext_offsetState and add data to ring buffer
	ext_offsetState.h = state.pos.h;
	ext_offsetState.lat = state.pos.lat;
	ext_offsetState.lon = state.pos.lon;
	ext_offsetState.yaw = state.pos.yaw;
	ext_offsetState.time.tai_seconds = state.misc.time.tai_seconds;
	ext_offsetState.time.tai_nanoseconds = state.misc.time.tai_nanoseconds;

	ftr_interface::tx_offsetStateBuffer(ext_offsetState);

	bool ext_calculateOffset;
	ftr_interface::rx_calculateOffset(ext_calculateOffset);

	// Calculate new offset, if trajectory is received that is planned based on actual vehicle pose
	if (ext_calculateOffset && traj_ENU_array.use_previous_trj == 0) {
		ftr::updatePoseOffset(traj_ENU_array, stateForCorrection, pose_Offset, state);
	}
	   
}


// Add drift to state to simulate position error of FZS
void addDrift(unicarState& state, long Cycles_No_CM) {
	
	// Position drift in rad per ms
	double basic_drift = 1e-11;

	state.pos.lat += basic_drift * Cycles_No_CM;
	state.pos.lon += basic_drift * Cycles_No_CM;

	// Orientation drift in rad per ms
	basic_drift *= 1e6;
	state.pos.yaw += basic_drift * Cycles_No_CM;

	double tmp_vel_east = state.vel.east;
	double tmp_vel_north = state.vel.north;
	double tmp_acc_east = state.acc.east;
	double tmp_acc_north = state.acc.north;
	double tmp_yaw_drift = basic_drift * Cycles_No_CM;

	ftr::rotateCartesianCoordinateSystem(tmp_vel_east, tmp_vel_north, tmp_yaw_drift, state.vel.east, state.vel.north);
	ftr::rotateCartesianCoordinateSystem(tmp_acc_east, tmp_acc_north, tmp_yaw_drift, state.acc.east, state.acc.north);
}


// Get dynamics module state from CM 
// All torques from CM are on motor side so gearbox is considered to provide wheel side values to FTR
void getDynState(dynState& dyn_StateVL, dynState& dyn_StateVR, dynState& dyn_StateHL, dynState& dyn_StateHR) {

	dyn_StateVL.brake_torque_Nm = DynMod.Brk.Trq_1 * 1 / ftr::gear_ratio_drive;
	dyn_StateVL.continuous_drive_torque_Nm = std::abs(DynMod.Drive.TrqMax_1) * 1/ftr::gear_ratio_drive;
	dyn_StateVL.drive_speed_rad_s = 0;
	dyn_StateVL.drive_torque_Nm = DynMod.Drive.Trq_1 * 1 / ftr::gear_ratio_drive;
	dyn_StateVL.frame_counter = 0;
	dyn_StateVL.max_brake_torque_Nm = std::abs(DynMod.Brk.TrqMax_1) * 1 / ftr::gear_ratio_drive;
	dyn_StateVL.max_steering_angle_velocity_rad_s = 0;
	dyn_StateVL.steering_angle_rad = 0;
	dyn_StateVL.steering_torque_nm = 0;
	dyn_StateVL.tai_nanoseconds = 0;
	dyn_StateVL.tai_seconds = 0;
	dyn_StateVL.max_drive_torque_Nm = std::abs(DynMod.Drive.TrqPeakMax_1) * 1 / ftr::gear_ratio_drive;
	dyn_StateVL.max_regen_brake_torque_Nm = std::abs(DynMod.Drive.TrqPeakMax_1) * 1 / ftr::gear_ratio_drive;


	dyn_StateVR.brake_torque_Nm = DynMod.Brk.Trq_2 * 1 / ftr::gear_ratio_drive;
	dyn_StateVR.continuous_drive_torque_Nm = std::abs(DynMod.Drive.TrqMax_2) * 1 / ftr::gear_ratio_drive;
	dyn_StateVR.drive_speed_rad_s = 0;
	dyn_StateVR.drive_torque_Nm = DynMod.Drive.Trq_2 * 1 / ftr::gear_ratio_drive;
	dyn_StateVR.frame_counter = 0;
	dyn_StateVR.max_brake_torque_Nm = std::abs(DynMod.Brk.TrqMax_2) * 1 / ftr::gear_ratio_drive;
	dyn_StateVR.max_steering_angle_velocity_rad_s = 0;
	dyn_StateVR.steering_angle_rad = 0;
	dyn_StateVR.steering_torque_nm = 0;
	dyn_StateVR.tai_nanoseconds = 0;
	dyn_StateVR.tai_seconds = 0;
	dyn_StateVR.max_drive_torque_Nm = std::abs(DynMod.Drive.TrqPeakMax_2) * 1 / ftr::gear_ratio_drive;
	dyn_StateVR.max_regen_brake_torque_Nm = std::abs(DynMod.Drive.TrqPeakMax_2) * 1 / ftr::gear_ratio_drive;


	dyn_StateHL.brake_torque_Nm = DynMod.Brk.Trq_3 * 1 / ftr::gear_ratio_drive;
	dyn_StateHL.continuous_drive_torque_Nm = std::abs(DynMod.Drive.TrqMax_3) * 1 / ftr::gear_ratio_drive;
	dyn_StateHL.drive_speed_rad_s = 0;
	dyn_StateHL.drive_torque_Nm = DynMod.Drive.Trq_3 * 1 / ftr::gear_ratio_drive;
	dyn_StateHL.frame_counter = 0;
	dyn_StateHL.max_brake_torque_Nm = std::abs(DynMod.Brk.TrqMax_3) * 1 / ftr::gear_ratio_drive;
	dyn_StateHL.max_steering_angle_velocity_rad_s = 0;
	dyn_StateHL.steering_angle_rad = 0;
	dyn_StateHL.steering_torque_nm = 0;
	dyn_StateHL.tai_nanoseconds = 0;
	dyn_StateHL.tai_seconds = 0;
	dyn_StateHL.max_drive_torque_Nm = std::abs(DynMod.Drive.TrqPeakMax_3) * 1 / ftr::gear_ratio_drive;
	dyn_StateHL.max_regen_brake_torque_Nm = std::abs(DynMod.Drive.TrqPeakMax_3) * 1 / ftr::gear_ratio_drive;


	dyn_StateHR.brake_torque_Nm = DynMod.Brk.Trq_4 * 1 / ftr::gear_ratio_drive;
	dyn_StateHR.continuous_drive_torque_Nm = std::abs(DynMod.Drive.TrqMax_4) * 1 / ftr::gear_ratio_drive;
	dyn_StateHR.drive_speed_rad_s = 0;
	dyn_StateHR.drive_torque_Nm = DynMod.Drive.Trq_4 * 1 / ftr::gear_ratio_drive;
	dyn_StateHR.frame_counter = 0;
	dyn_StateHR.max_brake_torque_Nm = std::abs(DynMod.Brk.TrqMax_4) * 1 / ftr::gear_ratio_drive;
	dyn_StateHR.max_steering_angle_velocity_rad_s = 0;
	dyn_StateHR.steering_angle_rad = 0;
	dyn_StateHR.steering_torque_nm = 0;
	dyn_StateHR.tai_nanoseconds = 0;
	dyn_StateHR.tai_seconds = 0;
	dyn_StateHR.max_drive_torque_Nm = std::abs(DynMod.Drive.TrqPeakMax_4) * 1 / ftr::gear_ratio_drive;
	dyn_StateHR.max_regen_brake_torque_Nm = std::abs(DynMod.Drive.TrqPeakMax_4) * 1 / ftr::gear_ratio_drive;


}


//Legacy code for offset correction, will be removed

/**
* Add drift to RawState
* @param raw state:    raw vehicle state
* @param time:     running time
*/
//void addDrift(oc::RawState& raw_state, long time) {
//	
//	// Position drift in rad per ms
//	double basic_drift = 1e-11;
//
//	raw_state.pos.lat += basic_drift * time;
//	raw_state.pos.lon += basic_drift * time;
//
//	// Orientation drift in rad per ms
//	basic_drift *= 1e6;
//	raw_state.pos.yaw += basic_drift * time;
//
//	oc::rotation(raw_state.vel.east, raw_state.vel.north, - basic_drift * time);
//	oc::rotation(raw_state.acc.east, raw_state.acc.north, - basic_drift * time);
//
//}


   /**
* read unicarState from RawState and CM
* @param raw_state: state with offset
* @param state: unicarState for FTR
*/
//void getState(oc::RawState& raw_state, unicarState& state) {
//
//	//Output current CarMaker PoI to console for debugging purposes
//	//std::cout<< "x: "<< Vehicle.Cfg.PoI_Pos_1[0] << " y: " << Vehicle.Cfg.PoI_Pos_1[1] <<" z: " << Vehicle.Cfg.PoI_Pos_1[2] << std::endl;
//
//	// Pose
//	state.pos.east = raw_state.pos.east;
//	state.pos.north = raw_state.pos.north;
//	state.pos.yaw = Vehicle.Yaw;
//
//	// Velocity
//	state.vel.east = raw_state.vel.east;
//	state.vel.north = raw_state.vel.north;
//	state.vel.yaw = raw_state.vel.yaw;
//
//	// Acceleration
//	state.acc.east = raw_state.acc.east;
//	state.acc.north = raw_state.acc.north;
//
//	// Time
//	state.misc.time.tai_nanoseconds = raw_state.time.tai_nanoseconds;
//	state.misc.time.tai_seconds = raw_state.time.tai_seconds;
//
//	// Tire radius
//	state.misc.r_dyn = Car.Tire[0].WRadius;
//
//}
