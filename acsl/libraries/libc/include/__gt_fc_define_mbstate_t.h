#ifndef __FC_DEFINE_MBSTATE_T
#define __FC_DEFINE_MBSTATE_T

#include "__fc_machdep.h"

__BEGIN_DECLS
#define MB_CUR_MAX __FC_MB_CUR_MAX

typedef struct { int __count; char __value[4]; } mbstate_t;
__END_DECLS

#define __GT_FC_MBSTATE_INITIAL_STATE {.__count = 0}

#endif
