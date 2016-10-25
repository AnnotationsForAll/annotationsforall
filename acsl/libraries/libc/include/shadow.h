/*
 * shadow.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SHADOW_H_
#define LIBC_SHADOW_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_define_size_t.h"
#include "__fc_define_file.h"
#include "paths.h"

#include "__fc_string_axiomatic.h"
#include "__gt_fc_file_axioms.h"
#include "errno.h"

#define SHADOW _PATH_SHADOW

struct spwd {
    char *sp_namp;
    char *sp_pwdp;
    long sp_lstchg;
    long sp_min;
    long sp_max;
    long sp_warn;
    long sp_inact;
    long sp_expire;
    unsigned long sp_flag;
};

/*@
requires valid_read_string(name);
assigns errno, \result;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> valid_string(\result->sp_namp);
ensures \result != \null ==> valid_string(\result->sp_pwdp);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
struct spwd *getspnam(const char *name);

/*@
assigns errno, \result;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> valid_string(\result->sp_namp);
ensures \result != \null ==> valid_string(\result->sp_pwdp);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
struct spwd *getspent(void);

/*@
assigns errno;
*/
void setspent(void);

/*@
assigns errno;
*/
void endspent(void);

/*@
requires file_is_open(stream);
assigns errno, \result;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> valid_string(\result->sp_namp);
ensures \result != \null ==> valid_string(\result->sp_pwdp);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
struct spwd *fgetspent(FILE *stream);

/*@
requires valid_read_string(name);
assigns errno, \result;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> valid_string(\result->sp_namp);
ensures \result != \null ==> valid_string(\result->sp_pwdp);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
struct spwd *sgetspent(const char *name);

/*@
requires \valid_read(p);
requires valid_read_string(p->sp_namp);
requires valid_read_string(p->sp_pwdp);
requires file_is_open(stream);
assigns errno, \result, *stream;
ensures file_is_open(stream);
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int putspent(const struct spwd *p, FILE *stream);

/*@
assigns errno, \result;
ensures \result == 0 || \result == -1;
*/
int lckpwdf(void);

/*@
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ulckpwdf(void);

/*@
requires \valid(spbuf);
requires \valid(buf+(0..buflen-1));
requires \valid(spbufp);
assigns errno, \result, *spbuf, buf[0..buflen-1], *spbufp;
ensures *spbufp != \null ==> *spbufp == spbuf;
ensures *spbufp != \null ==> valid_string(spbuf->sp_namp);
ensures *spbufp != \null ==> valid_string(spbuf->sp_pwdp);
ensures \result == 0 || \result == -1;
ensures \result == -1 ==> *spbufp == \null;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getspent_r(struct spwd *spbuf, char *buf, size_t buflen, struct spwd **spbufp);

/*@
requires valid_read_string(name);
requires \valid(spbuf);
requires \valid(buf+(0..buflen-1));
requires \valid(spbufp);
assigns errno, \result, *spbuf, buf[0..buflen-1], *spbufp;
ensures *spbufp != \null ==> *spbufp == spbuf;
ensures *spbufp != \null ==> valid_string(spbuf->sp_namp);
ensures *spbufp != \null ==> valid_string(spbuf->sp_pwdp);
ensures \result == 0 || \result == -1;
ensures \result == -1 ==> *spbufp == \null;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getspnam_r(const char *name, struct spwd *spbuf, char *buf, size_t buflen, struct spwd **spbufp);

/*@
requires file_is_open(stream);
requires \valid(spbuf);
requires \valid(buf+(0..buflen-1));
requires \valid(spbufp);
assigns errno, \result, *spbuf, buf[0..buflen-1], *spbufp;
ensures *spbufp != \null ==> *spbufp == spbuf;
ensures *spbufp != \null ==> valid_string(spbuf->sp_namp);
ensures *spbufp != \null ==> valid_string(spbuf->sp_pwdp);
ensures \result == 0 || \result == -1;
ensures \result == -1 ==> *spbufp == \null;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fgetspent_r(FILE *stream, struct spwd *spbuf, char *buf, size_t buflen, struct spwd **spbufp);

/*@
requires valid_read_string(name);
requires \valid(spbuf);
requires \valid(buf+(0..buflen-1));
requires \valid(spbufp);
assigns errno, \result, *spbuf, buf[0..buflen-1], *spbufp;
ensures *spbufp != \null ==> *spbufp == spbuf;
ensures *spbufp != \null ==> valid_string(spbuf->sp_namp);
ensures *spbufp != \null ==> valid_string(spbuf->sp_pwdp);
ensures \result == 0 || \result == -1;
ensures \result == -1 ==> *spbufp == \null;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sgetspent_r(const char *name, struct spwd *spbuf, char *buf, size_t buflen, struct spwd **spbufp);

#endif /* LIBC_SHADOW_H_ */
