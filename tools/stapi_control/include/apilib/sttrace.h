#ifndef STTRACE_H
#define STTRACE_H

/*!
 * Turns off completely the STTRACE trace mechanism. No SET_TRACE() traces will
 * be displayed when STTRACE_TURN_OFF_MECHANISM is defined; also, when defined,
 * it disables the sttbx_early_core.ko dependency.
 *
 * For System Tests, this flag should be undefined (comment out the #define),
 * because System Tests need to be run with error traces on.
 * In this case, sttbx_early_core.ko needs to be loaded (it is already the case
 * for all platforms defined under stapp/platform).
 */
/*#define STTRACE_TURN_OFF_MECHANISM*/
/*
 * COMPO_CID
 */
#define TRACE_COMPO_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_COMPO_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_COMPO_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_COMPO_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_COMPO_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_COMPO_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_COMPO_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * COMPO_CID: COMPO_CORE_CID
 */
#define TRACE_COMPO_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_COMPO_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_COMPO_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_COMPO_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_COMPO_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_COMPO_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_COMPO_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * COMPO_CID: COMPO_POWER_CID
 */
#define TRACE_COMPO_POWER_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_COMPO_POWER_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_COMPO_POWER_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_COMPO_POWER_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_COMPO_POWER_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_COMPO_POWER_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_COMPO_POWER_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * COMPO_CID: COMPO_SPARE1_CID
 */
#define TRACE_COMPO_SPARE1_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_COMPO_SPARE1_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_COMPO_SPARE1_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_COMPO_SPARE1_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_COMPO_SPARE1_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_COMPO_SPARE1_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_COMPO_SPARE1_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * COMPO_CID: COMPO_SPARE2_CID
 */
#define TRACE_COMPO_SPARE2_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_COMPO_SPARE2_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_COMPO_SPARE2_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_COMPO_SPARE2_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_COMPO_SPARE2_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_COMPO_SPARE2_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_COMPO_SPARE2_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * COMPO_CID: COMPO_SPARE3_CID
 */
#define TRACE_COMPO_SPARE3_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_COMPO_SPARE3_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_COMPO_SPARE3_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_COMPO_SPARE3_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_COMPO_SPARE3_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_COMPO_SPARE3_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_COMPO_SPARE3_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * COMPO_CID: COMPO_SPARE4_CID
 */
#define TRACE_COMPO_SPARE4_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_COMPO_SPARE4_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_COMPO_SPARE4_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_COMPO_SPARE4_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_COMPO_SPARE4_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_COMPO_SPARE4_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_COMPO_SPARE4_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * COMPO_CID: COMPO_SRC_CID
 */
#define TRACE_COMPO_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_COMPO_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_COMPO_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_COMPO_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_COMPO_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_COMPO_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_COMPO_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * ST2FX_CID
 */
#define TRACE_ST2FX_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_ST2FX_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_ST2FX_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_ST2FX_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_ST2FX_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_ST2FX_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_ST2FX_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * ST3FX_CID
 */
#define TRACE_ST3FX_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_ST3FX_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_ST3FX_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_ST3FX_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_ST3FX_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_ST3FX_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_ST3FX_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * ST3FX_CID: ST3FX_EGL_CID
 */
#define TRACE_ST3FX_EGL_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_ST3FX_EGL_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_ST3FX_EGL_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_ST3FX_EGL_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_ST3FX_EGL_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_ST3FX_EGL_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_ST3FX_EGL_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * ST3FX_CID: ST3FX_EXT_CID
 */
#define TRACE_ST3FX_EXT_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_ST3FX_EXT_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_ST3FX_EXT_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_ST3FX_EXT_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_ST3FX_EXT_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_ST3FX_EXT_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_ST3FX_EXT_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * ST3FX_CID: ST3FX_GL_CID
 */
#define TRACE_ST3FX_GL_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_ST3FX_GL_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_ST3FX_GL_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_ST3FX_GL_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_ST3FX_GL_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_ST3FX_GL_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_ST3FX_GL_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
 * ST3FX_CID: ST3FX_IM_CID
 */
#define TRACE_ST3FX_IM_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_ST3FX_IM_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_ST3FX_IM_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_ST3FX_IM_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_ST3FX_IM_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_ST3FX_IM_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_ST3FX_IM_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
 * ST3FX_CID: ST3FX_SIM_CID
 */
#define TRACE_ST3FX_SIM_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_ST3FX_SIM_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_ST3FX_SIM_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_ST3FX_SIM_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_ST3FX_SIM_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_ST3FX_SIM_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_ST3FX_SIM_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STAPP_CID
 */
#define TRACE_STAPP_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STAPP_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STAPP_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STAPP_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STAPP_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STAPP_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STAPP_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STAPP_CID: STAPP_FRONTEND_CID
 */
#define TRACE_STAPP_FRONTEND_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STAPP_FRONTEND_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STAPP_FRONTEND_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STAPP_FRONTEND_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STAPP_FRONTEND_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STAPP_FRONTEND_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STAPP_FRONTEND_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STAPP_CID: STAPP_PLAYREC_CID
 */
#define TRACE_STAPP_PLAYREC_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STAPP_PLAYREC_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STAPP_PLAYREC_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STAPP_PLAYREC_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STAPP_PLAYREC_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STAPP_PLAYREC_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STAPP_PLAYREC_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STAPP_CID: STAPP_TAPI_CID
 */
#define TRACE_STAPP_TAPI_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STAPP_TAPI_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STAPP_TAPI_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STAPP_TAPI_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STAPP_TAPI_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STAPP_TAPI_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STAPP_TAPI_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STAPP_CID: STAPP_UART_CID
 */
#define TRACE_STAPP_UART_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STAPP_UART_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STAPP_UART_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STAPP_UART_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STAPP_UART_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STAPP_UART_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STAPP_UART_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STAPP_CID: STAPP_VIDEO_CID
 */
#define TRACE_STAPP_VIDEO_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STAPP_VIDEO_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STAPP_VIDEO_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STAPP_VIDEO_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STAPP_VIDEO_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STAPP_VIDEO_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STAPP_VIDEO_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STATAPI_CID
 */
#define TRACE_STATAPI_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STATAPI_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STATAPI_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STATAPI_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STATAPI_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STATAPI_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STATAPI_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STATAPI_CID: STATAPI_API_CID
 */
#define TRACE_STATAPI_API_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STATAPI_API_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STATAPI_API_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STATAPI_API_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STATAPI_API_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STATAPI_API_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STATAPI_API_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STATAPI_CID: STATAPI_CMD_CID
 */
#define TRACE_STATAPI_CMD_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STATAPI_CMD_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STATAPI_CMD_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STATAPI_CMD_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STATAPI_CMD_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STATAPI_CMD_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STATAPI_CMD_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STATAPI_CID: STATAPI_COMMON_CID
 */
#define TRACE_STATAPI_COMMON_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STATAPI_COMMON_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STATAPI_COMMON_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STATAPI_COMMON_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STATAPI_COMMON_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STATAPI_COMMON_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STATAPI_COMMON_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STATAPI_CID: STATAPI_HAL_CID
 */
#define TRACE_STATAPI_HAL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STATAPI_HAL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STATAPI_HAL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STATAPI_HAL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STATAPI_HAL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STATAPI_HAL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STATAPI_HAL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STATAPI_CID: STATAPI_POWER_CID
 */
#define TRACE_STATAPI_POWER_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STATAPI_POWER_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STATAPI_POWER_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STATAPI_POWER_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STATAPI_POWER_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STATAPI_POWER_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STATAPI_POWER_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STAUDLX_CID
 */
#define TRACE_STAUDLX_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STAUDLX_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STAUDLX_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STAUDLX_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STAUDLX_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STAUDLX_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STAUDLX_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_BLOCKMANAGER_CID
 */
#define TRACE_STAUDLX_BLOCKMANAGER_CID_FATAL_ACTIVATED                        STTRACE_ON
#define TRACE_STAUDLX_BLOCKMANAGER_CID_ERROR_ACTIVATED                        STTRACE_ON
#define TRACE_STAUDLX_BLOCKMANAGER_CID_WARNING_ACTIVATED                      STTRACE_OFF
#define TRACE_STAUDLX_BLOCKMANAGER_CID_INFO_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_BLOCKMANAGER_CID_API_IN_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_BLOCKMANAGER_CID_API_OUT_ACTIVATED                      STTRACE_OFF
#define TRACE_STAUDLX_BLOCKMANAGER_CID_USER_ACTIVATED                         STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_DECODER_CID
 */
#define TRACE_STAUDLX_DECODER_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STAUDLX_DECODER_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STAUDLX_DECODER_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_DECODER_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STAUDLX_DECODER_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_DECODER_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_DECODER_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_DRIVER_CONFIG_CID
 */
#define TRACE_STAUDLX_DRIVER_CONFIG_CID_FATAL_ACTIVATED                       STTRACE_ON
#define TRACE_STAUDLX_DRIVER_CONFIG_CID_ERROR_ACTIVATED                       STTRACE_ON
#define TRACE_STAUDLX_DRIVER_CONFIG_CID_WARNING_ACTIVATED                     STTRACE_OFF
#define TRACE_STAUDLX_DRIVER_CONFIG_CID_INFO_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_DRIVER_CONFIG_CID_API_IN_ACTIVATED                      STTRACE_OFF
#define TRACE_STAUDLX_DRIVER_CONFIG_CID_API_OUT_ACTIVATED                     STTRACE_OFF
#define TRACE_STAUDLX_DRIVER_CONFIG_CID_USER_ACTIVATED                        STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_ENCODER_CID
 */
#define TRACE_STAUDLX_ENCODER_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STAUDLX_ENCODER_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STAUDLX_ENCODER_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_ENCODER_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STAUDLX_ENCODER_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_ENCODER_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_ENCODER_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_ES_PARSER_CID
 */
#define TRACE_STAUDLX_ES_PARSER_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_ES_PARSER_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_ES_PARSER_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_ES_PARSER_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_ES_PARSER_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STAUDLX_ES_PARSER_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_ES_PARSER_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_FRAME_PROCESSOR_CID
 */
#define TRACE_STAUDLX_FRAME_PROCESSOR_CID_FATAL_ACTIVATED                     STTRACE_ON
#define TRACE_STAUDLX_FRAME_PROCESSOR_CID_ERROR_ACTIVATED                     STTRACE_ON
#define TRACE_STAUDLX_FRAME_PROCESSOR_CID_WARNING_ACTIVATED                   STTRACE_OFF
#define TRACE_STAUDLX_FRAME_PROCESSOR_CID_INFO_ACTIVATED                      STTRACE_OFF
#define TRACE_STAUDLX_FRAME_PROCESSOR_CID_API_IN_ACTIVATED                    STTRACE_OFF
#define TRACE_STAUDLX_FRAME_PROCESSOR_CID_API_OUT_ACTIVATED                   STTRACE_OFF
#define TRACE_STAUDLX_FRAME_PROCESSOR_CID_USER_ACTIVATED                      STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_GENERIC_CID
 */
#define TRACE_STAUDLX_GENERIC_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STAUDLX_GENERIC_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STAUDLX_GENERIC_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_GENERIC_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STAUDLX_GENERIC_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_GENERIC_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_GENERIC_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_HDMIPLAYER_CID
 */
#define TRACE_STAUDLX_HDMIPLAYER_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_HDMIPLAYER_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_HDMIPLAYER_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_HDMIPLAYER_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_HDMIPLAYER_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_HDMIPLAYER_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_HDMIPLAYER_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_IPRC_PROXY_CID
 */
#define TRACE_STAUDLX_IPRC_PROXY_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_IPRC_PROXY_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_IPRC_PROXY_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_IPRC_PROXY_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_IPRC_PROXY_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_IPRC_PROXY_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_IPRC_PROXY_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_IPRC_STUB_CID
 */
#define TRACE_STAUDLX_IPRC_STUB_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_IPRC_STUB_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_IPRC_STUB_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_IPRC_STUB_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_IPRC_STUB_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STAUDLX_IPRC_STUB_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_IPRC_STUB_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_LINUX_ALSA_CID
 */
#define TRACE_STAUDLX_LINUX_ALSA_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_LINUX_ALSA_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_LINUX_ALSA_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_LINUX_ALSA_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_LINUX_ALSA_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_LINUX_ALSA_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_LINUX_ALSA_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_LINUX_CORE_CID
 */
#define TRACE_STAUDLX_LINUX_CORE_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_LINUX_CORE_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_LINUX_CORE_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_LINUX_CORE_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_LINUX_CORE_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_LINUX_CORE_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_LINUX_CORE_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_LINUX_DVB_CID
 */
#define TRACE_STAUDLX_LINUX_DVB_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_LINUX_DVB_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_LINUX_DVB_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_LINUX_DVB_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_LINUX_DVB_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STAUDLX_LINUX_DVB_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_LINUX_DVB_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_LINUX_IOCTL_CID
 */
#define TRACE_STAUDLX_LINUX_IOCTL_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STAUDLX_LINUX_IOCTL_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STAUDLX_LINUX_IOCTL_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_LINUX_IOCTL_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STAUDLX_LINUX_IOCTL_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_LINUX_IOCTL_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_LINUX_IOCTL_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_LINUX_PROXY_CID
 */
#define TRACE_STAUDLX_LINUX_PROXY_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STAUDLX_LINUX_PROXY_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STAUDLX_LINUX_PROXY_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_LINUX_PROXY_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STAUDLX_LINUX_PROXY_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_LINUX_PROXY_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_LINUX_PROXY_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_MIXER_CID
 */
#define TRACE_STAUDLX_MIXER_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STAUDLX_MIXER_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STAUDLX_MIXER_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STAUDLX_MIXER_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STAUDLX_MIXER_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STAUDLX_MIXER_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STAUDLX_MIXER_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_PARSER_CID
 */
#define TRACE_STAUDLX_PARSER_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STAUDLX_PARSER_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STAUDLX_PARSER_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_PARSER_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STAUDLX_PARSER_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STAUDLX_PARSER_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_PARSER_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_PCMPLAYER_CID
 */
#define TRACE_STAUDLX_PCMPLAYER_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_PCMPLAYER_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_PCMPLAYER_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_PCMPLAYER_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_PCMPLAYER_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STAUDLX_PCMPLAYER_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_PCMPLAYER_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_PCM_INPUT_CID
 */
#define TRACE_STAUDLX_PCM_INPUT_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_PCM_INPUT_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STAUDLX_PCM_INPUT_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_PCM_INPUT_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STAUDLX_PCM_INPUT_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STAUDLX_PCM_INPUT_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_PCM_INPUT_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_PCM_READER_CID
 */
#define TRACE_STAUDLX_PCM_READER_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_PCM_READER_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_PCM_READER_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_PCM_READER_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_PCM_READER_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_PCM_READER_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_PCM_READER_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_PES_PARSER_CID
 */
#define TRACE_STAUDLX_PES_PARSER_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_PES_PARSER_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STAUDLX_PES_PARSER_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_PES_PARSER_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STAUDLX_PES_PARSER_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_PES_PARSER_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_PES_PARSER_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_POST_PROCESSOR_CID
 */
#define TRACE_STAUDLX_POST_PROCESSOR_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STAUDLX_POST_PROCESSOR_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STAUDLX_POST_PROCESSOR_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STAUDLX_POST_PROCESSOR_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_POST_PROCESSOR_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STAUDLX_POST_PROCESSOR_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STAUDLX_POST_PROCESSOR_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_SOFTAUDIO_IF_CID
 */
#define TRACE_STAUDLX_SOFTAUDIO_IF_CID_FATAL_ACTIVATED                        STTRACE_ON
#define TRACE_STAUDLX_SOFTAUDIO_IF_CID_ERROR_ACTIVATED                        STTRACE_ON
#define TRACE_STAUDLX_SOFTAUDIO_IF_CID_WARNING_ACTIVATED                      STTRACE_OFF
#define TRACE_STAUDLX_SOFTAUDIO_IF_CID_INFO_ACTIVATED                         STTRACE_OFF
#define TRACE_STAUDLX_SOFTAUDIO_IF_CID_API_IN_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_SOFTAUDIO_IF_CID_API_OUT_ACTIVATED                      STTRACE_OFF
#define TRACE_STAUDLX_SOFTAUDIO_IF_CID_USER_ACTIVATED                         STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_SPDIFFORMATTER_CID
 */
#define TRACE_STAUDLX_SPDIFFORMATTER_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STAUDLX_SPDIFFORMATTER_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STAUDLX_SPDIFFORMATTER_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STAUDLX_SPDIFFORMATTER_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_SPDIFFORMATTER_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STAUDLX_SPDIFFORMATTER_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STAUDLX_SPDIFFORMATTER_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STAUDLX_CID: STAUDLX_SPDIFPLAYER_CID
 */
#define TRACE_STAUDLX_SPDIFPLAYER_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STAUDLX_SPDIFPLAYER_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STAUDLX_SPDIFPLAYER_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_SPDIFPLAYER_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STAUDLX_SPDIFPLAYER_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STAUDLX_SPDIFPLAYER_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STAUDLX_SPDIFPLAYER_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STAVMEM_CID
 */
#define TRACE_STAVMEM_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STAVMEM_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STAVMEM_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STAVMEM_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STAVMEM_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STAVMEM_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STAVMEM_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STAVMEM_CID: STAVMEM_CORE_CID
 */
#define TRACE_STAVMEM_CORE_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STAVMEM_CORE_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STAVMEM_CORE_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STAVMEM_CORE_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STAVMEM_CORE_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STAVMEM_CORE_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STAVMEM_CORE_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STAVMEM_CID: STAVMEM_IOCTL_CID
 */
#define TRACE_STAVMEM_IOCTL_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STAVMEM_IOCTL_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STAVMEM_IOCTL_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STAVMEM_IOCTL_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STAVMEM_IOCTL_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STAVMEM_IOCTL_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STAVMEM_IOCTL_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STAVMEM_CID: STAVMEM_SRC_CID
 */
#define TRACE_STAVMEM_SRC_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STAVMEM_SRC_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STAVMEM_SRC_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STAVMEM_SRC_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STAVMEM_SRC_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STAVMEM_SRC_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STAVMEM_SRC_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STBLAST_CID
 */
#define TRACE_STBLAST_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STBLAST_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STBLAST_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STBLAST_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STBLAST_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STBLAST_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STBLAST_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STBLAST_CID: STBLAST_COMMON_CID
 */
#define TRACE_STBLAST_COMMON_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STBLAST_COMMON_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STBLAST_COMMON_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STBLAST_COMMON_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STBLAST_COMMON_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLAST_COMMON_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STBLAST_COMMON_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STBLAST_CID: STBLAST_CORE_CID
 */
#define TRACE_STBLAST_CORE_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STBLAST_CORE_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STBLAST_CORE_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLAST_CORE_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STBLAST_CORE_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STBLAST_CORE_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLAST_CORE_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STBLAST_CID: STBLAST_IOCTL_CID
 */
#define TRACE_STBLAST_IOCTL_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STBLAST_IOCTL_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STBLAST_IOCTL_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLAST_IOCTL_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLAST_IOCTL_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLAST_IOCTL_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLAST_IOCTL_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STBLAST_CID: STBLAST_PROTOCOLS_CID
 */
#define TRACE_STBLAST_PROTOCOLS_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STBLAST_PROTOCOLS_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STBLAST_PROTOCOLS_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STBLAST_PROTOCOLS_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STBLAST_PROTOCOLS_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STBLAST_PROTOCOLS_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STBLAST_PROTOCOLS_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STBLAST_CID: STBLAST_SRC_CID
 */
#define TRACE_STBLAST_SRC_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STBLAST_SRC_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STBLAST_SRC_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STBLAST_SRC_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STBLAST_SRC_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLAST_SRC_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STBLAST_SRC_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STBLIT_CID
 */
#define TRACE_STBLIT_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STBLIT_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STBLIT_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STBLIT_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STBLIT_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STBLIT_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STBLIT_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STBLIT_CID: STBLIT_API_CID
 */
#define TRACE_STBLIT_API_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STBLIT_API_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STBLIT_API_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLIT_API_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STBLIT_API_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STBLIT_API_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLIT_API_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STBLIT_CID: STBLIT_CORE_CID
 */
