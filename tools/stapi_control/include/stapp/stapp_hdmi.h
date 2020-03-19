/*****************************************************************************/
/* COPYRIGHT (C) 2009 STMicroelectronics - All Rights Reserved               */
/* ST makes no warranty express or implied including but not limited to,     */
/* any warranty of                                                           */
/*                                                                           */
/*   (i)  merchantability or fitness for a particular purpose and/or         */
/*   (ii) requirements, for a particular purpose in relation to the LICENSED */
/*        MATERIALS, which is provided AS IS, WITH ALL FAULTS. ST does not   */
/*        represent or warrant that the LICENSED MATERIALS provided here     */
/*        under is free of infringement of any third party patents,          */
/*        copyrights, trade secrets or other intellectual property rights.   */
/*        ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE       */
/*        EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                    */
/*                                                                           */
/*****************************************************************************/
/**
 * @file     stapp_hdmi.h
 * @brief    This is the hdmi output file header.
 *           It is used to connect the digital product to hdmi input interface of the tv.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_HDMI_H_
#define _STAPP_HDMI_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
/* No hdmi support */
#endif
#if defined(ST_5206)
/* No hdmi support */
#endif
#if defined(ST_7105)
#define HDMI_MAX_NUMBER     1
#define HDMI_MAX_CEC_NUMBER 4
/*#define HDMI_HDCP_ON*/
/*#define HDMI_FORCE_DVI*/   /* Will force DVI  without to get the info from the EDID extraction */
/*#define HDMI_FORCE_HDMI*/  /* Will force HDMI without to get the info from the EDID extraction */
#endif
#if defined(ST_7108)
#define HDMI_MAX_NUMBER     1
#define HDMI_MAX_CEC_NUMBER 4
/*#define HDMI_HDCP_ON*/
/*#define HDMI_FORCE_DVI*/   /* Will force DVI  without to get the info from the EDID extraction */
/*#define HDMI_FORCE_HDMI*/ /* Will force HDMI without to get the info from the EDID extraction */
#endif
#if defined(ST_7111)
#define HDMI_MAX_NUMBER     1
#define HDMI_MAX_CEC_NUMBER 4
/*#define HDMI_HDCP_ON*/
/*#define HDMI_FORCE_DVI*/   /* Will force DVI  without to get the info from the EDID extraction */
/*#define HDMI_FORCE_HDMI*/  /* Will force HDMI without to get the info from the EDID extraction */
#endif
#if defined(ST_7141)
#define HDMI_MAX_NUMBER     1
#define HDMI_MAX_CEC_NUMBER 4
/*#define HDMI_HDCP_ON*/
/*#define HDMI_FORCE_DVI*/   /* Will force DVI  without to get the info from the EDID extraction */
/*#define HDMI_FORCE_HDMI*/  /* Will force HDMI without to get the info from the EDID extraction */
#endif
#if defined(ST_H205)
#define HDMI_MAX_NUMBER     1
#define HDMI_MAX_CEC_NUMBER 4
/*#define HDMI_HDCP_ON*/
/*#define HDMI_FORCE_DVI*/   /* Will force DVI  without to get the info from the EDID extraction */
/*#define HDMI_FORCE_HDMI*/  /* Will force HDMI without to get the info from the EDID extraction */
#endif

/* Max number of EDID blocks */
#define MAX_EDID_BLOCK 8

/* Includes */
/* -------- */
#if defined(HDMI_MAX_NUMBER)
#include "sthdmi.h"
#endif

/* HDMI Context */
/* ------------ */
#if defined(HDMI_MAX_NUMBER)
typedef struct HDMI_3DFormat_s
{
 ST_MM_3D_Format_t Vic3DStructure;
 U32               Vic;
}HDMI_3DFormat_t;

