#include "../../../test_common.h"
#include <math.h>

int expv;

/*@
predicate is_power_of_2(integer x) = \exists integer y; y >= -1 && \pow(2, y) == x;
*/
/*@
    // Proves
    lemma finite_not_nan:
        \forall float x; is_finite_float(x) ==> !is_NaN_float(x);
 */

void runSuccess() {
    float val = 1.0f;
    //@ assert is_finite_float(val);
    //@ assert is_finite_float(val) ==> !is_NaN_float(val); // Instantiation of lemma finite_not_nan | x:=val
    frexpf(val, &expv);
}

void runSuccess2() {
    float val = 0.0f;
    //@ assert is_finite_float(val);
    //@ assert is_finite_float(val) ==> !is_NaN_float(val); // Instantiation of lemma finite_not_nan | x:=val
    frexpf(val, &expv);
}

void runSuccess3() {
    float val =  -1.0f;
    //@ assert is_finite_float(val);
    //@ assert is_finite_float(val) ==> !is_NaN_float(val); // Instantiation of lemma finite_not_nan | x:=val
    frexpf(val, &expv);
}

void runSuccess4() {
    float val = val = INFINITY;
    //@ assert !is_NaN_float(val);
    frexpf(val, &expv);
}

void runFailure() {
    frexpf(0.0f, NULL);
}

void runFailure1() {
    frexpf(anyfloat(), NULL);
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = frexpf(1.0f, &expv);
    // assert .5 <= \abs(result) < 1;
    //result = frexpf(1.5f, &expv);
    // assert result * \pow(2, expv) == 1.5
    result = frexpf(0.0f, &expv);
    //@ assert result == 0 && expv == 0;
    //result = frexpf(anyfloat(), &expv);
    // assert is_power_of_2(expv);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