#define TRACE_STBLIT_CORE_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STBLIT_CORE_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STBLIT_CORE_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STBLIT_CORE_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STBLIT_CORE_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLIT_CORE_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STBLIT_CORE_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STBLIT_CID: STBLIT_IOCTL_CID
 */
#define TRACE_STBLIT_IOCTL_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STBLIT_IOCTL_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STBLIT_IOCTL_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLIT_IOCTL_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STBLIT_IOCTL_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STBLIT_IOCTL_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLIT_IOCTL_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STBLIT_CID: STBLIT_POWER_CID
 */
#define TRACE_STBLIT_POWER_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STBLIT_POWER_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STBLIT_POWER_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLIT_POWER_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STBLIT_POWER_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STBLIT_POWER_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLIT_POWER_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STBLIT_CID: STBLIT_SPARE1_CID
 */
#define TRACE_STBLIT_SPARE1_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STBLIT_SPARE1_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STBLIT_SPARE1_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLIT_SPARE1_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLIT_SPARE1_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLIT_SPARE1_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLIT_SPARE1_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STBLIT_CID: STBLIT_SPARE2_CID
 */
#define TRACE_STBLIT_SPARE2_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STBLIT_SPARE2_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STBLIT_SPARE2_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLIT_SPARE2_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLIT_SPARE2_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLIT_SPARE2_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLIT_SPARE2_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STBLIT_CID: STBLIT_SPARE3_CID
 */
#define TRACE_STBLIT_SPARE3_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STBLIT_SPARE3_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STBLIT_SPARE3_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLIT_SPARE3_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLIT_SPARE3_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLIT_SPARE3_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLIT_SPARE3_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STBLIT_CID: STBLIT_SPARE4_CID
 */
#define TRACE_STBLIT_SPARE4_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STBLIT_SPARE4_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STBLIT_SPARE4_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLIT_SPARE4_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLIT_SPARE4_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STBLIT_SPARE4_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STBLIT_SPARE4_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STBLIT_CID: STBLIT_SRC_CID
 */
#define TRACE_STBLIT_SRC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STBLIT_SRC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STBLIT_SRC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLIT_SRC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STBLIT_SRC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STBLIT_SRC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STBLIT_SRC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STBOOT_CID
 */
#define TRACE_STBOOT_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STBOOT_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STBOOT_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STBOOT_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STBOOT_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STBOOT_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STBOOT_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STBOOT_CID: STBOOT_CORE_CID
 */
#define TRACE_STBOOT_CORE_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STBOOT_CORE_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STBOOT_CORE_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STBOOT_CORE_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STBOOT_CORE_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STBOOT_CORE_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STBOOT_CORE_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STBUFFER_CID
 */
#define TRACE_STBUFFER_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STBUFFER_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STBUFFER_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_STBUFFER_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_STBUFFER_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_STBUFFER_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_STBUFFER_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
 * STCC_CID
 */
#define TRACE_STCC_CID_FATAL_ACTIVATED                                        STTRACE_ON
#define TRACE_STCC_CID_ERROR_ACTIVATED                                        STTRACE_ON
#define TRACE_STCC_CID_WARNING_ACTIVATED                                      STTRACE_OFF
#define TRACE_STCC_CID_INFO_ACTIVATED                                         STTRACE_OFF
#define TRACE_STCC_CID_API_IN_ACTIVATED                                       STTRACE_OFF
#define TRACE_STCC_CID_API_OUT_ACTIVATED                                      STTRACE_OFF
#define TRACE_STCC_CID_USER_ACTIVATED                                         STTRACE_OFF
/*
 * STCC_CID: STCC_POWER_CID
 */
#define TRACE_STCC_POWER_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STCC_POWER_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STCC_POWER_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STCC_POWER_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STCC_POWER_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCC_POWER_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STCC_POWER_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STCC_CID: STCC_SRC_CID
 */
#define TRACE_STCC_SRC_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STCC_SRC_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STCC_SRC_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_STCC_SRC_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_STCC_SRC_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_STCC_SRC_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_STCC_SRC_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
* STCC_CID: STCC_CORE_CID
*/
#define TRACE_STCC_CORE_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STCC_CORE_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STCC_CORE_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCC_CORE_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STCC_CORE_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STCC_CORE_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCC_CORE_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
* STCC_CID: STCC_IOCTL_CID
*/
#define TRACE_STCC_IOCTL_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STCC_IOCTL_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STCC_IOCTL_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STCC_IOCTL_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STCC_IOCTL_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCC_IOCTL_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STCC_IOCTL_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STCLKRV_CID
 */
#define TRACE_STCLKRV_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STCLKRV_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STCLKRV_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STCLKRV_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STCLKRV_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STCLKRV_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STCLKRV_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_ENABLE_DISABLE_CID
 */
#define TRACE_STCLKRV_ENABLE_DISABLE_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STCLKRV_ENABLE_DISABLE_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STCLKRV_ENABLE_DISABLE_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLKRV_ENABLE_DISABLE_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLKRV_ENABLE_DISABLE_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLKRV_ENABLE_DISABLE_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLKRV_ENABLE_DISABLE_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_GET_EXT_STC_CID
 */
#define TRACE_STCLKRV_GET_EXT_STC_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STCLKRV_GET_EXT_STC_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STCLKRV_GET_EXT_STC_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLKRV_GET_EXT_STC_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLKRV_GET_EXT_STC_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_GET_EXT_STC_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLKRV_GET_EXT_STC_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_GET_SET_RECOVERY_CID
 */
#define TRACE_STCLKRV_GET_SET_RECOVERY_CID_FATAL_ACTIVATED                    STTRACE_ON
#define TRACE_STCLKRV_GET_SET_RECOVERY_CID_ERROR_ACTIVATED                    STTRACE_ON
#define TRACE_STCLKRV_GET_SET_RECOVERY_CID_WARNING_ACTIVATED                  STTRACE_OFF
#define TRACE_STCLKRV_GET_SET_RECOVERY_CID_INFO_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLKRV_GET_SET_RECOVERY_CID_API_IN_ACTIVATED                   STTRACE_OFF
#define TRACE_STCLKRV_GET_SET_RECOVERY_CID_API_OUT_ACTIVATED                  STTRACE_OFF
#define TRACE_STCLKRV_GET_SET_RECOVERY_CID_USER_ACTIVATED                     STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_GET_STC_CID
 */
#define TRACE_STCLKRV_GET_STC_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STCLKRV_GET_STC_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STCLKRV_GET_STC_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLKRV_GET_STC_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLKRV_GET_STC_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STCLKRV_GET_STC_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLKRV_GET_STC_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_INFO_CID
 */
#define TRACE_STCLKRV_INFO_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STCLKRV_INFO_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STCLKRV_INFO_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLKRV_INFO_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCLKRV_INFO_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STCLKRV_INFO_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLKRV_INFO_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_INIT_TERM_CID
 */
#define TRACE_STCLKRV_INIT_TERM_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STCLKRV_INIT_TERM_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STCLKRV_INIT_TERM_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLKRV_INIT_TERM_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STCLKRV_INIT_TERM_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLKRV_INIT_TERM_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLKRV_INIT_TERM_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_INVALIDATE_CLK_CID
 */
#define TRACE_STCLKRV_INVALIDATE_CLK_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STCLKRV_INVALIDATE_CLK_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STCLKRV_INVALIDATE_CLK_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLKRV_INVALIDATE_CLK_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLKRV_INVALIDATE_CLK_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLKRV_INVALIDATE_CLK_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLKRV_INVALIDATE_CLK_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_LINUX_CORE_CID
 */
#define TRACE_STCLKRV_LINUX_CORE_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_LINUX_CORE_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_LINUX_CORE_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_LINUX_CORE_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLKRV_LINUX_CORE_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLKRV_LINUX_CORE_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_LINUX_CORE_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_LINUX_IOCTL_CID
 */
#define TRACE_STCLKRV_LINUX_IOCTL_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STCLKRV_LINUX_IOCTL_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STCLKRV_LINUX_IOCTL_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLKRV_LINUX_IOCTL_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLKRV_LINUX_IOCTL_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_LINUX_IOCTL_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLKRV_LINUX_IOCTL_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_LLR_INFO_CID
 */
#define TRACE_STCLKRV_LLR_INFO_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STCLKRV_LLR_INFO_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STCLKRV_LLR_INFO_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLKRV_LLR_INFO_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STCLKRV_LLR_INFO_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLKRV_LLR_INFO_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLKRV_LLR_INFO_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_NOMINAL_FREQ_CID
 */
#define TRACE_STCLKRV_NOMINAL_FREQ_CID_FATAL_ACTIVATED                        STTRACE_ON
#define TRACE_STCLKRV_NOMINAL_FREQ_CID_ERROR_ACTIVATED                        STTRACE_ON
#define TRACE_STCLKRV_NOMINAL_FREQ_CID_WARNING_ACTIVATED                      STTRACE_OFF
#define TRACE_STCLKRV_NOMINAL_FREQ_CID_INFO_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLKRV_NOMINAL_FREQ_CID_API_IN_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLKRV_NOMINAL_FREQ_CID_API_OUT_ACTIVATED                      STTRACE_OFF
#define TRACE_STCLKRV_NOMINAL_FREQ_CID_USER_ACTIVATED                         STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_OPEN_CLOSE_CID
 */
#define TRACE_STCLKRV_OPEN_CLOSE_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_OPEN_CLOSE_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_OPEN_CLOSE_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_OPEN_CLOSE_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLKRV_OPEN_CLOSE_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLKRV_OPEN_CLOSE_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_OPEN_CLOSE_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_PCR_INFO_CID
 */
#define TRACE_STCLKRV_PCR_INFO_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STCLKRV_PCR_INFO_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STCLKRV_PCR_INFO_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLKRV_PCR_INFO_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STCLKRV_PCR_INFO_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLKRV_PCR_INFO_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLKRV_PCR_INFO_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_PCR_SOURCE_CID
 */
#define TRACE_STCLKRV_PCR_SOURCE_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_PCR_SOURCE_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_PCR_SOURCE_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_PCR_SOURCE_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLKRV_PCR_SOURCE_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLKRV_PCR_SOURCE_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_PCR_SOURCE_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_POWER_CID
 */
#define TRACE_STCLKRV_POWER_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STCLKRV_POWER_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STCLKRV_POWER_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STCLKRV_POWER_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STCLKRV_POWER_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLKRV_POWER_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STCLKRV_POWER_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_STC_BASELINE_CID
 */
#define TRACE_STCLKRV_STC_BASELINE_CID_FATAL_ACTIVATED                        STTRACE_ON
#define TRACE_STCLKRV_STC_BASELINE_CID_ERROR_ACTIVATED                        STTRACE_ON
#define TRACE_STCLKRV_STC_BASELINE_CID_WARNING_ACTIVATED                      STTRACE_OFF
#define TRACE_STCLKRV_STC_BASELINE_CID_INFO_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLKRV_STC_BASELINE_CID_API_IN_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLKRV_STC_BASELINE_CID_API_OUT_ACTIVATED                      STTRACE_OFF
#define TRACE_STCLKRV_STC_BASELINE_CID_USER_ACTIVATED                         STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_STC_OFFSET_CID
 */
#define TRACE_STCLKRV_STC_OFFSET_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_STC_OFFSET_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_STC_OFFSET_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_STC_OFFSET_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLKRV_STC_OFFSET_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLKRV_STC_OFFSET_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_STC_OFFSET_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STCLKRV_CID: STCLKRV_STC_SOURCE_CID
 */
#define TRACE_STCLKRV_STC_SOURCE_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_STC_SOURCE_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STCLKRV_STC_SOURCE_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_STC_SOURCE_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLKRV_STC_SOURCE_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLKRV_STC_SOURCE_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLKRV_STC_SOURCE_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STCLOCK_CID
 */
#define TRACE_STCLOCK_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STCLOCK_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STCLOCK_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STCLOCK_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STCLOCK_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STCLOCK_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STCLOCK_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_API_CID
 */
#define TRACE_STCLOCK_API_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STCLOCK_API_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STCLOCK_API_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STCLOCK_API_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STCLOCK_API_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STCLOCK_API_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STCLOCK_API_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_FREQ_CID
 */
#define TRACE_STCLOCK_FREQ_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_FREQ_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_FREQ_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_FREQ_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCLOCK_FREQ_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STCLOCK_FREQ_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_FREQ_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_INIT_CID
 */
#define TRACE_STCLOCK_INIT_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_INIT_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_INIT_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_INIT_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCLOCK_INIT_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STCLOCK_INIT_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_INIT_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_IPRC_CID
 */
#define TRACE_STCLOCK_IPRC_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_IPRC_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_IPRC_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_IPRC_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCLOCK_IPRC_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STCLOCK_IPRC_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_IPRC_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_MASTER_INIT_CID
 */
#define TRACE_STCLOCK_MASTER_INIT_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STCLOCK_MASTER_INIT_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STCLOCK_MASTER_INIT_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLOCK_MASTER_INIT_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLOCK_MASTER_INIT_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLOCK_MASTER_INIT_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLOCK_MASTER_INIT_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_MODE_CID
 */
#define TRACE_STCLOCK_MODE_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_MODE_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_MODE_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_MODE_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCLOCK_MODE_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STCLOCK_MODE_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_MODE_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_MSG_RECD_HOST_CID
 */
#define TRACE_STCLOCK_MSG_RECD_HOST_CID_FATAL_ACTIVATED                       STTRACE_ON
#define TRACE_STCLOCK_MSG_RECD_HOST_CID_ERROR_ACTIVATED                       STTRACE_ON
#define TRACE_STCLOCK_MSG_RECD_HOST_CID_WARNING_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLOCK_MSG_RECD_HOST_CID_INFO_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLOCK_MSG_RECD_HOST_CID_API_IN_ACTIVATED                      STTRACE_OFF
#define TRACE_STCLOCK_MSG_RECD_HOST_CID_API_OUT_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLOCK_MSG_RECD_HOST_CID_USER_ACTIVATED                        STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_MSG_RECD_SLAVE_CID
 */
#define TRACE_STCLOCK_MSG_RECD_SLAVE_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STCLOCK_MSG_RECD_SLAVE_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STCLOCK_MSG_RECD_SLAVE_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLOCK_MSG_RECD_SLAVE_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLOCK_MSG_RECD_SLAVE_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLOCK_MSG_RECD_SLAVE_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLOCK_MSG_RECD_SLAVE_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_MSG_SEND_HOST_CID
 */
#define TRACE_STCLOCK_MSG_SEND_HOST_CID_FATAL_ACTIVATED                       STTRACE_ON
#define TRACE_STCLOCK_MSG_SEND_HOST_CID_ERROR_ACTIVATED                       STTRACE_ON
#define TRACE_STCLOCK_MSG_SEND_HOST_CID_WARNING_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLOCK_MSG_SEND_HOST_CID_INFO_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLOCK_MSG_SEND_HOST_CID_API_IN_ACTIVATED                      STTRACE_OFF
#define TRACE_STCLOCK_MSG_SEND_HOST_CID_API_OUT_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLOCK_MSG_SEND_HOST_CID_USER_ACTIVATED                        STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_MSG_SEND_SLAVE_CID
 */
#define TRACE_STCLOCK_MSG_SEND_SLAVE_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STCLOCK_MSG_SEND_SLAVE_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STCLOCK_MSG_SEND_SLAVE_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLOCK_MSG_SEND_SLAVE_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLOCK_MSG_SEND_SLAVE_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLOCK_MSG_SEND_SLAVE_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLOCK_MSG_SEND_SLAVE_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_REGISTER_CID
 */
#define TRACE_STCLOCK_REGISTER_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STCLOCK_REGISTER_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STCLOCK_REGISTER_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLOCK_REGISTER_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STCLOCK_REGISTER_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLOCK_REGISTER_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLOCK_REGISTER_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_REGISTER_SLAVE_CID
 */
#define TRACE_STCLOCK_REGISTER_SLAVE_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STCLOCK_REGISTER_SLAVE_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STCLOCK_REGISTER_SLAVE_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLOCK_REGISTER_SLAVE_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STCLOCK_REGISTER_SLAVE_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLOCK_REGISTER_SLAVE_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STCLOCK_REGISTER_SLAVE_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_RESCLOCK_CID
 */
#define TRACE_STCLOCK_RESCLOCK_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STCLOCK_RESCLOCK_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STCLOCK_RESCLOCK_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLOCK_RESCLOCK_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STCLOCK_RESCLOCK_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLOCK_RESCLOCK_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STCLOCK_RESCLOCK_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_SLAVE_INIT_CID
 */
#define TRACE_STCLOCK_SLAVE_INIT_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STCLOCK_SLAVE_INIT_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STCLOCK_SLAVE_INIT_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLOCK_SLAVE_INIT_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLOCK_SLAVE_INIT_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLOCK_SLAVE_INIT_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLOCK_SLAVE_INIT_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_TERM_CID
 */
#define TRACE_STCLOCK_TERM_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_TERM_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STCLOCK_TERM_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_TERM_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCLOCK_TERM_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STCLOCK_TERM_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STCLOCK_TERM_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_UNREGISTER_CID
 */
#define TRACE_STCLOCK_UNREGISTER_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STCLOCK_UNREGISTER_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STCLOCK_UNREGISTER_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLOCK_UNREGISTER_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STCLOCK_UNREGISTER_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STCLOCK_UNREGISTER_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STCLOCK_UNREGISTER_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STCLOCK_CID: STCLOCK_UNREGISTER_SLAVE_CID
 */
#define TRACE_STCLOCK_UNREGISTER_SLAVE_CID_FATAL_ACTIVATED                    STTRACE_ON
#define TRACE_STCLOCK_UNREGISTER_SLAVE_CID_ERROR_ACTIVATED                    STTRACE_ON
#define TRACE_STCLOCK_UNREGISTER_SLAVE_CID_WARNING_ACTIVATED                  STTRACE_OFF
#define TRACE_STCLOCK_UNREGISTER_SLAVE_CID_INFO_ACTIVATED                     STTRACE_OFF
#define TRACE_STCLOCK_UNREGISTER_SLAVE_CID_API_IN_ACTIVATED                   STTRACE_OFF
#define TRACE_STCLOCK_UNREGISTER_SLAVE_CID_API_OUT_ACTIVATED                  STTRACE_OFF
#define TRACE_STCLOCK_UNREGISTER_SLAVE_CID_USER_ACTIVATED                     STTRACE_OFF
/*
 * STCOMMON_CID
 */
#define TRACE_STCOMMON_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STCOMMON_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STCOMMON_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_STCOMMON_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_STCOMMON_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_STCOMMON_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_STCOMMON_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
 * STCOMMON_CID: STCOMMON_CORE_CID
 */
#define TRACE_STCOMMON_CORE_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STCOMMON_CORE_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STCOMMON_CORE_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STCOMMON_CORE_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STCOMMON_CORE_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STCOMMON_CORE_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STCOMMON_CORE_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STCOMMON_CID: STCOMMON_IOCTL_CID
 */
#define TRACE_STCOMMON_IOCTL_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STCOMMON_IOCTL_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STCOMMON_IOCTL_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STCOMMON_IOCTL_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STCOMMON_IOCTL_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STCOMMON_IOCTL_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STCOMMON_IOCTL_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STCOMMON_CID: STCOMMON_SOCS_CID
 */
#define TRACE_STCOMMON_SOCS_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STCOMMON_SOCS_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STCOMMON_SOCS_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STCOMMON_SOCS_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STCOMMON_SOCS_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STCOMMON_SOCS_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STCOMMON_SOCS_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STCOMMON_CID: STCOMMON_SRC_CID
 */
#define TRACE_STCOMMON_SRC_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STCOMMON_SRC_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STCOMMON_SRC_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STCOMMON_SRC_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STCOMMON_SRC_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STCOMMON_SRC_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STCOMMON_SRC_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STDENC_CID
 */
#define TRACE_STDENC_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STDENC_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STDENC_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STDENC_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STDENC_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STDENC_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STDENC_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STDENC_CID: STDENC_CORE_CID
 */
#define TRACE_STDENC_CORE_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STDENC_CORE_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STDENC_CORE_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STDENC_CORE_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STDENC_CORE_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STDENC_CORE_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STDENC_CORE_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STDENC_CID: STDENC_IOCTL_CID
 */
