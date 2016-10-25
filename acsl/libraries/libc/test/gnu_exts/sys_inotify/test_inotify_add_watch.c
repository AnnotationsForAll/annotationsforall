#include "../../../test_common.h"
#include <sys/inotify.h>

void runSuccess() {
    inotify_add_watch(anyint(), anystring(), anyint());
}

void runFailure() {
    inotify_add_watch(anyint(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    inotify_add_watch(anyint(), anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
