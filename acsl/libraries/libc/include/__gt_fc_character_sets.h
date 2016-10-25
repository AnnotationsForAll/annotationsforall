/*
 * __fc_character_sets.h
 */

#ifndef GT_FC_CHARACTER_SETS_H_
#define GT_FC_CHARACTER_SETS_H_

/**
 * Character sets, defined in 5.2.1
 */

/*@
    // 5.2.1 (2): Null character
    predicate charset_null{L}(int c) =
        c == 0;

    // 5.2.1 (3):
    // Upper case
    predicate charset_uppercase{L}(int c) =
        'A' <= c && c <= 'Z';

    // Lower case
    predicate charset_lowercase{L}(int c) =
        'a' <= c && c <= 'z';

    // digits
    predicate charset_digit{L}(int c) =
        '0' <= c && c <= '9';

    // graphic characters
    predicate charset_graphic{L}(int c) =
        c == '!'
        || c == '"'
        || c == '#'
        || c == '%'
        || c == '&'
        || c == '\''
        || c == '('
        || c == ')'
        || c == '*'
        || c == '+'
        || c == ','
        || c == '-'
        || c == '.'
        || c == '/'
        || c == ':'
        || c == ';'
        || c == '<'
        || c == '='
        || c == '>'
        || c == '?'
        || c == '['
        || c == '\\'
        || c == ']'
        || c == '^'
        || c == '_'
        || c == '{'
        || c == '|'
        || c == '}'
        || c == '~'
        ;

    // space, control characters for horizontal tab, vertical tab, and form feed
    predicate charset_other{L}(int c) =
        c == ' '
        || c == '\t'
//        || c == '\v'  // FIXME:
        || c == '\f'
    ;

    // basic source
    predicate charset_basic_source{L}(int c) =
        charset_uppercase{L}(c)
        || charset_lowercase{L}(c)
        || charset_digit{L}(c)
        || charset_graphic{L}(c)
        || charset_other{L}(c)
    ;

    // basic execution
    predicate charset_basic_execution{L}(int c) =
        charset_basic_source{L}(c);

    predicate charset_control{L}(int c) =
        0 <= c && c < 32;

    // 5.2.1 (4): letter
    // Note from specification: "in this International Standard the term does not include other characters that are letters in other alphabets"
    predicate charset_letter{L}(int c) =
        charset_lowercase{L}(c) || charset_uppercase{L}(c);

    // 6.4.4.1: hexadecimal-digit
    predicate charset_hexadecimal_digit{L}(int c) =
        charset_digit{L}(c)
        || ('a' <= c && c <= 'f')
        || ('A' <= c && c <= 'F');

*/


#endif /* GT_FC_CHARACTER_SETS_H_ */

