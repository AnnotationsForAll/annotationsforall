#include "../../../test_common.h"
#include <sys/sendfile.h>

void runSuccess() {
    off_t off;
    sendfile(anyint(), anyint(), &off, anysize());
}

void runSuccess1() {
    off_t off;
    sendfile(anyint(), anyint(), NULL, anysize());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    size_t len;
    off_t off;
    ssize_t result = sendfile(anyint(), anyint(), &off, len);
    //@ assert -1 <= result <= len;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
