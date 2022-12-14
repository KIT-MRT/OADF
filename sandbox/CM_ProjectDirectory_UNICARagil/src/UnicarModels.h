/*
******************************************************************************
**  CarMaker - Version 6.0.4
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

#define NWHEEL 4

/*
 * Example of how a
 * interface struct could look like
 * (tUnicarControl)
 */

typedef enum {
    PT_Standard,
    PT_PivotedTurn,
    PT_Rotate,
    PT_RotControl,
    PT_TrqControl,
    PT_LoadControl
} tPTMode;

typedef enum {
    SM_Standard,
    SM_InPhase,
    SM_CounterPhase,
    SM_Sideways,
    SM_Diagonal,
    SM_PivotedTurn,
    SM_Rotate,
    SM_Individual
} tSteerMode;

typedef struct t3DPoint {
    double timestamp;
    double ax;
    double ay;
} t3DPoint;

typedef struct tUnicarTraj {
    double timestamp;
    int nPoints;
    t3DPoint Points3D[10];
} tUnicarTraj;

typedef struct tUnicarControlSteer {
    struct tWheelAngle {
	double wheelSteerAngle;
	double rackMovement;
    } Wheel[4];
} tUnicarControlSteer;

typedef struct tUnicarControlAcc {
    struct tWheelAcc {
	double nrot_trg;
	double trq_trg;
    } Wheel[4];
} tUnicarControlAcc;

typedef struct tUnicarControl {
    double timestamp;
    tUnicarTraj UnicarTraj;
    tUnicarControlSteer UnicarControlSteer;
    tUnicarControlAcc UnicarControlAcc;
    tSteerMode SteerMode;			/* Steering mode 		*/
    tPTMode PTMode;				/* PowerTrain mode		*/
} tUnicarControl;


extern tUnicarControl UnicarControl;

int VehicleControl_Register_UnicarControl 	(void);
int 	updateTrajectory				(tUnicarTraj *Traj);
int 	controlModelCalculation			(void);
int Steering_Register_AllWheelSteering          (void);
int 	ConvertSteerWheelAngle2RackMovement	(tUnicarControlSteer *UnicarControlSteer);
int PTControl_Register_WheelControlModel	(void);


#ifdef __cplusplus
}
#endif

#endif	/* #ifndef _MYMODELS_H__ */