#define TRACE_STDENC_IOCTL_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STDENC_IOCTL_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STDENC_IOCTL_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STDENC_IOCTL_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STDENC_IOCTL_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STDENC_IOCTL_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STDENC_IOCTL_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STDENC_CID: STDENC_POWER_CID
 */
#define TRACE_STDENC_POWER_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STDENC_POWER_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STDENC_POWER_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STDENC_POWER_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STDENC_POWER_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STDENC_POWER_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STDENC_POWER_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STDENC_CID: STDENC_SRC_CID
 */
#define TRACE_STDENC_SRC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STDENC_SRC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STDENC_SRC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STDENC_SRC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STDENC_SRC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STDENC_SRC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STDENC_SRC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STDISP_CID
 */
#define TRACE_STDISP_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STDISP_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STDISP_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STDISP_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STDISP_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STDISP_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STDISP_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STDISP_CID: STDISP_CORE_CID
 */
#define TRACE_STDISP_CORE_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STDISP_CORE_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STDISP_CORE_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STDISP_CORE_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STDISP_CORE_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STDISP_CORE_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STDISP_CORE_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STDISP_CID: STDISP_DISP_PM_CID
 */
#define TRACE_STDISP_DISP_PM_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STDISP_DISP_PM_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STDISP_DISP_PM_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STDISP_DISP_PM_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STDISP_DISP_PM_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STDISP_DISP_PM_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STDISP_DISP_PM_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STDISP_CID: STDISP_DISP_POWER_CID
 */
#define TRACE_STDISP_DISP_POWER_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STDISP_DISP_POWER_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STDISP_DISP_POWER_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STDISP_DISP_POWER_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STDISP_DISP_POWER_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STDISP_DISP_POWER_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STDISP_DISP_POWER_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STDISP_CID: STDISP_SPARE1_CID
 */
#define TRACE_STDISP_SPARE1_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STDISP_SPARE1_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STDISP_SPARE1_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STDISP_SPARE1_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STDISP_SPARE1_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STDISP_SPARE1_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STDISP_SPARE1_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STDISP_CID: STDISP_SPARE2_CID
 */
#define TRACE_STDISP_SPARE2_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STDISP_SPARE2_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STDISP_SPARE2_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STDISP_SPARE2_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STDISP_SPARE2_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STDISP_SPARE2_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STDISP_SPARE2_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STDISP_CID: STDISP_SPARE3_CID
 */
#define TRACE_STDISP_SPARE3_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STDISP_SPARE3_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STDISP_SPARE3_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STDISP_SPARE3_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STDISP_SPARE3_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STDISP_SPARE3_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STDISP_SPARE3_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STDISP_CID: STDISP_SPARE4_CID
 */
#define TRACE_STDISP_SPARE4_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STDISP_SPARE4_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STDISP_SPARE4_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STDISP_SPARE4_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STDISP_SPARE4_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STDISP_SPARE4_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STDISP_SPARE4_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STDISP_CID: STDISP_SRC_CID
 */
#define TRACE_STDISP_SRC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STDISP_SRC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STDISP_SRC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STDISP_SRC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STDISP_SRC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STDISP_SRC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STDISP_SRC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STEVT_CID
 */
#define TRACE_STEVT_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STEVT_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STEVT_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STEVT_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STEVT_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STEVT_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STEVT_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STEVT_CID: STEVT_API_CID
 */
#define TRACE_STEVT_API_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STEVT_API_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STEVT_API_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STEVT_API_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STEVT_API_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STEVT_API_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STEVT_API_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STEVT_CID: STEVT_CORE_CID
 */
#define TRACE_STEVT_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STEVT_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STEVT_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STEVT_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STEVT_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STEVT_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STEVT_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STEVT_CID: STEVT_LINUX_CORE_CID
 */
#define TRACE_STEVT_LINUX_CORE_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STEVT_LINUX_CORE_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STEVT_LINUX_CORE_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STEVT_LINUX_CORE_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STEVT_LINUX_CORE_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STEVT_LINUX_CORE_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STEVT_LINUX_CORE_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STEVT_CID: STEVT_LINUX_IOCTL_CID
 */
#define TRACE_STEVT_LINUX_IOCTL_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STEVT_LINUX_IOCTL_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STEVT_LINUX_IOCTL_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STEVT_LINUX_IOCTL_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STEVT_LINUX_IOCTL_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STEVT_LINUX_IOCTL_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STEVT_LINUX_IOCTL_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STEVT_CID: STEVT_MEM_HANDLER_CID
 */
#define TRACE_STEVT_MEM_HANDLER_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STEVT_MEM_HANDLER_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STEVT_MEM_HANDLER_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STEVT_MEM_HANDLER_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STEVT_MEM_HANDLER_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STEVT_MEM_HANDLER_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STEVT_MEM_HANDLER_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STEVT_CID: STEVT_NOTIFY_CID
 */
#define TRACE_STEVT_NOTIFY_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STEVT_NOTIFY_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STEVT_NOTIFY_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STEVT_NOTIFY_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STEVT_NOTIFY_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STEVT_NOTIFY_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STEVT_NOTIFY_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STEVT_CID: STEVT_SRC_CID
 */
#define TRACE_STEVT_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STEVT_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STEVT_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STEVT_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STEVT_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STEVT_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STEVT_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STEVT_CID: STEVT_SUBSCRIBE_CID
 */
#define TRACE_STEVT_SUBSCRIBE_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STEVT_SUBSCRIBE_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STEVT_SUBSCRIBE_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STEVT_SUBSCRIBE_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STEVT_SUBSCRIBE_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STEVT_SUBSCRIBE_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STEVT_SUBSCRIBE_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STEVT_CID: STEVT_REGISTER_CID
 */
#define TRACE_STEVT_REGISTER_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STEVT_REGISTER_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STEVT_REGISTER_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STEVT_REGISTER_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STEVT_REGISTER_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STEVT_REGISTER_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STEVT_REGISTER_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STEVT_CID: STEVT_EVTRELAY_CID
 */
#define TRACE_STEVT_EVTRELAY_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STEVT_EVTRELAY_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STEVT_EVTRELAY_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STEVT_EVTRELAY_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STEVT_EVTRELAY_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STEVT_EVTRELAY_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STEVT_EVTRELAY_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STEVT_RELAY_CID
 */
#define TRACE_STEVT_RELAY_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STEVT_RELAY_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STEVT_RELAY_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STEVT_RELAY_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STEVT_RELAY_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STEVT_RELAY_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STEVT_RELAY_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STEVT_RELAY_CID : STEVT_RELAY_IPRC_PROXY_CID
 */
#define TRACE_STEVT_RELAY_IPRC_PROXY_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STEVT_RELAY_IPRC_PROXY_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STEVT_RELAY_IPRC_PROXY_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STEVT_RELAY_IPRC_PROXY_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STEVT_RELAY_IPRC_PROXY_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STEVT_RELAY_IPRC_PROXY_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STEVT_RELAY_IPRC_PROXY_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STEVT_RELAY_CID : STEVTRELAY_SRC_CID
 */
#define TRACE_STEVT_RELAY_SRC_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STEVT_RELAY_SRC_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STEVT_RELAY_SRC_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STEVT_RELAY_CID : STEVTRELAY_SRC_CALLBACK_CID
 */
#define TRACE_STEVT_RELAY_SRC_CALLBACK_CID_FATAL_ACTIVATED                    STTRACE_ON
#define TRACE_STEVT_RELAY_SRC_CALLBACK_CID_ERROR_ACTIVATED                    STTRACE_ON
#define TRACE_STEVT_RELAY_SRC_CALLBACK_CID_WARNING_ACTIVATED                  STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_CALLBACK_CID_INFO_ACTIVATED                     STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_CALLBACK_CID_API_IN_ACTIVATED                   STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_CALLBACK_CID_API_OUT_ACTIVATED                  STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_CALLBACK_CID_USER_ACTIVATED                     STTRACE_OFF
/*
 * STEVT_RELAY_CID : STEVTRELAY_SRC_NOTIFY_CID
 */
#define TRACE_STEVT_RELAY_SRC_NOTIFY_CID_FATAL_ACTIVATED                       STTRACE_ON
#define TRACE_STEVT_RELAY_SRC_NOTIFY_CID_ERROR_ACTIVATED                       STTRACE_ON
#define TRACE_STEVT_RELAY_SRC_NOTIFY_CID_WARNING_ACTIVATED                     STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_NOTIFY_CID_INFO_ACTIVATED                        STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_NOTIFY_CID_API_IN_ACTIVATED                      STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_NOTIFY_CID_API_OUT_ACTIVATED                     STTRACE_OFF
#define TRACE_STEVT_RELAY_SRC_NOTIFY_CID_USER_ACTIVATED                        STTRACE_OFF
/*
 * STFDMA_CID
 */
#define TRACE_STFDMA_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STFDMA_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STFDMA_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STFDMA_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STFDMA_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STFDMA_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STFDMA_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_ADD_REGION_CID
 */
#define TRACE_STFDMA_ADD_REGION_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STFDMA_ADD_REGION_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STFDMA_ADD_REGION_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STFDMA_ADD_REGION_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STFDMA_ADD_REGION_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STFDMA_ADD_REGION_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STFDMA_ADD_REGION_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CHANNEL_CID
 */
#define TRACE_STFDMA_CHANNEL_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STFDMA_CHANNEL_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STFDMA_CHANNEL_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STFDMA_CHANNEL_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STFDMA_CHANNEL_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STFDMA_CHANNEL_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STFDMA_CHANNEL_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_ALLOC_DEALLOC_CID
 */
#define TRACE_STFDMA_CONTEXT_ALLOC_DEALLOC_CID_FATAL_ACTIVATED                STTRACE_ON
#define TRACE_STFDMA_CONTEXT_ALLOC_DEALLOC_CID_ERROR_ACTIVATED                STTRACE_ON
#define TRACE_STFDMA_CONTEXT_ALLOC_DEALLOC_CID_WARNING_ACTIVATED              STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_ALLOC_DEALLOC_CID_INFO_ACTIVATED                 STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_ALLOC_DEALLOC_CID_API_IN_ACTIVATED               STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_ALLOC_DEALLOC_CID_API_OUT_ACTIVATED              STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_ALLOC_DEALLOC_CID_USER_ACTIVATED                 STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_GET_CID
 */
#define TRACE_STFDMA_CONTEXT_GET_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STFDMA_CONTEXT_GET_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STFDMA_CONTEXT_GET_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_GET_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_GET_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_GET_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_GET_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_INIT_TERM_CID
 */
#define TRACE_STFDMA_CONTEXT_INIT_TERM_CID_FATAL_ACTIVATED                    STTRACE_ON
#define TRACE_STFDMA_CONTEXT_INIT_TERM_CID_ERROR_ACTIVATED                    STTRACE_ON
#define TRACE_STFDMA_CONTEXT_INIT_TERM_CID_WARNING_ACTIVATED                  STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_INIT_TERM_CID_INFO_ACTIVATED                     STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_INIT_TERM_CID_API_IN_ACTIVATED                   STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_INIT_TERM_CID_API_OUT_ACTIVATED                  STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_INIT_TERM_CID_USER_ACTIVATED                     STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_SECURED_GET_CID
 */
#define TRACE_STFDMA_CONTEXT_SECURED_GET_CID_FATAL_ACTIVATED                  STTRACE_ON
#define TRACE_STFDMA_CONTEXT_SECURED_GET_CID_ERROR_ACTIVATED                  STTRACE_ON
#define TRACE_STFDMA_CONTEXT_SECURED_GET_CID_WARNING_ACTIVATED                STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SECURED_GET_CID_INFO_ACTIVATED                   STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SECURED_GET_CID_API_IN_ACTIVATED                 STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SECURED_GET_CID_API_OUT_ACTIVATED                STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SECURED_GET_CID_USER_ACTIVATED                   STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_SECURED_SET_CID
 */
#define TRACE_STFDMA_CONTEXT_SECURED_SET_CID_FATAL_ACTIVATED                  STTRACE_ON
#define TRACE_STFDMA_CONTEXT_SECURED_SET_CID_ERROR_ACTIVATED                  STTRACE_ON
#define TRACE_STFDMA_CONTEXT_SECURED_SET_CID_WARNING_ACTIVATED                STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SECURED_SET_CID_INFO_ACTIVATED                   STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SECURED_SET_CID_API_IN_ACTIVATED                 STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SECURED_SET_CID_API_OUT_ACTIVATED                STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SECURED_SET_CID_USER_ACTIVATED                   STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_SET_CID
 */
#define TRACE_STFDMA_CONTEXT_SET_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STFDMA_CONTEXT_SET_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STFDMA_CONTEXT_SET_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SET_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SET_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SET_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_SET_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_VIRTUAL_ALLOC_DEALLOC_CID
 */
#define TRACE_STFDMA_CONTEXT_VIRTUAL_ALLOC_DEALLOC_CID_FATAL_ACTIVATED        STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_ALLOC_DEALLOC_CID_ERROR_ACTIVATED        STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_ALLOC_DEALLOC_CID_WARNING_ACTIVATED      STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_ALLOC_DEALLOC_CID_INFO_ACTIVATED         STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_ALLOC_DEALLOC_CID_API_IN_ACTIVATED       STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_ALLOC_DEALLOC_CID_API_OUT_ACTIVATED      STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_ALLOC_DEALLOC_CID_USER_ACTIVATED         STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_VIRTUAL_GET_CID
 */
#define TRACE_STFDMA_CONTEXT_VIRTUAL_GET_CID_FATAL_ACTIVATED                  STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_GET_CID_ERROR_ACTIVATED                  STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_GET_CID_WARNING_ACTIVATED                STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_GET_CID_INFO_ACTIVATED                   STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_GET_CID_API_IN_ACTIVATED                 STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_GET_CID_API_OUT_ACTIVATED                STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_GET_CID_USER_ACTIVATED                   STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_VIRTUAL_SAVE_RESTORE_CID
 */
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SAVE_RESTORE_CID_FATAL_ACTIVATED         STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SAVE_RESTORE_CID_ERROR_ACTIVATED         STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SAVE_RESTORE_CID_WARNING_ACTIVATED       STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SAVE_RESTORE_CID_INFO_ACTIVATED          STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SAVE_RESTORE_CID_API_IN_ACTIVATED        STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SAVE_RESTORE_CID_API_OUT_ACTIVATED       STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SAVE_RESTORE_CID_USER_ACTIVATED          STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_VIRTUAL_SECURED_GET_CID
 */
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_GET_CID_FATAL_ACTIVATED          STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_GET_CID_ERROR_ACTIVATED          STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_GET_CID_WARNING_ACTIVATED        STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_GET_CID_INFO_ACTIVATED           STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_GET_CID_API_IN_ACTIVATED         STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_GET_CID_API_OUT_ACTIVATED        STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_GET_CID_USER_ACTIVATED           STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_VIRTUAL_SECURED_SET_CID
 */
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_SET_CID_FATAL_ACTIVATED          STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_SET_CID_ERROR_ACTIVATED          STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_SET_CID_WARNING_ACTIVATED        STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_SET_CID_INFO_ACTIVATED           STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_SET_CID_API_IN_ACTIVATED         STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_SET_CID_API_OUT_ACTIVATED        STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SECURED_SET_CID_USER_ACTIVATED           STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_CONTEXT_VIRTUAL_SET_CID
 */
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SET_CID_FATAL_ACTIVATED                  STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SET_CID_ERROR_ACTIVATED                  STTRACE_ON
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SET_CID_WARNING_ACTIVATED                STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SET_CID_INFO_ACTIVATED                   STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SET_CID_API_IN_ACTIVATED                 STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SET_CID_API_OUT_ACTIVATED                STTRACE_OFF
#define TRACE_STFDMA_CONTEXT_VIRTUAL_SET_CID_USER_ACTIVATED                   STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_DMEM_REG_CID
 */
#define TRACE_STFDMA_DMEM_REG_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STFDMA_DMEM_REG_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STFDMA_DMEM_REG_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_DMEM_REG_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STFDMA_DMEM_REG_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STFDMA_DMEM_REG_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_DMEM_REG_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_GENERIC_CID
 */
#define TRACE_STFDMA_GENERIC_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STFDMA_GENERIC_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STFDMA_GENERIC_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STFDMA_GENERIC_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STFDMA_GENERIC_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STFDMA_GENERIC_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STFDMA_GENERIC_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_INIT_TERM_CID
 */
#define TRACE_STFDMA_INIT_TERM_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STFDMA_INIT_TERM_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STFDMA_INIT_TERM_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STFDMA_INIT_TERM_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STFDMA_INIT_TERM_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_INIT_TERM_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STFDMA_INIT_TERM_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_LINUX_CORE_CID
 */
#define TRACE_STFDMA_LINUX_CORE_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STFDMA_LINUX_CORE_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STFDMA_LINUX_CORE_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STFDMA_LINUX_CORE_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STFDMA_LINUX_CORE_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STFDMA_LINUX_CORE_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STFDMA_LINUX_CORE_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_LINUX_IOCTL_CID
 */
#define TRACE_STFDMA_LINUX_IOCTL_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STFDMA_LINUX_IOCTL_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STFDMA_LINUX_IOCTL_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STFDMA_LINUX_IOCTL_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_LINUX_IOCTL_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STFDMA_LINUX_IOCTL_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STFDMA_LINUX_IOCTL_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_PACED_CID
 */
#define TRACE_STFDMA_PACED_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STFDMA_PACED_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STFDMA_PACED_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STFDMA_PACED_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STFDMA_PACED_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STFDMA_PACED_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STFDMA_PACED_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_POWER_CID
 */
#define TRACE_STFDMA_POWER_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STFDMA_POWER_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STFDMA_POWER_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STFDMA_POWER_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STFDMA_POWER_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STFDMA_POWER_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STFDMA_POWER_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_REVISION_CID
 */
#define TRACE_STFDMA_REVISION_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STFDMA_REVISION_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STFDMA_REVISION_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_REVISION_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STFDMA_REVISION_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STFDMA_REVISION_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_REVISION_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_STATUS_CID
 */
#define TRACE_STFDMA_STATUS_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STFDMA_STATUS_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STFDMA_STATUS_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STFDMA_STATUS_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STFDMA_STATUS_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STFDMA_STATUS_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STFDMA_STATUS_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STFDMA_CID: STFDMA_TRANSFER_CID
 */
#define TRACE_STFDMA_TRANSFER_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STFDMA_TRANSFER_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STFDMA_TRANSFER_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_TRANSFER_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STFDMA_TRANSFER_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STFDMA_TRANSFER_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STFDMA_TRANSFER_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STFLASH_CID
 */
#define TRACE_STFLASH_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STFLASH_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STFLASH_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STFLASH_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STFLASH_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STFLASH_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STFLASH_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_API_CID
 */
#define TRACE_STFLASH_API_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STFLASH_API_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STFLASH_API_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STFLASH_API_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STFLASH_API_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STFLASH_API_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STFLASH_API_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_HALATMEL_CID
 */
#define TRACE_STFLASH_HALATMEL_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STFLASH_HALATMEL_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STFLASH_HALATMEL_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STFLASH_HALATMEL_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_HALATMEL_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STFLASH_HALATMEL_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STFLASH_HALATMEL_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_HALM28_CID
 */
#define TRACE_STFLASH_HALM28_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STFLASH_HALM28_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STFLASH_HALM28_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STFLASH_HALM28_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STFLASH_HALM28_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_HALM28_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STFLASH_HALM28_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_HALM29_CID
 */
#define TRACE_STFLASH_HALM29_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STFLASH_HALM29_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STFLASH_HALM29_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STFLASH_HALM29_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STFLASH_HALM29_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_HALM29_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STFLASH_HALM29_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_HALP0_CID
 */
#define TRACE_STFLASH_HALP0_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STFLASH_HALP0_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STFLASH_HALP0_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_HALP0_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STFLASH_HALP0_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STFLASH_HALP0_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_HALP0_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_HALSPIBOOT_CID
 */
