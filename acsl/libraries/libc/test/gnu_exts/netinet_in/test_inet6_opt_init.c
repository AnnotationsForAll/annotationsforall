#include "../../../test_common.h"
#include <netinet/in.h>

/*@
assigns \result;
ensures \valid(\result+(0..size-1));
*/
char* my_malloc(int size);

void runSuccess() {
    int len = inet6_opt_init(NULL, anyint());
    char* bp = my_malloc(len);
    inet6_opt_init(bp, len);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int result;
    char* bp;
    int len = inet6_opt_init(NULL, anyint());

    bp = my_malloc(len);
    result = inet6_opt_init(bp, len);
    //@ assert result != -1 ==> result == len;

    bp = my_malloc(len-1);
    result = inet6_opt_init(bp, len-1);
    //@ assert result == -1;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
