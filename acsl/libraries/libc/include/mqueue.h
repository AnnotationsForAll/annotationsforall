/*
 * mqueue.h
 *
 *  Created on: Jul 18, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_MQUEUE_H_
#define LIBC_MQUEUE_H_

#include "__fc_define_timespec.h"
#include "__fc_string_axiomatic.h"
#include "signal.h"
#include "sys/types.h"
#include "errno.h"

struct mq_attr {
    long mq_flags;
    long mq_maxmsg;
    long mq_msgsize;
    long mq_curmsgs;
};

typedef char* mqd_t;

/*@
assigns errno, \result, *mqdes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mq_close(mqd_t mqdes);

/*@
requires \valid(mqstat);
assigns errno, \result, *mqdes, *mqstat;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mq_getattr(mqd_t mqdes, struct mq_attr *mqstat);

/*@
requires notification != \null ==> \valid_read(notification);
assigns errno, \result, *mqdes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mq_notify(mqd_t mqdes, const struct sigevent *notification);

/*@
requires valid_read_string(name);
assigns errno, \result;
ensures \result == ((mqd_t)-1) ? errno != 0 : errno == \old(errno);
*/
mqd_t mq_open(const char *name, int oflag, ...);

/*@
requires \valid(msg_ptr+(0..msg_len-1));
requires msg_prio != \null ==> \valid(msg_prio);
assigns \result, errno, msg_ptr[0..msg_len-1], *msg_prio;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned *msg_prio);

/*@
requires \valid_read(msg_ptr+(0..msg_len-1));
assigns \result, errno, *mqdes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned msg_prio);

/*@
requires \valid_read(mqstat);
requires omqstat != \null ==> \valid(omqstat);
assigns \result, errno, *mqdes, *omqstat;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mq_setattr(mqd_t mqdes, const struct mq_attr *restrict mqstat, struct mq_attr *restrict omqstat);

/*@
requires \valid(msg_ptr+(0..msg_len-1));
requires msg_prio != \null ==> \valid(msg_prio);
requires \valid(abstime);
assigns \result, errno, *mqdes, msg_ptr[0..msg_len-1], *msg_prio;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t mq_timedreceive(mqd_t mqdes, char *restrict msg_ptr, size_t msg_len, unsigned *restrict msg_prio, const struct timespec *restrict abstime);

/*@
requires \valid_read(msg_ptr+(0..msg_len-1));
requires \valid(abstime);
assigns \result, errno, *mqdes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned msg_prio, const struct timespec *abstime);

/*@
requires valid_read_string(name);
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mq_unlink(const char *name);

#endif /* LIBC_MQUEUE_H_ */
