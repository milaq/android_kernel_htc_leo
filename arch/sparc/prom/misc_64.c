/*
 * misc.c:  Miscellaneous prom functions that don't belong
 *          anywhere else.
 *
 * Copyright (C) 1995 David S. Miller (davem@caip.rutgers.edu)
 * Copyright (C) 1996,1997 Jakub Jelinek (jj@sunsite.mff.cuni.cz)
 */

#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/module.h>

#include <asm/openprom.h>
#include <asm/oplib.h>
#include <asm/system.h>
#include <asm/ldc.h>

int prom_service_exists(const char *service_name)
{
<<<<<<< HEAD
	int err = p1275_cmd("test", P1275_ARG(0, P1275_ARG_IN_STRING) |
			    P1275_INOUT(1, 1), service_name);

	if (err)
=======
	unsigned long args[5];

	args[0] = (unsigned long) "test";
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned long) service_name;
	args[4] = (unsigned long) -1;

	p1275_cmd_direct(args);

	if (args[4])
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
		return 0;
	return 1;
}

void prom_sun4v_guest_soft_state(void)
{
	const char *svc = "SUNW,soft-state-supported";
<<<<<<< HEAD

	if (!prom_service_exists(svc))
		return;
	p1275_cmd(svc, P1275_INOUT(0, 0));
=======
	unsigned long args[3];

	if (!prom_service_exists(svc))
		return;
	args[0] = (unsigned long) svc;
	args[1] = 0;
	args[2] = 0;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

/* Reset and reboot the machine with the command 'bcommand'. */
void prom_reboot(const char *bcommand)
{
<<<<<<< HEAD
=======
	unsigned long args[4];

>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
#ifdef CONFIG_SUN_LDOMS
	if (ldom_domaining_enabled)
		ldom_reboot(bcommand);
#endif
<<<<<<< HEAD
	p1275_cmd("boot", P1275_ARG(0, P1275_ARG_IN_STRING) |
		  P1275_INOUT(1, 0), bcommand);
=======
	args[0] = (unsigned long) "boot";
	args[1] = 1;
	args[2] = 0;
	args[3] = (unsigned long) bcommand;

	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

/* Forth evaluate the expression contained in 'fstring'. */
void prom_feval(const char *fstring)
{
<<<<<<< HEAD
	if (!fstring || fstring[0] == 0)
		return;
	p1275_cmd("interpret", P1275_ARG(0, P1275_ARG_IN_STRING) |
		  P1275_INOUT(1, 1), fstring);
=======
	unsigned long args[5];

	if (!fstring || fstring[0] == 0)
		return;
	args[0] = (unsigned long) "interpret";
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned long) fstring;
	args[4] = (unsigned long) -1;

	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}
EXPORT_SYMBOL(prom_feval);

#ifdef CONFIG_SMP
extern void smp_capture(void);
extern void smp_release(void);
#endif

/* Drop into the prom, with the chance to continue with the 'go'
 * prom command.
 */
void prom_cmdline(void)
{
<<<<<<< HEAD
=======
	unsigned long args[3];
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
	unsigned long flags;

	local_irq_save(flags);

#ifdef CONFIG_SMP
	smp_capture();
#endif

<<<<<<< HEAD
	p1275_cmd("enter", P1275_INOUT(0, 0));
=======
	args[0] = (unsigned long) "enter";
	args[1] = 0;
	args[2] = 0;

	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e

#ifdef CONFIG_SMP
	smp_release();
#endif

	local_irq_restore(flags);
}

/* Drop into the prom, but completely terminate the program.
 * No chance of continuing.
 */
void notrace prom_halt(void)
{
<<<<<<< HEAD
=======
	unsigned long args[3];

>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
#ifdef CONFIG_SUN_LDOMS
	if (ldom_domaining_enabled)
		ldom_power_off();
#endif
again:
<<<<<<< HEAD
	p1275_cmd("exit", P1275_INOUT(0, 0));
=======
	args[0] = (unsigned long) "exit";
	args[1] = 0;
	args[2] = 0;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
	goto again; /* PROM is out to get me -DaveM */
}

void prom_halt_power_off(void)
{
<<<<<<< HEAD
=======
	unsigned long args[3];

>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
#ifdef CONFIG_SUN_LDOMS
	if (ldom_domaining_enabled)
		ldom_power_off();
#endif
<<<<<<< HEAD
	p1275_cmd("SUNW,power-off", P1275_INOUT(0, 0));
=======
	args[0] = (unsigned long) "SUNW,power-off";
	args[1] = 0;
	args[2] = 0;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e

	/* if nothing else helps, we just halt */
	prom_halt();
}

/* Set prom sync handler to call function 'funcp'. */
void prom_setcallback(callback_func_t funcp)
{
<<<<<<< HEAD
	if (!funcp)
		return;
	p1275_cmd("set-callback", P1275_ARG(0, P1275_ARG_IN_FUNCTION) |
		  P1275_INOUT(1, 1), funcp);
=======
	unsigned long args[5];
	if (!funcp)
		return;
	args[0] = (unsigned long) "set-callback";
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned long) funcp;
	args[4] = (unsigned long) -1;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

/* Get the idprom and stuff it into buffer 'idbuf'.  Returns the
 * format type.  'num_bytes' is the number of bytes that your idbuf
 * has space for.  Returns 0xff on error.
 */
unsigned char prom_get_idprom(char *idbuf, int num_bytes)
{
	int len;

	len = prom_getproplen(prom_root_node, "idprom");
	if ((len >num_bytes) || (len == -1))
		return 0xff;
	if (!prom_getproperty(prom_root_node, "idprom", idbuf, num_bytes))
		return idbuf[0];

	return 0xff;
}

int prom_get_mmu_ihandle(void)
{
	int node, ret;

	if (prom_mmu_ihandle_cache != 0)
		return prom_mmu_ihandle_cache;

	node = prom_finddevice(prom_chosen_path);
	ret = prom_getint(node, prom_mmu_name);
	if (ret == -1 || ret == 0)
		prom_mmu_ihandle_cache = -1;
	else
		prom_mmu_ihandle_cache = ret;

	return ret;
}

static int prom_get_memory_ihandle(void)
{
	static int memory_ihandle_cache;
	int node, ret;

	if (memory_ihandle_cache != 0)
		return memory_ihandle_cache;

	node = prom_finddevice("/chosen");
	ret = prom_getint(node, "memory");
	if (ret == -1 || ret == 0)
		memory_ihandle_cache = -1;
	else
		memory_ihandle_cache = ret;

	return ret;
}

/* Load explicit I/D TLB entries. */
<<<<<<< HEAD
=======
static long tlb_load(const char *type, unsigned long index,
		     unsigned long tte_data, unsigned long vaddr)
{
	unsigned long args[9];

	args[0] = (unsigned long) prom_callmethod_name;
	args[1] = 5;
	args[2] = 1;
	args[3] = (unsigned long) type;
	args[4] = (unsigned int) prom_get_mmu_ihandle();
	args[5] = vaddr;
	args[6] = tte_data;
	args[7] = index;
	args[8] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (long) args[8];
}

>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
long prom_itlb_load(unsigned long index,
		    unsigned long tte_data,
		    unsigned long vaddr)
{
<<<<<<< HEAD
	return p1275_cmd(prom_callmethod_name,
			 (P1275_ARG(0, P1275_ARG_IN_STRING) |
			  P1275_ARG(2, P1275_ARG_IN_64B) |
			  P1275_ARG(3, P1275_ARG_IN_64B) |
			  P1275_INOUT(5, 1)),
			 "SUNW,itlb-load",
			 prom_get_mmu_ihandle(),
			 /* And then our actual args are pushed backwards. */
			 vaddr,
			 tte_data,
			 index);
=======
	return tlb_load("SUNW,itlb-load", index, tte_data, vaddr);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

long prom_dtlb_load(unsigned long index,
		    unsigned long tte_data,
		    unsigned long vaddr)
{
<<<<<<< HEAD
	return p1275_cmd(prom_callmethod_name,
			 (P1275_ARG(0, P1275_ARG_IN_STRING) |
			  P1275_ARG(2, P1275_ARG_IN_64B) |
			  P1275_ARG(3, P1275_ARG_IN_64B) |
			  P1275_INOUT(5, 1)),
			 "SUNW,dtlb-load",
			 prom_get_mmu_ihandle(),
			 /* And then our actual args are pushed backwards. */
			 vaddr,
			 tte_data,
			 index);
=======
	return tlb_load("SUNW,dtlb-load", index, tte_data, vaddr);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

int prom_map(int mode, unsigned long size,
	     unsigned long vaddr, unsigned long paddr)
{
<<<<<<< HEAD
	int ret = p1275_cmd(prom_callmethod_name,
			    (P1275_ARG(0, P1275_ARG_IN_STRING) |
			     P1275_ARG(3, P1275_ARG_IN_64B) |
			     P1275_ARG(4, P1275_ARG_IN_64B) |
			     P1275_ARG(6, P1275_ARG_IN_64B) |
			     P1275_INOUT(7, 1)),
			    prom_map_name,
			    prom_get_mmu_ihandle(),
			    mode,
			    size,
			    vaddr,
			    0,
			    paddr);

=======
	unsigned long args[11];
	int ret;

	args[0] = (unsigned long) prom_callmethod_name;
	args[1] = 7;
	args[2] = 1;
	args[3] = (unsigned long) prom_map_name;
	args[4] = (unsigned int) prom_get_mmu_ihandle();
	args[5] = (unsigned int) mode;
	args[6] = size;
	args[7] = vaddr;
	args[8] = 0;
	args[9] = paddr;
	args[10] = (unsigned long) -1;

	p1275_cmd_direct(args);

	ret = (int) args[10];
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
	if (ret == 0)
		ret = -1;
	return ret;
}

void prom_unmap(unsigned long size, unsigned long vaddr)
{
<<<<<<< HEAD
	p1275_cmd(prom_callmethod_name,
		  (P1275_ARG(0, P1275_ARG_IN_STRING) |
		   P1275_ARG(2, P1275_ARG_IN_64B) |
		   P1275_ARG(3, P1275_ARG_IN_64B) |
		   P1275_INOUT(4, 0)),
		  prom_unmap_name,
		  prom_get_mmu_ihandle(),
		  size,
		  vaddr);
=======
	unsigned long args[7];

	args[0] = (unsigned long) prom_callmethod_name;
	args[1] = 4;
	args[2] = 0;
	args[3] = (unsigned long) prom_unmap_name;
	args[4] = (unsigned int) prom_get_mmu_ihandle();
	args[5] = size;
	args[6] = vaddr;

	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

/* Set aside physical memory which is not touched or modified
 * across soft resets.
 */
<<<<<<< HEAD
unsigned long prom_retain(const char *name,
			  unsigned long pa_low, unsigned long pa_high,
			  long size, long align)
{
	/* XXX I don't think we return multiple values correctly.
	 * XXX OBP supposedly returns pa_low/pa_high here, how does
	 * XXX it work?
	 */

	/* If align is zero, the pa_low/pa_high args are passed,
	 * else they are not.
	 */
	if (align == 0)
		return p1275_cmd("SUNW,retain",
				 (P1275_ARG(0, P1275_ARG_IN_BUF) | P1275_INOUT(5, 2)),
				 name, pa_low, pa_high, size, align);
	else
		return p1275_cmd("SUNW,retain",
				 (P1275_ARG(0, P1275_ARG_IN_BUF) | P1275_INOUT(3, 2)),
				 name, size, align);
=======
int prom_retain(const char *name, unsigned long size,
		unsigned long align, unsigned long *paddr)
{
	unsigned long args[11];

	args[0] = (unsigned long) prom_callmethod_name;
	args[1] = 5;
	args[2] = 3;
	args[3] = (unsigned long) "SUNW,retain";
	args[4] = (unsigned int) prom_get_memory_ihandle();
	args[5] = align;
	args[6] = size;
	args[7] = (unsigned long) name;
	args[8] = (unsigned long) -1;
	args[9] = (unsigned long) -1;
	args[10] = (unsigned long) -1;

	p1275_cmd_direct(args);

	if (args[8])
		return (int) args[8];

	/* Next we get "phys_high" then "phys_low".  On 64-bit
	 * the phys_high cell is don't care since the phys_low
	 * cell has the full value.
	 */
	*paddr = args[10];

	return 0;
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

/* Get "Unumber" string for the SIMM at the given
 * memory address.  Usually this will be of the form
 * "Uxxxx" where xxxx is a decimal number which is
 * etched into the motherboard next to the SIMM slot
 * in question.
 */
int prom_getunumber(int syndrome_code,
		    unsigned long phys_addr,
		    char *buf, int buflen)
{
<<<<<<< HEAD
	return p1275_cmd(prom_callmethod_name,
			 (P1275_ARG(0, P1275_ARG_IN_STRING)	|
			  P1275_ARG(3, P1275_ARG_OUT_BUF)	|
			  P1275_ARG(6, P1275_ARG_IN_64B)	|
			  P1275_INOUT(8, 2)),
			 "SUNW,get-unumber", prom_get_memory_ihandle(),
			 buflen, buf, P1275_SIZE(buflen),
			 0, phys_addr, syndrome_code);
=======
	unsigned long args[12];

	args[0] = (unsigned long) prom_callmethod_name;
	args[1] = 7;
	args[2] = 2;
	args[3] = (unsigned long) "SUNW,get-unumber";
	args[4] = (unsigned int) prom_get_memory_ihandle();
	args[5] = buflen;
	args[6] = (unsigned long) buf;
	args[7] = 0;
	args[8] = phys_addr;
	args[9] = (unsigned int) syndrome_code;
	args[10] = (unsigned long) -1;
	args[11] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (int) args[10];
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

/* Power management extensions. */
void prom_sleepself(void)
{
<<<<<<< HEAD
	p1275_cmd("SUNW,sleep-self", P1275_INOUT(0, 0));
=======
	unsigned long args[3];

	args[0] = (unsigned long) "SUNW,sleep-self";
	args[1] = 0;
	args[2] = 0;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

int prom_sleepsystem(void)
{
<<<<<<< HEAD
	return p1275_cmd("SUNW,sleep-system", P1275_INOUT(0, 1));
=======
	unsigned long args[4];

	args[0] = (unsigned long) "SUNW,sleep-system";
	args[1] = 0;
	args[2] = 1;
	args[3] = (unsigned long) -1;
	p1275_cmd_direct(args);

	return (int) args[3];
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

int prom_wakeupsystem(void)
{
<<<<<<< HEAD
	return p1275_cmd("SUNW,wakeup-system", P1275_INOUT(0, 1));
=======
	unsigned long args[4];

	args[0] = (unsigned long) "SUNW,wakeup-system";
	args[1] = 0;
	args[2] = 1;
	args[3] = (unsigned long) -1;
	p1275_cmd_direct(args);

	return (int) args[3];
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

#ifdef CONFIG_SMP
void prom_startcpu(int cpunode, unsigned long pc, unsigned long arg)
{
<<<<<<< HEAD
	p1275_cmd("SUNW,start-cpu", P1275_INOUT(3, 0), cpunode, pc, arg);
=======
	unsigned long args[6];

	args[0] = (unsigned long) "SUNW,start-cpu";
	args[1] = 3;
	args[2] = 0;
	args[3] = (unsigned int) cpunode;
	args[4] = pc;
	args[5] = arg;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

void prom_startcpu_cpuid(int cpuid, unsigned long pc, unsigned long arg)
{
<<<<<<< HEAD
	p1275_cmd("SUNW,start-cpu-by-cpuid", P1275_INOUT(3, 0),
		  cpuid, pc, arg);
=======
	unsigned long args[6];

	args[0] = (unsigned long) "SUNW,start-cpu-by-cpuid";
	args[1] = 3;
	args[2] = 0;
	args[3] = (unsigned int) cpuid;
	args[4] = pc;
	args[5] = arg;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

void prom_stopcpu_cpuid(int cpuid)
{
<<<<<<< HEAD
	p1275_cmd("SUNW,stop-cpu-by-cpuid", P1275_INOUT(1, 0),
		  cpuid);
=======
	unsigned long args[4];

	args[0] = (unsigned long) "SUNW,stop-cpu-by-cpuid";
	args[1] = 1;
	args[2] = 0;
	args[3] = (unsigned int) cpuid;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

void prom_stopself(void)
{
<<<<<<< HEAD
	p1275_cmd("SUNW,stop-self", P1275_INOUT(0, 0));
=======
	unsigned long args[3];

	args[0] = (unsigned long) "SUNW,stop-self";
	args[1] = 0;
	args[2] = 0;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

void prom_idleself(void)
{
<<<<<<< HEAD
	p1275_cmd("SUNW,idle-self", P1275_INOUT(0, 0));
=======
	unsigned long args[3];

	args[0] = (unsigned long) "SUNW,idle-self";
	args[1] = 0;
	args[2] = 0;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

void prom_resumecpu(int cpunode)
{
<<<<<<< HEAD
	p1275_cmd("SUNW,resume-cpu", P1275_INOUT(1, 0), cpunode);
=======
	unsigned long args[4];

	args[0] = (unsigned long) "SUNW,resume-cpu";
	args[1] = 1;
	args[2] = 0;
	args[3] = (unsigned int) cpunode;
	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}
#endif
