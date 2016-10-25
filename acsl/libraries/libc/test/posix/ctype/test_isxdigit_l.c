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
    isxdigit_l('1', locale());
    isxdigit_l('a', locale());
    isxdigit_l('\t', locale());
    isxdigit_l(EOF, locale());
    isxdigit_l(anychar(), locale());
}

void runFailure() {
    isxdigit_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isxdigit_l('1', locale());
    //@ assert result != 0;
    result = isxdigit_l('0', locale());
    //@ assert result != 0;
    result = isxdigit_l('9', locale());
    //@ assert result != 0;
    result = isxdigit_l(' ', locale());
    //@ assert result == 0;
    result = isxdigit_l('A', locale());
    //@ assert result != 0;
    result = isxdigit_l('f', locale());
    //@ assert result != 0;
    result = isxdigit_l('z', locale());
    //@ assert result == 0;
    result = isxdigit_l('\t', locale());
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


