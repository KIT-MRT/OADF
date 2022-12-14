/**
 * \file dcm_core_ps_ECUstatus.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_PS_ECUSTATUS_H
#define DCM_CORE_PS_ECUSTATUS_H

/*************************************************************************
@struct ps_ECUstatus
@brief Structure for the status of thread ps_ECU
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 09.08.2021
*************************************************************************/
typedef struct ps_ECUstatus {
    /*************************************************************************
    @brief Timestamp of the last successful received odot struct from USS ECU 1 (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t ps_ECU_odot_valid_time_seconds;

    /*************************************************************************
    @brief Timestamp of the last successful received odot struct from USS ECU 1 (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t ps_ECU_odot_time_nanoseconds;

    /*************************************************************************
    @brief Timestamp of the last successful received feature/freespace struct from USS ECU 1 (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t ps_ECU_ulfc_valid_time_seconds;

    /*************************************************************************
    @brief Timestamp of the last successful received odot datagram from USS ECU 1 (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t ps_ECU_ulfc_time_nanoseconds;

    /*************************************************************************
    @brief Timestamp of the last successful received sdi struct from USS ECU 2 via USS ECU 1 (seconds)
    @date 01.03.2022
    *************************************************************************/
    uint64_t ps_ECU_sdi_valid_time_seconds;

    /*************************************************************************
    @brief Timestamp of the last successful received odot datagram from USS ECU 2 via USS ECU 1 (nanoseconds fraction)
    @date 01.03.2022
    *************************************************************************/
    uint32_t ps_ECU_sdi_time_nanoseconds;

    /*************************************************************************
    @brief Time stamp of last valid output FL_uss (seconds)
    @date 09.08.2021
    *************************************************************************/
    uint64_t FL_uss_valid_time_seconds;

    /*************************************************************************
    @brief Time stamp of last valid output FL_uss (nanoseconds fraction)
    @date 09.08.2021
    *************************************************************************/
    uint32_t FL_uss_valid_time_nanoseconds;

    /*************************************************************************
    @brief Runtime of function func_ps_ECU (seconds)
    @date 09.08.2021
    *************************************************************************/
    double ps_ECU_runtime_seconds;

    /*************************************************************************
    @brief Number of error codes
    @details
    @date 20.06.2021
    *************************************************************************/
    uint16_t no_errcode[1];

    /*************************************************************************
    @brief Valeo ECU odot state
    @details 1 Element: is_reliable(yes/not), 2 Element: sw_fault_detected(yes/not),
    @date 16.12.2021
    *************************************************************************/
    bool ecu_odotstate[2];

    /*************************************************************************
    @brief Valeo ECU ULFC_masks_S state
    @details 1 Element: updated_slb_masks_group1 (bitmask), 2 Element: updated_slb_masks_group2 (bitmask),
     3 Element: reset_slb_masks_group1 (bitmask), 4 Element: reset_slb_masks_group2 (bitmask),
    @date 16.12.2021
    *************************************************************************/
    uint32_t ULFC_masks_S[4];

    /*************************************************************************
    @brief Valeo ECU ULFC_dgr_tgl_times_S state
    @details 1 Element: t_delta_hvy_nse_tgl_1024us_group1 (1024us), 2 Element: t_delta_hvy_nse_tgl_1024us_group2 (1024us),
     3 Element: t_delta_imd_tgl_1024us_group1 (1024us), 4 Element: t_delta_imd_tgl_1024us_group2 (1024us),
    @date 16.12.2021
    *************************************************************************/
    uint16_t ULFC_dgr_tgl_times_S[4];

    /*************************************************************************
    @brief Valeo ECU ULFC_dgr_info_data_S state
    @details 1 Element: dgr_reason_mask_cl_group1 (bitmask), 2 Element: dgr_reason_mask_cl_group2 (bitmask),
     3 Element: dgr_reason_mask_sl_group1 (bitmask), 4 Element: dgr_reason_mask_sl_group2 (bitmask),
     5 Element: dgr_reason_mask_inner_group1 (bitmask), 6 Element: dgr_reason_mask_inner_group2 (bitmask),
     7 Element: dgr_reason_mask_sr_group1 (bitmask), 8 Element: dgr_reason_mask_sr_group2 (bitmask),
     9 Element: dgr_reason_mask_cr_group1 (bitmask), 10 Element: dgr_reason_mask_cr_group (bitmask),
     11 Element: dgr_level_cl_group1 (no/low/mid/high), 12 Element: dgr_level_cl_group2 (no/low/mid/high),
     13 Element: dgr_level_sl_group1 (no/low/mid/high), 14 Element: dgr_level_sl_group2 (no/low/mid/high),
     15 Element: dgr_level_inner_group1 (no/low/mid/high), 16 Element: dgr_level_inner_group2 (no/low/mid/high),
     17 Element: dgr_level_sr_group1 (no/low/mid/high), 18 Element: dgr_level_sr_group2 (no/low/mid/high),
     19 Element: dgr_level_cr_group1 (no/low/mid/high), 20 Element: dgr_level_cr_group2 (no/low/mid/high),
    @date 16.12.2021
    *************************************************************************/
    uint16_t ULFC_dgr_info_data_S[20];

} ps_ECUstatus;

#endif //DCM_CORE_PS_ECUSTATUS_H
