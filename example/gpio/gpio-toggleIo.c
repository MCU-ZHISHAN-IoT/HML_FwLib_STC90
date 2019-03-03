/*
 * @Author:
 *  #Amy Chung | zhongliguo@zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:show how to use firmware library to control GPIO
 * @Required-complier:SDCC
 * @Support-mcu:STC micro STC90-RC/RD+ series
 * @Test-board:
 * @Test-mcu:
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