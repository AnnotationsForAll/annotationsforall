#include "../../../test_common.h"
#include <sys/fanotify.h>

void runSuccess() {
    fanotify_init(anyuint(), anyuint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    fanotify_init(anyuint(), anyuint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
