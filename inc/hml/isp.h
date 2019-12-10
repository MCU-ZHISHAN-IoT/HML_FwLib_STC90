/*****************************************************************************/
/** 
 * \file        isp.h
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for ISP module
 * \note        
 * \version     v0.2
 * \ingroup     ISP
******************************************************************************/

#ifndef ___ISP_H___
#define ___ISP_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include <stdbool.h>
/*****************************************************************************/
#include "util.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\brief: define ISP address
 */
#if (HML_MCU_MODEL == MCU_MODEL_STC90C51RC)      || \
    (HML_MCU_MODEL == MCU_MODEL_STC90LE51RC)
    #define ISP_ADDR_START 0x1000
    #define ISP_ADDR_END 0x33FF
#elif (HML_MCU_MODEL == MCU_MODEL_STC90C52RC)    || \
      (HML_MCU_MODEL == MCU_MODEL_STC90LE52RC)
    #define ISP_ADDR_START 0x2000
    #define ISP_ADDR_END 0x33FF
#elif (HML_MCU_MODEL == MCU_MODEL_STC90C12RC)    || \
      (HML_MCU_MODEL == MCU_MODEL_STC90LE12RC)
    #define ISP_ADDR_START 0x3000
    #define ISP_ADDR_END 0x33FF
#else
    #define ISP_ADDR_END 0xF3FF
    #if (HML_MCU_MODEL == MCU_MODEL_STC90C54RDP)      || \
        (HML_MCU_MODEL == MCU_MODEL_STC90LE54RDP)
        #define ISP_ADDR_START 0x4000
    #elif (HML_MCU_MODEL == MCU_MODEL_STC90C58RDP)    || \
          (HML_MCU_MODEL == MCU_MODEL_STC90LE58RDP)
        #define ISP_ADDR_START 0x8000
    #elif (HML_MCU_MODEL == MCU_MODEL_STC90C510RDP)   || \
          (HML_MCU_MODEL == MCU_MODEL_STC90LE510RDP)
        #define ISP_ADDR_START 0xA000
    #elif (HML_MCU_MODEL == MCU_MODEL_STC90C512RDP)   || \
          (HML_MCU_MODEL == MCU_MODEL_STC90LE512RDP)
        #define ISP_ADDR_START 0xC000
    #elif (HML_MCU_MODEL == MCU_MODEL_STC90C514RDP)   || \
          (HML_MCU_MODEL == MCU_MODEL_STC90LE514RDP)
        #define ISP_ADDR_START 0xE000
    #endif
#endif

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 *\brief: define ISP command
 */
typedef enum
{
    ISP_command_idle  = 0x0,
    ISP_command_read  = 0x1,
    ISP_command_write = 0x2,
    ISP_command_erase = 0x3
} ISP_command;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void ISP_cmd(Action a);
bool ISP_eraseByte(unsigned int addr);
void ISP_idle(void);
byte ISP_readByte(unsigned int addr);
void ISP_setAddress(unsigned int addr);
void ISP_setCommand(ISP_command cmd);
void ISP_trig(void);
bool ISP_writeByte(unsigned int addr,byte dat);

#endif
