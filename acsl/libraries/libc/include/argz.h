/*
 * argp.h
 *
 *  Created on: Jul 5, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ARGP_H_
#define LIBC_ARGP_H_

#include "errno.h"
#include "__fc_define_size_t.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_argv_axiomatic.h"

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

/*@
axiomatic ArgZ {
    logic boolean argz_valid(char* argz, size_t argz_len) reads *argz;
    logic size_t argz_count(char* argz) reads *argz;
    logic boolean argz_element(char* argz, char* elem) reads *argz;

    axiom argz_is_own_elem: \forall char* argz; argz_element(argz, argz);
}
*/

/*@
requires \exists size_t i; argv_count_pred(argv, i);
requires \valid(argz);
requires \valid(argz_len);
assigns \result, **argz, *argz_len \from argv[0..argv_count(argv)];
ensures argz_valid(*argz, *argz_len);
ensures argz_count(*argz) == argv_count(argv);
*/
error_t argz_create(char* const argv[], char** argz, size_t* argz_len);

/*@
requires \valid(string);
requires (char)sep == sep;
requires \valid(argz);
requires \valid(argz_len);
assigns \result, *argz, *argz_len \from string, sep;
ensures argz_valid(*argz, *argz_len);
*/
error_t argz_create_sep(const char* string, int sep, char** argz, size_t* argz_len);

/*@
requires argz_valid(argz, argz_len);
assigns \result \from *argz, argz_len;
ensures \result == argz_count(argz);
*/
size_t argz_count(const char* argz, size_t argz_len);

/*@
requires argz_valid(argz, argz_len);
requires \valid(argv+(0..argz_count(argz)));
assigns *argv[0..argz_count(argz)] \from *argz, argz_len;
ensures argv_count(argv) == argz_count(argz);
*/
void argz_extract(const char* argz, size_t argz_len, char** argv);

/*@
requires argz_valid(argz, argz_len);
requires (char)sep == sep;
assigns *argz \from *argz, argz_len, sep;
ensures valid_string(argz);
*/
void argz_stringify(char* argz, size_t argz_len, int sep);

/*@
requires argz_valid(*argz, *argz_len);
requires \valid_read(str);
assigns \result, **argz, *argz_len \from *argz, *argz_len, str;
ensures *argz_len >= \old(*argz_len);
ensures argz_valid(*argz, *argz_len);
ensures argz_count(*argz) == \old(argz_count(*argz)) + 1;
*/
error_t argz_add(char** argz, size_t* argz_len, const char* str);

/*@
requires argz_valid(*argz, *argz_len);
requires \valid_read(str);
requires (char)sep == sep;
assigns \result, **argz, *argz_len \from *argz, *argz_len, str, sep;
ensures *argz_len >= \old(*argz_len);
ensures argz_valid(*argz, *argz_len);
ensures argz_count(*argz) > \old(argz_count(*argz));
*/
error_t argz_add_sep(char** argz, size_t* argz_len, const char* str, int sep);

/*@
requires argz_valid(*argz, *argz_len);
requires \valid_read(str+(0..str_len-1));
assigns \result, **argz, *argz_len \from *argz, *argz_len, str[0..str_len-1];
ensures *argz_len >= \old(*argz_len);
ensures argz_valid(*argz, *argz_len);
ensures argz_count(*argz) == \old(argz_count(*argz)) + 1;
*/
error_t argz_append(char** argz, size_t* argz_len, const char* str, size_t str_len);

/*@
requires argz_valid(*argz, *argz_len);
requires argz_element(*argz, entry);
assigns *argz, *argz_len \from *argz, *argz_len, entry;
ensures *argz_len <= \old(*argz_len);
ensures argz_valid(*argz, *argz_len);
ensures argz_count(*argz) == \old(argz_count(*argz)) - 1;
*/
void argz_delete(char** argz, size_t* argz_len, char* entry);

/*@
requires argz_valid(*argz, *argz_len);
requires argz_element(*argz, before);
requires \valid_read(entry);
assigns \result, **argz, *argz_len \from *argz, *argz_len, before, entry;
ensures *argz_len >= \old(*argz_len);
ensures argz_valid(*argz, *argz_len);
ensures argz_count(*argz) == \old(argz_count(*argz)) + 1;
*/
error_t argz_insert(char** argz, size_t* argz_len, char* before, const char* entry);

/*@
requires argz_valid(argz, argz_len);
requires argz_element(argz, entry);
assigns \result \from *argz, argz_len;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> argz_element(argz, \result);
*/
char* argz_next(const char* argz, size_t argz_len, const char* entry);

/*@
requires argz_valid(*argz, *argz_len);
requires \valid_read(str);
requires \valid_read(with);
requires replace_count != \null ==> \valid(replace_count);
assigns \result, **argz, *argz_len, *replace_count \from *argz, *argz_len, str, with;
ensures *argz_len >= \old(*argz_len);
ensures argz_valid(*argz, *argz_len);
ensures argz_count(*argz) == \old(argz_count(*argz));
ensures 0 <= *replace_count <= argz_count(*argz);
*/
error_t argz_replace(char** argz, size_t* argz_len, const char* str, const char* with, unsigned* replace_count);

#endif /* LIBC_ARGP_H_ */
