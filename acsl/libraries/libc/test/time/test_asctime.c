#include "../../test_common.h"
#include <time.h>

/*@
    predicate realisticTmStruct{L}(struct tm *tmPtr) =
        (-1900 < tmPtr->tm_year < 8100) && (0 <= tmPtr->tm_mon < 12) && (0 <= tmPtr->tm_wday < 7);
 */

/*@
assigns \result;
ensures \valid(\result);
ensures valid_tm(\result);
*/
extern struct tm * anytm();

/*@
assigns \result;
ensures \valid(\result);
ensures realisticTmStruct(\result);
*/
extern struct tm * realistictm();

void runSuccess() {
    asctime(anytm());
}

void runFailure() {
    asctime(NULL);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = asctime(realistictm());
    //@ assert \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

void testValues2() {
    before:
    f = 2;
    // Typical use for asctime
    time_t rawtime;
    time ( &rawtime );

    char *time;
    struct tm *tmptr = localtime( &rawtime );
    if (tmptr == NULL) {return;}

    time = asctime (tmptr);
    //@ assert realisticTmStruct(tmptr) ==> valid_string(time);
    //@ assert realisticTmStruct(tmptr) ==> strlen(time) >= 21;
    //@ assert realisticTmStruct(tmptr) ==> errno == \at(errno, before);

    if(tmptr != NULL) {
        tmptr->tm_year = INT_MAX;
        time = asctime (tmptr);
        //@ assert time == \null;
    }

    //@ assert frame_condition: f == 2;
    //@ assert vacuous: \false;
}
