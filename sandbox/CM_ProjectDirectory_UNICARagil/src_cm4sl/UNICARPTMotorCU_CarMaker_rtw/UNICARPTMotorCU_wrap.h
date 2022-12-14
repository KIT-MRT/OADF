/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/
#ifndef __UNICARPTMOTORCU_WRAP_H__
#define __UNICARPTMOTORCU_WRAP_H__
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
# define rtModel_UNICARPTMotorCU       RT_MODEL_UNICARPTMotorCU_T
#else
# define rtModel_UNICARPTMotorCU       tag_RTM_UNICARPTMotorCU_T
#endif                                 //CLASSIC_INTERFACE

#define ExternalInputs_UNICARPTMotorCU ExtU_UNICARPTMotorCU_T
#define ExternalOutputs_UNICARPTMotorCU ExtY_UNICARPTMotorCU_T
#ifndef UNICARPTMotorCU_rtModel

  typedef struct rtModel_UNICARPTMotorCU rtModel_UNICARPTMotorCU;

#endif

  /* Model registration function */
  rtModel_UNICARPTMotorCU *UNICARPTMotorCU (struct tInfos *Inf);

#if defined(CLASSIC_INTERFACE) && !defined(CM4SLDS)

  void rt_ODECreateIntegrationData (RTWSolverInfo *si);
  void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);
  void rt_ODEDestroyIntegrationData(RTWSolverInfo *si);

#endif

  /* Dictionary variables and other items of the model */
  extern struct tMatSuppDictDef *UNICARPTMotorCU_DictDefines;
  extern struct tMdlBdyFrame *UNICARPTMotorCU_BdyFrameDefines;

  /* Wrapper functions */
  void UNICARPTMotorCU_SetParams (rtModel_UNICARPTMotorCU *rtm,
      struct tMatSuppTunables *tuns,
      struct tInfos *Inf);
  int UNICARPTMotorCU_Register (void);

#ifdef __cplusplus

}
#endif
#endif                                 /* __UNICARPTMOTORCU_WRAP_H__ */
