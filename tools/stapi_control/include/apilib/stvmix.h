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
 @File   stvmix.h                                                              
 @brief                                                                         
                                                                               
                                                                               
                                                                               
*/


#ifndef __STVMIX_H
#define __STVMIX_H


/******************************************************************************/
/* Modules includes                                                           */
/******************************************************************************/
#include "stddefs.h"
#include "stgxobj.h"
#include "stavmem.h"


#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/* Public constants                                                           */
/******************************************************************************/
#define  STVMIX_DRIVER_ID       160                              /* Driver ID */
#define  STVMIX_DRIVER_BASE     (STVMIX_DRIVER_ID << 16)

enum                                                    /* STVMIX Error Codes */
{
    STVMIX_ERROR_LAYER_UNKNOWN = STVMIX_DRIVER_BASE
  , STVMIX_ERROR_LAYER_UPDATE_PARAMETERS
  , STVMIX_ERROR_LAYER_ALREADY_CONNECTED
  , STVMIX_ERROR_LAYER_ACCESS
  , STVMIX_ERROR_VOUT_UNKNOWN
  , STVMIX_ERROR_VOUT_ALREADY_CONNECTED
  , STVMIX_ERROR_NO_VSYNC
};


/******************************************************************************/
/* Public types                                                               */
/******************************************************************************/
typedef enum STVMIX_DeviceType_e
{
    STVMIX_COMPOSITOR
  , STVMIX_GENERIC_GAMMA_TYPE_7111
  , STVMIX_GENERIC_GAMMA_TYPE_7105
  , STVMIX_GENERIC_GAMMA_TYPE_7141
  , STVMIX_GENERIC_GAMMA_TYPE_5206
  , STVMIX_GENERIC_GAMMA_TYPE_7108
  , STVMIX_GENERIC_GAMMA_TYPE_H205
  , STVMIX_COMPOSITOR_FIELD
  , STVMIX_COMPOSITOR_FIELD_SDRAM
  , STVMIX_COMPOSITOR_FIELD_COMBINED
  , STVMIX_COMPOSITOR_FIELD_COMBINED_SDRAM
  , STVMIX_COMPOSITOR_422
  , STVMIX_COMPOSITOR_FIELD_422
  , STVMIX_COMPOSITOR_FIELD_SDRAM_422
  , STVMIX_COMPOSITOR_FIELD_COMBINED_422
  , STVMIX_COMPOSITOR_FIELD_COMBINED_SDRAM_422

} STVMIX_DeviceType_t;


typedef struct STVMIX_RegisterInfo_s
{
    void*  CompoBaseAddress_p;                              /* COMPO registers related */
    void*  GdmaBaseAddress_p;                               /* GDMA registers related  */
    void*  VoutBaseAddress_p;                               /* VOUT registers related  */

} STVMIX_RegisterInfo_t;


typedef struct STVMIX_InitParams_s
{
    ST_Partition_t*             CPUPartition_p;             /* Driver memory pool */
    void*                       BaseAddress_p;              /* Mixer offset wrt compositor base address */
    void*                       DeviceBaseAddress_p;        /* Compositor base address */
    STVMIX_DeviceType_t         DeviceType;                 /* Device type */
    U32                         MaxOpen;                    /* Maximum number of clients */
    U16                         MaxLayer;                   /* Maximum number of layers to be connected */
    ST_DeviceName_t             VTGName;                    /* VTG associated with mixer */
    ST_DeviceName_t             EvtHandlerName;             /* Name of Event manager */
    ST_DeviceName_t*            OutputArray_p;              /* Outputs connected to mixer */
    STAVMEM_PartitionHandle_t   AVMEM_Partition;            /* Video memory pool for mixer use */
    STAVMEM_PartitionHandle_t   AVMEM_Partition2;           /* Video memory pool used for OutputBitmap */
    STVMIX_RegisterInfo_t       RegisterInfo;               /* Device base address for BDISP based mixer */
    STGXOBJ_Bitmap_t*           CacheBitmap_p;              /* Cached bitmap for BDISP based mixer */

} STVMIX_InitParams_t;


typedef U32  STVMIX_Handle_t;
typedef U32  STVMIX_VBIViewPortHandle_t;


typedef struct STVMIX_Capability_s
{
    S8   ScreenOffsetVerticalMin;
    S8   ScreenOffsetVerticalMax;
    S8   ScreenOffsetHorizontalMin;
    S8   ScreenOffsetHorizontalMax;

} STVMIX_Capability_t;


typedef enum STVMIX_VBIType_e
{
    STVMIX_VBI_TXT_ODD
  , STVMIX_VBI_TXT_EVEN

} STVMIX_VBIViewPortType_t;


typedef U8 STVMIX_VBISource_t;


typedef struct STVMIX_VBIViewPortParams_s
{
    STVMIX_VBISource_t*        Source_p;                    /* VBI viewport source */
    U32                        LineMask;                    /* Selected teletext lines */

} STVMIX_VBIViewPortParams_t;


typedef struct STVMIX_LayerDisplayParams_s
{
    ST_DeviceName_t            DeviceName;                  /* Layer device name */
    BOOL                       ActiveSignal;                /* If HW supported, use pin active signal ? */

} STVMIX_LayerDisplayParams_t;


typedef struct
{
    U8    Dummy;

} STVMIX_OpenParams_t;


