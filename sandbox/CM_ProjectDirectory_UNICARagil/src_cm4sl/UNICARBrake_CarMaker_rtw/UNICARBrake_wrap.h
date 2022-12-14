/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/

#ifndef __UNICARBRAKE_WRAP_H__
#define __UNICARBRAKE_WRAP_H__
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
# define rtModel_UNICARBrake           RT_MODEL_UNICARBrake_T
#else
# define rtModel_UNICARBrake           tag_RTM_UNICARBrake_T
#endif                                 //CLASSIC_INTERFACE

#define ExternalInputs_UNICARBrake     ExtU_UNICARBrake_T
#define ExternalOutputs_UNICARBrake    ExtY_UNICARBrake_T
#ifndef UNICARBrake_rtModel

  typedef struct rtModel_UNICARBrake rtModel_UNICARBrake;

#endif

  /* Model registration function */
  rtModel_UNICARBrake *UNICARBrake (struct tInfos *Inf);

#if defined(CLASSIC_INTERFACE) && !defined(CM4SLDS)

  void rt_ODECreateIntegrationData (RTWSolverInfo *si);
  void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);
  void rt_ODEDestroyIntegrationData(RTWSolverInfo *si);

#endif

  /* Dictionary variables and other items of the model */
  extern struct tMatSuppDictDef *UNICARBrake_DictDefines;
  extern struct tMdlBdyFrame *UNICARBrake_BdyFrameDefines;

  /* Wrapper functions */
  void UNICARBrake_SetParams (rtModel_UNICARBrake *rtm,
      struct tMatSuppTunables *tuns,
      struct tInfos *Inf);
  int UNICARBrake_Register (void);

#ifdef __cplusplus

}
#endif
#endif                                 /* __UNICARBRAKE_WRAP_H__ */
