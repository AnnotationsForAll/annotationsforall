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
    isalpha('a');
    isalpha('z');
    isalpha('A');
    isalpha('Z');
    isalpha('d');
    isalpha('E');
    isalpha(EOF);
    isalpha(anychar());
}

void runFailure() {
    isalpha(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isalpha('a');
    //@ assert result != 0;
    result = isalpha('z');
    //@ assert result != 0;
    result = isalpha('A');
    //@ assert result != 0;
    result = isalpha('Z');
    //@ assert result != 0;
    result = isalpha('g');
    //@ assert result != 0;
    result = isalpha('5');
    //@ assert result == 0;
    result = isalpha('\t');
    //@ assert result == 0;
    result = isalpha(' ');
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


