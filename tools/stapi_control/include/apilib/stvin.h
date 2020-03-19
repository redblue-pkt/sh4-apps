/*****************************************************************************/
/* COPYRIGHT (C) 2009 STMicroelectronics - All Rights Reserved               */
/* ST makes no warranty express or implied including but not limited to,     */
/* any warranty of                                                           */
/*                                                                           */
/*   (i)  merchantability or fitness for a particular purpose and/or         */
/*   (ii) requirements, for a particular purpose in relation to the LICENSED */
/*        MATERIALS, which is provided “AS IS”, WITH ALL FAULTS. ST does not */
/*        represent or warrant that the LICENSED MATERIALS provided here     */
/*        under is free of infringement of any third party patents,          */
/*        copyrights,trade secrets or other intellectual property rights.    */
/*        ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE       */
/*        EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                    */
/*                                                                           */
/*****************************************************************************/
/**                                                                            
 @File   stvin.h                                                               
 @brief  VIN module header file                                                                       
                                                                               
                                                                               
                                                                               
*/

/* Define to prevent recursive inclusion */
#ifndef __STVIN_H
#define __STVIN_H


/* Includes ----------------------------------------------------------------- */
#if !defined(ST_OSLINUX)
#include "stlite.h"
#endif /* ST_OSLINUX */

#include "stddefs.h"
#include "stgxobj.h"
#include "stevt.h"
#include "stavmem.h"
#include "stclkrv.h"
#include "stvid.h"
#include "stvtg.h"