#define TRACE_STFLASH_HALSPIBOOT_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STFLASH_HALSPIBOOT_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STFLASH_HALSPIBOOT_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STFLASH_HALSPIBOOT_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STFLASH_HALSPIBOOT_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STFLASH_HALSPIBOOT_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STFLASH_HALSPIBOOT_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_HALSPISEQUENCE_CID
 */
#define TRACE_STFLASH_HALSPISEQUENCE_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STFLASH_HALSPISEQUENCE_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STFLASH_HALSPISEQUENCE_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STFLASH_HALSPISEQUENCE_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STFLASH_HALSPISEQUENCE_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STFLASH_HALSPISEQUENCE_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STFLASH_HALSPISEQUENCE_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_HALSPI_CID
 */
#define TRACE_STFLASH_HALSPI_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STFLASH_HALSPI_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STFLASH_HALSPI_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STFLASH_HALSPI_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STFLASH_HALSPI_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_HALSPI_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STFLASH_HALSPI_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_HALUTILS_CID
 */
#define TRACE_STFLASH_HALUTILS_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STFLASH_HALUTILS_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STFLASH_HALUTILS_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STFLASH_HALUTILS_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_HALUTILS_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STFLASH_HALUTILS_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STFLASH_HALUTILS_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_POWER_CID
 */
#define TRACE_STFLASH_POWER_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STFLASH_POWER_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STFLASH_POWER_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_POWER_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STFLASH_POWER_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STFLASH_POWER_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_POWER_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STFLASH_CID: STFLASH_UTILS_CID
 */
#define TRACE_STFLASH_UTILS_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STFLASH_UTILS_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STFLASH_UTILS_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_UTILS_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STFLASH_UTILS_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STFLASH_UTILS_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STFLASH_UTILS_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STFRONTEND_CID
 */
#define TRACE_STFRONTEND_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STFRONTEND_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STFRONTEND_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STFRONTEND_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STFRONTEND_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STFRONTEND_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STFRONTEND_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_CHIP_CID
 */
#define TRACE_STFRONTEND_CHIP_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STFRONTEND_CHIP_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STFRONTEND_CHIP_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STFRONTEND_CHIP_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STFRONTEND_CHIP_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STFRONTEND_CHIP_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STFRONTEND_CHIP_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_CAB_DEMOD_CID
 */
#define TRACE_STFRONTEND_DRIVERS_CAB_DEMOD_CID_FATAL_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_CAB_DEMOD_CID_ERROR_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_CAB_DEMOD_CID_WARNING_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_CAB_DEMOD_CID_INFO_ACTIVATED                 STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_CAB_DEMOD_CID_API_IN_ACTIVATED               STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_CAB_DEMOD_CID_API_OUT_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_CAB_DEMOD_CID_USER_ACTIVATED                 STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_CAB_TUNER_CID
 */
#define TRACE_STFRONTEND_DRIVERS_CAB_TUNER_CID_FATAL_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_CAB_TUNER_CID_ERROR_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_CAB_TUNER_CID_WARNING_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_CAB_TUNER_CID_INFO_ACTIVATED                 STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_CAB_TUNER_CID_API_IN_ACTIVATED               STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_CAB_TUNER_CID_API_OUT_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_CAB_TUNER_CID_USER_ACTIVATED                 STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_SAT_DEMOD_CID
 */
#define TRACE_STFRONTEND_DRIVERS_SAT_DEMOD_CID_FATAL_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SAT_DEMOD_CID_ERROR_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SAT_DEMOD_CID_WARNING_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_DEMOD_CID_INFO_ACTIVATED                 STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_DEMOD_CID_API_IN_ACTIVATED               STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_DEMOD_CID_API_OUT_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_DEMOD_CID_USER_ACTIVATED                 STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_SAT_LNB_CID
 */
#define TRACE_STFRONTEND_DRIVERS_SAT_LNB_CID_FATAL_ACTIVATED                  STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SAT_LNB_CID_ERROR_ACTIVATED                  STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SAT_LNB_CID_WARNING_ACTIVATED                STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_LNB_CID_INFO_ACTIVATED                   STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_LNB_CID_API_IN_ACTIVATED                 STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_LNB_CID_API_OUT_ACTIVATED                STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_LNB_CID_USER_ACTIVATED                   STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_SAT_SCR_CID
 */
#define TRACE_STFRONTEND_DRIVERS_SAT_SCR_CID_FATAL_ACTIVATED                  STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SAT_SCR_CID_ERROR_ACTIVATED                  STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SAT_SCR_CID_WARNING_ACTIVATED                STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_SCR_CID_INFO_ACTIVATED                   STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_SCR_CID_API_IN_ACTIVATED                 STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_SCR_CID_API_OUT_ACTIVATED                STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_SCR_CID_USER_ACTIVATED                   STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_SAT_TUNER_CID
 */
#define TRACE_STFRONTEND_DRIVERS_SAT_TUNER_CID_FATAL_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SAT_TUNER_CID_ERROR_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SAT_TUNER_CID_WARNING_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_TUNER_CID_INFO_ACTIVATED                 STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_TUNER_CID_API_IN_ACTIVATED               STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_TUNER_CID_API_OUT_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SAT_TUNER_CID_USER_ACTIVATED                 STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_SHARED_TUNER_CID
 */
#define TRACE_STFRONTEND_DRIVERS_SHARED_TUNER_CID_FATAL_ACTIVATED             STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SHARED_TUNER_CID_ERROR_ACTIVATED             STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_SHARED_TUNER_CID_WARNING_ACTIVATED           STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SHARED_TUNER_CID_INFO_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SHARED_TUNER_CID_API_IN_ACTIVATED            STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SHARED_TUNER_CID_API_OUT_ACTIVATED           STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_SHARED_TUNER_CID_USER_ACTIVATED              STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_TER_DEMOD_CID
 */
#define TRACE_STFRONTEND_DRIVERS_TER_DEMOD_CID_FATAL_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_TER_DEMOD_CID_ERROR_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_TER_DEMOD_CID_WARNING_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_TER_DEMOD_CID_INFO_ACTIVATED                 STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_TER_DEMOD_CID_API_IN_ACTIVATED               STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_TER_DEMOD_CID_API_OUT_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_TER_DEMOD_CID_USER_ACTIVATED                 STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_TER_TUNER_CID
 */
#define TRACE_STFRONTEND_DRIVERS_TER_TUNER_CID_FATAL_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_TER_TUNER_CID_ERROR_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_TER_TUNER_CID_WARNING_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_TER_TUNER_CID_INFO_ACTIVATED                 STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_TER_TUNER_CID_API_IN_ACTIVATED               STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_TER_TUNER_CID_API_OUT_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_TER_TUNER_CID_USER_ACTIVATED                 STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_DRIVERS_VSB_DEMOD_CID
 */
#define TRACE_STFRONTEND_DRIVERS_VSB_DEMOD_CID_FATAL_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_VSB_DEMOD_CID_ERROR_ACTIVATED                STTRACE_ON
#define TRACE_STFRONTEND_DRIVERS_VSB_DEMOD_CID_WARNING_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_VSB_DEMOD_CID_INFO_ACTIVATED                 STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_VSB_DEMOD_CID_API_IN_ACTIVATED               STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_VSB_DEMOD_CID_API_OUT_ACTIVATED              STTRACE_OFF
#define TRACE_STFRONTEND_DRIVERS_VSB_DEMOD_CID_USER_ACTIVATED                 STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_EXT_DEMOD_CID
 */
#define TRACE_STFRONTEND_EXT_DEMOD_CID_FATAL_ACTIVATED                        STTRACE_ON
#define TRACE_STFRONTEND_EXT_DEMOD_CID_ERROR_ACTIVATED                        STTRACE_ON
#define TRACE_STFRONTEND_EXT_DEMOD_CID_WARNING_ACTIVATED                      STTRACE_OFF
#define TRACE_STFRONTEND_EXT_DEMOD_CID_INFO_ACTIVATED                         STTRACE_OFF
#define TRACE_STFRONTEND_EXT_DEMOD_CID_API_IN_ACTIVATED                       STTRACE_OFF
#define TRACE_STFRONTEND_EXT_DEMOD_CID_API_OUT_ACTIVATED                      STTRACE_OFF
#define TRACE_STFRONTEND_EXT_DEMOD_CID_USER_ACTIVATED                         STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_EXT_TUNER_CID
 */
#define TRACE_STFRONTEND_EXT_TUNER_CID_FATAL_ACTIVATED                        STTRACE_ON
#define TRACE_STFRONTEND_EXT_TUNER_CID_ERROR_ACTIVATED                        STTRACE_ON
#define TRACE_STFRONTEND_EXT_TUNER_CID_WARNING_ACTIVATED                      STTRACE_OFF
#define TRACE_STFRONTEND_EXT_TUNER_CID_INFO_ACTIVATED                         STTRACE_OFF
#define TRACE_STFRONTEND_EXT_TUNER_CID_API_IN_ACTIVATED                       STTRACE_OFF
#define TRACE_STFRONTEND_EXT_TUNER_CID_API_OUT_ACTIVATED                      STTRACE_OFF
#define TRACE_STFRONTEND_EXT_TUNER_CID_USER_ACTIVATED                         STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_MANAGER_CAB_CID
 */
#define TRACE_STFRONTEND_MANAGER_CAB_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_CAB_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_CAB_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_CAB_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_CAB_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_CAB_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_CAB_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_MANAGER_CID
 */
#define TRACE_STFRONTEND_MANAGER_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_MANAGER_SAT_CID
 */
#define TRACE_STFRONTEND_MANAGER_SAT_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_SAT_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_SAT_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_SAT_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_SAT_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_SAT_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_SAT_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_MANAGER_TER_CID
 */
#define TRACE_STFRONTEND_MANAGER_TER_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_TER_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_TER_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_TER_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_TER_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_TER_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_TER_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STFRONTEND_CID: STFRONTEND_MANAGER_VSB_CID
 */
#define TRACE_STFRONTEND_MANAGER_VSB_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_VSB_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STFRONTEND_MANAGER_VSB_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_VSB_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_VSB_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_VSB_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STFRONTEND_MANAGER_VSB_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STFSK_CID
 */
#define TRACE_STFSK_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STFSK_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STFSK_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STFSK_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STFSK_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STFSK_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STFSK_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STGFB_CID
 */
#define TRACE_STGFB_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STGFB_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STGFB_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STGFB_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STGFB_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STGFB_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STGFB_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STGFB_CID: STGFB_BLIT_ACCEL_CID
 */
#define TRACE_STGFB_BLIT_ACCEL_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STGFB_BLIT_ACCEL_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STGFB_BLIT_ACCEL_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STGFB_BLIT_ACCEL_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STGFB_BLIT_ACCEL_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STGFB_BLIT_ACCEL_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STGFB_BLIT_ACCEL_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STGFB_CID: STGFB_CONTROL_CID
 */
#define TRACE_STGFB_CONTROL_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STGFB_CONTROL_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STGFB_CONTROL_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STGFB_CONTROL_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STGFB_CONTROL_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STGFB_CONTROL_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STGFB_CONTROL_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STGFB_CID: STGFB_CORE_CID
 */
#define TRACE_STGFB_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STGFB_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STGFB_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STGFB_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STGFB_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STGFB_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STGFB_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STGFB_CID: STGFB_IOCTL_CID
 */
#define TRACE_STGFB_IOCTL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STGFB_IOCTL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STGFB_IOCTL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STGFB_IOCTL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STGFB_IOCTL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STGFB_IOCTL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STGFB_IOCTL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STGFB_CID: STGFB_SPARE1_CID
 */
#define TRACE_STGFB_SPARE1_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STGFB_SPARE1_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STGFB_SPARE1_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STGFB_SPARE1_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STGFB_SPARE1_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STGFB_SPARE1_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STGFB_SPARE1_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STGFB_CID: STGFB_SPARE2_CID
 */
#define TRACE_STGFB_SPARE2_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STGFB_SPARE2_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STGFB_SPARE2_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STGFB_SPARE2_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STGFB_SPARE2_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STGFB_SPARE2_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STGFB_SPARE2_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STGFB_CID: STGFB_SPARE3_CID
 */
#define TRACE_STGFB_SPARE3_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STGFB_SPARE3_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STGFB_SPARE3_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STGFB_SPARE3_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STGFB_SPARE3_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STGFB_SPARE3_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STGFB_SPARE3_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STGFB_CID: STGFB_SPARE4_CID
 */
#define TRACE_STGFB_SPARE4_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STGFB_SPARE4_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STGFB_SPARE4_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STGFB_SPARE4_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STGFB_SPARE4_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STGFB_SPARE4_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STGFB_SPARE4_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STHDMI_CID
 */
#define TRACE_STHDMI_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STHDMI_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STHDMI_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STHDMI_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STHDMI_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STHDMI_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STHDMI_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STHDMI_CID: STHDMI_CORE_CID
 */
#define TRACE_STHDMI_CORE_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STHDMI_CORE_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STHDMI_CORE_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STHDMI_CORE_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STHDMI_CORE_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STHDMI_CORE_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STHDMI_CORE_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STHDMI_CID: STHDMI_IOCTL_CID
 */
#define TRACE_STHDMI_IOCTL_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STHDMI_IOCTL_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STHDMI_IOCTL_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STHDMI_IOCTL_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STHDMI_IOCTL_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STHDMI_IOCTL_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STHDMI_IOCTL_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STHDMI_CID: STHDMI_SPARE1_CID
 */
#define TRACE_STHDMI_SPARE1_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STHDMI_SPARE1_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STHDMI_SPARE1_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STHDMI_SPARE1_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STHDMI_SPARE1_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STHDMI_SPARE1_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STHDMI_SPARE1_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STHDMI_CID: STHDMI_SPARE2_CID
 */
#define TRACE_STHDMI_SPARE2_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STHDMI_SPARE2_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STHDMI_SPARE2_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STHDMI_SPARE2_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STHDMI_SPARE2_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STHDMI_SPARE2_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STHDMI_SPARE2_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STHDMI_CID: STHDMI_SPARE3_CID
 */
#define TRACE_STHDMI_SPARE3_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STHDMI_SPARE3_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STHDMI_SPARE3_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STHDMI_SPARE3_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STHDMI_SPARE3_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STHDMI_SPARE3_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STHDMI_SPARE3_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STHDMI_CID: STHDMI_SPARE4_CID
 */
#define TRACE_STHDMI_SPARE4_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STHDMI_SPARE4_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STHDMI_SPARE4_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STHDMI_SPARE4_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STHDMI_SPARE4_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STHDMI_SPARE4_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STHDMI_SPARE4_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STHDMI_CID: STHDMI_SRC_CID
 */
#define TRACE_STHDMI_SRC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STHDMI_SRC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STHDMI_SRC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STHDMI_SRC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STHDMI_SRC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STHDMI_SRC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STHDMI_SRC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STI2C_CID
 */
#define TRACE_STI2C_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STI2C_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STI2C_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STI2C_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STI2C_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STI2C_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STI2C_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STI2C_CID: STI2C_CORE_CID
 */
#define TRACE_STI2C_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STI2C_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STI2C_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STI2C_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STI2C_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STI2C_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STI2C_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STI2C_CID: STI2C_IOCTL_CID
 */
#define TRACE_STI2C_IOCTL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STI2C_IOCTL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STI2C_IOCTL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STI2C_IOCTL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STI2C_IOCTL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STI2C_IOCTL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STI2C_IOCTL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STI2C_CID: STI2C_SPARE1_CID
 */
#define TRACE_STI2C_SPARE1_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STI2C_SPARE1_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STI2C_SPARE1_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STI2C_SPARE1_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STI2C_SPARE1_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STI2C_SPARE1_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STI2C_SPARE1_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STI2C_CID: STI2C_SPARE2_CID
 */
#define TRACE_STI2C_SPARE2_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STI2C_SPARE2_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STI2C_SPARE2_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STI2C_SPARE2_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STI2C_SPARE2_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STI2C_SPARE2_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STI2C_SPARE2_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STI2C_CID: STI2C_SPARE3_CID
 */
#define TRACE_STI2C_SPARE3_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STI2C_SPARE3_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STI2C_SPARE3_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STI2C_SPARE3_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STI2C_SPARE3_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STI2C_SPARE3_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STI2C_SPARE3_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STI2C_CID: STI2C_SPARE4_CID
 */
#define TRACE_STI2C_SPARE4_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STI2C_SPARE4_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STI2C_SPARE4_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STI2C_SPARE4_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STI2C_SPARE4_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STI2C_SPARE4_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STI2C_SPARE4_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STI2C_CID: STI2C_SRC_CID
 */
#define TRACE_STI2C_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STI2C_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STI2C_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STI2C_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STI2C_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STI2C_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STI2C_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STINJECT_CID
 */
#define TRACE_STINJECT_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STINJECT_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STINJECT_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_STINJECT_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_STINJECT_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_STINJECT_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_STINJECT_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_BUFFER_CPU_CID
 */
#define TRACE_STINJECT_BUFFER_CPU_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STINJECT_BUFFER_CPU_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STINJECT_BUFFER_CPU_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STINJECT_BUFFER_CPU_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STINJECT_BUFFER_CPU_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STINJECT_BUFFER_CPU_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STINJECT_BUFFER_CPU_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_BUFFER_FDMA_CID
 */
#define TRACE_STINJECT_BUFFER_FDMA_CID_FATAL_ACTIVATED                        STTRACE_ON
#define TRACE_STINJECT_BUFFER_FDMA_CID_ERROR_ACTIVATED                        STTRACE_ON
#define TRACE_STINJECT_BUFFER_FDMA_CID_WARNING_ACTIVATED                      STTRACE_OFF
#define TRACE_STINJECT_BUFFER_FDMA_CID_INFO_ACTIVATED                         STTRACE_OFF
#define TRACE_STINJECT_BUFFER_FDMA_CID_API_IN_ACTIVATED                       STTRACE_OFF
#define TRACE_STINJECT_BUFFER_FDMA_CID_API_OUT_ACTIVATED                      STTRACE_OFF
#define TRACE_STINJECT_BUFFER_FDMA_CID_USER_ACTIVATED                         STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_FIFO_CPU_CID
 */
#define TRACE_STINJECT_FIFO_CPU_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STINJECT_FIFO_CPU_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STINJECT_FIFO_CPU_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STINJECT_FIFO_CPU_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STINJECT_FIFO_CPU_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STINJECT_FIFO_CPU_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STINJECT_FIFO_CPU_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_FIFO_FDMA_CID
 */
#define TRACE_STINJECT_FIFO_FDMA_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STINJECT_FIFO_FDMA_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STINJECT_FIFO_FDMA_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STINJECT_FIFO_FDMA_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STINJECT_FIFO_FDMA_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STINJECT_FIFO_FDMA_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STINJECT_FIFO_FDMA_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_IPRC_PROXY_CID
 */
#define TRACE_STINJECT_IPRC_PROXY_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STINJECT_IPRC_PROXY_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STINJECT_IPRC_PROXY_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STINJECT_IPRC_PROXY_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STINJECT_IPRC_PROXY_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STINJECT_IPRC_PROXY_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STINJECT_IPRC_PROXY_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_IPRC_STUB_CID
 */
#define TRACE_STINJECT_IPRC_STUB_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STINJECT_IPRC_STUB_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STINJECT_IPRC_STUB_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STINJECT_IPRC_STUB_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STINJECT_IPRC_STUB_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STINJECT_IPRC_STUB_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STINJECT_IPRC_STUB_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_LINUX_CORE_CID
 */
#define TRACE_STINJECT_LINUX_CORE_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STINJECT_LINUX_CORE_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STINJECT_LINUX_CORE_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STINJECT_LINUX_CORE_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STINJECT_LINUX_CORE_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STINJECT_LINUX_CORE_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STINJECT_LINUX_CORE_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_LINUX_IOCTL_CID
 */
