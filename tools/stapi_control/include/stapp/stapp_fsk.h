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
 * @file     stapp_fsk.h
 * @brief    This is the fsk file header.
 *           It is used to control dish parameters (like diseqc).
 * @author   STMicroelectronics
 */

#ifndef _STAPP_FSK_
#define _STAPP_FSK_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
/* No fsk support */
#endif
#if defined(sat5189)
/* No fsk support */
#endif
#if defined(sat7111)
/* No fsk support */
#endif
#if defined(adi7108)
/* No fsk support */
#endif
#if defined(hdk5251)
/* No fsk support */
#endif
#if defined(hdk5289)
/* No fsk support */
#endif
#if defined(hdk7108)
/* No fsk support */
#endif
#if defined(hdk7111)
/* No fsk support */
#endif
#if defined(b2069)
/* No fsk support */
#endif
#if defined(mb628)
/* No fsk support */
#endif
#if defined(mb628e)
/* No fsk support */
#endif
#if defined(eud7141)
/* No fsk support */
#endif
#if defined(hdkh225)
/* No fsk support */
#endif
#if defined(mb676)
/* No fsk support */
#endif
#if defined(mb680)
/* No fsk support */
#endif
#if defined(mb704)
/* No fsk support */
#endif
#if defined(mb796)
/* No fsk support */
#endif
#if defined(mb837)
/* No fsk support */
#endif
#if defined(mb903)
/* No fsk support */
#endif
#if defined(b2066)
/* No fsk support */
#endif
#if defined(hmp7105)
/* No fsk support */
#endif
#if defined(sdk7105)
/* No fsk support */
#endif
#if defined(kourou)
/* No fsk support */
#endif
#if defined(isdb7102)
/* No fsk support */
#endif
#if defined(iptv7105)
/* No fsk support */
#endif
#if defined(b2068)
/* No fsk support */
#endif
#if defined(hdk7167)
/* No fsk support */
#endif
#if defined(hdk7197)
/* No fsk support */
#endif
#if defined(hdkh251)
/* No fsk support */
#endif
#if defined(dtt5267)
/* No fsk support */
#endif
#if defined(b2049)
/* No fsk support */
#endif
#if defined(b2039)
/* No fsk support */
#endif
#if defined(b2057)
/* No fsk support */
#endif
#if defined(b2064)
/* No fsk support */
#endif
#if defined(ep8000)
/* No fsk support */
#endif
#if defined(epp8000)
/* No fsk support */
#endif
#if defined(gpv8000)
/* No fsk support */
#endif
#if defined(b2067)
/* No fsk support */
#endif
#if defined(dp2010)
/* No fsk support */
#endif
#if defined(dp7000)
/* No fsk support */
#endif
#if defined(dp7001)
/* No fsk support */
#endif
#if defined(dp7050)
/* No fsk support */
#endif
#if defined(fx6010)
/* No fsk support */
#endif
#if defined(b2075)
/* No fsk support */
#endif
#if defined(b2076)
/* No fsk support */
#endif
#if defined(custom001030)
/* No fsk support */
#endif
#if defined(custom001034)
/* No fsk support */
#endif
#if defined(custom001035)
/* No fsk support */
#endif
#if defined(custom001036)
/* No fsk support */
#endif
#if defined(custom001039)
/* No fsk support */
#endif
#if defined(custom002005)
/* No fsk support */
#endif
#if defined(custom002006)
/* No fsk support */
#endif
#if defined(custom002007)
/* No fsk support */
#endif
#if defined(custom002008)
/* No fsk support */
#endif
#if defined(custom003008)
/* No fsk support */
#endif
#if defined(custom003009)
/* No fsk support */
#endif
#if defined(custom003015)
/* No fsk support */
#endif
#if defined(custom003018)
/* No fsk support */
#endif
#if defined(custom018001)
/* No fsk support */
#endif
#if defined(custom021001)
/* No fsk support */
#endif
#if defined(custom022001)
/* No fsk support */
#endif
/* For linux, FSK support not yet supported */
#if defined(ST_OSLINUX)
#if defined(FSK_MAX_NUMBER)
#undef FSK_MAX_NUMBER
#endif
#endif

/* Includes */
/* -------- */
#if defined(FSK_MAX_NUMBER)
#include "stfsk.h"
#endif

/* Definition of the tuner Registration status */
/* ------------------------------------------- */
#if defined(FSK_MAX_NUMBER)
typedef enum FSK_TunerStatus
{
 FSK_STATUS_NOT_REGISTERED,
 FSK_STATUS_REGISTRATION_PENDING,
 FSK_STATUS_REGISTERED
}FSK_TunerStatus_t;
#endif

/* Definition of Framing byte determines the message type */
/* ------------------------------------------------------ */
#if defined(FSK_MAX_NUMBER)
typedef enum FSK_FramingByte
{
 FSK_CMD_FROM_MASTER_FIRST_TX               = 0xE2, /* Command from Master     - Reply required, First transmission                                                                 */
 FSK_CMD_FROM_MASTER_REPEATED_TX            = 0xE3, /* Command from Master     - Reply required, Repeated transmission                                                              */
 FSK_REPLY_FROM_SLAVE_OK                    = 0xE4, /* "OK" Reply from Slave   - No errors detected                                                                                 */
 FSK_REPLY_FROM_SLAVE_ERROR_CMD_INVALID     = 0xE5, /* Error Reply from Slave  - Command not executable by Slave                                                                    */
 FSK_REPLY_FROM_SLAVE_ERROR_MSG_LENGTH      = 0xE7, /* Error Reply from Slave  - Suggest repeat of message, Received message format not correct (e.g. wrong number of bits / bytes) */
 FSK_REPLY_FROM_SLAVE_ERROR_STB_NUM_INVALID = 0xED, /* Error Report from Slave - STB Number in the command message not valid                                                        */
 FSK_REPLY_FROM_SLAVE_ERROR_CRC_INVALID     = 0xEE  /* Error Report from Slave - CRC not valid                                                                                      */
} FSK_FramingByte_t;
#endif

