#include "../../stdio_common.h"

void runSuccess() {
    char buf[] = "BUF";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setvbuf(file, buf, _IOFBF, 3);
    }
}

void runSuccess1() {
    char buf[] = "BUF";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setvbuf(file, buf, _IOLBF, 1);
    }
}

void runSuccess2() {
    char buf[] = "BUF";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setvbuf(file, NULL, _IONBF, anysize());
    }
}

void runSuccess3() {
    char buf[] = "BUF";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setvbuf(file, buf, anyint(), 3);
    }
}

void runFailure() {
    char buf[] = "BUF";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setvbuf(file, buf, _IOFBF, 87); //size given is too high
    }
}

void runFailure1() {
    char buf[] = "BUF";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    setvbuf(NULL, buf, _IOLBF, 3);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char buf[] = "BUF";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = setvbuf(file, buf, _IOFBF, 3);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
