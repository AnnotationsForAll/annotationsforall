/*
 * pty.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_PTY_H_
#define LIBC_PTY_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "termios.h"
#include "sys/ioctl.h"

/*@
requires \valid(amaster);
requires \valid(aslave);
requires name != \null ==> \valid(name);
requires termp != \null ==> \valid(termp);
requires winp != \null ==> \valid(winp);
assigns \result, *amaster, *aslave, *name \from *termp, *winp;
ensures \result == -1 || \result == 0;
*/
int openpty (int *amaster, int *aslave, char *name, const struct termios *termp, const struct winsize *winp);

/*@
requires \valid(amaster);
requires name != \null ==> \valid(name);
requires termp != \null ==> \valid(termp);
requires winp != \null ==> \valid(winp);
assigns \result, *amaster, *name \from *termp, *winp;
ensures \result == -1 || \result == 0;
*/
int forkpty (int *amaster, char *name, const struct termios *termp, const struct winsize *winp);

#endif /* LIBC_PTY_H_ */
