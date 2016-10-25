#include "../../../test_common.h"
#include <sys/mman.h>

/*@
assigns \result;
*/
extern off_t anyoff();

void runSuccess() {
    char buf[10];
    mmap(buf, 10, anyint(), anyint(), anyint(), anyoff());
}

void runFailure() {
    mmap(NULL, 10, anyint(), anyint(), anyint(), anyoff());
}

void runFailure1() {
    char buf[10];
    mmap(buf, 20, anyint(), anyint(), anyint(), anyoff());
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char buf[10];
    result = mmap(buf, 10, anyint(), anyint(), anyint(), anyoff());
    //@ assert result == MAP_FAILED || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
