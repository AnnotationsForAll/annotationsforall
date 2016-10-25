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
    isalnum_l('a', locale());
    isalnum_l('z', locale());
    isalnum_l('A', locale());
    isalnum_l('Z', locale());
    isalnum_l('d', locale());
    isalnum_l('E', locale());
    isalnum_l('1', locale());
    isalnum_l('9', locale());
    isalnum_l('0', locale());
    isalnum_l(EOF, locale());
    isalnum_l(anychar(), locale());
}

void runFailure() {
    isalnum_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isalnum_l('a', locale());
    //@ assert result != 0;
    result = isalnum_l('z', locale());
    //@ assert result != 0;
    result = isalnum_l('A', locale());
    //@ assert result != 0;
    result = isalnum_l('Z', locale());
    //@ assert result != 0;
    result = isalnum_l('g', locale());
    //@ assert result != 0;
    result = isalnum_l('1', locale());
    //@ assert result != 0;
    result = isalnum_l('0', locale());
    //@ assert result != 0;
    result = isalnum_l('9', locale());
    //@ assert result != 0;
    result = isalnum_l('5', locale());
    //@ assert result != 0;
    result = isalnum_l('\t', locale());
    //@ assert result == 0;
    result = isalnum_l(' ', locale());
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


