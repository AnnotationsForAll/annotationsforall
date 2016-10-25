#include "../../test_common.h"
#include <locale.h>

void runSuccess() {
    localeconv();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct lconv* result;
    
    result = localeconv();
    //@ assert \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}