/*
 * raw.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_RAW_H_
#define LIBC_SYS_RAW_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "ioctl.h"

#define RAW_MAJOR   162

#define RAW_SETBIND     _IO(0xac, 0)
#define RAW_GETBIND     _IO(0xac, 1)

struct raw_config_request
{
  int raw_minor;
  uint64_t block_major;
  uint64_t block_minor;
};

#endif /* LIBC_SYS_RAW_H_ */
