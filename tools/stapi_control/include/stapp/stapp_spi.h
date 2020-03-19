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
 * @file     stapp_spi.h
 * @brief    This is the spi file header.
 *           It is used to exchange informations between hardware devices using
 *           standart spi protocol.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_SPI_H_
#define _STAPP_SPI_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
#define SPI_MAX_NUMBER 1
#endif
#if defined(sat5189)
#define SPI_MAX_NUMBER 1
#endif
#if defined(sat7111)
#define SPI_MAX_NUMBER 1
#endif
#if defined(adi7108)
/* No SPI support */
#endif
#if defined(hdk5251)
/* No SPI support */
#endif
#if defined(hdk5289)
/* No SPI support */
#endif
#if defined(hdk7108)
/* No SPI support */
#endif
#if defined(hdk7111)
#define SPI_MAX_NUMBER 1
#endif
#if defined(b2069)
#define SPI_MAX_NUMBER 1
#endif
#if defined(b2039)
/* No SPI support */
#endif
#if defined(b2057)
/* No SPI support */
#endif
#if defined(b2064)
/* No SPI support */
#endif
#if defined(b2067)
/* No SPI support */
#endif
#if defined(dp2010)
/* No SPI support */
#endif
#if defined(dp7000)
/* No SPI support */
#endif
#if defined(dp7001)
/* No SPI support */
#endif
#if defined(dp7050)
/* No SPI support */
#endif
#if defined(fx6010)
/* No SPI support */
#endif
#if defined(ep8000)
/* No SPI support */
#endif
#if defined(epp8000)
/* No SPI support */
#endif
#if defined(gpv8000)
/* No SPI support */
#endif
#if defined(b2075)
/* No SPI support */
#endif
#if defined(b2076)
/* No SPI support */
#endif
#if defined(mb618)
#define SPI_MAX_NUMBER 1
#endif
#if defined(mb628)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(mb628e)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(eud7141)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 2
#endif
#endif
#if defined(hdkh225)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 2
#endif
#endif
#if defined(mb676)
#define SPI_MAX_NUMBER 1
#endif
#if defined(mb680)
/* No SPI support */
#endif
#if defined(mb704)
#define SPI_MAX_NUMBER 1
#endif
#if defined(mb796)
/* No SPI support */
#endif
#if defined(mb837)
/* No SPI support */
#endif
#if defined(mb903)
/* No SPI support */
#endif
#if defined(b2066)
/* No SPI support */
#endif
#if defined(hmp7105)
/* No SPI support */
#endif
#if defined(sdk7105)
#if (HARDWARE_REVISION>=5)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(kourou)
/* No SPI support */
#endif
#if defined(isdb7102)
#define SPI_MAX_NUMBER 1
#endif
#if defined(iptv7105)
#define SPI_MAX_NUMBER 1
#endif
#if defined(b2068)
#define SPI_MAX_NUMBER 1
#endif
#if defined(hdk7167)
#if (HARDWARE_REVISION>=2)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(ngb7167)
/* No SPI support */
#endif
#if defined(hdk7197)
#define SPI_MAX_NUMBER 1
#endif
#if defined(hdkh251)
#define SPI_MAX_NUMBER 1
#endif
#if defined(dtt5267)
#if (HARDWARE_REVISION>=2)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(b2049)
#define SPI_MAX_NUMBER 1
#endif
#if defined(custom001030)
/* No SPI support */
#endif
#if defined(custom001034)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(custom001035)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(custom001036)
/* No SPI support */
#endif
#if defined(custom001039)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(custom002005)
/* No SPI support */
#endif
#if defined(custom002006)
/* No SPI support */
#endif
#if defined(custom002007)
/* No SPI support */
#endif
#if defined(custom002008)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(custom003008)
/* No SPI support */
#endif
#if defined(custom003009)
/* No SPI support */
#endif
#if defined(custom003011)
/* No SPI support */
#endif
#if defined(custom003012)
/* No SPI support */
#endif
#if defined(custom003015)
#define SPI_MAX_NUMBER 1
#endif
#if defined(custom003018)
#define SPI_MAX_NUMBER 1
#endif
#if defined(custom018001)
/* No SPI support */
#endif
#if defined(custom021001)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 1
#endif
#endif
#if defined(custom022001)
#if (CABLE_MODEM_ATTACHED==0)
#define SPI_MAX_NUMBER 1
#endif
#endif
/* For linux, stspi is not yet officially supported */
#if defined(ST_OSLINUX)
#if defined(SPI_MAX_NUMBER)
#undef SPI_MAX_NUMBER
#endif
#endif

/* Includes */
/* -------- */
#if defined(SPI_MAX_NUMBER)
#include "stspi.h"
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t SPI_Init(void);
ST_ErrorCode_t SPI_Term(void);
#if defined(SPI_MAX_NUMBER)
ST_ErrorCode_t SPI_Read (U32 SPI_Device,U32 SPI_ChipSelect,U32 Register,U32 *Value);
ST_ErrorCode_t SPI_Write(U32 SPI_Device,U32 SPI_ChipSelect,U32 Register,U32  Value);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

