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
 @File   stvout.h
 @brief


*/
#ifndef __STVOUT_H
#define __STVOUT_H

/* Includes --------------------------------------------------------------- */

#include "stddefs.h"
#include "stvtg.h"
#include "stpio.h"                      /* Dependencies */
#include "sti2c.h"

#if defined(STPOWER_SUPPORTED)
#include "stpower.h"
#endif /* STPOWER_SUPPORTED */

/* stvout structures */


#include "internal/vout_feature.h"

#ifndef WA_RnDHV49440
#if (STVOUT_DEVTYPE >= STVOUT_DEVTYPE_7108)
/* 
WA_RnDHV49440 Inversion of corposant Red and Blue for NTSC video format.
WA2_RnDHV49440 Change decimation to drop Cb sampling for NTSC video format. 
*/
/* define WA_RnDHV49440 or WA2_RnDHV49440(default) */
#define WA2_RnDHV49440
#endif
#endif
/* Exported Constants ----------------------------------------------------- */
#define STVOUT_DRIVER_ID      146
#define STVOUT_DRIVER_BASE    (STVOUT_DRIVER_ID << 16)
#define STVOUT_MAX_CEC_MESSAGE_LENGTH 16

enum
{
   STVOUT_CHANGE_STATE_EVT = STVOUT_DRIVER_BASE,
   STVOUT_REVOKED_KSV_EVT,
   STVOUT_CEC_MESSAGE_EVT,
   STVOUT_CEC_LOGIC_ADDRESS_EVT,
   STVOUT_CEC_WAKEUP_EVT,
   STVOUT_HPD_EVT
};

enum
{
    STVOUT_ERROR_DENC_ACCESS = STVOUT_DRIVER_BASE,
    STVOUT_ERROR_VOUT_NOT_AVAILABLE,
    STVOUT_ERROR_VOUT_NOT_ENABLE,
    STVOUT_ERROR_VOUT_ENABLE,
    STVOUT_ERROR_VOUT_MAP_SYS,
    STVOUT_ERROR_VOUT_INCOMPATIBLE,
    STVOUT_ERROR_VOUT_CRC
};

/* Big clean-up to happen there !*/
typedef enum STVOUT_DeviceType_e
{
    STVOUT_DEVICE_TYPE_DENC,
    STVOUT_DEVICE_TYPE_7015,
    STVOUT_DEVICE_TYPE_7020,
    STVOUT_DEVICE_TYPE_GX1,
    STVOUT_DEVICE_TYPE_5528,
    STVOUT_DEVICE_TYPE_4629,
    STVOUT_DEVICE_TYPE_DIGITAL_OUTPUT,
    STVOUT_DEVICE_TYPE_DENC_ENHANCED,
    STVOUT_DEVICE_TYPE_V13,     /* 5197*/
    STVOUT_DEVICE_TYPE_7710,
    STVOUT_DEVICE_TYPE_5525,    /* 5188*/
    STVOUT_DEVICE_TYPE_7100,    /* 7109*/
    STVOUT_DEVICE_TYPE_7200,    /* 7200*/
    STVOUT_DEVICE_TYPE_7111     /* All other Soc supported: ST_5206 ST_5289 ST_7105 ST_7111 ST_7141 ST_7108*/
} STVOUT_DeviceType_t;

typedef enum STVOUT_OutputType_e
{
    STVOUT_OUTPUT_ANALOG_RGB                               = 1,
    STVOUT_OUTPUT_ANALOG_YUV                               = 2,
    STVOUT_OUTPUT_ANALOG_YC                                = 4,
    STVOUT_OUTPUT_ANALOG_CVBS                              = 8,
    STVOUT_OUTPUT_ANALOG_SVM                               = 16,
    STVOUT_OUTPUT_DIGITAL_YCBCR444_24BITSCOMPONENTS        = 32,
    STVOUT_OUTPUT_DIGITAL_YCBCR422_16BITSCHROMAMULTIPLEXED = 64, /* SMPTE274/295 */
    STVOUT_OUTPUT_DIGITAL_YCBCR422_8BITSMULTIPLEXED        = 128,   /* CCIR656 */
    STVOUT_OUTPUT_DIGITAL_RGB888_24BITSCOMPONENTS          = 256,
	STVOUT_OUTPUT_DIGITAL_RGB8888_32BITSCOMPONENTS         = 512,
    STVOUT_OUTPUT_HD_ANALOG_RGB                            = 1024,
    STVOUT_OUTPUT_HD_ANALOG_YUV                            = 2048,
    STVOUT_OUTPUT_DIGITAL_HDMI_RGB888                      = 4096,
    STVOUT_OUTPUT_DIGITAL_HDMI_YCBCR444                    = 8192,
    STVOUT_OUTPUT_DIGITAL_HDMI_YCBCR422                    = 16384
} STVOUT_OutputType_t;

typedef enum STVOUT_StateParams_e
{
    STVOUT_PARAMS_NOT_CHANGED,
    STVOUT_PARAMS_DEFAULT,
    STVOUT_PARAMS_AFFECTED
} STVOUT_StateParams_t;

typedef enum STVOUT_AnalogProgrammableOutput_e
{
    STVOUT_Y        = 1,
    STVOUT_C        = 2,
    STVOUT_YC_RATIO = 4,
    STVOUT_CVBS     = 8,
    STVOUT_RGB      = 16,
    STVOUT_YUV      = 32
} STVOUT_AnalogProgrammableOutput_t;

