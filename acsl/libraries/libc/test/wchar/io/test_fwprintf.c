#include "../../../stdio_common.h"
#include <wchar.h>

void runSuccess() {
    char s2[] = "Hello";
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    //@ assert \valid(s1+(0..3));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwprintf(file, s1, s2);
    }
}

void runFailure() {
    char s2[] = "Hello";
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    //@ assert \valid(s1+(0..3));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    fwprintf(NULL, s1, s2);
}

void runFailure1() {
    char s2[] = "Hello";

    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwprintf(file, NULL, s2);
    }
}

int f;
void testValues() {
    f = 2;
    int result;
    char s2[] = "Hello";
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    //@ assert \valid(s1+(0..3));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fwprintf(file, s1, s2);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
