#include "../../../test_common.h"
#include <mpool.h>

void any_pager(void *, pgno_t, void *);

void runSuccess() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_sync(mp);
    }
}

void runFailure() {
    mpool_sync(NULL);
}

int f;
void testValues() {
    f = 2;
    
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_sync(mp);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
