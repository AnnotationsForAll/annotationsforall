#include "../../../unistd_common.h"
#include <stdio.h>

void runSuccess() {
    char buf[] = "r";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    int fd = VALID_FD;
    if (fd != -1) {
        fdopen(fd, buf);
    }
}

void runSuccess1() {
    char buf[] = "ab";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    int fd = VALID_FD;
    if (fd != -1) {
        fdopen(fd, buf);
    }
}

void runSuccess2() {
    char buf[] = "w+";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    int fd = VALID_FD;
    if (fd != -1) {
        fdopen(fd, buf);
    }
}

void runSuccess3() {
    char buf[] = "rb+";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    int fd = VALID_FD;
    if (fd != -1) {
        fdopen(fd, buf);
    }
}

void runSuccess4() {
    char buf[] = "r+b";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    int fd = VALID_FD;
    if (fd != -1) {
        fdopen(fd, buf);
    }
}

/*void runFailure() {
    char buf[] = "$";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    int fd = VALID_FD;
    if (fd != -1) {
        fdopen(fd, buf);
    }
}*/

void runFailure1() {
    int fd = VALID_FD;
    if (fd != -1) {
        fdopen(fd, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    FILE* result;
    char buf[] = "r";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    int fd = VALID_FD;
    if (fd != -1) {
        result = fdopen(fd, buf);
        //@ assert result == \null || \valid(result);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
