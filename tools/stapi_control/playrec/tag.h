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
 * @file     tag.h
 * @brief    This is the tag (player and recorder) header file api.
 *           It is used to set or get generic tags from the playrec component.
 * @author   STMicroelectronics
 */

#ifndef _PLAYREC_TAG_H_
#define _PLAYREC_TAG_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constant definition */
/* ------------------- */
#define TAG_CODENAME_SIZE_MAX         50 /* Maximum length size of the codec identification     */
#define TAG_CONTAINERNAME_SIZE_MAX    20 /* Maximum length size of the container identification */
#define TAG_LANGUAGE_SIZE_MAX         32 /* Maximum length size of the language identification  */
#define TAG_DESCRIPTOR_SIZE_MAX     1024 /* Maxiumm lenght size of the ca descriptor            */

/* Track type definition */
/* --------------------- */
typedef enum TAG_TrackType_e
{
 TAG_TRACK_INVALID,
 TAG_TRACK_AUDIO,
 TAG_TRACK_VIDEO,
 TAG_TRACK_SUBTITLE,
 TAG_TRACK_TELETEXT,
 TAG_TRACK_PCR
} TAG_TrackType_t;

/* Complex Data type  */
/* ------------------ */
typedef enum TAG_DataType_s
{
 TAG_DATA_UNDEFINED,  /* Type undefined                                  */
 TAG_DATA_UTF_8,      /* Unicode UTF-8                                   */
 TAG_DATA_UTF_16,     /* Unicode UTF-16                                  */
 TAG_DATA_UTF_32,     /* Unicode UTF-32                                  */
 TAG_DATA_ISO8859_1,  /* Standard byte array definition                  */
 TAG_DATA_ISO8850_1,  /* Standard byte definition + control / characters */
 TAG_DATA_BOOL,       /* Boolean value coded on 32 bits                  */
 TAG_DATA_DWORD,      /* Value coded on 32 bits                          */
 TAG_DATA_QWORD,      /* Value coded on 64 bits                          */
 TAG_DATA_WORD,       /* Value coded on 16 bits                          */
 TAG_DATA_CHAR        /* Value coded on 8 bits                           */
} TAG_DataType_t;


/* Aspect Ratio definition */
/* ----------------------- */
typedef enum TAG_AspectRatio_s
{
 TAG_ASPECTRATIO_UNDEFINED,
 TAG_ASPECTRATIO_SQUARE,
 TAG_ASPECTRATIO_4TO3,
 TAG_ASPECTRATIO_16TO9,
 TAG_ASPECTRATIO_221TO1
} TAG_AspectRatio_t;

/* Generic type */
/* ------------ */
typedef struct TAG_GenericType_s
{
 TAG_DataType_t type;
 unsigned int length;
 unsigned char *data;
} TAG_GenericType_t;

/* To Identify the kind of TAG_ComplexType_t is */
/* ----------------------- */
typedef enum TAG_ExtendedType_s
{
 TAG_EXTENDED_TYPE_UNDEFINED,
 TAG_EXTENDED_TYPE_CHAPTER_INFO,
 TAG_EXTENDED_TYPE_FONT_ATTACHMENT
} TAG_ExtendedType_t;


/* Generic type = complex data  */
/* ---------------------------- */
typedef struct TAG_ComplexType_s
{
 TAG_GenericType_t name;
 TAG_GenericType_t value;
} TAG_ComplexType_t;

