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
 * @file     stapp_pcpd.h
 * @brief    This is the pcpd file header.
 *           It is used to communicate between host cpu and specific cable modem cpu (STx7141 or STx498 devices).
 * @author   STMicroelectronics
 */

#ifndef _STAPP_PCPD_H_
#define _STAPP_PCPD_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
/* No pcpd support */
#endif
#if defined(ST_5206)
/* No pcpd support */
#endif
#if defined(ST_7105)
/* No pcpd support */
#endif
#if defined(ST_7108)
/* No pcpd support */
#endif
#if defined(ST_7111)
/* No pcpd support */
#endif
#if defined(ST_7141)&&(CABLE_MODEM_ATTACHED==1)
#define PCPD_MAX_NUMBER 1
#endif
#if defined(ST_H205)
/* No pcpd support */
#endif

/* Includes */
/* -------- */
#if defined(PCPD_MAX_NUMBER)
#include "stpcpd.h"
#endif

/* DSG Support */
/* ----------- */
#if defined(PCPD_MAX_NUMBER)
#define DSG_SUPPORT_ENABLED  0
#if DSG_SUPPORT_ENABLED
#define DSG_SUPPORT_IS_BASIC 1 /* Default basic, change it to 0 for advance */
#if DSG_SUPPORT_IS_BASIC
#define DSG_SUPPORT_BASIC    1 /* DSG Basic Mode */
#else
#define DSG_SUPPORT_ADVANCED 1 /* Start the eCM in dsg advanced mode. Take care to disable dsg basic modes flag by commenting */
#endif
#endif
#endif

/* Debug macros */
/* ------------ */
#if defined(PCPD_MAX_NUMBER)
#define PCPD_DEBUG_PRINT(ISON,arg)  ISON ? print  arg:ISON
#if defined(RUN_FROM_FLASH)
#define PCPD_DEBUG_PRINTF(ISON,arg) ISON ? print arg:ISON
#else
#define PCPD_DEBUG_PRINTF(ISON,arg) ISON ? printf arg:ISON
#endif
#endif

/* Flag to use Nand and Nor Flash together by PCPD */
/* ----------------------------------------------- */
#if defined(PCPD_MAX_NUMBER)
#if defined(ST_OSLINUX)&&(defined(eud7141)||defined(hdkh225)||defined(custom022001))&&(RUN_FROM_FLASH)
#define FLASH_HYBRID 1
#endif
#endif

/* PCPD Print Priorites */
/* -------------------- */
/* PCPD_HIGH_PRIORITY                    */
/*   - Error conditions                  */
/*   - Default prints                    */
/*   - File Open and close in SW Upgrade */
/* PCPD_MEDIUM_PRIORITY                  */
/*   - Debug prints                      */
/* PCPD_LOW_PRIORITY                     */
/*   - SWupgrade File Writes (repeating) */
/*   - NVMM Key Requests (repeating)     */
/*   - Function Entry and Exits          */
#define PCPD_HIGH_PRIORITY   1
#define PCPD_MEDIUM_PRIORITY 0
#define PCPD_LOW_PRIORITY    0
#define PCPD_EVENT_MAX       47

/* Enable/Disable eCM CLI over PCPD */
/* -------------------------------- */
#define PCPD_ECMCLI_OVER_PCPD 0

/* Check Flash Status   */
/* -------------------- */
#define PCPD_FLASH_DEVID     0
#define FLASH_STATUS_CHECK(StatusCode,Operation)   ((StatusCode == ST_NO_ERROR) ? PCPD_DEBUG_PRINT(PCPD_LOW_PRIORITY, ("Flash %s OK\n",Operation)) :  \
                                                    (StatusCode == ST_ERROR_SUSPENDED) ?  PCPD_DEBUG_PRINT(PCPD_MEDIUM_PRIORITY, ("Flash %s is not supported in Low Power\n",Operation)): \
                                                     PCPD_DEBUG_PRINT(PCPD_HIGH_PRIORITY, ("Error in Flash %s \n",Operation))    )

