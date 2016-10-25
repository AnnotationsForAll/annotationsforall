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

#ifndef __FC_UNISTD
#define __FC_UNISTD

#include "__fc_string_axiomatic.h"
#include "__fc_define_size_t.h"
#include "__fc_define_null.h"
#include "__fc_define_ssize_t.h"
#include "__fc_define_uid_and_gid.h"
#include "__fc_define_off_t.h"
#include "__fc_define_pid_t.h"
#include "__fc_define_useconds_t.h"
#include "__fc_define_intptr_t.h"
#include "__fc_define_useconds_t.h"
#include "__fc_select.h"
#include "__gt_fc_define_sysconf.h"
#include "__fc_define_seek_macros.h"
#include "__gt_fc_fcntl_macros.h"
#include "__gt_fc_define_ctermid.h"
#include "features.h"
#include "getopt.h"
#include "crypt.h"
#include "limits.h"
#include "sys/sysinfo.h"
#include "sys/acct.h"

/* Standard file descriptors.  */
#define STDIN_FILENO    0   /* Standard input.  */
#define STDOUT_FILENO   1   /* Standard output.  */
#define STDERR_FILENO   2   /* Standard error output.  */

#include "__fc_define_seek_macros.h"

__BEGIN_DECLS

#include "errno.h"

// arbitrary number
#define __FC_MAX_OPEN_FILES 1024

// __fc_fds represents the state of open file descriptors.
//@ ghost int __fc_fds[__FC_MAX_OPEN_FILES];
// TODO: Model the state of some functions more precisely.
// TODO: define __fc_fds as volatile.


/*@
requires \valid(path);
assigns \result, errno \from path[..], amode;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int access(const char *path, int amode);

/*@
requires \valid(path);
assigns \result, errno \from path[..], amode, fd, flag;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int faccessat(int fd, const char *path, int amode, int flag);

/*@
assigns \result \from seconds;
*/
unsigned alarm(unsigned seconds);

/*@
requires \valid(path);
assigns \result, errno \from path[..], owner, group;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int chown(const char *path, uid_t owner, gid_t group);

/*@
requires \valid(path);
assigns \result, errno \from path[..], owner, group, fd, flag;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fchownat(int fd, const char *path, uid_t owner, gid_t group, int flag);

/*@
requires 0 <= fd < __FC_MAX_OPEN_FILES;
assigns errno, \result, __fc_fds[fd] \from fd, __fc_fds[fd];
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int close(int fd);

/*@
assigns \result, errno \from fildes;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int dup(int fildes);

/*@
assigns \result, errno \from fildes, fildes2;
ensures \result == -1 || \result == fildes2;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int dup2(int fildes, int fildes2);

/*@
ensures \false;
exits \exit_status == status;
*/
void _exit(int status);

/*@
requires arg != \null;
requires valid_read_string(path);
requires valid_read_string(arg);
assigns \result, errno \from path[0..], arg[0..];
ensures \result == -1;
ensures errno != 0;
*/
int execl(const char *path, const char *arg, ...);

/*@
requires arg != \null;
requires valid_read_string(path);
requires valid_read_string(arg);
assigns \result, errno \from path[0..], arg[0..];
ensures \result == -1;
ensures errno != 0;
*/
int execle(const char *path, const char *arg, ...);

/*@
requires arg != \null;
requires valid_read_string(path);
requires valid_read_string(arg);
assigns \result, errno \from path[0..], arg[0..];
ensures \result == -1;
ensures errno != 0;
*/
int execlp(const char *path, const char *arg, ...);

/*@
requires argv[0] != \null;
requires valid_read_string(path);
requires valid_read_string(argv[0]);
assigns \result, errno \from path[0..], argv[0..];
ensures \result == -1;
ensures errno != 0;
*/
int execv(const char *path, char * const argv[]);

/*@
requires argv[0] != \null;
requires valid_read_string(path);
requires valid_read_string(argv[0]);
assigns \result, errno \from path[0..], argv[0..];
ensures \result == -1;
ensures errno != 0;
*/
int execve(const char *path, char * const argv[], char * const env[]);

/*@
assigns \result, errno \from fd;
ensures \result == -1;
ensures errno != 0;
*/
int fexecve(int fd, char *const argv[], char *const envp[]);

