/*****************************************************************************/
/** 
 * \file        macro.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML macro define
 * \note        
 * \version     v0.3
 * \ingroup     generic
******************************************************************************/

#ifndef ___HML_MACRO_H___
#define ___HML_MACRO_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/conf.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\brief: mark MCU model of STC90 series(suffix letter 'P' represents '+' )
 *        keep the same order with datasheet
 */
#define MCU_MODEL_GENERIC         0x01
#define MCU_MODEL_STC90C51        0x02
#define MCU_MODEL_STC90LE51       0x03
#define MCU_MODEL_STC90C52        0x03
#define MCU_MODEL_STC90LE52       0x04
#define MCU_MODEL_STC90C51RC      0x05
#define MCU_MODEL_STC90LE51RC     0x06
#define MCU_MODEL_STC90C52RC      0x07
#define MCU_MODEL_STC90LE52RC     0x08
#define MCU_MODEL_STC90C53RC      0x09
#define MCU_MODEL_STC90LE53RC     0x0A
#define MCU_MODEL_STC90C12RC      0x0B
#define MCU_MODEL_STC90LE12RC     0x0C
#define MCU_MODEL_STC90C54RDP     0x0D
#define MCU_MODEL_STC90LE54RDP    0x0E
#define MCU_MODEL_STC90C58RDP     0x0F
#define MCU_MODEL_STC90LE58RDP    0x10
#define MCU_MODEL_STC90C510RDP    0x11
#define MCU_MODEL_STC90LE510RDP   0x12
#define MCU_MODEL_STC90C512RDP    0x13
#define MCU_MODEL_STC90LE512RDP   0x14
#define MCU_MODEL_STC90C514RDP    0x15
#define MCU_MODEL_STC90LE514RDP   0x16
#define MCU_MODEL_STC90C516RDP    0x17
#define MCU_MODEL_STC90LE516RDP   0x18

/**
 *\brief: check macro for MCU model
 */
#define IS_STC90_MCU_MODEL(model)                \
    (                                            \
        (model == MCU_MODEL_GENERIC)       ||    \
        (model == MCU_MODEL_STC90C51)      ||    \
        (model == MCU_MODEL_STC90LE51)     ||    \
        (model == MCU_MODEL_STC90C52)      ||    \
        (model == MCU_MODEL_STC90LE52)     ||    \
        (model == MCU_MODEL_STC90C51RC)    ||    \
        (model == MCU_MODEL_STC90LE51RC)   ||    \
        (model == MCU_MODEL_STC90C52RC)    ||    \
        (model == MCU_MODEL_STC90LE52RC)   ||    \
        (model == MCU_MODEL_STC90C53RC)    ||    \
        (model == MCU_MODEL_STC90LE53RC)   ||    \
        (model == MCU_MODEL_STC90C12RC)    ||    \
        (model == MCU_MODEL_STC90LE12RC)   ||    \
        (model == MCU_MODEL_STC90C54RDP)   ||    \
        (model == MCU_MODEL_STC90LE54RDP)  ||    \
        (model == MCU_MODEL_STC90C58RDP)   ||    \
        (model == MCU_MODEL_STC90LE58RDP)  ||    \
        (model == MCU_MODEL_STC90C510RDP)  ||    \
        (model == MCU_MODEL_STC90LE510RDP) ||    \
        (model == MCU_MODEL_STC90C512RDP)  ||    \
        (model == MCU_MODEL_STC90LE512RDP) ||    \
        (model == MCU_MODEL_STC90C514RDP)  ||    \
        (model == MCU_MODEL_STC90LE514RDP) ||    \
        (model == MCU_MODEL_STC90C516RDP)  ||    \
        (model == MCU_MODEL_STC90LE516RDP)       \
    )

/**
 *\brief: judgment macro for ISP function
 */
