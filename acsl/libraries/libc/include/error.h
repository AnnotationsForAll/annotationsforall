/*
 * error.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ERROR_H_
#define LIBC_ERROR_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

extern void (*error_print_progname) (void);
extern unsigned int error_message_count;
extern int error_one_per_line;

/*@
requires \valid(format);
assigns \nothing;
exits status != 0 && \exit_status == status;
ensures status != 0 ==> \false;
*/
void error (int status, int errnum, const char *format, ...);

/*@
requires \valid(fname);
requires \valid(format);
assigns \nothing;
exits status != 0 && \exit_status == status;
ensures status != 0 ==> \false;
*/
void error_at_line (int status, int errnum, const char *fname, unsigned int lineno, const char *format, ...);

#endif /* LIBC_ERROR_H_ */
