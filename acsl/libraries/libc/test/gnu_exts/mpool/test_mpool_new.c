#include "../../../test_common.h"
#include <mpool.h>

void any_pager(void *, pgno_t, void *);

void runSuccess() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page;
        mpool_new(mp, &page);
    }
}

void runFailure() {
    pgno_t page;
    mpool_new(NULL, &page);
}

void runFailure1() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page;
        mpool_new(mp, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page;
        mpool_new(mp, &page);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
