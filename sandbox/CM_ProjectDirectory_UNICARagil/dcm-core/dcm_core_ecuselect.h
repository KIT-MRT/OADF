/**
 * \file psa_core_ecuselect.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef PSA_CORE_ECUSELECT_H
#define PSA_CORE_ECUSELECT_H

/*************************************************************************
@struct ecuselect
@brief Structure for the selection of the active ECU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 26.06.2021
*************************************************************************/
typedef struct ecuselect {

    /*************************************************************************
     @brief Timestamp of sending time for ecuselect (seconds fraction)
     @date 26.06.2021
     *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for ecuselect  (nanoseconds fraction)
    @date 26.06.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief ECU selection (0 - ECU 1, 1 - ECU 2)
    @date 26.06.2021
    *************************************************************************/
    uint16_t ecuselect;

    /*************************************************************************
    @brief Valid state of ecu selection
    @date 26.06.2021
    *************************************************************************/
    bool valid;

} ecuselect;

#endif //PSA_CORE_ECUSELECT_H
