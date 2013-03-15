#ifndef RESUME_TRACE_H
#define RESUME_TRACE_H

<<<<<<< HEAD
enum {
	TRACE_DPM_PREPARE = 1U << 0,
	TRACE_DPM_SUSPEND = 1U << 1,
	TRACE_DPM_SUSPEND_NOIRQ = 1U << 2,
	TRACE_SYSDEV_SUSPEND = 1U << 3,
	TRACE_SYSDEV_RESUME = 1U << 4,
	TRACE_DPM_RESUME_NOIRQ = 1U << 5,
	TRACE_DPM_RESUME = 1U << 6,
	TRACE_DPM_COMPLETE = 1U << 7,
};

=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
#ifdef CONFIG_PM_TRACE
#include <asm/resume-trace.h>

extern int pm_trace_enabled;
<<<<<<< HEAD
extern int pm_trace_mask;
=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e

struct device;
extern void set_trace_device(struct device *);
extern void generate_resume_trace(const void *tracedata, unsigned int user);

<<<<<<< HEAD
#ifdef CONFIG_PM_TRACE_RTC
=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
#define TRACE_DEVICE(dev) do { \
	if (pm_trace_enabled) \
		set_trace_device(dev); \
	} while(0)
<<<<<<< HEAD
#else
#define TRACE_DEVICE(dev) do { } while (0)
#endif

#define TRACE_MASK(type, format, arg...) do {\
	if (pm_trace_mask & type) \
		pr_info("[PM.%x] " format, type, ## arg); \
	} while(0)
=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e

#else

#define TRACE_DEVICE(dev) do { } while (0)
#define TRACE_RESUME(dev) do { } while (0)
<<<<<<< HEAD
#define TRACE_MASK(type, format, arg...) do { } while (0)
=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e

#endif

#endif
