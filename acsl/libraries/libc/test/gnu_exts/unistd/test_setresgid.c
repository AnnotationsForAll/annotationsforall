#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    gid_t a, b, c;
    setresgid(a, b, c);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    gid_t a, b, c;
    setresgid(a, b, c);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
