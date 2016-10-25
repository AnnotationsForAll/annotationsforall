/*
 * swap.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_SWAP_H_
#define LIBC_SYS_SWAP_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_string_axiomatic.h"
#include "../errno.h"

#define SWAP_FLAG_PREFER  (1 << 0)
#define SWAP_FLAG_DISCARD (1 << 1)

#define SWAP_FLAG_PRIO_MASK   (~0b11)
#define SWAP_FLAG_PRIO_SHIFT  2

/*@
requires valid_read_string(path);
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int swapon(const char *path, int swapflags);

/*@
requires valid_read_string(path);
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int swapoff(const char *path);

#endif /* LIBC_SYS_SWAP_H_ */