/* Definition of the FSK polarity type */
/* ----------------------------------- */
#if defined(FSK_MAX_NUMBER)
typedef enum
{
 FSK_PLR_VERTICAL,
 FSK_PLR_HORIZONTAL
} FSK_Polarity_t;
#endif

/* Command byte defines the function of the command being sent */
/* ----------------------------------------------------------- */
#if defined(FSK_MAX_NUMBER)
typedef enum FSK_CommandByte
{
 FSK_TUNING_CMD                  = 0x73, /* It involves tuning the relevant channel or turning it to standby            */
 FSK_CONFIGURATION_CMD           = 0x78, /* Commands that are setting the system up and refer to allocation of channels */
 FSK_INSTALLATION_STATUS_REQUEST = 0x74  /* It is used to download the LNB status for a particular STB                  */
} FSK_CommandByte_t;
#endif

/* Sub commands which come under FSK_CONFIGURATION_CMD */
/* --------------------------------------------------- */
#if defined(FSK_MAX_NUMBER)
typedef enum FSK_ConfCommandByte
{
 FSK_Install_Request_Slot_X = 0xC2, /* This command is used in the installation process to allow the LNB to allocate a slot to the STB */
 FSK_Clear_Slot_Allocation  = 0xC4, /* This removes the slot allocation from the STB and the LNB                                       */
 FSK_Clear_Unused_Slots     = 0xC6, /* This command will clear the allocation flag from any channels that are no longer in use         */
 FSK_Clear_All_Slots        = 0xC5, /* This command is used to clear the allocation on all of the channels in the LNB                  */
 FSK_Set_Default_Channel    = 0xD1, /* This changes the default channel in the LNB                                                     */
 FSK_Set_Def_Trans_Freq     = 0xD2, /* This sends the transponder frequency, the polarisation                                          */
 FSK_Set_Def_Trans_Setting  = 0xD3, /* Required for the default transponder                                                            */
 FSK_Clear_Default_Channel  = 0xD4  /* This command allows the default channel to be cleared totally                                   */
} FSK_ConfCommandByte_t;
#endif

/* Msg comes from LNB */
/* ------------------ */
#if defined(FSK_MAX_NUMBER)
typedef enum FSK_ReplyCommand
{
 FSK_INSTALL_OK     = 0x04, /* This reply is used in response to either a FSK_Install_Request_Slot_0 or FSK_Install_Request_Slot_X command                                        */
 FSK_INSTALL_ERROR  = 0x06, /* TThis command will be used if the LNB is not able to comply with any install request apart from the situation where all the channels are allocated */
 FSK_INSTALL_FULL   = 0x07, /* This message is used if any FSK_Install_Request_Slot command is used and the LNB has already had all of its channels allocated                     */
 FSK_INSTALL_STATUS = 0x00  /* This reply is used in response toReply_Installation_Request                                                                                        */
} FSK_ReplyCommand_t;
#endif

/* Definition of the registered tuner data */
/* --------------------------------------- */
#if defined(FSK_MAX_NUMBER)
typedef struct FSK_TunerData
{
 U32               FSK_TUNERIndex;       /* ID of tuner instance                */
 U32               FSK_STBNumber;        /* STB number                          */
 U32               FSK_XIDVal;           /* XID value 0 1 hour and 1 is 60 days */
 U32               FSK_AllocationStatus; /* Set to 1 if channel is allocated    */
 U32               FSK_InUseStatus;      /* Set to 1 if channel is in use       */
 U32               FSK_SlotNumber;       /* Slot number                         */
 U32               FSK_ChannelNumber;    /* Channel number                      */
 FSK_TunerStatus_t FSK_TunerStatus;      /* Status of the tuner                 */
 U32               FSK_Index;            /* ID of Fsk instance                  */
 U32               FSK_ChFrequencyKHz;   /* Channel freq at allocated channel   */
 U32               FSK_SlotFrequencyKHz; /* Slot freq at allocated Slot         */
} FSK_TunerData_t;
#endif

/* External declarations */
/* --------------------- */
#if defined(FSK_MAX_NUMBER)
extern STFSK_Handle_t FSK_Handle[];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t  FSK_Init           (void);
ST_ErrorCode_t  FSK_Term           (void);
#if defined(FSK_MAX_NUMBER)
ST_ErrorCode_t  FSK_ChannelChange  (U32 FSK_Index,U32 TUNER_Index,U32 FSK_FrequencyKhz,U32 FSK_Band,U32 FSK_Polarity);
ST_ErrorCode_t  FSK_GetStatus      (U32 FSK_Index,U32 TUNER_Index,FSK_TunerData_t *TUNER_Data);
ST_ErrorCode_t  FSK_RegisterTuner  (U32 FSK_Index,U32 TUNER_Index);
ST_ErrorCode_t  FSK_UnRegisterTuner(U32 FSK_Index,U32 TUNER_Index);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif
