/*
 * poll.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_POLL_H_
#define LIBC_POLL_H_

#include "errno.h"
#include "__fc_define_timespec.h"
#include "__fc_define_sigset_t.h"

typedef struct pollfd {
    int fd;
    short events;
    short revents;
} pollfd;

typedef unsigned int nfds_t;

#define POLLIN     (1 << 0)
#define POLLRDNORM (1 << 1)
#define POLLRDBAND (1 << 2)
#define POLLPRI    (1 << 3)
#define POLLOUT    (1 << 4)
#define POLLWRNORM (1 << 5)
#define POLLWRBAND (1 << 6)
#define POLLERR    (1 << 7)
#define POLLHUP    (1 << 8)
#define POLLNVAL   (1 << 9)
#define POLLMSG    (1 << 10)
#define POLLMSG    (1 << 11)
#define POLLREMOVE (1 << 12)
#define POLLRDHUP  (1 << 13)

/*@
requires \valid(fds+(0..nfds-1));
assigns \result, errno \from fds[0..nfds-1], nfds, timeout;
ensures -1 <= \result <= nfds;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int poll(struct pollfd *fds, nfds_t nfds, int timeout);

/*@
requires \valid(fds+(0..nfds-1));
requires tmo_p != \null ==> \valid_read(tmo_p);
requires sigmask != \null ==> \valid_read(sigmask);
assigns \result, errno \from fds[0..nfds-1], nfds, *tmo_p, *sigmask;
ensures -1 <= \result <= nfds;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *tmo_p, const sigset_t *sigmask);

#endif /* LIBC_POLL_H_ */
