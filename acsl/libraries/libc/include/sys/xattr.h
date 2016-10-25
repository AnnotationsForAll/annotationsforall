/*
 * xattr.h
 *
 *  Created on: Jul 14, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_XATTR_H_
#define LIBC_SYS_XATTR_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_size_t.h"
#include "../__fc_define_ssize_t.h"

#include "../__fc_string_axiomatic.h"
#include "../errno.h"

#define XATTR_CREATE  1
#define XATTR_REPLACE 2

/*@
requires valid_read_string(path);
requires valid_read_string(name);
requires \valid(((char*)value)+(0..size-1));
assigns errno, \result, ((char*)value)[0..size-1];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t getxattr(const char *path, const char *name, void *value, size_t size);

/*@
requires valid_read_string(path);
requires valid_read_string(name);
requires \valid(((char*)value)+(0..size-1));
assigns errno, \result, ((char*)value)[0..size-1];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t lgetxattr(const char *path, const char *name, void *value, size_t size);

/*@
requires valid_read_string(name);
requires \valid(((char*)value)+(0..size-1));
assigns errno, \result, ((char*)value)[0..size-1];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t fgetxattr(int fd, const char *name, void *value, size_t size);

/*@
requires valid_read_string(path);
requires \valid(((char*)list)+(0..size-1));
assigns errno, \result, ((char*)list)[0..size-1];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t listxattr(const char *path, char *list, size_t size);

/*@
requires valid_read_string(path);
requires \valid(((char*)list)+(0..size-1));
assigns errno, \result, ((char*)list)[0..size-1];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t llistxattr(const char *path, char *list, size_t size);

/*@
requires \valid(((char*)list)+(0..size-1));
assigns errno, \result, ((char*)list)[0..size-1];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t flistxattr(int fd, char *list, size_t size);

/*@
requires valid_read_string(path);
requires valid_read_string(name);
assigns errno, \result;
ensures \result == -1 || \result  == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int removexattr(const char *path, const char *name);

/*@
requires valid_read_string(path);
requires valid_read_string(name);
assigns errno, \result;
ensures \result == -1 || \result  == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int lremovexattr(const char *path, const char *name);

/*@
requires valid_read_string(name);
assigns errno, \result;
ensures \result == -1 || \result  == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fremovexattr(int fd, const char *name);

/*@
requires valid_read_string(path);
requires valid_read_string(name);
requires \valid_read(((char*)value)+(0..size-1));
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setxattr(const char *path, const char *name, const void *value, size_t size, int flags);

/*@
requires valid_read_string(path);
requires valid_read_string(name);
requires \valid_read(((char*)value)+(0..size-1));
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int lsetxattr(const char *path, const char *name, const void *value, size_t size, int flags);

/*@
requires valid_read_string(name);
requires \valid_read(((char*)value)+(0..size-1));
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fsetxattr(int fd, const char *name, const void *value, size_t size, int flags);

#endif /* LIBC_SYS_XATTR_H_ */
