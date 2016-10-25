/*
 * sysinfo.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_SYSINFO_H_
#define LIBC_SYS_SYSINFO_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"

struct sysinfo {
    long uptime;
    unsigned long loads[3];
    unsigned long totalram;
    unsigned long freeram;
    unsigned long sharedram;
    unsigned long bufferram;
    unsigned long totalswap;
    unsigned long freeswap;
    uint16_t procs;
    uint16_t pad;
    unsigned long totalhigh;
    unsigned long freehigh;
    uint32_t mem_unit;
};

/*@
assigns \result;
ensures \result > 0;
*/
int get_nprocs_conf (void);

/*@
assigns \result;
ensures \result > 0;
*/
int get_nprocs (void);

/*@
assigns \result;
ensures \result >= 0;
*/
long int get_phys_pages (void);

/*@
assigns \result;
ensures \result >= 0;
*/
long int get_avphys_pages (void);

/*@
requires \valid(info);
assigns \result, *info;
ensures \result == 0 || \result == -1;
*/
int sysinfo (struct sysinfo *info);

#endif /* LIBC_SYS_SYSINFO_H_ */
