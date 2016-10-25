#include "../../../test_common.h"
#include <netinet/in.h>

void runSuccess() {
    inet6_option_space(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int result = inet6_option_space(anyint());
    //@ assert result > 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
