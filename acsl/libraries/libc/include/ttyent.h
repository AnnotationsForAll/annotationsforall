/*
 * ttyent.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_TTYENT_H_
#define LIBC_TTYENT_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "__fc_string_axiomatic.h"

#define TTY_ON     (1 << 0)
#define TTY_SECURE (1 << 1)

struct ttyent {
    char *ty_name;
    char *ty_getty;
    char *ty_type;
    int ty_status;
    char *ty_window;
    char *ty_comment;
};

/*@
assigns \result;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> valid_string_or_null(\result->ty_name);
ensures \result != \null ==> valid_string_or_null(\result->ty_getty);
ensures \result != \null ==> valid_string_or_null(\result->ty_type);
ensures \result != \null ==> valid_string_or_null(\result->ty_window);
ensures \result != \null ==> valid_string_or_null(\result->ty_comment);
*/
struct ttyent *getttyent(void);

/*@
requires valid_read_string(name);
assigns \result;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> valid_string_or_null(\result->ty_name);
ensures \result != \null ==> valid_string_or_null(\result->ty_getty);
ensures \result != \null ==> valid_string_or_null(\result->ty_type);
ensures \result != \null ==> valid_string_or_null(\result->ty_window);
ensures \result != \null ==> valid_string_or_null(\result->ty_comment);
*/
struct ttyent *getttynam(const char *name);

/*@
assigns \result;
ensures \result == 0 || \result == 1;
*/
int setttyent(void);

/*@
assigns \result;
ensures \result == 0 || \result == 1;
*/
int endttyent(void);

#endif /* LIBC_TTYENT_H_ */
