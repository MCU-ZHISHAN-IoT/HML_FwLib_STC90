/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some definitions for operating ISP/IAP module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90 series
 * @Version:V0
 */

#ifndef ___ISP_H___
#define ___ISP_H___

#include <stc90.h>
#include <stdbool.h>

#include "util.h"
#include "macro.h"

typedef enum
{
	ISP_CMMD_idle  = 0x0,
	ISP_CMMD_read  = 0x1,
	ISP_CMMD_write = 0x2,
	ISP_CMMD_erase = 0x3,
} ISP_CMMD;

/* ---------- addr define --------- */

#if (MCU_MODEL == MCU_STC90C51RC)  || \
    (MCU_MODEL == MCU_STC90LE51RC)
	#define ISP_beginAddress 0x1000
	#define ISP_endAddress 0x33FF
	
#elif \
    (MCU_MODEL == MCU_STC90C52RC)  || \
    (MCU_MODEL == MCU_STC90LE52RC)
	#define ISP_beginAddress 0x2000
	#define ISP_endAddress 0x33FF
	
#elif \
	(MCU_MODEL == MCU_STC90C12RC)  || \
    (MCU_MODEL == MCU_STC90LE12RC)
	#define ISP_beginAddress 0x3000
	#define ISP_endAddress 0x33FF
	
#else 
	#define ISP_endAddress 0xF3FF
	#if (MCU_MODEL == MCU_STC90C54RDP)    || \
        (MCU_MODEL == MCU_STC90LE54RDP)
		#define ISP_beginAddress 0x4000
	#elif (MCU_MODEL == MCU_STC90C58RDP)  || \
	      (MCU_MODEL == MCU_STC90LE58RDP)
		#define ISP_beginAddress 0x8000
	#elif (MCU_MODEL == MCU_STC90C510RDP) || \
	      (MCU_MODEL == MCU_STC90LE510RDP)
		#define ISP_beginAddress 0xA000
	#elif (MCU_MODEL == MCU_STC90C512RDP) || \
	      (MCU_MODEL == MCU_STC90LE512RDP)
		#define ISP_beginAddress 0xC000
	#elif (MCU_MODEL == MCU_STC90C514RDP) || \
	      (MCU_MODEL == MCU_STC90LE514RDP)
		#define ISP_beginAddress 0xE000
	#endif /* else */

#endif/* MCU_MODEL RC/RDP */
	
/* ---------- @function --------- */
void ISP_cmd(Action a);
bool ISP_eraseByte(unsigned int addr);
void ISP_idle(void);
unsigned char ISP_readByte(unsigned int addr);
void ISP_setAddress(unsigned int addr);
void ISP_setCommand(ISP_CMMD cmd);
void ISP_trig(void);
void ISP_writeByte(unsigned int addr,unsigned char byte);

#endif /*___ISP_H___*/
