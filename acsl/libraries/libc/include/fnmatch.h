/*
 * fnmatch.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_FNMATCH_H_
#define LIBC_FNMATCH_H_

#define FNM_NOMATCH -1

#define FNM_PATHNAME    (1 << 0)
#define FNM_PERIOD      (1 << 1)
#define FNM_NOESCAPE    (1 << 2)
#define FNM_LEADING_DIR (1 << 3)
#define FNM_CASEFOLD    (1 << 4)
#define FNM_EXTMATCH    (1 << 5)
#define FNM_FILE_NAME   FNM_PATHNAME

/*@
requires \valid(pattern) && \valid(string);
assigns \result \from pattern[..], string[..], flags;
*/
int fnmatch(const char *pattern, const char *string, int flags);

#endif /* LIBC_FNMATCH_H_ */