/* General stream info */
/* ------------------- */
typedef struct TAG_Generic_Info_s
{
 char               container[TAG_CONTAINERNAME_SIZE_MAX];
 unsigned int       year;
 TAG_GenericType_t  title;
 TAG_GenericType_t  author;
 TAG_GenericType_t  album;
 TAG_GenericType_t  genre;
 TAG_GenericType_t  copyright;
 TAG_GenericType_t  description;
 TAG_GenericType_t  rating;
 unsigned long long filesize;                             /* Filesize in bytes             */
 unsigned long long duration;                             /* Duration in ms                */
 unsigned int       bitrate;                              /* bitrate in bits/s             */
 unsigned int       nbtrack;                              /* Number of track               */
 unsigned int       nbprogram;                            /* Number of program             */
 unsigned int       nbextendedinfo;                       /* Number of extended info       */
 unsigned int       nbdescriptors;                        /* Number of descriptors         */
 char               descriptors[TAG_DESCRIPTOR_SIZE_MAX]; /* List of dvb descriptors       */
 unsigned char     *pat;                                  /* Dvb pat raw buffer            */
 unsigned int       patsize;                              /* Dvb pat raw buffer size       */
 unsigned char     *pmt;                                  /* Dvb pmt raw buffer            */
 unsigned int       pmtsize;                              /* Dvb pmt raw buffer            */
 unsigned char     *ecm;                                  /* Dvb first ecm raw buffer      */
 unsigned int       ecmsize;                              /* Dvb first ecm raw buffer size */
 BOOL               isMultimediaFile;                     /* TRUE if it's a media file     */
} TAG_Generic_Info_t;

/* Program info */
/* ------------ */
typedef struct TAG_Program_Info_s
{
 unsigned short id;
} TAG_Program_Info_t;

/* Video track info */
/* ---------------- */
typedef struct TAG_Video_Info_s
{
 unsigned int width;             /* Video width (pixels)   */
 unsigned int height;            /* Video height (pixels)  */
 unsigned int bitrate;           /* Video bitrate (bits/s) */
 unsigned int framerate;         /* Video framerate (fps)  */
 TAG_AspectRatio_t aspectratio;  /* Video aspect ratio     */
} TAG_Video_Info_t;

/* Audio track info */
/* ---------------- */
typedef struct TAG_Audio_Info_s
{
 unsigned int bitrate;    /* Audio bitrate    (bits/s) */
 unsigned int samplerate; /* Audio samplerate (khz)    */
} TAG_Audio_Info_t;

/* Subtitle track info */
/* ------------------- */
typedef struct TAG_Subtitle_Info_s
{
 unsigned char  type;
 unsigned short composition_page_id;
 unsigned short ancillary_page_id;
} TAG_Subtitle_Info_t;

/* Pcr track info */
/* -------------- */
typedef struct TAG_Pcr_Info_s
{
} TAG_Pcr_Info_t;

/* Teletext track info */
/* ------------------- */
typedef struct TAG_Teletext_Info_s
{
 unsigned char type;
 unsigned char magazine_number;
 unsigned char page_number;
} TAG_Teletext_Info_t;

/* Language definition */
/* ------------------- */
typedef struct TAG_Language_s
{
 char slang[TAG_LANGUAGE_SIZE_MAX];
 TAG_GenericType_t lang;
} TAG_Language_t;

/* Track info */
/* ---------- */
typedef struct TAG_Track_Info_s
{
 unsigned short    prognumber;
 unsigned short    programid;
 unsigned short    id;
 char             *contentid;
 unsigned int      nbdescriptors;
 TAG_TrackType_t   type;
 TAG_GenericType_t trackName;
 char              codec[TAG_CODENAME_SIZE_MAX];
 char              descriptors[TAG_DESCRIPTOR_SIZE_MAX];
 TAG_Language_t    language;
 union
  {
   TAG_Video_Info_t    video;
   TAG_Audio_Info_t    audio;
   TAG_Subtitle_Info_t subtitle;
   TAG_Pcr_Info_t      pcr;
   TAG_Teletext_Info_t teletext;
  } info;
} TAG_Track_Info_t;

/* Tags in Get mode */
/* ---------------- */
typedef enum TAG_ContentFlags_e
{
 TAG_GENERIC_INFO,
 TAG_TRACK_INFO,
 TAG_PROGRAM_INFOS,
 TAG_EXTENDED_INFOS
} TAG_ContentFlags_t;

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif /* _PLAYREC_TAG_H_ */


