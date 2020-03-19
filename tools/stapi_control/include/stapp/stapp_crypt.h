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
 * @file     stapp_crypt.h
 * @brief    This is the encryption/decryption file header.
 *           It is used to encrypt/decrypt mass storage or buffer content
 * @author   STMicroelectronics
 */

#ifndef _STAPP_CRYPT_H_
#define _STAPP_CRYPT_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
/* No crypto support */
#endif
#if defined(ST_5206)
/* No crypto support */
#endif
#if defined(ST_7105)
#define CRYPT_MAX_NUMBER 1
#define TKDMA_MAX_NUMBER 1
#endif
#if defined(ST_7108)
#define CRYPT_MAX_NUMBER 1
#endif
#if defined(ST_7111)
#define CRYPT_MAX_NUMBER 1
#define TKDMA_MAX_NUMBER 1
#endif
#if defined(ST_7141)
/* Crypto plain dma libraries not available, not yet supported */
/*#define CRYPT_MAX_NUMBER 1*/
#endif
#if defined(ST_H205)
/* No crypto support */
#endif
#if defined(SECURITY)||defined(ST_OSLINUX)
#if defined(CRYPT_MAX_NUMBER)&&(!defined(DRM_SUPPORTED))
#undef CRYPT_MAX_NUMBER
#undef TKDMA_MAX_NUMBER
#undef TKD_MAX_NUMBER
#endif
#endif
#if defined(VIRTUAL_PLATFORM_TLM)
#undef CRYPT_MAX_NUMBER
#undef TKDMA_MAX_NUMBER
#undef TKD_MAX_NUMBER
#endif

#if defined(CRYPT_MAX_NUMBER)&&defined(DRM_SUPPORTED)&&defined(DIVXDRM_SUPPORT)
#undef TKDMA_MAX_NUMBER
#undef TKD_MAX_NUMBER
#endif
#if defined(CRYPT_MAX_NUMBER)&&defined(DRM_SUPPORTED)&&defined(PLAYREADYDRM_SUPPORT)
#undef TKDMA_MAX_NUMBER
#undef TKD_MAX_NUMBER
#endif

/* Includes */
/* -------- */
#if defined(CRYPT_MAX_NUMBER)&&defined(TKDMA_MAX_NUMBER)
#include "sttkdma.h"
#endif
#if defined(CRYPT_MAX_NUMBER)&&defined(TKD_MAX_NUMBER)
/*TODO: #include "sttkd.h"   To be included later*/
#endif

/* Crypto mode */
/* ----------- */
#if defined(CRYPT_MAX_NUMBER)
typedef enum
{
 CRYPT_MODE_ENCRYPT  = 0x00000001,
 CRYPT_MODE_DECRYPT  = 0x00000002,
 CRYPT_MODE_USER     = 0x01000000,
 CRYPT_MODE_PHYSICAL = 0x02000000,
 CRYPT_MODE_PLAIN    = 0x10000000,
 CRYPT_MODE_AES      = 0x20000000,
 CRYPT_MODE_TDES     = 0x30000000
} CRYPT_Mode_t;
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t CRYPT_Init(void);
ST_ErrorCode_t CRYPT_Term(void);
#if defined(CRYPT_MAX_NUMBER)
ST_ErrorCode_t CRYPT_Transfer(U32 StartAddress,U32 DestinationAddress,U32 Size,CRYPT_Mode_t Mode);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

