#include "../../../test_common.h"
#include <mpool.h>

void runSuccess() {
    char buf[10];
    DBT key = {
            .size = 10,
            .data = buf,
    };
    mpool_open(&key, anyint(), anysize(), anysize());
}

void runSuccess1() {
    mpool_open(NULL, anyint(), anysize(), anysize());
}

void runFailure() {
    char buf[10];
    DBT key = {
            .size = 20,
            .data = buf,
    };
    mpool_open(&key, anyint(), anysize(), anysize());
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    DBT key = {
            .size = 10,
            .data = buf,
    };
    MPOOL* mp = mpool_open(&key, anyint(), anysize(), anysize());
    //@ assert mp == \null || \valid(mp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
