/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:includes some definitions for operating ISP/IAP module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90 series
 * @Version:V0
 */

#ifndef ___ISP_H___
#define ___ISP_H___

/* ----- @header file ----- */
#include <stc89.h>
#include <stdbool.h>

#include "macro.h"
#include "util.h"

/* ----- @enumeration type ----- */
/* mark command */
typedef enum
{
    ISP_command_idle  = 0x0,
    ISP_command_read  = 0x1,
    ISP_command_write = 0x2,
    ISP_command_erase = 0x3
} ISP_command;

/* ---------- addr define --------- */

#if (_MCU_MODEL_ == _MCU_STC90C51RC_)  || \
    (_MCU_MODEL_ == _MCU_STC90LE51RC_)
    #define ISP_ADDR_START 0x1000
    #define ISP_ADDR_END 0x33FF
    
#elif \
    (_MCU_MODEL_ == _MCU_STC90C52RC_)  || \
    (_MCU_MODEL_ == _MCU_STC90LE52RC_)
    #define ISP_ADDR_START 0x2000
    #define ISP_ADDR_END 0x33FF
    
#elif \
    (_MCU_MODEL_ == _MCU_STC90C12RC_)  || \
    (_MCU_MODEL_ == _MCU_STC90LE12RC_)
    #define ISP_ADDR_START 0x3000
    #define ISP_ADDR_END 0x33FF
    
#else
    #define ISP_ADDR_END 0xF3FF
    #if (_MCU_MODEL_ == _MCU_STC90C54RD_)    || \
        (_MCU_MODEL_ == _MCU_STC90LE54RD_)
        #define ISP_ADDR_START 0x4000
    #elif (_MCU_MODEL_ == _MCU_STC90C58RD_)  || \
        (_MCU_MODEL_ == _MCU_STC90LE58RD_)
        #define ISP_ADDR_START 0x8000
    #elif (_MCU_MODEL_ == _MCU_STC90C510RD_) || \
    (_MCU_MODEL_ == _MCU_STC90LE510RD_)
        #define ISP_ADDR_START 0xA000
    #elif (_MCU_MODEL_ == _MCU_STC90C512RD_) || \
        (_MCU_MODEL_ == _MCU_STC90LE512RD_)
        #define ISP_ADDR_START 0xC000
    #elif (_MCU_MODEL_ == _MCU_STC90C514RD_) || \
        (_MCU_MODEL_ == _MCU_STC90LE514RD_)
        #define ISP_ADDR_START 0xE000
    #endif /* else */

#endif
    
/* ----- @function ----- */
void ISP_cmd(Action a);
bool ISP_eraseByte(unsigned int addr);
void ISP_idle(void);
unsigned char ISP_readByte(unsigned int addr);
void ISP_setAddress(unsigned int addr);
void ISP_setCommand(ISP_command cmd);
void ISP_trig(void);
bool ISP_writeByte(unsigned int addr,byte dat);

#endif
