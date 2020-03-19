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
 * @file     stapp_tuner.h
 * @brief    This is the tuner file header.
 *           It is used to set frequency on different digital sat/ter/cab tuners.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_TUNER_
#define _STAPP_TUNER_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
/* Here we define 4 tuners maximum for all the platforms */
#if !defined(MXL584_HYDRA_SUPPORT)
#define TUNER_MAX_NUMBER 4
#else
#define TUNER_MAX_NUMBER 8
#endif
#if !defined(DVD_FRONTEND_TUNER)
#undef TUNER_MAX_NUMBER
#endif

/* Includes */
/* -------- */
#if defined(TUNER_MAX_NUMBER)
#include "stfrontend.h"
#endif

/* Indicate if there is a need to support NON ST tuners */
/* ---------------------------------------------------- */
#if defined(TUNER_MAX_NUMBER)
#if defined(custom001012)
#if !defined(ST_OSLINUX)
#define TUNER_CUSTOM_SUPPORT
#endif
#endif
#if defined(custom001013)
#define TUNER_CUSTOM_SUPPORT
#endif
#if defined(custom001022)
#define TUNER_CUSTOM_SUPPORT
#endif
#if defined(custom001029)
#define TUNER_CUSTOM_SUPPORT
#endif
#if defined(custom001031)
#define TUNER_CUSTOM_SUPPORT
#endif
#endif

/* Frequencies band boundaries */
/* --------------------------- */
#if defined(TUNER_MAX_NUMBER)
#define TUNER_C_BAND_START         3000000 /*kHZ*/
#define TUNER_C_BAND_END           4200000 /*kHZ*/
#define TUNER_KU_LOW_BAND_START   10700000 /*kHZ*/
#define TUNER_KU_LOW_BAND_END     11700000 /*kHZ*/
#define TUNER_KU_HIGH_BAND_START  11700001 /*kHZ*/
#define TUNER_KU_HIGH_BAND_END    12750000 /*kHZ*/
#endif

/* Max Diseqc cmd length    */
/* ------------------------ */
#if defined(TUNER_MAX_NUMBER)
#define TUNER_MAX_DISEQC_CMD_LEN 16
#endif

