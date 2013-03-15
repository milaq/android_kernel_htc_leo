/*
 * devops.c:  Device operations using the PROM.
 *
 * Copyright (C) 1995 David S. Miller (davem@caip.rutgers.edu)
 * Copyright (C) 1996,1997 Jakub Jelinek (jj@sunsite.mff.cuni.cz)
 */
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/sched.h>

#include <asm/openprom.h>
#include <asm/oplib.h>

/* Open the device described by the string 'dstr'.  Returns the handle
 * to that device used for subsequent operations on that device.
 * Returns 0 on failure.
 */
int
prom_devopen(const char *dstr)
{
<<<<<<< HEAD
	return p1275_cmd ("open", P1275_ARG(0,P1275_ARG_IN_STRING)|
				  P1275_INOUT(1,1),
				  dstr);
=======
	unsigned long args[5];

	args[0] = (unsigned long) "open";
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned long) dstr;
	args[4] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (int) args[4];
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}

/* Close the device described by device handle 'dhandle'. */
int
prom_devclose(int dhandle)
{
<<<<<<< HEAD
	p1275_cmd ("close", P1275_INOUT(1,0), dhandle);
=======
	unsigned long args[4];

	args[0] = (unsigned long) "close";
	args[1] = 1;
	args[2] = 0;
	args[3] = (unsigned int) dhandle;

	p1275_cmd_direct(args);

>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
	return 0;
}

/* Seek to specified location described by 'seekhi' and 'seeklo'
 * for device 'dhandle'.
 */
void
prom_seek(int dhandle, unsigned int seekhi, unsigned int seeklo)
{
<<<<<<< HEAD
	p1275_cmd ("seek", P1275_INOUT(3,1), dhandle, seekhi, seeklo);
=======
	unsigned long args[7];

	args[0] = (unsigned long) "seek";
	args[1] = 3;
	args[2] = 1;
	args[3] = (unsigned int) dhandle;
	args[4] = seekhi;
	args[5] = seeklo;
	args[6] = (unsigned long) -1;

	p1275_cmd_direct(args);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
}
