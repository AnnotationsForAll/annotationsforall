/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2015                                               */
/*    CEA (Commissariat à l'énergie atomique et aux énergies              */
/*         alternatives)                                                  */
/*                                                                        */
/*  you can redistribute it and/or modify it under the terms of the GNU   */
/*  Lesser General Public License as published by the Free Software       */
/*  Foundation, version 2.1.                                              */
/*                                                                        */
/*  It is distributed in the hope that it will be useful,                 */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/*  GNU Lesser General Public License for more details.                   */
/*                                                                        */
/*  See the GNU Lesser General Public License version 2.1                 */
/*  for more details (enclosed in the file licenses/LGPLv2.1).            */
/*                                                                        */
/**************************************************************************/

/* ISO C: 7.19 */
#ifndef __FC_STDIO
#define __FC_STDIO
#include "features.h"
#include "__fc_machdep.h"
#include "__fc_define_ssize_t.h"
#include "__fc_define_stat.h"
#include "__fc_define_fpos_t.h"
#include "__fc_define_file.h"
#include "__fc_define_null.h"
#include "__gt_fc_define_ctermid.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_file_axioms.h"
#include "stdarg.h"
#include "stddef.h"
#include "errno.h"
#include "obstack.h"
#include "paths.h"

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define BUFSIZ __FC_BUFSIZ
#define EOF __FC_EOF
#define FOPEN_MAX __FC_FOPEN_MAX
#define FILENAME_MAX __FC_FILENAME_MAX
#define L_tmpnam __FC_L_tmpnam

#include "__fc_define_seek_macros.h"

#define TMP_MAX __FC_TMP_MAX

__BEGIN_DECLS

extern FILE * __fc_stderr;
#define stderr (__fc_stderr)

extern FILE * __fc_stdin;
#define stdin (__fc_stdin)

extern FILE * __fc_stdout;
#define stdout (__fc_stdout)

FILE __fc_fopen[__FC_FOPEN_MAX];
FILE* const __p_fc_fopen = __fc_fopen;

/*
  Note: currently some functions only consider the __fc_stdio_id field of FILE.
        This models the fact that operations on different files are considered
        non-interferent between them.
*/


/*@
assigns \result \from filename[..];
*/ 
int remove(const char *filename);

/*@
assigns \result \from old_name[..], new_name[..];
*/
int rename(const char *old_name, const char *new_name);

/*@
assigns \result \from __fc_fopen[..]; 
ensures \result==\null || (\valid(\result) && file_is_open(\result));
*/
FILE *tmpfile(void);

//@ ghost char __tmpnam_buffer[L_tmpnam];

/*@
behavior null_argument:
    assumes s == \null;
    assigns __tmpnam_buffer[..];
    ensures \result == __tmpnam_buffer || \result == \null;
behavior pointer_argument:
    assumes s != \null;
    requires \valid(s+(0..( L_tmpnam )-1));
    assigns s[..];
    ensures \result == s || \result == \null;
complete behaviors; disjoint behaviors;
*/
char *tmpnam(char *s);

/*@
requires \valid(stream);
requires file_is_open(stream);
assigns \result \from stream, stream->__fc_stdio_id;
ensures !file_has_buffer(stream); //TODO: automatic deallocation of buffer
ensures \result == 0 ==> !file_is_open(stream);
ensures \result == 0 || \result == EOF;
*/
int fclose(FILE *stream);

/*@
requires stream == \null || \valid_read(stream);
requires stream != \null ==> file_is_open(stream);
assigns \result, *stream \from *stream;
ensures \result == 0 || \result == EOF;
*/
int fflush(FILE *stream);

/*@ 
requires \valid(filename) && \valid(mode);
assigns \result \from filename[..], mode[..], __p_fc_fopen, errno;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result);
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
ensures \result==\null || (\valid(\result) && file_is_open(\result));
*/ 
FILE *fopen(const char * restrict filename, const char * restrict mode);

