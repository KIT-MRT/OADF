/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/
#ifndef __UNICARPTCONTROL_WRAP_H__
#define __UNICARPTCONTROL_WRAP_H__
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
# define rtModel_UNICARPTControl       RT_MODEL_UNICARPTControl_T
#else
# define rtModel_UNICARPTControl       tag_RTM_UNICARPTControl_T
#endif                                 //CLASSIC_INTERFACE

#define ExternalInputs_UNICARPTControl ExtU_UNICARPTControl_T
#define ExternalOutputs_UNICARPTControl ExtY_UNICARPTControl_T
#ifndef UNICARPTControl_rtModel

  typedef struct rtModel_UNICARPTControl rtModel_UNICARPTControl;

#endif

  /* Model registration function */
  rtModel_UNICARPTControl *UNICARPTControl (struct tInfos *Inf);

#if defined(CLASSIC_INTERFACE) && !defined(CM4SLDS)

  void rt_ODECreateIntegrationData (RTWSolverInfo *si);
  void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);
  void rt_ODEDestroyIntegrationData(RTWSolverInfo *si);

#endif

  /* Dictionary variables and other items of the model */
  extern struct tMatSuppDictDef *UNICARPTControl_DictDefines;
  extern struct tMdlBdyFrame *UNICARPTControl_BdyFrameDefines;

  /* Wrapper functions */
  void UNICARPTControl_SetParams (rtModel_UNICARPTControl *rtm,
      struct tMatSuppTunables *tuns,
      struct tInfos *Inf);
  int UNICARPTControl_Register (void);

#ifdef __cplusplus

}
#endif
#endif                                 /* __UNICARPTCONTROL_WRAP_H__ */
