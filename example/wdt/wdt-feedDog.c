/*
 * @Author:
 *  #Amy Chung | zhongliguo(at)zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:show how to use firmware library to configure and feed watchdog
 * @Test-board:ZS5110
 * @Test-mcu:STC90C53RC
 * @Version:V0
 */

#include "conf.h"

/*
 * @Prototype:void sys_init(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:initial MCU
 */
void sys_init(void)
{
    UART_configTypeDef uc;
    
    uc.baudrate          = 9600;
    uc.baudGenerator     = PERIPH_TIM_1;
    uc.interruptState    = ENABLE;
    uc.interruptPriority = INTR_priority_0;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;
    
    UART_config(&uc);
    enableAllInterrupts();
}

/* ----- @main ----- */
void main(void)
{
    sys_init();
    UART_sendString("MCU boot");
    WDT_setPrescale(WDT_prescale_32);
    WDT_cmd(ENABLE);
    
    while(true)
    {
        /*feed watchdog per 500ms*/
        sleep(500);
        WDT_clear();
        UART_sendString("root@localboard:Watch dog has been fed\r\n");
    }
}