/*@ 
requires \valid(filename) && \valid(mode);
//requires valid_fopen_mode(mode);
requires \valid(stream); //FIXME: needs to be a file once returned by fopen; but can be a closed file
assigns \result \from filename[..], mode[..], __fc_fopen[..], *stream;
ensures \result != \null ==> \result == stream;
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result);
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
*/ 
FILE *freopen(const char * restrict filename,
              const char * restrict mode,
              FILE * restrict stream);

/*@
requires buf == \null || \valid(buf+(0..( BUFSIZ )-1));
requires file_is_open(stream);
assigns *stream, buf[..] \from buf;
behavior pass:
    assumes file_op_failed(stream);
    ensures file_has_buffer(stream);
    ensures buf == \null <==> file_dynamic_buffer(stream);
behavior fail:
    assumes !file_op_failed(stream);
complete behaviors; disjoint behaviors;
*/
void setbuf(FILE * restrict stream,
     char * restrict buf);

/*@
requires buf == \null || \valid(buf+(0..size-1));
requires file_is_open(stream);
assigns *stream, buf[..] \from buf, mode, size;
ensures \result == 0 ==> file_has_buffer(stream);
ensures \result == 0 ==> (buf == \null <==> file_dynamic_buffer(stream));
*/
int setvbuf(FILE * restrict stream,
     char * restrict buf,
     int mode, size_t size);

/*@
requires file_is_open(stream);
requires \valid(format);
assigns *stream \from stream->__fc_stdio_id;
// unsupported...
*/
int fprintf(FILE * restrict stream,
     const char * restrict format, ...);

/*@
requires \valid(stream);
requires \valid(format);
assigns *stream \from stream->__fc_stdio_id;
ensures \result >= 0 || \result == EOF;
// unsupported...
*/
int fscanf(FILE * restrict stream,
     const char * restrict format, ...);

/*@
requires \valid(format);
assigns *__fc_stdout \from format[..];
// unsupported...
*/
int printf(const char * restrict format, ...);

/*@
requires \valid(format);
assigns *__fc_stdin;
ensures \result >= 0 || \result == EOF;
*/
int scanf(const char * restrict format, ...);

/*@
requires \valid(s+(0..n-1));
requires \valid(format);
assigns s[0..n-1];
*/
int snprintf(char * restrict s, size_t n,
    const char * restrict format, ...);

/*@
// This is not a useful spec - assume termination
//requires \false; //FIXME: sprintf can never be verified, as an infinitely long string could always be written here
assigns \nothing;
*/
int sprintf(char * restrict s,
     const char * restrict format, ...);

/*@ //TODO: assigns
requires \valid(s);
requires \valid(format);
ensures \result >= 0 || \result == EOF;
// unsupported...
*/
int sscanf(const char * restrict s,
     const char * restrict format, ...);

/*@
requires file_is_open(stream);
assigns *stream \from format[..], arg;
*/
int vfprintf(FILE * restrict stream,
     const char * restrict format,
     va_list arg);

/*@
requires file_is_open(stream);
assigns *stream \from format[..], *stream, arg; 
ensures \result >= 0 || \result == EOF;
*/
int vfscanf(FILE * restrict stream,
     const char * restrict format,
     va_list arg);

/*@
assigns *__fc_stdout \from format[..], arg;
*/
int vprintf(const char * restrict format,
     va_list arg);

/*@
assigns *__fc_stdin \from format[..], *__fc_stdin, arg; 
ensures \result >= 0 || \result == EOF;
*/
int vscanf(const char * restrict format,
     va_list arg);

/*@
requires \valid(s+(0..n-1));
requires \valid(format);
assigns s[0..n-1] \from format[..], arg;
*/
int vsnprintf(char * restrict s, size_t n,
     const char * restrict format,
     va_list arg);

/*@
requires \false; //FIXME: sprintf can never be verified, as an infinitely long string could always be written here
*/
int vsprintf(char * restrict s,
     const char * restrict format,
     va_list arg);

/*@ //TODO: assigns
requires \valid(s);
requires \valid(format);
ensures \result >= 0 || \result == EOF;
*/
int vsscanf(const char * restrict s,
     const char * restrict format,
     va_list arg);

