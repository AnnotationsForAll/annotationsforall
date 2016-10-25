/*
 * fpu_control.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_FPU_CONTROL_H_
#define LIBC_FPU_CONTROL_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

/*
Most of these look like internal symbols, but are actually meant for user use.
These macros appear across all platforms with this header, so should be relatively portable.
The exact values here do not reflect any specific architecture. They do not need to.
*/

// The only truly architecture-dependent section are the mask macros.
// TODO: use machdep instead of just including them all

// x86 / x64 / SPARC / Alpha:
#define _FPU_MASK_IM     (1 << 0)
#define _FPU_MASK_DM     (1 << 1)
#define _FPU_MASK_ZM     (1 << 2)
#define _FPU_MASK_OM     (1 << 3)
#define _FPU_MASK_UM     (1 << 4)
#define _FPU_MASK_PM     (1 << 5)

// PPC adds these to x86:
#define _FPU_MASK_XM     (1 << 6)
#define _FPU_MASK_NI     (1 << 7)

// ARM adds these to x86:
#define _FPU_MASK_NZCV   ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9))

// SH adds these to x86:
#define _FPU_MASK_VM     (1 << 6)

// HP-PARISC adds these to x86:
#define _FPU_HPPA_MASK_RM     _FPU_MASK_RM
#define _FPU_HPPA_MASK_INT    _FPU_MASK_EXCEPT
#define _FPU_HPPA_SHIFT_FLAGS 27

// 68k:
# define _FPU_MASK_BSUN  (1 << 0)
# define _FPU_MASK_SNAN  (1 << 1)
# define _FPU_MASK_OPERR (1 << 2)
# define _FPU_MASK_OVFL  (1 << 3)
# define _FPU_MASK_UNFL  (1 << 4)
# define _FPU_MASK_DZ    (1 << 5)
# define _FPU_MASK_INEX1 (1 << 6)
# define _FPU_MASK_INEX2 (1 << 7)

// MIPS:
#define _FPU_MASK_V      (1 << 0)
#define _FPU_MASK_Z      (1 << 1)
#define _FPU_MASK_O      (1 << 2)
#define _FPU_MASK_U      (1 << 3)
#define _FPU_MASK_I      (1 << 4)
#define _FPU_FLUSH_TZ    (1 << 5)
#define _FPU_ABS2008     (1 << 6)
#define _FPU_NAN2008     (1 << 7)

#define _FPU_RC_MASK    _FPU_MASK_RM

// AArch64:
#define _FPU_FPSR_RESERVED  0
#define _FPU_FPSR_DEFAULT   0

#define _FPU_FPCR_RM_MASK  _FPU_MASK_RM

#define _FPU_FPCR_MASK_IXE (1 << 0)
#define _FPU_FPCR_MASK_UFE (1 << 1)
#define _FPU_FPCR_MASK_OFE (1 << 2)
#define _FPU_FPCR_MASK_DZE (1 << 3)
#define _FPU_FPCR_MASK_IOE (1 << 4)

#define _FPU_FPCR_IEEE (_FPU_DEFAULT  | _FPU_FPCR_MASK_IXE | _FPU_FPCR_MASK_UFE | _FPU_FPCR_MASK_OFE |  _FPU_FPCR_MASK_DZE | _FPU_FPCR_MASK_IOE)
#define _FPU_FPSR_IEEE 0

#define _FPU_GETFPSR(cw) __gt_fc_fpu_getfpsr(&cw)
#define _FPU_SETFPSR(cw) __gt_fc_fpu_setfpsr(&cw)

typedef unsigned int fpu_fpsr_t;

void __gt_fc_fpu_getfpsr(fpu_control_t* cw);
void __gt_fc_fpu_setfpsr(fpu_control_t* cw);

// The S/390 adds nothing unique.

// Architecture-independent macros:
#define _FPU_MASK_EXCEPT 0b111111111

#define _FPU_SINGLE   0
#define _FPU_DOUBLE   (1 << 10)
#define _FPU_EXTENDED ((1 << 10) | (1 << 11))

#define _FPU_RC_NEAREST 0
#define _FPU_RC_DOWN    (1 << 12)
#define _FPU_RC_UP      (1 << 13)
#define _FPU_RC_ZERO    ((1 << 12) | (1 << 13))

#define _FPU_MASK_RM    (_FPU_RC_NEAREST | _FPU_RC_DOWN | _FPU_RC_UP | _FPU_RC_ZERO)

#define _FPU_RESERVED 0

#define _FPU_IEEE     (_FPU_MASK_EXCEPT | _FPU_EXTENDED | _FPU_RC_NEAREST)
#define _FPU_DEFAULT  _FPU_IEEE

#define _FPU_GETCW(cw) __gt_fc_fpu_getcw(&cw)
#define _FPU_SETCW(cw) __gt_fc_fpu_setcw(&cw)

typedef unsigned int fpu_control_t;

extern fpu_control_t __fpu_control;

void __gt_fc_fpu_getcw(fpu_control_t* cw);
void __gt_fc_fpu_setcw(fpu_control_t* cw);

#endif /* LIBC_FPU_CONTROL_H_ */
