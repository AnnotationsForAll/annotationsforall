#include "../../../test_common.h"
#include <sys/sysmacros.h>

void runSuccess() {
    dev_t dev;
    gnu_dev_minor(dev);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    dev_t dev = gnu_dev_makedev(12, 34);
    unsigned int b = gnu_dev_minor(dev);
    //@ assert b == 34;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
