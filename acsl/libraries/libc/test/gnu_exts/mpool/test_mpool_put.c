#include "../../../test_common.h"
#include <mpool.h>

void any_pager(void *, pgno_t, void *);

void runSuccess() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page;
        void* data1 = mpool_new(mp, &page);
        if (data1) {
            mpool_put(mp, page, anyint());
        }
    }
}

void runFailure() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page;
        void* data1 = mpool_new(mp, &page);
        mpool_put(NULL, page, anyint());
    }
}

void runFailure1() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page = anyint();
        mpool_put(mp, page, anyint());
    }
}

int f;
void testValues() {
    f = 2;
    
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page;
        void* data1 = mpool_new(mp, &page);
        if (data1) {
            mpool_put(mp, page, anyint());
        }
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
