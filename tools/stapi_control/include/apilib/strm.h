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
 @File   strm.h
 @brief
*/

#ifndef __STRM_H
#define __STRM_H

/* --------------------------------------------------------------------------------
Get revision of STRM API
-------------------------------------------------------------------------------- */
#define STRM_GetRevision() ((ST_Revision_t) "STRM-REL_2.0.9")

/* Includes ----------------------------------------------------------------- */
#include "stddefs.h"
#include "stddef.h"    // size_t

/* C++ support */
#ifdef __cplusplus
extern "C" {
#endif

/* Driver constants, required by the driver model */
#define STRM_DRIVER_ID        59
#define STRM_DRIVER_BASE      (STRM_DRIVER_ID << 16)

/* Exported Constants ------------------------------------------------------- */
#define STRM_MAX_STRING_LENGTH 48  /* 47 characters plus '\0' */

/* Exported Types ----------------------------------------------------------- */
typedef U32 STRM_Handle_t;
typedef int STRM_Id_t;
typedef char STRM_String_t[STRM_MAX_STRING_LENGTH];
typedef enum {UNKNOWN_RESOURCE_TYPE, DEVICE, PORT, PROPERTY} STRM_Resource_Type_t;
typedef enum {UNKNOWN_DEVICE_TYPE, FRONTEND, DEMUX, VIDEO_DECODE, AUDIO_DECODE, VIDEO_MIXER, AUDIO_MIXER, DISPLAY, INFRASTRUCTURE} STRM_Device_Type_t;
typedef enum {UNKNOWN_PORT_TYPE, SOURCE, SINK, INTERFACE, END_OF_PORT_LIST} STRM_Port_Type_t;
typedef enum {UNKNOWN_PROPERTY_TYPE, INTEGER, STRING, CSV, RANGE, ENUMERATE, RAW_DATA, END_OF_PROP_LIST} STRM_Property_Type_t;
typedef enum {STRM_NO_ERROR,
              STRM_ERROR_NAME_ALREADY_REGISTERED,
              STRM_ERROR_NAME_NOT_VALID,
              STRM_ERROR_ID_NOT_VALID,
              STRM_ERROR_RESOURCE_NOT_VALID,
              STRM_ERROR_DEV_NOT_VALID,
              STRM_ERROR_DEV_NOT_FOUND,
              STRM_ERROR_DEV_NOT_EMPTY,
              STRM_ERROR_PORT_NOT_VALID,
              STRM_ERROR_PORT_NOT_FOUND,
              STRM_ERROR_PROP_NOT_VALID,
              STRM_ERROR_PROP_NOT_FOUND,
              STRM_ERROR_ATTACHED_TO_RESOURCES,
              STRM_ERROR_MEMORY_MISSING,
              STRM_ERROR_CONNECTION_ALREADY_REGISTERED,
              STRM_ERROR_CONNECTION_NOT_FOUND,
              STRM_ERROR_TYPE_NOT_VALID} STRM_Errors_t;
extern STRM_String_t STRM_ERROR_names[];

typedef enum {STRM_I2C, STRM_UART, STRM_SPI, STRM_VID, STRM_AUD } STRM_STAPI_DRIVER; /*  TODO complete this list */

/* Exported Variables ------------------------------------------------------- */

/* Exported Macros ---------------------------------------------------------- */
#define PORT_EMPTY_LIST (struct STRM_Description_Port_t []) {{"",END_OF_PORT_LIST,NULL}}
#define PORT_LIST(args,...) (struct STRM_Description_Port_t[]) {args,##__VA_ARGS__,{"",END_OF_PORT_LIST,NULL}}
#define PORT(name,type,prop_desc) {name,type,prop_desc}

#define PROP_EMPTY_LIST (struct STRM_Description_Property_t[]) {{"",END_OF_PROP_LIST,0,NULL}}
#define PROP_LIST(args,...) (struct STRM_Description_Property_t[]) {args,##__VA_ARGS__,{"",END_OF_PROP_LIST,0,NULL}}
#define PROP(name,type,value) {name,type,sizeof(value),value}


/*-----------------------------------------------------------------------------
 *  Resource manager API
 *-----------------------------------------------------------------------------*/

void STRM_Init(void); /* Initialize STRM - Called when the kernel object is loaded */
void STRM_Term(void); /* Terminate STRM - Called when the kernel object is removed */
ST_ErrorCode_t STRM_ApplicationInit(void); /* Open STRM file descriptor - Called when a new process is created */
ST_ErrorCode_t STRM_ApplicationTerm(void); /* Close STRM file descriptor - Called when a process terminates*/

/* Fill the database - add or remove a device */
/* TODO : the device type must be treated as a property (for later searches...) */
ST_ErrorCode_t STRM_Add_Device(const STRM_String_t name, const STRM_Device_Type_t type, STRM_Id_t *dev_id_p);
ST_ErrorCode_t STRM_Delete_Device(const STRM_Id_t dev_id_p);

ST_ErrorCode_t STRM_Add_Port(const STRM_Id_t dev_id, const STRM_String_t name, const STRM_Port_Type_t type, STRM_Id_t *port_id_p);
ST_ErrorCode_t STRM_Delete_Port(const STRM_Id_t port_id);

ST_ErrorCode_t STRM_Add_Property(const STRM_Id_t res_id, const STRM_String_t name, const STRM_Property_Type_t type, void* const data, const size_t size, STRM_Id_t * const prop_id_p);
ST_ErrorCode_t STRM_Delete_Property(const STRM_Id_t prop_id);

/* Search info in the database */
ST_ErrorCode_t STRM_Get_DeviceId_FromName(const STRM_String_t name, STRM_Id_t *dev_id_p);
ST_ErrorCode_t STRM_Get_PropertyId(const STRM_Id_t dev_id, const STRM_String_t prop_name, STRM_Id_t *prop_id_p);
ST_ErrorCode_t STRM_Get_PortId(const STRM_Id_t res_id, const STRM_String_t port_name, STRM_Id_t *port_id_p);
ST_ErrorCode_t STRM_Read_Property(const STRM_Id_t prop_id, void* const data, size_t size);
ST_ErrorCode_t STRM_Write_Property(const STRM_Id_t prop_id, void* const data, size_t size);
ST_ErrorCode_t STRM_Read_Property_nolock(const STRM_Id_t prop_id, void* const data, size_t size);
ST_ErrorCode_t STRM_Write_Property_nolock(const STRM_Id_t prop_id, void* const data, size_t size);
U32 STRM_Get_DeviceCount(void);

/* Ports connections */
ST_ErrorCode_t STRM_Connect(const STRM_Id_t source, const STRM_Id_t sink);
ST_ErrorCode_t STRM_Detach(const STRM_Id_t source, const STRM_Id_t sink);
ST_ErrorCode_t STRM_Get_NbConnectedSinks(const STRM_Id_t source, size_t * const size);
ST_ErrorCode_t STRM_Get_NbConnectedSources(const STRM_Id_t sink, size_t * const size);
ST_ErrorCode_t STRM_Get_ConnectedSinks(const STRM_Id_t source, STRM_Id_t * const table, const U32 size);
ST_ErrorCode_t STRM_Get_ConnectedSources(const STRM_Id_t sink, STRM_Id_t * const table, const U32 size);

/* Display resources */
void STRM_Display_ResourceList(void);
void STRM_Display_ConnectionList(void);

/* Resource Manager locking */
void STRM_Lock(void);
void STRM_Release(void);

/*-----------------------------------------------------------------------------
 *  API for descriptions
 *-----------------------------------------------------------------------------*/
struct STRM_Description_Device_t
 {
  STRM_String_t name;
  STRM_Device_Type_t type;
  struct STRM_Description_Property_t *prop_desc;
  struct STRM_Description_Port_t *port_desc;
 };

struct STRM_Description_Property_t
 {
  STRM_String_t name;
  STRM_Property_Type_t type;
  size_t size;
  void *data;
 };

struct STRM_Description_Port_t
 {
  STRM_String_t name;
  STRM_Port_Type_t type;
  struct STRM_Description_Property_t *prop_desc;
 };

ST_ErrorCode_t STRM_Add_PropDescription(const STRM_Id_t dev_id, const struct STRM_Description_Property_t desc, STRM_Id_t *prop_id_p);
ST_ErrorCode_t STRM_Add_PortDescription(const STRM_Id_t dev_id, const struct STRM_Description_Port_t desc, STRM_Id_t *port_id_p);
ST_ErrorCode_t STRM_Add_DeviceDescription(const struct STRM_Description_Device_t desc, STRM_Id_t *dev_id_p);

/*-----------------------------------------------------------------------------
 *  functions added for test purposes
 *-----------------------------------------------------------------------------*/
ST_ErrorCode_t STRM_Test(void);


/* C++ support */
#ifdef __cplusplus
}
#endif

#endif /* __STRM_H */

/* End of strm.h */
