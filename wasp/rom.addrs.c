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

#include <asm/types.h>
#include "rom.addrs.h"

bootrom_fn_t bootrom_fn[] = {
// Wasp 1.0
	{
		(void *)0xbfc01114, (void *)0xbfc04000, (void *)0xbfc045ac,
		(void *)0xbfc00720, (void *)0xbfc005d0, (void *)0xbd0008a8
	},
// Wasp 1.1
	{
		(void *)0xbfc0114c, (void *)0xbfc0421c, (void *)0xbfc047a8,
		(void *)0xbfc00730, (void *)0xbfc005d4, (void *)0xbd000898
	},
// Wasp 1.2, same as above
	{
		(void *)0xbfc0114c, (void *)0xbfc0421c, (void *)0xbfc047a8,
		(void *)0xbfc00730, (void *)0xbfc005d4, (void *)0xbd000898
	},
// Wasp 1.3
	{
		(void *)0xbfc00c7c, (void *)0xbfc00f2c, (void *)0xbfc00ac8,
		(void *)0xbfc00730, (void *)0xbfc005d4,
	},
};
