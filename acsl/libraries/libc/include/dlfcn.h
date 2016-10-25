/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2015                                               */
/*    CEA (Commissariat à l'énergie atomique et aux énergies              */
/*         alternatives)                                                  */
/*                                                                        */
/*  you can redistribute it and/or modify it under the terms of the GNU   */
/*  Lesser General Public License as published by the Free Software       */
/*  Foundation, version 2.1.                                              */
/*                                                                        */
/*  It is distributed in the hope that it will be useful,                 */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/*  GNU Lesser General Public License for more details.                   */
/*                                                                        */
/*  See the GNU Lesser General Public License version 2.1                 */
/*  for more details (enclosed in the file licenses/LGPLv2.1).            */
/*                                                                        */
/**************************************************************************/

#ifndef __FC_DLFCN_H
#define __FC_DLFCN_H

#include "features.h"
#include "elf.h"
#include "link.h"
#include "__gt_fc_define_lmid_t.h"
#include "__fc_string_axiomatic.h"

#define RTLD_LAZY         (1 << 0)
#define RTLD_NOW          (1 << 1)
#define RTLD_NOLOAD       (1 << 2)
#define RTLD_DEEPBIND     (1 << 3)
#define RTLD_GLOBAL       (1 << 4)
#define RTLD_LOCAL        (1 << 5)
#define RTLD_NODELETE     (1 << 6)
#define RTLD_BINDING_MASK (RTLD_LAZY | RTLD_NOW)

#define RTLD_NEXT ((void *) -1l)
#define RTLD_DEFAULT ((void *) 0)

/*@
axiomatic OpenDynTable {
    logic boolean is_dyn_table_open(void* p);
}
*/

__BEGIN_DECLS

/*@
requires file == \null || \valid(file);
assigns \result \from file[..], mode;
ensures \result != \null ==> \valid((char*)\result);
ensures \result != \null ==> is_dyn_table_open(\result);
*/
void *dlopen(const char *file, int mode);

/*@
requires is_dyn_table_open(handle);
assigns \result \from handle, name[..];
ensures \result != \null ==> \valid((char*)\result);
*/
void *dlsym(void *restrict handle, const char *restrict name);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
char *dlerror(void);

/* GNU Extensions */

#define RTLD_DL_LINKMAP (1 << 0)
#define RTLD_DL_SYMENT  (1 << 1)

#define LM_ID_BASE -1L
#define LM_ID_NEWLM -2L

#define RTLD_DI_LMID        0
#define RTLD_DI_LINKMAP     1
#define RTLD_DI_ORIGIN      2
#define RTLD_DI_SERINFO     3
#define RTLD_DI_SERINFOSIZE 4
#define RTLD_DI_TLS_MODID   5
#define RTLD_DI_TLS_DATA    6
#define RTLD_DI_CONFIGADDR  7
#define RTLD_DI_PROFILENAME 8
#define RTLD_DI_PROFILEOUT  9

#define RTLD_DI_MAX         10

#define DL_CALL_FCT(fctp, ...) (*fctp) ( __VA_ARGS__ )

typedef struct {
    const char *dli_fname;
    void *dli_fbase;
    const char *dli_sname;
    void *dli_saddr;
} Dl_info;

typedef struct {
    char *dls_name;
    unsigned int dls_flags;
} Dl_serpath;

typedef struct {
    size_t dls_size;
    unsigned int dls_cnt;
    Dl_serpath dls_serpath[1];
} Dl_serinfo;

/*@
requires \valid(info);
assigns \result, *info \from addr;
ensures \result != 0 ==> valid_string(info->dli_fname);
ensures \result != 0 ==> info->dli_sname != \null ==> valid_string(info->dli_sname);
ensures \result != 0 ==> (info->dli_sname == \null <==> info->dli_saddr == \null);
*/
int dladdr(void *addr, Dl_info *info);

/*@
requires \valid(info);
requires flags == RTLD_DL_LINKMAP || flags == RTLD_DL_SYMENT;
requires \valid(extra_info);
assigns \result, *info \from addr;
ensures \result != 0 ==> valid_string(info->dli_fname);
ensures \result != 0 ==> info->dli_sname != \null ==> valid_string(info->dli_sname);
ensures \result != 0 ==> (info->dli_sname == \null <==> info->dli_saddr == \null);
behavior mode_linkmap:
    assumes flags == RTLD_DL_LINKMAP;
    ensures \result != 0 ==> \valid(*((struct link_map**)(extra_info)));
behavior mode_syment:
    assumes flags == RTLD_DL_SYMENT;
    ensures \result != 0 ==> \valid(*((ElfW(Sym)**)(extra_info)));
complete behaviors; disjoint behaviors;
*/
int dladdr1(void *addr, Dl_info *info, void **extra_info, int flags);

/*@
requires file == \null || \valid(file);
assigns \result \from file[..], mode;
ensures \result != \null ==> \valid((char*)\result);
ensures \result != \null ==> is_dyn_table_open(\result);
*/
void *dlmopen(Lmid_t lmid, const char *file, int mode);

/*@ // TODO: need to be able to say what it assigns for every request type
requires is_dyn_table_open(handle);
assigns \result \from handle, request;
ensures \result == 0 || \result == -1;
*/
int dlinfo(void *handle, int request, void *info);

/*@
requires is_dyn_table_open(handle);
requires valid_read_string(name);
requires valid_read_string(version);
assigns \result \from handle, name[0..], version[0..];
ensures \result != \null ==> \valid((char*)\result);
*/
void *dlvsym(void *handle, char *name, char *version);

__END_DECLS

#endif

