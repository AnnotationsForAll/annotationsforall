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
    isalpha_l('a', locale());
    isalpha_l('z', locale());
    isalpha_l('A', locale());
    isalpha_l('Z', locale());
    isalpha_l('d', locale());
    isalpha_l('E', locale());
    isalpha_l(EOF, locale());
    isalpha_l(anychar(), locale());
}

void runFailure() {
    isalpha_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isalpha_l('a', locale());
    //@ assert result != 0;
    result = isalpha_l('z', locale());
    //@ assert result != 0;
    result = isalpha_l('A', locale());
    //@ assert result != 0;
    result = isalpha_l('Z', locale());
    //@ assert result != 0;
    result = isalpha_l('g', locale());
    //@ assert result != 0;
    result = isalpha_l('5', locale());
    //@ assert result == 0;
    result = isalpha_l('\t', locale());
    //@ assert result == 0;
    result = isalpha_l(' ', locale());
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


