/*
 * fanotify.h
 *
 *  Created on: Jul 14, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_FANOTIFY_H_
#define LIBC_SYS_FANOTIFY_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"

#include "../errno.h"

/*
TODO: Some of this might be public, kernel-independent interface, and some might be kernel-dependent.
The kernel-dependent bits need to be enumerated, sorted out, and made machdep-specific.
*/

#define FAN_CLASS_PRE_CONTENT (1 << 0)
#define FAN_CLASS_CONTENT     (1 << 1)
#define FAN_CLASS_NOTIF       (1 << 2)
#define FAN_CLOEXEC           (1 << 3)
#define FAN_NONBLOCK          (1 << 4)
#define FAN_UNLIMITED_QUEUE   (1 << 5)
#define FAN_UNLIMITED_MARKS   (1 << 6)

#define FAN_MARK_ADD                 (1 << 0)
#define FAN_MARK_REMOVE              (1 << 1)
#define FAN_MARK_FLUSH               (1 << 2)
#define FAN_MARK_DONT_FOLLOW         (1 << 3)
#define FAN_MARK_ONLYDIR             (1 << 4)
#define FAN_MARK_MOUNT               (1 << 5)
#define FAN_MARK_IGNORED_MASK        (1 << 6)
#define FAN_MARK_IGNORED_SURV_MODIFY (1 << 7)
#define FAN_ACCESS                   (1 << 8)
#define FAN_MODIFY                   (1 << 9)
#define FAN_CLOSE_WRITE              (1 << 10)
#define FAN_CLOSE_NOWRITE            (1 << 11)
#define FAN_OPEN                     (1 << 12)
#define FAN_OPEN_PERM                (1 << 13)
#define FAN_ACCESS_PERM              (1 << 14)
#define FAN_ONDIR                    (1 << 15)
#define FAN_EVENT_ON_CHILD           (1 << 16)

#define FAN_CLOSE (FAN_CLOSE_WRITE|FAN_CLOSE_NOWRITE)

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fanotify_init(unsigned int flags, unsigned int event_f_flags);

/*@
requires valid_read_string_or_null(pathname);
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fanotify_mark(int fanotify_fd, unsigned int flags, uint64_t mask, int dirfd, const char *pathname);

#endif /* LIBC_SYS_FANOTIFY_H_ */
