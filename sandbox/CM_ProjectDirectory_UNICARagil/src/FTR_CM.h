#pragma once
//#define USE_FTR_WITH_FZS
//#define STATE_DRIFT

#include "../unicar-definitions/UNICAR_definitions.h"
#include "../ftr-core/FTR.h"
#include "Car/Vehicle_Car.h"
#include "MyModels.h"
#include "Vehicle/Sensor_GNav.h"
#include "User.h"
#include "FZS_cm.h"

namespace ftr_cm {

	template <typename T2> int sgn(T2 val) {
		return (T2(0) < val) - (val < T2(0));
	}

}

extern poseOffset pose_Offset;

void Vector2Array(trajENU& traj_ENU, trajENU_array& traj_ENU_array);
void writeDM(setpointDM& DMValues);
void getState(unicarState& state);
void stateConvertFTR(unicarState& state, struct_FZS& stateFZS);
void offsetCorrectionCM(unicarState& state, trajENU_array& traj_ENU_array, offsetState& stateForCorrection);
void addDrift(unicarState& state, long Cycles_No_CM);
void getDynState(dynState& dyn_StateVL, dynState& dyn_StateVR, dynState& dyn_StateHL, dynState& dyn_StateHR);
