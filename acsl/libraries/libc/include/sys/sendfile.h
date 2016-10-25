/*
 * sendfile.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_SENDFILE_H_
#define LIBC_SYS_SENDFILE_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_size_t.h"
#include "../__fc_define_ssize_t.h"
#include "../__fc_define_off_t.h"

#include "../errno.h"

/*@
requires offset != \null ==> \valid(offset);
assigns errno, \result;
ensures -1 <= \result <= count;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t sendfile(int out_fd, int in_fd, off_t *offset, size_t count);

/*@
requires offset != \null ==> \valid(offset);
assigns errno, \result;
ensures -1 <= \result <= count;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t sendfile64(int out_fd, int in_fd, off64_t *offset, size_t count);

#endif /* LIBC_SYS_SENDFILE_H_ */
