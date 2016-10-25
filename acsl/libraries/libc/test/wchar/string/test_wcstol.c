#include "../../../test_common.h"
#include <stdlib.h>
#include <wchar.h>

wchar_t* ptr;

void runSuccess() {
    wchar_t s1[3]; s1[0] = L'1'; s1[1] = L'0'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
   wcstol(s1, &ptr, 0);
}

void runSuccess1() {
    wchar_t s1[3]; s1[0] = L'1'; s1[1] = L'0'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
   wcstol(s1, NULL, 10);
}

void runFailure() {
    wcstol(NULL, &ptr, 0);
}

void runFailure1() {
    wcstol(NULL, NULL, 10);
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    wchar_t s1[3]; s1[0] = L'1'; s1[1] = L'0'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    result = wcstol(s1, &ptr, 0);
    // assert \subset(ptr,wcs+(0..4));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
