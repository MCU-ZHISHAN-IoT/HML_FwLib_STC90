/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some macro definitions that used frequently
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90 series
 * @Version:V0
 */

#ifndef ___MACRO_H___
#define ___MACRO_H___

/* typedef */	
typedef unsigned char u8;
typedef unsigned int  u16;

typedef enum
{
	RESET = 0x0,
	SET = !RESET
}FunctionalState;

typedef enum
{
	DISABLE = 0x0,
	ENABLE = !DISABLE
}Action;

/* mark model */
#define MCU_NULL          0
#define MCU_STC90C51RC    1
#define MCU_STC90LE51RC   1
#define MCU_STC90C52RC    2
#define MCU_STC90LE52RC   2
#define MCU_STC90C12RC    3
#define MCU_STC90LE12RC   3
#define MCU_STC90C54RDP    4
#define MCU_STC90LE54RDP   4
#define MCU_STC90C58RDP    5
#define MCU_STC90LE58RDP   5
#define MCU_STC90C510RDP   6
#define MCU_STC90LE510RDP  6
#define MCU_STC90C512RDP   7
#define MCU_STC90LE512RDP  7
#define MCU_STC90C514RDP   8
#define MCU_STC90LE514RDP  8

/* ---------- NEED TO BE SETTED ---------- */
#define MCU_MODEL MCU_STC90C52RC

/* config clock frequency */
#define _FRE_OSC_ 11059200L
//#define _FRE_OSC_ 12000000L

/* ---------- ---------- */

/* ---------- @run-time check --------- */
#if (MCU_MODEL == MCU_NULL)
	#error HML run-time check:not specify MCU model!(ERROR_CODE-0x01)
#endif /* MCU_MODEL */

#ifndef _FRE_OSC_
	#error HML run-time check:the firmware library need define extern clcok frequency!(ERROR_CODE-0x02)
#endif

#endif /* ___MACRO_H___ */