typedef enum STVOUT_SVM_ShapeControl_e
{
    STVOUT_SVM_SHAPE_OFF = 0,
    STVOUT_SVM_SHAPE_1 = 1,
    STVOUT_SVM_SHAPE_2 = 2,
    STVOUT_SVM_SHAPE_3 = 3
} STVOUT_SVM_ShapeControl_t;

typedef enum STVOUT_SVM_OSD_Factor_e
{
    STVOUT_SVM_FACTOR_0   = 0,
    STVOUT_SVM_FACTOR_1_2 = 1,
    STVOUT_SVM_FACTOR_3_4 = 2,
    STVOUT_SVM_FACTOR_1   = 3
} STVOUT_SVM_OSD_Factor_t;

typedef enum STVOUT_SVM_Filter_e
{
    STVOUT_SVM_FILTER_1 = 1,
    STVOUT_SVM_FILTER_2 = 2
} STVOUT_SVM_Filter_t;

typedef enum STVOUT_ColorSpace_e
{
    STVOUT_SMPTE240M = 1,
    STVOUT_ITU_R_601 = 2,
    STVOUT_ITU_R_709 = 4,
    STVOUT_XVYCC_601 = 8,
    STVOUT_XVYCC_709 = 16,
    STVOUT_SYCC_601  = 32,
    STVOUT_ADOBE_YCC_601  = 64,
    STVOUT_ADOBE_RGB  = 128
} STVOUT_ColorSpace_t;

typedef enum STVOUT_Option_e
{
    STVOUT_OPTION_GENERAL_AUX_NOT_MAIN,
    STVOUT_OPTION_NOTCH_FILTER_ON_LUMA,
    STVOUT_OPTION_RGB_SATURATION,
    STVOUT_OPTION_IF_DELAY
} STVOUT_Option_t;

typedef enum STVOUT_DAC_e
{
    STVOUT_DAC_1=1,
    STVOUT_DAC_2=2,
    STVOUT_DAC_3=4,
    STVOUT_DAC_4=8,
    STVOUT_DAC_5=16,
    STVOUT_DAC_6=32
}STVOUT_DAC_t;

typedef enum STVOUT_DACOutput_e
{
    STVOUT_DAC_OUTPUT_CVBS_MAIN,
    STVOUT_DAC_OUTPUT_CVBS_AUX,
    STVOUT_DAC_OUTPUT_YC_MAIN,
    STVOUT_DAC_OUTPUT_YC_AUX,
    STVOUT_DAC_OUTPUT_RGB,
    STVOUT_DAC_OUTPUT_YUV_MAIN,
    STVOUT_DAC_OUTPUT_YUV_AUX,
    STVOUT_DAC_OUTPUT_NONE
}STVOUT_DACOutput_t;

 typedef enum STVOUT_Source_e
{
    STVOUT_SOURCE_MAIN,
    STVOUT_SOURCE_AUX
} STVOUT_Source_t ;

typedef enum STVOUT_Format_e
{
    STVOUT_SD_MODE    ,
    STVOUT_ED_MODE    ,
    STVOUT_HD_MODE    ,
    STVOUT_HDRQ_MODE
} STVOUT_Format_t ;

typedef enum STVOUT_State_e
{
	STVOUT_IDLE, /* Driver is on low-power mode */
    /* Following with non DVI/HDMI*/
    STVOUT_DISABLED,
    STVOUT_ENABLED,
   /* Following with DVI/HDMI use*/
    STVOUT_NO_RECEIVER,
    STVOUT_RECEIVER_CONNECTED,
	STVOUT_RECEIVER_INACTIVE,
    STVOUT_NO_ENCRYPTION,
    STVOUT_NO_HDCP_RECEIVER,
    STVOUT_AUTHENTICATION_IN_PROGRESS,
    STVOUT_AUTHENTICATED,
    STVOUT_AUTHENTICATION_FAILED,
    STVOUT_AUTHENTICATION_SUCCEEDED,
    STVOUT_AUTHENTICATION_PART3_SUCCEEDED,
    STVOUT_SECOND_PART_AUTHENTICATION
} STVOUT_State_t;

typedef enum STVOUT_InfoFrameType_e
{
    STVOUT_INFOFRAME_TYPE_VS,
    STVOUT_INFOFRAME_TYPE_AVI,
    STVOUT_INFOFRAME_TYPE_AUDIO,
    STVOUT_INFOFRAME_TYPE_SPD,
    STVOUT_INFOFRAME_TYPE_MPEG,
    STVOUT_INFOFRAME_TYPE_ACR,
    STVOUT_INFOFRAME_TYPE_ACP,
    STVOUT_INFOFRAME_TYPE_ISRC1,
    STVOUT_INFOFRAME_TYPE_ISRC2,
    STVOUT_INFOFRAME_TYPE_GAMUT_P0,
    STVOUT_INFOFRAME_TYPE_GAMUT_P1,
    STVOUT_INFOFRAME_TYPE_GAMUT_P2,
    STVOUT_INFOFRAME_TYPE_GAMUT_P3,
    STVOUT_INFOFRAME_LAST
} STVOUT_InfoFrameType_t;

