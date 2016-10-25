#include "../../../test_common.h"
#include <sys/sysmacros.h>

void runSuccess() {
    gnu_dev_makedev(anyuint(), anyuint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    dev_t dev = gnu_dev_makedev(12, 34);
    unsigned int a = gnu_dev_major(dev);
    unsigned int b = gnu_dev_minor(dev);
    //@ assert a == 12;
    //@ assert b == 34;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
