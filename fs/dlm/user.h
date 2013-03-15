/*
<<<<<<< HEAD
 * Copyright (C) 2006-2008 Red Hat, Inc.  All rights reserved.
=======
 * Copyright (C) 2006-2010 Red Hat, Inc.  All rights reserved.
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU General Public License v.2.
 */

#ifndef __USER_DOT_H__
#define __USER_DOT_H__

<<<<<<< HEAD
void dlm_user_add_ast(struct dlm_lkb *lkb, int type, int bastmode);
=======
void dlm_user_add_ast(struct dlm_lkb *lkb, int type, int mode);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
int dlm_user_init(void);
void dlm_user_exit(void);
int dlm_device_deregister(struct dlm_ls *ls);
int dlm_user_daemon_available(void);

#endif
