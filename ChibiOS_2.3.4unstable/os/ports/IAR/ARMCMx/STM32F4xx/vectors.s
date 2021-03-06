/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

        MODULE  ?vectors

        AAPCS INTERWORK, VFP_COMPATIBLE, RWPI_COMPATIBLE
        PRESERVE8

        SECTION IRQSTACK:DATA:NOROOT(3)
        SECTION .intvec:CODE:NOROOT(3)

        EXTERN  __iar_program_start
        PUBLIC  __vector_table

        DATA

__vector_table:
        DCD     SFE(IRQSTACK)
        DCD     __iar_program_start
        DCD     NMIVector
        DCD     HardFaultVector
        DCD     MemManageVector
        DCD     BusFaultVector
        DCD     UsageFaultVector
        DCD     Vector1C
        DCD     Vector20
        DCD     Vector24
        DCD     Vector28
        DCD     SVCallVector
        DCD     DebugMonitorVector
        DCD     Vector34
        DCD     PendSVVector
        DCD     SysTickVector
        DCD     Vector40
        DCD     Vector44
        DCD     Vector48
        DCD     Vector4C
        DCD     Vector50
        DCD     Vector54
        DCD     Vector58
        DCD     Vector5C
        DCD     Vector60
        DCD     Vector64
        DCD     Vector68
        DCD     Vector6C
        DCD     Vector70
        DCD     Vector74
        DCD     Vector78
        DCD     Vector7C
        DCD     Vector80
        DCD     Vector84
        DCD     Vector88
        DCD     Vector8C
        DCD     Vector90
        DCD     Vector94
        DCD     Vector98
        DCD     Vector9C
        DCD     VectorA0
        DCD     VectorA4
        DCD     VectorA8
        DCD     VectorAC
        DCD     VectorB0
        DCD     VectorB4
        DCD     VectorB8
        DCD     VectorBC
        DCD     VectorC0
        DCD     VectorC4
        DCD     VectorC8
        DCD     VectorCC
        DCD     VectorD0
        DCD     VectorD4
        DCD     VectorD8
        DCD     VectorDC
        DCD     VectorE0
        DCD     VectorE4
        DCD     VectorE8
        DCD     VectorEC
        DCD     VectorF0
        DCD     VectorF4
        DCD     VectorF8
        DCD     VectorFC
        DCD     Vector100
        DCD     Vector104
        DCD     Vector108
        DCD     Vector10C
        DCD     Vector110
        DCD     Vector114
        DCD     Vector118
        DCD     Vector11C
        DCD     Vector120
        DCD     Vector124
        DCD     Vector128
        DCD     Vector12C
        DCD     Vector130
        DCD     Vector134
        DCD     Vector138
        DCD     Vector13C
        DCD     Vector140
        DCD     Vector144
        DCD     Vector148
        DCD     Vector14C
        DCD     Vector150
        DCD     Vector154
        DCD     Vector158
        DCD     Vector15C
        DCD     Vector160
        DCD     Vector164
        DCD     Vector168
        DCD     Vector16C
        DCD     Vector170
        DCD     Vector174
        DCD     Vector178
        DCD     Vector17C
        DCD     Vector180
        DCD     Vector184

