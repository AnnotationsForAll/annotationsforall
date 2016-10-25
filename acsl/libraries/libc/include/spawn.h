/*
 * spawn.h
 *
 *  Created on: Jul 18, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SPAWN_H_
#define LIBC_SPAWN_H_

#include "__fc_define_mode_t.h"
#include "__fc_define_pid_t.h"
#include "__fc_define_sigset_t.h"
#include "sched.h"

#define POSIX_SPAWN_RESETIDS      (1 << 0)
#define POSIX_SPAWN_SETPGROUP     (1 << 1)
#define POSIX_SPAWN_SETSCHEDPARAM (1 << 2)
#define POSIX_SPAWN_SETSCHEDULER  (1 << 3)
#define POSIX_SPAWN_SETSIGDEF     (1 << 4)
#define POSIX_SPAWN_SETSIGMASK    (1 << 5)
#define POSIX_SPAWN_USEVFORK      (1 << 6)

typedef void* posix_spawnattr_t;
typedef void* posix_spawn_file_actions_t;

int posix_spawn(pid_t *restrict, const char *restrict, const posix_spawn_file_actions_t *, const posix_spawnattr_t *restrict, char * const,
char *const [restrict]);
int posix_spawn_file_actions_addclose(posix_spawn_file_actions_t *, int);
int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *, int, int);
int posix_spawn_file_actions_addopen(posix_spawn_file_actions_t *restrict, int, const char *restrict, int, mode_t);
int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *);
int posix_spawn_file_actions_init(posix_spawn_file_actions_t *);
int posix_spawnattr_destroy(posix_spawnattr_t *);
int posix_spawnattr_getflags(const posix_spawnattr_t *restrict, short *restrict);
int posix_spawnattr_getpgroup(const posix_spawnattr_t *restrict, pid_t *restrict);
int posix_spawnattr_getschedparam(const posix_spawnattr_t *restrict, struct sched_param *restrict);
int posix_spawnattr_getschedpolicy(const posix_spawnattr_t *restrict, int *restrict);
int posix_spawnattr_getsigdefault(const posix_spawnattr_t *restrict, sigset_t *restrict);
int posix_spawnattr_getsigmask(const posix_spawnattr_t *restrict, sigset_t *restrict);
int posix_spawnattr_init(posix_spawnattr_t *);
int posix_spawnattr_setflags(posix_spawnattr_t *, short);
int posix_spawnattr_setpgroup(posix_spawnattr_t *, pid_t);
int posix_spawnattr_setschedparam(posix_spawnattr_t *restrict, const struct sched_param *restrict);
int posix_spawnattr_setschedpolicy(posix_spawnattr_t *, int);
int posix_spawnattr_setsigdefault(posix_spawnattr_t *restrict, const sigset_t *restrict);
int posix_spawnattr_setsigmask(posix_spawnattr_t *restrict, const sigset_t *restrict);
int posix_spawnp(pid_t *restrict, const char *restrict, const posix_spawn_file_actions_t *, const posix_spawnattr_t *restrict, char * const, char *const);

#endif /* LIBC_SPAWN_H_ */
