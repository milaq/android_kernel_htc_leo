/******************************************************************************
*******************************************************************************
**
<<<<<<< HEAD
**  Copyright (C) 2005-2008 Red Hat, Inc.  All rights reserved.
=======
**  Copyright (C) 2005-2010 Red Hat, Inc.  All rights reserved.
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
**
**  This copyrighted material is made available to anyone wishing to use,
**  modify, copy, or redistribute it subject to the terms and conditions
**  of the GNU General Public License v.2.
**
*******************************************************************************
******************************************************************************/

#ifndef __ASTD_DOT_H__
#define __ASTD_DOT_H__

<<<<<<< HEAD
void dlm_add_ast(struct dlm_lkb *lkb, int type, int bastmode);
=======
void dlm_add_ast(struct dlm_lkb *lkb, int type, int mode);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
void dlm_del_ast(struct dlm_lkb *lkb);

void dlm_astd_wake(void);
int dlm_astd_start(void);
void dlm_astd_stop(void);
void dlm_astd_suspend(void);
void dlm_astd_resume(void);

#endif

