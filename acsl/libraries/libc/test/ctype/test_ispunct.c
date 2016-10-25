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
    ispunct('a');
    ispunct('5');
    ispunct('$');
    ispunct('\0');
    ispunct(EOF);
    ispunct(anychar());
}

void runFailure() {
    ispunct(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = ispunct('a');
    //@ assert result == 0;
    result = ispunct('5');
    //@ assert result == 0;
    result = ispunct(' ');
    //@ assert result == 0;
    result = ispunct('\t');
    //@ assert result == 0;
    result = ispunct('!');
    //@ assert result != 0;
    result = ispunct('#');
    //@ assert result != 0;
    result = ispunct('.');
    //@ assert result != 0;
    result = ispunct('?');
    //@ assert result != 0;
    result = ispunct(',');
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


