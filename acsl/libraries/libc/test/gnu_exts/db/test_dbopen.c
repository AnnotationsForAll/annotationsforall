//OPTIONS: -wp-model Typed+cast

#include "../../../stdio_common.h"
#include <db.h>

void runSuccess() {
    BTREEINFO info;
    dbopen(anystring(), anyint(), anyint(), DB_BTREE, &info);
}

void runSuccess1() {
    HASHINFO info;
    dbopen(anystring(), anyint(), anyint(), DB_HASH, &info);
}

void runSuccess2() {
    RECNOINFO info;
    dbopen(anystring(), anyint(), anyint(), DB_RECNO, &info);
}

void runSuccess3() {
    RECNOINFO info;
    dbopen(NULL, anyint(), anyint(), DB_RECNO, &info);
}

void runSuccess4() {
    RECNOINFO info;
    dbopen(anystring(), anyint(), anyint(), DB_RECNO, NULL);
}

void runFailure() {
    RECNOINFO info;
    dbopen(anystring(), anyint(), anyint(), anyint(), &info);
}

int f;
void testValues() {
    f = 2;
    
    BTREEINFO info;
    DB* result = dbopen(anystring(), anyint(), anyint(), DB_BTREE, &info);
    //@ assert result != \null ==> result->type == DB_BTREE;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


