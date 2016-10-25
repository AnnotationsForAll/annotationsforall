#include "../../../test_common.h"
#include <wchar.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern mbstate_t* anystate();

char str[MB_CUR_MAX];

void runSuccess() {
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    //@ assert \valid(s1+(0..3));
    wcsrtombs(str, s1, 3, anystate());
}

void runFailure() {
    wcsrtombs(NULL, NULL, anysize(), anystate());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    wchar_t s1[4]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'A'; s1[3] = L'\0';
    //@ assert \valid(s1+(0..3));
    wcsrtombs(str, s1, 3, anystate());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
