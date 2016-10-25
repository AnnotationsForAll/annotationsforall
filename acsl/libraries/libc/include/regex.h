/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2015                                               */
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

#ifndef _REGEX_H
#define _REGEX_H 1
#include "features.h"
#include "__fc_define_size_t.h"
#include "__fc_string_axiomatic.h"

__BEGIN_DECLS

struct re_pattern_buffer {
    size_t re_nsub;
    /* GNU extension fields */
    unsigned char* buffer;
    unsigned long int allocated;
    char * fastmap;
    unsigned char* translate;
    unsigned not_bol;
    unsigned not_eol;
};

typedef struct re_pattern_buffer regex_t;

#define REG_EXTENDED (1 << 0)
#define REG_ICASE    (1 << 1)
#define REG_NEWLINE  (1 << 2)
#define REG_NOSUB    (1 << 3)


/* Eflags */
#define REG_NOTBOL   (1 << 0)
#define REG_NOTEOL   (1 << 1)
#define REG_STARTEND (1 << 2)

/* Error codes */
typedef enum
{
  REG_ENOSYS = -1,
  REG_NOERROR = 0,
  REG_NOMATCH,    
  REG_BADPAT,     
  REG_ECOLLATE,   
  REG_ECTYPE,     
  REG_EESCAPE,    
  REG_ESUBREG,    
  REG_EBRACK,     
  REG_EPAREN,     
  REG_EBRACE,     
  REG_BADBR,      
  REG_ERANGE,     
  REG_ESPACE,     
  REG_BADRPT,     
  REG_EEND,   
  REG_ESIZE,      
  REG_ERPAREN     
} reg_errcode_t;

typedef int regoff_t;

typedef struct
{
  regoff_t rm_so;
  regoff_t rm_eo;
} regmatch_t;

/*@
axiomatic IsRegexOpen {
    logic boolean is_regex_open{L}(regex_t * preg) reads *preg;
}
*/

/*@
requires \valid(preg);
requires \valid(pattern);
assigns \result, *preg \from pattern[..], cflags;
ensures is_regex_open(preg);
*/
int regcomp(regex_t *restrict preg, const char *restrict pattern, int cflags);

/*@
requires preg != \null ==> is_regex_open(preg);
requires \valid(errbuf+(0..errbuf_size-1));
assigns \result, errbuf[0..errbuf_size-1] \from errcode, *preg, errbuf_size;
ensures 0 <= \result <= errbuf_size;
*/
size_t regerror(int errcode, const regex_t *restrict preg, char *restrict errbuf, size_t errbuf_size);

/*@
requires is_regex_open(preg);
requires \valid(string);
requires \valid(pmatch);
assigns \result, *pmatch \from *preg, string[..], nmatch, eflags;
*/
int regexec(const regex_t *restrict preg, const char *restrict string, size_t nmatch, regmatch_t *restrict pmatch, int eflags);

/*@
requires is_regex_open(preg);
assigns *preg \from \nothing;
ensures !is_regex_open(preg);
*/
void regfree(regex_t *preg);

/* GNU Extensions */

#define RE_BACKSLASH_ESCAPE_IN_LISTS (1 << 4)
#define RE_BK_PLUS_QM                (1 << 5)
#define RE_CHAR_CLASSES              (1 << 6)
#define RE_CONTEXT_INDEP_ANCHORS     (1 << 7)
#define RE_CONTEXT_INDEP_OPS         (1 << 8)
#define RE_CONTEXT_INVALID_OPS       (1 << 9)
#define RE_DOT_NEWLINE               (1 << 10)
#define RE_DOT_NOT_NULL              (1 << 11)
#define RE_HAT_LISTS_NOT_NEWLINE     (1 << 12)
#define RE_INTERVALS                 (1 << 13)
#define RE_LIMITED_OPS               (1 << 14)
#define RE_NEWLINE_ALT               (1 << 15)
#define RE_NO_BK_BRACES              (1 << 16)
#define RE_NO_BK_PARENS              (1 << 17)
#define RE_NO_BK_REFS                (1 << 18)
#define RE_NO_BK_VBAR                (1 << 19)
#define RE_NO_EMPTY_RANGES           (1 << 20)
#define RE_UNMATCHED_RIGHT_PAREN_ORD (1 << 21)
#define RE_NO_POSIX_BACKTRACKING     (1 << 22)
#define RE_NO_GNU_OPS                (1 << 23)
#define RE_DEBUG                     (1 << 24)
#define RE_INVALID_INTERVAL_ORD      (1 << 25)
#define RE_CARET_ANCHORS_HERE        (1 << 26)
#define RE_CONTEXT_INVALID_DUP       (1 << 27)
#define RE_NO_SUB                    (1 << 28)
#define RE_ICASE                     (1 << 29)

#define RE_SYNTAX_EMACS 0
#define RE_SYNTAX_AWK                           \
  (RE_BACKSLASH_ESCAPE_IN_LISTS   | RE_DOT_NOT_NULL         \
   | RE_NO_BK_PARENS              | RE_NO_BK_REFS           \
   | RE_NO_BK_VBAR                | RE_NO_EMPTY_RANGES          \
   | RE_DOT_NEWLINE       | RE_CONTEXT_INDEP_ANCHORS        \
   | RE_CHAR_CLASSES                            \
   | RE_UNMATCHED_RIGHT_PAREN_ORD | RE_NO_GNU_OPS)
