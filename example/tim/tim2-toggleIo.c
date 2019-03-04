/*
 * @Author:
 *  #Amy Chung | zhongliguo@zhishan-iot.tk
 * @File-description:show how to use firmware library to
 *                   make a tim interruption
 * @Required-compiler:SDCC
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
    TIM2_configTypeDef tc;
    
    tc.function = TIM2_function_tim;
    tc.interruptState = ENABLE;
    tc.interruptPriority = ENABLE;
    tc.mode = TIM2_mode_0;
    tc.value = TIM2_calculateValue(50000);
    
    TIM2_config(&tc);
    TIM2_cmd(ENABLE);
    enableAllInterrupts();
}

void main(void)
{
    sys_init();
    while(true);
}

/*
 * @Protype:void TIM2_isr(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:interrupt service function for TIM2
 */
void TIM2_isr(void) __interrupt TF2_VECTOR
{
    static int cnt = 0;
    TIM2_clearFlag();
    
    /* per 500ms */
    cnt++;
    if(cnt == 10)
    {
        GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_2);
        cnt = 0;
    }
}
