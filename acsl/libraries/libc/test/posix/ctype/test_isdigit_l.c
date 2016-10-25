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
    isdigit_l('1', locale());
    isdigit_l('9', locale());
    isdigit_l('0', locale());
    isdigit_l('q', locale());
    isdigit_l('*', locale());
    isdigit_l(EOF, locale());
    isdigit_l(anychar(), locale());
}

void runFailure() {
    isdigit_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    result = isdigit_l('1', locale());
    //@ assert result != 0;
    result = isdigit_l('0', locale());
    //@ assert result != 0;
    result = isdigit_l('9', locale());
    //@ assert result != 0;
    result = isdigit_l(' ', locale());
    //@ assert result == 0;
    result = isdigit_l('A', locale());
    //@ assert result == 0;
    result = isdigit_l('z', locale());
    //@ assert result == 0;
    result = isdigit_l('\t', locale());
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


