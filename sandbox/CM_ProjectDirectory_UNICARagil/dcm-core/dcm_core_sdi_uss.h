/**
 * \file dcm_core_sdi_uss.h
 *
 * CONFIDENTIAL (Valeo)
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_SDI_USS_H
#define DCM_CORE_SDI_USS_H

    /*************************************************************************
    @struct SDI_uss
    @brief Structure for the plattform sensor ultrasonic sensor sdi
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 01.03.2022
    *************************************************************************/
typedef struct SDI_uss {

    /*************************************************************************
    @brief Timestamp of sending time for SDI_uss (seconds fraction)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 01.03.2022
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for SDI_uss (nanoseconds fraction)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 01.03.2022
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /* An array of ultra-sonic signalway distance data. */
    /*************************************************************************
    @brief Measurement start timestamp.
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<unsigned int> timestamp_2us;

    /* Data of 1st echo */
    /*************************************************************************
    @brief Time of flight.
    @details Default: U16_MAX
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> fe_tof_2us;

    /*************************************************************************
    @brief Current distance of track
    @details Unit: mm, Resolution: 1, Range: [0, U16_MAX]. Default: U16_MAX (in case of no dist)
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> fe_dist_mm;

    /*************************************************************************
    @brief Amplitude of the reflection.
    @details Default: U16_MAX
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> fe_amplitude;

    /*************************************************************************
    @brief Relative velocity.
    @details Unit: m/s, Resolution: 0.1, Default: SI8_MAX
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<int8_t> fe_rel_velocity_10th_m_s;

    /*************************************************************************
    @brief The Number of detections (associations)
    @details The Number of detections (associations) of the tracked distance will only be reported if echo was at least detected twice (associations = 1) Range: [1, 100]. Default: U8_MAX
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> fe_number_detections;

    /*************************************************************************
    @brief Height classification.
    @details Default: CAPP_H_UNKNOWN
    @details 0: unknown; 1: low; 2: high
    @details low: Something low which is <u>not</u> possible to drive over.
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> fe_height;

    /* Data of 2nd echo */
    /*************************************************************************
    @brief Time of flight.
    @details Default: U16_MAX
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> se_tof_2us;

    /*************************************************************************
    @brief Current distance of track
    @details Unit: mm, Resolution: 1, Range: [0, U16_MAX]. Default: U16_MAX (in case of no dist)
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> se_dist_mm;

    /*************************************************************************
    @brief Amplitude of the reflection.
    @details Default: U16_MAX
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> se_amplitude;

    /*************************************************************************
    @brief Relative velocity.
    @details Unit: m/s, Resolution: 0.1, Default: SI8_MAX
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<int8_t> se_rel_velocity_10th_m_s;

    /*************************************************************************
    @brief The Number of detections (associations)
    @details The Number of detections (associations) of the tracked distance will only be reported if echo was at least detected twice (associations = 1) Range: [1, 100]. Default: U8_MAX
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> se_number_detections;

    /*************************************************************************
    @brief Height classification.
    @details Default: CAPP_H_UNKNOWN
    @details 0: unknown; 1: low; 2: high
    @details low: Something low which is <u>not</u> possible to drive over.
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> se_height;


    /*************************************************************************
    @brief Maximum detection distance.
    @details Unit: mm, Resolution: 32, Range: [0, U8_MAX].
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> max_det_dist_32mm;

    /*************************************************************************
    @brief Blind distance.
    @details The distance below which the sensor was blind. Due to attenuation time for      * direct signal ways and acoustical shortcut for indirect signal ways. Unit: mm, Resolution: 4
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> blind_distance_4mm;

    /*************************************************************************
    @brief The physical sensor id of the sending sensor.
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> phys_sens_id_tx;

    /*************************************************************************
    @brief The physical sensor id of the recieving sensor.
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> phys_sens_id_rx;

    /*************************************************************************
    @brief The number of distances available in the distances array.
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint8_t num_distances;

    /*************************************************************************
    @brief Maximum number of allocated distances in the distances array.
    @author Valeo
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint8_t max_num_distances;

    /*************************************************************************
    @brief Live counter incremented every time data is available.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint8_t live_cnt;

    /*************************************************************************
    @brief Available flag which indicates if data was updated in current step.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 01.03.2022

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    bool is_available;

} SDI_uss;

#endif //DCM_CORE_SDI_USS_H
