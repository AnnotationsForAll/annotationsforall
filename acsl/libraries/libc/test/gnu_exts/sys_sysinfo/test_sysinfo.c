#include "../../../test_common.h"
#include <sys/sysinfo.h>

void runSuccess() {
    struct sysinfo info;
    sysinfo(&info);
}

void runFailure() {
    struct sysinfo info;
    sysinfo(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct sysinfo info;
    sysinfo(&info);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
