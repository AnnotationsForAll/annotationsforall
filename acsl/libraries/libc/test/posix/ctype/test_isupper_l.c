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
    isupper_l('A', locale());
    isupper_l('I', locale());
    isupper_l('z', locale());
    isupper_l('?', locale());
    isupper_l(EOF, locale());
    isupper_l(anychar(), locale());
}

void runFailure() {
    isupper_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    result = isupper_l('z', locale());
    //@ assert result == 0;
    result = isupper_l('a', locale());
    //@ assert result == 0;
    result = isupper_l('c', locale());
    //@ assert result == 0;
    result = isupper_l(' ', locale());
    //@ assert result == 0;
    result = isupper_l('A', locale());
    //@ assert result != 0;
    result = isupper_l('Z', locale());
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


