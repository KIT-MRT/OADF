/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/
#ifndef __UNICARSTEER_WRAP_H__
#define __UNICARSTEER_WRAP_H__
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
# define rtModel_UNICARSteer           RT_MODEL_UNICARSteer_T
#else
# define rtModel_UNICARSteer           tag_RTM_UNICARSteer_T
#endif                                 //CLASSIC_INTERFACE

#define ExternalInputs_UNICARSteer     ExtU_UNICARSteer_T
#define ExternalOutputs_UNICARSteer    ExtY_UNICARSteer_T
#ifndef UNICARSteer_rtModel

  typedef struct rtModel_UNICARSteer rtModel_UNICARSteer;

#endif

  /* Model registration function */
  rtModel_UNICARSteer *UNICARSteer (struct tInfos *Inf);

#if defined(CLASSIC_INTERFACE) && !defined(CM4SLDS)

  void rt_ODECreateIntegrationData (RTWSolverInfo *si);
  void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);
  void rt_ODEDestroyIntegrationData(RTWSolverInfo *si);

#endif

  /* Dictionary variables and other items of the model */
  extern struct tMatSuppDictDef *UNICARSteer_DictDefines;
  extern struct tMdlBdyFrame *UNICARSteer_BdyFrameDefines;

  /* Wrapper functions */
  void UNICARSteer_SetParams (rtModel_UNICARSteer *rtm,
      struct tMatSuppTunables *tuns,
      struct tInfos *Inf);
  int UNICARSteer_Register (void);

#ifdef __cplusplus

}
#endif
#endif                                 /* __UNICARSTEER_WRAP_H__ */
