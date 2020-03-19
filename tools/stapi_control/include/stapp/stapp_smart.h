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
 * @file     stapp_smart.h
 * @brief    This is the smartcard file header.
 *           It is used to exchange control words with smartcard inserted in the product
 *           to descramble channels when they are encrypted.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_SMART_H_
#define _STAPP_SMART_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
#define SMART_MAX_NUMBER 1
#if defined(ST_OSLINUX)
#undef SMART_MAX_NUMBER
#endif
#endif
#if defined(sat5189)
#define SMART_MAX_NUMBER 1
#if defined(ST_OSLINUX)
#undef SMART_MAX_NUMBER
#endif
#endif
#if defined(sat7111)
#define SMART_MAX_NUMBER 1
#endif
#if defined(adi7108)
#define SMART_MAX_NUMBER 1
#endif
#if defined(hdk5251)
#define SMART_MAX_NUMBER 1
#endif
#if defined(hdk5289)
#define SMART_MAX_NUMBER 1
#endif
#if defined(hdk7108)
#define SMART_MAX_NUMBER 1
#endif
#if defined(hdk7111)
#define SMART_MAX_NUMBER 1
#endif
#if defined(b2069)
#define SMART_MAX_NUMBER 1
#endif
#if defined(b2039)
#define SMART_MAX_NUMBER 1
#endif
#if defined(b2057)
#define SMART_MAX_NUMBER 1
#endif
#if defined(b2064)
#define SMART_MAX_NUMBER 1
#endif
#if defined(ep8000)
#define SMART_MAX_NUMBER 1
#endif
#if defined(epp8000)
#define SMART_MAX_NUMBER 1
#endif
#if defined(gpv8000)
#define SMART_MAX_NUMBER 1
#endif
#if defined(b2067)
#define SMART_MAX_NUMBER 1
#endif
#if defined(fx6010)
#define SMART_MAX_NUMBER 1
#endif
#if defined(dp2010)
#define SMART_MAX_NUMBER 1
#endif
#if defined(dp7000)
#define SMART_MAX_NUMBER 1
#endif
#if defined(dp7001)
#define SMART_MAX_NUMBER 1
#endif
#if defined(dp7050)
#define SMART_MAX_NUMBER 1
#endif
#if defined(b2075)
#define SMART_MAX_NUMBER 1
#endif
#if defined(b2076)
#define SMART_MAX_NUMBER 1
#endif
#if defined(mb618)
#define SMART_MAX_NUMBER 2
#endif
#if defined(mb628)
/* No smartcard support */
#endif
#if defined(mb628e)
/* No smartcard support */
#endif
#if defined(eud7141)
/* No smartcard support */
#endif
#if defined(hdkh225)
#define SMART_MAX_NUMBER 1
#endif
#if defined(mb676)
#define SMART_MAX_NUMBER 2
#if defined(ST_OSLINUX)
#undef SMART_MAX_NUMBER
#endif
#endif
#if defined(mb680)
#define SMART_MAX_NUMBER 2
#endif
#if defined(mb704)
#define SMART_MAX_NUMBER 2
#if defined(ST_OSLINUX)
#undef SMART_MAX_NUMBER
#endif
#endif
#if defined(mb796)
#define SMART_MAX_NUMBER 1
#endif
#if defined(mb837)
#define SMART_MAX_NUMBER 1
#endif
#if defined(mb903)
/* No smartcard support */
#endif
#if defined(b2066)
/* No smartcard support */
#endif
#if defined(hmp7105)
/* No smartcard support */
#endif
#if defined(sdk7105)
#define SMART_MAX_NUMBER 2
#endif
#if defined(kourou)
#define SMART_MAX_NUMBER 2
#endif
#if defined(isdb7102)
#define SMART_MAX_NUMBER 1
#endif
#if defined(iptv7105)
/* No smartcard support */
#endif
#if defined(b2068)
#define SMART_MAX_NUMBER 1
#endif
#if defined(hdk7167)
#define SMART_MAX_NUMBER 1
#endif
#if defined(ngb7167)
#define SMART_MAX_NUMBER 1
#endif
#if defined(hdk7197)
#define SMART_MAX_NUMBER 2
#endif
#if defined(hdkh251)
#define SMART_MAX_NUMBER 2
#endif
#if defined(dtt5267)
#define SMART_MAX_NUMBER 1
#endif
#if defined(b2049)
#define SMART_MAX_NUMBER 1
#endif
#if defined(custom001030)
#define SMART_MAX_NUMBER 1
#endif
#if defined(custom001034)
/* No smartcard support */
#endif
#if defined(custom001035)
/* No smartcard support */
#endif
#if defined(custom001036)
#define SMART_MAX_NUMBER 1
#endif
#if defined(custom001039)
/* No smartcard support */
#endif
#if defined(custom002005)
/* No smartcard support */
#endif
#if defined(custom002006)
#define SMART_MAX_NUMBER 1
#endif
#if defined(custom002007)
/* No smartcard support */
#endif
#if defined(custom002008)
/* No smartcard support */
#endif
#if defined(custom003008)
/* No smartcard support */
#endif
#if defined(custom003009)
/* No smartcard support */
#endif
#if defined(custom003011)
/* No smartcard support */
#endif
#if defined(custom003012)
/* No smartcard support */
#endif
#if defined(custom003015)
#define SMART_MAX_NUMBER 1
#endif
#if defined(custom003018)
#define SMART_MAX_NUMBER 1
#endif
#if defined(custom018001)
/* No smartcard support */
#endif
#if defined(custom021001)
/* No smartcard support */
#endif
#if defined(custom022001)
#define SMART_MAX_NUMBER 1
#endif
#if defined(SECURITY)
#if defined(SMART_MAX_NUMBER)
#undef SMART_MAX_NUMBER
#endif
#endif

/* Includes */
/* -------- */
#if defined(SMART_MAX_NUMBER)
#include "stuart.h"
#include "stsmart.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(SMART_MAX_NUMBER)
extern STSMART_Handle_t SMART_Handle[SMART_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t SMART_Init(void);
ST_ErrorCode_t SMART_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

