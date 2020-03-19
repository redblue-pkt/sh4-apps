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
 * @file     stapp_pios.h
 * @brief    This is the pio file header.
 *           It is used to configure hardware pio settings of the platforms
 * @author   STMicroelectronics
 */

#ifndef _STAPP_PIOS_H_
#define _STAPP_PIOS_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
#define PIO_MAX_NUMBER 5
#endif
#if defined(sat5189)
#define PIO_MAX_NUMBER 5
#endif
#if defined(sat7111)
#define PIO_MAX_NUMBER 7
#endif
#if defined(adi7108)
#define PIO_MAX_NUMBER 27
#endif
#if defined(hdk5251)
#define PIO_MAX_NUMBER 4
#endif
#if defined(hdk5289)
#define PIO_MAX_NUMBER 4
#endif
#if defined(hdk7108)
#define PIO_MAX_NUMBER 27
#endif
#if defined(hdk7111)
#define PIO_MAX_NUMBER 7
#endif
#if defined(b2069)
#define PIO_MAX_NUMBER 7
#endif
#if defined(b2039)
#define PIO_MAX_NUMBER 16
#endif
#if defined(b2057)
#define PIO_MAX_NUMBER 16
#endif
#if defined(b2064)
#define PIO_MAX_NUMBER 16
#endif
#if defined(b2067)
#define PIO_MAX_NUMBER 16
#endif
#if defined(b2075)
#define PIO_MAX_NUMBER 16
#endif
#if defined(b2076)
#define PIO_MAX_NUMBER 16
#endif
#if defined(mb618)
#define PIO_MAX_NUMBER 7
#endif
#if defined(mb628)
#define PIO_MAX_NUMBER 16
#endif
#if defined(mb628e)
#define PIO_MAX_NUMBER 16
#endif
#if defined(eud7141)
#define PIO_MAX_NUMBER 16
#endif
#if defined(hdkh225)
#define PIO_MAX_NUMBER 16
#endif
#if defined(mb676)
#define PIO_MAX_NUMBER 5
#endif
#if defined(mb680)
#define PIO_MAX_NUMBER 17
#endif
#if defined(mb704)
#define PIO_MAX_NUMBER 5
#endif
#if defined(mb796)
#define PIO_MAX_NUMBER 4
#endif
#if defined(mb837)
#define PIO_MAX_NUMBER 27
#endif
#if defined(mb903)
#define PIO_MAX_NUMBER 27
#endif
#if defined(b2066)
#define PIO_MAX_NUMBER 27
#endif
#if defined(hmp7105)
#define PIO_MAX_NUMBER 17
#endif
#if defined(sdk7105)
#define PIO_MAX_NUMBER 17
#endif
#if defined(kourou)
#define PIO_MAX_NUMBER 17
#endif
#if defined(isdb7102)
#define PIO_MAX_NUMBER 17
#endif
#if defined(iptv7105)
#define PIO_MAX_NUMBER 17
#endif
#if defined(b2068)
#define PIO_MAX_NUMBER 17
#endif
#if defined(hdk7167)
#define PIO_MAX_NUMBER 17
#endif
#if defined(ngb7167)
#define PIO_MAX_NUMBER 17
#endif
#if defined(hdk7197)
#define PIO_MAX_NUMBER 17
#endif
#if defined(hdkh251)
#define PIO_MAX_NUMBER 17
#endif
#if defined(dtt5267)
#define PIO_MAX_NUMBER 17
#endif
#if defined(b2049)
#define PIO_MAX_NUMBER 17
#endif
#if defined(custom001030)
#define PIO_MAX_NUMBER 7
#endif
#if defined(custom001034)
#define PIO_MAX_NUMBER 16
#endif
#if defined(custom001035)
#define PIO_MAX_NUMBER 16
#endif
#if defined(custom001036)
#define PIO_MAX_NUMBER 17
#endif
#if defined(custom001039)
#define PIO_MAX_NUMBER 16
#endif
#if defined(custom002005)
#define PIO_MAX_NUMBER 7
#endif
#if defined(custom002006)
#define PIO_MAX_NUMBER 17
#endif
#if defined(custom002007)
#define PIO_MAX_NUMBER 17
#endif
#if defined(custom002008)
#define PIO_MAX_NUMBER 16
#endif
#if defined(custom003008)
#define PIO_MAX_NUMBER 7
#endif
#if defined(custom003009)
#define PIO_MAX_NUMBER 17
#endif
#if defined(custom003011)
#define PIO_MAX_NUMBER 17
#endif
#if defined(custom003012)
#define PIO_MAX_NUMBER 17
#endif
#if defined(custom003015)
#define PIO_MAX_NUMBER 27
#endif
#if defined(custom003018)
#define PIO_MAX_NUMBER 27
#endif
#if defined(custom018001)
#define PIO_MAX_NUMBER 7
#endif
#if defined(custom021001)
#define PIO_MAX_NUMBER 16
#endif
#if defined(custom022001)
#define PIO_MAX_NUMBER 16
#endif
#if defined(dp2010)
#define PIO_MAX_NUMBER 16
#endif
#if defined(dp7000)
#define PIO_MAX_NUMBER 16
#endif
#if defined(dp7001)
#define PIO_MAX_NUMBER 16
#endif
#if defined(dp7050)
#define PIO_MAX_NUMBER 16
#endif
#if defined(fx6010)
#define PIO_MAX_NUMBER 16
#endif
#if defined(ep8000)
#define PIO_MAX_NUMBER 16
#endif
#if defined(epp8000)
#define PIO_MAX_NUMBER 16
#endif
#if defined(gpv8000)
#define PIO_MAX_NUMBER 16
#endif

