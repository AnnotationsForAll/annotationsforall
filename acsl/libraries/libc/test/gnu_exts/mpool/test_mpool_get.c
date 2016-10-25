#include "../../../test_common.h"
#include <mpool.h>

void any_pager(void *, pgno_t, void *);

void runSuccess() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page;
        void* data1 = mpool_new(mp, &page);
        if (data1) {
            void* data2 = mpool_get(mp, page, anyint());
        }
    }
}

void runFailure() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page;
        void* data1 = mpool_new(mp, &page);
        void* data2 = mpool_get(NULL, page, anyint());
    }
}

void runFailure1() {
    MPOOL* mp = mpool_open(NULL, anyint(), anysize(), anysize());
    if (mp) {
        pgno_t page = anyint();
        void* data2 = mpool_get(mp, page, anyint());
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
            void* data2 = mpool_get(mp, page, anyint());
            //@ assert data1 == data2;
        }
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
