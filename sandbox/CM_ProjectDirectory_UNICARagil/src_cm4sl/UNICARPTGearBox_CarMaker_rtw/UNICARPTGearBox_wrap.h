/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/
#ifndef __UNICARPTGEARBOX_WRAP_H__
#define __UNICARPTGEARBOX_WRAP_H__
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
# define rtModel_UNICARPTGearBox       RT_MODEL_UNICARPTGearBox_T
#else
# define rtModel_UNICARPTGearBox       tag_RTM_UNICARPTGearBox_T
#endif                                 //CLASSIC_INTERFACE

#define ExternalInputs_UNICARPTGearBox ExtU_UNICARPTGearBox_T
#define ExternalOutputs_UNICARPTGearBox ExtY_UNICARPTGearBox_T
#ifndef UNICARPTGearBox_rtModel

  typedef struct rtModel_UNICARPTGearBox rtModel_UNICARPTGearBox;

#endif

  /* Model registration function */
  rtModel_UNICARPTGearBox *UNICARPTGearBox (struct tInfos *Inf);

#if defined(CLASSIC_INTERFACE) && !defined(CM4SLDS)

  void rt_ODECreateIntegrationData (RTWSolverInfo *si);
  void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);
  void rt_ODEDestroyIntegrationData(RTWSolverInfo *si);

#endif

  /* Dictionary variables and other items of the model */
  extern struct tMatSuppDictDef *UNICARPTGearBox_DictDefines;
  extern struct tMdlBdyFrame *UNICARPTGearBox_BdyFrameDefines;

  /* Wrapper functions */
  void UNICARPTGearBox_SetParams (rtModel_UNICARPTGearBox *rtm,
      struct tMatSuppTunables *tuns,
      struct tInfos *Inf);
  int UNICARPTGearBox_Register (void);

#ifdef __cplusplus

}
#endif
#endif                                 /* __UNICARPTGEARBOX_WRAP_H__ */
