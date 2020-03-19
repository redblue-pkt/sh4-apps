/******************************************************************************/
/* COPYRIGHT (C) 2009 STMicroelectronics - All Rights Reserved               				   */
/* ST makes no warranty express or implied including but not limited to,     				   */
/* any warranty of                                                           							   */
/*                                                                           								   */
/*   (i)  merchantability or fitness for a particular purpose and/or         					   */
/*   (ii) requirements, for a particular purpose in relation to the LICENSED 				   */
/*        MATERIALS, which is provided AS IS, WITH ALL FAULTS. ST does not   			   */
/*        represent or warrant that the LICENSED MATERIALS provided here     			   */
/*        under is free of infringement of any third party patents,          					   */
/*        copyrights, trade secrets or other intellectual property rights.   					   */
/*        ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE       		   */
/*        EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                    			   */
/*                                                                           								   */
/*****************************************************************************/

/**
	@file	      stclkrv.h
   	@brief    Contains all the structures and macros used in the driver

**/


/* Modified to include multi-instance support */

/* Define to prevent recursive inclusion */
#ifndef __STCLKRV_H
#define __STCLKRV_H

/* Includes --------------------------------------------------------------- */
#include "stddefs.h"
#include "stcommon.h"
#include "stpti.h"


#ifdef __cplusplus
extern "C" {
#endif

/* Exported Constants ----------------------------------------------------- */
#define STCLKRV_DRIVER_ID               72
#define STCLKRV_DRIVER_BASE                    ( STCLKRV_DRIVER_ID << 16 )
#define STCLKRV_STAT_VERSION_BASE        (0x434c4b << 8)        /*ASCII `CLK' << 8*/
#define STCLKRV_STAT_VERSION_LAST        ((0x434c4b+1) << 8) /*ASCII `CLL' << 8*/
#define STCLKRV_STAT_MAGIC                      (0x53544154)              /*ASCII 'STAT' */


#define STATIC_CLKRV_ASSERT(expr, msg) \
extern const char STATIC_CLKRV_ASSERTION__##msg[(expr)?1:-1]


/* External return codes */
#define STCLKRV_ERROR_BASE              STCLKRV_DRIVER_BASE

#define STCLKRV_ERROR_HANDLER_INSTALL   ( STCLKRV_ERROR_BASE )
#define STCLKRV_ERROR_PCR_UNAVAILABLE   ( STCLKRV_ERROR_BASE + 1 )
#define STCLKRV_ERROR_EVT_REGISTER      ( STCLKRV_ERROR_BASE + 2 )
#define STCLKRV_ERROR_INVALID_FREQUENCY ( STCLKRV_ERROR_BASE + 3 )
#define STCLKRV_ERROR_INVALID_SLAVE     ( STCLKRV_ERROR_BASE + 4 )
#define STCLKRV_ERROR_INVALID_PCR          ( STCLKRV_ERROR_BASE + 5 )

#define STCLKRV_NB_REGISTERED_EVENTS    4      /* Number of events registered with STEVT */
#define STCLKRV_NB_SUBSCRIBED_EVENTS    1      /* Number of events subscribed to   */

/* General Init paramaters values */
/* Filter window size parameters, Defaults given for Satellite */
/* Larger the Window stable is the PWM, Slower the response */
#define STCLKRV_MIN_SAMPLE_THRESHOLD 3      /* Number of samples to recieve before PWM correction */
                                            /* Min Window For Satellite - 3 */
                                            /* Min Window For Terrestrial - 50 */

#define STCLKRV_MAX_WINDOW_SIZE      150     /* Maximum number samples in moving average window */

                                            /* Max Window For Satellite - 30 */
                                            /* Max Window For Terrestrial - 150 */
#define STCLKRV_PCR_DRIFT_THRES      200    /* For Satellite = 200 */
                                            /* For Terrestrial(1/8 gaurd interval) = 10000 */
                                            /* For Terrestrial(1/32 gaurd interval) = 2500 */
#define STCLKRV_PCR_MAX_GLITCH       2      /* number of bad PCRs pre re-basing */
                                            /* threshold for Error */


/* Exported Types --------------------------------------------------------- */

/* Application Modes */
#if defined (ST_7710)||defined(ST_7100) || defined(ST_7111) || defined(ST_7105) || defined(ST_7141) \
	|| defined (ST_7108) || defined(ST_5206) || defined(ST_H205)
typedef enum STCLKRV_ApplicationMode_e
{
    STCLKRV_APPLICATION_MODE_NORMAL,
    STCLKRV_APPLICATION_MODE_DVO1_SD_ONLY,
    STCLKRV_APPLICATION_MODE_SD_ONLY = 1
}STCLKRV_ApplicationMode_t;
#endif

/* Clock Sources */
typedef enum STCLKRV_Clock_e
{
    STCLKRV_CLOCK_SD_0,            /* Primary SD/pixel Clock on All chips */
    STCLKRV_CLOCK_SD_1,            /* Secondary SD/pixel Clock on 5525/7200 */
#if defined (ST_5197) || defined(ST_5206)
    STCLKRV_CLOCK_PIX,   		    /* 'clk_pix' fed to the DENC in 5197. 'clk_spare' drives the STC and hence is the one to be recovered
                                                        in 5206 sd_0->27mhz getting recovered pix->pix_sd fed to denc unrecovered*/
#endif
    STCLKRV_CLOCK_PCM_0,           /* Audio main PCM Clock on All chips */
    STCLKRV_CLOCK_PCM_1,           /* FS Audio PCM_1 Clock on 7100/5525/7200 */
    STCLKRV_CLOCK_PCM_2,           /* FS Audio PCM_2 Clock on 5525/7200 */
    STCLKRV_CLOCK_PCM_3,           /* FS Audio PCM_3 Clock on 5525/7200 */
    STCLKRV_CLOCK_SPDIF_HDMI_0,    /* FS Audio HDMI Clock on 7200 */
    STCLKRV_CLOCK_SPDIF_0,         /* Audio SPDIF 5100/5105/5301/5107/7100/5525/7200/5162 (on 7710 spdif derived by PCM0) */
    STCLKRV_CLOCK_HD_0,            /* High Definition 7710/7100/7200 */
    STCLKRV_CLOCK_HD_1             /* High Definition 7200 */
}STCLKRV_ClockSource_t;

/* Clock Decodes
   On 5525, Dual decode is possible */
typedef enum STCLKRV_Decode_e
{
    STCLKRV_DECODE_PRIMARY,        /* Primary decode by default on all chips */
    STCLKRV_DECODE_SECONDARY       /* Supported only on 5525 */
}STCLKRV_Decode_t;

/* PCR Source */
typedef enum STCLKRV_PCRSource_e
{
    STCLKRV_PCR_SOURCE_PTI

}STCLKRV_PCRSource_t;

/* STCLKRV STC source select values */
typedef enum STCLKRV_STCSource_e
{
    STCLKRV_STC_SOURCE_PCR,
    STCLKRV_STC_SOURCE_BASELINE,
    STCLKRV_STC_SOURCE_PCR_BASELINE  /*Added for MAIN AND PIP USECASE ONLY SINGLE CLKRV SUPPORTED SOC*/
}STCLKRV_STCSource_t;


typedef struct STCLKRV_WMAParams_s
{
   U32                 PCRDriftThres;      /* 200 suggested for SaTellite */
    U32                 MinSampleThres;     /* Minimum number of PCRs to average, 3 suggested (Satellite) */
    U32                 MaxWindowSize;      /* Maximum number of PCRs to average, 30 suggested (Satellite)*/

}STCLKRV_WMAParams_t;

typedef struct STCLKRV_LLRParams_s
{
  STCOMMON_JitterDistrib_e  JitterDistribType; /* Environment or jitter distribution type for IP */
    U32                                 MaxJitterValue; /* Maximum expected enviroment jitter -useful for IP */
    U32                                 MaxPCRRate; /* Stream PCR rate */

}STCLKRV_LLRParams_t;

typedef enum STCLKRV_SelectAlgo_e
{
    	STCLKRV_WMA,
    	STCLKRV_LLR

}STCLKRV_SelectAlgo_t;


typedef union Algo_Params_u
{
	STCLKRV_WMAParams_t WMAParams;
	STCLKRV_LLRParams_t   LLRParams;

}STCLKRV_Algo_Params;



typedef struct STCLKRV_Algo_s
{
	STCLKRV_SelectAlgo_t SelectedAlgo;
	STCLKRV_Algo_Params AlgoParams;
}STCLKRV_Algo_t;


/* PCR Source parameters type */
typedef struct STCLKRV_SourceParams_s
{
    STCLKRV_PCRSource_t Source;
    union
    {
        struct
        {

            STPTI_Slot_t Slot;

        }STPTI_s;
    }Source_u;
}STCLKRV_SourceParams_t;


/* Event Types */
typedef enum STCLKRV_Event_s
{
    STCLKRV_PCR_VALID_EVT          = STCLKRV_DRIVER_BASE,
    STCLKRV_PCR_DISCONTINUITY_EVT  = STCLKRV_DRIVER_BASE + 1,
    STCLKRV_PCR_GLITCH_EVT         = STCLKRV_DRIVER_BASE + 2,
    STCLKRV_PCR_END_EVT		= STCLKRV_DRIVER_BASE + 3
} STCLKRV_Event_t;

/*=========================================================
  5100,5301 and 5105,5107,5162 device type = STCLKRV_DEVICE_TYPE_5100
  7710 device type = STCLKRV_DEVICE_TYPE_7710
  7100 device type = STCLKRV_DEVICE_TYPE_7100
  5525 device type = STCLKRV_DEVICE_TYPE_5525
  7200 device type = STCLKRV_DEVICE_TYPE_7200
  =========================================================*/
/* STCLKRV Device type */
typedef enum STCLKRV_Device_e
{
    STCLKRV_DEVICE_TYPE_5100,               /* SD/PCM/SPDIF and clkrv tracking registers in clkgen block */
    STCLKRV_DEVICE_TYPE_7100,               /* SD/HD clkrv tracking registers in clkgen block,PCM clk in AUDCFG, PTI(STC) access */
    STCLKRV_DEVICE_TYPE_7710,
    STCLKRV_DEVICE_TYPE_H205,               /* Two decodes, Primary/Secondary */
    STCLKRV_DEVICE_TYPE_7200,				/* Two decodes, Primary/Secondary */
    STCLKRV_DEVICE_TYPE_BASELINE_ONLY
}STCLKRV_Device_t;


/* Clock recovery init params */
typedef struct STCLKRV_InitParams_s
{
    STCLKRV_Device_t    DeviceType;
    ST_Partition_t      *Partition_p;       /* Memory partition to use (mi) */

    /* STPTI & Clock recovery Events */
    ST_DeviceName_t     EVTDeviceName;      /* Clkrv event handler name */
    ST_DeviceName_t     PCREvtHandlerName;  /* PCR Event handler name (STPTI) */
    ST_DeviceName_t     PTIDeviceName;      /* To get access to PTI STC timer */

    /* Clock recovery Filter */
    U32                 PCRMaxGlitch;       /* 2 suggested */
    U32                 PCRDriftThres;      /* 200 suggested for SaTellite */
    U32                 MinSampleThres;     /* Minimum number of PCRs to average, 3 suggested (Satellite) */
    U32                 MaxWindowSize;      /* Maximum number of PCRs to average, 30 suggested (Satellite)*/

#ifdef ST_OS21                              /* Clock recovery module HW interrupt number */
    interrupt_name_t    InterruptNumber;
#else
    U32                 InterruptNumber;
#endif
    U32                 InterruptLevel;     /* Clock recovery module HW interrupt number */

    /* device type dependant parameters */
    void                *FSBaseAddress_p;   /* SD/PCM/SPDIF or HD clock FS and clkrv tracking registers 5100/7710 */
#if defined(ST_7100) ||defined(ST_7200) || defined(ST_7111) || defined(ST_7105) || defined(ST_7141) \
	|| defined (ST_5206) || defined(ST_7108) || defined(ST_H205)
    void                *AUDCFGBaseAddress_p; /* Audio clocks FS registers base address */
#else
    void                *ADSCBaseAddress_p; /* Audio clocks FS registers base address in 7710 only */
#endif
    /* On 5525/7200 there could be Primary/Secondary decode, Default 0 is primary */
    STCLKRV_Decode_t    DecodeType;
    void                *CRUBaseAddress_p;    /* Clock recovery unit base address for 7200 */
} STCLKRV_InitParams_t;

typedef struct STCLKRV_TermParams_s
{
    BOOL ForceTerminate;
} STCLKRV_TermParams_t;

typedef struct STCLKRV_ExtendedSTC_s
{
    U32 BaseBit32;        /* Bit 32 of the STC */
    U32 BaseValue;        /* Bits 31..0 of the STC in 90KHz units */
    U32 Extension;        /* 27MHz portion of the STC (modulo 300) */
} STCLKRV_ExtendedSTC_t;

typedef enum STCLKRV_StatisticsVersion_e
{
	STCLKRV_STAT_VERSION1 = STCLKRV_STAT_VERSION_BASE,
	/* Add new versions */
	STCLKRV_STAT_UNSUPPORTED
}STCLKRV_StatisticsVersion_t;

STATIC_CLKRV_ASSERT(!(STCLKRV_STAT_UNSUPPORTED>= STCLKRV_STAT_VERSION_LAST), Too_many_Versions_in_STCLKRV_StatisticsVersion_e);

typedef struct STCLKRV_StatStructVer1_s
{
	U32 PCRAccuracyErrorCounter;
	U32 PCRRepetitionErrorCounter;
	U32 PCRDiscontinuityCounter;
} STCLKRV_StatStructVer1_t;

typedef struct STCLKRV_Statistics_s
{
  U32                                        StatMagicNumber;                   /*Should be set to STCLKRV_STAT_MAGIC by caller*/
  STCLKRV_StatisticsVersion_t    Version;                                   /*Should be valid enum from STCLKRV_StatisticsVersion_e, to be set by caller*/
  union
  {
    STCLKRV_StatStructVer1_t      StatStructVer1;
                                                                                                /* No other versions at present */
  }Statistics;
}STCLKRV_Statistics_t;

typedef enum STCLKRV_SetupObject_e
{
	STCLKRV_SETUP_PTI_NAME= 0x0001	/* Setup object to set a PTIName to be connected to STCLKRV instance. */
} STCLKRV_SetupObject_t;


typedef struct STCLKRV_SetupParams_s
{
	STCLKRV_SetupObject_t SetupObject; /* Specify the kind of setup element to be processed. */
	union
	{
		ST_DeviceName_t PTIDeviceName; /* STCLKRV_SETUP_PTI_NAMESetup object parameter: PTI device Name to be connected to. */
	} SetupSettings;
}
STCLKRV_SetupParams_t;


typedef void* STCLKRV_OpenParams_t;         /* none required presently */
typedef U32  STCLKRV_Handle_t;


/* Exported Variables ----------------------------------------------------- */

/* Exported Macros -------------------------------------------------------- */

#define STCLKRV_GetDecodeClk( a, b )    STCLKRV_GetSTC( (a), (b) )

/* Exported Functions ----------------------------------------------------- */

ST_Revision_t STCLKRV_GetRevision(void);

ST_ErrorCode_t STCLKRV_Init(const ST_DeviceName_t Name, const STCLKRV_InitParams_t *InitParams);

ST_ErrorCode_t STCLKRV_Open(const ST_DeviceName_t Name, const STCLKRV_OpenParams_t *OpenParams, STCLKRV_Handle_t *Handle);

#if defined (ST_7710) || defined(ST_7100) || defined(ST_7111) || defined(ST_7105) || defined(ST_7141) \
	|| defined(ST_7108) || defined(ST_5206) || defined(ST_H205)

ST_ErrorCode_t STCLKRV_SetApplicationMode(STCLKRV_Handle_t Handle, STCLKRV_ApplicationMode_t AppMode);

#endif

ST_ErrorCode_t STCLKRV_GetRecoveryMethod(STCLKRV_Handle_t Handle , STCLKRV_Algo_t *SelectAlgorithm);

ST_ErrorCode_t STCLKRV_SetRecoveryMethod(STCLKRV_Handle_t Handle, STCLKRV_Algo_t SelectAlgorithm );

ST_ErrorCode_t STCLKRV_SetNominalFreq(STCLKRV_Handle_t Handle, STCLKRV_ClockSource_t ClockSource, U32 Frequency);

ST_ErrorCode_t STCLKRV_Close(STCLKRV_Handle_t Handle);

ST_ErrorCode_t STCLKRV_Term(const ST_DeviceName_t Name, const STCLKRV_TermParams_t *TermParams);

ST_ErrorCode_t STCLKRV_Enable(STCLKRV_Handle_t Handle);

ST_ErrorCode_t STCLKRV_SetSTCSource(STCLKRV_Handle_t Handle, STCLKRV_STCSource_t STCSource);

ST_ErrorCode_t STCLKRV_SetPCRSource(STCLKRV_Handle_t ClkHandle, STCLKRV_SourceParams_t *PCRSource);

ST_ErrorCode_t STCLKRV_SetSTCBaseline(STCLKRV_Handle_t Handle, STCLKRV_ExtendedSTC_t *STC);

ST_ErrorCode_t STCLKRV_SetSTCOffset(STCLKRV_Handle_t Handle, S32 STCOffset);

ST_ErrorCode_t STCLKRV_InvDecodeClk(STCLKRV_Handle_t Handle);

ST_ErrorCode_t STCLKRV_Disable(STCLKRV_Handle_t Handle);

ST_ErrorCode_t STCLKRV_GetSTC(STCLKRV_Handle_t Handle, U32 *STC );

ST_ErrorCode_t STCLKRV_GetExtendedSTC(STCLKRV_Handle_t Handle, STCLKRV_ExtendedSTC_t *ExtendedSTC);

ST_ErrorCode_t STCLKRV_GetStatistics(STCLKRV_Handle_t Handle,STCLKRV_Statistics_t *STCLKRV_Statistics_p);

ST_ErrorCode_t STCLKRV_ResetStatistics(STCLKRV_Handle_t Handle,STCLKRV_Statistics_t *STCLKRV_Statistics_p);

ST_ErrorCode_t STCLKRV_Setup( STCLKRV_Handle_t Handle, STCLKRV_SetupParams_t *SetupParams_p  ) ;


#if defined(ST_OSLINUX)
BOOL STCLKRV_IsAlreadyRegistered(const ST_DeviceName_t DeviceName);
#endif
int stclkrv_IPrC_Handler(U32 request, void *arg);
#ifdef __cplusplus
}
#endif

#endif /* #ifndef __STCLKRV_H */
/* End of stclkrv.h */
