/*
 * search.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SEARCH_H_
#define LIBC_SEARCH_H_

#include "__fc_define_size_t.h"
#include "__gt_fc_define_comparison_fn_t.h"
#include "errno.h"

typedef struct entry {
    char* key;
    char* data;
} ENTRY;

typedef enum {
    FIND,
    ENTER
} ACTION;

typedef enum {
    preorder,
    postorder,
    endorder,
    leaf
} VISIT;

//@ ghost ENTRY* __hash_table;

/*@
assigns \result, __hash_table, errno \from nel;
ensures \result != 0 ==> \valid(__hash_table);
*/
int hcreate(size_t nel);

/*@
requires \valid(__hash_table);
assigns __hash_table \from \nothing;
ensures !\valid(__hash_table);
*/
void hdestroy(void);

/*@
requires action == FIND || action == ENTER;
requires \valid(__hash_table);
assigns \result, __hash_table, errno \from __hash_table, item, action;
ensures \result != \null ==> \valid(\result);
ensures \valid(__hash_table);
*/
ENTRY *hsearch(ENTRY item, int action);

/*@
requires \valid((char*)element);
assigns *((char*)element) \from *((char*)element), pred;
*/
void insque(void *element, void *pred);

/*@
requires \valid((char*)element);
assigns *((char*)element) \from *((char*)element);
*/
void remque(void *element);

/*@
requires \valid(nelp);
requires compar != \null;
requires \valid(((char*)key)+(0..width-1));
requires \valid(((char*)base)+(0..(((*nelp)+1)*width)-1));
assigns \result \from ((char*)key)[0..width-1], ((char*)base)[0..(((*nelp)+1)*width)-1], *compar;
ensures ((char*)\result) != \null ==> \valid(((char*)\result));
ensures *nelp == \old(*nelp) || *nelp == \old(*nelp)+1;
*/
void *lsearch(const void *key, void *base, size_t *nelp, size_t width, int (*compar)(const void *, const void *));

/*@
requires \valid(nelp);
requires compar != \null;
requires \valid(((char*)key)+(0..width-1));
requires \valid(((char*)base)+(0..(((*nelp))*width)-1));
assigns \result \from ((char*)key)[0..width-1], ((char*)base)[0..(((*nelp))*width)-1], *compar;
ensures ((char*)\result) != \null ==> \valid(((char*)\result));
*/
void *lfind(const void *key, const void *base, size_t *nelp, size_t width, int (*compar)(const void *, const void *));

/*@
requires rootp != \null ==> \valid(rootp);
requires compar != \null;
assigns \result, *((char*)rootp), *((char*)key) \from *((char*)key), *((char*)rootp), *compar;
ensures ((char*)\result) != \null ==> \valid(((char*)\result));
*/
void *tdelete(const void *restrict key, void **restrict rootp, int(*compar)(const void *, const void *));

/*@
requires rootp != \null ==> \valid(rootp);
requires compar != \null;
assigns \result, *((char*)rootp), *((char*)key) \from *((char*)key), *((char*)rootp), *compar;
ensures ((char*)\result) != \null ==> \valid(((char*)\result));
*/
void *tfind(const void *key, void *const *rootp, int(*compar)(const void *, const void *));

/*@
requires rootp != \null ==> \valid(rootp);
requires compar != \null;
assigns \result, *((char*)rootp), *((char*)key) \from *((char*)key), *((char*)rootp), *compar;
ensures ((char*)\result) != \null ==> \valid(((char*)\result));
*/
void *tsearch(const void *key, void **rootp, int (*compar)(const void *, const void *));

/*@
requires (char*)root != \null ==> \valid((char*)root);
requires action != \null;
assigns \nothing;
*/
void twalk(const void *root, void (*action)(const void *, int, int));

/* GNU Extensions */

struct hsearch_data {
    struct ENTRY *table;
    unsigned int size;
    unsigned int filled;
};

struct qelem {
    struct qelem *q_forw;
    struct qelem *q_back;
    char q_data[1];
};

/*@
requires htab != \null ==> \valid(htab);
assigns errno, \result, *htab, htab->table[0..nel-1];
ensures htab == \null ==> \result == 0 && errno == EINVAL;
ensures \result == 0 ? errno != 0 : errno == \old(errno);
ensures \result != 0 ==> \valid(htab->table+(0..nel-1));
ensures \result != 0 ==> htab->filled == 0;
ensures \result != 0 ==> htab->size == nel;
*/
int hcreate_r(size_t nel, struct hsearch_data *htab);

/*@
requires \valid(htab);
assigns errno, \result, *retval, *htab, htab->table[0..htab->size-1] \from *htab, htab->table[0..htab->size-1];
ensures \result == 0 ==> *retval == \null;
ensures \result != 0 ==> \valid(*retval);
ensures \result == 0 ? errno != 0 : errno == \old(errno);
ensures htab->table == \old(htab->table);
ensures htab->size == \old(htab->size);
*/
int hsearch_r(ENTRY item, ACTION action, ENTRY **retval, struct hsearch_data *htab);

/*@
requires htab != \null ==> \valid(htab);
assigns errno, *htab;
ensures htab == \null ==> errno == EINVAL;
*/
void hdestroy_r(struct hsearch_data *htab);

#endif /* LIBC_SEARCH_H_ */
