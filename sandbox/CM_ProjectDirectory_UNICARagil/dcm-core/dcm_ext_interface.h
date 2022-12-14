/**
 * \file dcm_ext_interface.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/
#ifndef DCM_EXT_INTERFACE_H
#define DCM_EXT_INTERFACE_H

/*************************************************************************
@brief Namespace for dcm interface
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
namespace dcminterface {

/*************************************************************************
@brief Threads exit condition
@details Global atomic_flag for thread communication (Threads join if exitCondition is set)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::atomic_bool exitCondition;

/*************************************************************************
@brief Mutex for std::cout
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_cout;

/*************************************************************************
@struct glob_pathENU
@brief Global variable for pathENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern struct pathENU glob_pathENU;

/*************************************************************************
@brief Mutex for global variable for pathENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_glob_pathENU;

/*************************************************************************
@brief condition_variable for global variable for pathENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::condition_variable cv_glob_pathENU;

/*************************************************************************
@brief Atomic bool for new global variable for pathENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool pathENU_new;

/*************************************************************************
@struct glob_trajENU
@brief Global variable for trajENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern struct trajENU glob_trajENU;

/*************************************************************************
@brief Mutex for global variable for trajENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_glob_trajENU;

/*************************************************************************
@brief condition_variable for global variable for trajENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::condition_variable cv_glob_trajENU;

/*************************************************************************
@brief Atomic bool for new global variable for trajENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool trajENU_new;

/*************************************************************************
@struct glob_dcm_err
@brief Global variable for dcm_err
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::deque<dcm_err> glob_dcm_err;

/*************************************************************************
@brief Mutex for global variable for dcm_err
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_glob_dcm_err;

/*************************************************************************
@brief condition_variable for global variable for dcm_err
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::condition_variable cv_glob_dcm_err;

/*************************************************************************
@brief Atomic bool for empty global queue for dcm_err
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool dcm_err_empty;

/*************************************************************************
@struct int_glob_interp_shpath
@brief Global variable for glob_interp_shpath
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern struct interp_shpath int_glob_interp_shpath;

/*************************************************************************
@brief Never interp_shpath condition
@details Global atomic_flag for notification, that never was an interp_shpath available
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.10.2021
*************************************************************************/
    extern std::atomic_bool interp_shpath_never;

/*************************************************************************
@brief New interp_shpath condition
@details Global atomic_flag for notification, that a new interp_shpath is available
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.10.2021
*************************************************************************/
    extern std::atomic_bool interp_shpath_new;

/*************************************************************************
@brief New OL_fus condition
@details Global atomic_flag for notification, that a new OL_fus is available
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.10.2021
*************************************************************************/
    extern std::atomic_bool OL_fus_new;

/*************************************************************************
@brief Mutex for global variable dcm_shpath_input
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::mutex mx_dcm_shpath_input;;

/*************************************************************************
@brief condition_variable for dcm_shpath_input
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
    extern std::condition_variable cv_dcm_shpath_input;

/*************************************************************************
@brief This function reads the current TAI_Time
@param[out] taitime Taitime struct for tai_seconds and tai_nanoseconds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.11.2020
*************************************************************************/

    void read_taitime(taitime &taitime);

/*************************************************************************
@brief This function reads the TOML configuration file
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.03.2022
*************************************************************************/
    void read_dcmparam();

/*************************************************************************
@brief This function reads the current steady time difference for func_dcm_shpath
@param[i] a 0 for steady clock reset, 1 for time difference
@return double steady time difference in seconds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 12.11.2020
*************************************************************************/
    double steady_diff_time(int a);

/*************************************************************************
@brief This function reads the current steady time difference for read_dcm_shpath_input
@param[i] a 0 for steady clock reset, 1 for time difference
@return double steady time difference in seconds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.08.2021
*************************************************************************/
    double steady_diff_time_dcminput(int a);

/*************************************************************************
@brief This function reads the current steady time difference for rx_xL_ps
@param[i] a 0 for steady clock reset, 1 for time difference
@return double steady time difference in seconds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 21.10.2021
*************************************************************************/
    double steady_diff_time_xL_psinput(int a);

