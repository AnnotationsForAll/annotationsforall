#include "../../test_common.h"
#include <inttypes.h>

void runSuccess() {
    wchar_t buf[3]; buf[0] = L'1'; buf[1] = L'1'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    wchar_t* ptr;

   wcstoimax(buf, &ptr, 0);
}

void runSuccess1() {
    wchar_t buf[3]; buf[0] = L'1'; buf[1] = L'1'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    wchar_t* ptr;

   wcstoimax(buf, &ptr, 10);
}

void runSuccess2() {
    wchar_t buf[3]; buf[0] = L'1'; buf[1] = L'1'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';

   wcstoimax(buf, NULL, 0);
}

void runFailure() {
    wchar_t* ptr;

    wcstoimax(NULL, &ptr, 0);
}

void runFailure1() {
    wcstoimax(NULL, NULL, 10);
}

int f;
void testValues() {
    f = 2;
    intmax_t result;
    wchar_t buf[3]; buf[0] = L'1'; buf[1] = L'1'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    wchar_t* ptr;
    
    result = wcstoimax(buf, &ptr, 0);
    //@ assert \valid(ptr);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
