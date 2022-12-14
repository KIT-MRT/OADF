/**
 * \file dcm_core_param_ps_fusion.h
 *
 * Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
 **********************************************************************/

#ifndef DCM_CORE_PARAM_PS_FUSION_H
#define DCM_CORE_PARAM_PS_FUSION_H

/*************************************************************************
@struct param_ps_fusion
@brief Structure for the parameter for param_ps_fusion
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 07.06.2021
*************************************************************************/
typedef struct param_ps_fusion {

/*************************************************************************
@brief Position and orientation of radar sensor front in UNICARagil frame (x in mm, y in mm, orientation (in +- 180°))
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021
*************************************************************************/
    std::vector<int> RF;

/*************************************************************************
@brief Position and orientation of radar sensor back in UNICARagil frame (x in mm, y in mm, orientation (in +- 180°))
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021
*************************************************************************/
    std::vector<int> RB;

/*************************************************************************
@brief Position and orientation of uss sensor in UNICARagil frame (x in mm, y in mm, orientation (in +- 180°))
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 20.10.2021
*************************************************************************/
    std::vector<int> USS;

} param_ps_fusion;

#endif //DCM_CORE_PARAM_PS_FUSION_H
