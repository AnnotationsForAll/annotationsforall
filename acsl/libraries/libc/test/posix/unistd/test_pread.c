#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern off_t anyoff();

void runSuccess() {
    char buf[10];
    pread(anyint(), buf, 10, anyoff());
}

void runFailure() {
    char buf[10];
    pread(anyint(), buf, 20, anyoff());
}

void runFailure1() {
    pread(anyint(), NULL, 20, anyoff());
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    char buf[10];
    
    result = pread(anyint(), buf, 10, anyoff());
    //@ assert result >= -1;
    //@ assert result != -1 ==> \valid_read(buf+(0..result-1));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
