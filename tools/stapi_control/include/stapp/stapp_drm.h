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
 * @file     stapp_drm.h
 * @brief    This is the Data Right Management file header.
 *           It is used to decrypt media files
 * @author   STMicroelectronics
 */

#ifndef _STAPP_DRM_H_
#define _STAPP_DRM_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

#define ACTIVATION_CODE_LENGTH 10
#define DEACTIVATION_CODE_LENGTH 10


/* DRM type definition */
/* ------------------- */
typedef enum
{
 DRM_TYPE_NONE=0,    /* No known DRM type                 */
 DRM_TYPE_JANUS,     /* Windows DRM for Portable Devices  */
 DRM_TYPE_CARDEA,    /* Windows DRM for Networked Devices */
 DRM_TYPE_DIVXHT,    /* DivX Home Theater DRM             */
 DRM_TYPE_MARLIN,    /* Marlin DRM                        */
 DRM_TYPE_PLAYREADY  /* PlayReady DRM                     */
} DRM_Type_t;

typedef enum
{
 DRM_PLAYBACK_ALLOWED              = 0,
 DRM_PLAYBACK_NOT_ALLOWED          = 1
}DRM_PlaybackRights_t;


typedef enum
{
   DRM_CLIENTINFO = 0,     /**< WMDRM Property */
   DRM_SECURITYVERSION,    /**< WMDRM Property */
   DRM_REGISTRATIONCODE,   /**< DivX Property  */
   DRM_ACTIVATIONSTATUS,   /**< DivX Property  */
   DRM_DEACTIVATIONCODE,   /**< DivX Property  */
   DRM_NONEINFO
} DRM_DeviceInfoProperty_t;



typedef enum
{
 DRM_COPY_PROTECT_CGMSA_COPY_FREELY,  /**< Unlimited copies allowed*/
 DRM_COPY_PROTECT_CGMSA_COPY_NO_MORE, /**< No more copies allowed */
 DRM_COPY_PROTECT_CGMSA_COPY_ONE,     /**< One copy allowed */
 DRM_COPY_PROTECT_CGMSA_COPY_NEVER    /**< Copy forbidden */
}DRM_AVCopyProtectCGMSA_t;

typedef enum
{
 DRM_ANALOG_PROTECT_OFF,     /**< No analog copy protection required */
 DRM_ANALOG_PROTECT_AGC,     /**< Automatic Gain Control only - Pseudo Sync Pulse */
 DRM_ANALOG_PROTECT_2_LINE,  /**< Automatic Gain Control and 2-line ColorStripe */
 DRM_ANALOG_PROTECT_4_LINE   /**< Automatic Gain Control and 4-line ColorStripe */
}DRM_AVAnalogProtect_t;

typedef enum
{
 DRM_ANALOG_ICT_PROTECT_OFF,     /**< Analog Image Constrained */
 DRM_ANALOG_ICT_PROTECT_ON,      /**< Analog Image High Definition */
}DRM_AVICTAnalogProtect_t;

typedef enum
{
 DRM_DIGITAL_OUTPUT_PROTECT_OFF, /**< No digital protection required */
 DRM_DIGITAL_OUTPUT_PROTECT_ON,  /**< Digital protection required */
 DRM_DIGITAL_OUTPUT_DISABLED,    /**< Output disabled */
}DRM_AVDigitalOutput_t;

typedef struct
{
 DRM_AVCopyProtectCGMSA_t AVCopyProtectCGMSA;
 DRM_AVAnalogProtect_t    AVAnalogProtect;
 DRM_AVICTAnalogProtect_t AVICTAnalogProtect;
 DRM_AVDigitalOutput_t    AVDigitalVideoOutput;
 DRM_AVDigitalOutput_t    AVDigitalAudioOutput;
}DRM_OutputProtection_t;

typedef enum
{
    DRM_RESTRICTION_NORIGHT,
    DRM_RESTRICTION_UNLIMITED,
    DRM_RESTRICTION_COUNT,
    DRM_RESTRICTION_FROM,
    DRM_RESTRICTION_UNTIL,
    DRM_RESTRICTION_FROM_UNTIL,
    DRM_RESTRICTION_COUNT_FROM,
    DRM_RESTRICTION_COUNT_UNTIL,
    DRM_RESTRICTION_COUNT_FROM_UNTIL,
    DRM_RESTRICTION_COUNTDOWN,
    DRM_RESTRICTION_COUNTDOWN_AND_FROM,
    DRM_RESTRICTION_COUNTDOWN_AND_UNTIL,
    DRM_RESTRICTION_COUNTDOWN_AND_FROM_UNTIL,
    DRM_RESTRICTION_EXPIRATION_AFTER_FIRSTUSE
} DRM_RestrictionType_t;


typedef struct
{
 DRM_RestrictionType_t DRM_RestrictionType;
 U32 InitialCount;
 U32 RemainingCount;
}DRM_Restrictions_t;


/* Prototypes */
/* ---------- */
ST_ErrorCode_t DRM_Init(void);
ST_ErrorCode_t DRM_Term(void);
ST_ErrorCode_t DRM_SetService    (char *Filename,DRM_Type_t DRM_Type,void *DRM_Service);
ST_ErrorCode_t DRM_SetMetadatas  (char *Filename,DRM_Type_t DRM_Type,char *DRM_Metadatas);
ST_ErrorCode_t DRM_AcquireLicense(char *Filename,DRM_Type_t DRM_Type,char *DRM_Metadatas);
ST_ErrorCode_t DRM_GetPlaybackRights(char *Filename,DRM_Type_t DRM_Type,DRM_PlaybackRights_t *DRM_PlaybackRights);
ST_ErrorCode_t DRM_GetOutputProtectionLevels(char *Filename,DRM_Type_t DRM_Type,DRM_OutputProtection_t *DRM_OutputProtection);
ST_ErrorCode_t DRM_GetUsageInfo(char *Filename,DRM_Type_t DRM_Type,DRM_Restrictions_t *DRM_Restrictions);
ST_ErrorCode_t DRM_GetDeviceInfo(U32 ID,DRM_Type_t DRMType,DRM_DeviceInfoProperty_t DRM_DeviceInfoProperty,void *DeviceInfo);


/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

