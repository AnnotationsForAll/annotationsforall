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
    islower_l('a', locale());
    islower_l('j', locale());
    islower_l('z', locale());
    islower_l('Z', locale());
    islower_l('1', locale());
    islower_l('#', locale());
    islower_l(EOF, locale());
    islower_l(anychar(), locale());
}

void runFailure() {
    islower_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = islower_l('z', locale());
    //@ assert result != 0;
    result = islower_l('a', locale());
    //@ assert result != 0;
    result = islower_l('h', locale());
    //@ assert result != 0;
    result = islower_l(' ', locale());
    //@ assert result == 0;
    result = islower_l('A', locale());
    //@ assert result == 0;
    result = islower_l('Z', locale());
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