typedef struct STVMIX_ScreenParams_s
{
    STGXOBJ_AspectRatio_t   AspectRatio;                    /* Output aspect ratio */
    STGXOBJ_ScanType_t      ScanType;                       /* Output scan type */
    U32                     FrameRate;                      /* Framerate in millihertz */
    U32                     Width;                          /* Active area width */
    U32                     Height;                         /* Active area height */
    U32                     XStart;                         /* XStart of active area */
    U32                     YStart;                         /* YStart of active area */

} STVMIX_ScreenParams_t;


typedef struct STVMIX_TermParams_s
{
    BOOL    ForceTerminate;

} STVMIX_TermParams_t;


/******************************************************************************/
/* Public macros                                                              */
/******************************************************************************/

/******************************************************************************/
/* Public functions prototypes                                                */
/******************************************************************************/
ST_Revision_t   STVMIX_GetRevision( void );

ST_ErrorCode_t  STVMIX_GetCapability
                    ( const ST_DeviceName_t                         DeviceName
                    , STVMIX_Capability_t* const                    Capability_p
                    );

ST_ErrorCode_t  STVMIX_Init
                    ( const ST_DeviceName_t                         DeviceName
                    , const STVMIX_InitParams_t * const             InitParams_p
                    );
ST_ErrorCode_t  STVMIX_Term
                    ( const ST_DeviceName_t                         DeviceName
                    , const STVMIX_TermParams_t * const             TermParams_p
                    );

ST_ErrorCode_t  STVMIX_Open
                    ( const ST_DeviceName_t                         DeviceName
                    , const STVMIX_OpenParams_t* const              OpenParams_p
                    , STVMIX_Handle_t* const                        Handle_p
                    );
ST_ErrorCode_t  STVMIX_Close
                    ( const STVMIX_Handle_t                         Handle
                    );

ST_ErrorCode_t  STVMIX_SetTimeBase
                    ( const STVMIX_Handle_t                         Handle
                    , const ST_DeviceName_t                         VTGDriver
                    );
ST_ErrorCode_t  STVMIX_GetTimeBase
                    ( const STVMIX_Handle_t                         Handle
                    , ST_DeviceName_t* const                        VTGDriver_p
                    );

ST_ErrorCode_t  STVMIX_ConnectLayers
                    ( const STVMIX_Handle_t                         Handle
                    , const STVMIX_LayerDisplayParams_t*  const     LayerDisplayParams[]
                    , const U16                                     NbLayerParams
                    );
ST_ErrorCode_t  STVMIX_DisconnectLayers
                    ( const STVMIX_Handle_t                         Handle
                    );
ST_ErrorCode_t  STVMIX_GetConnectedLayers
                    ( const STVMIX_Handle_t                         Handle
                    , const U16                                     LayerPosition
                    , STVMIX_LayerDisplayParams_t* const            LayerParams_p
                    );

ST_ErrorCode_t  STVMIX_Enable
                    ( const STVMIX_Handle_t                         Handle
                    );
ST_ErrorCode_t  STVMIX_Disable
                    ( const STVMIX_Handle_t                         Handle
                    );

ST_ErrorCode_t  STVMIX_SetBackgroundColor
                    ( const STVMIX_Handle_t                         Handle
                    , const STGXOBJ_ColorRGB_t                      RGB888
                    , const BOOL                                    Enable
                    );
ST_ErrorCode_t  STVMIX_GetBackgroundColor
                    ( const STVMIX_Handle_t                         Handle
                    , STGXOBJ_ColorRGB_t* const                     RGB888_p
                    , BOOL* const                                   Enable_p
                    );

ST_ErrorCode_t  STVMIX_SetScreenOffset
                    ( const STVMIX_Handle_t                         Handle
                    , const S8                                      Horizontal
                    , const S8                                      Vertical
                    );
ST_ErrorCode_t  STVMIX_GetScreenOffset
                    ( const STVMIX_Handle_t                         Handle
                    , S8* const                                     Horizontal_p
                    , S8* const                                     Vertical_p
                    );

ST_ErrorCode_t  STVMIX_SetScreenParams
                    ( const STVMIX_Handle_t                         Handle
                    , const STVMIX_ScreenParams_t* const            ScreenParams_p
                    );
ST_ErrorCode_t  STVMIX_GetScreenParams
                    ( const STVMIX_Handle_t                         Handle
                    , STVMIX_ScreenParams_t* const                  ScreenParams_p
                    );

ST_ErrorCode_t  STVMIX_EnableGlobalFlickerFilter
                    ( const STVMIX_Handle_t                         Handle
                    );
ST_ErrorCode_t  STVMIX_DisableGlobalFlickerFilter
                    ( const STVMIX_Handle_t                         Handle
                    );

ST_ErrorCode_t  STVMIX_OpenVBIViewPort
                    ( STVMIX_Handle_t                               Handle
                    , STVMIX_VBIViewPortType_t                      VBIType
                    , STVMIX_VBIViewPortHandle_t*                   VPHandle_p
                    );
ST_ErrorCode_t  STVMIX_CloseVBIViewPort
                    ( STVMIX_VBIViewPortHandle_t                    VPHandle
                    );

ST_ErrorCode_t  STVMIX_EnableVBIViewPort
                    ( STVMIX_VBIViewPortHandle_t                    VPHandle
                    );
ST_ErrorCode_t  STVMIX_DisableVBIViewPort
                    ( STVMIX_VBIViewPortHandle_t                    VPHandle
                    );

ST_ErrorCode_t  STVMIX_SetVBIViewPortParams
                    ( STVMIX_VBIViewPortHandle_t                    VPHandle
                    , STVMIX_VBIViewPortParams_t*                   Params_p
                    );


#ifdef __cplusplus
}
#endif

#endif /* #ifndef __STVMIX_H */
