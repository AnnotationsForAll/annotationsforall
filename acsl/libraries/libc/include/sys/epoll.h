/*
 * epoll.h
 *
 *  Created on: Jul 14, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_EPOLL_H_
#define LIBC_SYS_EPOLL_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_sigset_t.h"

#include "../errno.h";

#define EPOLL_CLOEXEC 1

#define EPOLLIN      (1 << 0)
#define EPOLLPRI     (1 << 1)
#define EPOLLOUT     (1 << 2)
#define EPOLLRDNORM  (1 << 3)
#define EPOLLRDBAND  (1 << 4)
#define EPOLLWRNORM  (1 << 5)
#define EPOLLWRBAND  (1 << 6)
#define EPOLLMSG     (1 << 7)
#define EPOLLERR     (1 << 8)
#define EPOLLHUP     (1 << 9)
#define EPOLLRDHUP   (1 << 10)
#define EPOLLWAKEUP  (1 << 11)
#define EPOLLONESHOT (1 << 12)
#define EPOLLET      (1 << 13)

#define EPOLL_CTL_ADD 1
#define EPOLL_CTL_DEL 2
#define EPOLL_CTL_MOD 3

typedef union epoll_data {
    void *ptr;
    int fd;
    uint32_t u32;
    uint64_t u64;
} epoll_data_t;

struct epoll_event {
    uint32_t events;
    epoll_data_t data;
};

/*@
assigns \result;
ensures \result >= -1;
ensures size > 0 ==> \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int epoll_create(int size);

/*@
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int epoll_create1(int flags);

/*@
requires EPOLL_CTL_ADD <= op <= EPOLL_CTL_MOD;
requires op != EPOLL_CTL_DEL ==> \valid(event);
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

/*@
requires \valid(events+(0..maxevents-1));
assigns errno, \result, events[0..maxevents-1];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);

/*@
requires \valid(events+(0..maxevents-1));
requires sigmask != \null ==> \valid(sigmask);
assigns errno, \result, events[0..maxevents-1];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int epoll_pwait(int epfd, struct epoll_event *events, int maxevents, int timeout, const sigset_t *sigmask);

#endif /* LIBC_SYS_EPOLL_H_ */
