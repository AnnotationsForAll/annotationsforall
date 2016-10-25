#include "../../../unistd_common.h"
#include <fcntl.h>

void runSuccess() {
    splice(anyint(), NULL, anyint(), NULL, anysize(), anyint());
}

void runSuccess1() {
    off64_t roff = anylonglong();
    off64_t woff = anylonglong();
    splice(anyint(), &roff, anyint(), &woff, anysize(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    splice(anyint(), NULL, anyint(), NULL, anysize(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