#define TRACE_STINJECT_LINUX_IOCTL_CID_FATAL_ACTIVATED                        STTRACE_ON
#define TRACE_STINJECT_LINUX_IOCTL_CID_ERROR_ACTIVATED                        STTRACE_ON
#define TRACE_STINJECT_LINUX_IOCTL_CID_WARNING_ACTIVATED                      STTRACE_OFF
#define TRACE_STINJECT_LINUX_IOCTL_CID_INFO_ACTIVATED                         STTRACE_OFF
#define TRACE_STINJECT_LINUX_IOCTL_CID_API_IN_ACTIVATED                       STTRACE_OFF
#define TRACE_STINJECT_LINUX_IOCTL_CID_API_OUT_ACTIVATED                      STTRACE_OFF
#define TRACE_STINJECT_LINUX_IOCTL_CID_USER_ACTIVATED                         STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_LINUX_PROXY_CID
 */
#define TRACE_STINJECT_LINUX_PROXY_CID_FATAL_ACTIVATED                        STTRACE_ON
#define TRACE_STINJECT_LINUX_PROXY_CID_ERROR_ACTIVATED                        STTRACE_ON
#define TRACE_STINJECT_LINUX_PROXY_CID_WARNING_ACTIVATED                      STTRACE_OFF
#define TRACE_STINJECT_LINUX_PROXY_CID_INFO_ACTIVATED                         STTRACE_OFF
#define TRACE_STINJECT_LINUX_PROXY_CID_API_IN_ACTIVATED                       STTRACE_OFF
#define TRACE_STINJECT_LINUX_PROXY_CID_API_OUT_ACTIVATED                      STTRACE_OFF
#define TRACE_STINJECT_LINUX_PROXY_CID_USER_ACTIVATED                         STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_NODE_CID
 */
#define TRACE_STINJECT_NODE_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STINJECT_NODE_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STINJECT_NODE_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STINJECT_NODE_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STINJECT_NODE_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STINJECT_NODE_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STINJECT_NODE_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_POWER_CID
 */
#define TRACE_STINJECT_POWER_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STINJECT_POWER_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STINJECT_POWER_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STINJECT_POWER_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STINJECT_POWER_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STINJECT_POWER_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STINJECT_POWER_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_PTI5_CID
 */
#define TRACE_STINJECT_PTI5_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STINJECT_PTI5_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STINJECT_PTI5_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STINJECT_PTI5_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STINJECT_PTI5_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STINJECT_PTI5_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STINJECT_PTI5_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STINJECT_CID: STINJECT_SRC_CID
 */
#define TRACE_STINJECT_SRC_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STINJECT_SRC_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STINJECT_SRC_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STINJECT_SRC_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STINJECT_SRC_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STINJECT_SRC_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STINJECT_SRC_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STIPRC_CID
 */
#define TRACE_STIPRC_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STIPRC_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STIPRC_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STIPRC_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STIPRC_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STIPRC_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STIPRC_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STIPRC_CID: STIPRC_INIT_TERM_CID
 */
#define TRACE_STIPRC_INIT_TERM_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STIPRC_INIT_TERM_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STIPRC_INIT_TERM_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STIPRC_INIT_TERM_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STIPRC_INIT_TERM_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STIPRC_INIT_TERM_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STIPRC_INIT_TERM_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STIPRC_CID: STIPRC_MAPPING_CID
 */
#define TRACE_STIPRC_MAPPING_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STIPRC_MAPPING_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STIPRC_MAPPING_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STIPRC_MAPPING_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STIPRC_MAPPING_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STIPRC_MAPPING_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STIPRC_MAPPING_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STIPRC_CID: STIPRC_PROXY_CID
 */
#define TRACE_STIPRC_PROXY_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STIPRC_PROXY_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STIPRC_PROXY_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STIPRC_PROXY_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STIPRC_PROXY_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STIPRC_PROXY_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STIPRC_PROXY_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STIPRC_CID: STIPRC_STUB_CID
 */
#define TRACE_STIPRC_STUB_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STIPRC_STUB_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STIPRC_STUB_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STIPRC_STUB_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STIPRC_STUB_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STIPRC_STUB_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STIPRC_STUB_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STKEYSCN_CID
 */
#define TRACE_STKEYSCN_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STKEYSCN_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STKEYSCN_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_STKEYSCN_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_STKEYSCN_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_STKEYSCN_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_STKEYSCN_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
 * STKEYSCN_CID: STKEYSCN_API_CID
 */
#define TRACE_STKEYSCN_API_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STKEYSCN_API_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STKEYSCN_API_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STKEYSCN_API_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STKEYSCN_API_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STKEYSCN_API_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STKEYSCN_API_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STKEYSCN_CID: STKEYSCN_BUFFER_CID
 */
#define TRACE_STKEYSCN_BUFFER_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STKEYSCN_BUFFER_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STKEYSCN_BUFFER_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STKEYSCN_BUFFER_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STKEYSCN_BUFFER_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STKEYSCN_BUFFER_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STKEYSCN_BUFFER_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STKEYSCN_CID: STKEYSCN_CORE_CID
 */
#define TRACE_STKEYSCN_CORE_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STKEYSCN_CORE_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STKEYSCN_CORE_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STKEYSCN_CORE_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STKEYSCN_CORE_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STKEYSCN_CORE_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STKEYSCN_CORE_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STKEYSCN_CID: STKEYSCN_INT_CID
 */
#define TRACE_STKEYSCN_INT_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STKEYSCN_INT_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STKEYSCN_INT_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STKEYSCN_INT_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STKEYSCN_INT_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STKEYSCN_INT_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STKEYSCN_INT_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STKEYSCN_CID: STKEYSCN_IOCTL_CID
 */
#define TRACE_STKEYSCN_IOCTL_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STKEYSCN_IOCTL_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STKEYSCN_IOCTL_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STKEYSCN_IOCTL_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STKEYSCN_IOCTL_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STKEYSCN_IOCTL_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STKEYSCN_IOCTL_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STKEYSCN_CID: STKEYSCN_UTILS_CID
 */
#define TRACE_STKEYSCN_UTILS_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STKEYSCN_UTILS_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STKEYSCN_UTILS_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STKEYSCN_UTILS_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STKEYSCN_UTILS_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STKEYSCN_UTILS_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STKEYSCN_UTILS_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STLAYER_CID
 */
#define TRACE_STLAYER_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STLAYER_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STLAYER_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STLAYER_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STLAYER_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STLAYER_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STLAYER_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_API_CID
 */
#define TRACE_STLAYER_API_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STLAYER_API_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STLAYER_API_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STLAYER_API_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STLAYER_API_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STLAYER_API_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STLAYER_API_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_CORE_CID
 */
#define TRACE_STLAYER_CORE_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STLAYER_CORE_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STLAYER_CORE_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STLAYER_CORE_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STLAYER_CORE_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STLAYER_CORE_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STLAYER_CORE_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_GRAPHICS_CID
 */
#define TRACE_STLAYER_GRAPHICS_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STLAYER_GRAPHICS_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STLAYER_GRAPHICS_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STLAYER_GRAPHICS_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_GRAPHICS_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STLAYER_GRAPHICS_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STLAYER_GRAPHICS_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_IOCTL_CID
 */
#define TRACE_STLAYER_IOCTL_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STLAYER_IOCTL_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STLAYER_IOCTL_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_IOCTL_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STLAYER_IOCTL_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STLAYER_IOCTL_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_IOCTL_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_LAYCOMPO_CID
 */
#define TRACE_STLAYER_LAYCOMPO_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STLAYER_LAYCOMPO_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STLAYER_LAYCOMPO_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STLAYER_LAYCOMPO_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_LAYCOMPO_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STLAYER_LAYCOMPO_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STLAYER_LAYCOMPO_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_POWER_CID
 */
#define TRACE_STLAYER_POWER_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STLAYER_POWER_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STLAYER_POWER_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_POWER_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STLAYER_POWER_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STLAYER_POWER_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_POWER_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_SPARE1_CID
 */
#define TRACE_STLAYER_SPARE1_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STLAYER_SPARE1_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STLAYER_SPARE1_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STLAYER_SPARE1_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STLAYER_SPARE1_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_SPARE1_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STLAYER_SPARE1_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_SPARE2_CID
 */
#define TRACE_STLAYER_SPARE2_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STLAYER_SPARE2_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STLAYER_SPARE2_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STLAYER_SPARE2_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STLAYER_SPARE2_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_SPARE2_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STLAYER_SPARE2_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_SPARE3_CID
 */
#define TRACE_STLAYER_SPARE3_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STLAYER_SPARE3_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STLAYER_SPARE3_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STLAYER_SPARE3_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STLAYER_SPARE3_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_SPARE3_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STLAYER_SPARE3_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_SPARE4_CID
 */
#define TRACE_STLAYER_SPARE4_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STLAYER_SPARE4_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STLAYER_SPARE4_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STLAYER_SPARE4_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STLAYER_SPARE4_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_SPARE4_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STLAYER_SPARE4_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_SRC_CID
 */
#define TRACE_STLAYER_SRC_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STLAYER_SRC_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STLAYER_SRC_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STLAYER_SRC_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STLAYER_SRC_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STLAYER_SRC_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STLAYER_SRC_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STLAYER_CID: STLAYER_VIDEO_CID
 */
#define TRACE_STLAYER_VIDEO_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STLAYER_VIDEO_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STLAYER_VIDEO_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_VIDEO_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STLAYER_VIDEO_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STLAYER_VIDEO_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STLAYER_VIDEO_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STMERGE_CID
 */
#define TRACE_STMERGE_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STMERGE_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STMERGE_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STMERGE_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STMERGE_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STMERGE_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STMERGE_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STMERGE_CID: STMERGE_API_CID
 */
#define TRACE_STMERGE_API_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STMERGE_API_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STMERGE_API_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STMERGE_API_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STMERGE_API_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STMERGE_API_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STMERGE_API_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STMERGE_CID: STMERGE_HAL_CID
 */
#define TRACE_STMERGE_HAL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STMERGE_HAL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STMERGE_HAL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STMERGE_HAL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STMERGE_HAL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STMERGE_HAL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STMERGE_HAL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STMERGE_CID: STMERGE_INTPT_CID
 */
#define TRACE_STMERGE_INTPT_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_INTPT_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_INTPT_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_INTPT_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STMERGE_INTPT_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STMERGE_INTPT_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_INTPT_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STMERGE_CID: STMERGE_IOCTL_CID
 */
#define TRACE_STMERGE_IOCTL_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_IOCTL_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_IOCTL_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_IOCTL_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STMERGE_IOCTL_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STMERGE_IOCTL_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_IOCTL_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STMERGE_CID: STMERGE_LIB_CID
 */
#define TRACE_STMERGE_LIB_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STMERGE_LIB_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STMERGE_LIB_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STMERGE_LIB_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STMERGE_LIB_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STMERGE_LIB_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STMERGE_LIB_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STMERGE_CID: STMERGE_POWER_CID
 */
#define TRACE_STMERGE_POWER_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_POWER_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_POWER_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_POWER_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STMERGE_POWER_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STMERGE_POWER_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_POWER_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STMERGE_CID: STMERGE_PROXY_CID
 */
#define TRACE_STMERGE_PROXY_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_PROXY_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_PROXY_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_PROXY_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STMERGE_PROXY_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STMERGE_PROXY_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_PROXY_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STMERGE_CID: STMERGE_STUB_CID
 */
#define TRACE_STMERGE_STUB_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STMERGE_STUB_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STMERGE_STUB_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STMERGE_STUB_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STMERGE_STUB_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STMERGE_STUB_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STMERGE_STUB_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STMERGE_CID: STMERGE_UTILS_CID
 */
#define TRACE_STMERGE_UTILS_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_UTILS_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STMERGE_UTILS_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_UTILS_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STMERGE_UTILS_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STMERGE_UTILS_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STMERGE_UTILS_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STMISR_CID
 */
#define TRACE_STMISR_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STMISR_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STMISR_CID_INFO_WITHOUT_HEADER_ACTIVATED                       STTRACE_ON
#define TRACE_STMISR_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STMISR_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STMISR_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STMISR_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STMISR_CID_USER_ACTIVATED                                      STTRACE_OFF

/*
 * STMISR_CID: STMISR_SRC_CID
 */
#define TRACE_STMISR_SRC_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STMISR_SRC_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STMISR_SRC_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STMISR_SRC_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STMISR_SRC_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STMISR_SRC_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STMISR_SRC_CID_USER_ACTIVATED                                      STTRACE_OFF

/*
 * STMISR_CID: STMISR_API_CID
 */
#define TRACE_STMISR_API_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STMISR_API_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STMISR_API_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STMISR_API_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STMISR_API_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STMISR_API_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STMISR_API_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STNET_CID
 */
#define TRACE_STNET_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STNET_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STNET_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STNET_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STNET_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STNET_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STNET_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STNET_CID: STNET_FEC_CID
 */
#define TRACE_STNET_FEC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STNET_FEC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STNET_FEC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STNET_FEC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STNET_FEC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STNET_FEC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STNET_FEC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STNET_CID: STNET_HOOK_CID
 */
#define TRACE_STNET_HOOK_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STNET_HOOK_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STNET_HOOK_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STNET_HOOK_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STNET_HOOK_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STNET_HOOK_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STNET_HOOK_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STNET_CID: STNET_INJECT_CID
 */
#define TRACE_STNET_INJECT_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STNET_INJECT_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STNET_INJECT_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STNET_INJECT_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STNET_INJECT_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STNET_INJECT_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STNET_INJECT_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STNET_CID: STNET_IPRC_PROXY_CID
 */
#define TRACE_STNET_IPRC_PROXY_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STNET_IPRC_PROXY_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STNET_IPRC_PROXY_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STNET_IPRC_PROXY_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STNET_IPRC_PROXY_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STNET_IPRC_PROXY_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STNET_IPRC_PROXY_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STNET_CID: STNET_IPRC_STUB_CID
 */
#define TRACE_STNET_IPRC_STUB_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STNET_IPRC_STUB_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STNET_IPRC_STUB_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STNET_IPRC_STUB_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STNET_IPRC_STUB_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STNET_IPRC_STUB_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STNET_IPRC_STUB_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STNET_CID: STNET_LINUX_CORE_CID
 */
#define TRACE_STNET_LINUX_CORE_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STNET_LINUX_CORE_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STNET_LINUX_CORE_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STNET_LINUX_CORE_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STNET_LINUX_CORE_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STNET_LINUX_CORE_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STNET_LINUX_CORE_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STNET_CID: STNET_LINUX_IOCTL_CID
 */
#define TRACE_STNET_LINUX_IOCTL_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STNET_LINUX_IOCTL_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STNET_LINUX_IOCTL_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STNET_LINUX_IOCTL_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STNET_LINUX_IOCTL_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STNET_LINUX_IOCTL_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STNET_LINUX_IOCTL_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STNET_CID: STNET_LINUX_PROXY_CID
 */
#define TRACE_STNET_LINUX_PROXY_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STNET_LINUX_PROXY_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STNET_LINUX_PROXY_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STNET_LINUX_PROXY_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STNET_LINUX_PROXY_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STNET_LINUX_PROXY_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STNET_LINUX_PROXY_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STNET_CID: STNET_MULTIFILTER_CID
 */
#define TRACE_STNET_MULTIFILTER_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STNET_MULTIFILTER_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STNET_MULTIFILTER_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STNET_MULTIFILTER_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STNET_MULTIFILTER_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STNET_MULTIFILTER_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STNET_MULTIFILTER_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STNET_CID: STNET_RECEIVE_CID
 */
#define TRACE_STNET_RECEIVE_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STNET_RECEIVE_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STNET_RECEIVE_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STNET_RECEIVE_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STNET_RECEIVE_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STNET_RECEIVE_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STNET_RECEIVE_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STNET_CID: STNET_SRC_CID
 */
#define TRACE_STNET_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STNET_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STNET_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STNET_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STNET_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STNET_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STNET_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STNET_CID: STNET_TXMIT_CID
 */
#define TRACE_STNET_TXMIT_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STNET_TXMIT_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STNET_TXMIT_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STNET_TXMIT_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STNET_TXMIT_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STNET_TXMIT_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STNET_TXMIT_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STOS_CID
 */
#define TRACE_STOS_CID_FATAL_ACTIVATED                                        STTRACE_ON
#define TRACE_STOS_CID_ERROR_ACTIVATED                                        STTRACE_ON
#define TRACE_STOS_CID_WARNING_ACTIVATED                                      STTRACE_OFF
#define TRACE_STOS_CID_INFO_ACTIVATED                                         STTRACE_OFF
#define TRACE_STOS_CID_API_IN_ACTIVATED                                       STTRACE_OFF
#define TRACE_STOS_CID_API_OUT_ACTIVATED                                      STTRACE_OFF
#define TRACE_STOS_CID_USER_ACTIVATED                                         STTRACE_OFF
/*
 * STOS_CID: STOS_INTERRUPT_CID
 */
#define TRACE_STOS_INTERRUPT_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STOS_INTERRUPT_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STOS_INTERRUPT_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STOS_INTERRUPT_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STOS_INTERRUPT_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STOS_INTERRUPT_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STOS_INTERRUPT_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STOS_CID: STOS_LINUX_CID
 */
#define TRACE_STOS_LINUX_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STOS_LINUX_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STOS_LINUX_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STOS_LINUX_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STOS_LINUX_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STOS_LINUX_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STOS_LINUX_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STOS_CID: STOS_MEMORY_CID
 */
#define TRACE_STOS_MEMORY_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STOS_MEMORY_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STOS_MEMORY_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STOS_MEMORY_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STOS_MEMORY_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STOS_MEMORY_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STOS_MEMORY_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STOS_CID: STOS_MESSAGEQUEUE_CID
 */
#define TRACE_STOS_MESSAGEQUEUE_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STOS_MESSAGEQUEUE_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STOS_MESSAGEQUEUE_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STOS_MESSAGEQUEUE_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STOS_MESSAGEQUEUE_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STOS_MESSAGEQUEUE_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STOS_MESSAGEQUEUE_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STOS_CID: STOS_MUTEX_CID
 */
#define TRACE_STOS_MUTEX_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STOS_MUTEX_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STOS_MUTEX_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STOS_MUTEX_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STOS_MUTEX_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STOS_MUTEX_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STOS_MUTEX_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STOS_CID: STOS_REGION_CID
 */
#define TRACE_STOS_REGION_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STOS_REGION_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STOS_REGION_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STOS_REGION_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STOS_REGION_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STOS_REGION_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STOS_REGION_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STOS_CID: STOS_SEMAPHORE_CID
 */
#define TRACE_STOS_SEMAPHORE_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STOS_SEMAPHORE_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STOS_SEMAPHORE_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STOS_SEMAPHORE_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STOS_SEMAPHORE_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STOS_SEMAPHORE_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STOS_SEMAPHORE_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 *   STOS_CID: STOS_TASKS_CID
 *   */
#define TRACE_STOS_TASKS_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STOS_TASKS_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STOS_TASKS_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STOS_TASKS_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STOS_TASKS_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STOS_TASKS_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STOS_TASKS_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STOS_CID: STOS_TIME_CID
 */
#define TRACE_STOS_TIME_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STOS_TIME_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STOS_TIME_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STOS_TIME_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STOS_TIME_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STOS_TIME_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STOS_TIME_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STPCCRD_CID
 */
#define TRACE_STPCCRD_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STPCCRD_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STPCCRD_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STPCCRD_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STPCCRD_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPCCRD_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STPCCRD_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STPCCRD_CID: STPCCRD_API_CID
 */
#define TRACE_STPCCRD_API_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STPCCRD_API_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STPCCRD_API_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STPCCRD_API_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STPCCRD_API_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STPCCRD_API_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STPCCRD_API_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STPCCRD_CID: STPCCRD_CORE_CID
 */
#define TRACE_STPCCRD_CORE_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STPCCRD_CORE_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STPCCRD_CORE_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCCRD_CORE_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPCCRD_CORE_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STPCCRD_CORE_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCCRD_CORE_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 *  STPCCRD_CID: STPCCRD_DRV_CID
 */
#define TRACE_STPCCRD_DRV_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STPCCRD_DRV_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STPCCRD_DRV_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCCRD_DRV_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPCCRD_DRV_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STPCCRD_DRV_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCCRD_DRV_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STPCCRD_CID: STPCCRD_HAL_CID
 */
#define TRACE_STPCCRD_HAL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STPCCRD_HAL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STPCCRD_HAL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STPCCRD_HAL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STPCCRD_HAL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STPCCRD_HAL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STPCCRD_HAL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STPCCRD_CID: STPCCRD_HANDLER_CID
 */
