// frama-c notice:
/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2014                                               */
/*    CEA (Commissariat à l'énergie atomique et aux énergies              */
/*         alternatives)                                                  */
/*                                                                        */
/*  you can redistribute it and/or modify it under the terms of the GNU   */
/*  Lesser General Public License as published by the Free Software       */
/*  Foundation, version 2.1.                                              */
/*                                                                        */
/*  It is distributed in the hope that it will be useful,                 */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/*  GNU Lesser General Public License for more details.                   */
/*                                                                        */
/*  See the GNU Lesser General Public License version 2.1                 */
/*  for more details (enclosed in the file licenses/LGPLv2.1).            */
/*                                                                        */
/**************************************************************************/


#ifndef __FC_CTYPE
#define __FC_CTYPE
#include "features.h"

#include <stdio.h>
#include "__gt_fc_define_locale_t.h"
#include "__gt_fc_character_sets.h"

/*@
    // Common pre-condition for all libc ctype functions
    // 7.4 (1)
    predicate valid_ctype_param{L}(int c) =
        (unsigned char)(c) == c
        || c == EOF;

    // Logical definitions for ctype functions

    predicate alpha_char{L}(int c) =
        charset_lowercase(c) || charset_uppercase(c);

    predicate alnum_char{L}(int c) =
        alpha_char{L}(c) || charset_digit{L}(c);

    // 7.4 (3)
    // All characters which occupy one printing position on the screen
    // All letters and digits are guaranteed
    predicate printing_character{L}(int c) =
        charset_letter{L}(c)
        || charset_digit{L}(c)
        || charset_graphic{L}(c)
        || c == ' '
        // Or localization
        ;

    predicate locale_space{L}(int c) = \false; // TODO: ?

    // 7.4.1.10
    predicate whitespace_char{L}(int c) =
        c == ' '
        || c == '\f'
        || c == '\n'
        || c == '\r'
        || c == '\t'
//        || c == '\v'  // FIXME: This character is breaking frama-c kernel somehow
        || locale_space(c)
        ;

    // 7.4.1.3 (2)
    predicate blank_char{L}(int c) =
        c == ' '
        || c == '\t'
        || locale_space(c)
        ;

    // 7.4.1.6
    predicate graph_char{L}(int c) =
        printing_character{L}(c)
        && (c != ' ');

    // 7.4.1.9
    predicate punct_char{L}(int c) =
        printing_character{L}(c)
        && !whitespace_char{L}(c)
        && !alnum_char{L}(c);
*/

/********* libc functions ********/

/* ISO C : 7.4.1 */

__BEGIN_DECLS

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_alnum:
        assumes alnum_char(c);
        ensures \result == 1;
    behavior not_alnum:
        assumes !alnum_char(c);
        ensures \result == 0;
