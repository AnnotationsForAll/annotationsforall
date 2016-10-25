#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    void* addr;
    off_t off;
    size_t len;
    int fd;
    posix_mem_offset(addr, anysize(), &off, &len, &fd);
}

void runFailure() {
    void* addr;
    off_t off;
    size_t len;
    int fd;
    posix_mem_offset(addr, anysize(), NULL, &len, &fd);
}

void runFailure1() {
    void* addr;
    off_t off;
    size_t len;
    int fd;
    posix_mem_offset(addr, anysize(), &off, NULL, &fd);
}

void runFailure2() {
    void* addr;
    off_t off;
    size_t len;
    int fd;
    posix_mem_offset(addr, anysize(), &off, &len, NULL);
}

int f;
void testValues() {
    f = 2;
    
    void* addr;
    off_t off;
    size_t len;
    int fd;
    posix_mem_offset(addr, anysize(), &off, &len, &fd);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
