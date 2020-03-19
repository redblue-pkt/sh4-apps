/*****************************************************************************/
/*                                                                           */
/* File Name :stpower.h                                                      */
/*                                                                           */
/* Description :  API Defines for STPOWER                                    */
/*                                                                           */
/*                                                                           */
/* Component   :  STPOWER                                                    */
/* Module      :  API Header                                                 */
/*                                                                           */
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
#ifndef __STPOWER_H
#define __STPOWER_H

/* Includes ----------------------------------------- */
#include "stddefs.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef U32 STPOWER_Handle_t ;

#define MAX_SIZE_OF_DEVICE_NAME 31
typedef char STPOWER_DeviceName_t[MAX_SIZE_OF_DEVICE_NAME+1];

#define POWER_INVALID_HANDLE (STPOWER_Handle_t) 0xFFFFFFFF

/*Index of Power driver, This ID shoule be unique across all STAPI driver */
#define STPOWER_DRIVER_ID       9

/* Base of STPOWER Driver*/
#define STPOWER_DRIVER_BASE     (STPOWER_DRIVER_ID << 16)

/* Error Base of Power Driver */
#define STPOWER_ERROR_BASE     STPOWER_DRIVER_BASE

/*Maximum Entries expected per Register Profile call*/
#define MAX_ENTRIES_IN_LIST 200

/*Valid Time in Hour Minutes and Seconds */
#define VALID_HOUR 24
#define VALID_MIN 60
#define VALID_SEC 60

/*Error Type Defined for Power driver*/
enum
{
    /*This error will be reported in case Device is already present*/
    STPOWER_ERROR_DEVICE_PRESENT=STPOWER_ERROR_BASE,

    /*This error will be reported in case Device is notpresent*/
    STPOWER_ERROR_DEVICE_NOT_PRESENT,

    /*This error will be reported in case application want to set profile , which was not registered*/
    STPOWER_ERROR_PROFILE_NOT_SET,

    /*This error will be reported in case some operation requested on uninitailzed driver*/
    STPOWER_ERROR_DRIVER_NOT_INITIALIZED
};

/*Define Type of Device i.e. STAPI device or Clock*/
typedef enum STPOWER_DeviceType_e
{
    /*Device to use in of STAPI device */
    STPOWER_DEVICE,

    /*Device to use in of NATIVE LINUX device */
    STPOWER_DEVICE_NATIVE_LINUX

} STPOWER_DeviceType_t;


/*Define Set/Get Params for stpower driver */
typedef enum STPOWER_Parameter_e
{
    /*streset callback function params*/
    STPOWER_RESET_CALLBACK_PARAMS
} STPOWER_Parameter_t;


/*Define State of Device*/
typedef enum STPOWER_State_e
{
    /*D0 Used for Active Running mode*/
    STPOWER_DEVICE_STATE_D0=1<<1,

    /*D0 Used for Active Standby */
    STPOWER_DEVICE_STATE_D1=1<<2,

    /*D0 Used for Passive Standby*/
    STPOWER_DEVICE_STATE_D2=1<<3

} STPOWER_State_t;


/* This Defines Power Function for STAPI devices .. This will be a callback function
requesting device to go in Selected State and giving DeviceData as Parameter
*/
typedef ST_ErrorCode_t (*STPOWER_Func_t) (STPOWER_State_t State ,const void * DeviceData_p);




/*This defines Init Parameter of STPOWER driver*/
typedef struct STPOWER_InitParams_s
{
    /*CPU partition . This will be used for all STPOWER Allocations*/
    ST_Partition_t * CPUPartition;
} STPOWER_InitParams_t;

/*This defines open parameters for STPOWER driver*/
typedef struct STPOWER_OpenParams_s
{
    /* This is not Used */
    U32 Dummy; /*  Added Dummy for GCC_CHECK=1*/
} STPOWER_OpenParams_t;

/*This defines Term parameters for STPOWER driver*/
typedef struct STPOWER_TermParams_s
{
    /*Is Terminate is requested on opened driver*/
    BOOL ForceTerminate;
} STPOWER_TermParams_t;

typedef enum STPOWER_CPUState_e
{
    STPOWER_CPU_STATE_NORMAL,
    STPOWER_CPU_STATE_SLEEP,
    STPOWER_CPU_STATE_STANDBY,
    STPOWER_CPU_STATE_OFF,
}
STPOWER_CPUState_t;

typedef enum STPOWER_WakeUpReason_e
{
    STPOWER_WAKEUP_UNKNOWN=1<<0,
    STPOWER_WAKEUP_NMI=1<<1,
    STPOWER_WAKEUP_IR=1<<2,
    STPOWER_WAKEUP_FRONTPANEL=1<<3,
    STPOWER_WAKEUP_ETHERNET=1<<4,
    STPOWER_WAKEUP_TIMER=1<<5,
    STPOWER_WAKEUP_HDMI=1<<6,
    STPOWER_WAKEUP_MSG_REMOTE_CPU=1<<7,
    STPOWER_WAKEUP_GPIO=1<<8,
    STPOWER_WAKEUP_LAST=1<<9
} STPOWER_WakeUpReason_t;



