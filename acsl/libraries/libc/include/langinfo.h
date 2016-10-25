/*
 * langinfo.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_LANGINFO_H_
#define LIBC_LANGINFO_H_

#include "nl_types.h"
#include "locale.h"

#define ABDAY_1            0
#define ABDAY_2            1
#define ABDAY_3            2
#define ABDAY_4            3
#define ABDAY_5            4
#define ABDAY_6            5
#define ABDAY_7            6
#define DAY_1              7
#define DAY_2              8
#define DAY_3              9
#define DAY_4              10
#define DAY_5              11
#define DAY_6              12
#define DAY_7              13
#define ABMON_1            14
#define ABMON_2            15
#define ABMON_3            16
#define ABMON_4            17
#define ABMON_5            18
#define ABMON_6            19
#define ABMON_7            20
#define ABMON_8            21
#define ABMON_9            22
#define ABMON_10           23
#define ABMON_11           24
#define ABMON_12           25
#define MON_1              26
#define MON_2              27
#define MON_3              28
#define MON_4              29
#define MON_5              30
#define MON_6              31
#define MON_7              32
#define MON_8              33
#define MON_9              34
#define MON_10             35
#define MON_11             36
#define MON_12             37
#define AM_STR             38
#define PM_STR             39
#define D_T_FMT            40
#define D_FMT              41
#define T_FMT              42
#define T_FMT_AMPM         43
#define ERA                44
#define ERA_YEAR           45
#define ERA_D_FMT          46
#define ALT_DIGITS         47
#define ERA_D_T_FMT        48
#define ERA_T_FMT          49
#define _DATE_FMT          50
#define CODESET            51
#define INT_CURR_SYMBOL    52
#define CURRENCY_SYMBOL    53
#define MON_DECIMAL_POINT  54
#define MON_THOUSANDS_SEP  55
#define MON_GROUPING       56
#define POSITIVE_SIGN      57
#define NEGATIVE_SIGN      58
#define INT_FRAC_DIGITS    59
#define FRAC_DIGITS        60
#define P_CS_PRECEDES      61
#define P_SEP_BY_SPACE     62
#define N_CS_PRECEDES      63
#define N_SEP_BY_SPACE     64
#define P_SIGN_POSN        65
#define N_SIGN_POSN        66
#define CRNCYSTR           67
#define INT_P_CS_PRECEDES  68
#define INT_P_SEP_BY_SPACE 69
#define INT_N_CS_PRECEDES  70
#define INT_N_SEP_BY_SPACE 71
#define INT_P_SIGN_POSN    72
#define INT_N_SIGN_POSN    73
#define DECIMAL_POINT      74
#define RADIXCHAR          75
#define THOUSANDS_SEP      76
#define GROUPING           77
#define YESEXPR            78
#define NOEXPR             79
#define YESSTR             80
#define NOSTR              81

/*@
assigns \result \from item;
ensures \valid(\result);
*/
char *nl_langinfo(nl_item item);

/*@
assigns \result \from item, locale;
ensures \valid(\result);
*/
char *nl_langinfo_l(nl_item item, locale_t locale);

#endif /* LIBC_LANGINFO_H_ */
