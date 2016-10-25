#include "../../../test_common.h"
#include <sys/epoll.h>

void runSuccess() {
    epoll_create(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    epoll_create(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
