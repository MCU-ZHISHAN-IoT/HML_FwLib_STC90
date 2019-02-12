/*
 * @Author:
 *  #Amy Chung | zhongliguo@zhishan-iot.tk
 * @File-description:show how to use firmware library to
 *                   config and feed watchdog
 * @Required-complier:SDCC
 * @Support-mcu:STC micro STC90 series
 * @Version:V0
 */
#include "conf.h"

/*
 * @Protype:void sys_init(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:init MCU
 */
void sys_init(void)
{
    UART_configTypeDef uc;
    
    uc.baudrate = 9600;
    uc.baudGenerator = PERIPH_TIM_1;
    uc.interruptState = ENABLE;
    uc.interruptPriority = DISABLE;
    uc.mode = UART_mode_1;
    uc.multiBaudrate = DISABLE;
    uc.receiveState  = ENABLE;
    
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
        UART_sendString("root@localboard:Watch dog has been feeded\r\n");
    }
}