/*************************************************************************
@brief This function sends ext_pathENU to the dcm thread_interp_shpath
@param[in] ext_pathENU External pathENU struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.01.2021
*************************************************************************/
    void tx_pathENU(pathENU ext_pathENU);

/*************************************************************************
@brief This function receives dcm_err struct from the dcm threads
@param[out] ext_dcm_err External error std::deque
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    void rx_dcm_err(dcm_err &ext_dcm_err);

/*************************************************************************
@brief This function receives dcm_shpathplot from glob_dcm_shpathplot
@param[in] dcm_shpathplot dcm_shpathplot struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 06.05.2022
*************************************************************************/
	void rx_dcm_shpathplot(dcm_shpathplot &dcm_shpathplot);

/*************************************************************************
@brief This function sends ext_delay_time_s to glob_delay_time_s
@param[in] ext_delay_time_s in seconds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.01.2021
*************************************************************************/
    void tx_delay_time_s(double &ext_delay_time_s);

/*************************************************************************
@brief This function receives trajENU struct from the dcm threads
@param[out] ext_trajENU External trajENU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.03.2021
*************************************************************************/
    void rx_trajENU(trajENU &ext_trajENU);

/*************************************************************************
@struct int_glob_OL_ps_RF
@brief Global variable for int_glob_OL_ps_RF (Global object list for radar sensor front)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
    extern struct OL_radar int_glob_OL_ps_RF;

/*************************************************************************
@brief New OL_ps_RF condition
@details Global atomic_flag for notification, that a new OL_ps_RF is available
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.10.2021
*************************************************************************/
    extern std::atomic_bool OL_ps_RF_new;

/*************************************************************************
@struct int_glob_OL_ps_RB
@brief Global variable for int_glob_OL_ps_RB (Global object list for radar sensor back)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
    extern struct OL_radar int_glob_OL_ps_RB;

/*************************************************************************
@brief New OL_ps_RB condition
@details Global atomic_flag for notification, that a new OL_ps_RB is available
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.10.2021
*************************************************************************/
    extern std::atomic_bool OL_ps_RB_new;

/*************************************************************************
@struct int_glob_FL_ps_ECU
@brief Global variable for int_glob_FL_ps_ECU (Global feature list for ultrasonic sensors)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
    extern struct FL_uss int_glob_FL_ps_ECU;

/*************************************************************************
@brief New FL_ps_ECU condition
@details Global atomic_flag for notification, that a new FL_ps_ECU is available
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.10.2021
*************************************************************************/
    extern std::atomic_bool FL_ps_ECU_new;

/*************************************************************************
@struct int_glob_OL_fus
@brief Global variable for int_glob_OL_fus (Global fused object list)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
    extern struct OL_fus int_glob_OL_fus;

/*************************************************************************
@brief Mutex for global variables for ps fusion input
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.06.2021
*************************************************************************/
    extern std::mutex mx_ps_fusion_input;

/*************************************************************************
@brief Never ps_fusion_input condition
@details Global atomic_flag for notification, that never was there a ps_fusion_input
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 22.10.2021
*************************************************************************/
    extern std::atomic_bool ps_fusion_input_never;

/*************************************************************************
@brief condition_variable for ps fusion input
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.06.2021
*************************************************************************/
    extern std::condition_variable cv_ps_fusion_input;

