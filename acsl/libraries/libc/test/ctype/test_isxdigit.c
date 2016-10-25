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
    isxdigit('1');
    isxdigit('a');
    isxdigit('\t');
    isxdigit(EOF);
    isxdigit(anychar());
}

void runFailure() {
    isxdigit(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isxdigit('1');
    //@ assert result != 0;
    result = isxdigit('0');
    //@ assert result != 0;
    result = isxdigit('9');
    //@ assert result != 0;
    result = isxdigit(' ');
    //@ assert result == 0;
    result = isxdigit('A');
    //@ assert result != 0;
    result = isxdigit('f');
    //@ assert result != 0;
    result = isxdigit('z');
    //@ assert result == 0;
    result = isxdigit('\t');
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


