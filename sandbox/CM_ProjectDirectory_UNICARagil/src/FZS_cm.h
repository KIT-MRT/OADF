/*
******************************************************************************
**  Vehicle Dynamic State Estimation (FZS) for UNICARagil
**  Author:		Grischa Gottschalg (TU Darmstadt, PSGD)
**	Date:		2020-04-01
**  Version:	0.1
**  File:		FZS_cm.h --> header file for FZS_cm.cpp
**
** Changelog --> see .cpp file
******************************************************************************
*/

// Preprocessor variable to prevent including this header more than once
#ifndef FZS_CM_HEADER
#define FZS_CM_HEADER

// Include CarMaker h-files
#include "CarMaker.h"
// #include "Car/Vehicle_Car.h"
#include "Vehicle/Sensor_Inertial.h"
#include "Vehicle/Sensor_GNav.h"
#include "Vehicle/Sensor_SAngle.h"
#include "User.h"

// Inlcude libraries
#include <GeographicLib/Math.hpp>
#include <GeographicLib/LocalCartesian.hpp>
#include <GeographicLib/NormalGravity.hpp>

//struct for the FZS_CM output
typedef struct {
	uint8_t frame_counter;
	uint64_t tai_seconds;
	uint32_t tai_nanoseconds;
	uint8_t status;
	double pos_ell_lat_rad;
	double pos_ell_lon_rad;
	float pos_ell_h_m;
	float vel_enu_m_s[3];
	float acc_enu_m_s2[3];
	float rpy_rad[3];
	float omg_enu_rad_s[3];
}struct_FZS;

#endif //FZS_CM_HEADER 