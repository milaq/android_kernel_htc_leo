#ifndef _ASM_X86_CMPXCHG_64_H
#define _ASM_X86_CMPXCHG_64_H

#include <asm/alternative.h> /* Provides LOCK_PREFIX */

#define xchg(ptr, v) ((__typeof__(*(ptr)))__xchg((unsigned long)(v), \
						 (ptr), sizeof(*(ptr))))

#define __xg(x) ((volatile long *)(x))

<<<<<<< HEAD
static inline void set_64bit(volatile unsigned long *ptr, unsigned long val)
=======
static inline void set_64bit(volatile u64 *ptr, u64 val)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
{
	*ptr = val;
}

<<<<<<< HEAD
#define _set_64bit set_64bit

=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
/*
 * Note: no "lock" prefix even on SMP: xchg always implies lock anyway
 * Note 2: xchg has side effect, so that attribute volatile is necessary,
 *	  but generally the primitive is invalid, *ptr is output argument. --ANK
 */
static inline unsigned long __xchg(unsigned long x, volatile void *ptr,
				   int size)
{
	switch (size) {
	case 1:
		asm volatile("xchgb %b0,%1"
<<<<<<< HEAD
			     : "=q" (x)
			     : "m" (*__xg(ptr)), "0" (x)
=======
			     : "=q" (x), "+m" (*__xg(ptr))
			     : "0" (x)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
			     : "memory");
		break;
	case 2:
		asm volatile("xchgw %w0,%1"
<<<<<<< HEAD
			     : "=r" (x)
			     : "m" (*__xg(ptr)), "0" (x)
=======
			     : "=r" (x), "+m" (*__xg(ptr))
			     : "0" (x)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
			     : "memory");
		break;
	case 4:
		asm volatile("xchgl %k0,%1"
<<<<<<< HEAD
			     : "=r" (x)
			     : "m" (*__xg(ptr)), "0" (x)
=======
			     : "=r" (x), "+m" (*__xg(ptr))
			     : "0" (x)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
			     : "memory");
		break;
	case 8:
		asm volatile("xchgq %0,%1"
<<<<<<< HEAD
			     : "=r" (x)
			     : "m" (*__xg(ptr)), "0" (x)
=======
			     : "=r" (x), "+m" (*__xg(ptr))
			     : "0" (x)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
			     : "memory");
		break;
	}
	return x;
}

/*
 * Atomic compare and exchange.  Compare OLD with MEM, if identical,
 * store NEW in MEM.  Return the initial value in MEM.  Success is
 * indicated by comparing RETURN with OLD.
 */

#define __HAVE_ARCH_CMPXCHG 1