#define TRACE_STPCCRD_HANDLER_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STPCCRD_HANDLER_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STPCCRD_HANDLER_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STPCCRD_HANDLER_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCCRD_HANDLER_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STPCCRD_HANDLER_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STPCCRD_HANDLER_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STPCCRD_CID: STPCCRD_IOCTL_CID
 */
#define TRACE_STPCCRD_IOCTL_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STPCCRD_IOCTL_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STPCCRD_IOCTL_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STPCCRD_IOCTL_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STPCCRD_IOCTL_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCCRD_IOCTL_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STPCCRD_IOCTL_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STPCCRD_CID: STPCCRD_POWER_CID
 */
#define TRACE_STPCCRD_POWER_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STPCCRD_POWER_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STPCCRD_POWER_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STPCCRD_POWER_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STPCCRD_POWER_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCCRD_POWER_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STPCCRD_POWER_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STPCCRD_CID: STPCCRD_UTILS_CID
 */
#define TRACE_STPCCRD_UTILS_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STPCCRD_UTILS_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STPCCRD_UTILS_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STPCCRD_UTILS_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STPCCRD_UTILS_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCCRD_UTILS_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STPCCRD_UTILS_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STPCPD_CID
 */
#define TRACE_STPCPD_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STPCPD_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STPCPD_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPCPD_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STPCPD_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STPCPD_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPCPD_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STPCPD_CID : STPCPD_API_CID
 */
#define TRACE_STPCPD_API_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STPCPD_API_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STPCPD_API_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCPD_API_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPCPD_API_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STPCPD_API_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCPD_API_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STPCPD_CID : STPCPD_IOCTL_CID
 */
#define TRACE_STPCPD_IOCTL_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STPCPD_IOCTL_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STPCPD_IOCTL_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STPCPD_IOCTL_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STPCPD_IOCTL_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STPCPD_IOCTL_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STPCPD_IOCTL_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STPCPD_CID : STPCPD_LIB_CC_CID
 */
#define TRACE_STPCPD_LIB_CC_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STPCPD_LIB_CC_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STPCPD_LIB_CC_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STPCPD_LIB_CC_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STPCPD_LIB_CC_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STPCPD_LIB_CC_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STPCPD_LIB_CC_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STPCPD_CID ; STPCPD_LIB_CML_CID
 */
#define TRACE_STPCPD_LIB_CML_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STPCPD_LIB_CML_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STPCPD_LIB_CML_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STPCPD_LIB_CML_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STPCPD_LIB_CML_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STPCPD_LIB_CML_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STPCPD_LIB_CML_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STPCPD_CID : STPCPD_LIB_DSG_CID
 */
#define TRACE_STPCPD_LIB_DSG_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STPCPD_LIB_DSG_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STPCPD_LIB_DSG_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STPCPD_LIB_DSG_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STPCPD_LIB_DSG_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STPCPD_LIB_DSG_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STPCPD_LIB_DSG_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STPCPD_CID: STPCPD_LIB_ESAFE_CID
 */
#define TRACE_STPCPD_LIB_ESAFE_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STPCPD_LIB_ESAFE_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STPCPD_LIB_ESAFE_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STPCPD_LIB_ESAFE_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STPCPD_LIB_ESAFE_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STPCPD_LIB_ESAFE_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STPCPD_LIB_ESAFE_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STPCPD_CID : STPCPD_NET_LINUX_CID
 */
#define TRACE_STPCPD_NET_LINUX_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STPCPD_NET_LINUX_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STPCPD_NET_LINUX_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STPCPD_NET_LINUX_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STPCPD_NET_LINUX_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STPCPD_NET_LINUX_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STPCPD_NET_LINUX_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STPCPD_CID : STPCPD_NET_OS21_CID
 */
#define TRACE_STPCPD_NET_OS21_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STPCPD_NET_OS21_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STPCPD_NET_OS21_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STPCPD_NET_OS21_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STPCPD_NET_OS21_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STPCPD_NET_OS21_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STPCPD_NET_OS21_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STPIO_CID
 */
#define TRACE_STPIO_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STPIO_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STPIO_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STPIO_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STPIO_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STPIO_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STPIO_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STPIO_CID: STPIO_CORE_CID
 */
#define TRACE_STPIO_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STPIO_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STPIO_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STPIO_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STPIO_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPIO_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STPIO_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STPIO_CID: STPIO_IOCTL_CID
 */
#define TRACE_STPIO_IOCTL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STPIO_IOCTL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STPIO_IOCTL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STPIO_IOCTL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STPIO_IOCTL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STPIO_IOCTL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STPIO_IOCTL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STPIO_CID: STPIO_SPARE1_CID
 */
#define TRACE_STPIO_SPARE1_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STPIO_SPARE1_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STPIO_SPARE1_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STPIO_SPARE1_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPIO_SPARE1_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STPIO_SPARE1_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STPIO_SPARE1_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STPIO_CID: STPIO_SPARE2_CID
 */
#define TRACE_STPIO_SPARE2_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STPIO_SPARE2_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STPIO_SPARE2_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STPIO_SPARE2_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPIO_SPARE2_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STPIO_SPARE2_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STPIO_SPARE2_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STPIO_CID: STPIO_SPARE3_CID
 */
#define TRACE_STPIO_SPARE3_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STPIO_SPARE3_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STPIO_SPARE3_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STPIO_SPARE3_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPIO_SPARE3_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STPIO_SPARE3_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STPIO_SPARE3_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STPIO_CID: STPIO_SPARE4_CID
 */
#define TRACE_STPIO_SPARE4_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STPIO_SPARE4_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STPIO_SPARE4_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STPIO_SPARE4_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPIO_SPARE4_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STPIO_SPARE4_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STPIO_SPARE4_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STPIO_CID: STPIO_SRC_CID
 */
#define TRACE_STPIO_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STPIO_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STPIO_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPIO_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPIO_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STPIO_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPIO_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STPOD_CID
 */
#define TRACE_STPOD_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STPOD_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STPOD_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STPOD_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STPOD_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STPOD_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STPOD_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STPOD_CID: STPOD_API_CID
 */
#define TRACE_STPOD_API_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STPOD_API_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STPOD_API_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPOD_API_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPOD_API_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STPOD_API_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPOD_API_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STPOD_CID: STPOD_CCSC_CID
 */
#define TRACE_STPOD_CCSC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STPOD_CCSC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STPOD_CCSC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STPOD_CCSC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STPOD_CCSC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPOD_CCSC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STPOD_CCSC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STPOD_CID: STPOD_LINUX_CORE_CID
 */
#define TRACE_STPOD_LINUX_CORE_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STPOD_LINUX_CORE_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STPOD_LINUX_CORE_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STPOD_LINUX_CORE_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOD_LINUX_CORE_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STPOD_LINUX_CORE_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STPOD_LINUX_CORE_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STPOD_CID: STPOD_LINUX_IOCTL_CID
 */
#define TRACE_STPOD_LINUX_IOCTL_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STPOD_LINUX_IOCTL_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STPOD_LINUX_IOCTL_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STPOD_LINUX_IOCTL_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STPOD_LINUX_IOCTL_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STPOD_LINUX_IOCTL_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STPOD_LINUX_IOCTL_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STPOD_CID: STPOD_MCHI_CID
 */
#define TRACE_STPOD_MCHI_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STPOD_MCHI_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STPOD_MCHI_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STPOD_MCHI_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STPOD_MCHI_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPOD_MCHI_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STPOD_MCHI_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STPOD_CID: STPOD_PIO_CID
 */
#define TRACE_STPOD_PIO_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STPOD_PIO_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STPOD_PIO_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPOD_PIO_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPOD_PIO_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STPOD_PIO_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPOD_PIO_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STPOWER_CID
 */
#define TRACE_STPOWER_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STPOWER_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STPOWER_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STPOWER_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STPOWER_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPOWER_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STPOWER_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_API_CID
 */
#define TRACE_STPOWER_API_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STPOWER_API_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STPOWER_API_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STPOWER_API_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STPOWER_API_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STPOWER_API_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STPOWER_API_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_CLOCK_CID
 */
#define TRACE_STPOWER_CLOCK_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STPOWER_CLOCK_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STPOWER_CLOCK_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOWER_CLOCK_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STPOWER_CLOCK_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STPOWER_CLOCK_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOWER_CLOCK_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_CORE_CID
 */
#define TRACE_STPOWER_CORE_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STPOWER_CORE_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STPOWER_CORE_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STPOWER_CORE_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPOWER_CORE_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STPOWER_CORE_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STPOWER_CORE_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_CPU_STATES_CID
 */
#define TRACE_STPOWER_CPU_STATES_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STPOWER_CPU_STATES_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STPOWER_CPU_STATES_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STPOWER_CPU_STATES_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STPOWER_CPU_STATES_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STPOWER_CPU_STATES_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STPOWER_CPU_STATES_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_DEBUG_CID
 */
#define TRACE_STPOWER_DEBUG_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STPOWER_DEBUG_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STPOWER_DEBUG_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOWER_DEBUG_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STPOWER_DEBUG_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STPOWER_DEBUG_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOWER_DEBUG_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_MASTER_CID
 */
#define TRACE_STPOWER_MASTER_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STPOWER_MASTER_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STPOWER_MASTER_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STPOWER_MASTER_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STPOWER_MASTER_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOWER_MASTER_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STPOWER_MASTER_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_REGISTER_PM_DEVICES_CID
 */
#define TRACE_STPOWER_REGISTER_PM_DEVICES_CID_FATAL_ACTIVATED                 STTRACE_ON
#define TRACE_STPOWER_REGISTER_PM_DEVICES_CID_ERROR_ACTIVATED                 STTRACE_ON
#define TRACE_STPOWER_REGISTER_PM_DEVICES_CID_WARNING_ACTIVATED               STTRACE_OFF
#define TRACE_STPOWER_REGISTER_PM_DEVICES_CID_INFO_ACTIVATED                  STTRACE_OFF
#define TRACE_STPOWER_REGISTER_PM_DEVICES_CID_API_IN_ACTIVATED                STTRACE_OFF
#define TRACE_STPOWER_REGISTER_PM_DEVICES_CID_API_OUT_ACTIVATED               STTRACE_OFF
#define TRACE_STPOWER_REGISTER_PM_DEVICES_CID_USER_ACTIVATED                  STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_SLAVE_CID
 */
#define TRACE_STPOWER_SLAVE_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STPOWER_SLAVE_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STPOWER_SLAVE_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOWER_SLAVE_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STPOWER_SLAVE_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STPOWER_SLAVE_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOWER_SLAVE_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_UTILS_CID
 */
#define TRACE_STPOWER_UTILS_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STPOWER_UTILS_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STPOWER_UTILS_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOWER_UTILS_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STPOWER_UTILS_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STPOWER_UTILS_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STPOWER_UTILS_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_VIRTUAL_DEVICES_CID
 */
#define TRACE_STPOWER_VIRTUAL_DEVICES_CID_FATAL_ACTIVATED                     STTRACE_ON
#define TRACE_STPOWER_VIRTUAL_DEVICES_CID_ERROR_ACTIVATED                     STTRACE_ON
#define TRACE_STPOWER_VIRTUAL_DEVICES_CID_WARNING_ACTIVATED                   STTRACE_OFF
#define TRACE_STPOWER_VIRTUAL_DEVICES_CID_INFO_ACTIVATED                      STTRACE_OFF
#define TRACE_STPOWER_VIRTUAL_DEVICES_CID_API_IN_ACTIVATED                    STTRACE_OFF
#define TRACE_STPOWER_VIRTUAL_DEVICES_CID_API_OUT_ACTIVATED                   STTRACE_OFF
#define TRACE_STPOWER_VIRTUAL_DEVICES_CID_USER_ACTIVATED                      STTRACE_OFF
/*
 * STPOWER_CID: STPOWER_WAKEUP_REASON_CID
 */
#define TRACE_STPOWER_WAKEUP_REASON_CID_FATAL_ACTIVATED                       STTRACE_ON
#define TRACE_STPOWER_WAKEUP_REASON_CID_ERROR_ACTIVATED                       STTRACE_ON
#define TRACE_STPOWER_WAKEUP_REASON_CID_WARNING_ACTIVATED                     STTRACE_OFF
#define TRACE_STPOWER_WAKEUP_REASON_CID_INFO_ACTIVATED                        STTRACE_OFF
#define TRACE_STPOWER_WAKEUP_REASON_CID_API_IN_ACTIVATED                      STTRACE_OFF
#define TRACE_STPOWER_WAKEUP_REASON_CID_API_OUT_ACTIVATED                     STTRACE_OFF
#define TRACE_STPOWER_WAKEUP_REASON_CID_USER_ACTIVATED                        STTRACE_OFF
/*
 * STPTI4_CID
 */
#define TRACE_STPTI4_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STPTI4_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STPTI4_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPTI4_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STPTI4_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STPTI4_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPTI4_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STPTI5_CID
 */
#define TRACE_STPTI5_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STPTI5_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STPTI5_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPTI5_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STPTI5_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STPTI5_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPTI5_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STPWM_CID
 */
#define TRACE_STPWM_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STPWM_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STPWM_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STPWM_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STPWM_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STPWM_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STPWM_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STPWM_CID: STPWM_CORE_CID
 */
#define TRACE_STPWM_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STPWM_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STPWM_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STPWM_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STPWM_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPWM_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STPWM_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STPWM_CID: STPWM_DRV_CID
 */
#define TRACE_STPWM_DRV_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STPWM_DRV_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STPWM_DRV_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPWM_DRV_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STPWM_DRV_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STPWM_DRV_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STPWM_DRV_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STPWM_CID: STPWM_IOCTL_CID
 */
#define TRACE_STPWM_IOCTL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STPWM_IOCTL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STPWM_IOCTL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STPWM_IOCTL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STPWM_IOCTL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STPWM_IOCTL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STPWM_IOCTL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STRESET_CID
 */
#define TRACE_STRESET_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STRESET_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STRESET_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STRESET_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STRESET_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STRESET_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STRESET_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STRESET_CID: STRESET_API_CID
 */
#define TRACE_STRESET_API_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STRESET_API_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STRESET_API_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STRESET_API_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STRESET_API_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STRESET_API_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STRESET_API_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STRESET_CID: STRESET_LINUX_CORE_CID
 */
#define TRACE_STRESET_LINUX_CORE_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STRESET_LINUX_CORE_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STRESET_LINUX_CORE_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STRESET_LINUX_CORE_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STRESET_LINUX_CORE_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STRESET_LINUX_CORE_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STRESET_LINUX_CORE_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STRESET_CID: STRESET_LINUX_PROXY_CID
 */
#define TRACE_STRESET_LINUX_PROXY_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STRESET_LINUX_PROXY_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STRESET_LINUX_PROXY_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STRESET_LINUX_PROXY_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STRESET_LINUX_PROXY_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STRESET_LINUX_PROXY_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STRESET_LINUX_PROXY_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STRESET_CID: STRESET_PROXY_CID
 */
#define TRACE_STRESET_PROXY_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STRESET_PROXY_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STRESET_PROXY_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STRESET_PROXY_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STRESET_PROXY_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STRESET_PROXY_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STRESET_PROXY_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STRESET_CID: STRESET_STUB_CID
 */
#define TRACE_STRESET_STUB_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STRESET_STUB_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STRESET_STUB_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STRESET_STUB_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STRESET_STUB_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STRESET_STUB_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STRESET_STUB_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STRESET_CID: STRESET_TASK_CID
 */
#define TRACE_STRESET_TASK_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STRESET_TASK_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STRESET_TASK_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STRESET_TASK_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STRESET_TASK_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STRESET_TASK_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STRESET_TASK_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STRESET_CID: STRESET_UTILITY_CID
 */
#define TRACE_STRESET_UTILITY_CID_FATAL_ACTIVATED                             STTRACE_ON
#define TRACE_STRESET_UTILITY_CID_ERROR_ACTIVATED                             STTRACE_ON
#define TRACE_STRESET_UTILITY_CID_WARNING_ACTIVATED                           STTRACE_OFF
#define TRACE_STRESET_UTILITY_CID_INFO_ACTIVATED                              STTRACE_OFF
#define TRACE_STRESET_UTILITY_CID_API_IN_ACTIVATED                            STTRACE_OFF
#define TRACE_STRESET_UTILITY_CID_API_OUT_ACTIVATED                           STTRACE_OFF
#define TRACE_STRESET_UTILITY_CID_USER_ACTIVATED                              STTRACE_OFF
/*
 * STSCART_CID
 */
#define TRACE_STSCART_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STSCART_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STSCART_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STSCART_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STSCART_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STSCART_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STSCART_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STSCART_CID: STSCART_HAL_CID
 */
#define TRACE_STSCART_HAL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STSCART_HAL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STSCART_HAL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STSCART_HAL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STSCART_HAL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STSCART_HAL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STSCART_HAL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STSCART_CID: STSCART_SPARE1_CID
 */
#define TRACE_STSCART_SPARE1_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STSCART_SPARE1_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STSCART_SPARE1_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STSCART_SPARE1_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STSCART_SPARE1_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STSCART_SPARE1_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STSCART_SPARE1_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STSCART_CID: STSCART_SPARE2_CID
 */
#define TRACE_STSCART_SPARE2_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STSCART_SPARE2_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STSCART_SPARE2_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STSCART_SPARE2_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STSCART_SPARE2_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STSCART_SPARE2_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STSCART_SPARE2_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STSCART_CID: STSCART_SPARE3_CID
 */
#define TRACE_STSCART_SPARE3_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STSCART_SPARE3_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STSCART_SPARE3_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STSCART_SPARE3_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STSCART_SPARE3_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STSCART_SPARE3_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STSCART_SPARE3_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STSCART_CID: STSCART_SPARE4_CID
 */
#define TRACE_STSCART_SPARE4_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STSCART_SPARE4_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STSCART_SPARE4_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STSCART_SPARE4_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STSCART_SPARE4_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STSCART_SPARE4_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STSCART_SPARE4_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STSCART_CID: STSCART_SRC_CID
 */
#define TRACE_STSCART_SRC_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STSCART_SRC_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STSCART_SRC_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STSCART_SRC_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STSCART_SRC_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STSCART_SRC_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STSCART_SRC_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STSCART_CID: STSCART_UTILS_CID
 */
#define TRACE_STSCART_UTILS_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STSCART_UTILS_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STSCART_UTILS_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STSCART_UTILS_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STSCART_UTILS_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STSCART_UTILS_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STSCART_UTILS_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STSMART_CID
 */
#define TRACE_STSMART_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STSMART_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STSMART_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STSMART_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STSMART_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STSMART_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STSMART_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STSMART_CID: STSMART_CORE_CID
 */
#define TRACE_STSMART_CORE_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STSMART_CORE_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STSMART_CORE_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STSMART_CORE_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSMART_CORE_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STSMART_CORE_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STSMART_CORE_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STSMART_CID: STSMART_IOCTL_CID
 */
#define TRACE_STSMART_IOCTL_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STSMART_IOCTL_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STSMART_IOCTL_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STSMART_IOCTL_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STSMART_IOCTL_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STSMART_IOCTL_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STSMART_IOCTL_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STSMART_CID: STSMART_PROTOCOLS_CID
 */
#define TRACE_STSMART_PROTOCOLS_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STSMART_PROTOCOLS_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STSMART_PROTOCOLS_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STSMART_PROTOCOLS_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STSMART_PROTOCOLS_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STSMART_PROTOCOLS_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STSMART_PROTOCOLS_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STSMART_CID: STSMART_SRC_CID
 */
#define TRACE_STSMART_SRC_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STSMART_SRC_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STSMART_SRC_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STSMART_SRC_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STSMART_SRC_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STSMART_SRC_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STSMART_SRC_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STSPI_CID
 */
#define TRACE_STSPI_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STSPI_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STSPI_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STSPI_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STSPI_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STSPI_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STSPI_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STSPI_CID: STSPI_CORE_CID
 */
#define TRACE_STSPI_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STSPI_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STSPI_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STSPI_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STSPI_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSPI_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STSPI_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STSPI_CID: STSPI_IOCTL_CID
 */
