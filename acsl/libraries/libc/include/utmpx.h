/*
 * utmpx.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_UTMPX_H_
#define LIBC_UTMPX_H_

#include "__fc_define_pid_t.h"
#include "__fc_define_timeval.h"
#include "__gt_fc_define_alternative_types.h"
#include "sys/time.h"
#include "paths.h"

struct utmpx {
    char* ut_user;
    char* ut_id;
    char* ut_line;
    pid_t ut_pid;
    short ut_type;
    struct timeval ut_tv;
};

#define EMPTY 0
#define BOOT_TIME 1
#define OLD_TIME 2
#define NEW_TIME 3
#define USER_PROCESS 4
#define INIT_PROCESS 5
#define LOGIN_PROCESS 6
#define DEAD_PROCESS 7
#define RUN_LVL 8
#define ACCOUNTING 9

/*@
assigns \nothing;
*/
void endutxent(void);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
struct utmpx *getutxent(void);

/*@
requires \valid(id);
assigns \result \from *id;
ensures \result != \null ==> \valid(\result);
*/
struct utmpx *getutxid(const struct utmpx *id);

/*@
requires \valid(line);
assigns \result \from *line;
ensures \result != \null ==> \valid(\result);
*/
struct utmpx *getutxline(const struct utmpx *line);

/*@
requires \valid(utmpx);
assigns \result \from *utmpx;
ensures \result != \null ==> \valid(\result);
*/
struct utmpx *pututxline(const struct utmpx *utmpx);

/*@
assigns \nothing;
*/
void setutxent(void);

/* GNU Extensions */

#define UTMPX_FILE _PATH_UTMPX
#define UTMPX_FILENAME _PATH_UTMPX
#define WTMPX_FILE _PATH_WTMPX
#define WTMPX_FILENAME _PATH_WTMPX

// Macros for fields of utmp or utmpx. Included for legacy purposes.
#define ut_name  ut_user
#define ut_time  ut_tv.tv_sec
#define ut_xtime ut_tv.tv_sec
#define ut_addr  ut_addr_v6[0]

struct exit_status {
    short int e_termination;
    short int e_exit;
};

struct utmp {
    short int ut_type;
    pid_t ut_pid;
    char* ut_line;
    char* ut_id;
    char* ut_user;
    char* ut_host;
    struct exit_status ut_exit;
    long ut_session;
    struct timeval ut_tv;
    int32_t ut_addr_v6[4];
};

/*@
requires \valid_read(utmp);
requires \valid(utmpx);
assigns *utmpx \from utmp;
*/
void getutmpx(const struct utmp *utmp, struct utmpx *utmpx);

/*@
requires \valid_read(utmpx);
requires \valid(utmp);
assigns *utmp \from utmpx;
*/
void getutmp(const struct utmpx *utmpx, struct utmp *utmp);

/*@
requires \valid_read(wtmpx_file);
requires \valid_read(utmpx);
assigns \nothing;
*/
void updwtmpx(const char *wtmpx_file, const struct utmpx *utmpx);

/*@
requires \valid_read(file);
assigns \result;
ensures \result == 0 || \result == -1;
*/
int utmpxname(const char *file);

#endif /* LIBC_UTMPX_H_ */
