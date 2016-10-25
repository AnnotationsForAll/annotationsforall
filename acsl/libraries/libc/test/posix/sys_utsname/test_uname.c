#include "../../../test_common.h"
#include <sys/utsname.h>
#include <sys/types.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct utsname * anyname();

void runSuccess() {
    uname(anyname());
}

void runFailure() {
    uname(NULL);
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    
    uname(anyname());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
