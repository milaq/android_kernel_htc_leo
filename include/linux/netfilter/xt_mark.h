#ifndef _XT_MARK_H
#define _XT_MARK_H

#include <linux/types.h>

<<<<<<< HEAD
struct xt_mark_tginfo2 {
	__u32 mark, mask;
};

=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
struct xt_mark_mtinfo1 {
	__u32 mark, mask;
	__u8 invert;
};

#endif /*_XT_MARK_H*/
