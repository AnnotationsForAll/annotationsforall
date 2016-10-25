#include "../../../test_common.h"
#include <mcheck.h>

void valid_func_ptr(enum mcheck_status status) {}

void runSuccess() {
    mcheck(NULL);
}

void runSuccess1() {
    mcheck(valid_func_ptr);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    mcheck(NULL);
    mcheck(valid_func_ptr);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