/*************************************************************************
@brief Mutex for global variable for interp_shpathstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern std::mutex mx_glob_interp_shpathstatus;

/*************************************************************************
@struct glob_interp_shpathstatus
@brief Global variable for interp_shpathstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern struct interp_shpathstatus glob_interp_shpathstatus;

/*************************************************************************
@brief Mutex for global variable for dcm_shpathstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern std::mutex mx_glob_dcm_shpathstatus;

/*************************************************************************
@struct glob_dcm_shpathstatus
@brief Global variable for dcm_shpathstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern struct dcm_shpathstatus glob_dcm_shpathstatus;

/*************************************************************************
@brief Mutex for global variable for ps_RFstatus (front sensor)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern std::mutex mx_glob_ps_RFstatus;

/*************************************************************************
@struct glob_ps_RFstatus
@brief Global variable for ps_RFstatus (front sensor)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern struct ps_Rstatus glob_ps_RFstatus;

/*************************************************************************
@brief Mutex for global variable for ps_RBstatus (back sensor)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern std::mutex mx_glob_ps_RBstatus;

/*************************************************************************
@struct glob_ps_RBstatus
@brief Global variable for ps_RBstatus (back sensor)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern struct ps_Rstatus glob_ps_RBstatus;

/*************************************************************************
@brief Mutex for global variable for ps_ECUstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern std::mutex mx_glob_ps_ECUstatus;

/*************************************************************************
@struct glob_ps_ECUstatus
@brief Global variable for ps_ECUstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern struct ps_ECUstatus glob_ps_ECUstatus;

/*************************************************************************
@brief Mutex for global variable for ps_fusionstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern std::mutex mx_glob_ps_fusionstatus;

/*************************************************************************
@struct glob_ps_fusionstatus
@brief Global variable for ps_fusionstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern struct ps_fusionstatus glob_ps_fusionstatus;

/*************************************************************************
@struct glob_dcmstatus
@brief Global variable for dcmstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern struct dcmstatus glob_dcmstatus;

/*************************************************************************
@brief Mutex for global variable for dcmstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern std::mutex mx_glob_dcmstatus;

/*************************************************************************
@brief condition_variable for global variable for dcmstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    extern std::condition_variable cv_glob_dcmstatus;

/*************************************************************************
@brief Atomic bool for new global variable for dcmstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool dcmstatus_new;

/*************************************************************************
@struct glob_FOL_d
@brief Global variable for FOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern struct OL_fus glob_FOL_d;

/*************************************************************************
@brief Mutex for global variable for FOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::mutex mx_glob_FOL_d;

/*************************************************************************
@brief condition_variable for global variable for FOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::condition_variable cv_glob_FOL_d;

/*************************************************************************
@brief Atomic bool for new global variable for FOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::atomic_bool FOL_d_new;

/*************************************************************************
@struct glob_ishp_d
@brief Global variable for ishp_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern struct interp_shpath glob_ishp_d;

/*************************************************************************
@brief Mutex for global variable for ishp_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::mutex mx_glob_ishp_d;

/*************************************************************************
@brief condition_variable for global variable for ishp_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::condition_variable cv_glob_ishp_d;

/*************************************************************************
@brief Atomic bool for new global variable for ishp_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::atomic_bool ishp_d_new;

/*************************************************************************
@struct glob_RFOL_d
@brief Global variable for RFOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern struct OL_radar glob_RFOL_d;

/*************************************************************************
@brief Mutex for global variable for RFOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::mutex mx_glob_RFOL_d;

/*************************************************************************
@brief condition_variable for global variable for RFOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::condition_variable cv_glob_RFOL_d;

/*************************************************************************
@brief Atomic bool for new global variable for RFOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::atomic_bool RFOL_d_new;

/*************************************************************************
@struct glob_RBOL_d
@brief Global variable for RBOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern struct OL_radar glob_RBOL_d;

/*************************************************************************
@brief Mutex for global variable for RBOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::mutex mx_glob_RBOL_d;

/*************************************************************************
@brief condition_variable for global variable for RBOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::condition_variable cv_glob_RBOL_d;

/*************************************************************************
@brief Atomic bool for new global variable for RBOL_d
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    extern std::atomic_bool RBOL_d_new;

/*************************************************************************
@brief This function receives dcmstatus from the dcm thread_dcmstatus
@param[in,out] ext_dcmstatus External dcmstatus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
    void rx_dcmstatus(dcmstatus &ext_dcmstatus);

/*************************************************************************
@brief This function receives fused object list from the dcm thread_dcm_shpath
@param[in,out] ext_OL_fus External fusioned object list
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    void rx_FOL_d(OL_fus &ext_OL_fus);

/*************************************************************************
@brief This function receives fused object list from the dcm thread_dcm_shpath
@param[in,out] ext_interp_shpath External interpolated shpath
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    void rx_ishp_d(interp_shpath &ext_interp_shpath);

/*************************************************************************
@brief This function receives radar front object list from the dcm thread_dcm_ps_RF
@param[in,out] ext_OL_RF External radar front object list
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    void rx_RFOL_d(OL_radar &ext_OL_RF);

/*************************************************************************
@brief This function receives radar back object list from the dcm thread_dcm_ps_RB
@param[in,out] ext_OL_RB External radar back object list
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 24.03.2022
*************************************************************************/
    void rx_RBOL_d(OL_radar &ext_OL_RB);

