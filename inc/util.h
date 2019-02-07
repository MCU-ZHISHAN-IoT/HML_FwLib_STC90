/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some public functions
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90 series
 * @Version:V0
 */

#ifndef ___UTIL_H___
#define ___UTIL_H___

/* ----- @header file ----- */
#include <stc90.h>
#include "macro.h"

/* ----- @function ----- */
void disableAllInterrupts(void);
void enableAllInterrupts(void);
void sleep(unsigned int t);
#endif
