/*
 * @Author:
 *  #Amy Chung | zhongliguo@zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:show how to use HML_FwLib_STC90 to control GPIO
 * @Test-board:ZS5110
 * @Test-mcu:STC90C53RC
 * @Version:V0
 */
 
#include "conf.h"

/* ----- @main ----- */
void main()
{
    GPIO_resetBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);
    while(true)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);
    }
}