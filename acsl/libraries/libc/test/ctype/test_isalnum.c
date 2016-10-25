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
    isalnum('a');
    isalnum('z');
    isalnum('A');
    isalnum('Z');
    isalnum('d');
    isalnum('E');
    isalnum('1');
    isalnum('9');
    isalnum('0');
    isalnum(EOF);
    isalnum(anychar());
}

void runFailure() {
    isalnum(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isalnum('a');
    //@ assert result != 0;
    result = isalnum('z');
    //@ assert result != 0;
    result = isalnum('A');
    //@ assert result != 0;
    result = isalnum('Z');
    //@ assert result != 0;
    result = isalnum('g');
    //@ assert result != 0;
    result = isalnum('1');
    //@ assert result != 0;
    result = isalnum('0');
    //@ assert result != 0;
    result = isalnum('9');
    //@ assert result != 0;
    result = isalnum('5');
    //@ assert result != 0;
    result = isalnum('\t');
    //@ assert result == 0;
    result = isalnum(' ');
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


