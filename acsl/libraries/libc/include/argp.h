/*
 * argp.h
 *
 *  Created on: Jul 5, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ARGP_H_
#define LIBC_ARGP_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_define_file.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_file_axioms.h"
#include "errno.h"

#define OPTION_ARG_OPTIONAL         (1 << 0)
#define OPTION_HIDDEN               (1 << 1)
#define OPTION_ALIAS                (1 << 2)
#define OPTION_DOC                  (1 << 3)
#define OPTION_NO_USAGE             (1 << 4)

#define ARGP_ERR_UNKNOWN            E2BIG

#define ARGP_KEY_ARG                0
#define ARGP_KEY_END                1
#define ARGP_KEY_NO_ARGS            2
#define ARGP_KEY_INIT               3
#define ARGP_KEY_SUCCESS            4
#define ARGP_KEY_ERROR              5
#define ARGP_KEY_ARGS               6
#define ARGP_KEY_FINI               7
#define ARGP_KEY_HELP_PRE_DOC       8
#define ARGP_KEY_HELP_POST_DOC      9
#define ARGP_KEY_HELP_HEADER        10
#define ARGP_KEY_HELP_EXTRA         11
#define ARGP_KEY_HELP_DUP_ARGS_NOTE 12
#define ARGP_KEY_HELP_ARGS_DOC      13

#define ARGP_PARSE_ARGV0            (1 << 0)
#define ARGP_NO_ERRS                (1 << 1)
#define ARGP_NO_ARGS                (1 << 2)
#define ARGP_IN_ORDER               (1 << 3)
#define ARGP_NO_HELP                (1 << 4)
#define ARGP_NO_EXIT                (1 << 5)
#define ARGP_LONG_ONLY              (1 << 6)
#define ARGP_SILENT                 (ARGP_NO_EXIT | ARGP_NO_ERRS | ARGP_NO_HELP)

#define ARGP_HELP_USAGE              (1 << 0)
#define ARGP_HELP_SHORT_USAGE        (1 << 1)
#define ARGP_HELP_SEE                (1 << 2)
#define ARGP_HELP_LONG               (1 << 3)
#define ARGP_HELP_PRE_DOC            (1 << 4)
#define ARGP_HELP_POST_DOC           (1 << 5)
#define ARGP_HELP_DOC                (1 << 6)
#define ARGP_HELP_BUG_ADDR           (1 << 7)
#define ARGP_HELP_LONG_ONLY          (1 << 8)
#define ARGP_HELP_EXIT_ERR           (1 << 9)
#define ARGP_HELP_EXIT_OK            (1 << 10)
#define ARGP_HELP_STD_ERR            (ARGP_HELP_SEE | ARGP_HELP_EXIT_ERR)
#define ARGP_HELP_STD_USAGE          (ARGP_HELP_SHORT_USAGE | ARGP_HELP_SEE | ARGP_HELP_EXIT_ERR)
#define ARGP_HELP_STD_HELP           (ARGP_HELP_SHORT_USAGE | ARGP_HELP_LONG | ARGP_HELP_EXIT_OK | ARGP_HELP_DOC | ARGP_HELP_BUG_ADDR)

typedef error_t (*argp_parser_t)(int key, char *arg, struct argp_state *state);

struct argp_option {
    const char *name;
    int key;
    const char *arg;
    int flags;
    const char *doc;
    int group;
};

struct argp {
    const struct argp_option *options;
    argp_parser_t parser;
    const char *args_doc;
    const char *doc;
    const struct argp_child *children;
    char *(*help_filter)(int key, const char *text, void *input);
    const char *argp_domain;
};

struct argp_child {
    const struct argp *argp;
    int flags;
    const char *header;
    int group;
};

struct argp_state {
    const struct argp *root_argp;
    int argc;
    char **argv;
    int next;
    unsigned flags;
    unsigned arg_num;
    int quoted;
    void *input;
    void **child_inputs;
    void *hook;
    char *name;
    FILE *err_stream;
    FILE *out_stream;
    void *pstate;
};

extern const char *argp_program_version;
extern void (*argp_program_version_hook)(FILE *restrict stream, struct argp_state *restrict state);
extern const char *argp_program_bug_address;
extern error_t argp_err_exit_status;

/*@
requires argp != \null ==> \valid(argp);
requires \valid(argv+(0..argc-1));
requires \forall unsigned int i; i < argc ==> \valid(argv[i]);
requires arg_index != \null ==> \valid(arg_index);
assigns \result, *arg_index, *((char*)input) \from *argp, argc, argv[0..argc-1], flags;
 */
error_t argp_parse(const struct argp* argp, int argc, char** argv, unsigned flags, int* arg_index, void* input);

/*@
requires \valid(argp);
requires \valid(stream);
requires valid_read_string(name);
assigns *stream \from *argp, *stream, flags, name[0..strlen(name)];
*/
void argp_help(const struct argp *restrict argp, FILE *restrict stream, unsigned flags, char *restrict name);

/*@
requires \valid(state);
requires \valid(stream);
assigns *stream \from *state, *stream, flags;
behavior no_exit:
    exits \false;
    ensures \true;
behavior yes_exit:
    exits \exit_status == argp_err_exit_status;
    ensures \false;
complete behaviors; disjoint behaviors;
*/
void argp_state_help(const struct argp_state *restrict state, FILE *restrict stream, unsigned int flags);

/*@
requires \valid(state);
requires \valid(state->err_stream);
assigns *(state->err_stream) \from *state;
behavior no_exit:
    exits \false;
    ensures \true;
behavior yes_exit:
    exits \exit_status == argp_err_exit_status;
    ensures \false;
complete behaviors; disjoint behaviors;
*/
void argp_usage(const struct argp_state *state);

/*@
requires \valid(state);
requires \valid(state->err_stream);
requires valid_read_string(fmt);
assigns *(state->err_stream) \from *state, fmt[0..strlen(fmt)];
behavior no_exit:
    exits \false;
    ensures \true;
behavior yes_exit:
    exits \exit_status == argp_err_exit_status;
    ensures \false;
complete behaviors; disjoint behaviors;
*/
void argp_error(const struct argp_state *restrict state, const char *restrict fmt, ...);

/*@
requires \valid(state);
requires \valid(state->err_stream);
requires valid_read_string(fmt);
assigns *(state->err_stream) \from *state, fmt[0..strlen(fmt)], status, errnum;
behavior no_exit:
    exits \false;
    ensures \true;
behavior yes_exit:
    exits status != 0 && \exit_status == status;
    ensures status != 0 ==> \false;
complete behaviors; disjoint behaviors;
*/
void argp_failure(const struct argp_state *restrict state, int status, int errnum, const char *restrict fmt, ...);

#endif /* LIBC_ARGP_H_ */
