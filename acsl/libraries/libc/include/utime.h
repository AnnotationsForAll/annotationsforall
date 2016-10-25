/*
 * utime.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_UTIME_H_
#define LIBC_UTIME_H_

// This POSIX header is marked obselescent. Do not use for new work.

#include "time.h"

#include "__fc_string_axiomatic.h"
#include "errno.h"

struct utimbuf {
    time_t actime;
    time_t modtime;
};

/*@
requires valid_read_string(file);
requires file_times != \null ==> \valid_read(file_times);
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int utime(const char *file, const struct utimbuf *file_times);

#endif /* LIBC_UTIME_H_ */
