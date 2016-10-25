/*
 * obstack.h
 *
 *  Created on: Jul 6, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_OBSTACK_H_
#define LIBC_OBSTACK_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_define_size_t.h"

struct obstack {
    int __gt_fc_align_mask;
    int __gt_fc_chunk_size;
};

#define obstack_chunk_alloc malloc
#define obstack_chunk_free free

#define obstack_alignment_mask(op) (op)->__gt_fc_align_mask
#define obstack_chunk_size(op) (op)->__gt_fc_chunk_size

extern void (*obstack_alloc_failed_handler)();
extern int obstack_exit_failure;

/*@
axiomatic Obstack {
    logic boolean obstack_valid(struct obstack * op) reads *op;
    logic size_t obstack_len(struct obstack * op) reads *op;

    axiom obstack_valid_implies_valid_ptr: \forall struct obstack* op; obstack_valid(op) ==> \valid(op);
    axiom len_gt_0: \forall struct obstack* op; obstack_len(op) >= 0;
}

axiomatic ObstackGrow {
    logic boolean obstack_growing(struct obstack * op) reads *op;
    logic size_t obstack_growing_len(struct obstack * op) reads *op;
    logic size_t obstack_growing_max(struct obstack * op) reads *op;

    axiom max_gt_len: \forall struct obstack * op; obstack_valid(op) ==> obstack_growing_len(op) <= obstack_growing_max(op);
    axiom grow_len_gt_0: \forall struct obstack* op; obstack_growing_len(op) >= 0;
}
*/

/*@
requires \valid(op);
assigns \result, *op \from \nothing;
ensures \result == 1;
ensures obstack_valid(op);
ensures obstack_len(op) == 0;
ensures !obstack_growing(op);
ensures obstack_growing_len(op) == 0;
ensures obstack_growing_max(op) == 0;
*/
int obstack_init(struct obstack *op);

/*@
requires obstack_valid(op);
requires !obstack_growing(op);
requires size >= 0;
assigns \result, *op \from *op, size;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op)) + size;
ensures \valid(((char*)\result)+(0..size-1));
ensures !obstack_growing(op);
ensures obstack_growing_len(op) == 0;
ensures obstack_growing_max(op) == 0;
*/
void * obstack_alloc(struct obstack *op, int size);

/*@
requires obstack_valid(op);
requires !obstack_growing(op);
requires \valid_read(((char*)address)+(0..size-1));
requires size >= 0;
assigns \result, *op \from *op, ((char*)address)[0..size-1], size;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op)) + size;
ensures \valid(((char*)\result)+(0..size-1));
ensures !obstack_growing(op);
ensures obstack_growing_len(op) == 0;
ensures obstack_growing_max(op) == 0;
*/
void * obstack_copy(struct obstack *op, void *address, int size);

/*@
requires obstack_valid(op);
requires !obstack_growing(op);
requires \valid_read(((char*)address)+(0..size-1));
requires size >= 0;
assigns \result, *op \from *op, ((char*)address)[0..size-1], size;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op)) + size + 1;
ensures \valid(((char*)\result)+(0..size));
ensures !obstack_growing(op);
ensures obstack_growing_len(op) == 0;
ensures obstack_growing_max(op) == 0;
*/
void * obstack_copy0(struct obstack *op, void *address, int size);

/*@
requires obstack_valid(op);
requires !obstack_growing(op);
assigns *op \from *op, object;
ensures !obstack_growing(op);
ensures obstack_growing_len(op) == 0;
ensures obstack_growing_max(op) == 0;
behavior free_all:
    assumes object == \null;
    ensures !obstack_valid(op);
behavior free_elem:
    assumes object != \null;
    ensures obstack_valid(op);
    ensures obstack_len(op) <= \old(obstack_len(op));
complete behaviors; disjoint behaviors;
*/
void obstack_free(struct obstack *op, void *object);

