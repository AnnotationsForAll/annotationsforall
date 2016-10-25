#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    hypotl(1.0L, 1.0L);
    hypotl(1.0L, 0.0L);
    hypotl(8.3L, 5.0L);
    hypotl(0.0L, 121.1L);
    hypotl(anylongdouble(), anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    double x,y;
    
    hypotl(anylongdouble(), anylongdouble());
    
    //x = anylongdouble();
    //y = anylongdouble();
    //result = hypotl(x,y);
    // assert result == \sqrt(\pow(x,2)+\pow(y,2));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
