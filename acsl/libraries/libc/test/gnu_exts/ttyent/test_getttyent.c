#include "../../../test_common.h"
#include <ttyent.h>

void runSuccess() {
    getttyent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    struct ttyent * result = getttyent();
    if (result) {
        //@ assert valid_read_string_or_null(result->ty_name);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
