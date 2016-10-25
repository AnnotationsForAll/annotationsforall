/*
 * semaphore.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SEMAPHORE_H_
#define LIBC_SEMAPHORE_H_

#include "time.h"
#include "errno.h"

typedef struct sem_t {
    char dummy;
} sem_t;

/*@
axiomatic IsSemOpen {
    logic boolean sem_is_open{L}(sem_t* sem) reads *sem;
}
*/

#define SEM_FAILED ((sem_t*)0)

/*@
requires sem_is_open(sem);
assigns \result, *sem, errno \from *sem;
ensures \result == -1 || \result == 0;
ensures \result != -1 ==> !sem_is_open(sem);
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sem_close(sem_t *sem);

/*@
requires sem_is_open(sem);
assigns \result, *sem, errno \from *sem;
ensures !sem_is_open(sem);
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sem_destroy(sem_t *sem);

/*@
requires sem_is_open(sem);
requires \valid(sval);
assigns \result, *sem, *sval, errno \from *sem;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
ensures \result != -1 ==> *sval <= 0;
*/
int sem_getvalue(sem_t *restrict sem, int *restrict sval);

/*@
requires sem_is_open(sem);
assigns \result, *sem, errno \from *sem, pshared, value;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sem_init(sem_t *sem, int pshared, unsigned value);

/*@
requires \valid(name);
assigns \result, errno \from name[..], oflag;
ensures \result != SEM_FAILED ==> \valid(\result);
ensures \result != SEM_FAILED ==> sem_is_open(\result);
*/
sem_t *sem_open(const char *name, int oflag, ...);

/*@
requires sem_is_open(sem);
assigns \result, *sem, errno \from *sem;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sem_post(sem_t *sem);

/*@
requires sem_is_open(sem);
requires \valid(abstime);
assigns \result, *sem, errno \from *sem, *abstime;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sem_timedwait(sem_t *restrict sem, const struct timespec *restrict abstime);

/*@
requires sem_is_open(sem);
assigns \result, *sem, errno \from *sem;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sem_trywait(sem_t *sem);

/*@
requires sem_is_open(sem);
assigns \result, *sem, errno \from *sem;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sem_wait(sem_t *sem);

/*@
requires \valid(name);
assigns \result, errno \from name[..];
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sem_unlink(const char *name);

#endif /* LIBC_SEMAPHORE_H_ */
