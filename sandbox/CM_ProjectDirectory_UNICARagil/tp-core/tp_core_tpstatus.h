/**
 * \file tp_core_tpstatus.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef TP_CORE_TPSTATUS_H
#define TP_CORE_TPSTATUS_H

/*************************************************************************
@struct tpstatus
@brief Structure for the status of tp
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 17.06.2021
*************************************************************************/
typedef struct tpstatus {

    /*************************************************************************
    @brief Timestamp of sending time for tpstatus (seconds fraction)
    @date 17.06.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for tpstatus (nanoseconds fraction)
    @date 17.06.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief Input status
    @details Indicates when the last valid input was received. First element is for trajectory, second element for path. 0 - Never, 1 - Normal (100ms), 2 - One dropout, 3 - 3 dropouts, 4 - 6 dropouts, 5 - 10 dropouts, 6 - More than 10 dropouts
    @date 18.06.2021
    *************************************************************************/
    uint16_t input[2];

    /*************************************************************************
    @brief Output status
    @details Indicates when the last valid output was sent. First element is for trajectory, second element for path. 0 - Never, 1 - Normal (100ms), 2 - One dropout, 3 - 3 dropouts, 4 - 6 dropouts, 5 - 10 dropouts, 6 - More than 10 dropouts
    @date 18.06.2021
    *************************************************************************/
    uint16_t output[2];

    /*************************************************************************
    @brief Runtime status
    @details Indicates the runtime of functions for thread and path. First element is for trajectory, second element for path. 0 - Never, 1 - Normal , 2 - < 1 ms, 3 - < 10 ms, 4 - < 50 ms, 5 - <100 ms, 6 - < 100 ms
    @date 18.06.2021
    *************************************************************************/
    uint16_t runtime[2];

    /*************************************************************************
    @brief Input transmission time
    @details Indicates the input transmission time. First element is for trajectory, second element for path. 0 - Never, 1 - <10ms, 2 - <50 ms, 3 - < 100ms, 4 - <500ms, 5 - 1 s, 6 - >1s
    @date 18.06.2021
    *************************************************************************/
    uint16_t transm_t[2];

    /*************************************************************************
    @brief Number of error codes
    @details Indicates the overall number of error codes. Element 0 = thread_traj input, Element 1 = thread_traj ouput, Element 2 = thread_path input, Element 3 = thread_path output
    @date 18.06.2021
    *************************************************************************/
    uint16_t errcode[4];

    /*************************************************************************
    @brief Service operational status
    @details Indicates if the service is operational or not
    @details 1 = operational, 0 = not operational
    @date 14.07.2021
    *************************************************************************/
    uint16_t operational;

} tpstatus;

#endif //TP_CORE_TPSTATUS_H