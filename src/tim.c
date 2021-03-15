/*****************************************************************************/
/** 
 * \file        tim.c
 * \author      Jiabin Hsu   | zsiothsu@zhishan-iot.tk
 * \author      Weillun Fong | wlf@zhishan-iot.tk
 * \brief       operations for timers
 * \note        not for timer-2
 * \version     v0.3
 * \ingroup     TIM
******************************************************************************/

#include "hml/tim.h"

#ifdef COMPILE_TIM

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2021/03/01
 * \brief       calculate initial value for THx/TLx register
 * \param[in]   time: expected timing cycle(unit: us)
 * \param[in]   mode: work mode of timer
 * \return      initial value of timer counter register(if return 0x0000, it 
 *              means that the time has over the limit)
 * \ingroup     TIM
 * \remarks     
******************************************************************************/
uint16_t TIM_calculateValue(uint16_t time, TIM_mode mode)
{
    /* machine cycle: MCU_FRE_CLK / MCU_PRESCALER */
    uint16_t maxTick = 0x0000;
    uint16_t t       = time*(MCU_FRE_CLK/1000000)/MCU_PRESCALER;

    switch (mode)
    {
        case TIM_mode_0: maxTick = 0x1FFF; break;
        case TIM_mode_1: maxTick = 0xFFFF; break;
        case TIM_mode_2: maxTick = 0x00FF; break;
        case TIM_mode_3: maxTick = 0x00FF; break;
        default: break;
    }

    if (t >= maxTick)
    {
        return 0x0000;
    }
    else
    {
        return (maxTick + 1 - t);
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable or disable target timer
 * \param[in]   tim: target timer(the value must be PERIPH_TIM_0 or PERIPH_TIM_1)
 * \param[in]   a  : expected state
 * \return      none
 * \ingroup     TIM
 * \remarks     not for timer2
******************************************************************************/
void TIM_cmd(PERIPH_TIM tim, Action a)
{
    switch (tim)
    {
        case PERIPH_TIM_0: TR0 = a; break;
        case PERIPH_TIM_1: TR1 = a; break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       configure target timer
 * \param[in]   tim: target timer(the value must be PERIPH_TIM_0 or PERIPH_TIM_1)
 * \param[in]   tc : configuration struct includes all parameters
 * \return      none
 * \ingroup     TIM
 * \remarks     not for timer2
******************************************************************************/
void TIM_config(PERIPH_TIM tim, TIM_configTypeDef *tc)
{
    TIM_setFunction(tim, tc->function);
    TIM_setMode(tim, tc->mode);
    TIM_setValue(tim, tc->value);
    TIM_INT_cmd(tim, tc->interruptState);
    TIM_INT_setPriority(tim, tc->interruptPriority);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       get value from THx/TLx register
 * \param[in]   tim: target timer module
 * \return      value stored in THx/TLx register. This function will return 0x0000
 *              when it gets a invalid parameter
 * \ingroup     TIM
 * \remarks     not for timer2
******************************************************************************/
uint16_t TIM_getValue(PERIPH_TIM tim)
{
    switch (tim)
    {
        case PERIPH_TIM_0: return ((TH0 << 0x08) | TL0);
        case PERIPH_TIM_1: return ((TH1 << 0x08) | TL1);
        default: return 0;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       check whether counter of target timer is overflow or not
 * \param[in]   tim: target timer module
 * \return      true(overflow) or false. This function will return false when 
 *              it gets a invalid parameter
 * \ingroup     TIM
 * \remarks     not for timer2
******************************************************************************/
bool TIM_isOverflow(PERIPH_TIM tim)
{
    switch (tim)
    {
        case PERIPH_TIM_0: return (bool)TF0;
        case PERIPH_TIM_1: return (bool)TF1;
        default: return false;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       configure function(timer or counter) of target timer
 * \param[in]   tim: target timer module
 * \param[in]   f  : expected function
 * \return      none
 * \ingroup     TIM
 * \remarks     not for timer2
******************************************************************************/
void TIM_setFunction(PERIPH_TIM tim, TIM_function f)
{
    switch (tim)
    {
        case PERIPH_TIM_0: CONFB(TMOD, BIT_NUM_T0_CT, f); break;
        case PERIPH_TIM_1: CONFB(TMOD, BIT_NUM_T1_CT, f); break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       configure work mode of target timer
 * \param[in]   tim : target timer module
 * \param[in]   mode: expected work mode
 * \return      none
 * \ingroup     TIM
 * \remarks     not for timer2
******************************************************************************/
void TIM_setMode(PERIPH_TIM tim, TIM_mode mode)
{
    switch (tim)
    {
        case PERIPH_TIM_0: TMOD = (TMOD & 0xFC) | mode; break;
        case PERIPH_TIM_1: TMOD = (TMOD & 0xCF) | (mode << 0x04); break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       set value of THx/TLx register
 * \param[in]   tim: target timer module
 * \param[in]   val: expected value(range: 0x0000~0xFFFF)
 * \return      none
 * \ingroup     TIM
 * \remarks     not for timer2
******************************************************************************/
void TIM_setValue(PERIPH_TIM tim, uint16_t val)
{
    switch (tim)
    {
        case PERIPH_TIM_0:
        {
            TH0 = (uint8_t)((val >> 0x8) & 0x00FF);
            TL0 = (uint8_t)(val & 0x00FF);
        } break;
        case PERIPH_TIM_1:
        {
            TH1 = (uint8_t)((val >> 0x8) & 0x00FF);
            TL1 = (uint8_t)(val & 0x00FF);
        } break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable or disable interrupt function of target timer
 * \param[in]   tim: target timer module
 * \param[in]   a  : expected state
 * \return      none
 * \ingroup     TIM
 * \remarks     not for timer2
******************************************************************************/
void TIM_INT_cmd(PERIPH_TIM tim, Action a)
{
    switch (tim)
    {
        case PERIPH_TIM_0:ET0 = a; break;
        case PERIPH_TIM_1:ET1 = a; break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       configure interrupt priority class of target timer
 * \param[in]   tim: target timer module
 * \param[in]   p  : interrupt priority class
 * \return      none
 * \ingroup     TIM
 * \remarks     not for timer2
******************************************************************************/
void TIM_INT_setPriority(PERIPH_TIM tim, UTIL_interruptPriority p)
{
    switch (tim)
    {
        case PERIPH_TIM_0:
        {
            PT0 = TESTB(p, 0);
            CONFB(IPH, BIT_NUM_PT0H, TESTB(p, 1));
        } break;
        case PERIPH_TIM_1:
        {
            PT1 = TESTB(p, 0);
            CONFB(IPH, BIT_NUM_PT1H, TESTB(p, 1));
        } break;
        default: break;
    }
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