/* PCPD Callback definition */
/* ------------------------ */
#if defined(PCPD_MAX_NUMBER)
typedef struct PCPD_Callback_s
{
 void (*PCPD_NotificationFn)(STPCPD_CML_eCM_Status_Event_t *EventData_p);
 U16 Event;
} PCPD_Callback_t;
#endif

/* External declarations */
/* --------------------- */
#if defined(PCPD_MAX_NUMBER)
extern STPCPD_Handle_t PCPD_CML_Handle[PCPD_MAX_NUMBER];
extern BOOL            PCPD_gTwowaytraffic;
extern char            PCPD_VirtIfName[10];
extern BOOL            PCPD_ECMCLIOpen;
#endif

/* Enum */
/* ---- */
typedef enum PCPD_eCM_EVENTS
{
 EVENTMGR_EVENT_INTERFACE_CONNECTED = 1,             /* Interface is connected (plugged in): Param X is interface number, Param Y is QAM mode */
 EVENTMGR_EVENT_INTERFACE_DISCONNECTED,              /* Interface X is disconnected (unplugged): Param X is interface number */
 EVENTMGR_EVENT_DOWNSCAN_START,                      /* CM starting downstream scanning */
 EVENTMGR_EVENT_DOWNSCAN_COMPLETE_OK,                /* CM completed downstream scanning successfully: Param X is found channel in MHz.  */
 EVENTMGR_EVENT_DOWNSCAN_COMPLETE_FAIL,              /* CM completed downstream scanning, no channels found */
 EVENTMGR_EVENT_RANGE_START,                         /* CM started initial ranging: Param X is upstream channel ID.  */
 EVENTMGR_EVENT_RANGE_COMPLETE_OK,                   /* CM completed initial ranging successfully: Param X is upstream channel ID */
 EVENTMGR_EVENT_RANGE_COMPLETE_FAIL,                 /* CM completed initial ranging, failed to range: Param X is upstream channel ID */
 EVENTMGR_EVENT_DHCP_START,                          /* CM started DHCP */
 EVENTMGR_EVENT_DHCP_COMPLETE_OK,                    /* DHCP completed OK: Param X includes the DHCP IP address obtained */
 EVENTMGR_EVENT_DHCP_COMPLETE_FAIL,                  /* DHCP completed but failed */
 EVENTMGR_EVENT_TFTP_START,                          /* CM started TFTP */
 EVENTMGR_EVENT_TFTP_COMPLETE_OK,                    /* TFTP completed OK */
 EVENTMGR_EVENT_TFTP_COMPLETE_FAIL,                  /* TFTP completed but failed */
 EVENTMGR_EVENT_SWUPGRADE_START,                     /* CM started software upgrade */
 EVENTMGR_EVENT_SWUPGRADE_COMPLETE_OK,               /* Software upgrade completed OK */
 EVENTMGR_EVENT_SWUPGRADE_COMPLETE_FAIL,             /* Software upgrade completed but failed */
 EVENTMGR_EVENT_ENTERED_TWO_WAY_OPERATIONAL_STATE,   /* CM entered the DSG Two way operational state */
 EVENTMGR_EVENT_CHANNEL_CHANGE_START,                /* CM changing channel: Param X is downstream channel in MHz, Param Y is upstream channel ID   */
 EVENTMGR_EVENT_CHANNEL_CHANGE_COMPLETE_OK,          /* Channel change complete OK: Param X is downstream channel in MHz, Param Y is upstream channel ID  */
 EVENTMGR_EVENT_CHANNEL_CHANGE_COMPLETE_FAIL,        /* Channel change complete but failed */
 EVENTMGR_EVENT_ENTERING_ONE_WAY_OPERATIONAL_STATE,  /* CM entering the DSG one way operational mode */
 EVENTMGR_EVENT_ENTERING_TWO_WAY_DISABLED_STATE,     /* CM entering two way disabled state */
 EVENTMGR_EVENT_DCC_RSP_SENT,                        /* DCC Response message sent */
 EVENTMGR_EVENT_REGISTRATION_COMPLETE_OK,            /* Registration completed OK */
 EVENTMGR_EVENT_SHUTDOWN_COMPLETE,                   /* Shutdown completed */
 EVENTMGR_EVENT_TDSG1_TIMEOUT,                       /* TDSG1 timeout */
 EVENTMGR_EVENT_TDSG2_TIMEOUT,                       /* TDSG2 timeout */
 EVENTMGR_EVENT_TDSG3_TIMEOUT,                       /* TDSG3 timeout */
 EVENTMGR_EVENT_TDSG4_TIMEOUT,                       /* TDSG4 timeout */
 EVENTMGR_EVENT_CANNOT_FORWARD_2_WAY_TRAFFIC,        /* Cannot forward 2-way traffic */
 EVENTMGR_EVENT_ESTB_IFADMIN_CHANGED,                /* eSTB (ifIndex 17) ifAdminStatus change */
 EVENTMGR_EVENT_DHCPV6_START,                        /* CM started DHCPv6 */
 EVENTMGR_EVENT_DHCPV6_COMPLETE_OK,                  /* DHCPv6 completed OK.  */
 EVENTMGR_EVENT_DHCPV6_COMPLETE_FAIL,                /* DHCPv6 failed */
 EVENTMGR_EVENT_DSG_TUNNEL_NO_DSID,                  /* MDD update occurred, some DSG Tunnel MAC Addresses */
 EVENTMGR_EVENT_QAM_LOCK_LOST,
 EVENTMGR_EVENT_QAM_LOCK_RESTORED,
 EVENTMGR_EVENT_TUNING_NEW_FREQ,                     /* Trying new frequency in DOCSIS Scan.  */
 EVENTMGR_EVENT_LOW_POWER_WAKEUP,                    /* POWER WakeUp Event */
 EVENTMGR_EVENT_DSG_MAC_REINIT,                      /* MAC reinit */
 EVENTMGR_EVENT_OPERATIONAL,                         /* CM entered operational state */
 EVENTMGR_EVENT_REGISTRATION_START,                  /* CM started registration */
 EVENTMGR_EVENT_REGISTRATION_COMPLETE_FAIL,          /* Registration completed but failed */
 EVENTMGR_EVENT_INTERFACE_DATA_RX,                   /* Packet received on interface: Param X is interface number */
 EVENTMGR_EVENT_INTERFACE_DATA_TX,                   /* Packet transmitted on interface: Param X is interface number */
 EVENTMGR_EVENT_KILL_TASK,                           /* Special event type used to kill the task (MUST BE AT THE END) */
 EVENTMGR_EVENT_MAX
} PCPD_eCM_EVENTS_t;

