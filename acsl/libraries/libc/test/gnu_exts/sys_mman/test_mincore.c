#include "../../../test_common.h"
#include <sys/mman.h>
#include <unistd.h>

/*@
assigns \result;
ensures \valid(\result+(0..size-1));
*/
unsigned char * my_malloc(int size);

void runSuccess() {
    long sz = sysconf(_SC_PAGE_SIZE);
    unsigned char * vec = my_malloc(sz);
    void* addr;
    mincore(addr, 1, vec);
}

void runSuccess1() {
    long sz = sysconf(_SC_PAGE_SIZE) * 3;
    unsigned char * vec = my_malloc(sz);
    void* addr;
    mincore(addr, 3, vec);
}

void runFailure() {
    long sz = sysconf(_SC_PAGE_SIZE);
    unsigned char * vec = my_malloc(sz);
    void* addr;
    mincore(addr, 1, NULL);
}

int f;
void testValues() {
    f = 2;
    
    long sz = sysconf(_SC_PAGE_SIZE);
    unsigned char * vec = my_malloc(sz);
    void* addr;
    mincore(addr, 1, vec);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
