#include "../../../test_common.h"
#include <mpool.h>

void any_pager(void *, pgno_t, void *);

void runSuccess() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_filter(mp, NULL, NULL, anystring());
    }
}

void runSuccess1() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_filter(mp, any_pager, any_pager, anystring());
    }
}

void runSuccess2() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_filter(mp, NULL, NULL, NULL);
    }
}

void runSuccess3() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_filter(mp, any_pager, any_pager, NULL);
    }
}

void runFailure() {
    mpool_filter(NULL, NULL, NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        mpool_filter(mp, NULL, NULL, anystring());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