/* Definition of the tuner mode */
/* ---------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_NUL = 0x00000000,
 TUNER_SAT = 0x10000000,
 TUNER_TER = 0x20000000,
 TUNER_CAB = 0x40000000,
 TUNER_VSB = 0x80000000
} TUNER_Mode_t;
#endif

/* Definition of the tuner type */
/* ---------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_NONE=0,
 TUNER_SAT_01_EVAL,
 TUNER_SAT_299_EVAL,
 TUNER_SAT_299_STEM,
 TUNER_SAT_299_6000_EVAL,
 TUNER_SAT_288_6000_EVAL,
 TUNER_SAT_288_6100_EVAL,
 TUNER_SAT_899_6100_EVAL,
 TUNER_SAT_399_EVAL,
 TUNER_SAT_900_6100_EVAL,
 TUNER_SAT_900_6110_EVAL_P1,
 TUNER_SAT_900_6110_EVAL_P2,
 TUNER_SAT_900_6111_EVAL,
 TUNER_SAT_900_6120_EVAL_P1,
 TUNER_SAT_900_6120_EVAL_P2,
 TUNER_SAT_903_6100_EVAL,
 TUNER_SAT_903_6110_EVAL,
 TUNER_SAT_903_6111_EVAL,
 TUNER_SAT_910_6110_EVAL,
 TUNER_SAT_910_6111_EVAL,
 TUNER_SAT_910_6120_EVAL,
 TUNER_SAT_913_6110_EVAL,
 TUNER_SAT_913_6111_EVAL,
 TUNER_SAT_913_6120_EVAL,
 TUNER_SAT_THOMSON_4122A,
 TUNER_SAT_PHILIPS_TDA10093,
 TUNER_SAT_5189,
 TUNER_SAT_5289_6110,
 TUNER_SAT_7111_6100,
 TUNER_SAT_7111_6110,
 TUNER_SAT_7111_6111,
 TUNER_SAT_7111_6130,
 TUNER_TER_ISDBT_NONE,
 TUNER_TER_ISDBT_EARDA,
 TUNER_TER_ISDBT_TDA18212,
 TUNER_TER_ISDBT_MXL683,
 TUNER_TER_360,
 TUNER_TER_361,
 TUNER_TER_362,
 TUNER_TER_362_4100,
 TUNER_TER_362_TDQD3,
 TUNER_TER_362_DTT73200,
 TUNER_TER_362_DTT75200,
 TUNER_TER_362_DTT7540X,
 TUNER_TER_362_MT2060,
 TUNER_TER_362_DNOS40ASH201A,
 TUNER_TER_367_4100,
 TUNER_TER_367_DTT7546,
 TUNER_TER_367_DTT7546_30MHZ,
 TUNER_TER_367_TDA18212,
 TUNER_TER_367_TDA18219,
 TUNER_TER_368_TDA18212,
 TUNER_TER_368_TDA18219,
 TUNER_TER_368_MXL603,
 TUNER_TER_370,
 TUNER_TER_370_DTT7600,
 TUNER_TER_372,
 TUNER_TER_RF4000_DRX397,
 TUNER_TER_SONY_FT3114,
 TUNER_TER_SONY_ASCOT2S,
 TUNER_TER_SONY_ASCOT2S_RE201,
 TUNER_TER_SONY_ASCOT2S_RE202,
 TUNER_TER_SONY_ASCOT2S_RE502,
 TUNER_TER_SONY_ASCOT2S_DE202,
 TUNER_TER_SONY_ASCOT2S_DE501,
 TUNER_TER_SONY_ASCOT2D,
 TUNER_TER_SONY_ASCOT2D_RE212V,
 TUNER_TER_SONY_ASCOT2D_A2DREF,
 TUNER_TER_SONY_TDA18212,
 TUNER_TER_SONY_TDA18219,
 TUNER_TER_SONY_CXD2831WR,
 TUNER_CAB_297,
 TUNER_CAB_297E_DCT7045,
 TUNER_CAB_297E_MXL203,
 TUNER_CAB_297J_MXL201,
 TUNER_CAB_297_MT2060,
 TUNER_CAB_297E_CD1100,
 TUNER_CAB_PHILIPS_TDA10023,
 TUNER_CAB_498_MT2011,
 TUNER_CAB_498_DCU4000,
 TUNER_CAB_7141_MT2011,
 TUNER_CAB_7141_MT2068,
 TUNER_CAB_7141_MT2082,
 TUNER_CAB_7141_MXL201,
 TUNER_CAB_7141_CUSTOM_02,
 TUNER_CAB_7141_TDA18260,
 TUNER_CAB_7141_TDA18250,
 TUNER_CAB_5197,
 TUNER_CAB_5197_CD1616LF,
 TUNER_CAB_7167_CD1616LF,
 TUNER_CAB_367_CD1100,
 TUNER_CAB_367_4100,
 TUNER_CAB_367_DTT7546,
 TUNER_CAB_367_DTT7546_30MHZ,
 TUNER_CAB_367_TDA18212,
 TUNER_CAB_367_TDA18250A,
 TUNER_CAB_368_TDA18212,
 TUNER_CAB_368_TDA18219,
 TUNER_CAB_368_MXL603,
 TUNER_CAB_SONY_ASCOT2D,
 TUNER_CAB_SONY_ASCOT2S,
 TUNER_CAB_SONY_TDA18212,
 TUNER_CAB_SONY_TDA18219,
 TUNER_CAB_REMOTE,
 TUNER_VSB_373_DTT768XX
} TUNER_Type_t;
#endif

/* Definition of the tuner connection */
/* ---------------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_SERIAL=0,
 TUNER_PARALLEL
} TUNER_Connect_t;
#endif

/* Definition of the tuner input */
/* ----------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_NO_CONNECT = 0x00,
 TUNER_TSIN_0     = 0x01,
 TUNER_TSIN_1     = 0x02,
 TUNER_TSIN_2     = 0x04,
 TUNER_TSIN_3     = 0x08,
 TUNER_TSIN_4     = 0x10,
 TUNER_TSIN_5     = 0x20
} TUNER_TsInput_t;
#endif

/* Definition of the tuner modulation */
/* ---------------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_MOD_NONE,
 TUNER_MOD_QPSK,
 TUNER_MOD_8PSK,
 TUNER_MOD_QAM,
 TUNER_MOD_4QAM,
 TUNER_MOD_16QAM,
 TUNER_MOD_32QAM,
 TUNER_MOD_64QAM,
 TUNER_MOD_128QAM,
 TUNER_MOD_256QAM,
 TUNER_MOD_BPSK,
 TUNER_MOD_8VSB,
 TUNER_MOD_16APSK,
 TUNER_MOD_32APSK,
 TUNER_MOD_ALL
} TUNER_Modulation_t;
#endif

/* Definition of the tuner fec rate */
/* ------------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_FEC_NONE,
 TUNER_FEC_ALL,
 TUNER_FEC_1_2,
 TUNER_FEC_2_3,
 TUNER_FEC_3_4,
 TUNER_FEC_4_5,
 TUNER_FEC_5_6,
 TUNER_FEC_6_7,
 TUNER_FEC_7_8,
 TUNER_FEC_8_9,
 TUNER_FEC_1_4,
 TUNER_FEC_1_3,
 TUNER_FEC_2_5,
 TUNER_FEC_3_5,
 TUNER_FEC_9_10,
 TUNER_J83_A,
 TUNER_J83_B,
 TUNER_J83_C
} TUNER_FecRate_t;
#endif

/* Definition of the tuner polarity type */
/* ------------------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_PLR_NONE,
 TUNER_PLR_ALL,
 TUNER_PLR_HORIZONTAL,
 TUNER_PLR_VERTICAL
} TUNER_Polarity_t;
#endif

/* Definition of the tuner fec type */
/* -------------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_FEC_TYPE_NONE,
 TUNER_FEC_TYPE_DVBS1,
 TUNER_FEC_TYPE_DVBS2,
 TUNER_FEC_TYPE_ADCM_QPSK,
 TUNER_FEC_TYPE_ADCM_8PSK,
 TUNER_FEC_TYPE_AUTO_SEARCH,
 TUNER_FEC_TYPE_DTV,
 TUNER_DVB_TYPE_DVBT,
 TUNER_DVB_TYPE_DVBT2
} TUNER_FecType_t;
#endif

/* Definition of the tuner channel BW type */
/* --------------------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_CHAN_BW_NONE,
 TUNER_CHAN_BW_5M,
 TUNER_CHAN_BW_6M,
 TUNER_CHAN_BW_7M,
 TUNER_CHAN_BW_8M,
 TUNER_CHAN_BW_10M,
 TUNER_CHAN_BW_17M
} TUNER_ChanBWType_t;
#endif

/* Definition of the tuner spectrum */
/* -------------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_INVERSION_NONE,
 TUNER_INVERSION,
 TUNER_INVERSION_AUTO,
 TUNER_INVERSION_UNK
} TUNER_Spectrum_t;
#endif

/* Definition of the tuner lnb status */
/* ---------------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_LNB_TONE_NONE,
 TUNER_LNB_TONE_DEFAULT,
 TUNER_LNB_TONE_OFF,
 TUNER_LNB_TONE_22KHZ
} TUNER_LnbState_t;
#endif

/* Definition of the tuner lnb status */
/* ---------------------------------- */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_STATE_NONE,
 TUNER_STATE_IDLE,
 TUNER_STATE_STANDBY,
 TUNER_STATE_UNLOCKED,
 TUNER_STATE_SCANNING,
 TUNER_STATE_LOCKED
} TUNER_State_t;
#endif

