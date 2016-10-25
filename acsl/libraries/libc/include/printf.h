/*
 * printf.h
 *
 *  Created on: Jul 7, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_PRINTF_H_
#define LIBC_PRINTF_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_define_wchar_t.h"
#include "__fc_define_size_t.h"
#include "__fc_define_file.h"
#include "stdarg.h"

#define PA_FLAG_MASK ((int)0xFFFFFF00)

#define PA_INT     0
#define PA_CHAR    1
#define PA_STRING  2
#define PA_POINTER 3
#define PA_FLOAT   4
#define PA_DOUBLE  5
#define PA_LAST    6

#define PA_FLAG_PTR         (1 << 8)
#define PA_FLAG_SHORT       (1 << 9)
#define PA_FLAG_LONG        (1 << 10)
#define PA_FLAG_LONG_LONG   (1 << 11)
#define PA_FLAG_LONG_DOUBLE (1 << 12)

struct printf_info {
    int prec;
    int width;
    wchar_t spec;
    unsigned int is_long_double;
    unsigned int is_char;
    unsigned int is_short;
    unsigned int is_long;
    unsigned int alt;
    unsigned int space;
    unsigned int left;
    unsigned int showsign;
    unsigned int group;
    unsigned int extra;
    unsigned int wide;
    wchar_t pad;
};

typedef int (*printf_function)(FILE *stream, const struct printf_info *info, const void * const *args);
typedef int (*printf_arginfo_function)(const struct printf_info *info, size_t n, int *argtypes);
typedef int (*printf_arginfo_size_function)(const struct printf_info *info, size_t n, int *argtypes, int *size);
typedef void (*printf_va_arg_function)(void *mem, va_list *ap);

/*@
requires (char)spec == spec;
requires handler_function != \null;
requires arginfo_function != \null;
assigns \result \from spec, handler_function, arginfo_function;
ensures \result == -1 || \result == 0;
*/
int register_printf_function(int spec, printf_function handler_function, printf_arginfo_function arginfo_function);

/*@
requires \valid(template);
requires \valid(argtypes+(0..n-1));
assigns argtypes[0..n-1] \from template[0..], n;
*/
size_t parse_printf_format(const char *template, size_t n, int *argtypes);

// The following functions are undocumented, but some applications might make use of them.

int printf_size(FILE *stream, const struct printf_info *info, const void * const *args);
int printf_size_info(const struct printf_info *info, size_t n, int *argtypes);
int register_printf_modifier(const wchar_t *str);
int register_printf_specifier(int spec, printf_function func, printf_arginfo_size_function arginfo);
int register_printf_type (printf_va_arg_function fct);

#endif /* LIBC_PRINTF_H_ */