#define TRACE_STSPI_IOCTL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STSPI_IOCTL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STSPI_IOCTL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STSPI_IOCTL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STSPI_IOCTL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STSPI_IOCTL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STSPI_IOCTL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STSPI_CID: STSPI_SPARE1_CID
 */
#define TRACE_STSPI_SPARE1_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STSPI_SPARE1_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STSPI_SPARE1_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STSPI_SPARE1_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSPI_SPARE1_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STSPI_SPARE1_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STSPI_SPARE1_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STSPI_CID: STSPI_SPARE2_CID
 */
#define TRACE_STSPI_SPARE2_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STSPI_SPARE2_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STSPI_SPARE2_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STSPI_SPARE2_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSPI_SPARE2_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STSPI_SPARE2_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STSPI_SPARE2_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STSPI_CID: STSPI_SPARE3_CID
 */
#define TRACE_STSPI_SPARE3_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STSPI_SPARE3_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STSPI_SPARE3_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STSPI_SPARE3_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSPI_SPARE3_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STSPI_SPARE3_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STSPI_SPARE3_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STSPI_CID: STSPI_SPARE4_CID
 */
#define TRACE_STSPI_SPARE4_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STSPI_SPARE4_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STSPI_SPARE4_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STSPI_SPARE4_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSPI_SPARE4_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STSPI_SPARE4_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STSPI_SPARE4_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STSPI_CID: STSPI_SRC_CID
 */
#define TRACE_STSPI_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STSPI_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STSPI_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSPI_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STSPI_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STSPI_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSPI_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STSUBT_CID
 */
#define TRACE_STSUBT_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STSUBT_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STSUBT_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STSUBT_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STSUBT_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STSUBT_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STSUBT_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STSUBT_CID: STSUBT_CORE_CID
 */
#define TRACE_STSUBT_CORE_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STSUBT_CORE_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STSUBT_CORE_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STSUBT_CORE_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STSUBT_CORE_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STSUBT_CORE_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STSUBT_CORE_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STSUBT_CID: STSUBT_EPOCH_CID
 */
#define TRACE_STSUBT_EPOCH_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STSUBT_EPOCH_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STSUBT_EPOCH_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STSUBT_EPOCH_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSUBT_EPOCH_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STSUBT_EPOCH_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STSUBT_EPOCH_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STSUBT_CID: STSUBT_IOCTL_CID
 */
#define TRACE_STSUBT_IOCTL_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STSUBT_IOCTL_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STSUBT_IOCTL_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STSUBT_IOCTL_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSUBT_IOCTL_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STSUBT_IOCTL_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STSUBT_IOCTL_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STSUBT_CID: STSUBT_SRC_CID
 */
#define TRACE_STSUBT_SRC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STSUBT_SRC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STSUBT_SRC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STSUBT_SRC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STSUBT_SRC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STSUBT_SRC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STSUBT_SRC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STSUBT_CID: STSUBT_SRC_PES_BUFFER_CID
 */
#define TRACE_STSUBT_SRC_PES_BUFFER_CID_FATAL_ACTIVATED                       STTRACE_ON
#define TRACE_STSUBT_SRC_PES_BUFFER_CID_ERROR_ACTIVATED                       STTRACE_ON
#define TRACE_STSUBT_SRC_PES_BUFFER_CID_WARNING_ACTIVATED                     STTRACE_OFF
#define TRACE_STSUBT_SRC_PES_BUFFER_CID_INFO_ACTIVATED                        STTRACE_OFF
#define TRACE_STSUBT_SRC_PES_BUFFER_CID_API_IN_ACTIVATED                      STTRACE_OFF
#define TRACE_STSUBT_SRC_PES_BUFFER_CID_API_OUT_ACTIVATED                     STTRACE_OFF
#define TRACE_STSUBT_SRC_PES_BUFFER_CID_USER_ACTIVATED                        STTRACE_OFF
/*
 * STSUBT_CID: STSUBT_SYNC_PROC_CID
 */
#define TRACE_STSUBT_SYNC_PROC_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STSUBT_SYNC_PROC_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STSUBT_SYNC_PROC_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STSUBT_SYNC_PROC_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STSUBT_SYNC_PROC_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STSUBT_SYNC_PROC_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STSUBT_SYNC_PROC_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STSUBT_CID: STSUBT_SYNC_TIMER_CID
 */
#define TRACE_STSUBT_SYNC_TIMER_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STSUBT_SYNC_TIMER_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STSUBT_SYNC_TIMER_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STSUBT_SYNC_TIMER_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STSUBT_SYNC_TIMER_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STSUBT_SYNC_TIMER_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STSUBT_SYNC_TIMER_CID_USER_ACTIVATED                            STTRACE_OFF
/*
 * STSYS_CID
 */
#define TRACE_STSYS_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STSYS_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STSYS_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STSYS_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STSYS_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STSYS_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STSYS_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STTBX_CID
 */
#define TRACE_STTBX_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STTBX_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STTBX_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STTBX_CID_INFO_ACTIVATED                                        STTRACE_ON
#define TRACE_STTBX_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STTBX_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STTBX_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STTBX_CID: STTBX_TRC_PASSTHROUGH_CID
 */
#define TRACE_STTBX_TRC_PASSTHROUGH_CID_FATAL_ACTIVATED                       STTRACE_ON
#define TRACE_STTBX_TRC_PASSTHROUGH_CID_ERROR_ACTIVATED                       STTRACE_ON
#define TRACE_STTBX_TRC_PASSTHROUGH_CID_WARNING_ACTIVATED                     STTRACE_OFF
#define TRACE_STTBX_TRC_PASSTHROUGH_CID_INFO_ACTIVATED                        STTRACE_OFF
#define TRACE_STTBX_TRC_PASSTHROUGH_CID_API_IN_ACTIVATED                      STTRACE_OFF
#define TRACE_STTBX_TRC_PASSTHROUGH_CID_API_OUT_ACTIVATED                     STTRACE_OFF
#define TRACE_STTBX_TRC_PASSTHROUGH_CID_USER_ACTIVATED                        STTRACE_OFF
/*
 * STTBX_CID: STTBX_TRACES_CID
 */
#define TRACE_STTBX_TRACES_CID_FATAL_ACTIVATED                       STTRACE_ON
#define TRACE_STTBX_TRACES_CID_ERROR_ACTIVATED                       STTRACE_ON
#define TRACE_STTBX_TRACES_CID_WARNING_ACTIVATED                     STTRACE_OFF
/* The next #define must be STTRACE_ON to use dynamic filtering */
#define TRACE_STTBX_TRACES_CID_INFO_ACTIVATED                        STTRACE_ON
#define TRACE_STTBX_TRACES_CID_API_IN_ACTIVATED                      STTRACE_OFF
#define TRACE_STTBX_TRACES_CID_API_OUT_ACTIVATED                     STTRACE_OFF
#define TRACE_STTBX_TRACES_CID_USER_ACTIVATED                        STTRACE_OFF
/*
 * STTKDMA_CID
 */
#define TRACE_STTKDMA_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STTKDMA_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STTKDMA_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STTKDMA_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STTKDMA_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STTKDMA_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STTKDMA_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STTTX_CID
 */
#define TRACE_STTTX_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STTTX_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STTTX_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STTTX_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STTTX_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STTTX_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STTTX_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STTTX_CID: STTTX_API_CID
 */
#define TRACE_STTTX_API_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STTTX_API_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STTTX_API_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STTTX_API_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STTTX_API_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STTTX_API_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STTTX_API_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STTTX_CID: STTTX_DM_CID
 */
#define TRACE_STTTX_DM_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STTTX_DM_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STTTX_DM_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_STTTX_DM_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_STTTX_DM_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_STTTX_DM_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_STTTX_DM_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
 * STTTX_CID: STTTX_FILTER_CID
 */
#define TRACE_STTTX_FILTER_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STTTX_FILTER_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STTTX_FILTER_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STTTX_FILTER_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STTTX_FILTER_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STTTX_FILTER_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STTTX_FILTER_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STTTX_CID: STTTX_IOCTL_CID
 */
#define TRACE_STTTX_IOCTL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STTTX_IOCTL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STTTX_IOCTL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STTTX_IOCTL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STTTX_IOCTL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STTTX_IOCTL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STTTX_IOCTL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STTTX_CID: STTTX_PARSER_CID
 */
#define TRACE_STTTX_PARSER_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STTTX_PARSER_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STTTX_PARSER_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STTTX_PARSER_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STTTX_PARSER_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STTTX_PARSER_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STTTX_PARSER_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STTTX_CID: STTTX_RENDRER_CID
 */
#define TRACE_STTTX_RENDRER_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STTTX_RENDRER_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STTTX_RENDRER_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STTTX_RENDRER_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STTTX_RENDRER_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STTTX_RENDRER_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STTTX_RENDRER_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STTTX_CID: STTTX_SRC_CID
 */
#define TRACE_STTTX_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STTTX_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STTTX_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STTTX_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STTTX_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STTTX_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STTTX_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STTTX_CID: STTTX_UTILS_CID
 */
#define TRACE_STTTX_UTILS_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STTTX_UTILS_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STTTX_UTILS_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STTTX_UTILS_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STTTX_UTILS_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STTTX_UTILS_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STTTX_UTILS_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STTUNER_CID
 */
#define TRACE_STTUNER_CID_FATAL_ACTIVATED                                     STTRACE_ON
#define TRACE_STTUNER_CID_ERROR_ACTIVATED                                     STTRACE_ON
#define TRACE_STTUNER_CID_WARNING_ACTIVATED                                   STTRACE_OFF
#define TRACE_STTUNER_CID_INFO_ACTIVATED                                      STTRACE_OFF
#define TRACE_STTUNER_CID_API_IN_ACTIVATED                                    STTRACE_OFF
#define TRACE_STTUNER_CID_API_OUT_ACTIVATED                                   STTRACE_OFF
#define TRACE_STTUNER_CID_USER_ACTIVATED                                      STTRACE_OFF
/*
 * STUART_CID
 */
#define TRACE_STUART_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STUART_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STUART_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STUART_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STUART_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STUART_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STUART_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STUART_CID: STUART_CORE_CID
 */
#define TRACE_STUART_CORE_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STUART_CORE_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STUART_CORE_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STUART_CORE_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STUART_CORE_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STUART_CORE_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STUART_CORE_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STUART_CID: STUART_DMA_CID
 */
#define TRACE_STUART_DMA_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STUART_DMA_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STUART_DMA_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STUART_DMA_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STUART_DMA_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STUART_DMA_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STUART_DMA_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STUART_CID: STUART_IOCTL_CID
 */
#define TRACE_STUART_IOCTL_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STUART_IOCTL_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STUART_IOCTL_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STUART_IOCTL_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STUART_IOCTL_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STUART_IOCTL_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STUART_IOCTL_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STUART_CID: STUART_REGS_CID
 */
#define TRACE_STUART_REGS_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STUART_REGS_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STUART_REGS_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STUART_REGS_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STUART_REGS_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STUART_REGS_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STUART_REGS_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STUART_CID: STUART_SRC_CID
 */
#define TRACE_STUART_SRC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STUART_SRC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STUART_SRC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STUART_SRC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STUART_SRC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STUART_SRC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STUART_SRC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STUART_CID: STUART_UTILS_CID
 */
#define TRACE_STUART_UTILS_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STUART_UTILS_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STUART_UTILS_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STUART_UTILS_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STUART_UTILS_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STUART_UTILS_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STUART_UTILS_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVBI_CID
 */
#define TRACE_STVBI_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STVBI_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STVBI_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVBI_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STVBI_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STVBI_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVBI_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STVBI_CID: STVBI_CC_CID
 */
#define TRACE_STVBI_CC_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STVBI_CC_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STVBI_CC_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_CC_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVBI_CC_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVBI_CC_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_CC_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
 * STVBI_CID: STVBI_CGMS_CID
 */
#define TRACE_STVBI_CGMS_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STVBI_CGMS_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STVBI_CGMS_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STVBI_CGMS_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVBI_CGMS_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_CGMS_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STVBI_CGMS_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STVBI_CID: STVBI_CORE_CID
 */
#define TRACE_STVBI_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STVBI_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STVBI_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STVBI_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVBI_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STVBI_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STVBI_CID: STVBI_HAL_CID
 */
#define TRACE_STVBI_HAL_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STVBI_HAL_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STVBI_HAL_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_HAL_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVBI_HAL_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_HAL_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_HAL_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STVBI_CID: STVBI_IOCTL_CID
 */
#define TRACE_STVBI_IOCTL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STVBI_IOCTL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STVBI_IOCTL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STVBI_IOCTL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_IOCTL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STVBI_IOCTL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STVBI_IOCTL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STVBI_CID: STVBI_MV_CID
 */
#define TRACE_STVBI_MV_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STVBI_MV_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STVBI_MV_CID_WARNING_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_MV_CID_INFO_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVBI_MV_CID_API_IN_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVBI_MV_CID_API_OUT_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_MV_CID_USER_ACTIVATED                                     STTRACE_OFF
/*
 * STVBI_CID: STVBI_POWER_CID
 */
#define TRACE_STVBI_POWER_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STVBI_POWER_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STVBI_POWER_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STVBI_POWER_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_POWER_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STVBI_POWER_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STVBI_POWER_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STVBI_CID: STVBI_SRC_CID
 */
#define TRACE_STVBI_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STVBI_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STVBI_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVBI_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STVBI_CID: STVBI_TTX_CID
 */
#define TRACE_STVBI_TTX_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STVBI_TTX_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STVBI_TTX_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_TTX_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVBI_TTX_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_TTX_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_TTX_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STVBI_CID: STVBI_VPS_CID
 */
#define TRACE_STVBI_VPS_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STVBI_VPS_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STVBI_VPS_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_VPS_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVBI_VPS_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVBI_VPS_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVBI_VPS_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STVID_CID
 */
#define TRACE_STVID_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STVID_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STVID_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVID_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STVID_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STVID_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVID_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STVID_CID: STVID_API_CID
 */
#define TRACE_STVID_API_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STVID_API_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STVID_API_CID_WARNING_ACTIVATED                                 STTRACE_ON
#define TRACE_STVID_API_CID_INFO_ACTIVATED                                    STTRACE_ON
#define TRACE_STVID_API_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVID_API_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVID_API_CID_USER_ACTIVATED                                    STTRACE_ON
/*
 * STVID_CID: STVID_AVSYNC_CID
 */
#define TRACE_STVID_AVSYNC_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_AVSYNC_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_AVSYNC_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_AVSYNC_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVID_AVSYNC_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_AVSYNC_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_AVSYNC_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVID_CID: STVID_BUFFERS_CID
 */
#define TRACE_STVID_BUFFERS_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVID_BUFFERS_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVID_BUFFERS_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVID_BUFFERS_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVID_BUFFERS_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_BUFFERS_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVID_BUFFERS_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVID_CID: STVID_CORE_CID
 */
#define TRACE_STVID_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STVID_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STVID_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STVID_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVID_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVID_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STVID_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STVID_CID: STVID_DECODE_CID
 */
#define TRACE_STVID_DECODE_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_DECODE_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_DECODE_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_DECODE_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVID_DECODE_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_DECODE_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_DECODE_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVID_CID: STVID_DISPLAY_CID
 */
#define TRACE_STVID_DISPLAY_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVID_DISPLAY_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVID_DISPLAY_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVID_DISPLAY_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVID_DISPLAY_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_DISPLAY_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVID_DISPLAY_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVID_CID: STVID_INJECT_CID
 */
#define TRACE_STVID_INJECT_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_INJECT_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_INJECT_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_INJECT_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVID_INJECT_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_INJECT_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_INJECT_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVID_CID: STVID_ORDQUEUE_CID
 */
#define TRACE_STVID_ORDQUEUE_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STVID_ORDQUEUE_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STVID_ORDQUEUE_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STVID_ORDQUEUE_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_ORDQUEUE_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STVID_ORDQUEUE_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STVID_ORDQUEUE_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STVID_CID: STVID_POWER_CID
 */
#define TRACE_STVID_POWER_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STVID_POWER_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STVID_POWER_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_POWER_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVID_POWER_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STVID_POWER_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_POWER_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STVID_CID: STVID_PRODUCER_CID
 */
#define TRACE_STVID_PRODUCER_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STVID_PRODUCER_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STVID_PRODUCER_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STVID_PRODUCER_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_PRODUCER_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STVID_PRODUCER_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STVID_PRODUCER_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STVID_CID: STVID_SPARE1_CID
 */
#define TRACE_STVID_SPARE1_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_SPARE1_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_SPARE1_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_SPARE1_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVID_SPARE1_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_SPARE1_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_SPARE1_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVID_CID: STVID_SPARE2_CID
 */
#define TRACE_STVID_SPARE2_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_SPARE2_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_SPARE2_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_SPARE2_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVID_SPARE2_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_SPARE2_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_SPARE2_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVID_CID: STVID_SPARE3_CID
 */
#define TRACE_STVID_SPARE3_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_SPARE3_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_SPARE3_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_SPARE3_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVID_SPARE3_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_SPARE3_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_SPARE3_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVID_CID: STVID_SPARE4_CID
 */
#define TRACE_STVID_SPARE4_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_SPARE4_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVID_SPARE4_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_SPARE4_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVID_SPARE4_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_SPARE4_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVID_SPARE4_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVID_CID: STVID_SPEED_CID
 */
#define TRACE_STVID_SPEED_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STVID_SPEED_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STVID_SPEED_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_SPEED_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVID_SPEED_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STVID_SPEED_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_SPEED_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STVID_CID: STVID_TRICKMOD_CID
 */
#define TRACE_STVID_TRICKMOD_CID_FATAL_ACTIVATED                              STTRACE_ON
#define TRACE_STVID_TRICKMOD_CID_ERROR_ACTIVATED                              STTRACE_ON
#define TRACE_STVID_TRICKMOD_CID_WARNING_ACTIVATED                            STTRACE_OFF
#define TRACE_STVID_TRICKMOD_CID_INFO_ACTIVATED                               STTRACE_OFF
#define TRACE_STVID_TRICKMOD_CID_API_IN_ACTIVATED                             STTRACE_OFF
#define TRACE_STVID_TRICKMOD_CID_API_OUT_ACTIVATED                            STTRACE_OFF
#define TRACE_STVID_TRICKMOD_CID_USER_ACTIVATED                               STTRACE_OFF
/*
 * STVIN_CID
 */
#define TRACE_STVIN_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STVIN_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STVIN_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVIN_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STVIN_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STVIN_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVIN_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STVIN_CID: STVIN_API_CID
 */
#define TRACE_STVIN_API_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STVIN_API_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STVIN_API_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_API_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVIN_API_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVIN_API_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_API_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STVIN_CID: STVIN_CORE_CID
 */
#define TRACE_STVIN_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STVIN_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STVIN_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STVIN_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVIN_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STVIN_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STVIN_CID: STVIN_HAL_CID
 */
#define TRACE_STVIN_HAL_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STVIN_HAL_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STVIN_HAL_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_HAL_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVIN_HAL_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVIN_HAL_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_HAL_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STVIN_CID: STVIN_IOCTL_CID
 */
#define TRACE_STVIN_IOCTL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STVIN_IOCTL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STVIN_IOCTL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STVIN_IOCTL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVIN_IOCTL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STVIN_IOCTL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STVIN_IOCTL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STVIN_CID: STVIN_IPRC_CID
 */
#define TRACE_STVIN_IPRC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STVIN_IPRC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STVIN_IPRC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STVIN_IPRC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVIN_IPRC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_IPRC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STVIN_IPRC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STVIN_CID: STVIN_POWER_CID
 */
#define TRACE_STVIN_POWER_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STVIN_POWER_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STVIN_POWER_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STVIN_POWER_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVIN_POWER_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STVIN_POWER_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STVIN_POWER_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STVIN_CID: STVIN_SPARE1_CID
 */
#define TRACE_STVIN_SPARE1_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVIN_SPARE1_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVIN_SPARE1_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVIN_SPARE1_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_SPARE1_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVIN_SPARE1_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVIN_SPARE1_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVIN_CID: STVIN_SPARE2_CID
 */
#define TRACE_STVIN_SPARE2_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVIN_SPARE2_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVIN_SPARE2_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVIN_SPARE2_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_SPARE2_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVIN_SPARE2_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVIN_SPARE2_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVIN_CID: STVIN_SPARE3_CID
 */
