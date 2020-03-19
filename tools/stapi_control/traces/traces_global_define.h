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
/*!
 * FIXME: The contents of this file should migrate into sttbx.h
 */
#ifndef TRACES_GLOBAL_DEFINE_H
#define TRACES_GLOBAL_DEFINE_H

#include "sttrace.h"

#define STTRACE_CID_OFFSET      0x20


typedef enum {
    COMPO_CID           = (0*STTRACE_CID_OFFSET),
    ST2FX_CID           = (1*STTRACE_CID_OFFSET),
    ST3FX_CID           = (2*STTRACE_CID_OFFSET),
    STATAPI_CID         = (3*STTRACE_CID_OFFSET),
    STAUDLX_CID         = (4*STTRACE_CID_OFFSET),
    STAVMEM_CID         = (5*STTRACE_CID_OFFSET),
    STBLAST_CID         = (6*STTRACE_CID_OFFSET),
    STBLIT_CID          = (7*STTRACE_CID_OFFSET),
    STBOOT_CID          = (8*STTRACE_CID_OFFSET),
    STCC_CID            = (9*STTRACE_CID_OFFSET),
    STCLKRV_CID         = (10*STTRACE_CID_OFFSET),
    STCLOCK_CID         = (11*STTRACE_CID_OFFSET),
    STCOMMON_CID        = (12*STTRACE_CID_OFFSET),
    STDENC_CID          = (13*STTRACE_CID_OFFSET),
    STDISP_CID          = (14*STTRACE_CID_OFFSET),
    STEVT_CID           = (15*STTRACE_CID_OFFSET),
    STFDMA_CID          = (16*STTRACE_CID_OFFSET),
    STFLASH_CID         = (17*STTRACE_CID_OFFSET),
    STFRONTEND_CID      = (18*STTRACE_CID_OFFSET),
    STGFB_CID           = (19*STTRACE_CID_OFFSET),
    STHDMI_CID          = (20*STTRACE_CID_OFFSET),
    STI2C_CID           = (21*STTRACE_CID_OFFSET),
    STINJECT_CID        = (22*STTRACE_CID_OFFSET),
    STIPRC_CID          = (23*STTRACE_CID_OFFSET),
    STKEYSCN_CID        = (24*STTRACE_CID_OFFSET),
    STLAYER_CID         = (25*STTRACE_CID_OFFSET),
    STMERGE_CID         = (26*STTRACE_CID_OFFSET),
    STNET_CID           = (27*STTRACE_CID_OFFSET),
    STOS_CID            = (28*STTRACE_CID_OFFSET),
    STPCCRD_CID         = (29*STTRACE_CID_OFFSET),
    STPCPD_CID          = (30*STTRACE_CID_OFFSET),
    STPIO_CID           = (31*STTRACE_CID_OFFSET),
    STPOD_CID           = (32*STTRACE_CID_OFFSET),
    STPOWER_CID         = (33*STTRACE_CID_OFFSET),
    STPTI4_CID          = (34*STTRACE_CID_OFFSET),
    STPTI5_CID          = (35*STTRACE_CID_OFFSET),
    STPWM_CID           = (36*STTRACE_CID_OFFSET),
    STRESET_CID         = (37*STTRACE_CID_OFFSET),
    STSCART_CID         = (38*STTRACE_CID_OFFSET),
    STSMART_CID         = (39*STTRACE_CID_OFFSET),
    STSPI_CID           = (40*STTRACE_CID_OFFSET),
    STSUBT_CID          = (41*STTRACE_CID_OFFSET),
    STSYS_CID           = (42*STTRACE_CID_OFFSET),
    STTBX_CID           = (43*STTRACE_CID_OFFSET),
    STTTX_CID           = (44*STTRACE_CID_OFFSET),
    STUART_CID          = (45*STTRACE_CID_OFFSET),
    STVBI_CID           = (46*STTRACE_CID_OFFSET),
    STVID_CID           = (47*STTRACE_CID_OFFSET),
    STVIN_CID           = (48*STTRACE_CID_OFFSET),
    STVMIX_CID          = (49*STTRACE_CID_OFFSET),
    STVOUT_CID          = (50*STTRACE_CID_OFFSET),
    STVTG_CID           = (51*STTRACE_CID_OFFSET),
    STBUFFER_CID        = (52*STTRACE_CID_OFFSET),
    STXCPU_CID          = (53*STTRACE_CID_OFFSET),
    STAPP_CID           = (54*STTRACE_CID_OFFSET),
    STTUNER_CID         = (55*STTRACE_CID_OFFSET),
    STTKDMA_CID         = (56*STTRACE_CID_OFFSET),
    STFSK_CID           = (57*STTRACE_CID_OFFSET),
    STEVT_RELAY_CID     = (58*STTRACE_CID_OFFSET),
    STRM_CID            = (59*STTRACE_CID_OFFSET),
    STMISR_CID	        = (60*STTRACE_CID_OFFSET),
    STTRACE_LAST_CID    = (61*STTRACE_CID_OFFSET)
} STTRACE_DriverComponentID;

