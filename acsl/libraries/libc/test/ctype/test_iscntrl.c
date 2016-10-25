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
    iscntrl('a');
    iscntrl('Z');
    iscntrl('5');
    iscntrl('\r');
    iscntrl(EOF);
    iscntrl(anychar());
}

void runFailure() {
    iscntrl(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = iscntrl('\0');// Null terminator
    //@ assert result != 0;
    result = iscntrl('\a');// Bell / Alert
    //@ assert result != 0;
    result = iscntrl('\b');// backspace
    //@ assert result != 0;
    result = iscntrl('\r');// carriage return
    //@ assert result != 0;
    result = iscntrl('\n');// new line
    //@ assert result != 0;
    result = iscntrl(' ');
    //@ assert result == 0;
    result = iscntrl('6');
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


