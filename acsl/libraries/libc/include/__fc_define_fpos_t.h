// This is an exact copy from frama-c Sodium. It is included here for compatibility when running Neon.

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

#ifndef __FC_DEFINE_FPOS_T_H
#define __FC_DEFINE_FPOS_T_H
#include "features.h"
#include "__gt_fc_define_mbstate_t.h"
__BEGIN_DECLS

struct __fc_pos_t {
    unsigned long __fc_stdio_position;
    // FIXME:
//    mbstate_t __gt_fc_mbstate; // Only valid for wide-oriented streams
};
typedef struct __fc_pos_t fpos_t;
typedef struct __fc_pos_t fpos64_t;

__END_DECLS

#endif
