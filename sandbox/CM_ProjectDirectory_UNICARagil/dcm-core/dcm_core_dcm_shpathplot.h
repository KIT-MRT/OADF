/**
 * \file dcm_core_dcm_shpathplot.h
 *
 * Copyright (c) Stefan Ackermann (2022) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_DCM_SHPATHPLOT_H
#define DCM_CORE_DCM_SHPATHPLOT_H

 /*************************************************************************
 @struct dcm_shpathplot
 @brief Structure for the data of thread dcm_shpath to be plotted for debug purpose
 @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
 @date 05.05.2022
 *************************************************************************/
typedef struct dcm_shpathplot {

	/*************************************************************************
	@brief Timestamp of sending time for dcm_shpathplot (seconds fraction)
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 06.05.2022
	*************************************************************************/
	uint64_t send_tai_seconds;

	/*************************************************************************
	@brief Timestamp of sending time for dcm_shpathplot (nanoseconds fraction)
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 06.05.2022
	*************************************************************************/
	uint32_t send_tai_nanoseconds;

	/*************************************************************************
	@brief Non-significant object enu east position
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<double> ns_Object_DistENU_east;

	/*************************************************************************
	@brief Non-significant object enu north position
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<double> ns_Object_DistENU_north;

	/*************************************************************************
	@brief Multi-Polygon emergency path driving corridor east
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<std::vector<double>> path_buffered_east;

	/*************************************************************************
	@brief Multi-Polygon emergency path driving corridor north
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<std::vector<double>> path_buffered_north;

	/*************************************************************************
	@brief Multi-Polygon significant object bounding box east
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<std::vector<double>> s_obj_buffered_east;

	/*************************************************************************
	@brief Multi-Polygon significant object bounding box north
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<std::vector<double>> s_obj_buffered_north;

	/*************************************************************************
	@brief Current target object east
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<double> target_east;

	/*************************************************************************
	@brief Current target object north
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<double> target_north;

	/*************************************************************************
	@brief Current emergency path east
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<double> shpath_east;

	/*************************************************************************
	@brief Current emergency path north
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<double> shpath_north;

	/*************************************************************************
	@brief Multi-Polygon ego vehicle bounding box east
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<std::vector<double>> ego_buffered_east;

	/*************************************************************************
	@brief Multi-Polygon ego vehicle bounding box north
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<std::vector<double>> ego_buffered_north;

	/*************************************************************************
	@brief Multi-Multi-Polygon intersection bounding box east
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<std::vector<std::vector<double>>> intersection_east;

	/*************************************************************************
	@brief Multi-Multi-Polygon intersection bounding box north
	@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
	@date 05.05.2022
	*************************************************************************/
	std::vector<std::vector<std::vector<double>>> intersection_north;

} dcm_shpathplot;

#endif //DCM_CORE_DCM_SHPATHPLOT_H