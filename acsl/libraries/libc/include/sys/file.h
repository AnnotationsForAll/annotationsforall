/*
 * file.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_FILE_H_
#define LIBC_SYS_FILE_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_seek_macros.h"
#include "../fcntl.h"

#include "errno.h"

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int flock (int fd, int operation);

#endif /* LIBC_SYS_FILE_H_ */
