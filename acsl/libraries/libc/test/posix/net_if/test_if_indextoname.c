#include "../../../test_common.h"
#include <net/if.h>

void runSuccess() {
    char buf[IF_NAMESIZE];
    if_indextoname(anyuint(), buf);
}

void runFailure() {
    if_indextoname(anyuint(), NULL);
}

void runFailure1() {
    char buf[1];
    if_indextoname(anyuint(), buf);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[IF_NAMESIZE];
    
    result = if_indextoname(anyuint(), buf);
    //@ assert result == \null || result == buf;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