/* Includes */
/* -------- */
#if defined(PIO_MAX_NUMBER)
#include "stpio.h"
#endif

/* PIO Mode definition */
/* ------------------- */
typedef enum PIO_Mode_s
{
 PIO_NONPIO,    /* Input, weak pull-up (default) */
 PIO_BIDIR,     /* Bidirectional, open drain     */
 PIO_OUT,       /* Output, push-pull             */
 PIO_IN,        /* Input, high-Z                 */
 PIO_ALT_OUT,   /* Alternate output, push-pull   */
 PIO_ALT_BIDIR  /* Alternate bidir, open drain   */
} PIO_Mode_t;

/* Prototypes */
/* ---------- */
ST_ErrorCode_t PIO_Init(void);
ST_ErrorCode_t PIO_Term(void);
ST_ErrorCode_t PIO_ETHER_Reset(BOOL OnOff);
ST_ErrorCode_t PIO_ATA_Reset(BOOL OnOff);
ST_ErrorCode_t PIO_DAC_Reset(BOOL OnOff);
ST_ErrorCode_t PIO_FE_Reset(BOOL OnOff);
ST_ErrorCode_t PIO_MODEM_Reset(BOOL OnOff);
ST_ErrorCode_t PIO_SCART_Reset(BOOL OnOff);
ST_ErrorCode_t PIO_USB_Reset(BOOL OnOff);
ST_ErrorCode_t PIO_BIT_Get(U32 PIO_Index,U32 PIO_Bit,BOOL *OnOff);
ST_ErrorCode_t PIO_BIT_Set(U32 PIO_Index,U32 PIO_Bit,BOOL OnOff);
ST_ErrorCode_t PIO_BIT_Configure(U32 PIO_Index,U32 PIO_Bit,PIO_Mode_t PIO_Mode);
ST_ErrorCode_t PIO_LED_Set(U32 Led,BOOL OnOff);
ST_ErrorCode_t PIO_FLASH_Reset(BOOL OnOff);
ST_ErrorCode_t PIO_FLASH_Vpp(BOOL OnOff);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