/*@
requires file_is_open(stream);
assigns *stream;
ensures file_is_open(stream);
ensures (unsigned char)\result == \result || \result == EOF;
*/
int fgetc(FILE *stream);

/*@
requires file_is_open(stream);
requires \valid(s+(0..n-1));
assigns s[0..n-1],*stream \from *stream;
assigns \result \from s,n,*stream;
ensures \result == \null || \result == s;
*/
char *fgets(char * restrict s, int n,
    FILE * restrict stream);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures \result == (unsigned char)c || \result == EOF;
*/
int fputc(int c, FILE *stream);

/*@
requires file_is_open(stream);
requires \valid(s);
assigns *stream \from s[..];
ensures \result >= 0 || \result == EOF;
*/
int fputs(const char * restrict s,
     FILE * restrict stream);

/*@
requires file_is_open(stream);
assigns \result, *stream \from *stream;
ensures (unsigned char)\result == \result || \result == EOF;
 */
int getc(FILE *stream);

/*@
assigns *__fc_stdin;
ensures (unsigned char)\result == \result || \result == EOF;
 */
int getchar(void);

/*@
assigns s[..],*__fc_stdin \from *__fc_stdin;
assigns \result \from s,*__fc_stdin;
ensures \result == \null || \result == s;
*/
char *gets(char *s);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures \result == (unsigned char)c || \result == EOF;
*/
int putc(int c, FILE *stream);

/*@
assigns *__fc_stdout \from c, *__fc_stdout;
ensures \result == (unsigned char)c || \result == EOF;
*/
int putchar(int c);

/*@
requires \valid(s);
assigns *__fc_stdout \from s[..];
ensures \result >= 0 || \result == EOF;
*/
int puts(const char *s);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures file_is_open(stream);
ensures \result == (unsigned char)c || \result == EOF;
ensures \result != EOF ==> !file_eof(stream);
*/
int ungetc(int c, FILE *stream);

/*@
requires \valid(((char*)ptr)+(0..(nmemb*size)-1));
requires file_is_open(stream);
assigns *(((char*)ptr)+(0..(nmemb*size)-1)), \result \from size, nmemb, *stream;
ensures 0 <= \result <= (nmemb*size);
ensures \initialized(((char*)ptr)+(0..(\result*size)-1));
//TODO: specify precise fields from struct FILE
*/
size_t fread(void * restrict ptr,
     size_t size, size_t nmemb,
     FILE * restrict stream);

/*@
requires \valid(((char*)ptr)+(0..(nmemb*size)-1));
requires file_is_open(stream);
assigns *stream, \result \from *(((char*)ptr)+(0..(nmemb*size)-1));
ensures 0 <= \result <= (nmemb*size);
//TODO: specify precise fields from struct FILE
*/
size_t fwrite(const void * restrict ptr,
     size_t size, size_t nmemb,
     FILE * restrict stream);

/*@
requires \valid(pos);
requires file_is_open(stream);
assigns *pos \from *stream;
*/
int fgetpos(FILE * restrict stream,
     fpos_t * restrict pos);

/*@
requires file_is_open(stream);
assigns *stream \from offset, whence;
*/
int fseek(FILE *stream, long int offset, int whence);

/*@
requires file_is_open(stream);
requires \valid(pos);
assigns *stream \from *pos;
*/
int fsetpos(FILE *stream, const fpos_t *pos);

/*@
requires file_is_open(stream);
assigns \result \from *stream;
*/
long int ftell(FILE *stream);

/*@
requires file_is_open(stream);
assigns *stream \from \nothing;
*/
void rewind(FILE *stream);

/*@
requires file_is_open(stream);
assigns *stream \from *stream;
ensures !file_error(stream);
*/
void clearerr(FILE *stream);

/*@
requires file_is_open(stream);
assigns \result \from *stream;
ensures \result == 0 <==> !file_eof(stream);
*/
int feof(FILE *stream);

/*@
requires file_is_open(stream);
assigns \result \from *stream;
ensures \result == 0 <==> !file_error(stream);
*/
int ferror(FILE *stream);

