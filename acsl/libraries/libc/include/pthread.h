/*
 * pthread.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_PTHREAD_H_
#define LIBC_PTHREAD_H_

// Disallow parralellism
#error "Frama-C: unsupported pthread.h"

#include "sys/types.h"
#include "sched.h"
#include "time.h"

#define PTHREAD_BARRIER_SERIAL_THREAD 0
#define PTHREAD_CANCEL_ASYNCHRONOUS 1
#define PTHREAD_CANCEL_ENABLE 2
#define PTHREAD_CANCEL_DEFERRED 3
#define PTHREAD_CANCEL_DISABLE 4
#define PTHREAD_CANCELED 5
#define PTHREAD_CREATE_DETACHED 6
#define PTHREAD_CREATE_JOINABLE 7
#define PTHREAD_MUTEX_DEFAULT 8
#define PTHREAD_MUTEX_ERRORCHECK 9
#define PTHREAD_MUTEX_NORMAL 10
#define PTHREAD_MUTEX_RECURSIVE 11
#define PTHREAD_MUTEX_ROBUST 12
#define PTHREAD_MUTEX_STALLED 13
#define PTHREAD_ONCE_INIT 14
#define PTHREAD_PROCESS_SHARED 15
#define PTHREAD_PROCESS_PRIVATE 16

/*@
assigns \result;
ensures \valid(\result);
*/
extern pthread_cond_t __gt_fc_new_pthread_cond();

/*@
assigns \result;
ensures \valid(\result);
*/
extern pthread_mutex_t __gt_fc_new_pthread_mutex();

/*@
assigns \result;
ensures \valid(\result);
*/
extern pthread_rwlock_t __gt_fc_new_pthread_rwlock();

#define PTHREAD_COND_INITIALIZER (__gt_fc_new_pthread_cond())
#define PTHREAD_MUTEX_INITIALIZER (__gt_fc_new_pthread_mutex())
#define PTHREAD_RWLOCK_INITIALIZER (__gt_fc_new_pthread_rwlock())

int   pthread_atfork(void (*)(void), void (*)(void),
          void(*)(void));
int   pthread_attr_destroy(pthread_attr_t *);
int   pthread_attr_getdetachstate(const pthread_attr_t *, int *);
int   pthread_attr_getguardsize(const pthread_attr_t *restrict,
          size_t *restrict);
int   pthread_attr_getschedparam(const pthread_attr_t *restrict,
          struct sched_param *restrict);
int   pthread_attr_init(pthread_attr_t *);
int   pthread_attr_setdetachstate(pthread_attr_t *, int);
int   pthread_attr_setguardsize(pthread_attr_t *, size_t);
int   pthread_barrier_destroy(pthread_barrier_t *);
int   pthread_barrier_init(pthread_barrier_t *restrict,
          const pthread_barrierattr_t *restrict, unsigned);
int   pthread_barrier_wait(pthread_barrier_t *);
int   pthread_barrierattr_destroy(pthread_barrierattr_t *);
int   pthread_barrierattr_init(pthread_barrierattr_t *);
int   pthread_cancel(pthread_t);
void  pthread_cleanup_pop(int);
void  pthread_cleanup_push(void (*)(void*), void *);
int   pthread_cond_broadcast(pthread_cond_t *);
int   pthread_cond_destroy(pthread_cond_t *);
int   pthread_cond_init(pthread_cond_t *restrict,
          const pthread_condattr_t *restrict);
int   pthread_cond_signal(pthread_cond_t *);
int   pthread_cond_timedwait(pthread_cond_t *restrict,
          pthread_mutex_t *restrict, const struct timespec *restrict);
int   pthread_cond_wait(pthread_cond_t *restrict,
          pthread_mutex_t *restrict);
int   pthread_condattr_destroy(pthread_condattr_t *);
int   pthread_condattr_getclock(const pthread_condattr_t *restrict,
          clockid_t *restrict);
int   pthread_condattr_init(pthread_condattr_t *);
int   pthread_condattr_setclock(pthread_condattr_t *, clockid_t);
int   pthread_create(pthread_t *restrict, const pthread_attr_t *restrict,
          void *(*)(void*), void *restrict);
int   pthread_detach(pthread_t);
int   pthread_equal(pthread_t, pthread_t);
void  pthread_exit(void *);
void *pthread_getspecific(pthread_key_t);
int   pthread_join(pthread_t, void **);
int   pthread_key_create(pthread_key_t *, void (*)(void*));
int   pthread_key_delete(pthread_key_t);
int   pthread_mutex_consistent(pthread_mutex_t *);
int   pthread_mutex_destroy(pthread_mutex_t *);
int   pthread_mutex_init(pthread_mutex_t *restrict,
          const pthread_mutexattr_t *restrict);
int   pthread_mutex_lock(pthread_mutex_t *);
int   pthread_mutex_timedlock(pthread_mutex_t *restrict,
          const struct timespec *restrict);
int   pthread_mutex_trylock(pthread_mutex_t *);
int   pthread_mutex_unlock(pthread_mutex_t *);
int   pthread_mutexattr_destroy(pthread_mutexattr_t *);
int   pthread_mutexattr_getrobust(const pthread_mutexattr_t *restrict,
          int *restrict);
int   pthread_mutexattr_gettype(const pthread_mutexattr_t *restrict,
          int *restrict);
int   pthread_mutexattr_init(pthread_mutexattr_t *);
int   pthread_mutexattr_setrobust(pthread_mutexattr_t *, int);
int   pthread_mutexattr_settype(pthread_mutexattr_t *, int);
int   pthread_once(pthread_once_t *, void (*)(void));
int   pthread_rwlock_destroy(pthread_rwlock_t *);
int   pthread_rwlock_init(pthread_rwlock_t *restrict,
          const pthread_rwlockattr_t *restrict);
int   pthread_rwlock_rdlock(pthread_rwlock_t *);
int   pthread_rwlock_timedrdlock(pthread_rwlock_t *restrict,
          const struct timespec *restrict);
int   pthread_rwlock_timedwrlock(pthread_rwlock_t *restrict,
          const struct timespec *restrict);
int   pthread_rwlock_tryrdlock(pthread_rwlock_t *);
int   pthread_rwlock_trywrlock(pthread_rwlock_t *);
int   pthread_rwlock_unlock(pthread_rwlock_t *);
int   pthread_rwlock_wrlock(pthread_rwlock_t *);
int   pthread_rwlockattr_destroy(pthread_rwlockattr_t *);
int   pthread_rwlockattr_init(pthread_rwlockattr_t *);
pthread_t
      pthread_self(void);
int   pthread_setcancelstate(int, int *);
int   pthread_setcanceltype(int, int *);
int   pthread_setspecific(pthread_key_t, const void *);
int   pthread_spin_destroy(pthread_spinlock_t *);
int   pthread_spin_init(pthread_spinlock_t *, int);
int   pthread_spin_lock(pthread_spinlock_t *);
int   pthread_spin_trylock(pthread_spinlock_t *);
int   pthread_spin_unlock(pthread_spinlock_t *);
void  pthread_testcancel(void);

#endif /* LIBC_PTHREAD_H_ */
