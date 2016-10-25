#include "../../../test_common.h"
#include <stdlib.h>
#include <wchar.h>

wchar_t* ptr;

void runSuccess() {
    wchar_t s1[3]; s1[0] = L'1'; s1[1] = L'.'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcstold(s1, &ptr);
}

void runSuccess1() {
    wchar_t s1[3]; s1[0] = L'1'; s1[1] = L'.'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcstold(s1, NULL);
}

void runFailure() {
    wcstold(NULL, &ptr);
}

void runFailure1() {
    wcstold(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    wchar_t s1[3]; s1[0] = L'1'; s1[1] = L'.'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    result = wcstold(s1, &ptr);
    // assert \subset(ptr,str+(0..4));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
