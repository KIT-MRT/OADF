#ifdef DCM_DEBUG
#include <iostream> //std::cout
#endif

// Include CarMaker specific stuff
#include "CarMaker.h"
#include "User.h"
#include "Vehicle/Sensor_GNav.h"
#include "Vehicle/Sensor_Object.h"
#include "Vehicle/Sensor_Radar.h"

#include "../dcm-core/dcm_core.h"
#include "dcm_cm_param.h"

extern taitime tpathbegin;
extern taitime tdcmshpathinput;
extern taitime txL_psinput;
extern taitime time_debug;

/*************************************************************************
@brief This function gets ext_OL_radar_R from the CarMaker simulation Radar sensor and writes it to int_glob_OL_ps_R
@param[in,out] ext_OL_radar_R Temporary radar object list for plattform radar sensor
@param[in] input Origin of this radar data (0: radar front, 1: radar back)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.10.2021
*************************************************************************/
void cm_getObjectList_Radar(OL_radar ext_OL_radar_R, uint16_t &input);

/*************************************************************************
@brief This function gets ext_OL_radar_R from the CarMaker simulation ObjectList sensor and writes it to int_glob_OL_ps_R
@param[in,out] ext_OL_radar_R Temporary radar object list for plattform radar sensor
@param[in] input Origin of this radar data (0: radar front, 1: radar back)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.10.2021
*************************************************************************/
void cm_getObjectList_Radar_ObjectSensor(OL_radar ext_OL_radar_R, uint16_t &input);

/*************************************************************************
@brief This function gets ext_FL_uss_ECU from the CarMaker simulation ObjectList sensor and writes it to int_glob_FL_ps_ECU
@param[in,out] ext_FL_uss_ECU Temporary uss feature list for plattform uss sensor
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.10.2021
*************************************************************************/
void cm_getObjectList_USS(FL_uss ext_FL_uss_ECU);

/*************************************************************************
@brief This function gets ext_FL_uss_ECU from the CarMaker simulation ObjectList sensor and writes it to int_glob_FL_ps_ECU
@param[in] ext_dcm_shpathplot Structure with plot data for dcm_shpath
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 06.05.2022
*************************************************************************/
void cm_plot_dcm_shpath(dcm_shpathplot &ext_dcm_shpathplot);

/*************************************************************************
@brief This function transforms the position of a feature from the sensor frame to the valeo frame (middle of rear axis)
@param[in] sensor Sensor position and orientation
@param[in] x x position of feature (in sensor frame, in m)
@param[in] y y position of feature (in sensor frame, in m)
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 19.10.2021
*************************************************************************/
std::vector<int> ussc_transform_feature(std::vector<int> sensor, double x, double y);
