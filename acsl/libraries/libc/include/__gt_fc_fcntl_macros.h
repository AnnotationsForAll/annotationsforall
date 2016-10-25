/*
 * __gt_fc_fcntl_macros.h
 *
 *  Created on: Jul 19, 2016
 *      Author: jrobbins
 */

#ifndef LIBC___GT_FC_FCNTL_MACROS_H_
#define LIBC___GT_FC_FCNTL_MACROS_H_

#include "errno.h"

#define F_ULOCK 0
#define F_LOCK  1
#define F_TLOCK 2
#define F_TEST  3

#define R_OK 4
#define W_OK 2
#define X_OK 1
#define F_OK 0

/*@
assigns \result, errno;
ensures \result == 0 || \result == -1;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int lockf(int fd, int cmd, off_t len);

/*@
assigns \result, errno;
ensures \result == 0 || \result == -1;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int lockf64(int fd, int cmd, off64_t len);

#endif /* LIBC___GT_FC_FCNTL_MACROS_H_ */
