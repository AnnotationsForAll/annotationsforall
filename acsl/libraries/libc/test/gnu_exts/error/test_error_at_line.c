#include "../../../test_common.h"
#include <error.h>

void runSuccess() {
    error_at_line(anyint(), anyint(), anystring(), anyint(), anystring());
}

void runFailure() {
    error_at_line(anyint(), anyint(), NULL, anyint(), anystring());
}

void runFailure1() {
    error_at_line(anyint(), anyint(), anystring(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    error_at_line(0, anyint(), anystring(), anyint(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