#define IS_ISP_MODEL(model)                      \
    (                                            \
        (model == MCU_MODEL_STC90C51RC)    ||    \
        (model == MCU_MODEL_STC90LE51RC)   ||    \
        (model == MCU_MODEL_STC90C52RC)    ||    \
        (model == MCU_MODEL_STC90LE52RC)   ||    \
        (model == MCU_MODEL_STC90C12RC)    ||    \
        (model == MCU_MODEL_STC90LE12RC)   ||    \
        (model == MCU_MODEL_STC90C54RDP)   ||    \
        (model == MCU_MODEL_STC90LE54RDP)  ||    \
        (model == MCU_MODEL_STC90C58RDP)   ||    \
        (model == MCU_MODEL_STC90LE58RDP)  ||    \
        (model == MCU_MODEL_STC90C510RDP)  ||    \
        (model == MCU_MODEL_STC90LE510RDP) ||    \
        (model == MCU_MODEL_STC90C512RDP)  ||    \
        (model == MCU_MODEL_STC90LE512RDP) ||    \
        (model == MCU_MODEL_STC90C514RDP)  ||    \
        (model == MCU_MODEL_STC90LE514RDP)       \
    )

/**
 *\brief: compile select
 */
#if (__CONF_COMPILE_EXTI == 1)
    #define COMPILE_EXTI
#endif
#if (__CONF_COMPILE_GPIO == 1)
    #define COMPILE_GPIO
#endif
#if (__CONF_COMPILE_ISP == 1)
    #define COMPILE_ISP
#endif
#if (__CONF_COMPILE_MEM == 1)
    #define COMPILE_MEM
#endif
#if (__CONF_COMPILE_RST == 1)
    #define COMPILE_RST
#endif
#if (__CONF_COMPILE_TIM == 1)
    #define COMPILE_TIM
#endif
#if (__CONF_COMPILE_TIM2 == 1)
    #define COMPILE_TIM2
#endif
#if (__CONF_COMPILE_UART == 1)
    #define COMPILE_UART
#endif
#if (__CONF_COMPILE_UTIL == 1)
    #define COMPILE_UTIL
#endif
#if (__CONF_COMPILE_WDT == 1)
    #define COMPILE_WDT
#endif

/*****************************************************************************
 *                           run-time check                                  *
 *****************************************************************************/
/**
 *\brief: MCU clock configuration check
 */
#if (defined __CONF_FRE_CLKIN)
    #define MCU_FRE_CLK __CONF_FRE_CLKIN
#else
    #error HML run-time check: error: HML need define input clock frequency! (ERROR_CODE-0x01)
#endif

/**
 *\brief: MCU model check
 */
#if (defined __CONF_MCU_MODEL)
    #if IS_STC90_MCU_MODEL(__CONF_MCU_MODEL)
        #if (__CONF_MCU_MODEL == MCU_MODEL_GENERIC)
            #warning the value of macro HML_MCU_MODEL will be filled with MCU_MODEL_STC90C52RC
            #define HML_MCU_MODEL MCU_MODEL_STC90C52RC
        #else
            #define HML_MCU_MODEL __CONF_MCU_MODEL
        #endif
    #else
        #error HML run-time check: error: unknow or unsupported MCU model!(ERROR_CODE-0x02)
    #endif
#else
    #error HML run-time check: error: unspecify MCU model!(ERROR_CODE-0x03)
#endif

#if IS_ISP_MODEL(HML_MCU_MODEL)
    #define HAVE_ISP
#endif

/**
 *\brief: HML compile selection check
 */
#ifndef HAVE_ISP
    #ifdef COMPILE_ISP
        #error HML run-time check: error: specified MCU model does not suppport ISP function. (ERROR_CODE-0x04)
    #endif
#endif

#if (defined COMPILE_UART) && ((!defined COMPILE_TIM) || (!defined COMPILE_TIM2))
    #error HML run-time check: UART part need extern support, please enable macro __CONF_COMPILE_TIM  or __CONF_COMPILE_TIM2 at the same time(ERROR_CODE-0x05)
#endif

/**
 *\brief: SDCC version check
 */
#if (__SDCC_VERSION_MAJOR == 3)
    #if (__SDCC_VERSION_MINOR < 6)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x06)
    #endif
#else
    #if (__SDCC_VERSION_MAJOR < 3)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x06)
    #endif
#endif

#endif
