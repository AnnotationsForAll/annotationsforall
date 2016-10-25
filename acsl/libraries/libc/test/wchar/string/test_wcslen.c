#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcslen(s1);
}

void runSuccess1() {
    wchar_t s1[1]; s1[0] = L'\0';
    //@ assert \valid(s1);
    //@ assert \exists integer x; s1[x] == L'\0';
    wcslen(s1);
}

void runFailure() {
    wcslen(NULL);
}

void testValues() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    size_t result = wcslen(s1);
    //@ assert result == 2;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    wchar_t s1[1]; s1[0] = L'\0';
    //@ assert \valid(s1);
    //@ assert \exists integer x; s1[x] == L'\0';
    
    size_t result = wcslen(s1);
    //@ assert result == 0;
    
    //@ assert vacuous: \false;
}

void testValues2() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'\0'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    size_t result = wcslen(s1);
    //@ assert result == 1;
    
    //@ assert vacuous: \false;
}
