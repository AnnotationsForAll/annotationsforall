/*
 * err.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ERR_H_
#define LIBC_ERR_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "stdarg.h"

/*@
requires \valid(format);
assigns \nothing;
*/
void warn (const char *format, ...);

/*@
requires \valid(format);
assigns \nothing;
*/
void warnx (const char *format, ...);

/*@
requires \valid(format);
assigns \nothing;
exits \exit_status == status;
ensures \false;
*/
void err (int status, const char *format, ...);

/*@
requires \valid(format);
assigns \nothing;
exits \exit_status == status;
ensures \false;
*/
void errx (int status, const char *format, ...);

void vwarn (const char *format, va_list ap);
void vwarnx (const char *format, va_list ap);
void verr (int status, const char *format, va_list ap);
void verrx (int status, const char *format, va_list ap);

#endif /* LIBC_ERR_H_ */