*/
int isalnum(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_alpha:
        assumes alpha_char(c);
        ensures \result == 1;
    behavior not_alpha:
        assumes !alpha_char(c);
        ensures \result == 0;
*/
int isalpha(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_blank:
        assumes blank_char(c);
        ensures \result == 1;
    behavior not_blank:
        assumes !blank_char(c);
        ensures \result == 0;
*/
int isblank(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_cntrl:
        assumes charset_control(c);
        ensures \result == 1;
    behavior not_cntrl:
        assumes !charset_control(c);
        ensures \result == 0;
*/
int iscntrl(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_digit:
        assumes charset_digit(c);
        ensures \result == 1;
    behavior not_digit:
        assumes !charset_digit(c);
        ensures \result == 0;
*/
int isdigit(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_graph:
        assumes graph_char(c);
        ensures \result == 1;
    behavior not_graph:
        assumes !graph_char(c);
        ensures \result == 0;
*/
int isgraph(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_lower:
        assumes charset_lowercase(c);
        ensures \result == 1;
    behavior not_lower:
        assumes !charset_lowercase(c);
        ensures \result == 0;
*/
int islower(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_print:
        assumes printing_character(c);
        ensures \result == 1;
    behavior not_print:
        assumes !printing_character(c);
        ensures \result == 0;
*/
int isprint(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_print:
        assumes punct_char(c);
        ensures \result == 1;
    behavior not_print:
        assumes !punct_char(c);
        ensures \result == 0;
*/
int ispunct(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_whitespace:
        assumes whitespace_char(c);
        ensures \result == 1;
    behavior not_whitespace:
        assumes !whitespace_char(c);
        ensures \result == 0;
*/
int isspace(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_upper:
        assumes charset_uppercase(c);
        ensures \result == 1;
    behavior not_upper:
        assumes !charset_uppercase(c);
        ensures \result == 0;
*/
int isupper(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_xdigit:
        assumes charset_hexadecimal_digit(c);
        ensures \result == 1;
    behavior not_xdigit:
        assumes !charset_hexadecimal_digit(c);
        ensures \result == 0;
*/
int isxdigit(int c);

/* ISO C : 7.4.2 */

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_upper:
        assumes charset_uppercase(c);
        ensures \result == c + ('a' - 'A');
    behavior not_upper:
        assumes !charset_uppercase(c);
        ensures \result == c;
*/
int tolower(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_lower:
        assumes charset_lowercase(c);
        ensures \result == c - ('a' - 'A');
    behavior not_lower:
        assumes !charset_lowercase(c);
        ensures \result == c;
*/
int toupper(int c);

/* POSIX */
// Specification from http://pubs.opengroup.org/onlinepubs/009695399/functions/isascii.html

//note: isascii() is marked as obsolescent in POSIX standard
/*@
    assigns \result \from c ;
    behavior invalid:
        assumes c < 0 || c > 0177;
        ensures \result == 0;
    behavior valid:
        // TODO: is this correct?
        assumes 0 <= c && c <= 0177;
        ensures \result != 0;
*/
int isascii(int c);

/* locale-specific POSIX functions */

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_alnum:
        assumes alnum_char(c);
        ensures \result == 1;
    behavior not_alnum:
        assumes !alnum_char(c);
        ensures \result == 0;
*/
int isalnum_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_alpha:
        assumes alpha_char(c);
        ensures \result == 1;
    behavior not_alpha:
        assumes !alpha_char(c);
        ensures \result == 0;
*/
int isalpha_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_blank:
        assumes blank_char(c);
        ensures \result == 1;
    behavior not_blank:
        assumes !blank_char(c);
        ensures \result == 0;
*/
int isblank_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_cntrl:
        assumes charset_control(c);
        ensures \result == 1;
    behavior not_cntrl:
        assumes !charset_control(c);
        ensures \result == 0;
*/
int iscntrl_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_digit:
        assumes charset_digit(c);
        ensures \result == 1;
    behavior not_digit:
        assumes !charset_digit(c);
        ensures \result == 0;
*/
int isdigit_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_graph:
        assumes graph_char(c);
        ensures \result == 1;
    behavior not_graph:
        assumes !graph_char(c);
        ensures \result == 0;
*/
int isgraph_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_lower:
        assumes charset_lowercase(c);
        ensures \result == 1;
    behavior not_lower:
        assumes !charset_lowercase(c);
        ensures \result == 0;
*/
int islower_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_print:
        assumes printing_character(c);
        ensures \result == 1;
    behavior not_print:
        assumes !printing_character(c);
        ensures \result == 0;
*/
int isprint_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_print:
        assumes punct_char(c);
        ensures \result == 1;
    behavior not_print:
        assumes !punct_char(c);
        ensures \result == 0;
*/
int ispunct_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_whitespace:
        assumes whitespace_char(c);
        ensures \result == 1;
    behavior not_whitespace:
        assumes !whitespace_char(c);
        ensures \result == 0;
*/
int isspace_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_upper:
        assumes charset_uppercase(c);
        ensures \result == 1;
    behavior not_upper:
        assumes !charset_uppercase(c);
        ensures \result == 0;
*/
int isupper_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_xdigit:
        assumes charset_hexadecimal_digit(c);
        ensures \result == 1;
    behavior not_xdigit:
        assumes !charset_hexadecimal_digit(c);
        ensures \result == 0;
*/
int isxdigit_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_upper:
        assumes charset_uppercase(c);
        ensures \result == c + ('a' - 'A');
    behavior not_upper:
        assumes !charset_uppercase(c);
        ensures \result == c;
*/
int tolower_l(int c, locale_t locale);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_lower:
        assumes charset_lowercase(c);
        ensures \result == c - ('a' - 'A');
    behavior not_lower:
        assumes !charset_lowercase(c);
        ensures \result == c;
*/
int toupper_l(int c, locale_t locale);

/* BSD/SVID Extensions */

/*@
requires valid_ctype_param(c);
assigns \result \from c ;
ensures \result == (((char)c) & ((char)0b01111111));
*/
int toascii(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_upper:
        assumes charset_uppercase(c);
        ensures \result == c + ('a' - 'A');
    behavior not_upper:
        assumes !charset_uppercase(c);
        ensures \result == c;
*/
int _tolower(int c);

/*@
    requires valid_ctype_param(c);
    assigns \result \from c ;
    behavior is_lower:
        assumes charset_lowercase(c);
        ensures \result == c - ('a' - 'A');
    behavior not_lower:
        assumes !charset_lowercase(c);
        ensures \result == c;
*/
int _toupper(int c);

__END_DECLS

#endif /* __FC_CTYPE */

