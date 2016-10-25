#include "../../../test_common.h"
#include <regex.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern regex_t * anyregex();

void runSuccess() {
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());

    regfree(&preg);
}

void runFailure() {
    regfree(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());
    
    regfree(&preg);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