#define STTRACE_ARRAY_LAST_INDEX (61*STTRACE_CID_OFFSET)

typedef enum {
    FATAL=0,
    ERROR,
    WARNING,
    INFO,
    API_IN,
    API_OUT,
    USER,
    INFO_WITHOUT_HEADER,
    STTRACE_LAST_TYPE
} STTRACE_Type;

/*!
 *
 * \warning give explicit values for each level (and alias), and limit range to
 * 0:3 => can fit into 2 bits.
 */
typedef enum {
    LEVEL0 = 0,
    LEVEL1 = 1,
    LEVEL2 = 2,
    LEVEL3 = 3,
	STTRACE_LAST_LEVEL = 4
} STTRACE_Level;

/* default trace mask at startup */

#define DEFAULT_TRACE_MASK ( (0xf << (4*FATAL)) + (0xf << (4*ERROR)) )

/*! Used to remove path from the filename, in order to reduce number of
 * characters printed. Useful for the moment, as there are many ERROR traces
 * spuriously reported in STAPI, but in the future, when only real errors will
 * be printed, the full path will be displayed again.
 */
#define SHORTFILENAME(FileName)             ((strrchr((FileName),'/') != NULL) ? (strrchr((FileName),'/')+1) : (FileName))
#define LONGFILENAME(FileName)				FileName

/* PRINTF macro (defining our own because we need to avoid dependencies in early
 * traces) */
#if defined(ST_OSLINUX) && defined(__KERNEL__)
#   define PRINTF(x, args...) printk(x, ##args)
#else
#   include <stdio.h>
#   define PRINTF(x, args...) printf(x, ##args)
#endif

#ifndef STTRACE_TURN_OFF_MECHANISM  /* skip implementation if mechanism off */

#define GET_CID_NAME(cid) #cid

#define STTBX_TRACETXT_SIGNATURE \
    const STTRACE_DriverComponentID component_id  /*! ID of the component that generates the trace*/\
/* note: the "weird" indentation of the comma (, "") is so that Doxygen can extract the documentation*/\
/* for the parameters, without extra \param tags. Don't bother about it.*/\
,   const STTRACE_Type type               /*! type of the trace (first level of filtering)*/\
,   const STTRACE_Level level             /*! second level of filtering*/\
,   const char * format                 /*! printf()-like format string*/\
,   ...                                 /*! variable number of arguments to printf()-like function*/

typedef void (* STTBX_TraceTxt_functionpointer_t) (STTBX_TRACETXT_SIGNATURE);
extern STTBX_TraceTxt_functionpointer_t STTBX_TraceTxt_fptr;

