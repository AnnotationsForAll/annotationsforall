#include "../../../test_common.h"
#include <sys/fanotify.h>

void runSuccess() {
    fanotify_mark(anyint(), anyuint(), anyuint(), anyint(), anystring());
}

void runSuccess1() {
    fanotify_mark(anyint(), anyuint(), anyuint(), anyint(), NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    fanotify_mark(anyint(), anyuint(), anyuint(), anyint(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
