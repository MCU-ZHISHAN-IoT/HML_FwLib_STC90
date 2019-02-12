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
    TIM_configTypeDef tc;
    
    tc.function = TIM_function_tim;
    tc.interruptState = ENABLE;
    tc.interruptPriority = ENABLE;
    tc.mode = TIM_mode_1;
    tc.value = TIM_calculateValue(50000,TIM_mode_1);
    
    TIM_config(PERIPH_TIM_0,&tc);
    TIM_cmd(PERIPH_TIM_0,ENABLE);
    enableAllInterrupts();
}

void main(void)
{
	sys_init();
	while(true);
}

/*
 * @Protype:void TIM_isr(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:interrupt service function for TIM_0
 */
void TIM_isr(void) __interrupt TF0_VECTOR
{
    static int cnt = 0;
    
    /* per 500ms */
    cnt++;
    if(cnt == 10)
    {
        GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_2);
        cnt = 0;
    }
}