/*@
requires s != \null ==> \valid(s);
assigns __fc_stderr \from __FC_errno, s[..];
*/
void perror(const char *s);

/* POSIX */

/*@
requires \valid(mode); 
//requires \valid(mode);
//requires valid_fopen_mode(mode);
assigns \result \from fildes, mode[..], __fc_fopen[..];
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result); //TODO: ensure that the file backing the stream is fildes
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
*/ 
FILE *fdopen(int fildes, const char *mode);

/*@
requires \valid(format);
assigns \result \from fildes, format[..];
ensures 0 <= \result;
*/
int dprintf(int fildes, const char *restrict format, ...);

/*@
requires file_is_open(stream);
assigns \result \from *stream;
ensures \result >= -1;
*/
int fileno(FILE *stream);

/*@
requires file_is_open(stream);
assigns *stream \from \nothing;
*/
void flockfile(FILE *stream);

/*@
requires file_is_open(stream);
assigns *stream \from \nothing;
*/
void funlockfile(FILE *stream);

/*@
requires file_is_open(stream);
assigns \result, *stream \from \nothing;
*/
int ftrylockfile(FILE *stream);

/*@
requires \valid(mode);
//requires valid_string(mode);
//requires valid_fopen_mode(mode);
requires buf != \null ==> \valid(((char*)buf)+(0..size-1));
assigns \result \from mode[..], ((char*)buf)[0..size-1], __fc_fopen[..];
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result); //TODO: ensure that the file backing the stream is fildes
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
*/
FILE *fmemopen(void *restrict buf, size_t size, const char *restrict mode);

/*@
requires file_is_open(stream);
assigns *stream \from offset, whence;
*/
int fseeko(FILE *stream, off_t offset, int whence);

/*@
requires file_is_open(stream);
assigns \result \from *stream;
*/
off_t ftello(FILE *stream);

/*@
requires \valid(lineptr) && \valid(n); //TODO: lineptr has to refer to a pointer that has been allocated via malloc
requires \valid((*lineptr)+(0..(*n)-1));
requires file_is_open(stream);
assigns \result, *stream, *lineptr, **lineptr, *n \from lineptr, *n, delimiter, *stream;
ensures -1 <= \result <= *n;
*/
ssize_t getdelim(char **restrict lineptr, size_t *restrict n, int delimiter, FILE *restrict stream);

/*@
requires \valid(lineptr) && \valid(n);
requires \valid((*lineptr)+(0..(*n)-1));
requires file_is_open(stream);
assigns \result, *stream, *lineptr, **lineptr, *n \from lineptr, *n, *stream;
ensures -1 <= \result <= *n;
*/
ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);

/*@ //FIXME: errno behavior?
requires \valid(sizep);
requires \valid(bufp) && \valid((*bufp)+(0..((*sizep)-1)));
assigns \result \from bufp, sizep, __fc_fopen[..];
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result);
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
*/
FILE *open_memstream(char **bufp, size_t *sizep);

/*@
requires \valid(stream);
requires file_is_open(stream);
assigns *stream \from \nothing;
ensures !file_has_stream(stream);
ensures !file_has_buffer(stream); //TODO: automatic deallocation of buffer
ensures \result == 0 ==> !file_is_open(stream);
*/
int pclose(FILE *stream);

/*@ 
requires \valid(command) && \valid(mode);
//requires valid_string(command) && valid_string(mode);
//requires valid_fopen_mode(mode);
assigns \result \from command[..], mode[..], __fc_fopen[..];
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result);
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
*/
FILE *popen(const char *command, const char *mode);

/*@
requires \valid(old);
requires \valid(new);
assigns \result \from old[..], new[..];
ensures \result == 0 || \result == -1;
*/
int renameat(int oldfd, const char *old, int newfd, const char *new);

/*@
requires file_is_open(stream);
assigns *stream;
ensures file_is_open(stream);
ensures (unsigned char)\result == \result || \result == EOF;
 */
int getc_unlocked(FILE *stream);

