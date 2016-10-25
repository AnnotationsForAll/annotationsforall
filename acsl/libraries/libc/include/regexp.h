/*
 * regexp.h
 *
 *  Created on: Jul 19, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_REGEXP_H_
#define LIBC_REGEXP_H_

// This is a deprecated POSIX header. It is not present on most current systems.

extern char *loc1;
extern char *loc2;
extern char *locs;

// These functions rely on the execution of user-defined macros, and as such, could exhibit any behavior.
// Therefore, they are left unnanotated.

int advance(const char *string, const char *expbuf);
char *compile(char *instring, char *expbuf, const char *endbuf, int eof);
int step(const char *string, const char *expbuf);

#endif /* LIBC_REGEXP_H_ */
