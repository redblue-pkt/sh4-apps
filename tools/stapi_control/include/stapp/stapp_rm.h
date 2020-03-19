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
 * @file     stapp_rm.h
 * @brief    This is the Resource Manager file header.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_RM_H_
#define _STAPP_RM_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
/* No Resource Manager Support */
#endif
#if defined(ST_5206)
/* No Resource Manager Support */
#endif
#if defined(ST_7105)&&defined(ST_OSLINUX)
/*#define RM_MAX_NUMBER 1*/
#endif
#if defined(ST_7108)&&defined(ST_OSLINUX)
/*#define RM_MAX_NUMBER 1*/
#endif
#if defined(ST_7111)
/* No Resource Manager Support */
#endif
#if defined(ST_7141)
/* No Resource Manager Support */
#endif
#if defined(ST_H205)
/* No Resource Manager Support */
#endif


/* data types */
/* ---------- */
typedef enum {DEVICE_STATUS_AVAILABLE, DEVICE_STATUS_RUNNING, DEVICE_STATUS_STOPPED, DEVICE_STATUS_UNKNOWN} RM_DeviceStatus_t;
typedef enum {DECODER_CONTROL_DISABLED, DECODER_CONTROL_ENABLED} RM_DeviceCtrl_t;
typedef enum {VIDEO_MAIN, VIDEO_AUX, VIDEO_VIRTUAL, GRAPHIC} RM_LayerType_t;

/* Includes */
/* -------- */
#include "strm.h"

/* Prototypes */
/* ---------- */
ST_ErrorCode_t RM_Init(void);
ST_ErrorCode_t RM_Term(void);

/* Generic RM services */
/* ------------------- */
void           RM_Lock();
void           RM_Release();
ST_ErrorCode_t RM_IsFreeDevice(STRM_String_t DeviceName,BOOL *IsFree);
ST_ErrorCode_t RM_TakeDevice(STRM_String_t DeviceName,STRM_String_t ResourceName);
ST_ErrorCode_t RM_ReleaseDevice(STRM_String_t DeviceName);
ST_ErrorCode_t RM_GetDeviceProperty(STRM_String_t DeviceName,STRM_String_t Property,void *Value,size_t ValueSize);
ST_ErrorCode_t RM_SetDeviceProperty(STRM_String_t DeviceName,STRM_String_t Property,void *Value,size_t ValueSize);

/* Generic RM A/V API */
/* ------------------ */
ST_ErrorCode_t RM_GetLayer(RM_LayerType_t LAYER_Type, ST_DeviceName_t *LAYER_DevName);
ST_ErrorCode_t RM_InitVideoCodec(VID_CodecType_t VID_CodecType,VID_Codec_t *VID_Instance);
ST_ErrorCode_t RM_TermVideoCodec(VID_Codec_t *VID_Instance);
ST_ErrorCode_t RM_OpenViewPort(VID_Codec_t *VID_Instance,ST_DeviceName_t LAYER_DevName,STVID_ViewPortHandle_t *VID_Viewport);
ST_ErrorCode_t RM_CloseViewPort(VID_Codec_t *VID_Instance,STVID_ViewPortHandle_t VID_Viewport);
ST_ErrorCode_t RM_InitAudioCodec(AUD_CodecType_t AUD_CodecType,AUD_Codec_t *AUD_Instance);
ST_ErrorCode_t RM_TermAudioCodec(AUD_Codec_t *AUD_Instance);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