/* C++ support */
#ifdef __cplusplus
extern "C" {
#endif

/* Exported Constants ------------------------------------------------------- */

#define STVIN_DRIVER_ID    161 /* Replace ZZZZ by driver id (API doc number), in decimal */
#define STVIN_DRIVER_BASE  (STVIN_DRIVER_ID << 16)

enum
{
    STVIN_ERROR_FUNCTION_NOT_IMPLEMENTED = STVIN_DRIVER_BASE,

    /* Below are examples... */
    STVIN_ERROR_UNSUPPORTED_MODE,
    STVIN_ERROR_INVALID_NAME,
    STVIN_ERROR_INVALID_PROFILE,
    STVIN_ERROR_INVALID_CONSTRAINTS,
    STVIN_ERROR_MAP_VIN,
    STVIN_ERROR_MAP_SYS,
    STVIN_ERROR_MAP_CKG,
    STVIN_ERROR_NOT_AVAILABLE
};

enum
{
    /* This event passes a (STVIN_UserData_t *) as parameter */
    STVIN_USER_DATA_EVT = STVIN_DRIVER_BASE
};

#define STVIN_USER_DATA_EVT_ID                  0
#define STVIN_NB_REGISTERED_EVENTS_IDS          1

/* Exported Types ----------------------------------------------------------- */

/* STVIN handle could be any type of handle */
typedef U32 STVIN_Handle_t;

typedef enum STVIN_DefInputMode_e
{
    STVIN_INPUT_MODE_SD,
    STVIN_INPUT_MODE_HD,
    STVIN_INPUT_INVALID
} STVIN_DefInputMode_t;

typedef enum STVIN_InputPath_e
{
    STVIN_InputPath_PAD                      = 0,
    STVIN_InputPath_DVO                      = 1,
    STVIN_InputPath_CAP_EXTERNAL_SIGNED      = 2,
    STVIN_InputPath_CAP_EXTERNAL_UNSIGNED    = 3,
    STVIN_InputPath_CAP_VID1                 = 4,
    STVIN_InputPath_CAP_VID2                 = 5,
    STVIN_InputPath_CAP_MIX1_YCbCr_SIGNED    = 6,
    STVIN_InputPath_CAP_MIX1_YCbCr_UNSIGNED  = 7,
    STVIN_InputPath_CAP_MIX1_RGB             = 8,
    STVIN_InputPath_CAP_MIX2_YCbCr_SIGNED    = 9,
    STVIN_InputPath_CAP_MIX2_YCbCr_UNSIGNED  = 10,
    STVIN_InputPath_CAP_MIX2_RGB             = 11
} STVIN_InputPath_t;

/* Device base name : register base address 
 * SD Mode
 * HD Mode
 * SD
 * HD
 * DVP
 * DVO_LOOPBACK 
 * CAPTURE
 * H_RESIZE
 * V_RESIZE
 * ANCILLARY_DATA
 */

/* Chips base (7 bits) */
/* At the beginning, it was 8 bits, but to avoid problems related to signed
 * integers, one bit is never used in the DeviceType */
#define STVIN_DEVICE_TYPE_BASE_FIRST_BIT           0
#define STVIN_DEVICE_TYPE_BASE_NUMBER_OF_BITS      7
#define STVIN_DEVICE_TYPE_BASE_MASK                (((1 << STVIN_DEVICE_TYPE_BASE_NUMBER_OF_BITS) - 1) << STVIN_DEVICE_TYPE_BASE_FIRST_BIT)

/* Feature Supported */
#define STVIN_DEVICE_TYPE_FEATURE_FIRST_BIT        (STVIN_DEVICE_TYPE_BASE_FIRST_BIT + STVIN_DEVICE_TYPE_BASE_NUMBER_OF_BITS)
#define STVIN_DEVICE_TYPE_FEATURE_NUMBER_OF_BITS   5
#define STVIN_DEVICE_TYPE_FEATURE_MASK             (((1 << STVIN_DEVICE_TYPE_FEATURE_NUMBER_OF_BITS) - 1) << STVIN_DEVICE_TYPE_FEATURE_FIRST_BIT)
#define STVIN_DEVICE_TYPE_SD_SUPPORT               (1<<( 0 + STVIN_DEVICE_TYPE_FEATURE_FIRST_BIT ))
#define STVIN_DEVICE_TYPE_HD_SUPPORT               (1<<( 1 + STVIN_DEVICE_TYPE_FEATURE_FIRST_BIT ))
#define STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT       (1<<( 2 + STVIN_DEVICE_TYPE_FEATURE_FIRST_BIT )) 
#define STVIN_DEVICE_TYPE_V_DOWNSIZE_SUPPORT       (1<<( 3 + STVIN_DEVICE_TYPE_FEATURE_FIRST_BIT ))
#define STVIN_DEVICE_TYPE_ANCILLARY_DATA_SUPPORT   (1<<( 4 + STVIN_DEVICE_TYPE_FEATURE_FIRST_BIT ))

/* Hardware Chip */
#define STVIN_DEVICE_TYPE_CHIP_FIRST_BIT        (STVIN_DEVICE_TYPE_FEATURE_FIRST_BIT + STVIN_DEVICE_TYPE_FEATURE_NUMBER_OF_BITS)
#define STVIN_DEVICE_TYPE_CHIP_NUMBER_OF_BITS   5
#define STVIN_DEVICE_TYPE_CHIP_MASK             (((1 << STVIN_DEVICE_TYPE_CHIP_NUMBER_OF_BITS) - 1) << STVIN_DEVICE_TYPE_CHIP_FIRST_BIT)
#define STVIN_DEVICE_TYPE_SD_CHIP               (1<<( 0 + STVIN_DEVICE_TYPE_CHIP_FIRST_BIT ))
#define STVIN_DEVICE_TYPE_HD_CHIP               (1<<( 1 + STVIN_DEVICE_TYPE_CHIP_FIRST_BIT ))
#define STVIN_DEVICE_TYPE_DVP_CHIP              (1<<( 2 + STVIN_DEVICE_TYPE_CHIP_FIRST_BIT ))
#define STVIN_DEVICE_TYPE_DVO_LOOPBACK_CHIP     (1<<( 3 + STVIN_DEVICE_TYPE_CHIP_FIRST_BIT ))
#define STVIN_DEVICE_TYPE_CAPTURE_CHIP          (1<<( 4 + STVIN_DEVICE_TYPE_CHIP_FIRST_BIT ))


typedef enum STVIN_DeviceType_Base_e
{
    STVIN_DEVICE_TYPE_ST7111_BASE   = 0,
    STVIN_DEVICE_TYPE_ST7105_BASE   = 1,
    STVIN_DEVICE_TYPE_ST7141_BASE   = 2,
    STVIN_DEVICE_TYPE_ST7108_BASE   = 3,
    STVIN_DEVICE_TYPE_STH205_BASE   = 4
    /* Please insert new chip here !!! */
} STVIN_DeviceType_Base_t;

typedef enum STVIN_DeviceType_e
{
    STVIN_DEVICE_TYPE_ST7111_DVP_INPUT   = STVIN_DEVICE_TYPE_ST7111_BASE 
										| STVIN_DEVICE_TYPE_SD_SUPPORT
										| STVIN_DEVICE_TYPE_HD_SUPPORT
										| STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT
									    | STVIN_DEVICE_TYPE_DVP_CHIP
									    | STVIN_DEVICE_TYPE_DVO_LOOPBACK_CHIP
										,
    STVIN_DEVICE_TYPE_ST7111_CAP_INPUT   = STVIN_DEVICE_TYPE_ST7111_BASE 
										| STVIN_DEVICE_TYPE_SD_SUPPORT
										| STVIN_DEVICE_TYPE_HD_SUPPORT
										| STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT
										| STVIN_DEVICE_TYPE_V_DOWNSIZE_SUPPORT
									    | STVIN_DEVICE_TYPE_CAPTURE_CHIP
									    ,
    STVIN_DEVICE_TYPE_ST7105_DVP_INPUT   = STVIN_DEVICE_TYPE_ST7105_BASE 
                                        | STVIN_DEVICE_TYPE_SD_SUPPORT
                                        | STVIN_DEVICE_TYPE_HD_SUPPORT
                                        | STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_ANCILLARY_DATA_SUPPORT
                                        | STVIN_DEVICE_TYPE_DVP_CHIP
                                        | STVIN_DEVICE_TYPE_DVO_LOOPBACK_CHIP
                                        ,
    STVIN_DEVICE_TYPE_ST7105_CAP_INPUT   = STVIN_DEVICE_TYPE_ST7105_BASE 
                                        | STVIN_DEVICE_TYPE_SD_SUPPORT
                                        | STVIN_DEVICE_TYPE_HD_SUPPORT
                                        | STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_V_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_CAPTURE_CHIP
                                        ,
    STVIN_DEVICE_TYPE_ST7141_DVP_INPUT   = STVIN_DEVICE_TYPE_ST7141_BASE 
                                        | STVIN_DEVICE_TYPE_SD_SUPPORT
                                        | STVIN_DEVICE_TYPE_HD_SUPPORT
                                        | STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_ANCILLARY_DATA_SUPPORT
                                        | STVIN_DEVICE_TYPE_DVP_CHIP
                                        | STVIN_DEVICE_TYPE_DVO_LOOPBACK_CHIP
                                        ,
    STVIN_DEVICE_TYPE_ST7141_CAP_INPUT   = STVIN_DEVICE_TYPE_ST7141_BASE 
                                        | STVIN_DEVICE_TYPE_SD_SUPPORT
                                        | STVIN_DEVICE_TYPE_HD_SUPPORT
                                        | STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_V_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_CAPTURE_CHIP
                                        ,
    STVIN_DEVICE_TYPE_ST7108_DVP_INPUT   = STVIN_DEVICE_TYPE_ST7108_BASE 
                                        | STVIN_DEVICE_TYPE_SD_SUPPORT
                                        | STVIN_DEVICE_TYPE_HD_SUPPORT
                                        | STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_ANCILLARY_DATA_SUPPORT
                                        | STVIN_DEVICE_TYPE_DVP_CHIP
                                        | STVIN_DEVICE_TYPE_DVO_LOOPBACK_CHIP
                                        ,
    STVIN_DEVICE_TYPE_ST7108_CAP_INPUT   = STVIN_DEVICE_TYPE_ST7108_BASE 
                                        | STVIN_DEVICE_TYPE_SD_SUPPORT
                                        | STVIN_DEVICE_TYPE_HD_SUPPORT
                                        | STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_V_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_CAPTURE_CHIP
                                        ,
    STVIN_DEVICE_TYPE_STH205_CAP_INPUT   = STVIN_DEVICE_TYPE_STH205_BASE 
                                        | STVIN_DEVICE_TYPE_SD_SUPPORT
                                        | STVIN_DEVICE_TYPE_HD_SUPPORT
                                        | STVIN_DEVICE_TYPE_H_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_V_DOWNSIZE_SUPPORT
                                        | STVIN_DEVICE_TYPE_CAPTURE_CHIP
    /* Please insert new chip here !!! */
} STVIN_DeviceType_t;

typedef enum STVIN_ActiveEdge_e
{
    STVIN_RISING_EDGE,
    STVIN_FALLING_EDGE
} STVIN_ActiveEdge_t;

typedef enum STVIN_SyncType_e
{
    STVIN_SYNC_TYPE_EXTERNAL,
    STVIN_SYNC_TYPE_CCIR
} STVIN_SyncType_t;

typedef enum STVIN_AncillaryDataType_e
{
    STVIN_ANC_DATA_PACKET_NIBBLE_ENCODED = 1,
    STVIN_ANC_DATA_PACKET_DIRECT         = 2,
    STVIN_ANC_DATA_RAW_CAPTURE           = 4
} STVIN_AncillaryDataType_t;

typedef enum STVIN_InputType_e
{
    STVIN_INPUT_DIGITAL_YCbCr422_8_MULT,                   /* Block SD */
    STVIN_INPUT_DIGITAL_YCbCr422_16_CHROMA_MULT,           /* Block HD */
    STVIN_INPUT_DIGITAL_YCbCr444_24_COMP,                  /* Block HD */
    STVIN_INPUT_DIGITAL_RGB888_24_COMP_TO_YCbCr422,        /* Block HD */
    STVIN_INPUT_DIGITAL_RGB888_24_COMP,                    /* Block HD */
    STVIN_INPUT_DIGITAL_CD_SERIAL_MULT                     /* ??? */
} STVIN_InputType_t;

typedef enum STVIN_Standard_e
{
    STVIN_STANDARD_PAL,
    STVIN_STANDARD_PAL_SQ,
    STVIN_STANDARD_NTSC,
    STVIN_STANDARD_NTSC_SQ
} STVIN_Standard_t;


typedef enum STVIN_FieldDetectionMethod_e
{
    STVIN_FIELD_DETECTION_METHOD_LINE_COUNTING,
    STVIN_FIELD_DETECTION_METHOD_RELATIVE_ARRIVAL_TIMES
} STVIN_FieldDetectionMethod_t;

typedef enum STVIN_FirstPixelSignification_e
{
    STVIN_FIRST_PIXEL_IS_COMPLETE,
    STVIN_FIRST_PIXEL_IS_NOT_COMPLETE
} STVIN_FirstPixelSignification_t;

typedef enum STVIN_PolarityOfUpperFieldOutput_e
{
    STVIN_UPPER_FIELD_OUTPUT_POLARITY_ACTIVE_HIGH,
    STVIN_UPPER_FIELD_OUTPUT_POLARITY_ACTIVE_LOW
} STVIN_PolarityOfUpperFieldOutput_t;

typedef enum STVIN_InputMode_e
{
    /* Standard Definition */
    STVIN_SD_NTSC_720_480_I_CCIR,
    STVIN_SD_NTSC_640_480_I_CCIR,
    STVIN_SD_PAL_720_576_I_CCIR,
    STVIN_SD_PAL_768_576_I_CCIR,
    /* High definition */
    STVIN_HD_YCbCr_1920_1080_I_CCIR,
    STVIN_HD_YCbCr_1920_1080_P_CCIR,
    STVIN_HD_YCbCr_1280_720_P_CCIR,
    STVIN_HD_RGB_1024_768_P_EXT,
    STVIN_HD_RGB_800_600_P_EXT,
    STVIN_HD_RGB_640_480_P_EXT,
    STVIN_HD_YCbCr_720_576_P_CCIR,
    STVIN_HD_YCbCr_720_480_P_CCIR
} STVIN_InputMode_t;

typedef enum STVIN_VideoCaptureMode_e
{
    STVIN_CAPTURE_CONTINUOUS,
    STVIN_CAPTURE_SNAPSHOT
} STVIN_VideoCaptureMode_t;

typedef struct STVIN_InitParams_s
{
    ST_DeviceName_t             EvtHandlerName;
    ST_DeviceName_t             VidHandlerName;
    ST_DeviceName_t             ClockRecoveryName;
    ST_DeviceName_t             InterruptEventName;
    STEVT_EventConstant_t       InterruptEvent;
    ST_Partition_t *            CPUPartition_p;
    STAVMEM_PartitionHandle_t   AVMEMPartition;
    U32                         MaxOpen;
    void *                      DeviceBaseAddress_p;
    void *                      RegistersBaseAddress_p;
    STVIN_InputMode_t           InputMode;
    STVIN_DeviceType_t          DeviceType;

    U32                         UserDataBufferNumber;
    U32                         UserDataBufferSize;
    ST_DeviceName_t             VTGName;
    STVIN_InputPath_t           InputPath;               /* DVO/PAD/CAP */
} STVIN_InitParams_t;

typedef struct STVIN_UserData_s
{
    const void *  Buff_p;
    U32     Length;
    BOOL    BufferOverflow;
} STVIN_UserData_t;

typedef struct STVIN_OpenParams_s
{
    U32 Dummy;
} STVIN_OpenParams_t;

typedef struct STVIN_StartParams_s
{
    U32 Dummy;
} STVIN_StartParams_t;

typedef enum STVIN_Stop_e
{
    STVIN_STOP_NOW
} STVIN_Stop_t;

typedef struct STVIN_TermParams_s
{
    BOOL ForceTerminate;
} STVIN_TermParams_t;

typedef struct STVIN_Capability_s
{
    STVIN_AncillaryDataType_t    SupportedAncillaryData;        /* OR of supported ones */
    U32 Dummy;
} STVIN_Capability_t;

/* Standard Definition Parameters  - Used by STVIN_ExtraParams_t */
typedef struct STVIN_StandardDefinitionParams_s
{
    STVIN_Standard_t                    StandardType;                   /* PAL / NTSC */
    STVIN_AncillaryDataType_t           AncillaryDataType;              /* Ancillary Data */
    U16                                 AncillaryDataCaptureLength;
    STVIN_FirstPixelSignification_t     FirstPixelSignification;
} STVIN_StandardDefinitionParams_t;

/* High Definition Parameters - Used by STVIN_ExtraParams_t */
typedef struct STVIN_HighDefinitionParams_s
{
    STVIN_ActiveEdge_t                  ClockActiveEdge;
    STVIN_FieldDetectionMethod_t        DetectionMethod;
    STVIN_PolarityOfUpperFieldOutput_t  Polarity;
} STVIN_HighDefinitionParams_t;

typedef union STVIN_ExtraParams_u
{
    STVIN_StandardDefinitionParams_t    StandardDefinitionParams;
    STVIN_HighDefinitionParams_t        HighDefinitionParams;
} STVIN_ExtraParams_t;

typedef struct STVIN_VideoParams_s
{
    STVIN_InputType_t                   InputType;              /* RGB / YCbCr */
    STGXOBJ_ScanType_t                  ScanType;               /* Interlace / Progressif */
    STVIN_SyncType_t                    SyncType;               /* CCIR / External */
    STVIN_InputPath_t                   InputPath;               /* DVO/PAD/CAP */

    /* Size of the Frame - */
    U16                                 FrameWidth;
    U16                                 FrameHeight;

    /* Blancking Offset */
    U16                                 HorizontalBlankingOffset;
    U16                                 VerticalBlankingOffset;

    /* Set a window to dertermine field type */
    U16                                 HorizontalLowerLimit;
    U16                                 HorizontalUpperLimit;

    /* Polarity of HSync & VSync  */
    STVIN_ActiveEdge_t                  HorizontalSyncActiveEdge;
    STVIN_ActiveEdge_t                  VerticalSyncActiveEdge;

    /* Constants parameters - need to be hard fixed ! */
    U16                                 HSyncOutHorizontalOffset;               /* HSyncOut --+          */
    U16                                 HorizontalVSyncOutLineOffset;           /* VSyncOut   |-- Output */
    U16                                 VerticalVSyncOutLineOffset;             /* VSyncOut --+          */

    /* Extra Params */
    STVIN_ExtraParams_t                 ExtraParams;
    
    STVIN_VideoCaptureMode_t            VideoCapture;                           /* Continuous , Snapshot */
    STVID_PictureStructure_t            PictureStructure;                       /* Top , Bottom , Frame */
    STGXOBJ_ColorSpaceConversionMode_t  ColorSpaceConversionMode;               /* 709 , 601 */
    STGXOBJ_ColorType_t                 OutputFormat;
} STVIN_VideoParams_t;

/* Exported Variables ------------------------------------------------------- */


/* Exported Macros ---------------------------------------------------------- */


/* Exported Functions ------------------------------------------------------- */
ST_Revision_t STVIN_GetRevision(void);
ST_ErrorCode_t STVIN_GetCapability(const ST_DeviceName_t DeviceName, STVIN_Capability_t * const Capability_p);
ST_ErrorCode_t STVIN_Init(const ST_DeviceName_t DeviceName, const STVIN_InitParams_t * const InitParams_p);
ST_ErrorCode_t STVIN_Open(const ST_DeviceName_t DeviceName, const STVIN_OpenParams_t * const OpenParams_p, STVIN_Handle_t * const Handle_p);
ST_ErrorCode_t STVIN_Close(const STVIN_Handle_t Handle);
ST_ErrorCode_t STVIN_Term(const ST_DeviceName_t DeviceName, const STVIN_TermParams_t * const TermParams_p);

/* Std Functions */
ST_ErrorCode_t STVIN_SetSyncType(const STVIN_Handle_t Handle, const STVIN_SyncType_t SyncType);
ST_ErrorCode_t STVIN_SetScanType(const STVIN_Handle_t Handle, const STGXOBJ_ScanType_t ScanType);
ST_ErrorCode_t STVIN_SetAncillaryParameters(const STVIN_Handle_t Handle, const STVIN_AncillaryDataType_t DataType, const U16 DataCaptureLength);
ST_ErrorCode_t STVIN_SetInputType(const STVIN_Handle_t Handle, const STVIN_InputType_t InputType);
ST_ErrorCode_t STVIN_SetFrameRate(const STVIN_Handle_t Handle, const U32 FrameRate);
ST_ErrorCode_t STVIN_GetFrameRate(const STVIN_Handle_t Handle, U32 * const FrameRate_p);
ST_ErrorCode_t STVIN_SetInputWindowMode(const STVIN_Handle_t Handle, const BOOL AutoMode);
ST_ErrorCode_t STVIN_GetInputWindowMode( const STVIN_Handle_t Handle, BOOL * const AutoMode_p );
ST_ErrorCode_t STVIN_SetOutputWindowMode(const STVIN_Handle_t Handle, const BOOL AutoMode);
ST_ErrorCode_t STVIN_GetOutputWindowMode( const STVIN_Handle_t Handle, BOOL * const AutoMode_p );
ST_ErrorCode_t STVIN_SetIOWindows(
        const STVIN_Handle_t            Handle,
        S32 const InputWinX,            S32 const InputWinY,
        U32 const InputWinWidth,        U32 const InputWinHeight,
        U32 const OutputWinWidth,       U32 const OutputWinHeight);
ST_ErrorCode_t STVIN_GetIOWindows(
        const STVIN_Handle_t            Handle,
        S32 * const InputWinX_p,        S32 * const InputWinY_p,
        U32 * const InputWinWidth_p,    U32 * const InputWinHeight_p,
        U32 * const OutputWinWidth_p,   U32 * const OutputWinHeight_p);

ST_ErrorCode_t STVIN_GetParams(const STVIN_Handle_t Handle, STVIN_VideoParams_t * const VideoParams, STVIN_DefInputMode_t * const DefInputMode);
ST_ErrorCode_t STVIN_SetParams(const STVIN_Handle_t Handle, STVIN_VideoParams_t * const VideoParams);

ST_ErrorCode_t STVIN_Start(const STVIN_Handle_t Handle, const STVIN_StartParams_t * const StartParams);
ST_ErrorCode_t STVIN_Stop(const STVIN_Handle_t Handle, const STVIN_Stop_t StopMode);

int stvin_IPrC_Handler(U32 request, void *arg);

/* C++ support */
#ifdef __cplusplus
}
#endif

#endif /* #ifndef __STVIN_H */

/* End of stvin.h */
