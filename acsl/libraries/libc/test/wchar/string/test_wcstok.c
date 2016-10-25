#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    wcstok(s1, s2);
}

void runSuccess1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcstok(NULL, s1);
}

void runFailure() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcstok(s1, NULL);
}

void runFailure1() {
    wcstok(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    wchar_t* result;
    
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    result = wcstok(s1, s2);
    // assert result == \null || \subset(result,s1+(0..6));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
