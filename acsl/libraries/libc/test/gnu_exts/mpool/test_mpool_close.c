#include "../../../test_common.h"
#include <mpool.h>

void any_pager(void *, pgno_t, void *);

void runSuccess() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_close(mp);
    }
}

void runFailure() {
    mpool_close(NULL);
}

void runFailure1() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_close(mp);
        mpool_close(mp);
    }
}

int f;
void testValues() {
    f = 2;
    
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_close(mp);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
