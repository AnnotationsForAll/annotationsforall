#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

void runSuccess() {
    infnan(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    double result;

    errno = 0;
    result = infnan(anyint());
    //@ assert errno == ERANGE || errno == EDOM;
    result = infnan(ERANGE);
    //@ assert errno == ERANGE && result == HUGE_VAL;
    result = infnan(-ERANGE);
    //@ assert errno == ERANGE && result == -HUGE_VAL;
    result = infnan(0);
    //@ assert errno == EDOM;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