static inline unsigned long __cmpxchg(volatile void *ptr, unsigned long old,
				      unsigned long new, int size)
{
	unsigned long prev;
	switch (size) {
	case 1:
<<<<<<< HEAD
		asm volatile(LOCK_PREFIX "cmpxchgb %b1,%2"
			     : "=a"(prev)
			     : "q"(new), "m"(*__xg(ptr)), "0"(old)
			     : "memory");
		return prev;
	case 2:
		asm volatile(LOCK_PREFIX "cmpxchgw %w1,%2"
			     : "=a"(prev)
			     : "r"(new), "m"(*__xg(ptr)), "0"(old)
			     : "memory");
		return prev;
	case 4:
		asm volatile(LOCK_PREFIX "cmpxchgl %k1,%2"
			     : "=a"(prev)
			     : "r"(new), "m"(*__xg(ptr)), "0"(old)
			     : "memory");
		return prev;
	case 8:
		asm volatile(LOCK_PREFIX "cmpxchgq %1,%2"
			     : "=a"(prev)
			     : "r"(new), "m"(*__xg(ptr)), "0"(old)
=======
		asm volatile(LOCK_PREFIX "cmpxchgb %b2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "q"(new), "0"(old)
			     : "memory");
		return prev;
	case 2:
		asm volatile(LOCK_PREFIX "cmpxchgw %w2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "r"(new), "0"(old)
			     : "memory");
		return prev;
	case 4:
		asm volatile(LOCK_PREFIX "cmpxchgl %k2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "r"(new), "0"(old)
			     : "memory");
		return prev;
	case 8:
		asm volatile(LOCK_PREFIX "cmpxchgq %2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "r"(new), "0"(old)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
			     : "memory");
		return prev;
	}
	return old;
}

/*
 * Always use locked operations when touching memory shared with a
 * hypervisor, since the system may be SMP even if the guest kernel
 * isn't.
 */
static inline unsigned long __sync_cmpxchg(volatile void *ptr,
					   unsigned long old,
					   unsigned long new, int size)
{
	unsigned long prev;
	switch (size) {
	case 1:
<<<<<<< HEAD
		asm volatile("lock; cmpxchgb %b1,%2"
			     : "=a"(prev)
			     : "q"(new), "m"(*__xg(ptr)), "0"(old)
			     : "memory");
		return prev;
	case 2:
		asm volatile("lock; cmpxchgw %w1,%2"
			     : "=a"(prev)
			     : "r"(new), "m"(*__xg(ptr)), "0"(old)
			     : "memory");
		return prev;
	case 4:
		asm volatile("lock; cmpxchgl %1,%2"
			     : "=a"(prev)
			     : "r"(new), "m"(*__xg(ptr)), "0"(old)
=======
		asm volatile("lock; cmpxchgb %b2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "q"(new), "0"(old)
			     : "memory");
		return prev;
	case 2:
		asm volatile("lock; cmpxchgw %w2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "r"(new), "0"(old)
			     : "memory");
		return prev;
	case 4:
		asm volatile("lock; cmpxchgl %k2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "r"(new), "0"(old)
			     : "memory");
		return prev;
	case 8:
		asm volatile("lock; cmpxchgq %2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "r"(new), "0"(old)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
			     : "memory");
		return prev;
	}
	return old;
}

static inline unsigned long __cmpxchg_local(volatile void *ptr,
					    unsigned long old,
					    unsigned long new, int size)
{
	unsigned long prev;
	switch (size) {
	case 1:
<<<<<<< HEAD
		asm volatile("cmpxchgb %b1,%2"
			     : "=a"(prev)
			     : "q"(new), "m"(*__xg(ptr)), "0"(old)
			     : "memory");
		return prev;
	case 2:
		asm volatile("cmpxchgw %w1,%2"
			     : "=a"(prev)
			     : "r"(new), "m"(*__xg(ptr)), "0"(old)
			     : "memory");
		return prev;
	case 4:
		asm volatile("cmpxchgl %k1,%2"
			     : "=a"(prev)
			     : "r"(new), "m"(*__xg(ptr)), "0"(old)
			     : "memory");
		return prev;
	case 8:
		asm volatile("cmpxchgq %1,%2"
			     : "=a"(prev)
			     : "r"(new), "m"(*__xg(ptr)), "0"(old)
=======
		asm volatile("cmpxchgb %b2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "q"(new), "0"(old)
			     : "memory");
		return prev;
	case 2:
		asm volatile("cmpxchgw %w2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "r"(new), "0"(old)
			     : "memory");
		return prev;
	case 4:
		asm volatile("cmpxchgl %k2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "r"(new), "0"(old)
			     : "memory");
		return prev;
	case 8:
		asm volatile("cmpxchgq %2,%1"
			     : "=a"(prev), "+m"(*__xg(ptr))
			     : "r"(new), "0"(old)
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
			     : "memory");
		return prev;
	}
	return old;
}

#define cmpxchg(ptr, o, n)						\
	((__typeof__(*(ptr)))__cmpxchg((ptr), (unsigned long)(o),	\
				       (unsigned long)(n), sizeof(*(ptr))))
#define cmpxchg64(ptr, o, n)						\
({									\
	BUILD_BUG_ON(sizeof(*(ptr)) != 8);				\
	cmpxchg((ptr), (o), (n));					\
})
#define cmpxchg_local(ptr, o, n)					\
	((__typeof__(*(ptr)))__cmpxchg_local((ptr), (unsigned long)(o),	\
					     (unsigned long)(n),	\
					     sizeof(*(ptr))))
#define sync_cmpxchg(ptr, o, n)						\
	((__typeof__(*(ptr)))__sync_cmpxchg((ptr), (unsigned long)(o),	\
					    (unsigned long)(n),		\
					    sizeof(*(ptr))))
#define cmpxchg64_local(ptr, o, n)					\
({									\
	BUILD_BUG_ON(sizeof(*(ptr)) != 8);				\
	cmpxchg_local((ptr), (o), (n));					\
})

#endif /* _ASM_X86_CMPXCHG_64_H */
