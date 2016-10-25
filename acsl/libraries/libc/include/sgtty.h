/*
 * sgtty.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SGTTY_H_
#define LIBC_SGTTY_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "errno.h"

struct sgttyb {
    char sg_ispeed;
    char sg_ospeed;
    char sg_erase;
    char sg_kill;
    int sg_flags;
};

/*@
requires \valid(attributes);
assigns \result, errno, *attributes \from fildes;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int gtty (int fildes, struct sgttyb *attributes);

/*@
requires \valid(attributes);
assigns \result, errno \from fildes, *attributes;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int stty (int fildes, const struct sgttyb *attributes);

#endif /* LIBC_SGTTY_H_ */
