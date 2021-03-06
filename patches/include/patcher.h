/***************************************************************************
 *                                                                         *
 *          ###########   ###########   ##########    ##########           *
 *         ############  ############  ############  ############          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ###########   ####  ######  ##   ##   ##  ##    ######          *
 *          ###########  ####  #       ##   ##   ##  ##    #    #          *
 *                   ##  ##    ######  ##   ##   ##  ##    #    #          *
 *                   ##  ##    #       ##   ##   ##  ##    #    #          *
 *         ############  ##### ######  ##   ##   ##  ##### ######          *
 *         ###########    ###########  ##   ##   ##   ##########           *
 *                                                                         *
 *            S E C U R E   M O B I L E   N E T W O R K I N G              *
 *                                                                         *
 * This file is part of NexMon.                                            *
 *                                                                         *
 * Copyright (c) 2016 NexMon Team                                          *
 *                                                                         *
 * NexMon is free software: you can redistribute it and/or modify          *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * NexMon is distributed in the hope that it will be useful,               *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with NexMon. If not, see <http://www.gnu.org/licenses/>.          *
 *                                                                         *
 **************************************************************************/

#define FW_ADDR(addr) (0x8C0000 + addr)
#define UC_ADDR(addr) (0x920000 + addr)

#define BLPatch(name, func) \
    __attribute__((naked)) void \
    bl_ ## name(void) { asm("bl " #func "\n"); }

#define BLDPatch(name, func, delay_ins) \
    __attribute__((naked)) void \
    bl_ ## name(void) { asm("bl.d " #func "\n" delay_ins "\n"); }

#define BPatch(name, func) \
    __attribute__((naked)) void \
    b_ ## name(void) { asm("b " #func "\n"); }

#define BLNEPatch(name, func) \
    __attribute__((naked)) void \
    bl_ ## name(void) { asm("blne " #func "\n"); }

#define BDPatch(name, func, delay_ins) \
    __attribute__((naked)) void \
    b_ ## name(void) { asm("b.d " #func "\n" delay_ins "\n"); }

#define JPatch(name, func) \
    __attribute__((naked)) void \
    j_ ## name(void) { asm("j " #func "\n"); }

#define GenericPatch4(name, val) \
    const unsigned int gp4_ ## name = (unsigned int) (val);

#define GenericPatch2(name, val) \
    unsigned short gp2_ ## name = (unsigned short) (val);

#define GenericPatch1(name, val) \
    unsigned char gp1_ ## name = (unsigned char) (val);

#define StringPatch(name, val) \
    __attribute__((naked)) \
    void str_ ## name(void) { asm(".ascii \"" val "\"\n.byte 0x00"); }

#define Dummy(name) \
    void dummy_ ## name(void) { ; }
