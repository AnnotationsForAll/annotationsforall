#include "../../../test_common.h"
#include <sys/inotify.h>

void runSuccess() {
    inotify_rm_watch(anyint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    inotify_rm_watch(anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
