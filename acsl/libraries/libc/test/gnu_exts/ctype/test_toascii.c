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

void runSuccess() {
    toascii('a');
    toascii('5');
    toascii('$');
    toascii('\0');
    toascii(EOF);
    toascii(anychar());
}

void runFailure() {
    toascii(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = toascii('a');
    //@ assert result == 'a';
    result = toascii('z');
    //@ assert result == 'z';
    result = toascii('%');
    //@ assert result == '%';
    result = toascii('\0');
    //@ assert result == '\0';
    result = toascii('Z');
    //@ assert result == 'Z';
    result = toascii('A');
    //@ assert result == 'A';
    result = toascii('G');
    //@ assert result == 'G';

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