/*@
assigns *__fc_stdin;
ensures (unsigned char)\result == \result || \result == EOF;
 */
int getchar_unlocked(void);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures \result == (unsigned char)c || \result == EOF;
*/
int putc_unlocked(int c, FILE *stream);

/*@
assigns *__fc_stdout \from c, *__fc_stdout;
ensures \result == (unsigned char)c || \result == EOF;
*/
int putchar_unlocked(int c);

/*@
requires file_is_open(stream);
assigns *stream \from \nothing;
ensures !file_error(stream);
*/
void clearerr_unlocked(FILE *stream);

/*@
requires file_is_open(stream);
assigns \result \from *stream;
ensures \result == 0 <==> !file_eof(stream);
*/
int feof_unlocked(FILE *stream);

/*@
requires file_is_open(stream);
assigns \result \from *stream;
ensures \result == 0 <==> !file_error(stream);
*/
int ferror_unlocked(FILE *stream);

/*@
requires file_is_open(stream);
assigns \result \from *stream;
*/ //TODO: ensure return is a valid FD
int fileno_unlocked(FILE *stream);

/*@
requires file_is_open(stream);
*/
int fflush_unlocked(FILE *stream);

/*@
requires file_is_open(stream);
assigns *stream;
ensures (unsigned char)\result == \result || \result == EOF;
 */
int fgetc_unlocked(FILE *stream);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures \result == (unsigned char)c || \result == EOF;
*/
int fputc_unlocked(int c, FILE *stream);

/*@
requires \valid(((char*)ptr)+(0..(nmemb*size)-1));
requires file_is_open(stream);
assigns ((char*)ptr)[0..(nmemb*size)-1] \from *stream;
ensures 0 <= \result <= (nmemb*size);
*/
size_t fread_unlocked(void *ptr, size_t size, size_t nmemb,
                             FILE *stream);

/*@
requires \valid(((char*)ptr)+(0..(nmemb*size)-1));
requires file_is_open(stream);
assigns *stream \from ((char*)ptr)[0..(nmemb*size)-1];
ensures 0 <= \result <= (nmemb*size);
*/
size_t fwrite_unlocked(const void *ptr, size_t size, size_t nmemb,
                             FILE *stream);

/*@
requires file_is_open(stream);
assigns s[0..n-1],*stream \from *stream;
assigns \result \from s,n,*stream;
ensures \result == \null || \result == s;
*/
char *fgets_unlocked(char *s, int n, FILE *stream);

/*@
requires file_is_open(stream);
requires \valid(s);
assigns *stream \from s[..];
ensures \result >= 0 || \result == EOF;
*/
int fputs_unlocked(const char *s, FILE *stream);

/* GNU Extensions */

#define L_cuserid 32

#define P_tmpdir _PATH_TMP

#define RENAME_EXCHANGE  (1 << 0)
#define RENAME_NOREPLACE (1 << 1)
#define RENAME_WHITEOUT  (1 << 2)

typedef ssize_t (*cookie_read_function_t)(void *cookie, char *buffer, size_t size);
typedef ssize_t (*cookie_write_function_t)(void *cookie, const char *buffer, size_t size);
typedef int (*cookie_seek_function_t)(void *cookie, off64_t *position, int whence);
typedef int (*cookie_close_function_t)(void *cookie);

typedef struct {
    cookie_read_function_t read;
    cookie_write_function_t write;
    cookie_seek_function_t seek;
    cookie_close_function_t close;
} cookie_io_functions_t;

extern int sys_nerr;
extern const char *const sys_errlist[];

extern int _sys_nerr;
extern const char *const _sys_errlist[];

/*@
requires \valid(filename) && \valid(mode);
assigns \result \from filename[..], mode[..], __p_fc_fopen, errno;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result);
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
ensures \result==\null || (\valid(\result) && file_is_open(\result));
*/
FILE * fopen64 (const char *filename, const char *mode);

/*@
requires \valid(filename) && \valid(mode);
//requires valid_fopen_mode(mode);
requires \valid(stream); //FIXME: needs to be a file once returned by fopen; but can be a closed file
assigns \result \from filename[..], mode[..], __fc_fopen[..], *stream;
ensures \result != \null ==> \result == stream;
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result);
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
*/
FILE * freopen64 (const char *filename, const char *mode, FILE *stream);

