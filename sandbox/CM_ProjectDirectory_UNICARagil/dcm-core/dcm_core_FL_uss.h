/**
 * \file dcm_core_FL_uss.h
 *
 * CONFIDENTIAL (Valeo)
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_FL_USS_H
#define DCM_CORE_FL_USS_H

/*************************************************************************
    @struct FL_uss
    @brief Structure for the plattform sensor ultrasonic sensor feature list
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021
    *************************************************************************/
typedef struct FL_uss {

    /*************************************************************************
    @brief Timestamp of sending time for FL_uss (seconds fraction)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 03.06.2021
    *************************************************************************/
    uint64_t send_tai_seconds;

    /*************************************************************************
    @brief Timestamp of sending time for FL_uss (nanoseconds fraction)
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 03.06.2021
    *************************************************************************/
    uint32_t send_tai_nanoseconds;

    /*************************************************************************
    @brief The timestamp of at which the features and freespaces are generated.
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    unsigned int timestamp_2us;

    /*************************************************************************
    @brief Mask for updated signal ways of a group.
    @details Signalway bitmasks. A vector of masks for all groups. A list of signalway masks of the current update cycle for all groups.
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<unsigned int> updated_slb_masks;

    /*************************************************************************
    @brief Mask for reset signal ways of a group
    @details Signalway bitmasks. A vector of masks for all groups. A list of signalway masks of the current update cycle for all groups.
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<unsigned int> reset_slb_masks;

    /*************************************************************************
    @brief The number of groups in the group vector
    @details A list of signalway masks of the current update cycle for all groups.
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    unsigned char num_grps_grp_masks;

    /*************************************************************************
    @brief Maximum number of allocated groups in the group vector.
    @details A list of signalway masks of the current update cycle for all groups.
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    unsigned char max_num_grps_grp_masks;

    /*************************************************************************
    @brief The signal way bits of the group that created the feature.
    @author Valeo
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<unsigned int> sgw_bits;

    /*************************************************************************
    @brief X- and Y-pos is related to the center point of a feature
    @details Unit: mm - resolution: 4 mm  Signed
     Each point feature point has x, y and theta position (orientation) in vehicle coordinate system
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - Sensor interface Feature freespaces for OEM.pdf (03.2018), p. 3
    *************************************************************************/
    std::vector<int16_t> ULS_Feature_Ax_PT_X_mm;

    /*************************************************************************
    @brief X- and Y-pos is related to the center point of a feature
    @details Unit: mm - resolution: 4 mm  Signed
      Each point feature point has x, y and theta position (orientation) in vehicle coordinate system
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - Sensor interface Feature freespaces for OEM.pdf (03.2018), p. 3
    *************************************************************************/
    std::vector<int16_t> ULS_Feature_Ax_PT_Y_mm;

    /*************************************************************************
    @brief Orientation
    @details Resolution: 0,0054931640625 - Range: 0° <-> 360° - Unit: degree - Unsigned
     Each point feature point has x, y and theta position (orientation) in vehicle coordinate system
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - Sensor interface Feature freespaces for OEM.pdf (03.2018), p. 3
    *************************************************************************/
    std::vector<uint16_t> ULS_Feature_Ax_Theta_deg;

    /*************************************************************************
    @brief The length of the feature along the orientation.
    @details in mm
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> length_mm;

    /*************************************************************************
    @brief The closest distance from the sensor of all sensor measurements in the current bumper cycle
    @details in mm
    @details The closest distance from the sensor of all sensor measurements in the current bumper cycle that were responsible for the creation of the feature.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> curr_sens_det_dist_mm;

    /*************************************************************************
    @brief The maximum distance from the sensor at which the feature had a stable detection.
    @details in mm
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> max_sens_det_dist_mm;

    /*************************************************************************
    @brief Lateral uncertainty (=length for a line feature)
    @details Unsigned - Max value: 4095 mm - Unit: mm - Resolution: 4 mm
     In case ULS line feature, the lateral uncert is the length of ULS line feature
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - Sensor interface Feature freespaces for OEM.pdf (03.2018), p. 3
    *************************************************************************/
    std::vector<uint16_t> ULS_Feature_Ax_Lateral_Uncert;

    /*************************************************************************
    @brief Orthogonal uncertainty
    @details Unsigned - Max value: 4094 mm - Unit: mm - Resolution: 4 mm
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - Sensor interface Feature freespaces for OEM.pdf (03.2018), p. 3
    *************************************************************************/
    std::vector<uint16_t> ULS_Feature_Bx_Orthogonal_Uncert;

    /*************************************************************************
    @brief Angular uncertainty
    @details Range: 0°<-> +180°-Unit: degree -Unsigned
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - Sensor interface Feature freespaces for OEM.pdf (03.2018), p. 3
    *************************************************************************/
    std::vector<uint16_t> ULS_Feature_Bx_Angular_Uncert;

    /*************************************************************************
    @brief Absolute velocity in x direction.
    @details in mm/s. Resolution: 1.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<int16_t> velocity_abs_x_mm_s;

    /*************************************************************************
    @brief Absolute velocity in y direction.
    @details in mm/s. Resolution: 1.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<int16_t> velocity_abs_y_mm_s;

    /*************************************************************************
    @brief The group id that created the feature.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> group_id;

    /*************************************************************************
    @brief Feature type
    @details 0: unknown; 1: sharp; 2: unsure; 3: unsharp
     Unknown feature is the default value at the initialisation.
     Unsharp feature is created in the sensor axis with association of the same sensor position. → only distance information is available. Unsharp feature - A non-triangulated radial feature.
     Unsure feature is created with association with other sensor information or with the same sensor at different positions. → X, Y position is known, Not Confident on the association. Unsure feature - A triangulated ultra-sonic feature at a distance where the quality of the triangulation is not reliable.
     Sharp feature is created with association with other sensor information or with the same sensor at different positions. → X, Y position is known, Confident on the association. Sharp Feature - A sharp triangulated ultra-sonic feature.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> ULS_Feature_Bx_Type;

    /*************************************************************************
    @brief Existing confidence of the feature
    @details Range [1, 253]
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> ULS_Feature_Bx_Confi_Percent;

    /*************************************************************************
    @brief Existing confidence of the feature Height
    @details Indicative high probability of the feature based on the signalway distance and the number of high signalways. Incremented in steps of 1 if the signalway
      distance is less than the sensor height or is more than 1m, in steps of 2 otherwise. Proportional restriction is applied to limit the counter to a maximum value.
      Range: [0,6]
      Resolution: 0.25
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> ULS_Feature_Bx_HiHeight_Percent;

    /*************************************************************************
    @brief Existing confidence of the feature Low
    @details Indicative low probability of the feature based on the signalway distance and the number of low signalways. Incremented in steps of 1 if the signalway
     distance is less than the sensor height or is more than 1m, not incremented otherwise. Proportional restriction is applied to limit the counter to a maximum value.
     Range: [0,6]
     Resolution: 0.25
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> ULS_Feature_Bx_LoHeight_Percent;

    /*************************************************************************
    @brief Dynamic property of feature. The trend of the feature.
    @details 0: unknown; 1: approach; 2: depart; 3: constant to vehicle contour and was approaching before, 4: constant to vehicle contour and was departing before
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Sensor interface Feature freespaces for OEM.pdf (03.2018), p. 3
    *************************************************************************/
    std::vector<uint16_t> ULS_Feature_Bx_Trend;

    /*************************************************************************
    @brief The algorithm that generated the feature.
    @details 0: The feature generated by an algorithms, which takes different sensors.; 1: The feature generated by an algorithms, which takes same sensor over time and distance.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> feat_algo_type;

    /*************************************************************************
    @brief Line feature (yes/no)
    @details 0b: point; 1b: line
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 02.06.2021

    * <u>Reference:</u>
    * - Sensor interface Feature freespaces for OEM.pdf (03.2018), p. 3
    *************************************************************************/
    std::vector<uint16_t> ULS_Feature_Bx_Line_PT;

    /*************************************************************************
    @brief The number of ultra-sonic features available in the vector.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint8_t num_features;

    /*************************************************************************
    @brief Maximum number of allocated features in the feature vector.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint8_t max_num_features;

    /*************************************************************************
    @brief Delta time since heavy noise toggled the last time.
    @details Additional degradation information to indicate since when the degradation was toggled the last time for selected reasons.
     Unit: 1024us
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> t_delta_hvy_nse_tgl_1024us;

    /*************************************************************************
    @brief Delta time since ice/mud toggled the last time.
    @details Additional degradation information to indicate since when the degradation was toggled the last time for selected reasons.
     Unit: 1024us
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> t_delta_imd_tgl_1024us;

    /*************************************************************************
    @brief Mask for degradation reason of center left spatial allocation.
    @details Additional degradation information.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> dgr_reason_mask_cl;

    /*************************************************************************
    @brief Mask for degradation reason of side left spatial allocation.
    @details Additional degradation information.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> dgr_reason_mask_sl;

    /*************************************************************************
    @brief Mask for degradation reason of inner spatial allocation.
    @details Additional degradation information.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> dgr_reason_mask_inner;

    /*************************************************************************
    @brief Mask for degradation reason of side right spatial allocation.
    @details Additional degradation information.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> dgr_reason_mask_sr;

    /*************************************************************************
    @brief Mask for degradation reason of center right spatial allocation.
    @details Additional degradation information.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint8_t> dgr_reason_mask_cr;

    /*************************************************************************
    @brief Degradation level center left.
    @details 0: No degradation state; 1: Low degradation state; 2: Mid degradation state; 3: High degradation state
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> dgr_level_cl;

    /*************************************************************************
    @brief Degradation level side left.
    @details 0: No degradation state; 1: Low degradation state; 2: Mid degradation state; 3: High degradation state
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> dgr_level_sl;

    /*************************************************************************
    @brief Degradation level inner.
    @details 0: No degradation state; 1: Low degradation state; 2: Mid degradation state; 3: High degradation state
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> dgr_level_inner;

    /*************************************************************************
    @brief Degradation level side right.
    @details 0: No degradation state; 1: Low degradation state; 2: Mid degradation state; 3: High degradation state
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> dgr_level_sr;

    /*************************************************************************
    @brief Degradation level center right.
    @details 0: No degradation state; 1: Low degradation state; 2: Mid degradation state; 3: High degradation state
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    std::vector<uint16_t> dgr_level_cr;

    /*************************************************************************
    @brief The number of groups in the goup vector.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint8_t num_grps_dgr_info;

    /*************************************************************************
    @brief Maximum number of allocated features in the feature vector.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint8_t max_num_grps_dgr_info;

    /*************************************************************************
    @brief Live counter incremented every time data is available.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    uint8_t live_cnt;

    /*************************************************************************
    @brief Available flag which indicates if data was updated in current step.
    @author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
    @date 15.12.2021

    * <u>Reference:</u>
    * - Valeo deserializer
    *************************************************************************/
    bool is_available;

} FL_uss;

#endif //DCM_CORE_FL_USS_H