/*
 * Default interrupt handlers.
 */
        PUBWEAK NMIVector
        PUBWEAK HardFaultVector
        PUBWEAK MemManageVector
        PUBWEAK BusFaultVector
        PUBWEAK UsageFaultVector
        PUBWEAK Vector1C
        PUBWEAK Vector20
        PUBWEAK Vector24
        PUBWEAK Vector28
        PUBWEAK SVCallVector
        PUBWEAK DebugMonitorVector
        PUBWEAK Vector34
        PUBWEAK PendSVVector
        PUBWEAK SysTickVector
        PUBWEAK Vector40
        PUBWEAK Vector44
        PUBWEAK Vector48
        PUBWEAK Vector4C
        PUBWEAK Vector50
        PUBWEAK Vector54
        PUBWEAK Vector58
        PUBWEAK Vector5C
        PUBWEAK Vector60
        PUBWEAK Vector64
        PUBWEAK Vector68
        PUBWEAK Vector6C
        PUBWEAK Vector70
        PUBWEAK Vector74
        PUBWEAK Vector78
        PUBWEAK Vector7C
        PUBWEAK Vector80
        PUBWEAK Vector84
        PUBWEAK Vector88
        PUBWEAK Vector8C
        PUBWEAK Vector90
        PUBWEAK Vector94
        PUBWEAK Vector98
        PUBWEAK Vector9C
        PUBWEAK VectorA0
        PUBWEAK VectorA4
        PUBWEAK VectorA8
        PUBWEAK VectorAC
        PUBWEAK VectorB0
        PUBWEAK VectorB4
        PUBWEAK VectorB8
        PUBWEAK VectorBC
        PUBWEAK VectorC0
        PUBWEAK VectorC4
        PUBWEAK VectorC8
        PUBWEAK VectorCC
        PUBWEAK VectorD0
        PUBWEAK VectorD4
        PUBWEAK VectorD8
        PUBWEAK VectorDC
        PUBWEAK VectorE0
        PUBWEAK VectorE4
        PUBWEAK VectorE8
        PUBWEAK VectorEC
        PUBWEAK VectorF0
        PUBWEAK VectorF4
        PUBWEAK VectorF8
        PUBWEAK VectorFC
        PUBWEAK Vector100
        PUBWEAK Vector104
        PUBWEAK Vector108
        PUBWEAK Vector10C
        PUBWEAK Vector110
        PUBWEAK Vector114
        PUBWEAK Vector118
        PUBWEAK Vector11C
        PUBWEAK Vector120
        PUBWEAK Vector124
        PUBWEAK Vector128
        PUBWEAK Vector12C
        PUBWEAK Vector130
        PUBWEAK Vector134
        PUBWEAK Vector138
        PUBWEAK Vector13C
        PUBWEAK Vector140
        PUBWEAK Vector144
        PUBWEAK Vector148
        PUBWEAK Vector14C
        PUBWEAK Vector150
        PUBWEAK Vector154
        PUBWEAK Vector158
        PUBWEAK Vector15C
        PUBWEAK Vector160
        PUBWEAK Vector164
        PUBWEAK Vector168
        PUBWEAK Vector16C
        PUBWEAK Vector170
        PUBWEAK Vector174
        PUBWEAK Vector178
        PUBWEAK Vector17C
        PUBWEAK Vector180
        PUBWEAK Vector184
        PUBLIC  _unhandled_exception

        SECTION .text:CODE:REORDER(1)
        THUMB

NMIVector
HardFaultVector
MemManageVector
BusFaultVector
UsageFaultVector
Vector1C
Vector20
Vector24
Vector28
SVCallVector
DebugMonitorVector
Vector34
PendSVVector
SysTickVector
Vector40
Vector44
Vector48
Vector4C
Vector50
Vector54
Vector58
Vector5C
Vector60
Vector64
Vector68
Vector6C
Vector70
Vector74
Vector78
Vector7C
Vector80
Vector84
Vector88
Vector8C
Vector90
Vector94
Vector98
Vector9C
VectorA0
VectorA4
VectorA8
VectorAC
VectorB0
VectorB4
VectorB8
VectorBC
VectorC0
VectorC4
VectorC8
VectorCC
VectorD0
VectorD4
VectorD8
VectorDC
VectorE0
VectorE4
VectorE8
VectorEC
VectorF0
VectorF4
VectorF8
VectorFC
Vector100
Vector104
Vector108
Vector10C
Vector110
Vector114
Vector118
Vector11C
Vector120
Vector124
Vector128
Vector12C
Vector130
Vector134
Vector138
Vector13C
Vector140
Vector144
Vector148
Vector14C
Vector150
Vector154
Vector158
Vector15C
Vector160
Vector164
Vector168
Vector16C
Vector170
Vector174
Vector178
Vector17C
Vector180
Vector184
_unhandled_exception
        b       _unhandled_exception

        END
