#include "../../../test_common.h"
#include <printf.h>

void runSuccess() {
    int args[] = {anyint(), anyint()};
    char s[] = "s";

    parse_printf_format(s, 2, args);
}

void runSuccess1() {
    char s[] = "s";

    parse_printf_format(s, 0, NULL);
}

void runFailure() {
    int args[] = {anyint(), anyint()};

    parse_printf_format(NULL, 2, args);
}

void runFailure1() {
    char s[] = "s";

    parse_printf_format(s, 2, NULL);
}

int f;
void testValues() {
    f = 2;
    
    int args[] = {anyint(), anyint(), 47};
    char s[] = "s";

    parse_printf_format(s, 2, args);
    //@ assert args[2] == 47;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