/*@
assigns __fc_fopen[..];
*/
int fcloseall (void);

/*@
requires file_is_open(stream);
assigns *stream \from w, *stream;
ensures \result == w;
*/
int putw (int w, FILE *stream);

/*@
requires file_is_open(stream);
assigns \result, *stream \from *stream;
 */
int getw (FILE *stream);

/*@
requires \valid(ptr);
requires \valid(format);
assigns *ptr \from format[0..];
ensures \valid(*ptr);
*/
int asprintf (char **ptr, const char *format, ...);

/*@
requires \valid(ptr);
requires \valid(format);
assigns *ptr \from format[0..];
ensures \valid(*ptr);
*/
int vasprintf (char **ptr, const char *format, va_list ap);

/*@
requires obstack_valid(op);
requires \valid(format);
assigns *op \from *op, format[0..];
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) >= \old(obstack_growing_len(op));
*/
int obstack_printf (struct obstack *op, const char *format, ...);

/*@
requires obstack_valid(op);
requires \valid(format);
assigns *op \from *op, format[0..];
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) >= \old(obstack_growing_len(op));
*/
int obstack_vprintf (struct obstack *op, const char *format, va_list ap);

/*@
requires file_is_open(stream);
assigns \result \from *stream;
*/
off64_t ftello64 (FILE *stream);

/*@
requires file_is_open(stream);
assigns *stream \from offset, whence;
*/
int fseeko64 (FILE *stream, off64_t offset, int whence);

/*@
requires \valid(pos);
requires file_is_open(stream);
assigns *pos \from *stream;
*/
int fgetpos64 (FILE *stream, fpos64_t *pos);

/*@
requires file_is_open(stream);
requires \valid(pos);
assigns *stream \from *pos;
*/
int fsetpos64 (FILE *stream, const fpos64_t *pos);

/*@
requires \valid(mode);
//requires valid_string(mode);
//requires valid_fopen_mode(mode);
assigns \result \from mode[..], io_functions, __fc_fopen[..];
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result);
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
*/
FILE * fopencookie (void *cookie, const char *mode, cookie_io_functions_t io_functions);

/*@
assigns \result \from __fc_fopen[..];
ensures \result==\null || (\valid(\result) && file_is_open(\result));
*/
FILE * tmpfile64 (void);

/*@
behavior null_argument:
    assumes s == \null;
    ensures \result == \null;
behavior pointer_argument:
    assumes s != \null;
    requires \valid(s+(0..( L_tmpnam )-1));
    assigns s[..];
    ensures \result == s || \result == \null;
complete behaviors; disjoint behaviors;
*/
char *tmpnam_r (char *s);

//@ ghost char __gt_fc_cuserid_buffer[L_cuserid];

/*@
requires s != \null ==> \valid(s+(0..( L_cuserid )-1));
behavior null_arg:
    assumes s == \null;
    assigns __gt_fc_cuserid_buffer[0..( L_cuserid )-1] \from \nothing;
    ensures \result == __gt_fc_cuserid_buffer;
behavior valid_arg:
    assumes s != \null;
    assigns s[0..( L_cuserid )-1] \from \nothing;
    ensures \result == s;
complete behaviors; disjoint behaviors;
*/
char * cuserid (char *s);

/*@
requires buf != \null ==> \valid(buf+(0..size-1));
requires file_is_open(stream);
assigns *stream, buf[..] \from buf, size;
ensures file_has_buffer(stream);
ensures buf == \null <==> file_dynamic_buffer(stream);
*/
void setbuffer (FILE *restrict stream, char *restrict buf, size_t size);

/*@
requires file_is_open(stream);
assigns *stream \from \nothing;
ensures file_has_buffer(stream);
ensures file_dynamic_buffer(stream);
*/
void setlinebuf (FILE *stream);

__END_DECLS

#define IOV_MAX 1024

#endif
