#include "../../stdio_common.h"

void runSuccess() {
    char buf[] = "%s";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fprintf(file, buf, "Hello");
    }
}

void runFailure() {
    char buf[] = "%s";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    fprintf(NULL, buf, "Hello");
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fprintf(file, NULL, "Hello");
    }
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "%s";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fprintf(file, buf, "Hello");
    }
    //returns either the amt of bytes read or a negative value to indicate error.
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
