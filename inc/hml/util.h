/*****************************************************************************/
/** 
 * \file        util.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       public operations
 * \note        
 * \version     v0.2
 * \ingroup     UTIL
******************************************************************************/

#ifndef ___UTIL_H___
#define ___UTIL_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hw/stc90.h"
#include "macro.h"

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/
/**
 *\brief: mark interrupt priority, lager number means higher priority
 */
typedef enum
{
    UTIL_interruptPriority_0 = 0x00,
    UTIL_interruptPriority_1 = 0x01,
    UTIL_interruptPriority_2 = 0x02,
    UTIL_interruptPriority_3 = 0x03,
} UTIL_interruptPriority;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void disableAllInterrupts(void);
void enableAllInterrupts(void);
void sleep(unsigned int t);

#endif
