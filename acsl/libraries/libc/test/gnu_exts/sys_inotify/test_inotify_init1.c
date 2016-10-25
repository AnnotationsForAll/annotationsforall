#include "../../../test_common.h"
#include <sys/inotify.h>

void runSuccess() {
    inotify_init1(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    inotify_init1(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
