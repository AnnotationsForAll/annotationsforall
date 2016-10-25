#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    get_current_dir_name();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    get_current_dir_name();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