#define RE_SYNTAX_GNU_AWK                       \
  ((RE_SYNTAX_POSIX_EXTENDED | RE_BACKSLASH_ESCAPE_IN_LISTS     \
    | RE_INVALID_INTERVAL_ORD)                      \
   & ~(RE_DOT_NOT_NULL | RE_CONTEXT_INDEP_OPS               \
      | RE_CONTEXT_INVALID_OPS ))
#define RE_SYNTAX_POSIX_AWK                     \
  (RE_SYNTAX_POSIX_EXTENDED | RE_BACKSLASH_ESCAPE_IN_LISTS      \
   | RE_INTERVALS       | RE_NO_GNU_OPS             \
   | RE_INVALID_INTERVAL_ORD)
#define RE_SYNTAX_GREP                          \
  (RE_BK_PLUS_QM              | RE_CHAR_CLASSES             \
   | RE_HAT_LISTS_NOT_NEWLINE | RE_INTERVALS                \
   | RE_NEWLINE_ALT)
#define RE_SYNTAX_EGREP                         \
  (RE_CHAR_CLASSES        | RE_CONTEXT_INDEP_ANCHORS            \
   | RE_CONTEXT_INDEP_OPS | RE_HAT_LISTS_NOT_NEWLINE            \
   | RE_NEWLINE_ALT       | RE_NO_BK_PARENS             \
   | RE_NO_BK_VBAR)
#define RE_SYNTAX_POSIX_EGREP                       \
  (RE_SYNTAX_EGREP | RE_INTERVALS | RE_NO_BK_BRACES         \
   | RE_INVALID_INTERVAL_ORD)
#define RE_SYNTAX_ED RE_SYNTAX_POSIX_BASIC
#define RE_SYNTAX_SED RE_SYNTAX_POSIX_BASIC
#define RE_SYNTAX_POSIX_BASIC                       \
  ( (RE_CHAR_CLASSES | RE_DOT_NEWLINE | RE_DOT_NOT_NULL | RE_INTERVALS  | RE_NO_EMPTY_RANGES) | RE_BK_PLUS_QM | RE_CONTEXT_INVALID_DUP)
#define RE_SYNTAX_POSIX_MINIMAL_BASIC                   \
  ( (RE_CHAR_CLASSES | RE_DOT_NEWLINE | RE_DOT_NOT_NULL | RE_INTERVALS  | RE_NO_EMPTY_RANGES) | RE_LIMITED_OPS)
#define RE_SYNTAX_POSIX_EXTENDED                    \
  ( (RE_CHAR_CLASSES | RE_DOT_NEWLINE | RE_DOT_NOT_NULL | RE_INTERVALS  | RE_NO_EMPTY_RANGES)  | RE_CONTEXT_INDEP_ANCHORS          \
   | RE_CONTEXT_INDEP_OPS   | RE_NO_BK_BRACES               \
   | RE_NO_BK_PARENS        | RE_NO_BK_VBAR             \
   | RE_CONTEXT_INVALID_OPS | RE_UNMATCHED_RIGHT_PAREN_ORD)
#define RE_SYNTAX_POSIX_MINIMAL_EXTENDED                \
  ( (RE_CHAR_CLASSES | RE_DOT_NEWLINE | RE_DOT_NOT_NULL | RE_INTERVALS  | RE_NO_EMPTY_RANGES)  | RE_CONTEXT_INDEP_ANCHORS          \
   | RE_CONTEXT_INVALID_OPS | RE_NO_BK_BRACES               \
   | RE_NO_BK_PARENS        | RE_NO_BK_REFS             \
   | RE_NO_BK_VBAR      | RE_UNMATCHED_RIGHT_PAREN_ORD)

#define RE_NREGS 30

// TODO: make these machdep-independant
typedef long int s_reg_t;
typedef unsigned long int active_reg_t;
typedef unsigned long int reg_syntax_t;

struct re_registers {
    unsigned num_regs;
    regoff_t *start;
    regoff_t *end;
};

extern reg_syntax_t re_syntax_options;

// The following GNU extensions are undocumented, but some programs may use them.

reg_syntax_t re_set_syntax(reg_syntax_t syntax);
const char *re_compile_pattern (const char *pattern, size_t length, struct re_pattern_buffer *buffer);
int re_compile_fastmap (struct re_pattern_buffer *buffer);
int re_search(struct re_pattern_buffer *buffer, const char *string, int length, int start, int range, struct re_registers *regs);
int re_search_2(struct re_pattern_buffer *buffer, const char *string1, int length1, const char *string2, int length2, int start, int range, struct re_registers *regs, int stop);
int re_match(struct re_pattern_buffer *buffer, const char *string, int length, int start, struct re_registers *regs);
int re_match_2(struct re_pattern_buffer *buffer, const char *string1, int length1, const char *string2, int length2, int start, struct re_registers *regs, int stop);
void re_set_registers(struct re_pattern_buffer *buffer, struct re_registers *regs, unsigned int num_regs, regoff_t *starts, regoff_t *ends);

/* BSD Extensions */

/*@
requires regex != \null ==> valid_read_string(regex);
assigns \result;
ensures valid_read_string_or_null(\result);
*/
char *re_comp(const char *regex);

/*@
requires valid_read_string(string);
assigns \result;
ensures -1 <= \result <= 1;
*/
int re_exec(const char *string);

__END_DECLS

#endif
