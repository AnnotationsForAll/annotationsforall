#include "../../stdio_common.h"

void runSuccess() {
    char s1[] = "file";
    char s2[] = "r";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        freopen(s1, s2, file);
    }
}

void runSuccess1() {
    char s1[] = "file";
    char s2[] = "ab";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        freopen(s1, s2, file);
    }
}

void runSuccess2() {
    char s1[] = "file";
    char s2[] = "w+";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        freopen(s1, s2, file);
    }
}

void runSuccess3() {
    char s1[] = "file";
    char s2[] = "rb+";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        freopen(s1, s2, file);
    }
}

void runSuccess4() {
    char s1[] = "file";
    char s2[] = "r+b";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        freopen(s1, s2, file);
    }
}

/*void runFailure() {
    char s1[] = "file";
    char s2[] = "$";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        freopen(s1, s2, file);
    }
}*/

void runFailure1() {
    char s2[] = "$";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        freopen(NULL, s2, file);
    }
}

void runFailure2() {
    char s1[] = "file";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        freopen(s1, NULL, file);
    }
}

void runFailure3() {
    char s1[] = "file";
    char s2[] = "$";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    freopen(s1, s2, NULL);
}

int f;
void testValues() {
    f = 2;
    FILE* result;
    char s1[] = "file";
    char s2[] = "r";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = freopen(s1, s2, file);
        //@ assert result == \null || \valid(result);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