typedef enum STVOUT_ColorDepth_e
{
   STVOUT_COLOR_DEPTH_NOT_INDICATED,
   STVOUT_COLOR_DEPTH_24BITS,
   STVOUT_COLOR_DEPTH_30BITS,
   STVOUT_COLOR_DEPTH_36BITS,
   STVOUT_COLOR_DEPTH_48BITS

} STVOUT_ColorDepth_t;

typedef enum STVOUT_DecimationType_e
{
   STVOUT_DECIMATION_NONE,
   STVOUT_DECIMATION_CB,
   STVOUT_DECIMATION_CR

}STVOUT_DecimationType_t;

typedef enum
{
    STVOUT_EMBEDDED_SYSTEM_525_60,
    STVOUT_EMBEDDED_SYSTEM_625_50,
	STVOUT_EMBEDDED_SYSTEM_PROG_525_60,
    STVOUT_EMBEDDED_SYSTEM_PROG_625_50
} STVOUT_EmbeddedSystem_t;

typedef enum STVOUT_CECRole_e
{
    STVOUT_CEC_ROLE_TV              = 0x01,
	STVOUT_CEC_ROLE_RECORDER 		= 0x02,
    STVOUT_CEC_ROLE_TUNER           = 0x04,
    STVOUT_CEC_ROLE_PLAYBACK        = 0x08,
    STVOUT_CEC_ROLE_AUDIO           = 0x10
}STVOUT_CECRole_t;

typedef enum STVOUT_CECStatus_e
{
	STVOUT_CEC_STATUS_TX_SUCCEED,
	STVOUT_CEC_STATUS_TX_FAILED,
	STVOUT_CEC_STATUS_TX_PENDING,
	STVOUT_CEC_STATUS_TX_ARBITRATION_LOST,
	STVOUT_CEC_STATUS_RX_SUCCEED,
    STVOUT_CEC_STATUS_RX_BAD_FRAME
    /*...*/
 }STVOUT_CECStatus_t;

/* Delay on chroma path with reference to luma path on S-VHS and CVBS */
typedef enum STVOUT_ChromaLumaDelay_e
{
   STVOUT_CHROMALUMA_DELAY_M2   ,
   STVOUT_CHROMALUMA_DELAY_M1_5 ,
   STVOUT_CHROMALUMA_DELAY_M1   ,
   STVOUT_CHROMALUMA_DELAY_M0_5 ,
   STVOUT_CHROMALUMA_DELAY_0    ,
   STVOUT_CHROMALUMA_DELAY_0_5  ,
   STVOUT_CHROMALUMA_DELAY_P1   ,
   STVOUT_CHROMALUMA_DELAY_P1_5 ,
   STVOUT_CHROMALUMA_DELAY_P2   ,
   STVOUT_CHROMALUMA_DELAY_P2_5
}STVOUT_ChromaLumaDelay_t ;

typedef enum STVOUT_AudioDataType_e
{
    STVOUT_HDMI_NORMAL_AUDIO,
    STVOUT_HDMI_ONE_BIT_AUDIO,
    STVOUT_HDMI_DST_AUDIO,
    STVOUT_HDMI_HBR_AUDIO
}STVOUT_AudioDataType_t;

/* Exported Types --------------------------------------------------------- */
typedef struct STVOUT_DacRGB_s
{   /* RGB : n*2.44%, -8<=n<=7 => -19.52%<=level<=+21.08% */
    S8      R;
    S8      G;
    S8      B;
} STVOUT_DacRGB_t;

typedef struct STVOUT_DacYUV_s
{   /* YUV : n*3.125%, -8<=n<=7 => -25%<=level<=+21.875% */
    S8      Y;
    S8      U;
    S8      V;
} STVOUT_DacYUV_t;

typedef struct STVOUT_DacCVBS_s
{   /* CVBS : n*3.125%, -8<=n<=7 => -25%<=level<=+21.875% */
    /* YC Ratio : 1 <= ratio <= 1+n/64, 0<=n<=15 */
    S8      CVBS;
    U8      YCRatio;
} STVOUT_DacCVBS_t;

typedef struct STVOUT_DacYC_s
{   /* YC : n*3.125%, -8<=n<=7 => -25%<=level<=+21.875% */
    /* YC Ratio : 1 <= ratio <= 1+n/64, 0<=n<=15 */
    S8      Y;
    S8      C;
    U8      YCRatio;
} STVOUT_DacYC_t;

typedef struct STVOUT_BCSLevel_s
{
    U8      Brightness;
    S8      Contrast;
    U8      Saturation;
} STVOUT_BCSLevel_t;

typedef struct STVOUT_ChrLumFilter_s
{
    S16     Chroma[9];
    S16     Luma[10];
} STVOUT_ChrLumFilter_t;

typedef union STVOUT_AnalogLevel_u
{
    STVOUT_DacRGB_t     RGB;
    STVOUT_DacYUV_t     YUV;
    STVOUT_DacCVBS_t    CVBS;
    STVOUT_DacYC_t      YC;
} STVOUT_AnalogLevel_t;

typedef struct STVOUT_OptionParams_s
{
    STVOUT_Option_t                  Option;
    BOOL                             Enable;
} STVOUT_OptionParams_t;

typedef struct STVOUT_AnalogOutputParams_s
{
    /* Dac Level */
    STVOUT_StateParams_t    StateAnalogLevel;
    STVOUT_AnalogLevel_t    AnalogLevel;
    /*  */
    STVOUT_StateParams_t    StateBCSLevel;
    STVOUT_BCSLevel_t       BCSLevel;
    /*  */
    STVOUT_StateParams_t    StateChrLumFilter;
    STVOUT_ChrLumFilter_t   ChrLumFilter;
    /*  */
    BOOL                    InvertedOutput;
    BOOL                    EmbeddedType;
    BOOL                    SyncroInChroma;
    STVOUT_ColorSpace_t     ColorSpace;
} STVOUT_AnalogOutputParams_t;


