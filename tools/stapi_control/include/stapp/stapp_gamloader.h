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
 * @file     stapp_gamloader.h
 * @brief    This is the .gam loader file header.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_GAMLOADER_H_
#define _STAPP_GAMLOADER_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
/* -------- */
#include "stgxobj.h"

/* GAM object descriptor */
/* --------------------- */
typedef struct GAMLOAD_Object
{
 STGXOBJ_Bitmap_t  *Bitmap;
 STGXOBJ_Palette_t *Palette;
} GAMLOAD_Object_t;

/* Prototypes */
/* ---------- */
ST_ErrorCode_t GAMLOAD_Init(void);
ST_ErrorCode_t GAMLOAD_Term(void);
ST_ErrorCode_t GAMLOAD_LoadGamFile(char *FileName,GAMLOAD_Object_t *Object);
ST_ErrorCode_t GAMLOAD_SaveGamFile(char *FileName,GAMLOAD_Object_t *Object);
ST_ErrorCode_t GAMLOAD_FreeGamFile(GAMLOAD_Object_t *Object);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

