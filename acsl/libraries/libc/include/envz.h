/*
 * envz.h
 *
 *  Created on: Jul 6, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ENVZ_H_
#define LIBC_ENVZ_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "argz.h"

/*@
requires argz_valid(envz, envz_len);
requires \valid(name);
assigns \result \from *envz, envz_len, name[0..];
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> argz_element(envz, \result);
*/
char * envz_entry(const char *envz, size_t envz_len, const char *name);

/*@
requires argz_valid(envz, envz_len);
requires \valid(name);
assigns \result \from *envz, envz_len, name[0..];
ensures \result != \null ==> \valid(\result);
*/
char * envz_get(const char *envz, size_t envz_len, const char *name);

/*@
requires argz_valid(*envz, *envz_len);
requires \valid_read(name);
requires value != \null ==> \valid_read(value);
assigns \result, **envz, *envz_len \from *envz, *envz_len, name[0..], value[0..];
ensures *envz_len >= \old(*envz_len);
ensures argz_valid(*envz, *envz_len);
ensures argz_count(*envz) >= \old(argz_count(*envz));
*/
error_t envz_add(char **envz, size_t *envz_len, const char *name, const char *value);

/*@
requires argz_valid(*envz, *envz_len);
requires argz_valid(envz2, envz2_len);
assigns \result, **envz, *envz_len \from *envz, *envz_len, *envz2, envz2_len, override;
ensures *envz_len >= \old(*envz_len);
ensures argz_valid(*envz, *envz_len);
ensures argz_count(*envz) >= \old(argz_count(*envz));
*/
error_t envz_merge(char **envz, size_t *envz_len, const char *envz2, size_t envz2_len, int override);

/*@
requires argz_valid(*envz, *envz_len);
assigns **envz, *envz_len \from *envz, *envz_len;
ensures *envz_len <= \old(*envz_len);
ensures argz_valid(*envz, *envz_len);
ensures argz_count(*envz) <= \old(argz_count(*envz));
*/
void envz_strip(char **envz, size_t *envz_len);

/*@
requires argz_valid(*envz, *envz_len);
requires \valid_read(name);
assigns **envz, *envz_len \from *envz, *envz_len, name[0..];
ensures *envz_len <= \old(*envz_len);
ensures argz_valid(*envz, *envz_len);
ensures argz_count(*envz) <= \old(argz_count(*envz));
*/
void envz_remove(char **envz, size_t *envz_len, const char *name);

#endif /* LIBC_ENVZ_H_ */
