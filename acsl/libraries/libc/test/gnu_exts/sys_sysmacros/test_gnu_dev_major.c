#include "../../../test_common.h"
#include <sys/sysmacros.h>

void runSuccess() {
    dev_t dev;
    gnu_dev_major(dev);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    dev_t dev = gnu_dev_makedev(12, 34);
    unsigned int a = gnu_dev_major(dev);
    //@ assert a == 12;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