/* Function Prototypes */
/* ------------------- */
ST_ErrorCode_t PCPD_Init                    (void);
ST_ErrorCode_t PCPD_Term                    (void);
#if defined(PCPD_MAX_NUMBER)
ST_ErrorCode_t PCPD_IseCMBooted             (void);
void           PCPD_eCM_Start               (void);
ST_ErrorCode_t PCPD_Start                   (void);
ST_ErrorCode_t PCPD_Stop                    (void);
#if defined(TCPIP)&&defined(TCPIP_MAX_NUMBER)
void PCPD_Get_vEthMAC                       (U8 *vEthMAC);
void PCPD_Set_eSTB_vEthMACAddress           (void);
void PCPD_Send_vEthNWInfo                   (U16 TransID,BOOL IseCM_SyncReply,U8 IPvMode);
#endif
#if DSG_SUPPORT_ENABLED
BOOL           PCPD_DSGStart                (void);
#endif
ST_ErrorCode_t PCPD_eCMLoad                 (void);
ST_ErrorCode_t PCPD_NVMR_Load               (void);
ST_ErrorCode_t PCPD_RegisterCallBack        (U8 ID,PCPD_Callback_t *NotifyParams);
ST_ErrorCode_t PCPD_UnregisterCallBack      (U8 ID,PCPD_Callback_t *NotifyParams);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

