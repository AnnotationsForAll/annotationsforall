#include "../../../test_common.h"
#include <arpa/inet.h>

//@ assigns \result \from \nothing;
struct in_addr anyaddr();

void runSuccess() {
    inet_netof(anyaddr());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    inet_netof(anyaddr());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