typedef union STPOWER_Wakeup_Params_s
{
    struct
    {
        STPOWER_DeviceName_t PathOfDevice;  /* For Linux This would be pat of device and For OS21 this is not required*/
    } Ethernet;
    struct
    {
        U32 TimeInSec; /* Time in Seconds, after which wakeup is required Same for OS21 and Linux */
    } Timer;
    struct
    {
        STPOWER_DeviceName_t PathOfPIODevice; /* For Linux, this would be path of PIO device, as we are using Native Linux*/
        U32   PIOPortNumber;  /* For OS21, this is port number to which Front-Panel is connetced */
    }PIO;
} STPOWER_Wakeup_Params_t;

typedef ST_ErrorCode_t (*STPOWER_UserCallbackFunc_t) (STPOWER_WakeUpReason_t wakeupreason, const void * DeviceData_p);

typedef struct STPOWER_UserFunc_s
{
    STPOWER_UserCallbackFunc_t EntryFn;
    STPOWER_UserCallbackFunc_t ExitFn;
}STPOWER_UserFunc_t;


/***************   WARNING          ***************************
***************    WARNING          ***************************
***************    WARNING          ***************************
  THIS FUNCTION IS DUMMY FOR M4.5 Requriment of 7141,
 THIS WOULD BE REMOVED IN NEXT RELEASE */
/* Below check is only added 7108 dual CPU compilation */
#if defined(ST_7141) || defined(ST_7108)
typedef enum STPOWER_Clock_e
{

    STPOWER_CLKA_PLL,
    STPOWER_CLKA_IC_STNOC,
    STPOWER_CLKA_FDMA0,
    STPOWER_CLKA_FDMA1,
    STPOWER_CLKA_FDMA2,
    STPOWER_CLKA_SH4_ICK, /*5*/
    STPOWER_CLKA_SH4_ICK_498,/*6*/
    STPOWER_CLKA_LX_DMU_CPU,
    STPOWER_CLKA_LX_AUD_CPU,
    STPOWER_CLKA_IC_BDISP_200,
    STPOWER_CLKA_IC_DISP_200,
    STPOWER_CLKA_DISP_PIPE_200,
    STPOWER_CLKA_BLIT_PROC,
    STPOWER_CLKA_ETH_PHY,
    STPOWER_CLKA_PCI,
    STPOWER_CLKA_EMI_MASTER,
    STPOWER_CLKA_IC_COMPO_200,

    STPOWER_CLKB_FS0_CH1,
    STPOWER_CLKB_FS0_CH2,
    STPOWER_CLKB_FS0_CH3,

    STPOWER_CLKB_FS1_CH1,
    STPOWER_CLKB_FS1_CH2,
    STPOWER_CLKB_FS1_CH3,
    STPOWER_CLKB_FS1_CH4,


    STPOWER_CLKB_FS0, /*17*/
    STPOWER_CLKB_FS1,
    STPOWER_CLKB_TMDS_HDMI,
    STPOWER_CLKB_PIX_HD,
    STPOWER_CLKB_DISP_HD,
    STPOWER_CLKB_656,
    STPOWER_CLKB_GDP3,
    STPOWER_CLKB_DISP_ID,
    STPOWER_CLKB_PIX_SD,

    STPOWER_CLKB_PP,
    STPOWER_CLKB_150,
    STPOWER_CLKB_LPC,
    STPOWER_CLKB_DSS,


    STPOWER_CLKC_FS0_CH1,
    STPOWER_CLKC_FS0_CH2,
    STPOWER_CLKC_FS0_CH3,
    STPOWER_CLKC_FS0_CH4,

    STPOWER_CLKE_MSCC,

    /* Clockgen D */
    /* No clock should be set via API for gen D*/

    /* USB PLL*/
    STPOWER_USB_PLL,

    /* Clockgen E = 498 System */
    /*Front End driver is setting QAM clocks when going to low power
    in its callback function */
    /*POD driver is setting MSCC and CCSC clock by system config*/
    /* ONLY remain DOCSIS ,, Recommend to set its clock in Driver Only*/
    STPOWER_CLOCK_LAST


}STPOWER_Clock_t;
ST_ErrorCode_t STPOWER_HandleClock(STPOWER_Handle_t Handle, STPOWER_Clock_t Clock, BOOL Enable);
#endif

/***************   WARNING          ***************************
***************    WARNING          ***************************
***************    WARNING          ***************************
  THIS FUNCTION IS DUMMY FOR M4.5 Requriment of 7141,
 THIS WOULD BE REMOVED IN NEXT RELEASE */


