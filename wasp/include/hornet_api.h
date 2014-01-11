/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef _HORNET_API_H
#define _HORNET_API_H

#include <mem_api.h>
#include <uart_api.h>

#define A_INDIR(sym)   _A_HORNET_INDIRECTION_TABLE->sym

#define UART_MODULE_INSTALL()                 uart_module_install(&_A_HORNET_INDIRECTION_TABLE->uart)
#define A_UART_INIT()                         A_INDIR(uart._uart_init())
#define A_UART_GETC()                         A_INDIR(uart._uart_getc())
#define A_UART_PUTC(c)                        A_INDIR(uart._uart_putc(c))
#define A_UART_PUTS(s)                        A_INDIR(uart._uart_puts(s))

#define MEM_MODULE_INSTALL()                  mem_module_install(&_A_HORNET_INDIRECTION_TABLE->mem)
#define A_MEM_INIT(type)                      A_INDIR(mem._mem_init(type))

/*
 * This defines the layout of the indirection table, which
 * is used to access exported APIs of various modules.  The
 * layout is shared across ROM and RAM code.  RAM code may
 * call into ROM and ROM code may call into RAM.  Because
 * of the latter, existing offsets must not change for the
 * lifetime of a revision of ROM; but new members may be
 * added at the end.
 */
typedef struct _A_hornet_indirection_table {
    struct uart_api                     uart;
    struct memory_api                   mem;
} _A_hornet_indirection_table_t;

extern _A_hornet_indirection_table_t _indir_tbl;
#define _A_HORNET_INDIRECTION_TABLE_SIZE sizeof(_A_hornet_indirection_table_t)
//#if defined(__mips__)
#if 0
#define _A_HORNET_INDIRECTION_TABLE ((_A_hornet_indirection_table_t *)0x700)
#else
#define _A_HORNET_INDIRECTION_TABLE (&_indir_tbl)
#endif

#endif
