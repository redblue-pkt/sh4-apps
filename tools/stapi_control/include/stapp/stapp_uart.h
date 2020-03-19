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
 * @file     stapp_uart.h
 * @brief    This is the uart (rs232) file header.
 *           It is used to display traces on rs232 interfaces and also to be
 *           able to run testtool component.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_UART_H_
#define _STAPP_UART_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
#define UART_MAX_NUMBER 1
#endif
#if defined(sat5189)
#define UART_MAX_NUMBER 1
#endif
#if defined(sat7111)
#define UART_MAX_NUMBER 2
#endif
#if defined(adi7108)
#define UART_MAX_NUMBER 1
#endif
#if defined(hdk5251)
#define UART_MAX_NUMBER 1
#endif
#if defined(hdk5289)
#define UART_MAX_NUMBER 1
#endif
#if defined(hdk7108)
#define UART_MAX_NUMBER 1
#endif
#if defined(hdk7111)
#define UART_MAX_NUMBER 2
#endif
#if defined(b2069)
#define UART_MAX_NUMBER 2
#endif
#if defined(b2039)
#define UART_MAX_NUMBER 2
#endif
#if defined(b2057)
#define UART_MAX_NUMBER 1
#endif
#if defined(b2064)
#define UART_MAX_NUMBER 1
#endif
#if defined(ep8000)
#define UART_MAX_NUMBER 1
#endif
#if defined(epp8000)
#define UART_MAX_NUMBER 1
#endif
#if defined(gpv8000)
#define UART_MAX_NUMBER 1
#endif
#if defined(b2067)
#define UART_MAX_NUMBER 1
#endif
#if defined(dp2010)
#define UART_MAX_NUMBER 1
#endif
#if defined(dp7000)
#define UART_MAX_NUMBER 1
#endif
#if defined(dp7001)
#define UART_MAX_NUMBER 1
#endif
#if defined(dp7050)
#define UART_MAX_NUMBER 1
#endif
#if defined(fx6010)
#define UART_MAX_NUMBER 1
#endif
#if defined(b2075)
#define UART_MAX_NUMBER 1
#endif
#if defined(b2076)
#define UART_MAX_NUMBER 2
#endif
#if defined(mb618)
#define UART_MAX_NUMBER 2
#endif
#if defined(mb628)
#define UART_MAX_NUMBER 1
#endif
#if defined(mb628e)
#define UART_MAX_NUMBER 1
#endif
#if defined(eud7141)
#define UART_MAX_NUMBER 1
#endif
#if defined(hdkh225)
#define UART_MAX_NUMBER 1
#endif
#if defined(mb676)
#define UART_MAX_NUMBER 2
#endif
#if defined(mb680)
#define UART_MAX_NUMBER 2
#endif
#if defined(mb796)
#define UART_MAX_NUMBER 2
#endif
#if defined(mb704)
#define UART_MAX_NUMBER 2
#endif
#if defined(mb837)
#define UART_MAX_NUMBER 1
#endif
#if defined(mb903)
#define UART_MAX_NUMBER 1
#endif
#if defined(b2066)
#define UART_MAX_NUMBER 1
#endif
#if defined(hmp7105)
#define UART_MAX_NUMBER 2
#endif
#if defined(sdk7105)
#define UART_MAX_NUMBER 1
#endif
#if defined(kourou)
#define UART_MAX_NUMBER 1
#endif
#if defined(isdb7102)
#define UART_MAX_NUMBER 1
#endif
#if defined(iptv7105)
#define UART_MAX_NUMBER 2
#endif
#if defined(b2068)
#define UART_MAX_NUMBER 1
#endif
#if defined(hdk7167)
#define UART_MAX_NUMBER 1
#endif
#if defined(ngb7167)
#define UART_MAX_NUMBER 1
#endif
#if defined(hdk7197)
#define UART_MAX_NUMBER 1
#endif
#if defined(hdkh251)
#define UART_MAX_NUMBER 1
#endif
#if defined(dtt5267)
#define UART_MAX_NUMBER 1
#endif
#if defined(b2049)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom001030)
#define UART_MAX_NUMBER 2
#endif
#if defined(custom001034)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom001035)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom001036)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom001039)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom002005)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom002006)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom002007)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom002008)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom003008)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom003009)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom003011)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom003012)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom003015)
#if defined(ST_HOST)
#define UART_MAX_NUMBER 1
#endif
#endif
#if defined(custom003018)
#if defined(ST_HOST)
#define UART_MAX_NUMBER 1
#endif
#endif
#if defined(custom018001)
#define UART_MAX_NUMBER 2
#endif
#if defined(custom021001)
#define UART_MAX_NUMBER 1
#endif
#if defined(custom022001)
#define UART_MAX_NUMBER 2
#endif
/* For linux, there is no UART support in STSDK, this is done inside the kernel */
#if defined(ST_OSLINUX)
#if defined(UART_MAX_NUMBER)
#undef UART_MAX_NUMBER
#endif
#endif

/* Includes */
/* -------- */
#if defined(UART_MAX_NUMBER)
#include "stuart.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(UART_MAX_NUMBER)
extern STUART_Handle_t UART_Handle[UART_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t UART_Init(void);
ST_ErrorCode_t UART_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

