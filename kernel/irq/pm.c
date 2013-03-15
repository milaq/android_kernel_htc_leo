/*
 * linux/kernel/irq/pm.c
 *
 * Copyright (C) 2009 Rafael J. Wysocki <rjw@sisk.pl>, Novell Inc.
 *
 * This file contains power management functions related to interrupts.
 */

#include <linux/irq.h>
#include <linux/module.h>
#include <linux/interrupt.h>

#include "internals.h"

/**
 * suspend_device_irqs - disable all currently enabled interrupt lines
 *
 * During system-wide suspend or hibernation device drivers need to be prevented
 * from receiving interrupts and this function is provided for this purpose.
 * It marks all interrupt lines in use, except for the timer ones, as disabled
 * and sets the IRQ_SUSPENDED flag for each of them.
 */
void suspend_device_irqs(void)
{
	struct irq_desc *desc;
	int irq;

	for_each_irq_desc(irq, desc) {
		unsigned long flags;

		spin_lock_irqsave(&desc->lock, flags);
<<<<<<< HEAD
		if (desc->wake_depth == 0)
			__disable_irq(desc, irq, true);
=======
		__disable_irq(desc, irq, true);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
		spin_unlock_irqrestore(&desc->lock, flags);
	}

	for_each_irq_desc(irq, desc)
		if (desc->status & IRQ_SUSPENDED)
			synchronize_irq(irq);
}
EXPORT_SYMBOL_GPL(suspend_device_irqs);

<<<<<<< HEAD
/**
 * resume_device_irqs - enable interrupt lines disabled by suspend_device_irqs()
 *
 * Enable all interrupt lines previously disabled by suspend_device_irqs() that
 * have the IRQ_SUSPENDED flag set.
 */
void resume_device_irqs(void)
=======
static void resume_irqs(bool want_early)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
{
	struct irq_desc *desc;
	int irq;

	for_each_irq_desc(irq, desc) {
		unsigned long flags;
<<<<<<< HEAD

		if (!(desc->status & IRQ_SUSPENDED))
=======
		bool is_early = desc->action &&
			desc->action->flags & IRQF_EARLY_RESUME;

		if (is_early != want_early)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
			continue;

		spin_lock_irqsave(&desc->lock, flags);
		__enable_irq(desc, irq, true);
		spin_unlock_irqrestore(&desc->lock, flags);
	}
}
<<<<<<< HEAD
=======

/**
 * irq_pm_syscore_ops - enable interrupt lines early
 *
 * Enable all interrupt lines with %IRQF_EARLY_RESUME set.
 */
void irq_pm_syscore_resume(void)
{
	resume_irqs(true);
}

/**
 * resume_device_irqs - enable interrupt lines disabled by suspend_device_irqs()
 *
 * Enable all non-%IRQF_EARLY_RESUME interrupt lines previously
 * disabled by suspend_device_irqs() that have the IRQS_SUSPENDED flag
 * set as well as those with %IRQF_FORCE_RESUME.
 */
void resume_device_irqs(void)
{
	resume_irqs(false);
}
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
EXPORT_SYMBOL_GPL(resume_device_irqs);

/**
 * check_wakeup_irqs - check if any wake-up interrupts are pending
 */
int check_wakeup_irqs(void)
{
	struct irq_desc *desc;
	int irq;

	for_each_irq_desc(irq, desc)
		if ((desc->status & IRQ_WAKEUP) && (desc->status & IRQ_PENDING))
			return -EBUSY;

	return 0;
}
