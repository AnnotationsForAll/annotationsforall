#include "../../stdio_common.h"

void runSuccess() {
    int input;
    char buf[] = "%i";
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        //@ assert \valid(buf+(0..\block_length(buf)-1));
        //@ assert \exists integer x; buf[x] == '\0';
        fscanf(file, buf, &input);
    }
}

void runFailure() {
    int input;
    char buf[] = "%i";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    fscanf(NULL, buf, &input);
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fscanf(file, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    int result;
    int input;
    char buf[] = "%i";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fscanf(file, buf, &input);
        //@ assert result >= 0 || result == EOF;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
