/*****************************************************************************/
/* COPYRIGHT (C) 2009 STMicroelectronics - All Rights Reserved               */
/* ST makes no warranty express or implied including but not limited to,     */
/* any warranty of                                                           */
/*                                                                           */
/*   (i)  merchantability or fitness for a particular purpose and/or         */
/*   (ii) requirements, for a particular purpose in relation to the LICENSED */
/*        MATERIALS, which is provided “AS IS”, WITH ALL FAULTS. ST does not */
/*        represent or warrant that the LICENSED MATERIALS provided here     */
/*        under is free of infringement of any third party patents,          */
/*        copyrights,trade secrets or other intellectual property rights.    */
/*        ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE       */
/*        EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                    */
/*                                                                           */
/*****************************************************************************/
/**
 @File   stmmdefs.h
 @brief  ST MultiMedia Definitions header file
         Contains a number of generic type declarations and defines between multimedia actors (video, audio,...).

*/
#ifndef __STMMDEFS_H
#define __STMMDEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/* This data structure is identifying the different
 * kind of marker that should be inserted within the data
 * path.
 */
typedef enum ST_MM_Bitstream_Marker_e {
    /* This marker indicates a marker related to an injected chunk list. */
    ST_MARKER_CHUNK_ID = 0,
    /* For Streams injected in a forward manner, this marker indicates that the injected chunk following it is:
        - In the future compared to the previous one.
        - Not temporally linked to the previous one (jump in the future).
     */
    ST_MARKER_BRK_FWD,
    /* For Streams injected in a backward manner, this marker indicates that the injected chunk following it is:
        - In the past compared to the previous one.
        - Not temporally linked to the previous one (jump in the past).
     */
    ST_MARKER_BRK_BWD,
    /* (for future use): For exact boundary matching between injected chunks in backward direction.*/
    ST_MARKER_BRK_BWD_OVERLAP,
    /* (for future use): For forward splicing use cases..*/
    ST_MARKER_BRK_BWD_NO_OVERLAP,
    /* (for future use): For backward splicing use cases..*/
    ST_MARKER_BRK_FWD_SPLICING
} ST_MM_Bitstream_Marker_t;


/* The data structure defines the packing arrangement scheme of a
 * decoded frame. */
typedef enum ST_MM_3D_Format_e {
    ST_3D_NONE,
    ST_3D_FORMAT_SIDEBYSIDE_HALF,
    ST_3D_FORMAT_STACKED_HALF,
    ST_3D_FORMAT_FRAME_SEQ,
    /* Starting this point, all other format are not supported so far.
	 * There are mentioned for information only. */
    ST_3D_FORMAT_SIDEBYSIDE_FULL,
    ST_3D_FORMAT_STACKED_FRAME,
    ST_3D_FORMAT_FIELD_ALTERNATE,
    ST_3D_FORMAT_PICTURE_INTERLEAVE,
    ST_3D_FORMAT_L_D,
    ST_3D_FORMAT_L_D_G_GMINUSD,
    ST_3D_FORMAT_2_INDEP_STREAMS,
    ST_3D_FORMAT_FRAME_SEQ_L_L_R_R
} ST_MM_3D_Format_t;

#ifdef __cplusplus
}
#endif

#endif /* __STMMDEFS_H */
