/*
 * ustat.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_USTAT_H_
#define LIBC_SYS_USTAT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_caddr_t.h"
#include "../__fc_define_dev_t.h"
#include "../__fc_define_ino_t.h"

#include "errno.h"

struct ustat
  {
    daddr_t f_tfree;
    ino_t f_tinode;
    char f_fname[6];
    char f_fpack[6];
  };

/*@
requires \valid(ubuf);
assigns errno, \result, *ubuf;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ustat (dev_t dev, struct ustat *ubuf);

#endif /* LIBC_SYS_USTAT_H_ */