/*@
requires obstack_valid(op);
requires size >= 0;
assigns *op \from *op, size;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + size;
*/
void obstack_blank(struct obstack *op, int size);

/*@
requires obstack_valid(op);
requires \valid_read(((char*)address)+(0..size-1));
requires size >= 0;
assigns *op \from *op, ((char*)address)[0..size-1], size;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + size;
*/
void obstack_grow(struct obstack *op, void *address, int size);

/*@
requires obstack_valid(op);
requires \valid_read(((char*)address)+(0..size-1));
requires size >= 0;
assigns *op \from *op, ((char*)address)[0..size-1], size;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + size + 1;
*/
void obstack_grow0(struct obstack *op, void *address, int size);

/*@
requires obstack_valid(op);
assigns *op \from *op, c;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + sizeof(char);
*/
void obstack_1grow(struct obstack *op, char c);

/*@
requires obstack_valid(op);
assigns *op \from *op, data;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + sizeof(void*);
*/
void obstack_ptr_grow(struct obstack *op, void *data);

/*@
requires obstack_valid(op);
assigns *op \from *op, data;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + sizeof(int);
*/
void obstack_int_grow(struct obstack *op, int data);

/*@
requires obstack_valid(op);
assigns *op \from *op;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op)) + \old(obstack_growing_len(op));
ensures \valid(((char*)\result)+(0..\old(obstack_growing_len(op))));
ensures !obstack_growing(op);
ensures obstack_growing_len(op) == 0;
ensures obstack_growing_max(op) == 0;
*/
void * obstack_finish(struct obstack *op);

/*@
requires obstack_valid(op);
assigns \result \from *op;
ensures \result == obstack_growing_len(op);
*/
int obstack_object_size(struct obstack *op);

/*@
requires obstack_valid(op);
assigns \result \from *op;
ensures \result == obstack_growing_max(op) - obstack_growing_len(op);
*/
int obstack_room(struct obstack *op);

/*@
requires obstack_valid(op);
requires obstack_growing_len(op) + sizeof(char) <= obstack_growing_max(op);
assigns *op \from *op, c;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + sizeof(char);
*/
void obstack_1grow_fast(struct obstack *op, char c);

/*@
requires obstack_valid(op);
requires obstack_growing_len(op) + sizeof(void*) <= obstack_growing_max(op);
assigns *op \from *op, data;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + sizeof(void*);
*/
void obstack_ptr_grow_fast(struct obstack *op, void *data);

/*@
requires obstack_valid(op);
requires obstack_growing_len(op) + sizeof(int) <= obstack_growing_max(op);
assigns *op \from *op, data;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + sizeof(int);
*/
void obstack_int_grow_fast(struct obstack *op, int data);

/*@
requires obstack_valid(op);
requires obstack_growing_len(op) + size <= obstack_growing_max(op);
requires size >= 0;
assigns *op \from *op, size;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op)) + size;
*/
void obstack_blank_fast(struct obstack *op, int size);

/*@
requires obstack_valid(op);
assigns \result \from *op;
ensures \result != \null;
*/
void * obstack_base(struct obstack *op);

/*@
requires obstack_valid(op);
assigns \result \from *op;
ensures \result != \null;
*/
void * obstack_next_free(struct obstack *op);

/*@
requires obstack_valid(op);
requires size >= 0;
assigns *op;
ensures obstack_valid(op);
ensures obstack_len(op) == \old(obstack_len(op));
ensures obstack_growing(op);
ensures obstack_growing_len(op) == \old(obstack_growing_len(op));
ensures obstack_growing_max(op) == \old(obstack_growing_max(op)) + size;
*/
void obstack_make_room(struct obstack *op, int size);

/*@
requires obstack_valid(op);
assigns \result \from *op;
ensures \result == obstack_len(op);
*/
int obstack_memory_used(struct obstack *op);

#endif /* LIBC_OBSTACK_H_ */
