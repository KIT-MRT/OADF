/**
 * \file tp_core_err.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef TP_CORE_ERR_H
#define TP_CORE_ERR_H

/*************************************************************************
@struct tp_err
@brief Structure for tp_err
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 13.05.2021
*************************************************************************/
typedef struct tp_err {

    /*************************************************************************
    @brief Structure for trajGCS that caused an error
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    trajGCS errtrajGCS;

    /*************************************************************************
    @brief Structure for trajENU that failed the final check
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    trajENU errtrajENU;

    /*************************************************************************
    @brief Structure for pathGCS that caused an error
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    pathGCS errpathGCS;

    /*************************************************************************
    @brief Structure for pathENU that failed the final check
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    pathENU errpathENU;

    /*************************************************************************
    @brief String with error message
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::string errstring;

    /*************************************************************************
    @brief String with exception message
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    std::string execstring;

    /*************************************************************************
    @brief Error code
    @details 0 = thread_traj input, 1 = thread_traj ouput, 2 = thread_path input, 3 = thread_path output
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
    *************************************************************************/
    uint16_t errcode;

    /*************************************************************************
    @brief Tai time struct as sending time of error struct
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 13.05.2021
*************************************************************************/
    taitime send_tai;
} tp_err;

#endif //TP_CORE_ERR_H