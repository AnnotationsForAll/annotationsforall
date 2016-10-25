/*
 * link.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_LINK_H_
#define LIBC_LINK_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "elf.h"
#include "stdint.h"
#include "__fc_define_size_t.h"
#include "__gt_fc_define_alternative_types.h"
#include "__gt_fc_define_lmid_t.h"
#include "__fc_string_axiomatic.h"

#define ElfW(sym) Elf64_##sym //FIXME: make this machdep independent

#define LAV_CURRENT 1

struct link_map {
    ElfW(Addr) l_addr;
    char *l_name;
    ElfW(Dyn) *l_ld;
    struct link_map *l_next, *l_prev;
};

struct dl_phdr_info {
    ElfW(Addr) dlpi_addr;
    const char *dlpi_name;
    const ElfW(Phdr) *dlpi_phdr;
    ElfW(Half) dlpi_phnum;
    unsigned long long int dlpi_adds;
    unsigned long long int dlpi_subs;
    size_t dlpi_tls_modid;
    void *dlpi_tls_data;
};

struct r_debug {
    int r_version;
    struct link_map *r_map;
    ElfW(Addr) r_brk;
    enum {
        RT_CONSISTENT,
        RT_ADD,
        RT_DELETE
    } r_state;
    ElfW(Addr) r_ldbase;
};

enum {
    LA_ACT_CONSISTENT,
    LA_ACT_ADD,
    LA_ACT_DELETE
};

enum {
    LA_SER_ORIG = 0x01,
    LA_SER_LIBPATH = 0x02,
    LA_SER_RUNPATH = 0x04,
    LA_SER_CONFIG = 0x08,
    LA_SER_DEFAULT = 0x40,
    LA_SER_SECURE = 0x80
};

enum {
    LA_FLG_BINDTO = 0x01,
    LA_FLG_BINDFROM = 0x02
};

enum {
    LA_SYMB_NOPLTENTER = 0x01,
    LA_SYMB_NOPLTEXIT = 0x02,
    LA_SYMB_STRUCTCALL = 0x04,
    LA_SYMB_DLSYM = 0x08,
    LA_SYMB_ALTVALUE = 0x10
};

typedef uint32_t Elf_Symndx;

/*@
requires callback != \null;
assigns \result;
*/
int dl_iterate_phdr(int (*callback)(struct dl_phdr_info *info, size_t size, void *data), void *data);

// The below functions should never be called by users. These are hooks for an auditing library to use, and only the dynamic linker should call these functions.

// la_version() left intentionally unannotated.
unsigned int la_version(unsigned int version);

/*@
requires valid_read_string(name);
requires \valid(cookie);
ensures \result != \null ==> valid_read_string(\result);
*/
char *la_objsearch(const char *name, uintptr_t *cookie, unsigned int flag);

/*@
requires \valid(cookie);
*/
void la_activity(uintptr_t *cookie, unsigned int flag);

/*@
requires \valid(map);
requires \valid(cookie);
*/
unsigned int la_objopen(struct link_map *map, Lmid_t lmid, uintptr_t *cookie);

/*@
requires \valid(cookie);
*/
unsigned int la_objclose (uintptr_t *cookie);

/*@
requires \valid(cookie);
*/
void la_preinit(uintptr_t *cookie);

/*@
requires \valid(sym);
requires \valid(refcook);
requires \valid(defcook);
requires \valid(flags);
requires valid_read_string(symname);
*/
uintptr_t la_symbind32(Elf32_Sym *sym, unsigned int ndx, uintptr_t *refcook, uintptr_t *defcook, unsigned int *flags, const char *symname);

/*@
requires \valid(sym);
requires \valid(refcook);
requires \valid(defcook);
requires \valid(flags);
requires valid_read_string(symname);
*/
uintptr_t la_symbind64(Elf64_Sym *sym, unsigned int ndx, uintptr_t *refcook, uintptr_t *defcook, unsigned int *flags, const char *symname);

#endif /* LIBC_LINK_H_ */
