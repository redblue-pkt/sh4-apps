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
 * @file     stapp_text.h
 * @brief    This is the embedded text font toolkit file header.
 *           It uses blitter to accelerate text rendering.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_TEXT_H_
#define _STAPP_TEXT_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
/* -------- */
#include "stgxobj.h"

/* Constants */
/* --------- */
#define TEXT_ALLOCATE_DEFAULT_FONT
#define TEXT_MAX_STRING_SIZE                  (255)
#define TEXT_DEFAULT_SPACE_BETWEEN_CHARACTERS (2)
#define TEXT_MAX_NUMBER_OF_TEXT_OBJECTS       (50)
#define TEXT_MAX_NUMBER_OF_USER_FONTS         (8)
#define TEXT_FONT_NAME_SIZE                   (24)

/* Handle definition */
/* ----------------- */
typedef U32 TEXT_FontHandle_t;

/* Wrap mode definition */
/* -------------------- */
typedef enum TEXT_WrapMode_e
{
 TEXT_WRAP_NO=0,
 TEXT_WRAP_CHARACTER
} TEXT_WrapMode_t;

/* Font type definition */
/* -------------------- */
typedef enum TEXT_FontType_e
{
 TEXT_FONT_TYPE_REGULAR=0,
 TEXT_FONT_TYPE_BOLD,
 TEXT_FONT_TYPE_ITALIC
} TEXT_FontType_t;

/* Color type definition */
/* --------------------- */
typedef enum TEXT_FontColor_e
{
 TEXT_COLOR_B_W=0,   /* Grey scale (black charater and white is transparent)                      */
 TEXT_COLOR_B_W_INV, /* Grey scale inverted (black on white is displayed as white on transparent) */
 TEXT_COLOR_COLOR
} TEXT_FontColor_t;

/* Source type definition */
/* ---------------------- */
typedef enum TEXT_FontSource_e
{
 TEXT_FONT_SOURCE_BMP=0
} TEXT_FontSource_t;

/* Init parameters definition */
/* -------------------------- */
typedef struct TEXT_FontInitParameters_s
{
 U8                 FontName[TEXT_FONT_NAME_SIZE];   /* Name of the font                                                  */
 TEXT_FontHandle_t  FontHandle;                      /* Number of the font (same for Regular/Bold/Italic of the same font */
 TEXT_FontType_t    FontType;                        /* Regular, Bold, Italic...                                          */
 TEXT_FontColor_t   FontColor;                       /* Black and white font or colored font                              */
 TEXT_FontSource_t  FontSource;                      /* Type of source (only bitmap supported)                            */
 BOOL               FixedSize;                       /* Fixed size font                                                   */
 BOOL               KeyColor;                        /* TRUE if a color is used for transparancy                          */
 U32                RGBKeyColor;                     /* Color used for transparency for colored font                      */
} TEXT_FontInitParameters_t;

/* Font parameters definition */
/* -------------------------- */
typedef struct TEXT_FontParameters_s
{
 U8                 FontName[TEXT_FONT_NAME_SIZE];   /* Name of the font                                */
 U32                NumberOfCaracters;               /* Number of characters in the font                */
 S16                MaxCharacterSizeAboveReference;  /* Character size above the Y_Pos (negative value) */
 S16                MaxCharacterSizeBellowReference; /* Character size under the Y_Pos (positive value) */
 U16                MaxCharacterWidth;               /* Width of the widthest character                 */
 U16                MaxCharacterHeight;              /* Max height needed by a line of character        */
 U16                CharacterSpaceSize;              /* Size of the character space                     */
 TEXT_FontType_t    FontType;                        /* Type of the font                                */
} TEXT_FontParameters_t;

/* Text parameters definition */
/* -------------------------- */
typedef struct TEXT_Parameters_s
{
 TEXT_FontHandle_t  FontHandle;
 STGXOBJ_Bitmap_t  *GFX_LAYER_GXOBJ_Bitmap_p;  /* Destination bitmap                                         */
 STGXOBJ_Palette_t *GFX_LAYER_GXOBJ_Palette_p; /* Destination palette                                        */
 BOOL               FixedWidthCharacterSize;   /* TRUE : All characters have the same width                  */
 TEXT_WrapMode_t    WrapMode;                  /* Set text auto wrap mode at right side container limit      */
 BOOL               Blend;                     /* TRUE : Blend with destination bitmap, FALSE : overwrite    */
 BOOL               Append;                    /* TRUE : Append text to previous one (X_Pos, Y_Pos not used) */
 U32                Color;                     /* Color of the characters. Format is 0x00RRGGBB              */
 U32                X_Pos;                     /* X position in the container                                */
 U32                Y_Pos;                     /* Y position in the container                                */
 S16                Container_XPos;            /* X position of the container in the bitmap                  */
 S16                Container_YPos;            /* Y position of the container in the bitmap                  */
 U16                Container_Width;           /* Width of the container in the bitmap                       */
 U16                Container_Height;          /* Height of the container in the bitmap                      */
 U8                 Alpha;                     /* Global Transparency (to set once for each Print)           */
} TEXT_Parameters_t;

/* Prototypes */
/* ---------- */
ST_ErrorCode_t TEXT_Init              (void);
ST_ErrorCode_t TEXT_Term              (void);
ST_Revision_t  TEXT_GetRevision       (void);
ST_ErrorCode_t TEXT_CreateFont        (U8 *Bitmap_p,TEXT_FontInitParameters_t *FontInitParameters_p);
ST_ErrorCode_t TEXT_GetFontParameters (TEXT_FontHandle_t FontHandle,TEXT_FontType_t FontType,TEXT_FontParameters_t *FontParams_p);
ST_ErrorCode_t TEXT_FreeFont          (TEXT_FontHandle_t FontHandle);
ST_ErrorCode_t TEXT_GetTextHandle     (TEXT_Parameters_t **TextParams_p);
ST_ErrorCode_t TEXT_FreeTextHandle    (TEXT_Parameters_t  *TextParams_p);
ST_ErrorCode_t TEXT_PrintText         (TEXT_Parameters_t  *TextParams_p,const char *format,...);
ST_ErrorCode_t TEXT_ClearText         (TEXT_Parameters_t  *TextParams_p);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

