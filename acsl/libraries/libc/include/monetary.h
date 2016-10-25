/*
 * monetary.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_MONETARY_H_
#define LIBC_MONETARY_H_

#include "__fc_define_size_t.h"
#include "__fc_define_ssize_t.h"
#include "__gt_fc_define_locale_t.h"
#include "errno.h"

/*@
requires \valid(s+(0..maxsize-1));
requires \valid(format);
assigns \result, s[0..maxsize-1], errno \from maxsize, format[..];
ensures -1 <= \result <= maxsize;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t strfmon(char *restrict s, size_t maxsize, const char *restrict format, ...);

/*@
requires \valid(s+(0..maxsize-1));
requires \valid(format);
assigns \result, s[0..maxsize-1], errno \from maxsize, format[..], locale;
ensures -1 <= \result <= maxsize;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t strfmon_l(char *restrict s, size_t maxsize, locale_t locale, const char *restrict format, ...);

#endif /* LIBC_MONETARY_H_ */
