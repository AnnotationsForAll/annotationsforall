#include "../../../test_common.h"
#include <math.h>

int expv;

/*@
predicate is_power_of_2(integer x) = \exists integer y; y >= -1 && \pow(2, y) == x;
*/

/*@
    // Proves
    lemma finite_not_nan:
        \forall double x; is_finite_dbl(x) ==> !is_NaN_dbl(x);
 */

void runSuccess() {
    double val = 1.0;
    //@ assert is_finite_dbl(val);
    //@ assert is_finite_dbl(val) ==> !is_NaN_dbl(val); // Instantiation of lemma finite_not_nan with x:=val
    frexp(val, &expv);
}

void runSuccess2() {
    double val = 0.0;
    //@ assert is_finite_dbl(val);
    //@ assert is_finite_dbl(val) ==> !is_NaN_dbl(val); // Instantiation of lemma finite_not_nan with x:=val
    frexp(val, &expv);
}

void runSuccess3() {
    double val = -1.0;
    //@ assert is_finite_dbl(val);
    //@ assert is_finite_dbl(val) ==> !is_NaN_dbl(val); // Instantiation of lemma finite_not_nan with x:=val
    frexp(val, &expv);
}

void runFailure() {
    double val = 0.0;
    //@ assert is_finite_dbl(val);
    //@ assert is_finite_dbl(val) ==> !is_NaN_dbl(val); // Instantiation of lemma finite_not_nan with x:=val
    frexp(val, NULL);
}

void runFailure1() {
    frexp(anydouble(), NULL);
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = frexp(1.0, &expv);
    // assert .5 <= \abs(result) < 1;
    //result = frexp(1.5, &expv);
    // assert result * \pow(2, expv) == 1.5
    result = frexp(0.0, &expv);
    //@ assert result == 0 && expv == 0;
    //result = frexp(anydouble(), &expv);
    // assert is_power_of_2(expv);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