/*@ requires argv[0] != \null;
    requires valid_read_string(path);
    requires valid_read_string(argv[0]);
    assigns \result \from path[0..], argv[0..];
*/
int execvp(const char *path, char * const argv[]);

/*@
assigns \result \from \nothing;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fchdir(int fildes);

/*@
assigns \result \from fildes, owner, group;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fchown(int fildes, uid_t owner, gid_t group);

/*@
assigns \result, errno \from \nothing;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
pid_t fork(void);

/*@
assigns \result, errno \from fildes, length;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ftruncate(int fildes, off_t length);

/*@
requires \valid(buf+(0..size-1));
assigns \result, buf[0..size-1], errno \from size;
ensures \result == \null || \result == buf;
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char *getcwd(char *buf, size_t size);

/*@
assigns \result \from \nothing;
*/
gid_t getegid(void);

/*@
assigns \result \from \nothing;
*/
uid_t geteuid(void);

/*@
assigns \result \from \nothing;
*/
gid_t getgid(void);

/*@
requires \valid(grouplist+(0..gidsetsize-1));
assigns \result, grouplist[0..gidsetsize-1], errno \from gidsetsize;
ensures -1 <= \result <= gidsetsize;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getgroups(int gidsetsize, gid_t *grouplist);

/*@
assigns \result \from \nothing;
*/
long gethostid(void);

/*@
requires \valid(name+(0..namelen-1));
assigns \result, name[0..namelen-1], errno \from namelen;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int gethostname(char *name, size_t namelen);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
char *getlogin(void);
int getlogin_r(char *name, size_t namesize);

/*@
assigns \result \from \nothing;
*/
pid_t getpgid(pid_t pid);

/*@
assigns \result \from \nothing;
*/
pid_t getpgrp(void);

/*@
assigns \result \from \nothing;
*/
pid_t getpid(void);

/*@
assigns \result \from \nothing;
*/
pid_t getppid(void);

/*@
assigns \result \from \nothing;
*/
pid_t getsid(pid_t pid);

/*@
assigns \result \from \nothing;
*/
uid_t getuid(void);

/*@
ensures \result == 1 || \result == 0;
*/
int isatty(int fildes);

/*@
requires \valid(path);
assigns \result, errno \from path[..], owner, group;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int lchown(const char *path, uid_t owner, gid_t group);

/*@
requires \valid(path1) && \valid(path2);
assigns \result \from path1[..], path2[..];
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int link(const char *path1, const char *path2);

/*@
requires \valid(path1) && \valid(path2);
assigns \result \from path1[..], path2[..], fd1, fd2, flag;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int linkat(int fd1, const char *path1, int fd2, const char *path2, int flag);

/*@
assigns \result, errno \from fildes, offset, whence;
*/
off_t lseek(int fildes, off_t offset, int whence);

/*@
assigns \result, errno \from incr;
ensures -1 <= \result <= sysconf(_SC_NZERO)-1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int nice(int incr);

/*@
assigns \result, errno \from \nothing;
ensures \result == -1;
ensures errno == EINTR;
*/
int pause(void);

/*@
requires \valid(fildes+(0..1));
assigns \result, fildes[0..1], errno \from \nothing;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int pipe(int fildes[2]);

/*@
requires \valid(((char*)buf)+(0..nbyte-1));
assigns \result, ((char*)buf)[0..nbyte-1], errno \from fildes, nbyte, offset;
ensures -1 <= \result <= nbyte;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t pread(int fildes, void *buf, size_t nbyte, off_t offset);

/*@
requires 0 <= fd < __FC_MAX_OPEN_FILES;
requires \valid(((char*)buf)+(0..count-1));
assigns \result, *((char *)buf+(0..count-1)), __fc_fds[fd]
        \from __fc_fds[fd], count;
ensures -1 <= \result <= count;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
ensures  \initialized(((char*)buf)+(0..\result-1));
*/
ssize_t read(int fd, void *buf, size_t count);