/* Definition of the tuner status */
/* ------------------------------ */
#if defined(TUNER_MAX_NUMBER)
typedef struct
{
 U32 TUNER_FrequencyKhz;
 U32 TUNER_SymbolRate;
 U32 TUNER_ChannelBW;
 U32 TUNER_Modulation;
 U32 TUNER_FecRate;
 U32 TUNER_FecType;
 U32 TUNER_Polarity;
 U32 TUNER_LnbState;
 U32 TUNER_State;
 U32 TUNER_SignalQuality;
 U32 TUNER_BitErrorRate;
 S32 TUNER_RFLevel;
 U8  TUNER_PLPId;
 S32 TUNER_SSI;
 S32 TUNER_LDPC_Iterations;
 S32 TUNER_SNRdb;
 S32 TUNER_SQI;
} TUNER_Status_t;
#endif

/* Local definitions */
/* ----------------- */
#if defined(TUNER_MAX_NUMBER)
typedef struct TUNER_Params
{
 U32              TUNER_Index;
 char            *TUNER_Name;
 TUNER_Type_t     TUNER_Type;
 U32              TUNER_DemodI2cBus;
 U32              TUNER_DemodI2cAddress;
 U32              TUNER_TunerI2cBus;
 U32              TUNER_TunerI2cAddress;
 U32              TUNER_LnbI2cBus;
 U32              TUNER_LnbI2cAddress;
 TUNER_TsInput_t  TUNER_Input;
 TUNER_Connect_t  TUNER_Connect;
 BOOL             TUNER_InvertBitClock;
} TUNER_Params_t;
#endif

