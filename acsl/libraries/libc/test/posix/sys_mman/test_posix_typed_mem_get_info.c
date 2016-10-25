#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    struct posix_typed_mem_info info;
    posix_typed_mem_get_info(anyint(), &info);
}

void runFailure() {
    struct posix_typed_mem_info info;
    posix_typed_mem_get_info(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct posix_typed_mem_info info;
    posix_typed_mem_get_info(anyint(), &info);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
