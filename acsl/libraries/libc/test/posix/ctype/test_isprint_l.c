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
    isprint_l('a', locale());
    isprint_l('Z', locale());
    isprint_l('5', locale());
    isprint_l('\r', locale());
    isprint_l(EOF, locale());
    isprint_l(anychar(), locale());
}

void runFailure() {
    isprint_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isprint_l('a', locale());
    //@ assert result != 0;
    result = isprint_l('5', locale());
    //@ assert result != 0;
    result = isprint_l('Z', locale());
    //@ assert result != 0;
    result = isprint_l(' ', locale());
    //@ assert result != 0;
    result = isprint_l('\t', locale());
    //@ assert result == 0;
    result = isprint_l('#', locale());
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