/*This defines Profile Entry for the POWER driver*/
typedef struct STPOWER_ProfileEntry_s
{
    /*Name of Device*/
    STPOWER_DeviceName_t DeviceName;

    /*Device of Device - Is this a clock or Device*/
    STPOWER_DeviceType_t DeviceType;

    /* Requested state of Device/Clock*/
    STPOWER_State_t DeviceState;
} STPOWER_ProfileEntry_t;

/*Error code of STPOWER which */
typedef struct STPOWER_ErrorCode_s {
    /*Error Code */
  ST_ErrorCode_t ErrorCode;

  /*Name of error causing device*/
  ST_DeviceName_t   DeviceName;
}STPOWER_ErrorCode_t;

typedef struct STPOWER_CurrentTime_s {
   int Hour;
   int Minute;
   int Second;
}STPOWER_CurrentTime_t;
/*Functions */

ST_ErrorCode_t STPOWER_Init(const ST_DeviceName_t DeviceName,
                            STPOWER_InitParams_t *InitParams_p);


ST_ErrorCode_t STPOWER_Open(const ST_DeviceName_t DeviceName,
                            const STPOWER_OpenParams_t *Params,
                            STPOWER_Handle_t *Handle_p);


ST_ErrorCode_t STPOWER_Close(const STPOWER_Handle_t Handle);


ST_ErrorCode_t STPOWER_Term(const ST_DeviceName_t DeviceName,
                            const STPOWER_TermParams_t *TermParams_p);

ST_Revision_t STPOWER_GetRevision(void);


ST_ErrorCode_t STPOWER_RegisterProfile(const STPOWER_Handle_t Handle,
                                    STPOWER_ProfileEntry_t *Profile_p,
                                    U32 NumEntries, U32 *ProfileID_p);

ST_ErrorCode_t STPOWER_UnRegisterProfile(const STPOWER_Handle_t Handle_p,
                                                U32 ProfileID_p);

ST_ErrorCode_t STPOWER_SetProfile(const STPOWER_Handle_t Handle,
                                    U32 ProfileID);

ST_ErrorCode_t STPOWER_GetDeviceErrorInProfile(const STPOWER_Handle_t Handle,
                                              U32  ProfileID,
                                              STPOWER_ErrorCode_t *DeviceError);

ST_ErrorCode_t STPOWER_RegisterPowerFunction(const ST_DeviceName_t DeviceName,
                                STPOWER_Func_t Func, U32 SupportedState, void *
                                DeviceData_p);


ST_ErrorCode_t STPOWER_UnRegisterPowerFunction(const ST_DeviceName_t DeviceName);

ST_ErrorCode_t STPOWER_SetCPUState(const STPOWER_Handle_t Handle, STPOWER_CPUState_t CPUState, STPOWER_WakeUpReason_t *WakeUpReason_p);

ST_ErrorCode_t STPOWER_SetWakeUpDevice(STPOWER_Handle_t Handle, STPOWER_WakeUpReason_t Reason,
                                	   STPOWER_Wakeup_Params_t * WakeUpParams_p);

ST_ErrorCode_t STPOWER_UnSetWakeUpDevice(STPOWER_Handle_t Handle, STPOWER_WakeUpReason_t Reason);

ST_ErrorCode_t STPOWER_GetWakeUpDevices(STPOWER_Handle_t Handle, U32 *WakeUPDevices_p);


ST_ErrorCode_t STPOWER_SetCPUFrequency(STPOWER_Handle_t Handle, ST_CPU_t  CPUId, U32 Frequency);

ST_ErrorCode_t STPOWER_SetUserFunc(STPOWER_Handle_t Handle,STPOWER_UserFunc_t UserFunc, const void * Userdata );

ST_ErrorCode_t STPOWER_GetParameter(STPOWER_Handle_t Handle, STPOWER_Parameter_t Parameter, U32 *Value);

ST_ErrorCode_t STPOWER_GetCPUWakeupReason(STPOWER_Handle_t Handle, ST_CPU_t  CPUId, STPOWER_WakeUpReason_t *WakeUpReason_p);

ST_ErrorCode_t STPOWER_SetCurrentTime(STPOWER_Handle_t Handle,STPOWER_CurrentTime_t Time);


#ifdef STPOWER_SUPPORTED
#define STPOWER_REGISTERPOWERFUNCTION(Name,Func,State,Data) STPOWER_RegisterPowerFunction(Name,Func,State,Data)
#define STPOWER_UNREGISTERPOWERFUNCTION(Name)   STPOWER_UnRegisterPowerFunction(Name)


#else
#define STPOWER_REGISTERPOWERFUNCTION(Name,Func,State,Data) ST_NO_ERROR
#define STPOWER_UNREGISTERPOWERFUNCTION(Name)  ST_NO_ERROR


#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef __STPOWER_H */





