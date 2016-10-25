/*
 * stdio_ext.h
 *
 *  Created on: Jul 7, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_STDIO_EXT_H_
#define LIBC_STDIO_EXT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_define_file.h"
#include "__gt_fc_file_axioms.h"

#define FSETLOCKING_INTERNAL 0
#define FSETLOCKING_BYCALLER 1
#define FSETLOCKING_QUERY    2

/*@
requires \valid_read(stream);
requires file_is_open(stream);
assigns \result \from *stream;
*/
int __freadable (FILE *stream);

/*@
requires \valid_read(stream);
requires file_is_open(stream);
assigns \result \from *stream;
*/
int __fwritable (FILE *stream);

/*@
requires \valid_read(stream);
requires file_is_open(stream);
assigns \result \from *stream;
*/
int __freading (FILE *stream);

/*@
requires \valid_read(stream);
requires file_is_open(stream);
assigns \result \from *stream;
*/
int __fwriting (FILE *stream);

/*@
requires \valid_read(stream);
requires file_is_open(stream);
requires type == FSETLOCKING_INTERNAL || type == FSETLOCKING_BYCALLER || type == FSETLOCKING_QUERY;
assigns \result \from *stream, type;
ensures \result == FSETLOCKING_INTERNAL || \result == FSETLOCKING_BYCALLER;
*/
int __fsetlocking (FILE *stream, int type);

/*@
assigns \nothing;
*/
void _flushlbf (void);

/*@
requires \valid_read(stream);
requires file_is_open(stream);
assigns *stream \from *stream;
*/
void __fpurge (FILE *stream);

/*@
requires \valid_read(stream);
requires file_is_open(stream);
assigns \result \from *stream;
*/
int __flbf (FILE *stream);

/*@
requires \valid_read(stream);
requires file_is_open(stream);
assigns \result \from *stream;
*/
size_t __fbufsize (FILE *stream);

/*@
requires \valid_read(stream);
requires file_is_open(stream);
assigns \result \from *stream;
*/
size_t __fpending (FILE *stream);

#endif /* LIBC_STDIO_EXT_H_ */
