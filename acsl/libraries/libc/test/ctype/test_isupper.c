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
    isupper('A');
    isupper('I');
    isupper('z');
    isupper('?');
    isupper(EOF);
    isupper(anychar());
}

void runFailure() {
    isupper(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    result = isupper('z');
    //@ assert result == 0;
    result = isupper('a');
    //@ assert result == 0;
    result = isupper('c');
    //@ assert result == 0;
    result = isupper(' ');
    //@ assert result == 0;
    result = isupper('A');
    //@ assert result != 0;
    result = isupper('Z');
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


