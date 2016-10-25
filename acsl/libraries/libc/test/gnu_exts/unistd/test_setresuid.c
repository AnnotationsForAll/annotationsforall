#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    uid_t a, b, c;
    setresuid(a, b, c);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    uid_t a, b, c;
    setresuid(a, b, c);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