/*@
requires \valid(path);
requires \valid(buf+(0..bufsize-1));
assigns \result, buf[0..bufsize-1], errno \from path[..], bufsize;
ensures -1 <= \result <= bufsize;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize);

/*@
requires \valid(path);
requires \valid(buf+(0..bufsize-1));
assigns \result, buf[0..bufsize-1], errno \from path[..], bufsize, fd;
ensures -1 <= \result <= bufsize;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t readlinkat(int fd, const char *restrict path, char *restrict buf, size_t bufsize);

/*@
requires \valid(path);
assigns \result, errno \from path[..];
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int rmdir(const char *path);

/*@
assigns \result \from gid;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setegid(gid_t gid);

/*@
assigns \result \from uid;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int seteuid(uid_t uid);

/*@
assigns \result \from gid;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setgid(gid_t gid);

/*@
assigns \result \from pid, pgid;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setpgid(pid_t pid, pid_t pgid);

/*@
assigns \result \from \nothing;
*/
pid_t setpgrp(void);

/*@
assigns \result \from rgid, egid;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setregid(gid_t rgid, gid_t egid);

/*@
assigns \result \from ruid, euid;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setreuid(uid_t ruid, uid_t euid);

/*@
assigns \result \from \nothing;
*/
pid_t setsid(void);

/*@
assigns \result \from uid;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setuid(uid_t uid);

/*@
assigns \result \from seconds;
ensures 0 <= \result <= seconds;
*/
unsigned sleep(unsigned seconds);

/*@
requires \valid(((char*)src)+(0..nbytes-1)) && \valid(((char*)dest)+(0..nbytes-1));
assigns ((char*)dest)[0..nbytes-1] \from ((char*)src)[0..nbytes-1];
*/
void swab(const void *restrict src, void *restrict dest, ssize_t nbytes);

/*@
requires \valid(path1) && \valid(path2);
assigns \result, errno \from path1[..], path2[..];
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int symlink(const char *path1, const char *path2);

/*@
requires \valid(path1) && \valid(path2);
assigns \result, errno \from path1[..], path2[..], fd;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int symlinkat(const char *path1, int fd, const char *path2);

/*@
assigns \nothing;
*/
void sync(void);

/*@
assigns \result, errno \from fildes;
*/
pid_t tcgetpgrp(int fildes);

/*@
assigns \result, errno \from fildes, pgid_id;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int tcsetpgrp(int fildes, pid_t pgid_id);

/*@
requires \valid(path);
assigns \result, errno \from path[..], length;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int truncate(const char *path, off_t length);

/*@
assigns \result \from fildes;
ensures \result != \null ==> \valid(\result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char *ttyname(int fildes);
int ttyname_r(int fildes, char *name, size_t namesize);

/*@
requires \valid(path);
assigns \result \from path[..];
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int unlink(const char *path);

/*@
requires \valid(path);
assigns \result \from path[..], fd, flag;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int unlinkat(int fd, const char *path, int flag);

/*@
requires \valid(((char*)buf)+(0..nbyte-1));
assigns \result, errno \from ((char*)buf)[0..nbyte-1], fildes, nbyte, offset;
ensures -1 <= \result <= nbyte;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t pwrite(int fildes, const void *buf, size_t nbyte, off_t offset);

/*@
requires 0 <= fd < __FC_MAX_OPEN_FILES;
requires \valid_read(((char *)buf)+(0..count-1));

assigns errno, \result, __fc_fds[fd] \from fd, count, __fc_fds[fd];
ensures -1 <= \result <= count;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t write(int fd, const void *buf, size_t count);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fsync(int fd);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fdatasync(int fd);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int syncfs(int fd);

/* GNU Extensions */

#define TEMP_FAILURE_RETRY(expression)                                              \
        (                                                                           \
          ({ long int __result;                                                     \
             do __result = (long int) (expression);                                 \
             while (__result == -1L && errno == EINTR);                             \
             __result; }))

extern char ** environ;

