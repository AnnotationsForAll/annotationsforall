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

#ifndef __FC_DEFINE_SEEK_MACROS
#define __FC_DEFINE_SEEK_MACROS

// POSIX versions of the seek macros.
# define SEEK_SET 0
# define SEEK_CUR 1
# define SEEK_END 2
// GNU extension seek values.
#define SEEK_DATA 3
#define SEEK_HOLE 4

// BSD versions of the seek macros.
# define L_SET  SEEK_SET
# define L_INCR SEEK_CUR
# define L_XTND SEEK_END

#endif