typedef struct STVOUT_SinkInformation_s
{
    U8* Buffer_p;
    U32 Size;
}STVOUT_SinkInformation_t;

typedef struct STVOUT_DigitalOutputParams_s
{
    BOOL                           EmbeddedType;
    BOOL                           SyncroInChroma;
    STVOUT_ColorSpace_t            ColorSpace;
    STVOUT_EmbeddedSystem_t        EmbeddedSystem;
} STVOUT_DigitalOutputParams_t;

typedef struct STVOUT_EnhancedDigitalOutputParams_s
{
    BOOL                           EmbeddedSyncro;      /* Embadded or External synchro */
    BOOL                           InvertedPolarity;    /* Inverted Clock Polarity */
    BOOL                           DataEnable;          /* Enable EAV/SAV Data insertion */
    STVOUT_ColorSpace_t            ColorSpace;          /* Color Space : 601 SD / 709 HD */
} STVOUT_EnhancedDigitalOutputParams_t;

typedef struct STVOUT_DVOCell_s
{
    void*                   DeviceBaseAddress_p;
    void*                   BaseAddress_p;
} STVOUT_DVOCell_t;

typedef struct STVOUT_SVMOutputParams_s
{
    STVOUT_StateParams_t      StateAnalogSVM;
    U32                       DelayCompensation;
    STVOUT_SVM_ShapeControl_t Shape;
    U32                       Gain;
    STVOUT_SVM_OSD_Factor_t   OSDFactor;
    STVOUT_SVM_Filter_t       VideoFilter;
    STVOUT_SVM_Filter_t       OSDFilter;
} STVOUT_SVMOutputParams_t;

typedef struct STVOUT_HDMIOutputParams_s
{
	U32                  AudioFrequency;
    BOOL                 ForceDVI;
    BOOL                 IsHDCPEnable;
    BOOL                 IsSourceEncrypting;
}STVOUT_HDMIOutputParams_t;

#if (STVOUT_DEVTYPE >= STVOUT_DEVTYPE_7108)
typedef struct STVOUT_EnhancedHDMIOutputParams_s
{
    U32                      AudioFrequency;
    BOOL                     ForceDVI;
    BOOL                     IsHDCPEnable;
    BOOL                     IsSourceEncrypting;
    STVOUT_ColorDepth_t      ColorDepth;
    STVOUT_DecimationType_t  Decimation;
}STVOUT_EnhancedHDMIOutputParams_t;
#endif

typedef union STVOUT_OutputParams_u
{
    STVOUT_AnalogOutputParams_t             Analog;
    STVOUT_DigitalOutputParams_t            Digital;
    STVOUT_EnhancedDigitalOutputParams_t    EnhancedDigital;
    STVOUT_SVMOutputParams_t                SVM;
    STVOUT_HDMIOutputParams_t               HDMI;
#if (STVOUT_DEVTYPE >= STVOUT_DEVTYPE_7108)
    STVOUT_EnhancedHDMIOutputParams_t       EnhancedHDMI;
#endif
} STVOUT_OutputParams_t;

typedef union  STVOUT_TargetInformation_u
{
    STVOUT_SinkInformation_t SinkInfo;
}STVOUT_TargetInformation_t;

typedef struct STVOUT_HDMIAudioParams_s
{
   U8 NumberOfChannel;
   U8 SpdifDivider;
   U8 SpdifCTSDivider;
   U32 AudioFrequency;
   BOOL IsCTSBypass;
   BOOL IsAudioCompressed;
   STVOUT_AudioDataType_t AudioType;

}STVOUT_HDMIAudioParams_t;

typedef union STVOUT_TargetAudioParams_u
{
     STVOUT_HDMIAudioParams_t   AudioParams;

}STVOUT_TargetAudioParams_t;

typedef U32 STVOUT_Handle_t;

typedef struct STVOUT_HdsvmCell_s
{
    void*                   DeviceBaseAddress_p;
    void*                   BaseAddress_p;
} STVOUT_HdsvmCell_t;

typedef struct STVOUT_GenericCell_s
{
    ST_DeviceName_t         DencName;
    void*                   DeviceBaseAddress_p;
    void*                   BaseAddress_p;
} STVOUT_GenericCell_t;

typedef struct STVOUT_DualTriDacCell_s
{
    ST_DeviceName_t         DencName;             /* only for target STVOUT_DEVICE_TYPE_5528*/
    void*                   DeviceBaseAddress_p; /* only for target STVOUT_DEVICE_TYPE_5528*/
    void*                   BaseAddress_p;       /* only for target STVOUT_DEVICE_TYPE_5528*/
    STVOUT_DAC_t            DacSelect;           /* only for target STVOUT_DEVICE_TYPE_5528*/
    BOOL                    HD_Dacs;
    STVOUT_Format_t         Format;
 }STVOUT_DualTriDacCell_t;

 typedef struct STVOUT_EnhancedDacCell_s
{
    ST_DeviceName_t         DencName;             /* for target STVOUT_DEVICE_TYPE_7200*/
    ST_DeviceName_t         VTGName;              /* for target STVOUT_DEVICE_TYPE_7200*/
    void*                   DeviceBaseAddress_p;  /* for target STVOUT_DEVICE_TYPE_7200*/
    void*                   BaseAddress_p;        /* for target STVOUT_DEVICE_TYPE_7200*/
    STVOUT_DAC_t            DacSelect;            /* for target STVOUT_DEVICE_TYPE_7200*/
    BOOL                    HD_Dacs;
    STVOUT_Format_t         Format;

}STVOUT_EnhancedDacCell_t;


