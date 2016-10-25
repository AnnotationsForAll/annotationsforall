#include "../../../test_common.h"
#include <dirent.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct dirent * anydir();

void runSuccess() {
    struct dirent * d1 = anydir();
    struct dirent * d2 = anydir();
    
    alphasort(&d1, &d2);
}

void runFailure() {
    alphasort(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct dirent * d1 = anydir();
    struct dirent * d2 = anydir();
    
    result = alphasort(&d1, &d2);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
