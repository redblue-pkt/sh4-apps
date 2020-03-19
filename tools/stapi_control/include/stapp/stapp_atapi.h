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
 * @file     stapp_atapi.h
 * @brief    This is the atapi file header.
 *           It is used to gives access to SATA/PATA mass storage interfaces through OSPLUS.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_ATAPI_H_
#define _STAPP_ATAPI_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
/* ATAPI_PATA_MAX_NUMBER : is the maximum number of ATAPI interfaces using standard PIO/EMI interface   */
/*                         When this is not defined, it means that there is not such ATAPI on the board */
/* ATAPI_SATA_MAX_NUMBER : is the maximum number of SATA interfaces supported by the chipset itself     */
/*                         When this is not defined, it means that there is not such SATA on the board  */
/* ATAPI_MAX_NUMBER      : is the maximum number of PATA/SATA interfaces working simultaneous           */
/*                         When not defined, all the ATA code is completly disabled                     */
#if defined(cab5197)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif

#if defined(sat5189)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif

#if defined(sat7111)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif

#if defined(adi7108)
#define ATAPI_SATA_MAX_NUMBER 1
/*#define ATAPI_PATA_MAX_NUMBER 2*/
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif

#if defined(hdk5251)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif

#if defined(hdk5289)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif

#if defined(hdk7108)
#define ATAPI_SATA_MAX_NUMBER 1
/*#define ATAPI_PATA_MAX_NUMBER 2*/
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif

#if defined(hdk7111)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif

#if defined(b2069)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif

#if defined(b2039)
#define ATAPI_SATA_MAX_NUMBER 1
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif

#if defined(b2057)
#define ATAPI_SATA_MAX_NUMBER 1
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#if defined(b2064)
#if !defined(ST_H238)
#define ATAPI_SATA_MAX_NUMBER 1
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(ep8000)
#if !defined(ST_H238)
#define ATAPI_SATA_MAX_NUMBER 1
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(epp8000)
#if !defined(ST_H238)
#define ATAPI_SATA_MAX_NUMBER 1
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(gpv8000)
#if !defined(ST_H238)
#define ATAPI_SATA_MAX_NUMBER 1
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(b2067)
#if !(defined(ST_h237)|| defined(ST_h271))
#define ATAPI_SATA_MAX_NUMBER 1
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(dp2010)
#if !(defined(ST_h237)|| defined(ST_h271))
#define ATAPI_SATA_MAX_NUMBER 0
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(dp7000)
#if !(defined(ST_h237)|| defined(ST_h271))
#define ATAPI_SATA_MAX_NUMBER -
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(dp7001)
#if !(defined(ST_h237)|| defined(ST_h271))
#define ATAPI_SATA_MAX_NUMBER -
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(dp7050)
#if !(defined(ST_h237)|| defined(ST_h271))
#define ATAPI_SATA_MAX_NUMBER -
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(fx6010)
#if !(defined(ST_h237)|| defined(ST_h271))
#define ATAPI_SATA_MAX_NUMBER 0
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#endif
#if defined(b2075)
#define ATAPI_SATA_MAX_NUMBER 1
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#if defined(b2076)
#define ATAPI_SATA_MAX_NUMBER 1
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#if defined(mb618)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif
#if defined(mb628)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(mb628e)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(eud7141)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(hdkh225)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(mb676)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif
#if defined(mb796)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif
#if defined(mb680)
#define ATAPI_SATA_MAX_NUMBER 1
/*#define ATAPI_PATA_MAX_NUMBER 2*/
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#if defined(mb704)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif
#if defined(mb837)
#define ATAPI_SATA_MAX_NUMBER 1
/*#define ATAPI_PATA_MAX_NUMBER 2*/
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#if defined(mb903)
#define ATAPI_SATA_MAX_NUMBER 1
/*#define ATAPI_PATA_MAX_NUMBER 2*/
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER/*+ATAPI_PATA_MAX_NUMBER*/)
#endif
#if defined(b2066)
/*No SATA Support*/
#endif
#if defined(hmp7105)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif
#if defined(sdk7105)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(kourou)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(isdb7102)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(iptv7105)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(b2068)
/* #define ATAPI_SATA_MAX_NUMBER 1                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER) */
#endif
#if defined(hdk7167)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(hdk7197)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(hdkh251)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(dtt5267)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(b2049)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom001030)
/* No hard disk drive */
#endif
#if defined(custom001034)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom001035)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom001036)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom001039)
/* No hard disk drive */
#endif
#if defined(custom002005)
/* No hard disk drive */
#endif
#if defined(custom002006)
/* #define ATAPI_PATA_MAX_NUMBER 2                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_PATA_MAX_NUMBER) */
#endif
#if defined(custom002007)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom002008)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom003008)
/* No hard disk drive */
#endif
#if defined(custom003009)
/* No hard disk drive */
#endif
#if defined(custom003011)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom003012)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom003015)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom003018)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
#if defined(custom018001)
/* No hard disk drive */
#endif
#if defined(custom021001)
/* #define ATAPI_SATA_MAX_NUMBER 1                       */
/* #define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER) */
#endif
#if defined(custom022001)
#define ATAPI_SATA_MAX_NUMBER 1
#define ATAPI_MAX_NUMBER      (ATAPI_SATA_MAX_NUMBER)
#endif
/* For linux, ATAPI interface is managed directly by the kernel */
#if defined(ST_OSLINUX)
#if defined(ATAPI_MAX_NUMBER)
#undef ATAPI_MAX_NUMBER
#endif
#if defined(ATAPI_PATA_MAX_NUMBER)
#undef ATAPI_PATA_MAX_NUMBER
#endif
#if defined(ATAPI_SATA_MAX_NUMBER)
#undef ATAPI_SATA_MAX_NUMBER
#endif
#endif

/* Includes */
/* -------- */
#if defined(ATAPI_MAX_NUMBER)
#include "statapi.h"
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t ATAPI_Init(void);
ST_ErrorCode_t ATAPI_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

