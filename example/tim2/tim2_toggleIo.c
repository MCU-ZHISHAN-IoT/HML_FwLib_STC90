/*****************************************************************************/
/** 
 * \file        tim2_toggleIo.c
 * \author      Amy Chung | zhongliguo@zhishan-iot.tk
 * \date        
 * \brief       a example which shows how to toggle state of specified pin periodic
 *              via timers' interrupt
 * \note        
 * \version     v0.3
 * \ingroup     example
 * \remarks     test-board: ZS5110; test-MCU: STC90C53RC
******************************************************************************/

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/hml.h"
 
/*****************************************************************************/
/** 
 * \author      Amy Chung
 * \date        
 * \brief       initial MCU
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void sys_init(void)
{
    TIM2_configTypeDef tc;

    tc.function          = TIM2_function_tim;
    tc.interruptState    = ENABLE;
    tc.interruptPriority = UTIL_interruptPriority_0;
    tc.mode              = TIM2_mode_0;
    tc.value             = TIM2_calculateValue(50000);
    tc.reloadValue       = tc.value;

    TIM2_config(&tc);
    TIM2_cmd(ENABLE);
    enableAllInterrupts();
}

/*****************************************************************************/
/** 
 * \author      Amy Chung
 * \date        
 * \brief       main function
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void main(void)
{
    sys_init();
    while(true);
}

/*****************************************************************************/
/** 
 * \author      Amy Chung
 * \date        
 * \brief       interrupt service function for TIM2
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void TIM2_isr(void) __interrupt TF2_VECTOR
{
    static int cnt = 0;
    TIM2_clearFlag();

    /* per 500ms */
    cnt++;
    if (cnt == 10)
    {
        GPIO_toggleBitValue(PERIPH_GPIO_1, PERIPH_GPIO_PIN_2);
        cnt = 0;
    }
}
