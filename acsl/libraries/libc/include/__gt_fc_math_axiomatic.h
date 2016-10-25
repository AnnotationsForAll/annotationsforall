#ifndef LIBC___GT_FC_MATH_AXIOMATIC_H_
#define LIBC___GT_FC_MATH_AXIOMATIC_H_

#include "float.h"

// TODO: remove and replace with built-ins once implemented
/*@

    // finites are defined as bounded between the largest and smallest representable numbers of the type.
    // NaN, +INF, and -INF are defined as some (unknown) value.
    // Any number can only be one of: finite, +INF, -INF, NaN

    axiomatic NaN_INF {
        logic boolean is_NaN_dbl(double x);
        logic boolean is_NaN_float(float x);
        logic boolean is_positive_inf_dbl(double x);
        logic boolean is_positive_inf_float(float x);
        logic boolean is_negative_inf_dbl(double x);
        logic boolean is_negative_inf_float(float x);

        logic boolean is_finite_dbl(double x) = (-DBL_MAX <= x <= DBL_MAX);
        logic boolean is_finite_float(float x) = (-FLT_MAX <= x <= FLT_MAX);

        logic boolean is_inf_dbl(double x) = is_positive_inf_dbl(x) || is_negative_inf_dbl(x);
        logic boolean is_inf_float(float x) = is_positive_inf_float(x) || is_negative_inf_float(x);

        // finite, NaN, positive INF, and negative INF are mutually exclusive
        // But does not guarantee every float/double is one of these

        axiom unique_dbl_1: \forall double x; is_finite_dbl(x) ==> (!is_NaN_dbl(x) && !is_positive_inf_dbl(x) && !is_negative_inf_dbl(x));
        axiom unique_dbl_2: \forall double x; is_NaN_dbl(x) ==> (!is_positive_inf_dbl(x) && !is_negative_inf_dbl(x) && !is_finite_dbl(x));
        axiom unique_dbl_3: \forall double x; is_positive_inf_dbl(x) ==> (!is_NaN_dbl(x) && !is_negative_inf_dbl(x) && !is_finite_dbl(x));
        axiom unique_dbl_4: \forall double x; is_negative_inf_dbl(x) ==> (!is_NaN_dbl(x) && !is_positive_inf_dbl(x) && !is_finite_dbl(x));

        axiom unique_float_1: \forall float x; is_finite_float(x) ==> (!is_NaN_float(x) && !is_positive_inf_float(x) && !is_negative_inf_float(x));
        axiom unique_float_2: \forall float x; is_NaN_float(x) ==> (!is_positive_inf_float(x) && !is_negative_inf_float(x) && !is_finite_float(x));
        axiom unique_float_3: \forall float x; is_positive_inf_float(x) ==> (!is_NaN_float(x) && !is_negative_inf_float(x) && !is_finite_float(x));
        axiom unique_float_4: \forall float x; is_negative_inf_float(x) ==> (!is_NaN_float(x) && !is_positive_inf_float(x) && !is_finite_float(x));

        axiom inf_negation_dbl_1: \forall double x; is_positive_inf_dbl(x) ==> is_negative_inf_dbl((double)-x);
        axiom inf_negation_dbl_2: \forall double x; is_negative_inf_dbl(x) ==> is_positive_inf_dbl((double)-x);
        axiom inf_negation_float_1: \forall float x; is_positive_inf_float(x) ==> is_negative_inf_float((float)-x);
        axiom inf_negation_float_2: \forall float x; is_negative_inf_float(x) ==> is_positive_inf_float((float)-x);
    }
 */

/*
The following functions are used to represent HUGE_VAL.
These functions need to exist both as C declarations, and as logic functions.
This is because some functions need to ensure they return exactly HUGE_VAL in annotations,
and HUGE_VAL needs to remain a macro usable by both C and ACSL.

The argument "x" is a dummy, not used in the logic. This is so the function can exist as both a C and ACSL function;
ACSL logic functions cannot take zero arguments.
*/

/*@
axiomatic HugeVals {
    logic double __gt_fc_huge_val(integer x);
    axiom define_huge_val: \forall integer x; is_positive_inf_dbl(__gt_fc_huge_val(x));

    logic float __gt_fc_huge_valf(integer x);
    axiom define_huge_valf: \forall integer x; is_positive_inf_float(__gt_fc_huge_valf(x));
}
*/

/*@
assigns \result \from \nothing;
ensures \result == __gt_fc_huge_val(0);
*/
double __gt_fc_huge_val(int x);

/*@
assigns \result \from \nothing;
ensures \result == __gt_fc_huge_valf(0);
*/
float __gt_fc_huge_valf(int x);

/*@
assigns \result \from \nothing;
*/
long double __gt_fc_huge_vall(int x);

/*
These functions are used to represent the floor and ceiling functions.
Due to a bug in Frama-C ( https://bts.frama-c.com/view.php?id=2241 ), these are not working properly.
TODO: Make a fix?
*/

/*@
axiomatic RoundFuncs {
    logic real fpart(real x);
    logic integer ipart(real x);
    logic integer floor(real x) = ipart(x);
    logic integer ceil(real x);

    axiom fpart_1: \forall real x; 0 >= fpart(x) > 1;
    axiom fpart_2: \forall real x; fpart(x) == x - ipart(x);
    axiom fpart_3: \forall integer x; fpart(x) == 0;

    axiom ipart_1: \forall real x; x <= ipart(x) < x + 1;
    axiom ipart_2: \forall real x; ipart(x) + fpart(x) == x;
    axiom ipart_3: \forall integer x; ipart(x) == x;

    axiom ceil_1: \forall real x; x == ipart(x) <==> ceil(x) == x;
    axiom ceil_2: \forall real x; x != ipart(x) <==> ceil(x) == x + 1;
}
*/

#endif /* LIBC___GT_FC_MATH_AXIOMATIC_H_ */
