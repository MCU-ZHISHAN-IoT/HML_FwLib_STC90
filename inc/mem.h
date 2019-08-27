/*****************************************************************************/
/** 
 * \file        mem.h
 * \author      Weillun Fong | wlf@zhishan-iot.tk
 * \brief       operations for memory zone of MCU
 * \note        allow you to directly access the different memory areas of STC90
 *              series MCU
 * \version     v0.2
 * \ingroup     MEM
******************************************************************************/

#ifndef ___MEM_H___
#define ___MEM_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hw/stc90.h"
#include "macro.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/
/**
 *\brief: for access target zone directly
 */
#define __CBYTE ((unsigned char volatile __code  *) 0)
#define __DBYTE ((unsigned char volatile __data  *) 0)
#define __PBYTE ((unsigned char volatile __pdata *) 0)
#define __XBYTE ((unsigned char volatile __xdata *) 0)

#define __CWORD ((unsigned int volatile __code  *) 0)
#define __DWORD ((unsigned int volatile __data  *) 0)
#define __PWORD ((unsigned int volatile __pdata *) 0)
#define __XWORD ((unsigned int volatile __xdata *) 0)

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void MEM_cmd_ale(Action a);
void MEM_cmd_internalExtendedRam(Action a);

#endif
