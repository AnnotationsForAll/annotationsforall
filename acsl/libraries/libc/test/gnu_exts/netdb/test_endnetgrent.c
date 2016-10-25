#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    endnetgrent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    endnetgrent();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
