/*
 * trace.h
 *
 *  Created on: Jul 18, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_TRACE_H_
#define LIBC_TRACE_H_

#include "sys/types.h"

struct posix_trace_event_info {
    trace_event_id_t posix_event_id;
    pid_t posix_pid;
    void *posix_prog_address;
    pthread_t posix_thread_id;
    struct timespec posix_timestamp;
    int posix_truncation_status;
};

struct posix_trace_status_info {
    int posix_stream_full_status;
    int posix_stream_overrun_status;
    int posix_stream_status;
    int posix_log_full_status;
    int posix_log_overrun_status;
    int posix_stream_flush_error;
    int posix_stream_flush_status;
};

#define POSIX_TRACE_ALL_EVENTS         0
#define POSIX_TRACE_APPEND             1
#define POSIX_TRACE_CLOSE_FOR_CHILD    2
#define POSIX_TRACE_FILTER             3
#define POSIX_TRACE_FLUSH              4
#define POSIX_TRACE_FLUSH_START        5
#define POSIX_TRACE_FLUSH_STOP         6
#define POSIX_TRACE_FLUSHING           7
#define POSIX_TRACE_FULL               8
#define POSIX_TRACE_LOOP               9
#define POSIX_TRACE_NO_OVERRUN         10
#define POSIX_TRACE_NOT_FLUSHING       11
#define POSIX_TRACE_NOT_FULL           12
#define POSIX_TRACE_INHERITED          13
#define POSIX_TRACE_NOT_TRUNCATED      14
#define POSIX_TRACE_OVERFLOW           15
#define POSIX_TRACE_OVERRUN            16
#define POSIX_TRACE_RESUME             17
#define POSIX_TRACE_RUNNING            18
#define POSIX_TRACE_START              19
#define POSIX_TRACE_STOP               20
#define POSIX_TRACE_SUSPENDED          21
#define POSIX_TRACE_SYSTEM_EVENTS      22
#define POSIX_TRACE_TRUNCATED_READ     23
#define POSIX_TRACE_TRUNCATED_RECORD   24
#define POSIX_TRACE_UNNAMED_USER_EVENT 25
#define POSIX_TRACE_UNTIL_FULL         26
#define POSIX_TRACE_WOPID_EVENTS       27

int posix_trace_attr_destroy(trace_attr_t *);
int posix_trace_attr_getclockres(const trace_attr_t *, struct timespec *);
int posix_trace_attr_getcreatetime(const trace_attr_t *, struct timespec *);
int posix_trace_attr_getgenversion(const trace_attr_t *, char *);
int posix_trace_attr_getinherited(const trace_attr_t *restrict, int *restrict);
int posix_trace_attr_getlogfullpolicy(const trace_attr_t *restrict, int *restrict);
int posix_trace_attr_getlogsize(const trace_attr_t *restrict, size_t *restrict);
int posix_trace_attr_getmaxdatasize(const trace_attr_t *restrict, size_t *restrict);
int posix_trace_attr_getmaxsystemeventsize(const trace_attr_t *restrict, size_t *restrict);
int posix_trace_attr_getmaxusereventsize(const trace_attr_t *restrict, size_t, size_t *restrict);
int posix_trace_attr_getname(const trace_attr_t *, char *);
int posix_trace_attr_getstreamfullpolicy(const trace_attr_t *restrict, int *restrict);
int posix_trace_attr_getstreamsize(const trace_attr_t *restrict, size_t *restrict);
int posix_trace_attr_init(trace_attr_t *);
int posix_trace_attr_setinherited(trace_attr_t *, int);
int posix_trace_attr_setlogfullpolicy(trace_attr_t *, int);
int posix_trace_attr_setlogsize(trace_attr_t *, size_t);
int posix_trace_attr_setmaxdatasize(trace_attr_t *, size_t);
int posix_trace_attr_setname(trace_attr_t *, const char *);
int posix_trace_attr_setstreamfullpolicy(trace_attr_t *, int);
int posix_trace_attr_setstreamsize(trace_attr_t *, size_t);
int posix_trace_clear(trace_id_t);
int posix_trace_close(trace_id_t);
int posix_trace_create(pid_t, const trace_attr_t *restrict, trace_id_t *restrict);
int posix_trace_create_withlog(pid_t, const trace_attr_t *restrict, int, trace_id_t *restrict);
void posix_trace_event(trace_event_id_t, const void *restrict, size_t);
int posix_trace_eventid_equal(trace_id_t, trace_event_id_t, trace_event_id_t);
int posix_trace_eventid_get_name(trace_id_t, trace_event_id_t, char *);
int posix_trace_eventid_open(const char *restrict, trace_event_id_t *restrict);
int posix_trace_eventset_add(trace_event_id_t, trace_event_set_t *);
int posix_trace_eventset_del(trace_event_id_t, trace_event_set_t *);
int posix_trace_eventset_empty(trace_event_set_t *);
int posix_trace_eventset_fill(trace_event_set_t *, int);
int posix_trace_eventset_ismember(trace_event_id_t, const trace_event_set_t *restrict, int *restrict);
int posix_trace_eventtypelist_getnext_id(trace_id_t, trace_event_id_t *restrict, int *restrict);
int posix_trace_eventtypelist_rewind(trace_id_t);
int posix_trace_flush(trace_id_t);
int posix_trace_get_attr(trace_id_t, trace_attr_t *);
int posix_trace_get_filter(trace_id_t, trace_event_set_t *);
int posix_trace_get_status(trace_id_t, struct posix_trace_status_info *);
int posix_trace_getnext_event(trace_id_t, struct posix_trace_event_info *restrict, void *restrict, size_t, size_t *restrict, int *restrict);
int posix_trace_open(int, trace_id_t *);
int posix_trace_rewind(trace_id_t);
int posix_trace_set_filter(trace_id_t, const trace_event_set_t *, int);
int posix_trace_shutdown(trace_id_t);
int posix_trace_start(trace_id_t);
int posix_trace_stop(trace_id_t);
int posix_trace_timedgetnext_event(trace_id_t, struct posix_trace_event_info *restrict, void *restrict, size_t, size_t *restrict, int *restrict, const struct timespec *restrict);
int posix_trace_trid_eventid_open(trace_id_t, const char *restrict, trace_event_id_t *restrict);
int posix_trace_trygetnext_event(trace_id_t, struct posix_trace_event_info *restrict, void *restrict, size_t, size_t *restrict, int *restrict);

#endif /* LIBC_TRACE_H_ */
