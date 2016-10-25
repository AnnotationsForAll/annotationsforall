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
    toupper_l('a', locale());
    toupper_l('5', locale());
    toupper_l('$', locale());
    toupper_l('\0', locale());
    toupper_l(EOF, locale());
    toupper_l(anychar(), locale());
}

void runFailure() {
    toupper_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = toupper_l('Z', locale());
    //@ assert result == 'Z';
    result = toupper_l('A', locale());
    //@ assert result == 'A';
    result = toupper_l('%', locale());
    //@ assert result == '%';
    result = toupper_l('\0', locale());
    //@ assert result == '\0';
    result = toupper_l('a', locale());
    //@ assert result == 'A';
    result = toupper_l('z', locale());
    //@ assert result == 'Z';
    result = toupper_l('G', locale());
    //@ assert result == 'G';

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