typedef struct STVOUT_EnhancedCell_s
{
    ST_DeviceName_t        DencName;  /*only for target STVOUT_DEVICE_TYPE_DENC_ENHANCED */
    STVOUT_DAC_t           DacSelect; /*only for target STVOUT_DEVICE_TYPE_DENC_ENHANCED */
}STVOUT_EnhancedCell_t;

typedef struct STVOUT_EnhancedDvoCell_s
{
    ST_DeviceName_t         VTGName;              /* Nedded to setup Flex DVO AWG firmware for each installed VTG Mode*/
    void*                   BaseAddress_p;        /* For further use */
    void*                   DeviceBaseAddress_p;  /* not used */
    void*                   DVOBaseAddress_p;     /* Needed to enable/setup/disable Flex DVO cell */
}STVOUT_EnhancedDvoCell_t;

typedef struct STVOUT_OnChip_s
{
    ST_DeviceName_t        I2CDevice;
    ST_DeviceName_t        PIODevice;             /*only for target STVOUT_DEVICE_TYPE_7710 &7100: Hot plug detection*/
    U8                     HPD_Bit;
    BOOL                   IsHPDInversed;
    void*                  DeviceBaseAddress_p;  /* only for target STVOUT_DEVICE_TYPE_7710 &7100*/
    void*                  BaseAddress_p;        /* only for target STVOUT_DEVICE_TYPE_7710 &7100 : HDMI cell*/
    void*                  SecondBaseAddress_p;  /* only for target STVOUT_DEVICE_TYPE_7710 &7100: HDCP Cell*/
}STVOUT_OnChip_t;

typedef struct STVOUT_OnChipOne_s
{
    ST_DeviceName_t        I2CDevice;
    ST_DeviceName_t        PIODevice;
    U8                     HPD_Bit;
    BOOL                   IsHPDInversed;
    void*                  DeviceBaseAddress_p;  /* only for target 710X with CEC software solution */
    void*                  BaseAddress_p;        /* only for target 710X with CEC software solution */
    void*                  SecondBaseAddress_p;  /* only for target 710X with CEC software solution */
    ST_DeviceName_t        PWMName;
    ST_DeviceName_t        CECPIOName;
    U8                     CECPIO_BitNumber;
}STVOUT_OnChipOne_t;

typedef struct STVOUT_OnChipTwo_s
{
    ST_DeviceName_t        I2CDevice;  /* only for target 7200 & 7111 */
    ST_DeviceName_t        PIODevice;
    U8                     HPD_Bit;
    BOOL                   IsHPDInversed;
    void*                  DeviceBaseAddress_p;
    void*                  BaseAddress_p;
    void*                  SecondBaseAddress_p;
    void*                  CECBaseAddress_p;
    U32                    CECInterruptNumber;
    U32                    CECInterruptLevel;
} STVOUT_OnChipTwo_t;
#if (STVOUT_DEVTYPE >= STVOUT_DEVTYPE_7108)
typedef struct STVOUT_OnChipThree_s
{
    ST_DeviceName_t        I2CDevice;  /* only for target 7108 */
    ST_DeviceName_t        PIODevice;
    U8                     HPD_Bit;
    BOOL                   IsHPDInversed;
    BOOL                   IsRxSensEnabled;
    void*                  DeviceBaseAddress_p;
    void*                  BaseAddress_p;
    void*                  SecondBaseAddress_p;
    void*                  CECBaseAddress_p;
    U32                    CECInterruptNumber;
    U32                    CECInterruptLevel;
    U32                    CECWakeUpInterruptNumber;
    U32                    CECWakeUpInterruptLevel;
} STVOUT_OnChipThree_t;
#endif

typedef struct STVOUT_HDMICell_s
{
    U32                 InterruptNumber;
    U32                 InterruptLevel;
    ST_DeviceName_t     VTGName;
    ST_DeviceName_t     EventsHandlerName;
	STAVMEM_PartitionHandle_t	AVMEMPartition;
    union
    {
        STVOUT_OnChip_t      OnChipHdmiCell;
        STVOUT_OnChipOne_t   OnChipHdmiCellOne; /* only for target 710X with CEC software solution */
        STVOUT_OnChipTwo_t   OnChipHdmiCellTwo; /* only for target 7111 & 7200 with CEC IP */
#if (STVOUT_DEVTYPE >= STVOUT_DEVTYPE_7108)
        STVOUT_OnChipThree_t OnChipHdmiCellThree;  /* only for target 7108 */
#endif
    }Target;
    BOOL HSyncActivePolarity; /* Horizental sync polarity : TRUE for high, FALSE for low*/
    BOOL VSyncActivePolarity; /* Vertical sync polarity : TRUE for high, FALSE for low*/
    BOOL IsHDCPEnable;      /* TRUE: encryption used, FALSE: no */
}STVOUT_HDMICell_t;


