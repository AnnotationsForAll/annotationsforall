#include "../../../test_common.h"
#include <wchar.h>
#include <errno.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern mbstate_t* anystate();

void runSuccess() {
    char s1[] = "AAAA";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    mbrlen(s1, 3, anystate());
    mbrlen(s1, 4, NULL);
}

void runFailure() {
    mbrlen(NULL, anysize(), anystate());
}

int f;
void testValues() {
    f = 2;
    size_t result;
    
    char s1[] = "AAAA";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = mbrlen(s1, 4, anystate());
    //@ assert  0 <= result <= 4 || result == (size_t)(-1) || result == (size_t)(-2);
    //@ assert result == (size_t)(-1) ==> errno != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
