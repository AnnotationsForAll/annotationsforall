/*
 * inotify.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_INOTIFY_H_
#define LIBC_SYS_INOTIFY_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"

#include "../__fc_string_axiomatic.h"
#include "../errno.h"

#define IN_CLOEXEC  (1 << 0)
#define IN_NONBLOCK (1 << 1)

#define IN_ACCESS        (1 << 0)
#define IN_MODIFY        (1 << 1)
#define IN_ATTRIB        (1 << 2)
#define IN_CLOSE_WRITE   (1 << 3)
#define IN_CLOSE_NOWRITE (1 << 4)
#define IN_OPEN          (1 << 5)
#define IN_MOVED_FROM    (1 << 6)
#define IN_MOVED_TO      (1 << 7)
#define IN_CREATE        (1 << 8)
#define IN_DELETE        (1 << 9)
#define IN_DELETE_SELF   (1 << 10)
#define IN_MOVE_SELF     (1 << 11)
#define IN_UNMOUNT       (1 << 12)
#define IN_Q_OVERFLOW    (1 << 13)
#define IN_IGNORED       (1 << 14)
#define IN_ONLYDIR       (1 << 15)
#define IN_DONT_FOLLOW   (1 << 16)
#define IN_EXCL_UNLINK   (1 << 17)
#define IN_MASK_ADD      (1 << 18)
#define IN_ISDIR         (1 << 19)
#define IN_ONESHOT       (1 << 20)

#define IN_CLOSE      (IN_CLOSE_WRITE | IN_CLOSE_NOWRITE)
#define IN_MOVE       (IN_MOVED_FROM | IN_MOVED_TO)
#define IN_ALL_EVENTS (IN_ACCESS | IN_MODIFY | IN_ATTRIB | IN_CLOSE_WRITE | IN_CLOSE_NOWRITE | IN_OPEN | IN_MOVED_FROM | IN_MOVED_TO | IN_CREATE | IN_DELETE | IN_DELETE_SELF | IN_MOVE_SELF)

struct inotify_event {
    int wd;
    uint32_t mask;
    uint32_t cookie;
    uint32_t len;
    char name[];
};

/*@
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int inotify_init(void);

/*@
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int inotify_init1(int flags);

/*@
requires valid_read_string(name);
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int inotify_add_watch(int fd, const char *name, uint32_t mask);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int inotify_rm_watch(int fd, int wd);

#endif /* LIBC_SYS_INOTIFY_H_ */
