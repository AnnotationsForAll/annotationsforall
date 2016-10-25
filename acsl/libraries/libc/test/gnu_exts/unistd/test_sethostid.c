#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    sethostid(anylong());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sethostid(anylong());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
