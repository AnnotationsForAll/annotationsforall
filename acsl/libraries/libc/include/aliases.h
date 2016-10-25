/*
 * aliases.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ALIASES_H_
#define LIBC_ALIASES_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_string_axiomatic.h"
#include "errno.h"

struct aliasent {
    char *alias_name;
    size_t alias_members_len;
    char **alias_members;
    int alias_local;
};

//@ ghost void* __gt_fc_aliasent_state;

/*@
assigns errno;
ensures errno != 0 || errno == \old(errno);
*/
void setaliasent(void);

/*@
assigns \nothing;
*/
void endaliasent(void);

/*@
assigns \result, errno;
ensures \result == \null ? errno != 0 : errno == \old(errno);
ensures \result != \null ==> \valid_read(\result);
ensures \result != \null ==> valid_read_string(\result->alias_name);
ensures \result != \null ==> \forall integer i; 0 <= i < \result->alias_members_len ==> valid_read_string(\result->alias_members[i]);
*/
struct aliasent *getaliasent(void);

/*@
requires \valid(result);
requires \valid(buffer+(0..buflen-1));
requires \valid(res);
assigns \result, errno, *result, buffer[0..buflen-1], *res;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
ensures \result == 0 ==> *res == result;
ensures \result == 0 ==> valid_string(result->alias_name) && \base_addr(result->alias_name) == \base_addr(buffer);
ensures \result == 0 ==> \forall integer i; 0 <= i < result->alias_members_len ==> valid_string(result->alias_members[i]) && \base_addr(result->alias_members[i]) == \base_addr(buffer);
*/
int getaliasent_r(struct aliasent *result, char *buffer, size_t buflen, struct aliasent **res);

/*@
requires valid_read_string(name);
assigns \result, errno, __gt_fc_aliasent_state \from name[0..strlen(name)], __gt_fc_aliasent_state;
ensures \result != \null ==> errno == \old(errno);
ensures \result != \null ==> \valid_read(\result);
ensures \result != \null ==> valid_read_string(\result->alias_name);
ensures \result != \null ==> \forall integer i; 0 <= i < \result->alias_members_len ==> valid_read_string(\result->alias_members[i]);
*/
struct aliasent *getaliasbyname(const char *name);

/*@
requires valid_read_string(name);
requires \valid(result);
requires \valid(buffer+(0..buflen-1));
requires \valid(res);
assigns \result, errno, *result, buffer[0..buflen-1], *res, __gt_fc_aliasent_state \from name[0..strlen(name)], __gt_fc_aliasent_state;
ensures *res != \null ==> *res == result;
ensures *res != \null ==> valid_string(result->alias_name) && \base_addr(result->alias_name) == \base_addr(buffer);
ensures *res != \null ==> \forall integer i; 0 <= i < result->alias_members_len ==> valid_string(result->alias_members[i]) && \base_addr(result->alias_members[i]) == \base_addr(buffer);
*/
int getaliasbyname_r(const char *name, struct aliasent *result, char *buffer, size_t buflen, struct aliasent **res);

#endif /* LIBC_ALIASES_H_ */