/* Definition of Framing byte of DiseqC Bus Cmd  */
/* -------------------------------------------   */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_DISEQC_CMD_FRM_MASTER_IST_TX               = 0xE0,
 TUNER_DISEQC_CMD_FRM_MASTER_REPEATED_TX          = 0xE1,
 TUNER_DISEQC_CMD_FRM_MASTER_IST_TX_RPLY_REQ      = 0xE2,
 TUNER_DISEQC_CMD_FRM_MASTER_REPEATED_TX_RPLY_REQ = 0xE3,
 TUNER_DISEQC_CMD_RPLY_FRM_SLAVE_OK               = 0xE4,
 TUNER_DISEQC_CMD_RPLY_FRM_SLAVE_NOT_SUPPORTED    = 0xE5,
 TUNER_DISEQC_CMD_RPLY_FRM_SLAVE_PARITY_ERROR     = 0xE6,
 TUNER_DISEQC_CMD_RPLY_FRM_SLAVE_NOT_RECOGNISED   = 0xE7
} TUNER_DiseqcCmdFramingType_t;
#endif

/* Definition of command bytes which define the actions required of the addressed slave */
/* ------------------------------------------------------------------------------------ */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_DISEQC_CMD_RESET      = 0x00, /* Reset DiSEqC microcontroller                      - 3 bytes   */
 TUNER_DISEQC_CMD_CLR_RESET  = 0x01, /* Clear the "Reset" flag                            - 3 bytes   */
 TUNER_DISEQC_CMD_STANDBY    = 0x02, /* Switch peripheral power supply off                - 3 bytes   */
 TUNER_DISEQC_CMD_POWER_ON   = 0x03, /* Switch peripheral power supply on                 - 3 bytes   */
 TUNER_DISEQC_CMD_SET_LO     = 0x20, /* Select the Low Local Oscillator frequency         - 3 bytes   */
 TUNER_DISEQC_CMD_SET_VR     = 0x21, /* Select Vertical Polarisation (or Right circular)  - 3 bytes   */
 TUNER_DISEQC_CMD_SET_POS_A  = 0x22, /* Select Satellite position A (or position C)       - 3 bytes   */
 TUNER_DISEQC_CMD_SET_SO_A   = 0x23, /* Select Switch Option A (e.g. positions A/B)       - 3 bytes   */
 TUNER_DISEQC_CMD_SET_HI     = 0x24, /* Select the High Local Oscillator frequency        - 3 bytes   */
 TUNER_DISEQC_CMD_SET_HL     = 0x25, /* Select Horizontal Polarisation (or Left circular) - 3 bytes   */
 TUNER_DISEQC_CMD_SET_POS_B  = 0x26, /* Select Satellite position B (or position D)       - 3 bytes   */
 TUNER_DISEQC_CMD_SET_SO_B   = 0x27, /* Select Switch Option B (e.g. positions C/D)       - 3 bytes   */
 TUNER_DISEQC_CMD_WRITE_N0   = 0x38, /* Write to Port group 0 (Committed switches)        - 4 bytes   */
 TUNER_DISEQC_CMD_WRITE_N1   = 0x39, /* Write to Port group 1 (Uncommitted switches)      - 4 bytes   */
 TUNER_DISEQC_CMD_WRITE_FREQ = 0x58, /* Write channel frequency (BCD string)              - 5/6 bytes */
 TUNER_DISEQC_CMD_HALT       = 0x60, /* Stop Positioner movement                          - 3 bytes   */
 TUNER_DISEQC_CMD_LIMITS_OFF = 0x63, /* Disable Limits                                    - 3 bytes   */
 TUNER_DISEQC_CMD_LIMIT_E    = 0x66, /* Set East Limit (& Enable recommended)             - 3 bytes   */
 TUNER_DISEQC_CMD_LIMIT_W    = 0x67, /* Set West Limit (& Enable recommended)             - 3 bytes   */
 TUNER_DISEQC_CMD_DRIVE_E    = 0x68, /* Drive Motor East (with optional timeout/steps)    - 4 bytes   */
 TUNER_DISEQC_CMD_DRIVE_W    = 0x69, /* Drive Motor West (with optional timeout/steps)    - 4 bytes   */
 TUNER_DISEQC_CMD_STORE_NN   = 0x6A, /* Store Satellite Position & Enable Limits          - 4 bytes   */
 TUNER_DISEQC_CMD_GOTO_NN    = 0x6B  /* Drive Motor to Satellite Position nn              - 4 bytes   */
} TUNER_DiseqcCmdType_t;
#endif

