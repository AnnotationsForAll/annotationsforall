/*
 * mman.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#include "../__fc_define_mode_t.h"
#include "../__fc_define_off_t.h"
#include "../__fc_define_size_t.h"

#include "../__gt_fc_define_sysconf.h"
#include "../errno.h"

#ifndef LIBC_SYS_MMAN_H_
#define LIBC_SYS_MMAN_H_

#define PROT_NONE 0
#define PROT_EXEC 1
#define PROT_READ 2
#define PROT_WRITE 4

#define MAP_FIXED   (1 << 0)
#define MAP_PRIVATE (1 << 1)
#define MAP_SHARED  (1 << 2)

#define MAP_FAILED NULL

struct posix_typed_mem_info {
    size_t  posix_tmi_length;
};

/*@
assigns \result, errno \from len, prot, flags, fildes, off;
ensures ((char*)\result) != MAP_FAILED ==> \valid(((char*)\result)+(0..len-1));
*/
void *mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t off);

/*@
requires \valid(((char*)addr)+(0..len-1));
assigns \result, errno \from ((char*)addr)[0..len-1], len, prot;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mprotect(void *addr, size_t len, int prot);

/*@
requires \valid(((char*)addr)+(0..len-1));
assigns \result, errno \from ((char*)addr)[0..len-1], len;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int munmap(void *addr, size_t len);

/* GNU Exntensions */

#define MADV_NORMAL 0
#define MADV_RANDOM 1
#define MADV_SEQUENTIAL 2
#define MADV_WILLNEED 3
#define MADV_DONTNEED 4

#define POSIX_MADV_NORMAL 0
#define POSIX_MADV_RANDOM 1
#define POSIX_MADV_SEQUENTIAL 2
#define POSIX_MADV_WILLNEED 3
#define POSIX_MADV_DONTNEED 4

#define MS_SYNC 0
#define MS_ASYNC 1

#define MLOCK_ONFAULT 1

#define MCL_CURRENT 1
#define MCL_FUTURE 2
#define MCL_ONFAULT 4

#define MAP_GROWSDOWN  (1 << 3)
#define MAP_DENYWRITE  (1 << 4)
#define MAP_EXECUTABLE (1 << 5)
#define MAP_LOCKED     (1 << 6)
#define MAP_NORESERVE  (1 << 7)
#define MAP_POPULATE   (1 << 8)
#define MAP_NONBLOCK   (1 << 9)
#define MAP_STACK      (1 << 10)
#define MAP_HUGETLB    (1 << 11)
#define MAP_32BIT      (1 << 12)

/*@
assigns \result, errno \from len, prot, flags, fildes, off;
ensures ((char*)\result) != MAP_FAILED ==> \valid(((char*)\result)+(0..len-1));
*/
void *mmap64(void *addr, size_t len, int prot, int flags, int fildes, off64_t off);

/*@
requires \valid(((char*)address)+(0..length-1));
assigns \result \from ((char*)address)[0..length-1], length, flags;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int msync (void *address, size_t length, int flags);

/*@
requires \valid(((char*)address)+(0..length-1));
assigns \result, errno \from ((char*)address)[0..length-1], length, new_len, flag;
ensures ((char*)\result) != MAP_FAILED ==> \valid(((char*)\result)+(0..new_len-1));
*/
void * mremap (void *address, size_t length, size_t new_len, int flag);

/*@
requires \valid(((char*)address)+(0..length-1));
assigns \result \from ((char*)address)[0..length-1], length, advice;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int madvise (void *address, size_t length, int advice);

/*@
requires \valid(((char*)addr)+(0..len-1));
assigns \result, errno \from addr, len;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mlock (const void *addr, size_t len);

/*@
requires \valid(((char*)addr)+(0..len-1));
assigns \result, errno \from addr, len, flags;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mlock2(const void *addr, size_t len, int flags);

/*@
requires \valid(((char*)addr)+(0..len-1));
assigns \result, errno \from addr, len;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int munlock (const void *addr, size_t len);

/*@
assigns \result \from flags;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mlockall (int flags);

/*@
assigns \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int munlockall (void);

/*@
requires \valid(vec+(0..( (length+sysconf(_SC_PAGESIZE)-1)/sysconf(_SC_PAGESIZE) )-1));
assigns errno, \result, vec[0..( (length+sysconf(_SC_PAGESIZE)-1)/sysconf(_SC_PAGESIZE) )-1];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mincore(void *addr, size_t length, unsigned char *vec);

/*@
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int remap_file_pages(void *addr, size_t size, int prot, size_t pgoff, int flags);

/*@
requires \valid_read(name);
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int posix_typed_mem_open(const char *name, int oflag, int tflag);

/*@
requires \valid(info);
assigns \result, *info;
ensures \result <= 0;
*/
int posix_typed_mem_get_info(int fildes, struct posix_typed_mem_info *info);

/*@
requires \valid(off);
requires \valid(contig_len);
requires \valid(fildes);
assigns \result, *off, *contig_len, *fildes;
ensures \result <= 0;
*/
int posix_mem_offset(const void *restrict addr, size_t len, off_t *restrict off, size_t *restrict contig_len, int *restrict fildes);

/*@
assigns \result \from address, length, advice;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int posix_madvise (void *address, size_t length, int advice);

/*@
requires \valid_read(name);
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int shm_open (const char *name, int oflag, mode_t mode);

/*@
requires \valid_read(name);
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int shm_unlink (const char *name);

#endif /* LIBC_SYS_MMAN_H_ */