/*@
requires \valid(((char*)buf)+(0..nbyte-1));
assigns \result, ((char*)buf)[0..nbyte-1], errno \from fildes, nbyte, offset;
ensures -1 <= \result <= nbyte;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t pread64(int fildes, void *buf, size_t nbyte, off64_t offset);

/*@
requires \valid(((char*)buf)+(0..nbyte-1));
assigns \result, errno \from ((char*)buf)[0..nbyte-1], fildes, nbyte, offset;
ensures -1 <= \result <= nbyte;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t pwrite64(int fildes, const void *buf, size_t nbyte, off64_t offset);

/*@
requires \valid(buf+(0..( PATH_MAX )-1));
assigns \result, buf[0..( PATH_MAX )-1], errno \from buf;
ensures \result == \null || \result == buf;
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char * getwd(char *buf);

/*@
assigns \result, errno;
ensures \result == \null || \valid(\result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char * get_current_dir_name(void);

/*@
requires \valid(path);
assigns \result \from path[0..];
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int chdir(const char *path);

/*@
requires \valid(path);
assigns \result, errno \from path[..], length;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int truncate64(const char *path, off64_t length);

/*@
assigns \result, errno \from fildes, length;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ftruncate64(int fildes, off64_t length);

/*@
assigns \result, errno \from \nothing;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
pid_t vfork (void);

/*@
requires \valid((char*)addr);
assigns \result, errno \from addr;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int brk (void *addr);

/*@
assigns \result, errno \from delta;
ensures \result != ((void*)-1) ==> \valid(((char*)\result)+(0..delta));
ensures \result == ((void*)-1) ? errno != 0 : errno == \old(errno);
*/
void *sbrk (ptrdiff_t delta);

/*@
assigns \result;
ensures \result > 0;
*/
int getpagesize (void);

// syscall can assign everything, so leave it unannotated
long int syscall (long int sysno, ...);

/*@
requires \valid(prompt);
assigns \result, errno;
ensures \result != \null ==> valid_string(\result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char * getpass (const char *prompt);

/*@
requires \valid_read(path);
assigns \result, errno;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int chroot(const char *path);

/*@
assigns \result, errno;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int dup3(int oldfd, int newfd, int flags);

/*@
requires \valid(name+(0..len-1));
assigns errno, \result, name[0..len-1];
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getdomainname(char *name, size_t len);

/*@
requires \valid_read(name+(0..len-1));
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setdomainname(const char *name, size_t len);

/*@
assigns \result;
ensures \result >= 20;
ensures \result == sysconf(_SC_OPEN_MAX);
*/
int getdtablesize(void);

/*@
requires \valid(ruid);
requires \valid(euid);
requires \valid(suid);
assigns \result, *ruid, *euid, *suid;
ensures \result == 0;
*/
int getresuid(uid_t *ruid, uid_t *euid, uid_t *suid);

/*@
requires \valid(rgid);
requires \valid(egid);
requires \valid(sgid);
assigns \result, *rgid, *egid, *sgid;
ensures \result == 0;
*/
int getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int vhangup(void);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int daemon(int nochdir, int noclose);

/*@
requires \valid_read(pathname);
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int euidaccess(const char *pathname, int mode);

/*@
requires \valid_read(pathname);
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int eaccess(const char *pathname, int mode);

/*@
assigns \result;
ensures \result != \null ==> \valid(\result);
*/
char *getusershell(void);

/*@
assigns \nothing;
*/
void setusershell(void);

/*@
assigns \nothing;
*/
void endusershell(void);

/*@
assigns \result;
*/
int group_member(gid_t gid);

/*@
requires argv[0] != \null;
requires valid_read_string(path);
requires valid_read_string(argv[0]);
requires valid_read_string(envp[0]);
assigns \result, errno \from path[0..], argv[0..], envp[0..];
ensures \result == -1;
ensures errno != 0;
*/
int execvpe(const char *path, char * const argv[], char * const envp[]);

/*@
assigns \result, errno \from fildes, offset, whence;
*/
off64_t lseek64(int fildes, off64_t offset, int whence);

/*@
requires \valid(fildes+(0..1));
assigns \result, fildes[0..1], errno;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int pipe2(int fildes[2], int flags);

/*@
requires \valid(sample_buffer+(0..size-1));
assigns \result, sample_buffer[0..size-1];
ensures \result == 0;
*/
int profil(unsigned short int *sample_buffer, size_t size, size_t offset, unsigned int scale);

/*@
requires \valid_read(file);
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int revoke(const char *file);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sethostid(long int id);

/*@
requires \valid_read(name+(0..len-1));
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sethostname (const char *name, size_t len);

/*@
requires \valid_read(name);
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setlogin (const char *name);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setresuid (uid_t ruid, uid_t euid, uid_t suid);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setresgid (gid_t rgid, gid_t egid, gid_t sgid);

/*@
assigns \result;
*/
useconds_t ualarm (useconds_t value, useconds_t interval);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int usleep (useconds_t useconds);

__END_DECLS

#endif
