#include "../../stdio_common.h"

void runSuccess() {
    char buf[] = "Hi";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fputs(buf, file);
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fputs(NULL, file);
    }
}

void runFailure1() {
    char buf[] = "Hi";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    fputs(buf, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "Hi";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fputs(buf, file);
        //@ assert result >= 0 || result == EOF;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
