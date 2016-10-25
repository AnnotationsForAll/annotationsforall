/*
 * wordexp.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_WORDEXP_H_
#define LIBC_WORDEXP_H_

#include "__fc_define_size_t.h"

typedef struct wordexp_t {
    size_t we_wordc;
    char** we_wordv;
    size_t we_offs;
} wordexp_t;

#define WRDE_APPEND 1
#define WRDE_DOOFFS 2
#define WRDE_NOCMD 4
#define WRDE_REUSE 8
#define WRDE_SHOWERR 16
#define WRDE_UNDEF 32

#define WRDE_BADCHAR 1
#define WRDE_BADVAL 2
#define WRDE_CMDSUB 3
#define WRDE_NOSPACE 4
#define WRDE_SYNTAX 5

/*@
axiomatic IsWordExpOpen {
    logic boolean wordexp_is_open(wordexp_t * worde) reads *worde;
}
*/

/*@
requires \valid(words);
requires \valid(pwordexp);
assigns \result, *pwordexp \from words[..], flags;
ensures (\result == 0 || \result == WRDE_NOSPACE) ==> wordexp_is_open(pwordexp);
*/
int wordexp(const char *restrict words, wordexp_t *restrict pwordexp, int flags);

/*@
requires wordexp_is_open(pwordexp);
assigns *pwordexp \from *pwordexp;
ensures !wordexp_is_open(pwordexp);
*/
void wordfree(wordexp_t *pwordexp);

#endif /* LIBC_WORDEXP_H_ */
