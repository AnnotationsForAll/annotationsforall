/*
 * execinfo.h
 *
 *  Created on: Jul 6, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_EXECINFO_H_
#define LIBC_EXECINFO_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

// Disallow parralellism
#error "Frama-C: unsupported execinfo.h"

int backtrace(void **buffer, int size);
char ** backtrace_symbols(void * const *buffer, int size);
void backtrace_symbols_fd(void * const *buffer, int size, int fd);

#endif /* LIBC_EXECINFO_H_ */
