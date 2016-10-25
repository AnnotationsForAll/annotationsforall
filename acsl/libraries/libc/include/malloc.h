/*
 * malloc.h
 *
 *  Created on: Jul 6, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_MALLOC_H_
#define LIBC_MALLOC_H_

// This header is defined in the SVID/XPG interface. Do not use for strictly POSIX-compliant work.

#include "__gt_fc_heap_axiomatics.h"
#include "__fc_define_file.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_file_axioms.h"
#include "stdlib.h"
#include "stdio.h"
#include "errno.h"

#define M_TRIM_THRESHOLD 0
#define M_TOP_PAD        1
#define M_MMAP_THRESHOLD 2
#define M_MMAP_MAX       3
#define M_CHECK_ACTION   4
#define M_PERTURB        5
#define M_ARENA_TEST     6
#define M_ARENA_MAX      7
#define M_MXFAST         8
#define M_NLBLKS         9
#define M_GRAIN          10
#define M_KEEP           11


struct mallinfo {
    int arena;
    int ordblks;
    int smblks;
    int hblks;
    int hblkhd;
    int usmblks;
    int fsmblks;
    int uordblks;
    int fordblks;
    int keepcost;
};

extern void (* __after_morecore_hook) (void);
extern void* (*__malloc_hook)(size_t size, const void *caller);
extern void *(*__realloc_hook)(void *ptr, size_t size, const void *caller);
extern void (*__free_hook)(void *ptr, const void *caller);
extern void *(*__memalign_hook)(size_t alignment, size_t size, const void *caller);
extern void (*__malloc_initialize_hook)(void);

extern void *__default_morecore (ptrdiff_t __size);
extern void __malloc_check_init (void);

/*@
 requires M_TRIM_THRESHOLD <= param <= M_KEEP;
 assigns \result \from param, value;
 */
int mallopt(int param, int value);

/*@
assigns \result \from \nothing;
*/
struct mallinfo mallinfo();

/*@
axiomatic MallocState {
    logic boolean is_malloc_state(void* state) reads state;
}
*/

/*@
assigns \result, __fc_heap_status \from __fc_heap_status;
ensures \result != \null ==> is_malloc_state(\result);
*/
void* malloc_get_state(void);

/*@
requires is_malloc_state(state);
assigns \result, __fc_heap_status \from state;
ensures -2 <= \result <= 0;
*/
int malloc_set_state(void *state);

/*@
requires file_is_open(stream);
requires \valid(stream);
assigns errno, \result, *stream \from __fc_heap_status, options, *stream;
ensures options == 0 ? \result == 0 : \result == -1;
ensures options != 0 ? errno == EINVAL : errno == \old(errno);
*/
int malloc_info(int options, FILE *stream);

/*@
assigns *stderr \from *stderr, __fc_heap_status;
*/
void malloc_stats(void);

/*@
assigns __fc_heap_status \from pad, __fc_heap_status;
ensures \result == 1 || \result == 0;
*/
int malloc_trim(size_t pad);

/*@
assigns \result \from ptr, __fc_heap_status;
ensures \result == 0 || \result == \block_length((char*)ptr);
*/
size_t malloc_usable_size(void *ptr);

#endif /* LIBC_MALLOC_H_ */
