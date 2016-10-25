#include "../../../test_common.h"
#include <aliases.h>

void runSuccess() {
    struct aliasent result;
    char buffer[10];
    struct aliasent * rp;
    getaliasbyname_r(anystring(), &result, &buffer, 10, &rp);
}

void runSuccess1() {
    struct aliasent result;
    char buffer[10];
    struct aliasent * rp;
    getaliasbyname_r(anystring(), &result, &buffer, 5, &rp);
}

void runFailure() {
    getaliasbyname_r(NULL, NULL, NULL, anysize(), NULL);
}

void runFailure1() {
    getaliasbyname_r(anystring(), NULL, NULL, anysize(), NULL);
}

void runFailure2() {
    struct aliasent result;
    char buffer[10];
    struct aliasent * rp;
    getaliasbyname_r(anystring(), &result, &buffer, 20, &rp);
}

int f;
void testValues() {
    f = 2;
    
    struct aliasent result;
    char buffer[10];
    struct aliasent * rp;
    int status = getaliasbyname_r(anystring(), &result, &buffer, 10, &rp);
    //@ assert status == 0 ==> rp != NULL ==> *rp == result;
    //@ assert status == 0 ==> rp != NULL ==> \valid_read(result.alias_name);
    //@ assert status == 0 ==> rp != NULL ==> result.alias_members_len > 0 ==> \valid_read(result.alias_members[0]);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
