#include "../../../stdio_common.h"
#include <wchar.h>

void runSuccess() {
    int input;
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    //@ assert \valid(s1+(0..3));
    //@ assert \exists integer x; s1[x] == L'\0';
    wchar_t s2[4]; s2[0] = L'B'; s2[1] = L'B'; s2[2] = L'B'; s2[3] = L'\0';
    //@ assert \valid(s2+(0..3));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    swscanf(s1, s2, &input);
}

void runFailure() {
    int input;
    wchar_t s2[4]; s2[0] = L'A'; s2[1] = L'A'; s2[2] = L'A'; s2[3] = L'\0';
    //@ assert \valid(s2+(0..3));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    swscanf(NULL, s2, &input);
}

void runFailure1() {
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    //@ assert \valid(s1+(0..3));
    //@ assert \exists integer x; s1[x] == L'\0';
    swscanf(s1, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    int input;
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    //@ assert \valid(s1+(0..3));
    //@ assert \exists integer x; s1[x] == L'\0';
    wchar_t s2[4]; s2[0] = L'B'; s2[1] = L'B'; s2[2] = L'B'; s2[3] = L'\0';
    //@ assert \valid(s2+(0..3));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    result = swscanf(s1, s2, &input);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
