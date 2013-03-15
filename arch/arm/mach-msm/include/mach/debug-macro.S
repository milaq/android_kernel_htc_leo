/* arch/arm/mach-msm7200/include/mach/debug-macro.S
 *
 * Copyright (C) 2007 Google, Inc.
 * Author: Brian Swetland <swetland@google.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

<<<<<<< HEAD


#include <mach/hardware.h>
#include <mach/msm_iomap.h>

#ifdef CONFIG_MSM_DEBUG_UART
=======
#include <mach/hardware.h>
#include <mach/msm_iomap.h>

>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
	.macro	addruart,rx
	@ see if the MMU is enabled and select appropriate base address
	mrc	p15, 0, \rx, c1, c0
	tst	\rx, #1
<<<<<<< HEAD
	ldreq	\rx, =MSM_DEBUG_UART_PHYS
	ldrne	\rx, =MSM_DEBUG_UART_BASE
=======
	ldreq	\rx, =MSM_UART1_PHYS
	movne	\rx, #0
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
	.endm

	.macro	senduart,rd,rx
	teq	\rx, #0
	strne	\rd, [\rx, #0x0C]
	.endm

	.macro	waituart,rd,rx
	@ wait for TX_READY
<<<<<<< HEAD
1001:	ldr	\rd, [\rx, #0x08]
	tst	\rd, #0x04
	beq	1001b
1002:
	.endm
#else
	.macro	addruart,rx
	.endm

	.macro	senduart,rd,rx
	.endm

	.macro	waituart,rd,rx
	.endm
#endif
=======
	teq	\rx, #0
	bne	2f
1:	ldr	\rd, [\rx, #0x08]
	tst	\rd, #0x04
	beq	1b
2:
	.endm
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e

	.macro	busyuart,rd,rx
	.endm
