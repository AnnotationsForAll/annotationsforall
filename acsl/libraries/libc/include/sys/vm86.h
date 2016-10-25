/*
 * vm86.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_VM86_H_
#define LIBC_SYS_VM86_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

struct vm86plus_struct {
    void* dummy; //FIXME?
};

// This function cannot be annotated. It interprets fn as a pointer, and executes code there with 8086 emulation.
int vm86(unsigned long fn, struct vm86plus_struct *v86);

#endif /* LIBC_SYS_VM86_H_ */
