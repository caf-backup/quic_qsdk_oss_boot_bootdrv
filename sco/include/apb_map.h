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


#ifndef	_APB_MAP_H
#define	_APB_MAP_H

#ifdef CONFIG_MACH_AR944x
#include <944x.h>
#else
#error "Trying to build BootROM for unknown chip"
#endif

#define ath_reg_rd(_phys)	(*(volatile unsigned int *)KSEG1ADDR(_phys))

#define ath_reg_wr_nf(_phys, _val)	\
	((*(volatile unsigned int *)KSEG1ADDR(_phys)) = (_val))

#define ath_reg_wr(_phys, _val)	do {	\
	ath_reg_wr_nf(_phys, _val);	\
	ath_reg_rd(_phys);		\
} while (0)

#define ath_reg_rmw_set(_reg, _mask)	do {			\
	ath_reg_wr((_reg), (ath_reg_rd((_reg)) | (_mask)));	\
	ath_reg_rd((_reg));					\
} while (0)

#define ath_reg_rmw_clear(_reg, _mask)	do {			\
	ath_reg_wr((_reg), (ath_reg_rd((_reg)) & ~(_mask)));	\
	ath_reg_rd((_reg));					\
} while (0)

#endif	/* _APB_MAP_H */
