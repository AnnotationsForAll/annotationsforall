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
    ispunct_l('a', locale());
    ispunct_l('5', locale());
    ispunct_l('$', locale());
    ispunct_l('\0', locale());
    ispunct_l(EOF, locale());
    ispunct_l(anychar(), locale());
}

void runFailure() {
    ispunct_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = ispunct_l('a', locale());
    //@ assert result == 0;
    result = ispunct_l('5', locale());
    //@ assert result == 0;
    result = ispunct_l(' ', locale());
    //@ assert result == 0;
    result = ispunct_l('\t', locale());
    //@ assert result == 0;
    result = ispunct_l('!', locale());
    //@ assert result != 0;
    result = ispunct_l('#', locale());
    //@ assert result != 0;
    result = ispunct_l('.', locale());
    //@ assert result != 0;
    result = ispunct_l('?', locale());
    //@ assert result != 0;
    result = ispunct_l(',', locale());
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