typedef struct HDMI_Context_s
{
 Mutex_t                  MutexLock;
 STHDMI_Handle_t          HDMI_Handle;
 STEVT_Handle_t           EVT_Handle;
 STVOUT_Handle_t          VOUT_Handle;
 STVTG_Handle_t           VTG_Handle;
 ST_DeviceName_t          AUD_DeviceName;
 ST_DeviceName_t          VTG_DeviceName;
 STVOUT_State_t           VOUT_OldState;
 STVOUT_State_t           VOUT_State;
 BOOL                     HDMI_AutomaticEnableDisable;
 BOOL                     HDMI_AutomaticAudioCodingMode;
 BOOL                     HDMI_IsEnabled;
 BOOL                     HDMI_Is3DSinkCapable;
 BOOL                     HDMI_IsEDIDRetrieved;
 STVOUT_OutputType_t      HDMI_OutputType;
 STHDMI_ScanInfo_t        HDMI_ScanInfo;
 STVOUT_ColorSpace_t      HDMI_Colorimetry;
 STGXOBJ_AspectRatio_t    HDMI_AspectRatio;
 STGXOBJ_AspectRatio_t    HDMI_ActiveAspectRatio;
 STHDMI_PictureScaling_t  HDMI_PictureScaling;
 STHDMI_EDIDSink_t        HDMI_EDIDSink;
 U32                      HDMI_IV0_Key;
 U32                      HDMI_IV1_Key;
 U32                      HDMI_KV0_Key;
 U32                      HDMI_KV1_Key;
 U32                      HDMI_DeviceKeys[80];
 STAUD_Object_t           AUD_ObjectID;
 U16                      CodingMode;
 STAUD_AudioCodingMode_t  ReqCodingMode;
#if defined(HDMI_CEC_ON)
 BOOL                     HDMI_CEC_DevicePresent[HDMI_MAX_CEC_NUMBER];
 STVOUT_CECDevice_t       HDMI_CEC_Device[HDMI_MAX_CEC_NUMBER];
 STHDMI_CEC_CommandInfo_t HDMI_CEC_LastCommandReceived;
#endif
 STVID_3DVideoProperty_t  HDMI_3D_VideoProperty;
 HDMI_3DFormat_t          HDMI_3D_VideoFormat[16* MAX_EDID_BLOCK];  /* 16 first entries in the EDID * Maximum data block extension = 8 */
 BOOL                     HDMI_3D_ChangeDetected;
 U32                      HDMI_VTG3D_Expected_From_Stream;
 BOOL                     HDMI_IsDVIOnly;
}HDMI_Context_t;
#endif

/* External declarations */
/* --------------------- */
#if defined(HDMI_MAX_NUMBER)
extern STHDMI_Handle_t HDMI_Handle[HDMI_MAX_NUMBER];
extern HDMI_Context_t  HDMI_Context[HDMI_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t HDMI_Init(void);
ST_ErrorCode_t HDMI_Term(void);
#if defined(HDMI_MAX_NUMBER)
ST_ErrorCode_t HDMI_IsScreenDVIOnly            (U32 DeviceId,BOOL *DVIOnlyNotHDMI);
ST_ErrorCode_t HDMI_GetSink3DCapability        (U32 DeviceId);
ST_ErrorCode_t HDMI_CheckVTGMode               (STVTG_TimingMode_t VTG_NewMode, BOOL *ModeVTG2DSupported, BOOL *Mode3DSupported);
ST_ErrorCode_t HDMI_SetVSInfoframe             (U32 VTGMode3D);
ST_ErrorCode_t HDMI_EnableOutput               (U32 DeviceId);
ST_ErrorCode_t HDMI_DisableOutput              (U32 DeviceId);
ST_ErrorCode_t HDMI_FillInfoFrame              (U32 DeviceId);
extern void    HDMIi_HotplugCallback           (STEVT_CallReason_t Reason,const ST_DeviceName_t RegistrantName,STEVT_EventConstant_t Event,const void *EventData,const void *SubscriberData_p);
extern void    HDMIi_VideoCallback             (STEVT_CallReason_t Reason,const ST_DeviceName_t RegistrantName,STEVT_EventConstant_t Event,const void *EventData,const void *SubscriberData_p);
extern void    HDMIi_AudioCallback             (STEVT_CallReason_t Reason,const ST_DeviceName_t RegistrantName,STEVT_EventConstant_t Event,const void *EventData,const void *SubscriberData_p);
extern void    HDMIi_AudioFrameInfoCallback    (STEVT_CallReason_t Reason,const ST_DeviceName_t RegistrantName,STEVT_EventConstant_t Event,const void *EventData,const void *SubscriberData_p);
#if defined(HDMI_CEC_ON)
extern void    HDMIi_CEC_LogicalAddressCallBack(STEVT_CallReason_t Reason,const ST_DeviceName_t RegistrantName,STEVT_EventConstant_t Event,const void *EventData,const void *SubscriberData_p);
extern void    HDMIi_CEC_CommandCallBack       (STEVT_CallReason_t Reason,const ST_DeviceName_t RegistrantName,STEVT_EventConstant_t Event,const void *EventData,const void *SubscriberData_p);
#endif
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

