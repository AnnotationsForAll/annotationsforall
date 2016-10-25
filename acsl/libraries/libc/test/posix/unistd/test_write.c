#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[10];
    int fd = 1; // placeholder
    write(fd, buf, 10);
}

void runFailure() {
    char buf[10];
    int fd = 1; // placeholder
    write(fd, buf, 20);
}

void runFailure1() {
    int fd = 1; // placeholder
    write(fd, NULL, 20);
}

void runFailure2() {
    char buf[10];
    write(anyint(), buf, 10);
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    int fd = 1; // placeholder
    char buf[10];
    
    result = write(fd, buf, 10);
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
