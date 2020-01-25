/*****************************************************************************/
/** 
 * \file        conf.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML configurations, this file need to be modified by users
 * \note        
 * \version     v0.3
 * \ingroup     generic
******************************************************************************/

#ifndef ___HML_CONF_H___
#define ___HML_CONF_H___

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\brief: configure clock frequency of MCU
 */
#define __CONF_FRE_CLKIN 11059200L

/**
 *\brief: configure module of MCU
 */
#define __CONF_MCU_MODEL MCU_MODEL_STC90C52RC

/**
 *\brief: select HML module which take part in compilation
 */
#define __CONF_COMPILE_EXTI  1
#define __CONF_COMPILE_GPIO  1
#define __CONF_COMPILE_ISP   1
#define __CONF_COMPILE_MEM   1
#define __CONF_COMPILE_RST   1
#define __CONF_COMPILE_TIM   1
#define __CONF_COMPILE_TIM2  1
#define __CONF_COMPILE_UART  1
#define __CONF_COMPILE_UTIL  1
#define __CONF_COMPILE_WDT   1

#endif