/* Definition of DiseqC Protocal version */
/* ------------------------------------  */
#if defined(TUNER_MAX_NUMBER)
typedef enum
{
 TUNER_DISEQC_VER_1_2   = 1, /* Version 1.2 */
 TUNER_DISEQC_VER_2_0   = 2  /* Version 2.0 */
} TUNER_DiseqcVersion_t;
#endif

/* Tuner callback prototype */
/* ------------------------ */
#if defined(TUNER_MAX_NUMBER)
typedef void (*TUNER_ScanCallback_t)(U8 TunerLocked);
#endif

/* External declarations */
/* --------------------- */
#if defined(TUNER_MAX_NUMBER)
extern STFRONTEND_Handle_t TUNER_Handle[];
extern TUNER_Params_t      TUNER_Params[];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t  TUNER_Init               (void);
ST_ErrorCode_t  TUNER_Term               (void);
#if defined(TUNER_MAX_NUMBER)
ST_ErrorCode_t  TUNER_SetFrequency       (U32 TUNER_Index,U32 TUNER_FrequencyKhz,U32 TUNER_SymbolRate,U32 TUNER_Modulation,U32 TUNER_Fec,U32 TUNER_Polarity_ChannelBW,U32 TUNER_Fec_DvbType,U32 TUNER_PilotOn,U32 TUNER_RollOff,U32 TUNER_PLSIndex,U32 RFSource_Id);
ST_ErrorCode_t  TUNER_GetStatus          (U32 TUNER_Index,TUNER_Status_t *TUNER_Status);
ST_ErrorCode_t  TUNER_ScanStart          (U32 TUNER_Index,U32 ScanStartKhz,U32 ScanEndKhz,U32 TUNER_SymbolRate,U32 TUNER_Modulation,U32 TUNER_Fec,U32 TUNER_Polarity_ChannelBW,U32 TUNER_Fec_DvbType,U32 TUNER_Spectrum,TUNER_ScanCallback_t TUNER_Callback);
ST_ErrorCode_t  TUNER_ScanNext           (U32 TUNER_Index,TUNER_ScanCallback_t TUNER_Callback);
ST_ErrorCode_t  TUNER_ScanStop           (U32 TUNER_Index);
#if defined(TUNER_SAT_INCLUDED)
ST_ErrorCode_t  TUNER_SendDiseqcCommand  (U32 TUNER_Index,U8  TUNER_CommandLen,U8 *TUNER_Command,TUNER_DiseqcVersion_t TUNER_DiSEqCVer);
ST_ErrorCode_t  TUNER_LNBConfigure       (U32 TUNER_Index,U32 TUNER_FrequencyKhz,U32 TUNER_Polarity);
#if defined(PIO_MAX_NUMBER)
ST_ErrorCode_t  TUNER_LNBSwitch          (U32 TUNER_Index,U32 TUNER_Satellite);
#endif
#endif
ST_ErrorCode_t  TUNER_GetParams          (TUNER_TsInput_t     TUNER_Input,TUNER_Params_t *TUNER_Params);
char           *TUNER_StatusToString     (TUNER_State_t       TUNER_State);
char           *TUNER_FecRateToString    (TUNER_FecRate_t     TUNER_FecRate);
char           *TUNER_FecTypeToString    (TUNER_FecType_t     TUNER_FecType);
char           *TUNER_PolarityToString   (TUNER_Polarity_t    TUNER_Polarity);
char           *TUNER_ModulationToString (TUNER_Modulation_t  TUNER_Modulation);
char           *TUNER_LNBToString        (TUNER_LnbState_t    TUNER_LnbState);
#endif

/* Prototypes for customer front-end */
/* --------------------------------- */
#if defined(TUNER_MAX_NUMBER)
ST_ErrorCode_t TUNER_Custom_Init         (U32 TUNER_Index);
ST_ErrorCode_t TUNER_Custom_Term         (U32 TUNER_Index);
ST_ErrorCode_t TUNER_Custom_SetFrequency (U32 TUNER_Index,U32 TUNER_FrequencyKhz,U32 TUNER_SymbolRate,U32 TUNER_Modulation,U32 TUNER_Fec,U32 TUNER_Polarity_ChannelBW,U32 TUNER_Fec_DvbType,U32 TUNER_PilotOn,U32 TUNER_RollOff,U32 TUNER_PLSIndex,U32 RFSource_Id);
ST_ErrorCode_t TUNER_Custom_LoopThrough  (U32 TUNER_Index,BOOL Enable);
ST_ErrorCode_t TUNER_Custom_GetStatus    (U32 TUNER_Index);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif
