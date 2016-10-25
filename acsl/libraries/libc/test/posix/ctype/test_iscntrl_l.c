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
    iscntrl_l('a', locale());
    iscntrl_l('Z', locale());
    iscntrl_l('5', locale());
    iscntrl_l('\r', locale());
    iscntrl_l(EOF, locale());
    iscntrl_l(anychar(), locale());
}

void runFailure() {
    iscntrl_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = iscntrl_l('\0', locale());// Null terminator
    //@ assert result != 0;
    result = iscntrl_l('\a', locale());// Bell / Alert
    //@ assert result != 0;
    result = iscntrl_l('\b', locale());// backspace
    //@ assert result != 0;
    result = iscntrl_l('\r', locale());// carriage return
    //@ assert result != 0;
    result = iscntrl_l('\n', locale());// new line
    //@ assert result != 0;
    result = iscntrl_l(' ', locale());
    //@ assert result == 0;
    result = iscntrl_l('6', locale());
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


