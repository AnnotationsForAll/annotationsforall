#include "../../../test_common.h"
#include <sys/ustat.h>

void runSuccess() {
    dev_t dev;
    struct ustat buf;
    ustat(dev, &buf);
}

void runFailure() {
    dev_t dev;
    struct ustat buf;
    ustat(dev, NULL);
}

int f;
void testValues() {
    f = 2;
    
    dev_t dev;
    struct ustat buf;
    ustat(dev, &buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
