#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    void* addr;
    remap_file_pages(addr, anysize(), anyint(), anysize(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    void* addr;
    remap_file_pages(addr, anysize(), anyint(), anysize(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
