#ifndef FTR_INTERFACE_H
#define FTR_INTERFACE_H


#ifdef RUN_ON_R5
#include "netif/xadapter.h"
#endif

#ifdef RUN_ON_LINUX
#include <mutex>
#endif // RUN_ON_LINUX

namespace ftr_interface {

	extern struct trajENU_array glob_trajENU;
	#ifdef RUN_ON_R5
		extern SemaphoreHandle_t mx_glob_trajENU;
	#else
		extern std::mutex mx_glob_trajENU;
	#endif


	extern struct unicarState glob_stateFTR;
	#ifdef RUN_ON_R5
		extern SemaphoreHandle_t mx_glob_stateFTR;
	#else
		extern std::mutex mx_glob_stateFTR;
	#endif


    extern struct dynState glob_dynStateVL;
	#ifdef RUN_ON_R5
		extern SemaphoreHandle_t mx_glob_dynStateVL;
	#else
		extern std::mutex mx_glob_dynStateVL;
	#endif


    extern struct dynState glob_dynStateVR;
	#ifdef RUN_ON_R5
		extern SemaphoreHandle_t mx_glob_dynStateVR;
	#else
		extern std::mutex mx_glob_dynStateVR;
	#endif


    extern struct dynState glob_dynStateHL;
	#ifdef RUN_ON_R5
		extern SemaphoreHandle_t mx_glob_dynStateHL;
	#else
		extern std::mutex mx_glob_dynStateHL;
	#endif


    extern struct dynState glob_dynStateHR;
	#ifdef RUN_ON_R5
		extern SemaphoreHandle_t mx_glob_dynStateHR;
	#else
		extern std::mutex mx_glob_dynStateHR;
	#endif


	extern jnk0le::Ringbuffer<offsetState, ftr::NoElementsRingbuffer, false, 64> glob_offsetStateBuffer;
	#ifdef RUN_ON_R5
		extern SemaphoreHandle_t mx_glob_offsetStateBuffer;
	#else
		extern std::mutex mx_glob_offsetStateBuffer;
	#endif


	extern bool glob_calculateOffset;
	#ifdef RUN_ON_R5
		extern SemaphoreHandle_t mx_glob_calculateOffset;
	#else
		extern std::mutex mx_glob_calculateOffset;
	#endif


	extern bool is_instantiated;


	void tx_trajENU(trajENU_array ext_trajENU);
    void tx_stateFTR(unicarState ext_stateFTR);
	void tx_dynStateVL(dynState ext_dynStateVL);
    void tx_dynStateVR(dynState ext_dynStateVR);
    void tx_dynStateHL(dynState ext_dynStateHL);
    void tx_dynStateHR(dynState ext_dynStateHR);
    void tx_calculateOffset(bool ext_calculateOffset);
	void tx_offsetStateBuffer(offsetState ext_offsetState);

	void rx_trajENU(trajENU_array &ext_trajENU);
    void rx_stateFTR(unicarState &ext_stateFTR);
	void rx_dynStateVL(dynState &ext_dynStateVL);
    void rx_dynStateVR(dynState &ext_dynStateVR);
    void rx_dynStateHL(dynState &ext_dynStateHL);
    void rx_dynStateHR(dynState &ext_dynStateHR);
    void rx_calculateOffset(bool& ext_calculateOffset);

    bool initMutex();
}


namespace ftr_global {

	extern double curr_time;
	extern double time_error;

	extern alglib::spline1dinterpolant pos_east_int, pos_north_int, pos_yaw_int, vel_mag_int, vel_angle_int, vel_yaw_int, acc_mag_int, acc_angle_int, acc_yaw_int, misc_standstill_int, misc_parking_int, slope_lat_int, slope_lon_int;
	extern alglib::real_1d_array pos_east, pos_north, pos_yaw, vel_mag, vel_angle, vel_yaw, acc_mag, acc_angle, acc_yaw, misc_standstill, misc_parking, slope_lon, slope_lat, timestamps;

	extern LowPassFilter lpf1_ftr;
	extern LowPassFilter lpf2_ftr;
	extern pos_Err pose_error;

}


#endif