#define TRACE_STVIN_SPARE3_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVIN_SPARE3_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVIN_SPARE3_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVIN_SPARE3_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_SPARE3_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVIN_SPARE3_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVIN_SPARE3_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVIN_CID: STVIN_SPARE4_CID
 */
#define TRACE_STVIN_SPARE4_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVIN_SPARE4_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVIN_SPARE4_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVIN_SPARE4_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_SPARE4_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVIN_SPARE4_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVIN_SPARE4_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVIN_CID: STVIN_SRC_CID
 */
#define TRACE_STVIN_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STVIN_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STVIN_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVIN_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVIN_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVIN_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STVMIX_CID
 */
#define TRACE_STVMIX_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STVMIX_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STVMIX_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVMIX_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STVMIX_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVMIX_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVMIX_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STVMIX_CID: STVMIX_CORE_CID
 */
#define TRACE_STVMIX_CORE_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STVMIX_CORE_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STVMIX_CORE_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STVMIX_CORE_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVMIX_CORE_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STVMIX_CORE_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STVMIX_CORE_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STVMIX_CID: STVMIX_IOCTL_CID
 */
#define TRACE_STVMIX_IOCTL_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVMIX_IOCTL_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVMIX_IOCTL_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVMIX_IOCTL_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVMIX_IOCTL_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVMIX_IOCTL_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVMIX_IOCTL_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVMIX_CID: STVMIX_SPARE1_CID
 */
#define TRACE_STVMIX_SPARE1_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVMIX_SPARE1_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVMIX_SPARE1_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVMIX_SPARE1_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVMIX_SPARE1_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVMIX_SPARE1_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVMIX_SPARE1_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVMIX_CID: STVMIX_SPARE2_CID
 */
#define TRACE_STVMIX_SPARE2_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVMIX_SPARE2_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVMIX_SPARE2_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVMIX_SPARE2_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVMIX_SPARE2_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVMIX_SPARE2_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVMIX_SPARE2_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVMIX_CID: STVMIX_SPARE3_CID
 */
#define TRACE_STVMIX_SPARE3_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVMIX_SPARE3_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVMIX_SPARE3_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVMIX_SPARE3_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVMIX_SPARE3_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVMIX_SPARE3_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVMIX_SPARE3_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVMIX_CID: STVMIX_SPARE4_CID
 */
#define TRACE_STVMIX_SPARE4_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVMIX_SPARE4_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVMIX_SPARE4_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVMIX_SPARE4_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVMIX_SPARE4_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVMIX_SPARE4_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVMIX_SPARE4_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVMIX_CID: STVMIX_SRC_CID
 */
#define TRACE_STVMIX_SRC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STVMIX_SRC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STVMIX_SRC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STVMIX_SRC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVMIX_SRC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVMIX_SRC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STVMIX_SRC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STVOUT_CID
 */
#define TRACE_STVOUT_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STVOUT_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STVOUT_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVOUT_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STVOUT_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVOUT_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVOUT_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STVOUT_CID: STVOUT_CMD_CID
 */
#define TRACE_STVOUT_CMD_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STVOUT_CMD_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STVOUT_CMD_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STVOUT_CMD_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVOUT_CMD_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVOUT_CMD_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STVOUT_CMD_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STVOUT_CID: STVOUT_CORE_CID
 */
#define TRACE_STVOUT_CORE_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STVOUT_CORE_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STVOUT_CORE_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STVOUT_CORE_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVOUT_CORE_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STVOUT_CORE_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STVOUT_CORE_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STVOUT_CID: STVOUT_IOCTL_CID
 */
#define TRACE_STVOUT_IOCTL_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVOUT_IOCTL_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVOUT_IOCTL_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVOUT_IOCTL_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVOUT_IOCTL_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVOUT_IOCTL_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVOUT_IOCTL_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVOUT_CID: STVOUT_SPARE1_CID
 */
#define TRACE_STVOUT_SPARE1_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVOUT_SPARE1_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVOUT_SPARE1_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVOUT_SPARE1_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVOUT_SPARE1_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVOUT_SPARE1_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVOUT_SPARE1_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVOUT_CID: STVOUT_SPARE2_CID
 */
#define TRACE_STVOUT_SPARE2_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVOUT_SPARE2_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVOUT_SPARE2_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVOUT_SPARE2_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVOUT_SPARE2_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVOUT_SPARE2_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVOUT_SPARE2_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVOUT_CID: STVOUT_SPARE3_CID
 */
#define TRACE_STVOUT_SPARE3_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVOUT_SPARE3_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVOUT_SPARE3_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVOUT_SPARE3_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVOUT_SPARE3_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVOUT_SPARE3_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVOUT_SPARE3_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVOUT_CID: STVOUT_SPARE4_CID
 */
#define TRACE_STVOUT_SPARE4_CID_FATAL_ACTIVATED                               STTRACE_ON
#define TRACE_STVOUT_SPARE4_CID_ERROR_ACTIVATED                               STTRACE_ON
#define TRACE_STVOUT_SPARE4_CID_WARNING_ACTIVATED                             STTRACE_OFF
#define TRACE_STVOUT_SPARE4_CID_INFO_ACTIVATED                                STTRACE_OFF
#define TRACE_STVOUT_SPARE4_CID_API_IN_ACTIVATED                              STTRACE_OFF
#define TRACE_STVOUT_SPARE4_CID_API_OUT_ACTIVATED                             STTRACE_OFF
#define TRACE_STVOUT_SPARE4_CID_USER_ACTIVATED                                STTRACE_OFF
/*
 * STVOUT_CID: STVOUT_SRC_CID
 */
#define TRACE_STVOUT_SRC_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STVOUT_SRC_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STVOUT_SRC_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STVOUT_SRC_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVOUT_SRC_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVOUT_SRC_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STVOUT_SRC_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STVTG_CID
 */
#define TRACE_STVTG_CID_FATAL_ACTIVATED                                       STTRACE_ON
#define TRACE_STVTG_CID_ERROR_ACTIVATED                                       STTRACE_ON
#define TRACE_STVTG_CID_WARNING_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVTG_CID_INFO_ACTIVATED                                        STTRACE_OFF
#define TRACE_STVTG_CID_API_IN_ACTIVATED                                      STTRACE_OFF
#define TRACE_STVTG_CID_API_OUT_ACTIVATED                                     STTRACE_OFF
#define TRACE_STVTG_CID_USER_ACTIVATED                                        STTRACE_OFF
/*
 * STVTG_CID: STVTG_CORE_CID
 */
#define TRACE_STVTG_CORE_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STVTG_CORE_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STVTG_CORE_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STVTG_CORE_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STVTG_CORE_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVTG_CORE_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STVTG_CORE_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STVTG_CID: STVTG_IOCTL_CID
 */
#define TRACE_STVTG_IOCTL_CID_FATAL_ACTIVATED                                 STTRACE_ON
#define TRACE_STVTG_IOCTL_CID_ERROR_ACTIVATED                                 STTRACE_ON
#define TRACE_STVTG_IOCTL_CID_WARNING_ACTIVATED                               STTRACE_OFF
#define TRACE_STVTG_IOCTL_CID_INFO_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVTG_IOCTL_CID_API_IN_ACTIVATED                                STTRACE_OFF
#define TRACE_STVTG_IOCTL_CID_API_OUT_ACTIVATED                               STTRACE_OFF
#define TRACE_STVTG_IOCTL_CID_USER_ACTIVATED                                  STTRACE_OFF
/*
 * STVTG_CID: STVTG_SPARE1_CID
 */
#define TRACE_STVTG_SPARE1_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVTG_SPARE1_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVTG_SPARE1_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVTG_SPARE1_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVTG_SPARE1_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVTG_SPARE1_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVTG_SPARE1_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVTG_CID: STVTG_SPARE2_CID
 */
#define TRACE_STVTG_SPARE2_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVTG_SPARE2_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVTG_SPARE2_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVTG_SPARE2_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVTG_SPARE2_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVTG_SPARE2_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVTG_SPARE2_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVTG_CID: STVTG_SPARE3_CID
 */
#define TRACE_STVTG_SPARE3_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVTG_SPARE3_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVTG_SPARE3_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVTG_SPARE3_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVTG_SPARE3_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVTG_SPARE3_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVTG_SPARE3_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVTG_CID: STVTG_SPARE4_CID
 */
#define TRACE_STVTG_SPARE4_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STVTG_SPARE4_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STVTG_SPARE4_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STVTG_SPARE4_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVTG_SPARE4_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STVTG_SPARE4_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STVTG_SPARE4_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STVTG_CID: STVTG_SRC_CID
 */
#define TRACE_STVTG_SRC_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STVTG_SRC_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STVTG_SRC_CID_WARNING_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVTG_SRC_CID_INFO_ACTIVATED                                    STTRACE_OFF
#define TRACE_STVTG_SRC_CID_API_IN_ACTIVATED                                  STTRACE_OFF
#define TRACE_STVTG_SRC_CID_API_OUT_ACTIVATED                                 STTRACE_OFF
#define TRACE_STVTG_SRC_CID_USER_ACTIVATED                                    STTRACE_OFF
/*
 * STXCPU_CID
 */
#define TRACE_STXCPU_CID_FATAL_ACTIVATED                                      STTRACE_ON
#define TRACE_STXCPU_CID_ERROR_ACTIVATED                                      STTRACE_ON
#define TRACE_STXCPU_CID_WARNING_ACTIVATED                                    STTRACE_OFF
#define TRACE_STXCPU_CID_INFO_ACTIVATED                                       STTRACE_OFF
#define TRACE_STXCPU_CID_API_IN_ACTIVATED                                     STTRACE_OFF
#define TRACE_STXCPU_CID_API_OUT_ACTIVATED                                    STTRACE_OFF
#define TRACE_STXCPU_CID_USER_ACTIVATED                                       STTRACE_OFF
/*
 * STXCPU_CID : STXCPU_API_CID
 */
#define TRACE_STXCPU_API_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STXCPU_API_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STXCPU_API_CID_WARNING_ACTIVATED                                STTRACE_OFF
#define TRACE_STXCPU_API_CID_API_IN_ACTIVATED                                 STTRACE_OFF
#define TRACE_STXCPU_API_CID_API_OUT_ACTIVATED                                STTRACE_OFF
#define TRACE_STXCPU_API_CID_INFO_ACTIVATED                                   STTRACE_OFF
#define TRACE_STXCPU_API_CID_USER_ACTIVATED                                   STTRACE_OFF
/*
 * STXCPU_CID : STXCPU_STBUS_MEMORY_CID
 */
#define TRACE_STXCPU_STBUS_MEMORY_CID_ERROR_ACTIVATED                         STTRACE_ON
#define TRACE_STXCPU_STBUS_MEMORY_CID_FATAL_ACTIVATED                         STTRACE_ON
#define TRACE_STXCPU_STBUS_MEMORY_CID_WARNING_ACTIVATED                       STTRACE_OFF
#define TRACE_STXCPU_STBUS_MEMORY_CID_API_IN_ACTIVATED                        STTRACE_OFF
#define TRACE_STXCPU_STBUS_MEMORY_CID_API_OUT_ACTIVATED                       STTRACE_OFF
#define TRACE_STXCPU_STBUS_MEMORY_CID_INFO_ACTIVATED                          STTRACE_OFF
#define TRACE_STXCPU_STBUS_MEMORY_CID_USER_ACTIVATED                          STTRACE_OFF
/*
 * STXCPU_CID : STXCPU_STBUS_MBX_CID
 */
#define TRACE_STXCPU_STBUS_MBX_CID_ERROR_ACTIVATED                            STTRACE_ON
#define TRACE_STXCPU_STBUS_MBX_CID_FATAL_ACTIVATED                            STTRACE_ON
#define TRACE_STXCPU_STBUS_MBX_CID_WARNING_ACTIVATED                          STTRACE_OFF
#define TRACE_STXCPU_STBUS_MBX_CID_API_OUT_ACTIVATED                          STTRACE_OFF
#define TRACE_STXCPU_STBUS_MBX_CID_API_IN_ACTIVATED                           STTRACE_OFF
#define TRACE_STXCPU_STBUS_MBX_CID_INFO_ACTIVATED                             STTRACE_OFF
#define TRACE_STXCPU_STBUS_MBX_CID_USER_ACTIVATED                             STTRACE_OFF
/*
 * STXCPU_CID : STXCPU_STBUS_TRANSPORT_CID
 */
#define TRACE_STXCPU_STBUS_TRANSPORT_CID_ERROR_ACTIVATED                      STTRACE_ON
#define TRACE_STXCPU_STBUS_TRANSPORT_CID_FATAL_ACTIVATED                      STTRACE_ON
#define TRACE_STXCPU_STBUS_TRANSPORT_CID_WARNING_ACTIVATED                    STTRACE_OFF
#define TRACE_STXCPU_STBUS_TRANSPORT_CID_API_IN_ACTIVATED                     STTRACE_OFF
#define TRACE_STXCPU_STBUS_TRANSPORT_CID_API_OUT_ACTIVATED                    STTRACE_OFF
#define TRACE_STXCPU_STBUS_TRANSPORT_CID_INFO_ACTIVATED                       STTRACE_OFF
#define TRACE_STXCPU_STBUS_TRANSPORT_CID_USER_ACTIVATED                       STTRACE_OFF
/*
 * STXCPU_CID : STXCPU_STBUS_QUEUE_CID
 */
#define TRACE_STXCPU_STBUS_QUEUE_CID_ERROR_ACTIVATED                          STTRACE_ON
#define TRACE_STXCPU_STBUS_QUEUE_CID_FATAL_ACTIVATED                          STTRACE_ON
#define TRACE_STXCPU_STBUS_QUEUE_CID_WARNING_ACTIVATED                        STTRACE_OFF
#define TRACE_STXCPU_STBUS_QUEUE_CID_API_IN_ACTIVATED                         STTRACE_OFF
#define TRACE_STXCPU_STBUS_QUEUE_CID_API_OUT_ACTIVATED                        STTRACE_OFF
#define TRACE_STXCPU_STBUS_QUEUE_CID_INFO_ACTIVATED                           STTRACE_OFF
#define TRACE_STXCPU_STBUS_QUEUE_CID_USER_ACTIVATED                           STTRACE_OFF
/*
 * STXCPU_CID : STXCPU_STICS_CID
 */
#define TRACE_STXCPU_STICS_CID_ERROR_ACTIVATED                                STTRACE_ON
#define TRACE_STXCPU_STICS_CID_FATAL_ACTIVATED                                STTRACE_ON
#define TRACE_STXCPU_STICS_CID_WARNING_ACTIVATED                              STTRACE_OFF
#define TRACE_STXCPU_STICS_CID_API_IN_ACTIVATED                               STTRACE_OFF
#define TRACE_STXCPU_STICS_CID_API_OUT_ACTIVATED                              STTRACE_OFF
#define TRACE_STXCPU_STICS_CID_INFO_ACTIVATED                                 STTRACE_OFF
#define TRACE_STXCPU_STICS_CID_USER_ACTIVATED                                 STTRACE_OFF
/*
 * STXCPU_CID : STXCPU_LINUX_CORE_CID
 */
#define TRACE_STXCPU_LINUX_CORE_CID_ERROR_ACTIVATED                           STTRACE_ON
#define TRACE_STXCPU_LINUX_CORE_CID_FATAL_ACTIVATED                           STTRACE_ON
#define TRACE_STXCPU_LINUX_CORE_CID_WARNING_ACTIVATED                         STTRACE_OFF
#define TRACE_STXCPU_LINUX_CORE_CID_API_IN_ACTIVATED                          STTRACE_OFF
#define TRACE_STXCPU_LINUX_CORE_CID_API_OUT_ACTIVATED                         STTRACE_OFF
#define TRACE_STXCPU_LINUX_CORE_CID_INFO_ACTIVATED                            STTRACE_OFF
#define TRACE_STXCPU_LINUX_CORE_CID_USER_ACTIVATED                            STTRACE_OFF

/*
* STRM_CID 
*/
#define TRACE_STRM_CID_FATAL_ACTIVATED                                        STTRACE_ON
#define TRACE_STRM_CID_ERROR_ACTIVATED                                        STTRACE_ON
#define TRACE_STRM_CID_WARNING_ACTIVATED                                      STTRACE_ON
#define TRACE_STRM_CID_INFO_ACTIVATED                                         STTRACE_ON
#define TRACE_STRM_CID_API_IN_ACTIVATED                                       STTRACE_ON
#define TRACE_STRM_CID_API_OUT_ACTIVATED                                      STTRACE_ON
#define TRACE_STRM_CID_USER_ACTIVATED                                         STTRACE_ON
/*
* STRM_CORE_CID
*/
#define TRACE_STRM_CORE_CID_FATAL_ACTIVATED                                   STTRACE_ON
#define TRACE_STRM_CORE_CID_ERROR_ACTIVATED                                   STTRACE_ON
#define TRACE_STRM_CORE_CID_WARNING_ACTIVATED                                 STTRACE_ON
#define TRACE_STRM_CORE_CID_INFO_ACTIVATED                                    STTRACE_ON
#define TRACE_STRM_CORE_CID_API_IN_ACTIVATED                                  STTRACE_ON
#define TRACE_STRM_CORE_CID_API_OUT_ACTIVATED                                 STTRACE_ON
#define TRACE_STRM_CORE_CID_USER_ACTIVATED                                    STTRACE_ON
/*
* STRM_IOCTL_CID
*/
#define TRACE_STRM_IOCTL_CID_FATAL_ACTIVATED                                  STTRACE_ON
#define TRACE_STRM_IOCTL_CID_ERROR_ACTIVATED                                  STTRACE_ON
#define TRACE_STRM_IOCTL_CID_WARNING_ACTIVATED                                STTRACE_ON
#define TRACE_STRM_IOCTL_CID_INFO_ACTIVATED                                   STTRACE_ON
#define TRACE_STRM_IOCTL_CID_API_IN_ACTIVATED                                 STTRACE_ON
#define TRACE_STRM_IOCTL_CID_API_OUT_ACTIVATED                                STTRACE_ON
#define TRACE_STRM_IOCTL_CID_USER_ACTIVATED                                   STTRACE_ON
/*
* STRM_TEST_CID
*/
#define TRACE_STRM_TEST_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STRM_TEST_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STRM_TEST_CID_WARNING_ACTIVATED                                  STTRACE_ON
#define TRACE_STRM_TEST_CID_INFO_ACTIVATED                                     STTRACE_ON
#define TRACE_STRM_TEST_CID_API_IN_ACTIVATED                                   STTRACE_ON
#define TRACE_STRM_TEST_CID_API_OUT_ACTIVATED                                  STTRACE_ON
#define TRACE_STRM_TEST_CID_USER_ACTIVATED                                     STTRACE_ON

/*
* STRM_SRC_CID
*/
#define TRACE_STRM_SRC_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STRM_SRC_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STRM_SRC_CID_WARNING_ACTIVATED                                  STTRACE_ON
#define TRACE_STRM_SRC_CID_INFO_ACTIVATED                                     STTRACE_ON
#define TRACE_STRM_SRC_CID_API_IN_ACTIVATED                                   STTRACE_ON
#define TRACE_STRM_SRC_CID_API_OUT_ACTIVATED                                  STTRACE_ON
#define TRACE_STRM_SRC_CID_USER_ACTIVATED                                     STTRACE_ON

/*
* STRM_STAPP_CID
*/
#define TRACE_STRM_STAPP_CID_FATAL_ACTIVATED                                    STTRACE_ON
#define TRACE_STRM_STAPP_CID_ERROR_ACTIVATED                                    STTRACE_ON
#define TRACE_STRM_STAPP_CID_WARNING_ACTIVATED                                  STTRACE_ON
#define TRACE_STRM_STAPP_CID_INFO_ACTIVATED                                     STTRACE_ON
#define TRACE_STRM_STAPP_CID_API_IN_ACTIVATED                                   STTRACE_ON
#define TRACE_STRM_STAPP_CID_API_OUT_ACTIVATED                                  STTRACE_ON
#define TRACE_STRM_STAPP_CID_USER_ACTIVATED                                     STTRACE_ON

#endif /* #ifndef STTRACE_H */

