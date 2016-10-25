/*
 * __gt_fc_file_axioms.h
 */

#ifndef LIBC___GT_FC_FILE_AXIOMS_H_
#define LIBC___GT_FC_FILE_AXIOMS_H_

/*@
axiomatic FileOpen {
    logic boolean file_is_open{L}(FILE* file) reads file;
}

axiomatic FileStream {
    logic boolean file_has_stream{L}(FILE* file) reads file;
}

axiomatic FileBuffer {
    logic boolean file_has_buffer{L}(FILE* file) reads file;
    logic boolean file_dynamic_buffer{L}(FILE* file) reads file;
}

axiomatic FileError {
    logic boolean file_error{L}(FILE* file) reads file;
}

axiomatic FileEOF {
    logic boolean file_eof{L}(FILE* file) reads file;
}

axiomatic FopenMode {
    logic boolean valid_fopen_mode(char* s) reads s[..];
    
    axiom fopen_mode_length: \forall char* s; valid_fopen_mode(s) ==> 1 <= strlen(s) <= 3;
    axiom fopen_mode_0: \forall char* s; valid_fopen_mode(s) ==> s[0] == 'r' || s[0] == 'w' || s[0] == 'a';
    axiom fopen_mode_1: \forall char* s; valid_fopen_mode(s) ==> (\valid(s+(0..2)) ==> s[1] == 'b' || s[1] == '+');
    axiom fopen_mode_2: \forall char* s; valid_fopen_mode(s) ==> (\valid(s+(0..3)) ==> s[2] == 'b' || s[2] == '+');
    axiom fopen_mode_no_rep: \forall char* s; valid_fopen_mode(s) ==> (\valid(s+(0..3)) ==> s[1] != s[2]);
}

axiomatic RandomFailure {
    logic boolean file_op_failed(FILE* file) reads file; 
}
*/

#endif /* LIBC___GT_FC_FILE_AXIOMS_H_ */