typedef struct STVOUT_InitParams_s
{
    STVOUT_DeviceType_t         DeviceType;
    ST_Partition_t*             CPUPartition_p; /* CPUPartition to be used */
    U32                         MaxOpen;        /* MaxOpen authorized */
    /* device type dependant parameters */
    union
    {
        ST_DeviceName_t          DencName;        /* for target STVOUT_DEVICE_TYPE_7015...*/
        STVOUT_HdsvmCell_t       HdsvmCell;       /* for target STVOUT_DEVICE_TYPE_7015 and ..DIGITAL_OUTPUT */
        STVOUT_GenericCell_t     GX1Cell;         /* for target STVOUT_DEVICE_TYPE_GX1 only, kept for backward compatibility */
        STVOUT_GenericCell_t     GenericCell;     /* for target STVOUT_DEVICE_TYPE_7020...*/
        STVOUT_DVOCell_t         DVOCell;         /* for digital-output type with STi5528 type */
        STVOUT_DualTriDacCell_t  DualTriDacCell;  /* for target STVOUT_DEVICE_TYPE_7100*/
        STVOUT_EnhancedDacCell_t EnhancedDacCell; /* for target STVOUT_DEVICE_TYPE_7200 */
        STVOUT_EnhancedCell_t    EnhancedCell;    /* for target STVOUT_DEVICE_TYPE_DENC_ENHANCED */
        STVOUT_HDMICell_t        HDMICell;
        STVOUT_EnhancedDvoCell_t EnhancedDvoCell; /* for digital-output type with 7111, 7105, 7141, 7200, 7108, and 5206 */
    } Target;
    STVOUT_OutputType_t         OutputType;  /* output to be initialised */
} STVOUT_InitParams_t;

typedef struct STVOUT_OpenParams_s
{
    U8 NotUsed;
} STVOUT_OpenParams_t;

typedef struct STVOUT_TermParams_s
{
    BOOL                            ForceTerminate;
} STVOUT_TermParams_t;

typedef int STVOUT_Level_t;

typedef struct STVOUT_Limits_s
{
    STVOUT_Level_t      Min;
    STVOUT_Level_t      Max;
    STVOUT_Level_t      Step;
} STVOUT_Limits_t;

typedef struct STVOUT_Capability_s
{
    STVOUT_OutputType_t                 SupportedOutputs;
    STVOUT_OutputType_t                 SelectedOutput;
    /* */
    BOOL                                AnalogOutputsAdjustableCapable;
    STVOUT_AnalogProgrammableOutput_t   SupportedAnalogOutputsAdjustable;
    STVOUT_Limits_t                     RGB;
    STVOUT_Limits_t                     YC;
    STVOUT_Limits_t                     YCRatio;
    STVOUT_Limits_t                     CVBS;
    STVOUT_Limits_t                     YUV;
    /* */
    BOOL                                AnalogPictureControlCapable;
    STVOUT_Limits_t                     Brightness;
    STVOUT_Limits_t                     Contrast;
    STVOUT_Limits_t                     Saturation;
    /* */
    BOOL                                AnalogLumaChromaFilteringCapable;
    BOOL                                EmbeddedSynchroCapable;
    BOOL                                HDCPCapable;

} STVOUT_Capability_t;

typedef struct STVOUT_DAC_CONF_s
{
   STVOUT_DACOutput_t AuthorizedConfiguration[3];
   U8 Configuration;
 }STVOUT_DAC_CONF_t;

typedef struct STVOUT_AWG_Amplitude_s
{
	U16	Scaling_factor_Cb;
	U16	Scaling_factor_Y;
	U16	Scaling_factor_Cr;
	S16	Offset_factor_Cb;
	S16	Offset_factor_Y;
	S16	Offset_factor_Cr;

}STVOUT_AWG_Amplitude_t;


typedef struct STVOUT_HDCPParams_s
{
  U32   IV_0;
  U32   IV_1;
  U32   KSV_0;
  U32   KSV_1;
  U32   DeviceKeys[80];
  U32   IRate;
  BOOL  IsACEnabled;
}STVOUT_HDCPParams_t;

typedef struct STVOUT_HDCPSinkParams_s
{
  BOOL IsRepeater;
  BOOL IsFastDevice;
  BOOL ISHDCPOptionSupported;
  BOOL IsFastReauthentication;
  BOOL IsHDMIMode;
  BOOL IsMaxlevels;
  BOOL IsMaxDevs;
  U32  Depth;
  U32  DeviceCount;
}STVOUT_HDCPSinkParams_t;

typedef struct STVOUT_DefaultOutput_s
{
  U32  DataChannel0;
  U32  DataChannel1;
  U32  DataChannel2;
}STVOUT_DefaultOutput_t;

typedef struct STVOUT_Statistics_s
{
    U32 InterruptNewFrameCount;
    U32 InterruptHotPlugCount;
    U32 InterruptSoftResetCount;
    U32 InterruptInfoFrameCount;
    U32 InterruptPixelCaptureCount;
    U32 InterruptDllLockCount;
    U32 InfoFrameOverRunError;
    U32 SpdifFiFoOverRunCount;
    U32 InfoFrameCountGeneralControl;
    U32 InterruptGeneralControlCount;
    U32 InterruptGamutPktCount;
    U32 GamutPerVsincPktNumber;
    U32 GamutTotalPktNumber;
}STVOUT_Statistics_t;


