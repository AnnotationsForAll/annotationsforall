#include "../../../test_common.h"
#include <ctype.h>
#include <stdio.h>


/*@
assigns \result;
*/
extern unsigned char anychar();
/*@
assigns \result;
ensures (unsigned char)\result != \result && \result != EOF;
*/
extern int invalid();

/*@
assigns \result;
*/
extern locale_t locale();

void runSuccess() {
    isspace_l('a', locale());
    isspace_l('\t', locale());
    isspace_l(EOF, locale());
    isspace_l(anychar(), locale());
}

void runFailure() {
    isspace_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isspace_l('z', locale());
    //@ assert result == 0;
    result = isspace_l(' ', locale());
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


