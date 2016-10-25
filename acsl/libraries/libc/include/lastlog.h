/*
 * lastlog.h
 *
 *  Created on: Jul 19, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_LASTLOG_H_
#define LIBC_LASTLOG_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "utmp.h" // just include UTMP, because it (should) have lastlog in it. This is what glibc does.

#endif /* LIBC_LASTLOG_H_ */
