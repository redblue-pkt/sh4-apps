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
 * @file     testtool.h
 * @brief    This is the testtool header file.
 * @author   STMicroelectronics
 */

#ifndef _DEVELOP_H_
#define _DEVELOP_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
/* -------- */
#include "stddefs.h"
#include "clilib.h"

/* Key definition */
/* -------------- */
typedef enum e_key_code
{
 KEY_ESC,
 KEY_BACKSPACE,
 KEY_RETURN,
 KEY_END_OF_LINE,
 KEY_BEGIN_OF_LINE,
 KEY_ARROW_UP,
 KEY_ARROW_DOWN,
 KEY_ARROW_LEFT,
 KEY_ARROW_RIGHT,
 KEY_INSERT,
 KEY_DELETE,
 KEY_TAB,
 KEY_CLEAR_LINE,
 KEY_CLEAR_EOL,
 KEY_CTRL_LEFT,
 KEY_CTRL_RIGHT,
 KEY_NUMBERS
} e_key_code;

/* Action definition */
/* ----------------- */
typedef enum e_action_code
{
 ACTION_BACKSPACE,
 ACTION_RETURN,
 ACTION_MOVE_EOL,
 ACTION_MOVE_BOL,
 ACTION_HISTORY_UP,
 ACTION_HISTORY_DOWN,
 ACTION_MOVE_LEFT,
 ACTION_MOVE_RIGHT,
 ACTION_TOGGLE_INSERT,
 ACTION_DELETE,
 ACTION_COMPLETE,
 ACTION_CLEAR_LINE,
 ACTION_CLEAR_EOL,
 ACTION_ADD_CHAR,
 ACTION_MOVE_BOT,
 ACTION_MOVE_EOT,
 ACTION_NOACTION
} e_action_code;

/* Key bind definition */
/* ------------------- */
typedef struct s_key_bind
{
 e_key_code     key_code;
 char          *key_string;
 e_action_code  action_code;
} t_key_bind;

/* Legacy stuff with stapi drivers */
/* ------------------------------- */
#define STTST_MAX_TOK_LEN          MAX_TOK_LEN  /* Nb max of bytes for one token               */
#define STTST_INTERACTIVE_MODE     0            /* Press a key at start and end (default mode) */
#define STTST_BATCH_MODE           1            /* Natch mode                                  */
#define STTST_NO_ABBREVIATION_MODE 2            /* No symbol name abbreviation allowed         */
typedef struct parse STTST_Parse_t;
typedef S16    STTST_RunningMode_t;             /* Nit 1=abbreviation; bit 0=interactive       */
typedef struct
{
 ST_Partition_t *CPUPartition_p;                /* Partition for internal memory allocation    */
 S16  NbMaxOfSymbols;                           /* Size of the internal symbols table          */
 char InputFileName[STTST_MAX_TOK_LEN];         /* Filename for input commands (not mandatory) */
} STTST_InitParams_t;

/* History definition */
/* ------------------ */
#define NLINES 20
typedef struct
{
 U32 write_pointer;
 U32 read_pointer;
 U8  command_history[MAX_LINE_LEN][NLINES];
} history_t;

/* Prototypes */
/* ---------- */
void           print                           (const char *format,...);
void           report                          (ST_ErrorCode_t Error,const char *format,...);
S32            scan                            (const char *format,void *Variable);
char           io_getchar                      (char *filter,BOOL case_sensitive);
S32            pollkey                         (void);
void           tag_current_line                (parse_t * pars_p,char *message_p);
BOOL           assign_integer                  (char *token_p,S32 value,BOOL constant);
BOOL           assign_float                    (char *token_p,DOUBLE value,BOOL constant);
BOOL           assign_string                   (char *token_p,char *value,BOOL constant);
BOOL           register_command                (char *token_p,BOOL (*action) (parse_t *,char *),char *help_p);
BOOL           cget_string                     (parse_t *pars_p,char *default_p,char *result_p,S16 max_len);
BOOL           cget_integer                    (parse_t *pars_p,S32 def_int,S32 *result_p);
BOOL           cget_float                      (parse_t *pars_p,DOUBLE def_flt,DOUBLE *result_p);
BOOL           cget_item                       (parse_t *pars_p,char *default_p,char *result_p, S16 max_len);
BOOL           cget_token_count                (parse_t *pars_p,S16 *result_p);
BOOL           evaluate_integer                (char *token_p,S32 *value_p,S16 default_base);
BOOL           evaluate_float                  (char *token_p,DOUBLE *value_p);
BOOL           evaluate_comparison             (char *token_p,BOOL *result_p,S16 default_base);
BOOL           evaluate_string                 (char *token_p,char *string_p,S16 max_len);
ST_ErrorCode_t TesttoolInit                    (U32 DeviceId);
ST_ErrorCode_t TesttoolRun                     (BOOL Synchronous);
ST_ErrorCode_t MODULES_Init                    (void);
ST_ErrorCode_t MODULES_Term                    (void);
ST_ErrorCode_t MODULES_Debug                   (void);
ST_ErrorCode_t SECMODULES_Init                 (void);
ST_ErrorCode_t SECMODULES_Term                 (void);
ST_ErrorCode_t SECMODULES_Debug                (void);
#if defined(ST_OSLINUX)
int            exec_external_command           (char **args);
#endif
#define        STTST_Init(a)                   TesttoolInit()
#define        STTST_Start( )                  TesttoolRun()
#define        STTST_Term()                    TesttoolTerm()
#define        STTST_SetMode(a)
#define        STTST_Print(msg)                print msg
#define        STTST_PrintERROR(msg)           STTST_Print(("\033[31m")); STTST_Print(msg); STTST_Print(("\033[0m"))
#define        STTST_PrintREPORT(msg)          STTST_Print(("\033[32m")); STTST_Print(msg); STTST_Print(("\033[0m"))
#define        STTST_PrintINFO(msg)            STTST_Print(("\033[34m")); STTST_Print(msg); STTST_Print(("\033[0m"))
#define        STTST_GetItem(p,d,r,m)          cget_item(p,d,r,m)
#define        STTST_GetTokenCount(p,r)        cget_token_count(p,r)
#define        STTST_GetString(p,d,r,m)        cget_string(p,d,r,m)
#define        STTST_GetInteger(p,d,r)         cget_integer(p,d,r)
#define        STTST_GetFloat(p,d,r)           cget_float(p,d,r)
#define        STTST_AssignString(t,v,c)       assign_string(t,v,c)
#define        STTST_AssignInteger(t,v,c)      assign_integer(t,v,c)
#define        STTST_AssignFloat(t,v,c)        assign_float(t,v,c)
#define        STTST_EvaluateString(t,s,m)     evaluate_string(t,s,m)
#define        STTST_EvaluateInteger(t,v,d)    evaluate_integer(t,v,d)
#define        STTST_EvaluateFloat(t,v)        evaluate_float(t,v)
#define        STTST_EvaluateComparison(t,r,d) evaluate_comparison(t,r,d)
#define        STTST_TagCurrentLine(p,m)       tag_current_line(p,m)
#define        STTST_RegisterCommand(t,a,h)    register_command(t,a,h)

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

