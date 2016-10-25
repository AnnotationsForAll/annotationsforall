#include "../../../stdio_common.h"
#include <pwd.h>
#include <errno.h>

void runSuccess() {
    getpw(anyint(), NULL);
}

void runSuccess1() {
    getpw(anyint(), anystring());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    getpw(anyint(), NULL);
    //@ assert errno == EINVAL;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