/*************************************************************************
@brief This function receives ecus from the dcm thread
@param[in,out] ext_ecus External ecuselect struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 11.08.2021
*************************************************************************/
    void rx_ecus(ecuselect &ext_ecus);

/*************************************************************************
@struct glob_ecus
@brief Global variable for ecus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 11.08.2021
*************************************************************************/
    extern struct ecuselect glob_ecus;

/*************************************************************************
@brief Mutex for global variable for ecus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 11.08.2021
*************************************************************************/
    extern std::mutex mx_glob_ecus;

/*************************************************************************
@brief condition_variable for global variable for ecus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 11.08.2021
*************************************************************************/
    extern std::condition_variable cv_glob_ecus;

/*************************************************************************
@brief Atomic bool for new global variable for ecus
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 27.10.2021
*************************************************************************/
    extern std::atomic_bool ecus_new;

/*************************************************************************
@brief This function sends OL_ps_R from the environment (e.g. CarMaker) to int_glob_OL_ps_RB
@param[in,out] tmp_OL_ps_R Temporary radar object list for plattform radar sensor
@param[in] input Origin of this radar data (0: radar front, 1: radar back)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.10.2021
*************************************************************************/
    void tx_OL_ps_R(OL_radar tmp_OL_ps_R, uint16_t &input);

/*************************************************************************
@brief This function sends FL_ps_ECU from the environment (e.g. CarMaker) to int_glob_FL_ps_ECU
@param[in,out] tmp_FL_ps_ECU Temporary ultrasonic sensor feature list
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.10.2021
*************************************************************************/
    void tx_FL_ps_ECU(FL_uss tmp_FL_ps_ECU);

/*************************************************************************
@struct glob_vds
@brief Global variable for vds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 10.11.2021
*************************************************************************/
    extern struct vds glob_vds;

/*************************************************************************
@brief Mutex for global variable for vds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 10.11.2021
*************************************************************************/
    extern std::mutex mx_glob_vds;

/*************************************************************************
@brief condition_variable for global variable for vds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 10.11.2021
*************************************************************************/
    extern std::condition_variable cv_glob_vds;

/*************************************************************************
@brief Atomic bool for new global variable for vds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 10.11.2021
*************************************************************************/
    extern std::atomic_bool vds_new;

/*************************************************************************
@brief This function sends ext_vds to the dcm thread_dcm_shpath
@param[in] ext_vds External vds struct
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 10.11.2021
*************************************************************************/
    void tx_vds(vds ext_vds);

/*************************************************************************
@brief This function reads the current steady time difference for debug display
@param[i] a 0 for steady clock reset, 1 for time difference
@return double steady time difference in seconds
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.03.2022
*************************************************************************/
    double steady_diff_time_debug(int a);

/*************************************************************************
@struct glob_dcm_shpathplot
@brief Global variable for dcm_shpathplot
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 06.05.2022
*************************************************************************/
	extern struct dcm_shpathplot glob_dcm_shpathplot;

/*************************************************************************
@brief Mutex for global variable for dcm_shpathplot
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 06.05.2022
*************************************************************************/
	extern std::mutex mx_glob_dcm_shpathplot;

/*************************************************************************
@brief condition_variable for global variable for dcm_shpathplot
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 06.05.2022
*************************************************************************/
	extern std::condition_variable cv_glob_dcm_shpathplot;

/*************************************************************************
@brief Atomic bool for new global variable for dcm_shpathplot
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 06.05.2022
*************************************************************************/
	extern std::atomic_bool dcm_shpathplot_new;

}

#endif //DCM_EXT_INTERFACE_H