typedef struct STVOUT_CECDevice_s
{
    STVOUT_CECRole_t  Role;
	U8 LogicalAddress;
}STVOUT_CECDevice_t;


typedef struct STVOUT_CECMessage_s
{
    U8  Retries;
    U8  Source;
    U8  Destination;
    U8 Data[STVOUT_MAX_CEC_MESSAGE_LENGTH];
    U8 DataLength; /*Must be less than STVOUT_MAX_CEC_MESSAGE_LENGTH bytes*/
}STVOUT_CECMessage_t;

typedef struct STVOUT_CECMessageInfo_s
{
    STVOUT_CECStatus_t  Status;
	STVOUT_CECMessage_t	Message;
}STVOUT_CECMessageInfo_t;

typedef struct STVOUT_Preemphasis_s
{
   STVOUT_DefaultOutput_t Tap1;
   STVOUT_DefaultOutput_t Tap2;
   STVOUT_DefaultOutput_t Tap3;
}STVOUT_Preemphasis_t;

typedef struct STVOUT_PreemphasisConfig_s
{
    BOOL IsPreemphasisByPass;
    STVOUT_Preemphasis_t PreempControl;
    STVOUT_DefaultOutput_t Single;
    STVOUT_DefaultOutput_t Differentiel;
}STVOUT_PreemphasisConfig_t;

typedef struct STVOUT_ForcedColor_s
{
    BOOL Enable;
    U8 R_PR;
    U8 G_Y;
    U8 B_PB;
    #if defined (WA_RnDHV49440) || defined (WA2_RnDHV49440)
    BOOL R_B_invert;
    #endif
}STVOUT_ForcedColor_t;

/* Exported Variables ----------------------------------------------------- */

/* Exported Macros -------------------------------------------------------- */



