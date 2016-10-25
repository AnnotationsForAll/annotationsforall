#include "../../../test_common.h"
#include <ctype.h>
#include <limits.h>

void runSuccess() {
    isascii(INT_MIN);
    isascii(0);
    isascii(INT_MAX);
    isascii('a');
}

void runFailure() {
    // Defined on all inputs
}

int f;
void testValues() {
    f = 2;
    int result;
    result = isascii('a');
    //@ assert result != 0;
    result = isascii('z');
    //@ assert result != 0;
    result = isascii('A');
    //@ assert result != 0;
    result = isascii('Z');
    //@ assert result != 0;
    result = isascii('#');
    //@ assert result != 0;
    result = isascii('\0');
    //@ assert result != 0;
    result = isascii('0');
    //@ assert result != 0;
    result = isascii('\t');
    //@ assert result != 0;
    result = isascii(' ');
    //@ assert result != 0;
    result = isascii(((int)UCHAR_MAX)+1);
    //@ assert result == 0;
    result = isascii(-1);
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


