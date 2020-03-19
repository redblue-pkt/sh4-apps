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
 * @file     stapp_keyscn.h
 * @brief    This is the key scanning hardware file header.
 *           It is used to simplify buttons management available on the products
 *           by using keyscan hardware interface available on ST devices.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_KEYSCN_H_
#define _STAPP_KEYSCN_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
/* No keyscan driver */
#endif
#if defined(sat5189)
/* No keyscan driver */
#endif
#if defined(sat7111)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(adi7108)
/* No keyscan driver */
#endif
#if defined(hdk5251)
/* No keyscan driver */
#endif
#if defined(hdk5289)
/* No keyscan driver */
#endif
#if defined(hdk7108)
/* No keyscan driver */
#endif
#if defined(hdk7111)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(b2069)
/* No keyscan driver */
#endif
#if defined(b2039)
/* No keyscan driver */
#endif
#if defined(b2057)
/* No keyscan driver */
#endif
#if defined(b2064)
/* No keyscan driver */
#endif
#if defined(ep8000)
/* No keyscan driver */
#endif
#if defined(epp8000)
/* No keyscan driver */
#endif
#if defined(gpv8000)
/* No keyscan driver */
#endif
#if defined(b2067)
/* No keyscan driver */
#endif
#if defined(dp2010)
/* No keyscan driver */
#endif
#if defined(dp7000)
/* No keyscan driver */
#endif
#if defined(dp7001)
/* No keyscan driver */
#endif
#if defined(dp7050)
/* No keyscan driver */
#endif
#if defined(fx6010)
/* No keyscan driver */
#endif
#if defined(b2075)
/* No keyscan driver */
#endif
#if defined(b2076)
/* No keyscan driver */
#endif
#if defined(mb618)
/* Keyscan is exclusive with spi and fsk */
/* No keyscan driver                     */
#endif
#if defined(mb628)
/* No keyscan driver */
#endif
#if defined(mb628e)
/* No keyscan driver */
#endif
#if defined(eud7141)
/* No keyscan driver */
#endif
#if defined(hdkh225)
/* No keyscan driver */
#endif
#if defined(mb676)
/* No keyscan driver */
#endif
#if defined(mb680)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(mb704)
/* No keyscan driver */
#endif
#if defined(mb796)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(mb837)
/* No keyscan driver */
#endif
#if defined(mb903)
/* No keyscan driver */
#endif
#if defined(b2066)
/* No keyscan driver */
#endif
#if defined(hmp7105)
/* No keyscan driver */
#endif
#if defined(sdk7105)
/* No keyscan driver */
#endif
#if defined(kourou)
/* No keyscan driver */
#endif
#if defined(isdb7102)
/* No keyscan driver */
#endif
#if defined(iptv7105)
/* No keyscan driver */
#endif
#if defined(b2068)
/* No keyscan driver */
#endif
#if defined(hdk7167)
/* No keyscan driver */
#endif
#if defined(ngb7167)
/* No keyscan driver */
#endif
#if defined(hdk7197)
/* No keyscan driver */
#endif
#if defined(hdkh251)
/* No keyscan driver */
#endif
#if defined(dtt5267)
/* No keyscan driver */
#endif
#if defined(b2049)
/* No keyscan driver */
#endif
#if defined(custom001030)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(custom001034)
/* No keyscan driver */
#endif
#if defined(custom001035)
/* No keyscan driver */
#endif
#if defined(custom001036)
/* No keyscan driver */
#endif
#if defined(custom001039)
/* No keyscan driver */
#endif
#if defined(custom002005)
/* No keyscan driver */
#endif
#if defined(custom002006)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(custom002007)
/* No keyscan driver */
#endif
#if defined(custom002008)
/* No keyscan driver */
#endif
#if defined(custom003008)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(custom003009)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(custom003011)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(custom003012)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(custom003015)
/* No keyscan driver */
#endif
#if defined(custom003018)
/* No keyscan driver */
#endif
#if defined(custom018001)
#define KEYSCN_MAX_NUMBER 1
#endif
#if defined(custom021001)
/* No keyscan driver */
#endif
#if defined(custom022001)
/* No keyscan driver */
#endif
/* For linux, keyscan support not yet supported */
#if defined(ST_OSLINUX)
#if defined(KEYSCN_MAX_NUMBER)
#undef KEYSCN_MAX_NUMBER
#endif
#endif

/* Includes */
/* -------- */
#if defined(KEYSCN_MAX_NUMBER)
#include "stkeyscn.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(KEYSCN_MAX_NUMBER)
extern STKEYSCN_Handle_t KEYSCN_Handle[];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t KEYSCN_Init(void);
ST_ErrorCode_t KEYSCN_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

