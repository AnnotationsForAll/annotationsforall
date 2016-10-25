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
    tolower_l('a', locale());
    tolower_l('5', locale());
    tolower_l('$', locale());
    tolower_l('\0', locale());
    tolower_l(EOF, locale());
    tolower_l(anychar(), locale());
}

void runFailure() {
    tolower_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = tolower_l('a', locale());
    //@ assert result == 'a';
    result = tolower_l('z', locale());
    //@ assert result == 'z';
    result = tolower_l('%', locale());
    //@ assert result == '%';
    result = tolower_l('\0', locale());
    //@ assert result == '\0';
    result = tolower_l('Z', locale());
    //@ assert result == 'z';
    result = tolower_l('A', locale());
    //@ assert result == 'a';
    result = tolower_l('G', locale());
    //@ assert result == 'g';

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


