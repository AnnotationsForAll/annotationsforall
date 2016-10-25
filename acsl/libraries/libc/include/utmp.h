/*
 * utmp.h
 *
 *  Created on: Jul 12, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_UTMP_H_
#define LIBC_UTMP_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "paths.h"
#include "utmpx.h"

#define UTMP_FILE     _PATH_UTMP
#define UTMP_FILENAME _PATH_UTMP
#define WTMP_FILE     _PATH_WTMP
#define WTMP_FILENAME _PATH_WTMP

#define UT_LINESIZE 32
#define UT_NAMESIZE 32
#define UT_HOSTSIZE 256

#define UT_UNKNOWN EMPTY

struct lastlog {
    time_t ll_time;
    char ll_line[UT_LINESIZE];
    char ll_host[UT_HOSTSIZE];
};

/*@
assigns \nothing;
*/
void endutent(void);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
struct utmp *getutent(void);

/*@
requires \valid(id);
assigns \result \from *id;
ensures \result != \null ==> \valid(\result);
*/
struct utmp *getutid(const struct utmp *id);

/*@
requires \valid(line);
assigns \result \from *line;
ensures \result != \null ==> \valid(\result);
*/
struct utmp *getutline(const struct utmp *line);

/*@
requires \valid(utmpx);
assigns \result \from *utmpx;
ensures \result != \null ==> \valid(\result);
*/
struct utmp *pututline(const struct utmp *utmpx);

/*@
assigns \nothing;
*/
void setutent(void);

/*@
requires \valid(buffer);
requires \valid(result);
assigns \result, *buffer, *result \from \nothing;
*/
int getutent_r(struct utmp *buffer, struct utmp **result);

/*@
requires \valid(id);
requires \valid(buffer);
requires \valid(result);
assigns \result, *buffer, *result \from *buffer, *id;
*/
int getutid_r(const struct utmp *id, struct utmp *buffer, struct utmp **result);

/*@
requires \valid(line);
requires \valid(buffer);
requires \valid(result);
assigns \result, *buffer, *result \from *line, *buffer;
*/
int getutline_r(const struct utmp *line, struct utmp *buffer, struct utmp **result);

/*@
requires \valid(file);
assigns \result \from file[0..];
*/
int utmpname(const char *file);

/*@
requires \valid(file);
requires \valid(utmp);
assigns \nothing;
*/
void updwtmp(const char *file, const struct utmp *utmp);

/*@
assigns \result \from fildes;
ensures \result == -1 || \result == 0;
*/
int login_tty (int fildes);

/*@
requires \valid(entry);
*/
void login (const struct utmp *entry);

/*@
requires \valid(ut_line);
assigns \result \from ut_line;
ensures \result == 1 || \result == 0;
*/
int logout (const char *ut_line);

/*@
requires \valid(ut_line);
requires \valid(ut_name);
requires \valid(ut_host);
*/
void logwtmp (const char *ut_line, const char *ut_name, const char *ut_host);

#endif /* LIBC_UTMP_H_ */
