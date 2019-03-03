/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:includes some definitions for operating gpio module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90-RC/RD+ series
 * @Version:V0
 */
#ifndef ___GPIO_H___
#define ___GPIO_H___

/* ----- @header file ----- */
#include "stc90.h"
#include "macro.h"

/* ----- @enumeration type ----- */
/* define port */
typedef enum
{
    PERIPH_GPIO_0 = 0x0,
    PERIPH_GPIO_1 = 0x1,
    PERIPH_GPIO_2 = 0x2,
    PERIPH_GPIO_3 = 0x3,
    PERIPH_GPIO_4 = 0x4
} PERIPH_GPIO;

/* mark pin */
typedef enum
{
    PERIPH_GPIO_PIN_0 = 0x01,
    PERIPH_GPIO_PIN_1 = 0x02,
    PERIPH_GPIO_PIN_2 = 0x04,
    PERIPH_GPIO_PIN_3 = 0x08,
    PERIPH_GPIO_PIN_4 = 0x10,
    PERIPH_GPIO_PIN_5 = 0x20,
    PERIPH_GPIO_PIN_6 = 0x40,
    PERIPH_GPIO_PIN_7 = 0x80
} PERIPH_GPIO_PIN;


/* ----- @function ----- */
void GPIO_configBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin,FunctionalState f);
void GPIO_configPort(PERIPH_GPIO gpio,byte val);
FunctionalState GPIO_getBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_resetBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_setBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_toggleBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_P45_cmd(Action a);

#endif
