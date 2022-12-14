/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/

#ifndef __UNICARPTMOTOR_WRAP_H__
#define __UNICARPTMOTOR_WRAP_H__
#ifndef IS_CAR
# define IS_CAR
#endif

#ifdef __cplusplus

extern "C" {

#endif

  struct tInfos;
  struct tMdlBdyFrame;
  struct tMatSuppDictDef;
  struct tMatSuppTunables;

#ifdef CLASSIC_INTERFACE
# define rtModel_UNICARPTMotor         RT_MODEL_UNICARPTMotor_T
#else
# define rtModel_UNICARPTMotor         tag_RTM_UNICARPTMotor_T
#endif                                 //CLASSIC_INTERFACE

#define ExternalInputs_UNICARPTMotor   ExtU_UNICARPTMotor_T
#define ExternalOutputs_UNICARPTMotor  ExtY_UNICARPTMotor_T
#ifndef UNICARPTMotor_rtModel

  typedef struct rtModel_UNICARPTMotor rtModel_UNICARPTMotor;

#endif

  /* Model registration function */
  rtModel_UNICARPTMotor *UNICARPTMotor (struct tInfos *Inf);

#if defined(CLASSIC_INTERFACE) && !defined(CM4SLDS)

  void rt_ODECreateIntegrationData (RTWSolverInfo *si);
  void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);
  void rt_ODEDestroyIntegrationData(RTWSolverInfo *si);

#endif

  /* Dictionary variables and other items of the model */
  extern struct tMatSuppDictDef *UNICARPTMotor_DictDefines;
  extern struct tMdlBdyFrame *UNICARPTMotor_BdyFrameDefines;

  /* Wrapper functions */
  void UNICARPTMotor_SetParams (rtModel_UNICARPTMotor *rtm,
      struct tMatSuppTunables *tuns,
      struct tInfos *Inf);
  int UNICARPTMotor_Register (void);

#ifdef __cplusplus

}
#endif
#endif                                 /* __UNICARPTMOTOR_WRAP_H__ */
