#include "../../../test_common.h"
#include <sys/sysinfo.h>

void runSuccess() {
    get_nprocs_conf();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int result = get_nprocs_conf();
    //@ assert result > 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
