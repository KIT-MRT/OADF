/*
******************************************************************************
**  CarMaker - Version 8.1.1
**  Vehicle Dynamics Simulation Toolkit
**
**  Copyright (C)   IPG Automotive GmbH
**                  Bannwaldallee 60             Phone  +49.721.98520.0
**                  76185 Karlsruhe              Fax    +49.721.98520.99
**                  Germany                      WWW    www.ipg-automotive.com
******************************************************************************
*/

#ifndef _MYMODELS_H__
#define _MYMODELS_H__

#ifdef __cplusplus
extern "C" {
#endif

int VehicleControl_Register_VehicleControl_UNICAR(void);
int VehicleControl_Register_VehicleControl_SH(void);
int PTControl_Register_MyModel(void);
int Steering_Register_MyModel(void);
int Brake_Register_MyModel(void);

#ifdef __cplusplus
}
#endif

#endif	/* #ifndef _MYMODELS_H__ */
