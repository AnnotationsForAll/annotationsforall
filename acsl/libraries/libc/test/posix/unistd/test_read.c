#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[10];
    int fd = 1; // placeholder
    read(fd, buf, 10);
}

void runFailure() {
    char buf[10];
    int fd = 1; // placeholder
    read(fd, buf, 20);
}

void runFailure1() {
    int fd = 1; // placeholder
    read(fd, NULL, 20);
}

void runFailure2() {
    char buf[10];
    read(anyint(), buf, 10);
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    char buf[10];
    int fd = 1; // placeholder
    
    result = read(fd, buf, 10);
    //@ assert result >= -1;
    //@ assert result != -1 ==> \valid_read(buf+(0..result-1));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
