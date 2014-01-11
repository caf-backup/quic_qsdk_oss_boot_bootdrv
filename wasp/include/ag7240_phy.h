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

#ifndef _AG7240_PHY_H
#define _AG7240_PHY_H

#define ag7240_phy_setup(unit) do { \
    athrs26_phy_setup(unit); \
} while (0);

#define ag7240_phy_link(unit,link,fdx,speed) do { \
    link = athrs26_phy_is_up(unit); \
} while (0);

#define ag7240_phy_duplex(unit,duplex) do { \
    duplex =  athrs26_phy_is_fdx (unit); \
} while (0);

#define ag7240_phy_speed(unit,speed) do { \
        speed = athrs26_phy_speed (unit); \
} while (0);

#endif /*_AG7240_PHY_H*/
