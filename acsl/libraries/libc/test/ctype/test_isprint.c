#include "../../test_common.h"
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

void runSuccess() {
    isprint('a');
    isprint('Z');
    isprint('5');
    isprint('\r');
    isprint(EOF);
    isprint(anychar());
}

void runFailure() {
    isprint(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isprint('a');
    //@ assert result != 0;
    result = isprint('5');
    //@ assert result != 0;
    result = isprint('Z');
    //@ assert result != 0;
    result = isprint(' ');
    //@ assert result != 0;
    result = isprint('\t');
    //@ assert result == 0;
    result = isprint('#');
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


