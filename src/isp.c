/*****************************************************************************/
/** 
 * \file        isp.c
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for ISP module
 * \note        
 * \version     v0.3
 * \ingroup     ISP
******************************************************************************/

#include "hml/isp.h"

#ifdef HAVE_ISP

#ifdef COMPILE_ISP

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       enable or disable ISP module
 * \param[in]   a : expected action
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_cmd(Action a)
{
    CONFB(ISP_CONTR, BIT_NUM_ISPEN, a);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2021/01/28
 * \brief       set the wait time of cpu after isp module is triggered
 * \param[in]   none
 * \return      none
 * \ingroup     ISP
 * \remarks     call this function before using ISP module
******************************************************************************/
void ISP_config(void)
{
    ISP_CONTR = (ISP_CONTR & 0xF8) | ISP_WAITTIME;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2021/02/19
 * \brief       erase all data of specified ISP area
 * \param[in]   addr: address of target area
 * \return      complete to erase(true) or failed to execute operation(false)
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
bool ISP_eraseSector(uint16_t addr)
{
    /* check address */
    if ((addr < ISP_ADDR_START) || (addr > ISP_ADDR_END))
    {
        return false;
    }

    ISP_setAddress(addr);
    ISP_setCommand(ISP_command_erase);
    ISP_trig();

    return true;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2021/02/19
 * \brief       make ISP module be in idle mode
 * \param[in]   
 * \return      none
 * \ingroup     ISP
 * \remarks     After each Read/Write operation, call this function to prevent
 *              misoperation to wrong target
******************************************************************************/
void ISP_idle(void)
{
    /* 0xFFFF point to non-eeprom area */
    ISP_setAddress(0xFFFF);
    ISP_setCommand(ISP_command_idle);
    ISP_DATA = 0xFF;
    ISP_TRIG = 0x00;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2021/02/19
 * \brief       read one byte of data form specified ISP area
 * \param[in]   addr: address of target area
 * \return      access result
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
byte ISP_readByte(uint16_t addr)
{
    uint8_t dat = 0x00;

    ISP_setAddress(addr);
    ISP_setCommand(ISP_command_read);
    ISP_trig();
    dat = ISP_DATA;

    return dat;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       configure value of ISP address register for access
 * \param[in]   addr: address of target area
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_setAddress(uint16_t addr)
{
    ISP_ADDRL = addr;
    ISP_ADDRH = addr >> 0x8;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       send command to ISP module by writing ISP_CMD register
 * \param[in]   cmd: ISP command type
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_setCommand(ISP_command cmd)
{
    ISP_CMD = cmd;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2021/02/19
 * \brief       trigger instruction
 * \param[in]   
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_trig(void)
{
    ISP_TRIG = 0x46;
    ISP_TRIG = 0xB9;
    __asm
        nop ; MCU will hold here until ISP operation
    __endasm;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2021/02/19
 * \brief       write data to specified ISP area
 * \param[in]   addr: address of target ISP area
 * \param[in]   dat : one byte of data
 * \return      write successfully(true) or not(false)
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
bool ISP_writeByte(uint16_t addr, byte dat)
{
    if ((addr < ISP_ADDR_START) || (addr > ISP_ADDR_END))
    {
        return false;
    }
    else
    {
        ISP_setAddress(addr);
        ISP_setCommand(ISP_command_write);
        ISP_DATA = dat;
        ISP_trig();

        return true;
    }
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif

#endif