/* #define STTRACE_USE_KPTRACE */
#if defined(STTRACE_USE_KPTRACE) && defined(ST_OSLINUX)
    #include <asm-sh/kptrace.h>
    #if defined(MODULE)
        /* #warning "==========> including kptrace.h" */
        #define STTBX_TRACETXT_WRAPPER(componentID, type, level, format, args...)\
        do \
        {\
           kpprintf(format,##args);\
        } while(0)
    #else
        #define STTBX_TRACETXT_WRAPPER(componentID, type, level, format, args...)\
        do \
        {\
           FILE *fp;\
           if ((fp=fopen("/sys/devices/system/kptrace/userspace/new_record","a")) != NULL)\
           {\
             fprintf(fp,format,##args);\
             fclose(fp);\
           }\
        } while(0)
    #endif
#else
#define STTBX_TRACETXT_WRAPPER(componentID, type, level, format, args...)\
    do {\
        if(STTBX_TraceTxt_fptr != 0) {\
            STTBX_TraceTxt_fptr(componentID, type, level, format, ##args);\
        }\
        else {\
            PRINTF("WARNING: STTBX_TraceTxt_fptr == 0!\n"); /* this case should never happen */\
            PRINTF(format, ##args);\
        }\
    } while(0)
#endif


/*!
 * Macro used for STAPI system traces
 *
 * \note There is a lot of code duplication in order to minimize run-time
 * performance impact. Most of the code will be optimized out by the compiler
 * (branching on compile-time constants). -O2 is probably needed.
 *
 * \note The STTBX_TRACE name was already taken :(
 */
#if defined(ST_OSLINUX)
    #if defined(MODULE)
        #define TRACE_TAG "K:"
    #else
        #define TRACE_TAG "U:"
    #endif
#else
        #define TRACE_TAG ""
#endif

#   define STTRACE_ON(componentID, type, level, format, args...)\
    do {\
		/* these if()s will be optimized out by the compiler */\
        if(type == FATAL) {\
            STTBX_TRACETXT_WRAPPER(componentID, type, level, "%s%s()::FATAL: \""\
                    format "\" on line %d in %s\r\n",\
                    TRACE_TAG,__FUNCTION__, ##args, __LINE__, LONGFILENAME(__FILE__));\
        } else if(type == ERROR) {\
            STTBX_TRACETXT_WRAPPER(componentID, type, level, "%s%s()::ERROR: \""\
                    format "\" on line %d in %s\r\n",\
                    TRACE_TAG,__FUNCTION__, ##args, __LINE__, LONGFILENAME(__FILE__));\
        }\
        else if(type == API_IN) {\
            if(format[0] == '\0') {\
                STTBX_TRACETXT_WRAPPER(componentID, type, level, "%s%s(): enter\r\n",\
                    TRACE_TAG,__FUNCTION__);\
            }\
            else { /* add ":=" if non-empty format */\
                STTBX_TRACETXT_WRAPPER(componentID, type, level, "%s%s(): enter: "\
                    format "\r\n", TRACE_TAG,__FUNCTION__, ##args);\
            }\
        } else if(type == API_OUT) {\
            if(format[0] == '\0') {\
                STTBX_TRACETXT_WRAPPER(componentID, type, level, "%s%s(): exit\r\n",\
                    TRACE_TAG,__FUNCTION__);\
            }\
            else { /* add ":=" if non-empty format */\
                STTBX_TRACETXT_WRAPPER(componentID, type, level, "%s%s(): exit: "\
                    format "\r\n", TRACE_TAG,__FUNCTION__, ##args);\
            }\
        }\
        else if(type == WARNING) {\
            STTBX_TRACETXT_WRAPPER(componentID, type, level, "%s%s()::WARNING: "\
                    format "\r\n", TRACE_TAG,__FUNCTION__, ##args);\
        }\
        else if(type == INFO) {\
            STTBX_TRACETXT_WRAPPER(componentID, type, level, "%s%s()::INFO: "\
                    format "\r\n", TRACE_TAG,__FUNCTION__, ##args);\
        }\
        else if(type == USER) {\
            STTBX_TRACETXT_WRAPPER(componentID, type, level, "%s()::USER: "\
                    format "\r\n", __FUNCTION__, ##args);\
				}\
   				else if(type == INFO_WITHOUT_HEADER) {\
						STTBX_TRACETXT_WRAPPER(componentID, type, level,\
						format "\r\n",##args);\
			}\
       } while(0)

#   define STTRACE_OFF(componentID, type, level, format, args...)
/*  For the next delivery a mechanism similar to the following should be implemented */
#if 0
#ifdef DEBUG
#define DEBUGF(arg)     g_pIDebug->IDebugPrintf arg
#else
#define DEBUGF(arg)     __idebugprintf arg
static inline int __attribute__ ((format (printf, 1, 2))) __idebugprintf (const char *format, ...) {
      return 0;
}
#endif
#endif

#   define STTRACE_PRINT(componentID, type, level, format, args...)\
        TRACE_##componentID##_##type##_ACTIVATED(componentID, type, level, format, ##args)

#else /* STTRACE_TURN_OFF_MECHANISM defined */
    /* STTRACE_PRINT : don't do anything */
#   define STTRACE_PRINT(componentID, type, level, format, args...)
#endif /* #ifndef STTRACE_TURN_OFF_MECHANISM */

/*! defined for compatibility reasons */
#   define SET_TRACE    STTRACE_PRINT



/*! STATIC_ASSERT: macro for performing static assertion checks. See drivers'
 * stxxx_traces.h for an usage example. */
#ifdef __cplusplus
    #define STATIC_ASSERT(expr, msg) \
        extern const char STATIC_ASSERTION__##msg[(expr)?1:-1]
#else

#ifdef __GNUC__
#define STATIC_ASSERT_HELPER(expr, msg) \
    (!!sizeof \
        (struct { unsigned int STATIC_ASSERTION__##msg: (expr) ? 1 : -1; }))
#define STATIC_ASSERT(expr, msg) \
    extern int (*assert_function__(void)) [STATIC_ASSERT_HELPER(expr, msg)]
#else
    #define STATIC_ASSERT(expr, msg)   \
    extern char STATIC_ASSERTION__##msg[1]; \
    extern char STATIC_ASSERTION__##msg[(expr)?1:2]
#endif /* #ifdef __GNUC__ */

#endif /* #ifdef __cplusplus */
/* ----------- done STATIC_ASSERT definitions ------------ */


#endif /* #ifndef TRACES_GLOBAL_DEFINE_H */