#ifdef __cplusplus
extern "C" {
#endif

/* Exported Functions ----------------------------------------------------- */

ST_Revision_t  STVOUT_GetRevision (
                void
                    );
ST_ErrorCode_t STVOUT_GetCapability (
                const ST_DeviceName_t         DeviceName,
                STVOUT_Capability_t*          const Capability_p
                );

ST_ErrorCode_t STVOUT_Init (
                const ST_DeviceName_t         DeviceName,
                const STVOUT_InitParams_t*    const InitParams_p
                );
ST_ErrorCode_t STVOUT_Open (
                const ST_DeviceName_t         DeviceName,
                const STVOUT_OpenParams_t*    const OpenParams_p,
                STVOUT_Handle_t*              const Handle_p
                );
ST_ErrorCode_t STVOUT_Close (
                const STVOUT_Handle_t         Handle
                );
ST_ErrorCode_t STVOUT_Term (
                const ST_DeviceName_t         DeviceName,
                const STVOUT_TermParams_t*    const TermParams_p
                );

ST_ErrorCode_t STVOUT_Disable(
                const STVOUT_Handle_t         Handle
                );
ST_ErrorCode_t STVOUT_Enable(
                const STVOUT_Handle_t         Handle
                );

ST_ErrorCode_t STVOUT_SetOutputParams(
                const STVOUT_Handle_t         Handle,
                const STVOUT_OutputParams_t*  const OutputParams_p
                );
ST_ErrorCode_t STVOUT_GetOutputParams(
                const STVOUT_Handle_t         Handle,
                STVOUT_OutputParams_t*        const OutputParams_p
                );
ST_ErrorCode_t STVOUT_SetOption (
                const STVOUT_Handle_t         Handle,
                const STVOUT_OptionParams_t*  const OptionParams_p
                );
ST_ErrorCode_t STVOUT_GetOption (
                const STVOUT_Handle_t         Handle,
                STVOUT_OptionParams_t*        const OptionParams_p
                );
ST_ErrorCode_t STVOUT_SetInputSource(
                const STVOUT_Handle_t         Handle,
                STVOUT_Source_t               Source
                );
ST_ErrorCode_t STVOUT_GetDacSelect(
               const STVOUT_Handle_t          Handle,
               U8*   const                    DacSelect_p
               );


ST_ErrorCode_t STVOUT_AdjustChromaLumaDelay( const STVOUT_Handle_t     Handle,
                                             const STVOUT_ChromaLumaDelay_t  CLDelay);

/*AWG Sync calibration APIs : available only for 7200/7111/7105/7141/5206/7108*/

ST_ErrorCode_t STVOUT_SetSyncCalibration(const STVOUT_Handle_t     Handle,
                const STVOUT_AWG_Amplitude_t* AWG_Amplitude);

ST_ErrorCode_t STVOUT_ResetSyncCalibration (const STVOUT_Handle_t     Handle);

ST_ErrorCode_t STVOUT_GetSyncCalibration (const STVOUT_Handle_t     Handle,
                STVOUT_AWG_Amplitude_t* AWG_Amplitude );

/* HDMI APIs*/

ST_ErrorCode_t STVOUT_Start(
                const STVOUT_Handle_t         Handle
                );

ST_ErrorCode_t STVOUT_GetState(
               const STVOUT_Handle_t         Handle,
               STVOUT_State_t*         const State_p
               );

ST_ErrorCode_t STVOUT_GetTargetInformation(
               const STVOUT_Handle_t                Handle,
               STVOUT_TargetInformation_t*    const TargetInformation_p
               );

ST_ErrorCode_t STVOUT_SendData(
               const STVOUT_Handle_t                Handle,
               const STVOUT_InfoFrameType_t         InfoFrameType,
               U8* const                            Buffer_p,
               U32                                  Size
               );

ST_ErrorCode_t STVOUT_StopSendData(
               const STVOUT_Handle_t                Handle,
               const STVOUT_InfoFrameType_t         InfoFrameType
               );

ST_ErrorCode_t STVOUT_SetHDCPParams(
               const STVOUT_Handle_t                Handle,
               const STVOUT_HDCPParams_t*           const HDCPParams_p
               );

ST_ErrorCode_t STVOUT_GetHDCPSinkParams(
               const STVOUT_Handle_t                Handle,
               STVOUT_HDCPSinkParams_t*             const HDCPSinkParams_p
               );
ST_ErrorCode_t STVOUT_UpdateForbiddenKSVs(
               const STVOUT_Handle_t                Handle,
               U8* const                            KSVList_p,
               U32 const                            KSVNumber
               );

ST_ErrorCode_t STVOUT_GetStatistics(
               const STVOUT_Handle_t                Handle,
               STVOUT_Statistics_t*                 const Statistics_p
               );

ST_ErrorCode_t STVOUT_EnableDefaultOutput(
               const STVOUT_Handle_t                Handle,
               const STVOUT_DefaultOutput_t*        const DefaultOutput_p
               );

ST_ErrorCode_t STVOUT_DisableDefaultOutput(
               const STVOUT_Handle_t                Handle
               );

ST_ErrorCode_t STVOUT_SetHDMIOutputType(
               const STVOUT_Handle_t                Handle,
               STVOUT_OutputType_t                  OutputType
               );

ST_ErrorCode_t STVOUT_SendCECMessage(   const STVOUT_Handle_t   Handle,
                                        const STVOUT_CECMessage_t * const Message_p);

#if (STVOUT_DEVTYPE >= STVOUT_DEVTYPE_7108)
ST_ErrorCode_t STVOUT_SetPreemphasisConfig(const STVOUT_Handle_t   Handle,
                                           const STVOUT_PreemphasisConfig_t * const Preemphasis_p);

ST_ErrorCode_t STVOUT_GetPreemphasisConfig(const STVOUT_Handle_t   Handle,
                                           STVOUT_PreemphasisConfig_t * const Preemphasis_p);
#endif


ST_ErrorCode_t STVOUT_CECPhysicalAddressAvailable(
               const STVOUT_Handle_t   Handle
               );

ST_ErrorCode_t STVOUT_CECSetAdditionalAddress(
               const STVOUT_Handle_t Handle,
               const STVOUT_CECRole_t Role
               );

ST_ErrorCode_t STVOUT_CECWakeUpDevice(
               const STVOUT_Handle_t Handle,
               BOOL                  IsWakeUpDevice
               );


ST_ErrorCode_t STVOUT_SetTargetAudioParams(
               const STVOUT_Handle_t                Handle,
               const STVOUT_TargetAudioParams_t*    const AudioTargetParams_p
               );

ST_ErrorCode_t STVOUT_GetTargetAudioParams(
               const STVOUT_Handle_t                Handle,
               STVOUT_TargetAudioParams_t*          const AudioTargetParams_p
               );

#if defined (STPOWER_SUPPORTED)
ST_ErrorCode_t STVOUT_SetHdmiPowerState(
               const STVOUT_Handle_t 				Handle,
               const STPOWER_State_t 				DeviceState
			   );

ST_ErrorCode_t STVOUT_GetHdmiPowerState(
               const STVOUT_Handle_t 				Handle,
               STPOWER_State_t *	const			DeviceState
			   );
#endif
ST_ErrorCode_t STVOUT_ForceColor(
               const STVOUT_Handle_t         Handle,
			   const STVOUT_ForcedColor_t ForcedColor
               );
ST_ErrorCode_t STVOUT_AVMute(
               const STVOUT_Handle_t         Handle,
			   const BOOL Enable
               );
/******************************************************************************
 * Un-supported extensions (debug only) ---------------------------------------

   WARNING (do not remove)
   =======
   Every user of this code must be made aware of the following limitations.
   This section's API's are extensions to the STVOUT API, for debugging and testing
   purposes only. They are not part of the STVOUT product delivery, they don't
   contain driver features used in production. They are not compiled by default.
   They may change without notice. They may contain errors, are not tested. They
   may be not supported on some platforms, may change the driver normal behaviour.
   Application code such as reference software or customer application may use
   them at their own risks and not for production. There will be no support.
 ******************************************************************************/
#if defined (STVOUT_DEBUG)
ST_ErrorCode_t STVOUT_GetHDCPBcaps(
               const STVOUT_Handle_t                Handle,
               U8*                                  BcapsBuffer_p
               );

ST_ErrorCode_t STVOUT_GetHDCPBstatus(
               const STVOUT_Handle_t                Handle,
               U16*                                 BstatusBuffer_p
               );

ST_ErrorCode_t STVOUT_SetHDCPAuthenticationDelay(
               const STVOUT_Handle_t                Handle,
               U32                                  HDCPDelay
               );


ST_ErrorCode_t STVOUT_SetEnhancedLinkVerification(
               const STVOUT_Handle_t                Handle,
               BOOL                                 IsEnhancedLinkEnabled
               );
#endif  /* #if defined (STVOUT_DEBUG) */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef __STVOUT_H */

/* End of stvout.h */
