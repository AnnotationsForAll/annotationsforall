/*
 * elf.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ELF_H_
#define LIBC_ELF_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__gt_fc_define_alternative_types.h"

#define Elf32_Addr    uint32_t
#define Elf32_Off     uint32_t
#define Elf32_Section uint16_t
#define Elf32_Versym  uint16_t
#define Elf32Byte     unsigned char
#define Elf32_Half    uint16_t
#define Elf32_Sword   int32_t
#define Elf32_Word    uint32_t
#define Elf32_Sxword  int64_t
#define Elf32_Xword   uint64_t

#define Elf64_Addr    uint32_t
#define Elf64_Off     uint32_t
#define Elf64_Section uint16_t
#define Elf64_Versym  uint16_t
#define Elf64Byte     unsigned char
#define Elf64_Half    uint16_t
#define Elf64_Sword   int32_t
#define Elf64_Word    uint32_t
#define Elf64_Sxword  int64_t
#define Elf64_Xword   uint64_t

#define EI_MAG0       0
#define EI_MAG1       1
#define EI_MAG2       2
#define EI_MAG3       3
#define EI_CLASS      4
#define EI_DATA       5
#define EI_VERSION    6
#define EI_OSABI      7
#define EI_ABIVERSION 8
#define EI_PAD        9

#define ELFMAG0 0x7f
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'

#define ELFMAG  "\177ELF"
#define SELFMAG 4

#define ELFCLASSNONE 0
#define ELFCLASS32   1
#define ELFCLASS64   2
#define ELFCLASSNUM  3

#define ELFDATANONE 0
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2
#define ELFDATANUM  3

#define EV_NONE    0
#define EV_CURRENT 1
#define EV_NUM      2

#define ELFOSABI_NONE       0
#define ELFOSABI_SYSV       1
#define ELFOSABI_HPUX       2
#define ELFOSABI_NETBSD     3
#define ELFOSABI_GNU        4
#define ELFOSABI_LINUX      5
#define ELFOSABI_SOLARIS    6
#define ELFOSABI_AIX        7
#define ELFOSABI_IRIX       8
#define ELFOSABI_FREEBSD    9
#define ELFOSABI_TRU64      10
#define ELFOSABI_MODESTO    11
#define ELFOSABI_OPENBSD    12
#define ELFOSABI_ARM_AEABI  13
#define ELFOSABI_ARM        14
#define ELFOSABI_STANDALONE 15

#define ET_NONE   0
#define ET_REL    1
#define ET_EXEC   2
#define ET_DYN    3
#define ET_CORE   4
#define ET_NUM    5
#define ET_LOOS   6
#define ET_HIOS   7
#define ET_LOPROC 8
#define ET_HIPROC 9

#define EM_NONE         0
#define EM_M32          1
#define EM_SPARC        2
#define EM_386          3
#define EM_68K          4
#define EM_88K          5
#define EM_860          7
#define EM_MIPS         8
#define EM_S370         9
#define EM_MIPS_RS3_LE  10
#define EM_PARISC       15
#define EM_VPP500       17
#define EM_SPARC32PLUS  18
#define EM_960          19
#define EM_PPC          20
#define EM_PPC64        21
#define EM_S390         22
#define EM_V800         36
#define EM_FR20         37
#define EM_RH32         38
#define EM_RCE          39
#define EM_ARM          40
#define EM_FAKE_ALPHA   41
#define EM_SH           42
#define EM_SPARCV9      43
#define EM_TRICORE      44
#define EM_ARC          45
#define EM_H8_300       46
#define EM_H8_300H      47
#define EM_H8S          48
#define EM_H8_500       49
#define EM_IA_64        50
#define EM_MIPS_X       51
#define EM_COLDFIRE     52
#define EM_68HC12       53
#define EM_MMA          54
#define EM_PCP          55
#define EM_NCPU         56
#define EM_NDR1         57
#define EM_STARCORE     58
#define EM_ME16         59
#define EM_ST100        60
#define EM_TINYJ        61
#define EM_X86_64       62
#define EM_PDSP         63
#define EM_FX66         66
#define EM_ST9PLUS      67
#define EM_ST7          68
#define EM_68HC16       69
#define EM_68HC11       70
#define EM_68HC08       71
#define EM_68HC05       72
#define EM_SVX          73
#define EM_ST19         74
#define EM_VAX          75
#define EM_CRIS         76
#define EM_JAVELIN      77
#define EM_FIREPATH     78
#define EM_ZSP          79
#define EM_MMIX         80
#define EM_HUANY        81
#define EM_PRISM        82
#define EM_AVR          83
#define EM_FR30         84
#define EM_D10V         85
#define EM_D30V         86
#define EM_V850         87
#define EM_M32R         88
#define EM_MN10300      89
#define EM_MN10200      90
#define EM_PJ           91
#define EM_OPENRISC     92
#define EM_ARC_A5       93
#define EM_XTENSA       94
#define EM_ALTERA_NIOS2 113
#define EM_AARCH64      183
#define EM_TILEPRO      188
#define EM_MICROBLAZE   189
#define EM_TILEGX       191
#define EM_ALPHA        192
#define EM_NUM          193

#define PN_XNUM 0xffff

#define SHN_UNDEF     0
#define SHN_LORESERVE 1
#define SHN_LOPROC    2
#define SHN_BEFORE    3
#define SHN_AFTER     4
#define SHN_HIPROC    5
#define SHN_LOOS      6
#define SHN_HIOS      7
#define SHN_ABS       8
#define SHN_COMMON    9
#define SHN_XINDEX    10
#define SHN_HIRESERVE 11

#define PT_NULL         0
#define PT_LOAD         1
#define PT_DYNAMIC      2
#define PT_INTERP       3
#define PT_NOTE         4
#define PT_SHLIB        5
#define PT_PHDR         6
#define PT_TLS          7
#define PT_NUM          8
#define PT_LOOS         9
#define PT_GNU_EH_FRAME 10
#define PT_GNU_STACK    11
#define PT_GNU_RELRO    12
#define PT_LOSUNW       13
#define PT_SUNWBSS      14
#define PT_SUNWSTACK    15
#define PT_HISUNW       16
#define PT_HIOS         128
#define PT_LOPROC       129
#define PT_HIPROC       255

#define PF_X (1 << 0)
#define PF_W (1 << 1)
#define PF_R (1 << 2)
#define PF_MASKOS   0x0ff00000
#define PF_MASKPROC 0xf0000000

#define NT_PRSTATUS         1
#define NT_FPREGSET         2
#define NT_PRPSINFO         3
#define NT_PRXREG           4
#define NT_TASKSTRUCT       5
#define NT_PLATFORM         6
#define NT_AUXV             7
#define NT_GWINDOWS         8
#define NT_ASRS             9
#define NT_PSTATUS          10
#define NT_PSINFO           11
#define NT_PRCRED           12
#define NT_UTSNAME          13
#define NT_LWPSTATUS        14
#define NT_LWPSINFO         15
#define NT_PRFPXREG         16
#define NT_SIGINFO          17
#define NT_FILE             18
#define NT_PRXFPREG         19
#define NT_PPC_VMX          20
#define NT_PPC_SPE          21
#define NT_PPC_VSX          22
#define NT_386_TLS          23
#define NT_386_IOPERM       24
#define NT_X86_XSTATE       25
#define NT_S390_HIGH_GPRS   26
#define NT_S390_TIMER       27
#define NT_S390_TODCMP      28
#define NT_S390_TODPREG     29
#define NT_S390_CTRS        30
#define NT_S390_PREFIX      31
#define NT_S390_LAST_BREAK  32
#define NT_S390_SYSTEM_CALL 33
#define NT_S390_TDB         34
#define NT_ARM_VFP          35
#define NT_ARM_TLS          36
#define NT_ARM_HW_BREAK     37
#define NT_ARM_HW_WATCH     38

#define NT_VERSION 1

#define SHT_NULL           1
#define SHT_PROGBITS       2
#define SHT_SYMTAB         3
#define SHT_STRTAB         4
#define SHT_RELA           5
#define SHT_HASH           6
#define SHT_DYNAMIC        7
#define SHT_NOTE           8
#define SHT_NOBITS         9
#define SHT_REL            10
#define SHT_SHLIB          11
#define SHT_DYNSYM         12
#define SHT_INIT_ARRAY     13
#define SHT_FINI_ARRAY     14
#define SHT_PREINIT_ARRAY  15
#define SHT_GROUP          16
#define SHT_SYMTAB_SHNDX   17
#define SHT_NUM            18
#define SHT_LOOS           19
#define SHT_GNU_ATTRIBUTES 20
#define SHT_GNU_HASH       21
#define SHT_GNU_LIBLIST    22
#define SHT_CHECKSUM       23
#define SHT_LOSUNW         24
#define SHT_SUNW_move      25
#define SHT_SUNW_COMDAT    26
#define SHT_SUNW_syminfo   27
#define SHT_GNU_verdef     28
#define SHT_GNU_verneed    29
#define SHT_GNU_versym     30
#define SHT_HISUNW         31
#define SHT_HIOS           32
#define SHT_LOPROC         33
#define SHT_HIPROC         34
#define SHT_LOUSER         35
#define SHT_HIUSER         36

#define SHF_WRITE            (1 << 0)
#define SHF_ALLOC            (1 << 1)
#define SHF_EXECINSTR        (1 << 2)
#define SHF_MERGE            (1 << 4)
#define SHF_STRINGS          (1 << 5)
#define SHF_INFO_LINK        (1 << 6)
#define SHF_LINK_ORDER       (1 << 7)
#define SHF_OS_NONCONFORMING (1 << 8)
#define SHF_GROUP            (1 << 9)
#define SHF_TLS              (1 << 10)
#define SHF_COMPRESSED       (1 << 11)
#define SHF_MASKOS           (1 << 12)
#define SHF_MASKPROC         (1 << 13)
#define SHF_ORDERED          (1 << 14)
#define SHF_EXCLUDE          (1 << 15)

#define STB_LOCAL       0
#define STB_GLOBAL      1
#define STB_WEAK        2
#define STB_NUM         3
#define STB_LOOS        4
#define STB_GNU_UNIQUE  5
#define STB_HIOS        6
#define STB_LOPROC      7
#define STB_HIPROC      8

#define STT_NOTYPE    0
#define STT_OBJECT    1
#define STT_FUNC      2
#define STT_SECTION   3
#define STT_FILE      4
#define STT_COMMON    5
#define STT_TLS       6
#define STT_NUM       7
#define STT_LOOS      8
#define STT_GNU_IFUNC 9
#define STT_HIOS      10
#define STT_LOPROC    11
#define STT_HIPROC    12

#define STN_UNDEF 0

#define STV_DEFAULT   0
#define STV_INTERNAL  1
#define STV_HIDDEN    2
#define STV_PROTECTED 3

#define ELFCOMPRESS_ZLIB    1
#define ELFCOMPRESS_LOOS    2
#define ELFCOMPRESS_HIOS    3
#define ELFCOMPRESS_LOPROC  4
#define ELFCOMPRESS_HIPROC  5

#define GRP_COMDAT 1

#define SYMINFO_BT_SELF       1
#define SYMINFO_BT_PARENT     2
#define SYMINFO_BT_LOWRESERVE 3

#define SYMINFO_FLG_DIRECT   (1 << 0)
#define SYMINFO_FLG_PASSTHRU (1 << 1)
#define SYMINFO_FLG_COPY     (1 << 2)
#define SYMINFO_FLG_LAZYLOAD (1 << 3)

#define SYMINFO_NONE    0
#define SYMINFO_CURRENT 1
#define SYMINFO_NUM 2

#define DT_NULL            0
#define DT_NEEDED          1
#define DT_PLTRELSZ        2
#define DT_PLTGOT          3
#define DT_HASH            4
#define DT_STRTAB          5
#define DT_SYMTAB          6
#define DT_RELA            7
#define DT_RELASZ          8
#define DT_RELAENT         9
#define DT_STRSZ           10
#define DT_SYMENT          11
#define DT_INIT            12
#define DT_FINI            13
#define DT_SONAME          14
#define DT_RPATH           15
#define DT_SYMBOLIC        16
#define DT_REL             17
#define DT_RELSZ           18
#define DT_RELENT          19
#define DT_PLTREL          20
#define DT_DEBUG           21
#define DT_TEXTREL         22
#define DT_JMPREL          23
#define DT_BIND_NOW        24
#define DT_INIT_ARRAY      25
#define DT_FINI_ARRAY      26
#define DT_INIT_ARRAYSZ    27
#define DT_FINI_ARRAYSZ    28
#define DT_RUNPATH         29
#define DT_FLAGS           30
#define DT_ENCODING        31
#define DT_PREINIT_ARRAY   32
#define DT_PREINIT_ARRAYSZ 33
#define DT_NUM             34
#define DT_LOOS            35
#define DT_HIOS            36
#define DT_LOPROC          37
#define DT_HIPROC          38
#define DT_PROCNUM  DT_MIPS_NUM

#define DT_ALPHA_PLTRO      (DT_LOPROC + 0)
#define DT_ALPHA_NUM        1

#define DT_ADDRRNGLO    0x6ffffe00
#define DT_GNU_HASH     0x6ffffef5
#define DT_TLSDESC_PLT  0x6ffffef6
#define DT_TLSDESC_GOT  0x6ffffef7
#define DT_GNU_CONFLICT 0x6ffffef8
#define DT_GNU_LIBLIST  0x6ffffef9
#define DT_CONFIG       0x6ffffefa
#define DT_DEPAUDIT     0x6ffffefb
#define DT_AUDIT        0x6ffffefc
#define DT_PLTPAD       0x6ffffefd
#define DT_MOVETAB      0x6ffffefe
#define DT_SYMINFO      0x6ffffeff
#define DT_ADDRRNGHI    0x6ffffeff
#define DT_ADDRTAGIDX(tag)  (DT_ADDRRNGHI - (tag))
#define DT_ADDRNUM 11

#define DT_AUXILIARY    0x7ffffffd
#define DT_FILTER       0x7fffffff
#define DT_EXTRATAGIDX(tag) ((Elf32_Word)-((Elf32_Sword) (tag) <<1>>1)-1)
#define DT_EXTRANUM 3

#define DT_VALRNGLO       0x6ffffd00
#define DT_GNU_PRELINKED  0x6ffffdf5
#define DT_GNU_CONFLICTSZ 0x6ffffdf6
#define DT_GNU_LIBLISTSZ  0x6ffffdf7
#define DT_CHECKSUM       0x6ffffdf8
#define DT_PLTPADSZ       0x6ffffdf9
#define DT_MOVEENT        0x6ffffdfa
#define DT_MOVESZ         0x6ffffdfb
#define DT_FEATURE_1      0x6ffffdfc
#define DT_POSFLAG_1      0x6ffffdfd
#define DT_SYMINSZ        0x6ffffdfe
#define DT_SYMINENT       0x6ffffdff
#define DT_VALRNGHI       0x6ffffdff
#define DT_VALTAGIDX(tag)   (DT_VALRNGHI - (tag))
#define DT_VALNUM 12

#define DT_VERSYM    0x6ffffff0
#define DT_RELACOUNT 0x6ffffff9
#define DT_RELCOUNT  0x6ffffffa

#define DT_FLAGS_1    0x6ffffffb
#define DT_VERDEF     0x6ffffffc
#define DT_VERDEFNUM  0x6ffffffd
#define DT_VERNEED    0x6ffffffe
#define DT_VERNEEDNUM 0x6fffffff
#define DT_VERSIONTAGIDX(tag)   (DT_VERNEEDNUM - (tag))
#define DT_VERSIONTAGNUM 16

#define AT_NULL             0
#define AT_IGNORE           1
#define AT_EXECFD           2
#define AT_PHDR             3
#define AT_PHENT            4
#define AT_PHNUM            5
#define AT_PAGESZ           6
#define AT_BASE             7
#define AT_FLAGS            8
#define AT_ENTRY            9
#define AT_NOTELF           10
#define AT_UID              11
#define AT_EUID             12
#define AT_GID              13
#define AT_EGID             14
#define AT_CLKTCK           17
#define AT_PLATFORM         15
#define AT_HWCAP            16
#define AT_FPUCW            18
#define AT_DCACHEBSIZE      19
#define AT_ICACHEBSIZE      20
#define AT_UCACHEBSIZE      21
#define AT_IGNOREPPC        22
#define AT_SECURE           23
#define AT_BASE_PLATFORM    24
#define AT_RANDOM           25
#define AT_HWCAP2           26
#define AT_EXECFN           31
#define AT_SYSINFO          32
#define AT_SYSINFO_EHDR     33
#define AT_L1I_CACHESHAPE   34
#define AT_L1D_CACHESHAPE   35
#define AT_L2_CACHESHAPE    36
#define AT_L3_CACHESHAPE    37

#define DF_ORIGIN     (1 << 0)
#define DF_SYMBOLIC   (1 << 1)
#define DF_TEXTREL    (1 << 2)
#define DF_BIND_NOW   (1 << 3)
#define DF_STATIC_TLS (1 << 4)

#define DF_1_NOW        (1 << 0)
#define DF_1_GLOBAL     (1 << 1)
#define DF_1_GROUP      (1 << 2)
#define DF_1_NODELETE   (1 << 3)
#define DF_1_LOADFLTR   (1 << 4)
#define DF_1_INITFIRST  (1 << 5)
#define DF_1_NOOPEN     (1 << 6)
#define DF_1_ORIGIN     (1 << 7)
#define DF_1_DIRECT     (1 << 8)
#define DF_1_TRANS      (1 << 9)
#define DF_1_INTERPOSE  (1 << 10)
#define DF_1_NODEFLIB   (1 << 11)
#define DF_1_NODUMP     (1 << 12)
#define DF_1_CONFALT    (1 << 13)
#define DF_1_ENDFILTEE  (1 << 14)
#define DF_1_DISPRELDNE (1 << 15)
#define DF_1_DISPRELPND (1 << 16)
#define DF_1_NODIRECT   (1 << 17)
#define DF_1_IGNMULDEF  (1 << 18)
#define DF_1_NOKSYMS    (1 << 19)
#define DF_1_NOHDR      (1 << 20)
#define DF_1_EDITED     (1 << 21)
#define DF_1_NORELOC    (1 << 22)
#define DF_1_SYMINTPOSE (1 << 23)
#define DF_1_GLOBAUDIT  (1 << 24)
#define DF_1_SINGLETON  (1 << 25)

#define DTF_1_PARINIT (1 << 0)
#define DTF_1_CONFEXP (1 << 1)

#define DF_P1_LAZYLOAD  (1 << 0)
#define DF_P1_GROUPPERM (1 << 1)

#define VER_DEF_NONE    0
#define VER_DEF_CURRENT 1
#define VER_DEF_NUM     2

#define VER_FLG_BASE (1 << 0)
#define VER_FLG_WEAK (1 << 1)

#define VER_NDX_LOCAL       0
#define VER_NDX_GLOBAL      1
#define VER_NDX_LORESERVE   2
#define VER_NDX_ELIMINATE   3

#define VER_NEED_NONE    0
#define VER_NEED_CURRENT 1
#define VER_NEED_NUM     2

#define EI_NIDENT 16

#define ELF_NOTE_SOLARIS "SUNW Solaris"
#define ELF_NOTE_GNU     "GNU"

#define ELF_NOTE_PAGESIZE_HINT 1

#define NT_GNU_ABI_TAG 1
#define ELF_NOTE_ABI   NT_GNU_ABI_TAG

#define ELF_NOTE_OS_LINUX    0
#define ELF_NOTE_OS_GNU      1
#define ELF_NOTE_OS_SOLARIS2 2
#define ELF_NOTE_OS_FREEBSD  3

#define NT_GNU_HWCAP        2
#define NT_GNU_BUILD_ID     3
#define NT_GNU_GOLD_VERSION 4

#define EF_CPU32 0x00810000
#define STT_SPARC_REGISTER 13
#define DT_SPARC_REGISTER 0x70000001
#define DT_SPARC_NUM 2
#define STB_MIPS_SPLIT_COMMON 13

#define R_68K_NONE         0
#define R_68K_32           1
#define R_68K_16           2
#define R_68K_8            3
#define R_68K_PC32         4
#define R_68K_PC16         5
#define R_68K_PC8          6
#define R_68K_GOT32        7
#define R_68K_GOT16        8
#define R_68K_GOT8         9
#define R_68K_GOT32O       10
#define R_68K_GOT16O       11
#define R_68K_GOT8O        12
#define R_68K_PLT32        13
#define R_68K_PLT16        14
#define R_68K_PLT8         15
#define R_68K_PLT32O       16
#define R_68K_PLT16O       17
#define R_68K_PLT8O        18
#define R_68K_COPY         19
#define R_68K_GLOB_DAT     20
#define R_68K_JMP_SLOT     21
#define R_68K_RELATIVE     22
#define R_68K_TLS_GD32     23
#define R_68K_TLS_GD16     24
#define R_68K_TLS_GD8      25
#define R_68K_TLS_LDM32    26
#define R_68K_TLS_LDM16    27
#define R_68K_TLS_LDM8     28
#define R_68K_TLS_LDO32    29
#define R_68K_TLS_LDO16    30
#define R_68K_TLS_LDO8     31
#define R_68K_TLS_IE32     32
#define R_68K_TLS_IE16     33
#define R_68K_TLS_IE8      34
#define R_68K_TLS_LE32     35
#define R_68K_TLS_LE16     36
#define R_68K_TLS_LE8      37
#define R_68K_TLS_DTPMOD32 38
#define R_68K_TLS_DTPREL32 39
#define R_68K_TLS_TPREL32  40
#define R_68K_NUM          41

#define R_386_NONE          0
#define R_386_32            1
#define R_386_PC32          2
#define R_386_GOT32         3
#define R_386_PLT32         4
#define R_386_COPY          5
#define R_386_GLOB_DAT      6
#define R_386_JMP_SLOT      7
#define R_386_RELATIVE      8
#define R_386_GOTOFF        9
#define R_386_GOTPC         10
#define R_386_32PLT         11
#define R_386_TLS_TPOFF     12
#define R_386_TLS_IE        13
#define R_386_TLS_GOTIE     14
#define R_386_TLS_LE        15
#define R_386_TLS_GD        16
#define R_386_TLS_LDM       17
#define R_386_16            18
#define R_386_PC16          19
#define R_386_8             20
#define R_386_PC8           21
#define R_386_TLS_GD_32     22
#define R_386_TLS_GD_PUSH   23
#define R_386_TLS_GD_CALL   24
#define R_386_TLS_GD_POP    25
#define R_386_TLS_LDM_32    26
#define R_386_TLS_LDM_PUSH  27
#define R_386_TLS_LDM_CALL  28
#define R_386_TLS_LDM_POP   29
#define R_386_TLS_LDO_32    30
#define R_386_TLS_IE_32     31
#define R_386_TLS_LE_32     32
#define R_386_TLS_DTPMOD32  33
#define R_386_TLS_DTPOFF32  34
#define R_386_TLS_TPOFF32   35
#define R_386_SIZE32        36
#define R_386_TLS_GOTDESC   37
#define R_386_TLS_DESC_CALL 38
#define R_386_TLS_DESC      39
#define R_386_IRELATIVE     40
#define R_386_NUM           41

#define EF_SPARCV9_MM     0
#define EF_SPARCV9_TSO    1
#define EF_SPARCV9_PSO    2
#define EF_SPARCV9_RMO    3
#define EF_SPARC_LEDATA   4
#define EF_SPARC_EXT_MASK 5
#define EF_SPARC_32PLUS   6
#define EF_SPARC_SUN_US1  7
#define EF_SPARC_HAL_R1   8
#define EF_SPARC_SUN_US3  9

#define R_SPARC_NONE             0
#define R_SPARC_8                1
#define R_SPARC_16               2
#define R_SPARC_32               3
#define R_SPARC_DISP8            4
#define R_SPARC_DISP16           5
#define R_SPARC_DISP32           6
#define R_SPARC_WDISP30          7
#define R_SPARC_WDISP22          8
#define R_SPARC_HI22             9
#define R_SPARC_22               10
#define R_SPARC_13               11
#define R_SPARC_LO10             12
#define R_SPARC_GOT10            13
#define R_SPARC_GOT13            14
#define R_SPARC_GOT22            15
#define R_SPARC_PC10             16
#define R_SPARC_PC22             17
#define R_SPARC_WPLT30           18
#define R_SPARC_COPY             19
#define R_SPARC_GLOB_DAT         20
#define R_SPARC_JMP_SLOT         21
#define R_SPARC_RELATIVE         22
#define R_SPARC_UA32             23
#define R_SPARC_PLT32            24
#define R_SPARC_HIPLT22          25
#define R_SPARC_LOPLT10          26
#define R_SPARC_PCPLT32          27
#define R_SPARC_PCPLT22          28
#define R_SPARC_PCPLT10          29
#define R_SPARC_10               30
#define R_SPARC_11               31
#define R_SPARC_64               32
#define R_SPARC_OLO10            33
#define R_SPARC_HH22             34
#define R_SPARC_HM10             35
#define R_SPARC_LM22             36
#define R_SPARC_PC_HH22          37
#define R_SPARC_PC_HM10          38
#define R_SPARC_PC_LM22          39
#define R_SPARC_WDISP16          40
#define R_SPARC_WDISP19          41
#define R_SPARC_GLOB_JMP         42
#define R_SPARC_7                43
#define R_SPARC_5                44
#define R_SPARC_6                45
#define R_SPARC_DISP64           46
#define R_SPARC_PLT64            47
#define R_SPARC_HIX22            48
#define R_SPARC_LOX10            49
#define R_SPARC_H44              50
#define R_SPARC_M44              51
#define R_SPARC_L44              52
#define R_SPARC_REGISTER         53
#define R_SPARC_UA64             54
#define R_SPARC_UA16             55
#define R_SPARC_TLS_GD_HI22      56
#define R_SPARC_TLS_GD_LO10      57
#define R_SPARC_TLS_GD_ADD       58
#define R_SPARC_TLS_GD_CALL      59
#define R_SPARC_TLS_LDM_HI22     60
#define R_SPARC_TLS_LDM_LO10     61
#define R_SPARC_TLS_LDM_ADD      62
#define R_SPARC_TLS_LDM_CALL     63
#define R_SPARC_TLS_LDO_HIX22    64
#define R_SPARC_TLS_LDO_LOX10    65
#define R_SPARC_TLS_LDO_ADD      66
#define R_SPARC_TLS_IE_HI22      67
#define R_SPARC_TLS_IE_LO10      68
#define R_SPARC_TLS_IE_LD        69
#define R_SPARC_TLS_IE_LDX       70
#define R_SPARC_TLS_IE_ADD       71
#define R_SPARC_TLS_LE_HIX22     72
#define R_SPARC_TLS_LE_LOX10     73
#define R_SPARC_TLS_DTPMOD32     74
#define R_SPARC_TLS_DTPMOD64     75
#define R_SPARC_TLS_DTPOFF32     76
#define R_SPARC_TLS_DTPOFF64     77
#define R_SPARC_TLS_TPOFF32      78
#define R_SPARC_TLS_TPOFF64      79
#define R_SPARC_GOTDATA_HIX22    80
#define R_SPARC_GOTDATA_LOX10    81
#define R_SPARC_GOTDATA_OP_HIX22 82
#define R_SPARC_GOTDATA_OP_LOX10 83
#define R_SPARC_GOTDATA_OP       84
#define R_SPARC_H34              85
#define R_SPARC_SIZE32           86
#define R_SPARC_SIZE64           87
#define R_SPARC_WDISP10          88
#define R_SPARC_JMP_IREL         89
#define R_SPARC_IRELATIVE        90
#define R_SPARC_GNU_VTINHERIT    91
#define R_SPARC_GNU_VTENTRY      92
#define R_SPARC_REV32            93
#define R_SPARC_NUM              94

#define EF_MIPS_NOREORDER   (1 << 0)
#define EF_MIPS_PIC         (1 << 1)
#define EF_MIPS_CPIC        (1 << 2)
#define EF_MIPS_XGOT        (1 << 3)
#define EF_MIPS_64BIT_WHIRL (1 << 4)
#define EF_MIPS_ABI2        (1 << 5)
#define EF_MIPS_ABI_ON32    (1 << 6)
#define EF_MIPS_FP64        (1 << 7)
#define EF_MIPS_NAN2008     (1 << 8)
#define EF_MIPS_ARCH        0xf0000000

#define EF_MIPS_ARCH_1    1
#define EF_MIPS_ARCH_2    2
#define EF_MIPS_ARCH_3    3
#define EF_MIPS_ARCH_4    4
#define EF_MIPS_ARCH_5    5
#define EF_MIPS_ARCH_32   6
#define EF_MIPS_ARCH_64   7
#define EF_MIPS_ARCH_32R2 8
#define EF_MIPS_ARCH_64R2 9

#define E_MIPS_ARCH_1  EF_MIPS_ARCH_1
#define E_MIPS_ARCH_2  EF_MIPS_ARCH_2
#define E_MIPS_ARCH_3  EF_MIPS_ARCH_3
#define E_MIPS_ARCH_4  EF_MIPS_ARCH_4
#define E_MIPS_ARCH_5  EF_MIPS_ARCH_5
#define E_MIPS_ARCH_32 EF_MIPS_ARCH_32
#define E_MIPS_ARCH_64 EF_MIPS_ARCH_64

#define SHN_MIPS_ACOMMON    0
#define SHN_MIPS_TEXT       1
#define SHN_MIPS_DATA       2
#define SHN_MIPS_SCOMMON    3
#define SHN_MIPS_SUNDEFINED 4

#define SHT_MIPS_LIBLIST       0x70000000
#define SHT_MIPS_MSYM          0x70000001
#define SHT_MIPS_CONFLICT      0x70000002
#define SHT_MIPS_GPTAB         0x70000003
#define SHT_MIPS_UCODE         0x70000004
#define SHT_MIPS_DEBUG         0x70000005
#define SHT_MIPS_REGINFO       0x70000006
#define SHT_MIPS_PACKAGE       0x70000007
#define SHT_MIPS_PACKSYM       0x70000008
#define SHT_MIPS_RELD          0x70000009
#define SHT_MIPS_IFACE         0x7000000b
#define SHT_MIPS_CONTENT       0x7000000c
#define SHT_MIPS_OPTIONS       0x7000000d
#define SHT_MIPS_SHDR          0x70000010
#define SHT_MIPS_FDESC         0x70000011
#define SHT_MIPS_EXTSYM        0x70000012
#define SHT_MIPS_DENSE         0x70000013
#define SHT_MIPS_PDESC         0x70000014
#define SHT_MIPS_LOCSYM        0x70000015
#define SHT_MIPS_AUXSYM        0x70000016
#define SHT_MIPS_OPTSYM        0x70000017
#define SHT_MIPS_LOCSTR        0x70000018
#define SHT_MIPS_LINE          0x70000019
#define SHT_MIPS_RFDESC        0x7000001a
#define SHT_MIPS_DELTASYM      0x7000001b
#define SHT_MIPS_DELTAINST     0x7000001c
#define SHT_MIPS_DELTACLASS    0x7000001d
#define SHT_MIPS_DWARF         0x7000001e
#define SHT_MIPS_DELTADECL     0x7000001f
#define SHT_MIPS_SYMBOL_LIB    0x70000020
#define SHT_MIPS_EVENTS        0x70000021
#define SHT_MIPS_TRANSLATE     0x70000022
#define SHT_MIPS_PIXIE         0x70000023
#define SHT_MIPS_XLATE         0x70000024
#define SHT_MIPS_XLATE_DEBUG   0x70000025
#define SHT_MIPS_WHIRL         0x70000026
#define SHT_MIPS_EH_REGION     0x70000027
#define SHT_MIPS_XLATE_OLD     0x70000028
#define SHT_MIPS_PDR_EXCEPTION 0x70000029

#define SHF_MIPS_GPREL      0x10000000
#define SHF_MIPS_MERGE      0x20000000
#define SHF_MIPS_ADDR       0x40000000
#define SHF_MIPS_STRINGS    0x80000000
#define SHF_MIPS_NOSTRIP    0x08000000
#define SHF_MIPS_LOCAL      0x04000000
#define SHF_MIPS_NAMES      0x02000000
#define SHF_MIPS_NODUPE     0x01000000

#define STO_MIPS_DEFAULT         (1 << 0)
#define STO_MIPS_INTERNAL        (1 << 1)
#define STO_MIPS_HIDDEN          (1 << 2)
#define STO_MIPS_PROTECTED       (1 << 3)
#define STO_MIPS_PLT             (1 << 4)
#define STO_MIPS_SC_ALIGN_UNUSED (1 << 5)

#define ODK_NULL       0
#define ODK_REGINFO    1
#define ODK_EXCEPTIONS 2
#define ODK_PAD        3
#define ODK_HWPATCH    4
#define ODK_FILL       5
#define ODK_TAGS       6
#define ODK_HWAND      7
#define ODK_HWOR       8

#define OEX_FPU_MIN   0x0001f
#define OEX_FPU_MAX   0x01f00
#define OEX_PAGE0     0x10000
#define OEX_SMM       0x20000
#define OEX_FPDBUG    0x40000
#define OEX_PRECISEFP OEX_FPDBUG
#define OEX_DISMISS   0x80000

#define OEX_FPU_INEX  (1 << 0)
#define OEX_FPU_UFLO  (1 << 1)
#define OEX_FPU_OFLO  (1 << 2)
#define OEX_FPU_DIV0  (1 << 3)
#define OEX_FPU_INVAL (1 << 4)

#define OHW_R4KEOP    (1 << 0)
#define OHW_R8KPFETCH (1 << 1)
#define OHW_R5KEOP    (1 << 2)
#define OHW_R5KCVTL   (1 << 3)

#define OPAD_PREFIX  (1 << 0)
#define OPAD_POSTFIX (1 << 1)
#define OPAD_SYMBOL  (1 << 2)

#define OHWA0_R4KEOP_CHECKED (1 << 0)
#define OHWA1_R4KEOP_CLEAN   (1 << 1)

#define R_MIPS_NONE            0
#define R_MIPS_16              1
#define R_MIPS_32              2
#define R_MIPS_REL32           3
#define R_MIPS_26              4
#define R_MIPS_HI16            5
#define R_MIPS_LO16            6
#define R_MIPS_GPREL16         4
#define R_MIPS_LITERAL         5
#define R_MIPS_GOT16           6
#define R_MIPS_PC16            7
#define R_MIPS_CALL16          8
#define R_MIPS_GPREL32         9
#define R_MIPS_SHIFT5          10
#define R_MIPS_SHIFT6          11
#define R_MIPS_64              12
#define R_MIPS_GOT_DISP        13
#define R_MIPS_GOT_PAGE        14
#define R_MIPS_GOT_OFST        15
#define R_MIPS_GOT_HI16        16
#define R_MIPS_GOT_LO16        17
#define R_MIPS_SUB             18
#define R_MIPS_INSERT_A        19
#define R_MIPS_INSERT_B        20
#define R_MIPS_DELETE          21
#define R_MIPS_HIGHER          22
#define R_MIPS_HIGHEST         23
#define R_MIPS_CALL_HI16       24
#define R_MIPS_CALL_LO16       25
#define R_MIPS_SCN_DISP        26
#define R_MIPS_REL16           27
#define R_MIPS_ADD_IMMEDIATE   28
#define R_MIPS_PJUMP           29
#define R_MIPS_RELGOT          30
#define R_MIPS_JALR            31
#define R_MIPS_TLS_DTPMOD32    32
#define R_MIPS_TLS_DTPREL32    33
#define R_MIPS_TLS_DTPMOD64    34
#define R_MIPS_TLS_DTPREL64    35
#define R_MIPS_TLS_GD          36
#define R_MIPS_TLS_LDM         37
#define R_MIPS_TLS_DTPREL_HI16 38
#define R_MIPS_TLS_DTPREL_LO16 39
#define R_MIPS_TLS_GOTTPREL    40
#define R_MIPS_TLS_TPREL32     41
#define R_MIPS_TLS_TPREL64     42
#define R_MIPS_TLS_TPREL_HI16  43
#define R_MIPS_TLS_TPREL_LO16  44
#define R_MIPS_GLOB_DAT        45
#define R_MIPS_COPY            46
#define R_MIPS_JUMP_SLOT       47
#define R_MIPS_NUM             48

#define PT_MIPS_REGINFO  0
#define PT_MIPS_RTPROC   1
#define PT_MIPS_OPTIONS  2
#define PT_MIPS_ABIFLAGS 3

#define PF_MIPS_LOCAL 0x10000000

#define DT_MIPS_RLD_VERSION           0x70000001
#define DT_MIPS_TIME_STAMP            0x70000002
#define DT_MIPS_ICHECKSUM             0x70000003
#define DT_MIPS_IVERSION              0x70000004
#define DT_MIPS_FLAGS                 0x70000005
#define DT_MIPS_BASE_ADDRESS          0x70000006
#define DT_MIPS_MSYM                  0x70000007
#define DT_MIPS_CONFLICT              0x70000008
#define DT_MIPS_LIBLIST               0x70000009
#define DT_MIPS_LOCAL_GOTNO           0x7000000a
#define DT_MIPS_CONFLICTNO            0x7000000b
#define DT_MIPS_LIBLISTNO             0x70000010
#define DT_MIPS_SYMTABNO              0x70000011
#define DT_MIPS_UNREFEXTNO            0x70000012
#define DT_MIPS_GOTSYM                0x70000013
#define DT_MIPS_HIPAGENO              0x70000014
#define DT_MIPS_RLD_MAP               0x70000016
#define DT_MIPS_DELTA_CLASS           0x70000017
#define DT_MIPS_DELTA_CLASS_NO        0x70000018
#define DT_MIPS_DELTA_INSTANCE        0x70000019
#define DT_MIPS_DELTA_INSTANCE_NO     0x7000001a
#define DT_MIPS_DELTA_RELOC           0x7000001b
#define DT_MIPS_DELTA_RELOC_NO        0x7000001c
#define DT_MIPS_DELTA_SYM             0x7000001d
#define DT_MIPS_DELTA_SYM_NO          0x7000001e
#define DT_MIPS_DELTA_CLASSSYM        0x70000020
#define DT_MIPS_DELTA_CLASSSYM_NO     0x70000021
#define DT_MIPS_CXX_FLAGS             0x70000022
#define DT_MIPS_PIXIE_INIT            0x70000023
#define DT_MIPS_SYMBOL_LIB            0x70000024
#define DT_MIPS_LOCALPAGE_GOTIDX      0x70000025
#define DT_MIPS_LOCAL_GOTIDX          0x70000026
#define DT_MIPS_HIDDEN_GOTIDX         0x70000027
#define DT_MIPS_PROTECTED_GOTIDX      0x70000028
#define DT_MIPS_OPTIONS               0x70000029
#define DT_MIPS_INTERFACE             0x7000002a
#define DT_MIPS_DYNSTR_ALIGN          0x7000002b
#define DT_MIPS_INTERFACE_SIZE        0x7000002c
#define DT_MIPS_RLD_TEXT_RESOLVE_ADDR 0x7000002d
#define DT_MIPS_PERF_SUFFIX           0x7000002e
#define DT_MIPS_COMPACT_SIZE          0x7000002f
#define DT_MIPS_GP_VALUE              0x70000030
#define DT_MIPS_AUX_DYNAMIC           0x70000031
#define DT_MIPS_PLTGOT                0x70000032
#define DT_MIPS_RWPLT                 0x70000034
#define DT_MIPS_RLD_MAP_REL           0x70000035
#define DT_MIPS_NUM                   0x36

#define RHF_NONE                   0
#define RHF_QUICKSTART             (1 << 0)
#define RHF_NOTPOT                 (1 << 1)
#define RHF_NO_LIBRARY_REPLACEMENT (1 << 2)
#define RHF_NO_MOVE                (1 << 3)
#define RHF_SGI_ONLY               (1 << 4)
#define RHF_GUARANTEE_INIT         (1 << 5)
#define RHF_DELTA_C_PLUS_PLUS      (1 << 6)
#define RHF_GUARANTEE_START_INIT   (1 << 7)
#define RHF_PIXIE                  (1 << 8)
#define RHF_DEFAULT_DELAY_LOAD     (1 << 9)
#define RHF_REQUICKSTART           (1 << 10)
#define RHF_REQUICKSTARTED         (1 << 11)
#define RHF_CORD                   (1 << 12)
#define RHF_NO_UNRES_UNDEF         (1 << 13)
#define RHF_RLD_ORDER_SAFE         (1 << 14)

#define LL_NONE           0
#define LL_EXACT_MATCH    (1 << 0)
#define LL_IGNORE_INT_VER (1 << 1)
#define LL_REQUIRE_MINOR  (1 << 2)
#define LL_EXPORTS        (1 << 3)
#define LL_DELAY_LOAD     (1 << 4)
#define LL_DELTA          (1 << 5)

#define MIPS_AFL_REG_NONE 0
#define MIPS_AFL_REG_32   1
#define MIPS_AFL_REG_64   2
#define MIPS_AFL_REG_128  3

#define MIPS_AFL_ASE_DSP       (1 << 0)
#define MIPS_AFL_ASE_DSPR2     (1 << 1)
#define MIPS_AFL_ASE_EVA       (1 << 2)
#define MIPS_AFL_ASE_MCU       (1 << 3)
#define MIPS_AFL_ASE_MDMX      (1 << 4)
#define MIPS_AFL_ASE_MIPS3D    (1 << 5)
#define MIPS_AFL_ASE_MT        (1 << 6)
#define MIPS_AFL_ASE_SMARTMIPS (1 << 7)
#define MIPS_AFL_ASE_VIRT      (1 << 8)
#define MIPS_AFL_ASE_MSA       (1 << 9)
#define MIPS_AFL_ASE_MIPS16    (1 << 10)
#define MIPS_AFL_ASE_MICROMIPS (1 << 11)
#define MIPS_AFL_ASE_XPA       (1 << 12)
#define MIPS_AFL_ASE_MASK      0x00001fff

#define MIPS_AFL_EXT_XLR         1
#define MIPS_AFL_EXT_OCTEON2     2
#define MIPS_AFL_EXT_OCTEONP     3
#define MIPS_AFL_EXT_LOONGSON_3A 4
#define MIPS_AFL_EXT_OCTEON      5
#define MIPS_AFL_EXT_5900        6
#define MIPS_AFL_EXT_4650        7
#define MIPS_AFL_EXT_4010        8
#define MIPS_AFL_EXT_4100        9
#define MIPS_AFL_EXT_3900        10
#define MIPS_AFL_EXT_10000       11
#define MIPS_AFL_EXT_SB1         12
#define MIPS_AFL_EXT_4111        13
#define MIPS_AFL_EXT_4120        14
#define MIPS_AFL_EXT_5400        15
#define MIPS_AFL_EXT_5500        16
#define MIPS_AFL_EXT_LOONGSON_2E 17
#define MIPS_AFL_EXT_LOONGSON_2F 18

#define MIPS_AFL_FLAGS1_ODDSPREG 1

#define Val_GNU_MIPS_ABI_FP_ANY    0
#define Val_GNU_MIPS_ABI_FP_DOUBLE 1
#define Val_GNU_MIPS_ABI_FP_SINGLE 2
#define Val_GNU_MIPS_ABI_FP_SOFT   3
#define Val_GNU_MIPS_ABI_FP_OLD_64 4
#define Val_GNU_MIPS_ABI_FP_XX     5
#define Val_GNU_MIPS_ABI_FP_64     6
#define Val_GNU_MIPS_ABI_FP_64A    7
#define Val_GNU_MIPS_ABI_FP_MAX    8

#define EF_PARISC_TRAPNIL   0x00010000
#define EF_PARISC_EXT       0x00020000
#define EF_PARISC_LSB       0x00040000
#define EF_PARISC_WIDE      0x00080000
#define EF_PARISC_NO_KABP   0x00100000
#define EF_PARISC_LAZYSWAP  0x00400000
#define EF_PARISC_ARCH      0x0000ffff

#define EFA_PARISC_1_0 0x020b
#define EFA_PARISC_1_1 0x0210
#define EFA_PARISC_2_0 0x0214

#define SHN_PARISC_ANSI_COMMON 0xff00
#define SHN_PARISC_HUGE_COMMON 0xff01

#define SHT_PARISC_EXT    0x70000000
#define SHT_PARISC_UNWIND 0x70000001
#define SHT_PARISC_DOC    0x70000002

#define SHF_PARISC_SHORT 0x20000000
#define SHF_PARISC_HUGE  0x40000000
#define SHF_PARISC_SBP   0x80000000

#define STT_PARISC_MILLICODE 13

#define STT_HP_OPAQUE (STT_LOOS + 0x1)
#define STT_HP_STUB   (STT_LOOS + 0x2)

#define R_PARISC_NONE           0
#define R_PARISC_DIR32          1
#define R_PARISC_DIR21L         2
#define R_PARISC_DIR17R         3
#define R_PARISC_DIR17F         4
#define R_PARISC_DIR14R         5
#define R_PARISC_PCREL32        6
#define R_PARISC_PCREL21L       7
#define R_PARISC_PCREL17R       8
#define R_PARISC_PCREL17F       9
#define R_PARISC_PCREL14R       10
#define R_PARISC_DPREL21L       11
#define R_PARISC_DPREL14R       12
#define R_PARISC_GPREL21L       13
#define R_PARISC_GPREL14R       14
#define R_PARISC_LTOFF21L       15
#define R_PARISC_LTOFF14R       16
#define R_PARISC_SECREL32       17
#define R_PARISC_SEGBASE        18
#define R_PARISC_SEGREL32       19
#define R_PARISC_PLTOFF21L      20
#define R_PARISC_PLTOFF14R      21
#define R_PARISC_LTOFF_FPTR32   22
#define R_PARISC_LTOFF_FPTR21L  23
#define R_PARISC_LTOFF_FPTR14R  24
#define R_PARISC_FPTR64         25
#define R_PARISC_PLABEL32       26
#define R_PARISC_PLABEL21L      27
#define R_PARISC_PLABEL14R      28
#define R_PARISC_PCREL64        29
#define R_PARISC_PCREL22F       30
#define R_PARISC_PCREL14WR      31
#define R_PARISC_PCREL14DR      32
#define R_PARISC_PCREL16F       33
#define R_PARISC_PCREL16WF      34
#define R_PARISC_PCREL16DF      35
#define R_PARISC_DIR64          36
#define R_PARISC_DIR14WR        37
#define R_PARISC_DIR14DR        38
#define R_PARISC_DIR16F         39
#define R_PARISC_DIR16WF        40
#define R_PARISC_DIR16DF        41
#define R_PARISC_GPREL64        42
#define R_PARISC_GPREL14WR      43
#define R_PARISC_GPREL14DR      44
#define R_PARISC_GPREL16F       45
#define R_PARISC_GPREL16WF      46
#define R_PARISC_GPREL16DF      47
#define R_PARISC_LTOFF64        48
#define R_PARISC_LTOFF14WR      49
#define R_PARISC_LTOFF14DR      50
#define R_PARISC_LTOFF16F       51
#define R_PARISC_LTOFF16WF      52
#define R_PARISC_LTOFF16DF      53
#define R_PARISC_SECREL64       54
#define R_PARISC_SEGREL64       55
#define R_PARISC_PLTOFF14WR     56
#define R_PARISC_PLTOFF14DR     57
#define R_PARISC_PLTOFF16F      58
#define R_PARISC_PLTOFF16WF     59
#define R_PARISC_PLTOFF16DF     60
#define R_PARISC_LTOFF_FPTR64   61
#define R_PARISC_LTOFF_FPTR14WR 62
#define R_PARISC_LTOFF_FPTR14DR 63
#define R_PARISC_LTOFF_FPTR16F  64
#define R_PARISC_LTOFF_FPTR16WF 65
#define R_PARISC_LTOFF_FPTR16DF 66
#define R_PARISC_LORESERVE      67
#define R_PARISC_COPY           68
#define R_PARISC_IPLT           69
#define R_PARISC_EPLT           70
#define R_PARISC_TPREL32        71
#define R_PARISC_TPREL21L       72
#define R_PARISC_TPREL14R       73
#define R_PARISC_LTOFF_TP21L    74
#define R_PARISC_LTOFF_TP14R    75
#define R_PARISC_LTOFF_TP14F    76
#define R_PARISC_TPREL64        77
#define R_PARISC_TPREL14WR      78
#define R_PARISC_TPREL14DR      79
#define R_PARISC_TPREL16F       80
#define R_PARISC_TPREL16WF      81
#define R_PARISC_TPREL16DF      82
#define R_PARISC_LTOFF_TP64     83
#define R_PARISC_LTOFF_TP14WR   84
#define R_PARISC_LTOFF_TP14DR   85
#define R_PARISC_LTOFF_TP16F    86
#define R_PARISC_LTOFF_TP16WF   87
#define R_PARISC_LTOFF_TP16DF   88
#define R_PARISC_GNU_VTENTRY    89
#define R_PARISC_GNU_VTINHERIT  90
#define R_PARISC_TLS_GD21L      91
#define R_PARISC_TLS_GD14R      92
#define R_PARISC_TLS_GDCALL     93
#define R_PARISC_TLS_LDM21L     94
#define R_PARISC_TLS_LDM14R     95
#define R_PARISC_TLS_LDMCALL    96
#define R_PARISC_TLS_LDO21L     97
#define R_PARISC_TLS_LDO14R     98
#define R_PARISC_TLS_DTPMOD32   99
#define R_PARISC_TLS_DTPMOD64   100
#define R_PARISC_TLS_DTPOFF32   101
#define R_PARISC_TLS_DTPOFF64   102
#define R_PARISC_TLS_LE21L      R_PARISC_TPREL21L
#define R_PARISC_TLS_LE14R      R_PARISC_TPREL14R
#define R_PARISC_TLS_IE21L      R_PARISC_LTOFF_TP21L
#define R_PARISC_TLS_IE14R      R_PARISC_LTOFF_TP14R
#define R_PARISC_TLS_TPREL32    R_PARISC_TPREL32
#define R_PARISC_TLS_TPREL64    R_PARISC_TPREL64
#define R_PARISC_HIRESERVE      255

#define PT_HP_TLS           (PT_LOOS + 0x0)
#define PT_HP_CORE_NONE     (PT_LOOS + 0x1)
#define PT_HP_CORE_VERSION  (PT_LOOS + 0x2)
#define PT_HP_CORE_KERNEL   (PT_LOOS + 0x3)
#define PT_HP_CORE_COMM     (PT_LOOS + 0x4)
#define PT_HP_CORE_PROC     (PT_LOOS + 0x5)
#define PT_HP_CORE_LOADABLE (PT_LOOS + 0x6)
#define PT_HP_CORE_STACK    (PT_LOOS + 0x7)
#define PT_HP_CORE_SHM      (PT_LOOS + 0x8)
#define PT_HP_CORE_MMF      (PT_LOOS + 0x9)
#define PT_HP_PARALLEL      (PT_LOOS + 0x10)
#define PT_HP_FASTBIND      (PT_LOOS + 0x11)
#define PT_HP_OPT_ANNOT     (PT_LOOS + 0x12)
#define PT_HP_HSL_ANNOT     (PT_LOOS + 0x13)
#define PT_HP_STACK         (PT_LOOS + 0x14)

#define PT_PARISC_ARCHEXT 0x70000000
#define PT_PARISC_UNWIND  0x70000001

#define PF_PARISC_SBP       0x08000000
#define PF_HP_PAGE_SIZE     0x00100000
#define PF_HP_FAR_SHARED    0x00200000
#define PF_HP_NEAR_SHARED   0x00400000
#define PF_HP_CODE          0x01000000
#define PF_HP_MODIFY        0x02000000
#define PF_HP_LAZYSWAP      0x04000000
#define PF_HP_SBP           0x08000000

#define EF_ALPHA_32BIT    (1 << 0)
#define EF_ALPHA_CANRELAX (1 << 1)

#define SHT_ALPHA_DEBUG   0x70000001
#define SHT_ALPHA_REGINFO 0x70000002

#define SHF_ALPHA_GPREL 0x10000000

#define STO_ALPHA_NOPV       0x80
#define STO_ALPHA_STD_GPLOAD 0x88

#define R_ALPHA_NONE      0
#define R_ALPHA_REFLONG   1
#define R_ALPHA_REFQUAD   2
#define R_ALPHA_GPREL32   3
#define R_ALPHA_LITERAL   4
#define R_ALPHA_LITUSE    5
#define R_ALPHA_GPDISP    6
#define R_ALPHA_BRADDR    7
#define R_ALPHA_HINT      8
#define R_ALPHA_SREL16    9
#define R_ALPHA_SREL32    10
#define R_ALPHA_SREL64    11
#define R_ALPHA_GPRELHIGH 12
#define R_ALPHA_GPRELLOW  13
#define R_ALPHA_GPREL16   14
#define R_ALPHA_COPY      15
#define R_ALPHA_GLOB_DAT  16
#define R_ALPHA_JMP_SLOT  17
#define R_ALPHA_RELATIVE  18
#define R_ALPHA_TLS_GD_HI 19
#define R_ALPHA_TLSGD     20
#define R_ALPHA_TLS_LDM   21
#define R_ALPHA_DTPMOD64  22
#define R_ALPHA_GOTDTPREL 23
#define R_ALPHA_DTPREL64  24
#define R_ALPHA_DTPRELHI  25
#define R_ALPHA_DTPRELLO  26
#define R_ALPHA_DTPREL16  27
#define R_ALPHA_GOTTPREL  28
#define R_ALPHA_TPREL64   29
#define R_ALPHA_TPRELHI   30
#define R_ALPHA_TPRELLO   31
#define R_ALPHA_TPREL16   32
#define R_ALPHA_NUM       33

#define LITUSE_ALPHA_ADDR    0
#define LITUSE_ALPHA_BASE    1
#define LITUSE_ALPHA_BYTOFF  2
#define LITUSE_ALPHA_JSR     3
#define LITUSE_ALPHA_TLS_GD  4
#define LITUSE_ALPHA_TLS_LDM 5

#define DT_ALPHA_PLTRO      (DT_LOPROC + 0)
#define DT_ALPHA_NUM        1

#define EF_PPC_EMB 0x80000000

#define EF_PPC_RELOCATABLE     0x00010000
#define EF_PPC_RELOCATABLE_LIB 0x00008000

#define R_PPC_NONE            0
#define R_PPC_ADDR32          1
#define R_PPC_ADDR24          2
#define R_PPC_ADDR16          3
#define R_PPC_ADDR16_LO       4
#define R_PPC_ADDR16_HI       5
#define R_PPC_ADDR16_HA       6
#define R_PPC_ADDR14          7
#define R_PPC_ADDR14_BRTAKEN  8
#define R_PPC_ADDR14_BRNTAKEN 9
#define R_PPC_REL24           10
#define R_PPC_REL14           11
#define R_PPC_REL14_BRTAKEN   12
#define R_PPC_REL14_BRNTAKEN  13
#define R_PPC_GOT16           14
#define R_PPC_GOT16_LO        15
#define R_PPC_GOT16_HI        16
#define R_PPC_GOT16_HA        17
#define R_PPC_PLTREL24        18
#define R_PPC_COPY            19
#define R_PPC_GLOB_DAT        20
#define R_PPC_JMP_SLOT        21
#define R_PPC_RELATIVE        22
#define R_PPC_LOCAL24PC       23
#define R_PPC_UADDR32         24
#define R_PPC_UADDR16         25
#define R_PPC_REL32           26
#define R_PPC_PLT32           27
#define R_PPC_PLTREL32        28
#define R_PPC_PLT16_LO        29
#define R_PPC_PLT16_HI        30
#define R_PPC_PLT16_HA        31
#define R_PPC_SDAREL16        32
#define R_PPC_SECTOFF         33
#define R_PPC_SECTOFF_LO      34
#define R_PPC_SECTOFF_HI      35
#define R_PPC_SECTOFF_HA      36
#define R_PPC_TLS             37
#define R_PPC_DTPMOD32        38
#define R_PPC_TPREL16         39
#define R_PPC_TPREL16_LO      40
#define R_PPC_TPREL16_HI      41
#define R_PPC_TPREL16_HA      42
#define R_PPC_TPREL32         43
#define R_PPC_DTPREL16        44
#define R_PPC_DTPREL16_LO     45
#define R_PPC_DTPREL16_HI     46
#define R_PPC_DTPREL16_HA     47
#define R_PPC_DTPREL32        48
#define R_PPC_GOT_TLSGD16     49
#define R_PPC_GOT_TLSGD16_LO  50
#define R_PPC_GOT_TLSGD16_HI  51
#define R_PPC_GOT_TLSGD16_HA  52
#define R_PPC_GOT_TLSLD16     53
#define R_PPC_GOT_TLSLD16_LO  54
#define R_PPC_GOT_TLSLD16_HI  55
#define R_PPC_GOT_TLSLD16_HA  56
#define R_PPC_GOT_TPREL16     57
#define R_PPC_GOT_TPREL16_LO  58
#define R_PPC_GOT_TPREL16_HI  59
#define R_PPC_GOT_TPREL16_HA  60
#define R_PPC_GOT_DTPREL16    61
#define R_PPC_GOT_DTPREL16_LO 62
#define R_PPC_GOT_DTPREL16_HI 63
#define R_PPC_GOT_DTPREL16_HA 64
#define R_PPC_TLSGD           65
#define R_PPC_TLSLD           66
#define R_PPC_EMB_NADDR32     67
#define R_PPC_EMB_NADDR16     68
#define R_PPC_EMB_NADDR16_LO  69
#define R_PPC_EMB_NADDR16_HI  70
#define R_PPC_EMB_NADDR16_HA  71
#define R_PPC_EMB_SDAI16      72
#define R_PPC_EMB_SDA2I16     73
#define R_PPC_EMB_SDA2REL     74
#define R_PPC_EMB_SDA21       75
#define R_PPC_EMB_MRKREF      76
#define R_PPC_EMB_RELSEC16    77
#define R_PPC_EMB_RELST_LO    78
#define R_PPC_EMB_RELST_HI    79
#define R_PPC_EMB_RELST_HA    80
#define R_PPC_EMB_BIT_FLD     81
#define R_PPC_EMB_RELSDA      82
#define R_PPC_DIAB_SDA21_LO   83
#define R_PPC_DIAB_SDA21_HI   84
#define R_PPC_DIAB_SDA21_HA   85
#define R_PPC_DIAB_RELSDA_LO  86
#define R_PPC_DIAB_RELSDA_HI  87
#define R_PPC_DIAB_RELSDA_HA  88
#define R_PPC_IRELATIVE       89
#define R_PPC_REL16           90
#define R_PPC_REL16_LO        91
#define R_PPC_REL16_HI        92
#define R_PPC_REL16_HA        93
#define R_PPC_TOC16           94

#define DT_PPC_GOT (DT_LOPROC + 0)
#define DT_PPC_OPT (DT_LOPROC + 1)
#define DT_PPC_NUM 2

#define PPC_OPT_TLS     1

#define R_PPC64_NONE               0
#define R_PPC64_ADDR32             1
#define R_PPC64_ADDR24             2
#define R_PPC64_ADDR16             3
#define R_PPC64_ADDR16_LO          4
#define R_PPC64_ADDR16_HI          5
#define R_PPC64_ADDR16_HA          6
#define R_PPC64_ADDR14             7
#define R_PPC64_ADDR14_BRTAKEN     8
#define R_PPC64_ADDR14_BRNTAKEN    9
#define R_PPC64_REL24              10
#define R_PPC64_REL14              11
#define R_PPC64_REL14_BRTAKEN      12
#define R_PPC64_REL14_BRNTAKEN     13
#define R_PPC64_GOT16              14
#define R_PPC64_GOT16_LO           15
#define R_PPC64_GOT16_HI           16
#define R_PPC64_GOT16_HA           17
#define R_PPC64_COPY               18
#define R_PPC64_GLOB_DAT           19
#define R_PPC64_JMP_SLOT           20
#define R_PPC64_RELATIVE           21
#define R_PPC64_UADDR32            22
#define R_PPC64_UADDR16            23
#define R_PPC64_REL32              24
#define R_PPC64_PLT32              25
#define R_PPC64_PLTREL32           26
#define R_PPC64_PLT16_LO           27
#define R_PPC64_PLT16_HI           28
#define R_PPC64_PLT16_HA           29
#define R_PPC64_SECTOFF            30
#define R_PPC64_SECTOFF_LO         31
#define R_PPC64_SECTOFF_HI         32
#define R_PPC64_SECTOFF_HA         33
#define R_PPC64_ADDR30             34
#define R_PPC64_ADDR64             35
#define R_PPC64_ADDR16_HIGHER      36
#define R_PPC64_ADDR16_HIGHERA     37
#define R_PPC64_ADDR16_HIGHEST     38
#define R_PPC64_ADDR16_HIGHESTA    39
#define R_PPC64_UADDR64            40
#define R_PPC64_REL64              41
#define R_PPC64_PLT64              42
#define R_PPC64_PLTREL64           43
#define R_PPC64_TOC16              44
#define R_PPC64_TOC16_LO           45
#define R_PPC64_TOC16_HI           46
#define R_PPC64_TOC16_HA           47
#define R_PPC64_TOC                48
#define R_PPC64_PLTGOT16           49
#define R_PPC64_PLTGOT16_LO        50
#define R_PPC64_PLTGOT16_HI        51
#define R_PPC64_PLTGOT16_HA        52
#define R_PPC64_ADDR16_DS          53
#define R_PPC64_ADDR16_LO_DS       54
#define R_PPC64_GOT16_DS           55
#define R_PPC64_GOT16_LO_DS        56
#define R_PPC64_PLT16_LO_DS        57
#define R_PPC64_SECTOFF_DS         58
#define R_PPC64_SECTOFF_LO_DS      59
#define R_PPC64_TOC16_DS           60
#define R_PPC64_TOC16_LO_DS        61
#define R_PPC64_PLTGOT16_DS        62
#define R_PPC64_PLTGOT16_LO_DS     63
#define R_PPC64_TLS                64
#define R_PPC64_DTPMOD64           65
#define R_PPC64_TPREL16            66
#define R_PPC64_TPREL16_LO         67
#define R_PPC64_TPREL16_HI         68
#define R_PPC64_TPREL16_HA         69
#define R_PPC64_TPREL64            70
#define R_PPC64_DTPREL16           71
#define R_PPC64_DTPREL16_LO        72
#define R_PPC64_DTPREL16_HI        73
#define R_PPC64_DTPREL16_HA        74
#define R_PPC64_DTPREL64           75
#define R_PPC64_GOT_TLSGD16        76
#define R_PPC64_GOT_TLSGD16_LO     77
#define R_PPC64_GOT_TLSGD16_HI     78
#define R_PPC64_GOT_TLSGD16_HA     79
#define R_PPC64_GOT_TLSLD16        80
#define R_PPC64_GOT_TLSLD16_LO     81
#define R_PPC64_GOT_TLSLD16_HI     82
#define R_PPC64_GOT_TLSLD16_HA     83
#define R_PPC64_GOT_TPREL16_DS     84
#define R_PPC64_GOT_TPREL16_LO_DS  85
#define R_PPC64_GOT_TPREL16_HI     86
#define R_PPC64_GOT_TPREL16_HA     87
#define R_PPC64_GOT_DTPREL16_DS    88
#define R_PPC64_GOT_DTPREL16_LO_DS 89
#define R_PPC64_GOT_DTPREL16_HI    90
#define R_PPC64_GOT_DTPREL16_HA    91
#define R_PPC64_TPREL16_DS         92
#define R_PPC64_TPREL16_LO_DS      93
#define R_PPC64_TPREL16_HIGHER     94
#define R_PPC64_TPREL16_HIGHERA    95
#define R_PPC64_TPREL16_HIGHEST    96
#define R_PPC64_TPREL16_HIGHESTA   97
#define R_PPC64_DTPREL16_DS        98
#define R_PPC64_DTPREL16_LO_DS     99
#define R_PPC64_DTPREL16_HIGHER    100
#define R_PPC64_DTPREL16_HIGHERA   101
#define R_PPC64_DTPREL16_HIGHEST   102
#define R_PPC64_DTPREL16_HIGHESTA  103
#define R_PPC64_TLSGD              104
#define R_PPC64_TLSLD              105
#define R_PPC64_TOCSAVE            106
#define R_PPC64_ADDR16_HIGH        107
#define R_PPC64_ADDR16_HIGHA       108
#define R_PPC64_TPREL16_HIGH       109
#define R_PPC64_TPREL16_HIGHA      110
#define R_PPC64_DTPREL16_HIGH      111
#define R_PPC64_DTPREL16_HIGHA     112
#define R_PPC64_JMP_IREL           113
#define R_PPC64_IRELATIVE          114
#define R_PPC64_REL16              115
#define R_PPC64_REL16_LO           116
#define R_PPC64_REL16_HI           117
#define R_PPC64_REL16_HA           118

#define EF_PPC64_ABI 3

#define DT_PPC64_GLINK (DT_LOPROC + 0)
#define DT_PPC64_OPD   (DT_LOPROC + 1)
#define DT_PPC64_OPDSZ (DT_LOPROC + 2)
#define DT_PPC64_OPT   (DT_LOPROC + 3)
#define DT_PPC64_NUM   4

#define PPC64_OPT_TLS       1
#define PPC64_OPT_MULTI_TOC 2

#define STO_PPC64_LOCAL_BIT  5
#define STO_PPC64_LOCAL_MASK (7 << STO_PPC64_LOCAL_BIT)

#define EF_ARM_RELEXEC          0x01
#define EF_ARM_HASENTRY         0x02
#define EF_ARM_INTERWORK        0x04
#define EF_ARM_APCS_26          0x08
#define EF_ARM_APCS_FLOAT       0x10
#define EF_ARM_PIC              0x20
#define EF_ARM_ALIGN8           0x40
#define EF_ARM_NEW_ABI          0x80
#define EF_ARM_OLD_ABI          0x100
#define EF_ARM_SOFT_FLOAT       0x200
#define EF_ARM_VFP_FLOAT        0x400
#define EF_ARM_MAVERICK_FLOAT   0x800
#define EF_ARM_ABI_FLOAT_SOFT   0x200
#define EF_ARM_ABI_FLOAT_HARD   0x400
#define EF_ARM_SYMSARESORTED    0x04
#define EF_ARM_DYNSYMSUSESEGIDX 0x08
#define EF_ARM_MAPSYMSFIRST     0x10
#define EF_ARM_EABIMASK         0XFF000000
#define EF_ARM_BE8              0x00800000
#define EF_ARM_LE8              0x00400000
#define EF_ARM_EABI_UNKNOWN     0x00000000
#define EF_ARM_EABI_VER1        0x01000000
#define EF_ARM_EABI_VER2        0x02000000
#define EF_ARM_EABI_VER3        0x03000000
#define EF_ARM_EABI_VER4        0x04000000
#define EF_ARM_EABI_VER5        0x05000000

#define STT_ARM_TFUNC STT_LOPROC
#define STT_ARM_16BIT STT_HIPROC

#define SHF_ARM_ENTRYSECT 0x10000000
#define SHF_ARM_COMDEF    0x80000000

#define PF_ARM_SB  0x10000000
#define PF_ARM_PI  0x20000000
#define PF_ARM_ABS 0x40000000

#define PT_ARM_EXIDX (PT_LOPROC + 1)

#define SHT_ARM_EXIDX      (SHT_LOPROC + 1)
#define SHT_ARM_PREEMPTMAP (SHT_LOPROC + 2)
#define SHT_ARM_ATTRIBUTES (SHT_LOPROC + 3)

#define R_AARCH64_NONE                         0
#define R_AARCH64_P32_ABS32                    1
#define R_AARCH64_P32_COPY                     2
#define R_AARCH64_P32_GLOB_DAT                 3
#define R_AARCH64_P32_JUMP_SLOT                4
#define R_AARCH64_P32_RELATIVE                 5
#define R_AARCH64_P32_TLS_DTPMOD               6
#define R_AARCH64_P32_TLS_DTPREL               7
#define R_AARCH64_P32_TLS_TPREL                8
#define R_AARCH64_P32_TLSDESC                  9
#define R_AARCH64_P32_IRELATIVE                10
#define R_AARCH64_ABS64                        11
#define R_AARCH64_ABS32                        12
#define R_AARCH64_ABS16                        13
#define R_AARCH64_PREL64                       14
#define R_AARCH64_PREL32                       15
#define R_AARCH64_PREL16                       16
#define R_AARCH64_MOVW_UABS_G0                 17
#define R_AARCH64_MOVW_UABS_G0_NC              18
#define R_AARCH64_MOVW_UABS_G1                 19
#define R_AARCH64_MOVW_UABS_G1_NC              20
#define R_AARCH64_MOVW_UABS_G2                 21
#define R_AARCH64_MOVW_UABS_G2_NC              22
#define R_AARCH64_MOVW_UABS_G3                 23
#define R_AARCH64_MOVW_SABS_G0                 24
#define R_AARCH64_MOVW_SABS_G1                 25
#define R_AARCH64_MOVW_SABS_G2                 26
#define R_AARCH64_LD_PREL_LO19                 27
#define R_AARCH64_ADR_PREL_LO21                28
#define R_AARCH64_ADR_PREL_PG_HI21             29
#define R_AARCH64_ADR_PREL_PG_HI21_NC          30
#define R_AARCH64_ADD_ABS_LO12_NC              31
#define R_AARCH64_LDST8_ABS_LO12_NC            32
#define R_AARCH64_TSTBR14                      33
#define R_AARCH64_CONDBR19                     34
#define R_AARCH64_JUMP26                       35
#define R_AARCH64_CALL26                       36
#define R_AARCH64_LDST16_ABS_LO12_NC           37
#define R_AARCH64_LDST32_ABS_LO12_NC           38
#define R_AARCH64_LDST64_ABS_LO12_NC           39
#define R_AARCH64_MOVW_PREL_G0                 40
#define R_AARCH64_MOVW_PREL_G0_NC              41
#define R_AARCH64_MOVW_PREL_G1                 42
#define R_AARCH64_MOVW_PREL_G1_NC              43
#define R_AARCH64_MOVW_PREL_G2                 44
#define R_AARCH64_MOVW_PREL_G2_NC              45
#define R_AARCH64_MOVW_PREL_G3                 46
#define R_AARCH64_LDST128_ABS_LO12_NC          47
#define R_AARCH64_MOVW_GOTOFF_G0               48
#define R_AARCH64_MOVW_GOTOFF_G0_NC            49
#define R_AARCH64_MOVW_GOTOFF_G1               50
#define R_AARCH64_MOVW_GOTOFF_G1_NC            51
#define R_AARCH64_MOVW_GOTOFF_G2               52
#define R_AARCH64_MOVW_GOTOFF_G2_NC            53
#define R_AARCH64_MOVW_GOTOFF_G3               54
#define R_AARCH64_GOTREL64                     55
#define R_AARCH64_GOTREL32                     56
#define R_AARCH64_GOT_LD_PREL19                57
#define R_AARCH64_LD64_GOTOFF_LO15             58
#define R_AARCH64_ADR_GOT_PAGE                 59
#define R_AARCH64_LD64_GOT_LO12_NC             60
#define R_AARCH64_LD64_GOTPAGE_LO15            61
#define R_AARCH64_TLSGD_ADR_PREL21             62
#define R_AARCH64_TLSGD_ADR_PAGE21             63
#define R_AARCH64_TLSGD_ADD_LO12_NC            64
#define R_AARCH64_TLSGD_MOVW_G1                65
#define R_AARCH64_TLSGD_MOVW_G0_NC             66
#define R_AARCH64_TLSLD_ADR_PREL21             67
#define R_AARCH64_TLSLD_ADR_PAGE21             68
#define R_AARCH64_TLSLD_ADD_LO12_NC            69
#define R_AARCH64_TLSLD_MOVW_G1                70
#define R_AARCH64_TLSLD_MOVW_G0_NC             71
#define R_AARCH64_TLSLD_LD_PREL19              72
#define R_AARCH64_TLSLD_MOVW_DTPREL_G2         73
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1         74
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC      75
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0         76
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC      77
#define R_AARCH64_TLSLD_ADD_DTPREL_HI12        78
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12        79
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12_NC     80
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12      81
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC   82
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12     83
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC  84
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12     85
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC  86
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12     87
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC  88
#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G1       89
#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC    90
#define R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21    91
#define R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC  92
#define R_AARCH64_TLSIE_LD_GOTTPREL_PREL19     93
#define R_AARCH64_TLSLE_MOVW_TPREL_G2          94
#define R_AARCH64_TLSLE_MOVW_TPREL_G1          95
#define R_AARCH64_TLSLE_MOVW_TPREL_G1_NC       96
#define R_AARCH64_TLSLE_MOVW_TPREL_G0          97
#define R_AARCH64_TLSLE_MOVW_TPREL_G0_NC       98
#define R_AARCH64_TLSLE_ADD_TPREL_HI12         99
#define R_AARCH64_TLSLE_ADD_TPREL_LO12         100
#define R_AARCH64_TLSLE_ADD_TPREL_LO12_NC      101
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12       102
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC    103
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12      104
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC   105
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12      106
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC   107
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12      108
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC   109
#define R_AARCH64_TLSDESC_LD_PREL19            110
#define R_AARCH64_TLSDESC_ADR_PREL21           111
#define R_AARCH64_TLSDESC_ADR_PAGE21           112
#define R_AARCH64_TLSDESC_LD64_LO12            113
#define R_AARCH64_TLSDESC_ADD_LO12             114
#define R_AARCH64_TLSDESC_OFF_G1               115
#define R_AARCH64_TLSDESC_OFF_G0_NC            116
#define R_AARCH64_TLSDESC_LDR                  117
#define R_AARCH64_TLSDESC_ADD                  118
#define R_AARCH64_TLSDESC_CALL                 119
#define R_AARCH64_TLSLE_LDST128_TPREL_LO12     120
#define R_AARCH64_TLSLE_LDST128_TPREL_LO12_NC  121
#define R_AARCH64_TLSLD_LDST128_DTPREL_LO12    122
#define R_AARCH64_TLSLD_LDST128_DTPREL_LO12_NC 123
#define R_AARCH64_COPY                         124
#define R_AARCH64_GLOB_DAT                     125
#define R_AARCH64_JUMP_SLOT                    126
#define R_AARCH64_RELATIVE                     127
#define R_AARCH64_TLS_DTPMOD                   128
#define R_AARCH64_TLS_DTPREL                   129
#define R_AARCH64_TLS_TPREL                    130
#define R_AARCH64_TLSDESC                      131
#define R_AARCH64_IRELATIVE                    132

#define R_ARM_NONE              0
#define R_ARM_PC24              1
#define R_ARM_ABS32             2
#define R_ARM_REL32             3
#define R_ARM_PC13              4
#define R_ARM_ABS16             5
#define R_ARM_ABS12             6
#define R_ARM_THM_ABS5          7
#define R_ARM_ABS8              8
#define R_ARM_SBREL32           9
#define R_ARM_THM_PC22          10
#define R_ARM_THM_PC8           11
#define R_ARM_AMP_VCALL9        12
#define R_ARM_SWI24             13
#define R_ARM_TLS_DESC          14
#define R_ARM_THM_SWI8          15
#define R_ARM_XPC25             16
#define R_ARM_THM_XPC22         17
#define R_ARM_TLS_DTPMOD32      18
#define R_ARM_TLS_DTPOFF32      19
#define R_ARM_TLS_TPOFF32       20
#define R_ARM_COPY              21
#define R_ARM_GLOB_DAT          22
#define R_ARM_JUMP_SLOT         23
#define R_ARM_RELATIVE          24
#define R_ARM_GOTOFF            25
#define R_ARM_GOTPC             26
#define R_ARM_GOT32             27
#define R_ARM_PLT32             28
#define R_ARM_CALL              29
#define R_ARM_JUMP24            30
#define R_ARM_THM_JUMP24        31
#define R_ARM_BASE_ABS          32
#define R_ARM_ALU_PCREL_7_0     33
#define R_ARM_ALU_PCREL_15_8    34
#define R_ARM_ALU_PCREL_23_15   35
#define R_ARM_LDR_SBREL_11_0    36
#define R_ARM_ALU_SBREL_19_12   37
#define R_ARM_ALU_SBREL_27_20   38
#define R_ARM_TARGET1           39
#define R_ARM_SBREL31           40
#define R_ARM_V4BX              41
#define R_ARM_TARGET2           42
#define R_ARM_PREL31            43
#define R_ARM_MOVW_ABS_NC       44
#define R_ARM_MOVT_ABS          45
#define R_ARM_MOVW_PREL_NC      46
#define R_ARM_MOVT_PREL         47
#define R_ARM_THM_MOVW_ABS_NC   48
#define R_ARM_THM_MOVT_ABS  48  49
#define R_ARM_THM_MOVW_PREL_NC  50
#define R_ARM_THM_MOVT_PREL     51
#define R_ARM_THM_JUMP19        52
#define R_ARM_THM_JUMP6         53
#define R_ARM_THM_ALU_PREL_11_0 54
#define R_ARM_THM_PC12          55
#define R_ARM_ABS32_NOI         56
#define R_ARM_REL32_NOI         57
#define R_ARM_ALU_PC_G0_NC      58
#define R_ARM_ALU_PC_G0         59
#define R_ARM_ALU_PC_G1_NC      60
#define R_ARM_ALU_PC_G1         61
#define R_ARM_ALU_PC_G2         62
#define R_ARM_LDR_PC_G1         63
#define R_ARM_LDR_PC_G2         64
#define R_ARM_LDRS_PC_G0        65
#define R_ARM_LDRS_PC_G1        66
#define R_ARM_LDRS_PC_G2        67
#define R_ARM_LDC_PC_G0         68
#define R_ARM_LDC_PC_G1         69
#define R_ARM_LDC_PC_G2         70
#define R_ARM_ALU_SB_G0_NC      71
#define R_ARM_ALU_SB_G0         72
#define R_ARM_ALU_SB_G1_NC      73
#define R_ARM_ALU_SB_G1         74
#define R_ARM_ALU_SB_G2         75
#define R_ARM_LDR_SB_G0         76
#define R_ARM_LDR_SB_G1         77
#define R_ARM_LDR_SB_G2         78
#define R_ARM_LDRS_SB_G0        79
#define R_ARM_LDRS_SB_G1        80
#define R_ARM_LDRS_SB_G2        81
#define R_ARM_LDC_SB_G0         82
#define R_ARM_LDC_SB_G1         83
#define R_ARM_LDC_SB_G2         84
#define R_ARM_MOVW_BREL_NC      85
#define R_ARM_MOVT_BREL         86
#define R_ARM_MOVW_BREL         87
#define R_ARM_THM_MOVW_BREL_NC  88
#define R_ARM_THM_MOVT_BREL     89
#define R_ARM_THM_MOVW_BREL     90
#define R_ARM_TLS_GOTDESC       91
#define R_ARM_TLS_CALL          92
#define R_ARM_TLS_DESCSEQ       93
#define R_ARM_THM_TLS_CALL      94
#define R_ARM_PLT32_ABS         95
#define R_ARM_GOT_ABS           96
#define R_ARM_GOT_PREL          97
#define R_ARM_GOT_BREL12        98
#define R_ARM_GOTOFF12          99
#define R_ARM_GOTRELAX          100
#define R_ARM_GNU_VTENTRY       101
#define R_ARM_GNU_VTINHERIT     102
#define R_ARM_THM_PC11          103
#define R_ARM_THM_PC9           104
#define R_ARM_TLS_GD32          105
#define R_ARM_TLS_LDM32         106
#define R_ARM_TLS_LDO32         107
#define R_ARM_TLS_IE32          108
#define R_ARM_TLS_LE32          109
#define R_ARM_TLS_LDO12         110
#define R_ARM_TLS_LE12          111
#define R_ARM_TLS_IE12GP        112
#define R_ARM_ME_TOO            113
#define R_ARM_THM_TLS_DESCSEQ   114
#define R_ARM_THM_TLS_DESCSEQ16 115
#define R_ARM_THM_TLS_DESCSEQ32 116
#define R_ARM_THM_GOT_BREL12    117
#define R_ARM_IRELATIVE         118
#define R_ARM_RXPC25            119
#define R_ARM_RSBREL32          120
#define R_ARM_THM_RPC22         121
#define R_ARM_RREL32            122
#define R_ARM_RABS22            123
#define R_ARM_RPC24             124
#define R_ARM_RBASE             125
#define R_ARM_NUM               126

#define EF_IA_64_MASKOS 0x0000000f
#define EF_IA_64_ABI64  0x00000010
#define EF_IA_64_ARCH   0xff000000

#define PT_IA_64_ARCHEXT     (PT_LOPROC + 0)
#define PT_IA_64_UNWIND      (PT_LOPROC + 1)
#define PT_IA_64_HP_OPT_ANOT (PT_LOOS + 0x12)
#define PT_IA_64_HP_HSL_ANOT (PT_LOOS + 0x13)
#define PT_IA_64_HP_STACK    (PT_LOOS + 0x14)

#define PF_IA_64_NORECOV 0x80000000

#define SHT_IA_64_EXT    (SHT_LOPROC + 0)
#define SHT_IA_64_UNWIND (SHT_LOPROC + 1)

#define SHF_IA_64_SHORT   0x10000000
#define SHF_IA_64_NORECOV 0x20000000

#define DT_IA_64_PLT_RESERVE (DT_LOPROC + 0)
#define DT_IA_64_NUM         1

#define R_IA64_NONE            0
#define R_IA64_IMM14           1
#define R_IA64_IMM22           2
#define R_IA64_IMM64           3
#define R_IA64_DIR32MSB        4
#define R_IA64_DIR32LSB        5
#define R_IA64_DIR64MSB        6
#define R_IA64_DIR64LSB        7
#define R_IA64_GPREL22         8
#define R_IA64_GPREL64I        9
#define R_IA64_GPREL32MSB      10
#define R_IA64_GPREL32LSB      11
#define R_IA64_GPREL64MSB      12
#define R_IA64_GPREL64LSB      13
#define R_IA64_LTOFF22         14
#define R_IA64_LTOFF64I        15
#define R_IA64_PLTOFF22        16
#define R_IA64_PLTOFF64I       17
#define R_IA64_PLTOFF64MSB     18
#define R_IA64_PLTOFF64LSB     19
#define R_IA64_FPTR64I         20
#define R_IA64_FPTR32MSB       21
#define R_IA64_FPTR32LSB       22
#define R_IA64_FPTR64MSB       23
#define R_IA64_FPTR64LSB       24
#define R_IA64_PCREL60B        25
#define R_IA64_PCREL21B        26
#define R_IA64_PCREL21M        27
#define R_IA64_PCREL21F        28
#define R_IA64_PCREL32MSB      29
#define R_IA64_PCREL32LSB      30
#define R_IA64_PCREL64MSB      31
#define R_IA64_PCREL64LSB      32
#define R_IA64_LTOFF_FPTR22    33
#define R_IA64_LTOFF_FPTR64I   34
#define R_IA64_LTOFF_FPTR32MSB 35
#define R_IA64_LTOFF_FPTR32LSB 36
#define R_IA64_LTOFF_FPTR64MSB 37
#define R_IA64_LTOFF_FPTR64LSB 38
#define R_IA64_SEGREL32MSB     39
#define R_IA64_SEGREL32LSB     40
#define R_IA64_SEGREL64MSB     41
#define R_IA64_SEGREL64LSB     42
#define R_IA64_SECREL32MSB     43
#define R_IA64_SECREL32LSB     44
#define R_IA64_SECREL64MSB     45
#define R_IA64_SECREL64LSB     46
#define R_IA64_REL32MSB        47
#define R_IA64_REL32LSB        48
#define R_IA64_REL64MSB        49
#define R_IA64_REL64LSB        50
#define R_IA64_LTV32MSB        51
#define R_IA64_LTV32LSB        52
#define R_IA64_LTV64MSB        53
#define R_IA64_LTV64LSB        54
#define R_IA64_PCREL21BI       55
#define R_IA64_PCREL22         56
#define R_IA64_PCREL64I        57
#define R_IA64_IPLTMSB         58
#define R_IA64_IPLTLSB         59
#define R_IA64_COPY            60
#define R_IA64_SUB             61
#define R_IA64_LTOFF22X        62
#define R_IA64_LDXMOV          63
#define R_IA64_TPREL14         64
#define R_IA64_TPREL22         65
#define R_IA64_TPREL64I        66
#define R_IA64_TPREL64MSB      67
#define R_IA64_TPREL64LSB      68
#define R_IA64_LTOFF_TPREL22   69
#define R_IA64_DTPMOD64MSB     70
#define R_IA64_DTPMOD64LSB     71
#define R_IA64_LTOFF_DTPMOD22  72
#define R_IA64_DTPREL14        73
#define R_IA64_DTPREL22        74
#define R_IA64_DTPREL64I       75
#define R_IA64_DTPREL32MSB     76
#define R_IA64_DTPREL32LSB     77
#define R_IA64_DTPREL64MSB     78
#define R_IA64_DTPREL64LSB     79
#define R_IA64_LTOFF_DTPREL22  80

#define EF_SH_MACH_MASK    0x1f
#define EF_SH_UNKNOWN      0x0
#define EF_SH1             0x1
#define EF_SH2             0x2
#define EF_SH3             0x3
#define EF_SH_DSP          0x4
#define EF_SH3_DSP         0x5
#define EF_SH4AL_DSP       0x6
#define EF_SH3E            0x8
#define EF_SH4             0x9
#define EF_SH2E            0xb
#define EF_SH4A            0xc
#define EF_SH2A            0xd
#define EF_SH4_NOFPU       0x10
#define EF_SH4A_NOFPU      0x11
#define EF_SH4_NOMMU_NOFPU 0x12
#define EF_SH2A_NOFPU      0x13
#define EF_SH3_NOMMU       0x14
#define EF_SH2A_SH4_NOFPU  0x15
#define EF_SH2A_SH3_NOFPU  0x16
#define EF_SH2A_SH4        0x17
#define EF_SH2A_SH3E       0x18

#define R_SH_NONE          0
#define R_SH_DIR32         1
#define R_SH_REL32         2
#define R_SH_DIR8WPN       3
#define R_SH_IND12W        4
#define R_SH_DIR8WPL       5
#define R_SH_DIR8WPZ       6
#define R_SH_DIR8BP        7
#define R_SH_DIR8W         8
#define R_SH_DIR8L         9
#define R_SH_SWITCH16      10
#define R_SH_SWITCH32      11
#define R_SH_USES          12
#define R_SH_COUNT         13
#define R_SH_ALIGN         14
#define R_SH_CODE          15
#define R_SH_DATA          16
#define R_SH_LABEL         17
#define R_SH_SWITCH8       18
#define R_SH_GNU_VTINHERIT 19
#define R_SH_GNU_VTENTRY   20
#define R_SH_TLS_GD_32     21
#define R_SH_TLS_LD_32     22
#define R_SH_TLS_LDO_32    23
#define R_SH_TLS_IE_32     24
#define R_SH_TLS_LE_32     25
#define R_SH_TLS_DTPMOD32  26
#define R_SH_TLS_DTPOFF32  27
#define R_SH_TLS_TPOFF32   28
#define R_SH_GOT32         29
#define R_SH_PLT32         30
#define R_SH_COPY          31
#define R_SH_GLOB_DAT      32
#define R_SH_JMP_SLOT      33
#define R_SH_RELATIVE      34
#define R_SH_GOTOFF        35
#define R_SH_GOTPC         36
#define R_SH_NUM           37

#define EF_S390_HIGH_GPRS 0x00000001

#define R_390_NONE        0
#define R_390_8           1
#define R_390_12          2
#define R_390_16          3
#define R_390_32          4
#define R_390_PC32        5
#define R_390_GOT12       6
#define R_390_GOT32       7
#define R_390_PLT32       8
#define R_390_COPY        9
#define R_390_GLOB_DAT    10
#define R_390_JMP_SLOT    11
#define R_390_RELATIVE    12
#define R_390_GOTOFF32    13
#define R_390_GOTPC       14
#define R_390_GOT16       15
#define R_390_PC16        16
#define R_390_PC16DBL     17
#define R_390_PLT16DBL    18
#define R_390_PC32DBL     19
#define R_390_PLT32DBL    20
#define R_390_GOTPCDBL    21
#define R_390_64          22
#define R_390_PC64        23
#define R_390_GOT64       24
#define R_390_PLT64       25
#define R_390_GOTENT      26
#define R_390_GOTOFF16    27
#define R_390_GOTOFF64    28
#define R_390_GOTPLT12    29
#define R_390_GOTPLT16    30
#define R_390_GOTPLT32    31
#define R_390_GOTPLT64    32
#define R_390_GOTPLTENT   33
#define R_390_PLTOFF16    34
#define R_390_PLTOFF32    35
#define R_390_PLTOFF64    36
#define R_390_TLS_LOAD    37
#define R_390_TLS_GDCALL  38
#define R_390_TLS_LDCALL  39
#define R_390_TLS_GD32    40
#define R_390_TLS_GD64    41
#define R_390_TLS_GOTIE12 42
#define R_390_TLS_GOTIE32 43
#define R_390_TLS_GOTIE64 44
#define R_390_TLS_LDM32   45
#define R_390_TLS_LDM64   46
#define R_390_TLS_IE32    47
#define R_390_TLS_IE64    48
#define R_390_TLS_IEENT   49
#define R_390_TLS_LE32    50
#define R_390_TLS_LE64    51
#define R_390_TLS_LDO32   52
#define R_390_TLS_LDO64   53
#define R_390_TLS_DTPMOD  54
#define R_390_TLS_DTPOFF  55
#define R_390_TLS_TPOFF   56
#define R_390_20          57
#define R_390_GOT20       58
#define R_390_GOTPLT20    59
#define R_390_TLS_GOTIE20 60
#define R_390_IRELATIVE   61
#define R_390_NUM         62

#define R_CRIS_NONE          0
#define R_CRIS_8             1
#define R_CRIS_16            2
#define R_CRIS_32            3
#define R_CRIS_8_PCREL       4
#define R_CRIS_16_PCREL      5
#define R_CRIS_32_PCREL      6
#define R_CRIS_GNU_VTINHERIT 7
#define R_CRIS_GNU_VTENTRY   8
#define R_CRIS_COPY          9
#define R_CRIS_GLOB_DAT      10
#define R_CRIS_JUMP_SLOT     11
#define R_CRIS_RELATIVE      12
#define R_CRIS_16_GOT        13
#define R_CRIS_32_GOT        14
#define R_CRIS_16_GOTPLT     15
#define R_CRIS_32_GOTPLT     16
#define R_CRIS_32_GOTREL     17
#define R_CRIS_32_PLT_GOTREL 18
#define R_CRIS_32_PLT_PCREL  19
#define R_CRIS_NUM           20

#define R_X86_64_NONE            0
#define R_X86_64_64              1
#define R_X86_64_PC32            2
#define R_X86_64_GOT32           3
#define R_X86_64_PLT32           4
#define R_X86_64_COPY            5
#define R_X86_64_GLOB_DAT        6
#define R_X86_64_JUMP_SLOT       7
#define R_X86_64_RELATIVE        8
#define R_X86_64_GOTPCREL        9
#define R_X86_64_32              10
#define R_X86_64_32S             11
#define R_X86_64_16              12
#define R_X86_64_PC16            13
#define R_X86_64_8               14
#define R_X86_64_PC8             15
#define R_X86_64_DTPMOD64        16
#define R_X86_64_DTPOFF64        17
#define R_X86_64_TPOFF64         18
#define R_X86_64_TLSGD           19
#define R_X86_64_TLSLD           20
#define R_X86_64_DTPOFF32        21
#define R_X86_64_GOTTPOFF        22
#define R_X86_64_TPOFF32         23
#define R_X86_64_PC64            24
#define R_X86_64_GOTOFF64        25
#define R_X86_64_GOTPC32         26
#define R_X86_64_GOT64           27
#define R_X86_64_GOTPCREL64      28
#define R_X86_64_GOTPC64         29
#define R_X86_64_GOTPLT64        30
#define R_X86_64_PLTOFF64        31
#define R_X86_64_SIZE32          32
#define R_X86_64_SIZE64          33
#define R_X86_64_GOTPC32_TLSDESC 34
#define R_X86_64_TLSDESC_CALL    35
#define R_X86_64_TLSDESC         36
#define R_X86_64_IRELATIVE       37
#define R_X86_64_RELATIVE64      38
#define R_X86_64_NUM             39

#define R_MN10300_NONE          0
#define R_MN10300_32            1
#define R_MN10300_16            2
#define R_MN10300_8             3
#define R_MN10300_PCREL32       4
#define R_MN10300_PCREL16       5
#define R_MN10300_PCREL8        6
#define R_MN10300_GNU_VTINHERIT 7
#define R_MN10300_GNU_VTENTRY   8
#define R_MN10300_24            9
#define R_MN10300_GOTPC32       10
#define R_MN10300_GOTPC16       11
#define R_MN10300_GOTOFF32      12
#define R_MN10300_GOTOFF24      13
#define R_MN10300_GOTOFF16      14
#define R_MN10300_PLT32         15
#define R_MN10300_PLT16         16
#define R_MN10300_GOT32         17
#define R_MN10300_GOT24         18
#define R_MN10300_GOT16         19
#define R_MN10300_COPY          20
#define R_MN10300_GLOB_DAT      21
#define R_MN10300_JMP_SLOT      22
#define R_MN10300_RELATIVE      23
#define R_MN10300_TLS_GD        24
#define R_MN10300_TLS_LD        25
#define R_MN10300_TLS_LDO       26
#define R_MN10300_TLS_GOTIE     27
#define R_MN10300_TLS_IE        28
#define R_MN10300_TLS_LE        29
#define R_MN10300_TLS_DTPMOD    30
#define R_MN10300_TLS_DTPOFF    31
#define R_MN10300_TLS_TPOFF     32
#define R_MN10300_SYM_DIFF      33
#define R_MN10300_ALIGN         34
#define R_MN10300_NUM           35

#define R_M32R_NONE               0
#define R_M32R_16                 1
#define R_M32R_32                 2
#define R_M32R_24                 3
#define R_M32R_10_PCREL           4
#define R_M32R_18_PCREL           5
#define R_M32R_26_PCREL           6
#define R_M32R_HI16_ULO           7
#define R_M32R_HI16_SLO           8
#define R_M32R_LO16               9
#define R_M32R_SDA16              10
#define R_M32R_GNU_VTINHERIT      11
#define R_M32R_GNU_VTENTRY        12
#define R_M32R_16_RELA            13
#define R_M32R_32_RELA            14
#define R_M32R_24_RELA            15
#define R_M32R_10_PCREL_RELA      16
#define R_M32R_18_PCREL_RELA      17
#define R_M32R_26_PCREL_RELA      18
#define R_M32R_HI16_ULO_RELA      19
#define R_M32R_HI16_SLO_RELA      20
#define R_M32R_LO16_RELA          21
#define R_M32R_SDA16_RELA         22
#define R_M32R_RELA_GNU_VTINHERIT 23
#define R_M32R_RELA_GNU_VTENTRY   24
#define R_M32R_REL32              25
#define R_M32R_GOT24              26
#define R_M32R_26_PLTREL          27
#define R_M32R_COPY               28
#define R_M32R_GLOB_DAT           29
#define R_M32R_JMP_SLOT           30
#define R_M32R_RELATIVE           31
#define R_M32R_GOTOFF             32
#define R_M32R_GOTPC24            33
#define R_M32R_GOT16_HI_ULO       34
#define R_M32R_GOT16_HI_SLO       35
#define R_M32R_GOT16_LO           36
#define R_M32R_GOTPC_HI_ULO       37
#define R_M32R_GOTPC_HI_SLO       38
#define R_M32R_GOTPC_LO           39
#define R_M32R_GOTOFF_HI_ULO      40
#define R_M32R_GOTOFF_HI_SLO      41
#define R_M32R_GOTOFF_LO          42
#define R_M32R_NUM                43

#define R_MICROBLAZE_NONE          0
#define R_MICROBLAZE_32            1
#define R_MICROBLAZE_32_PCREL      2
#define R_MICROBLAZE_64_PCREL      3
#define R_MICROBLAZE_32_PCREL_LO   4
#define R_MICROBLAZE_64            5
#define R_MICROBLAZE_32_LO         6
#define R_MICROBLAZE_SRO32         7
#define R_MICROBLAZE_SRW32         8
#define R_MICROBLAZE_64_NONE       9
#define R_MICROBLAZE_32_SYM_OP_SYM 10
#define R_MICROBLAZE_GNU_VTINHERIT 11
#define R_MICROBLAZE_GNU_VTENTRY   12
#define R_MICROBLAZE_GOTPC_64      13
#define R_MICROBLAZE_GOT_64        14
#define R_MICROBLAZE_PLT_64        15
#define R_MICROBLAZE_REL           16
#define R_MICROBLAZE_JUMP_SLOT     17
#define R_MICROBLAZE_GLOB_DAT      18
#define R_MICROBLAZE_GOTOFF_64     19
#define R_MICROBLAZE_GOTOFF_32     20
#define R_MICROBLAZE_COPY          21
#define R_MICROBLAZE_TLS           22
#define R_MICROBLAZE_TLSGD         23
#define R_MICROBLAZE_TLSLD         24
#define R_MICROBLAZE_TLSDTPMOD32   25
#define R_MICROBLAZE_TLSDTPREL32   26
#define R_MICROBLAZE_TLSDTPREL64   27
#define R_MICROBLAZE_TLSGOTTPREL32 28
#define R_MICROBLAZE_TLSTPREL32    29

#define DT_NIOS2_GP 0x70000002

#define R_NIOS2_NONE          0
#define R_NIOS2_S16           1
#define R_NIOS2_U16           2
#define R_NIOS2_PCREL16       3
#define R_NIOS2_CALL26        4
#define R_NIOS2_IMM5          5
#define R_NIOS2_CACHE_OPX     6
#define R_NIOS2_IMM6          7
#define R_NIOS2_IMM8          8
#define R_NIOS2_HI16          9
#define R_NIOS2_LO16          10
#define R_NIOS2_HIADJ16       11
#define R_NIOS2_BFD_RELOC_32  12
#define R_NIOS2_BFD_RELOC_16  13
#define R_NIOS2_BFD_RELOC_8   14
#define R_NIOS2_GPREL         15
#define R_NIOS2_GNU_VTINHERIT 16
#define R_NIOS2_GNU_VTENTRY   17
#define R_NIOS2_UJMP          18
#define R_NIOS2_CJMP          19
#define R_NIOS2_CALLR         20
#define R_NIOS2_ALIGN         21
#define R_NIOS2_GOT16         22
#define R_NIOS2_CALL16        23
#define R_NIOS2_GOTOFF_LO     24
#define R_NIOS2_GOTOFF_HA     25
#define R_NIOS2_PCREL_LO      26
#define R_NIOS2_PCREL_HA      27
#define R_NIOS2_TLS_GD16      28
#define R_NIOS2_TLS_LDM16     29
#define R_NIOS2_TLS_LDO16     30
#define R_NIOS2_TLS_IE16      31
#define R_NIOS2_TLS_LE16      32
#define R_NIOS2_TLS_DTPMOD    33
#define R_NIOS2_TLS_DTPREL    34
#define R_NIOS2_TLS_TPREL     35
#define R_NIOS2_COPY          36
#define R_NIOS2_GLOB_DAT      37
#define R_NIOS2_JUMP_SLOT     38
#define R_NIOS2_RELATIVE      39
#define R_NIOS2_GOTOFF        40
#define R_NIOS2_CALL26_NOAT   41
#define R_NIOS2_GOT_LO        42
#define R_NIOS2_GOT_HA        43
#define R_NIOS2_CALL_LO       44
#define R_NIOS2_CALL_HA       45

#define R_TILEPRO_NONE               0
#define R_TILEPRO_32                 1
#define R_TILEPRO_16                 2
#define R_TILEPRO_8                  3
#define R_TILEPRO_32_PCREL           4
#define R_TILEPRO_16_PCREL           5
#define R_TILEPRO_8_PCREL            6
#define R_TILEPRO_LO16               7
#define R_TILEPRO_HI16               8
#define R_TILEPRO_HA16               9
#define R_TILEPRO_COPY               10
#define R_TILEPRO_GLOB_DAT           11
#define R_TILEPRO_JMP_SLOT           12
#define R_TILEPRO_RELATIVE           13
#define R_TILEPRO_BROFF_X1           14
#define R_TILEPRO_JOFFLONG_X1        15
#define R_TILEPRO_JOFFLONG_X1_PLT    16
#define R_TILEPRO_IMM8_X0            17
#define R_TILEPRO_IMM8_Y0            18
#define R_TILEPRO_IMM8_X1            19
#define R_TILEPRO_IMM8_Y1            20
#define R_TILEPRO_MT_IMM15_X1        21
#define R_TILEPRO_MF_IMM15_X1        22
#define R_TILEPRO_IMM16_X0           23
#define R_TILEPRO_IMM16_X1           24
#define R_TILEPRO_IMM16_X0_LO        25
#define R_TILEPRO_IMM16_X1_LO        26
#define R_TILEPRO_IMM16_X0_HI        27
#define R_TILEPRO_IMM16_X1_HI        28
#define R_TILEPRO_IMM16_X0_HA        29
#define R_TILEPRO_IMM16_X1_HA        30
#define R_TILEPRO_IMM16_X0_PCREL     31
#define R_TILEPRO_IMM16_X1_PCREL     32
#define R_TILEPRO_IMM16_X0_LO_PCREL  33
#define R_TILEPRO_IMM16_X1_LO_PCREL  34
#define R_TILEPRO_IMM16_X0_HI_PCREL  35
#define R_TILEPRO_IMM16_X1_HI_PCREL  36
#define R_TILEPRO_IMM16_X0_HA_PCREL  37
#define R_TILEPRO_IMM16_X1_HA_PCREL  38
#define R_TILEPRO_IMM16_X0_GOT       39
#define R_TILEPRO_IMM16_X1_GOT       40
#define R_TILEPRO_IMM16_X0_GOT_LO    41
#define R_TILEPRO_IMM16_X1_GOT_LO    42
#define R_TILEPRO_IMM16_X0_GOT_HI    43
#define R_TILEPRO_IMM16_X1_GOT_HI    44
#define R_TILEPRO_IMM16_X0_GOT_HA    45
#define R_TILEPRO_IMM16_X1_GOT_HA    46
#define R_TILEPRO_MMSTART_X0         47
#define R_TILEPRO_MMEND_X0           48
#define R_TILEPRO_MMSTART_X1         49
#define R_TILEPRO_MMEND_X1           50
#define R_TILEPRO_SHAMT_X0           51
#define R_TILEPRO_SHAMT_X1           52
#define R_TILEPRO_SHAMT_Y0           53
#define R_TILEPRO_SHAMT_Y1           54
#define R_TILEPRO_DEST_IMM8_X1       55
#define R_TILEPRO_TLS_GD_CALL        56
#define R_TILEPRO_IMM8_X0_TLS_GD_ADD 57
#define R_TILEPRO_IMM8_X1_TLS_GD_ADD 58
#define R_TILEPRO_IMM8_Y0_TLS_GD_ADD 59
#define R_TILEPRO_IMM8_Y1_TLS_GD_ADD 60
#define R_TILEPRO_TLS_IE_LOAD        61
#define R_TILEPRO_IMM16_X0_TLS_GD    62
#define R_TILEPRO_IMM16_X1_TLS_GD    63
#define R_TILEPRO_IMM16_X0_TLS_GD_LO 64
#define R_TILEPRO_IMM16_X1_TLS_GD_LO 65
#define R_TILEPRO_IMM16_X0_TLS_GD_HI 66
#define R_TILEPRO_IMM16_X1_TLS_GD_HI 67
#define R_TILEPRO_IMM16_X0_TLS_GD_HA 68
#define R_TILEPRO_IMM16_X1_TLS_GD_HA 69
#define R_TILEPRO_IMM16_X0_TLS_IE    70
#define R_TILEPRO_IMM16_X1_TLS_IE    71
#define R_TILEPRO_IMM16_X0_TLS_IE_LO 72
#define R_TILEPRO_IMM16_X1_TLS_IE_LO 73
#define R_TILEPRO_IMM16_X0_TLS_IE_HI 74
#define R_TILEPRO_IMM16_X1_TLS_IE_HI 75
#define R_TILEPRO_IMM16_X0_TLS_IE_HA 76
#define R_TILEPRO_IMM16_X1_TLS_IE_HA 77
#define R_TILEPRO_TLS_DTPMOD32       78
#define R_TILEPRO_TLS_DTPOFF32       79
#define R_TILEPRO_TLS_TPOFF32        80
#define R_TILEPRO_IMM16_X0_TLS_LE    81
#define R_TILEPRO_IMM16_X1_TLS_LE    82
#define R_TILEPRO_IMM16_X0_TLS_LE_LO 83
#define R_TILEPRO_IMM16_X1_TLS_LE_LO 84
#define R_TILEPRO_IMM16_X0_TLS_LE_HI 85
#define R_TILEPRO_IMM16_X1_TLS_LE_HI 86
#define R_TILEPRO_IMM16_X0_TLS_LE_HA 87
#define R_TILEPRO_IMM16_X1_TLS_LE_HA 88
#define R_TILEPRO_GNU_VTINHERIT      89
#define R_TILEPRO_GNU_VTENTRY        90
#define R_TILEPRO_NUM                91

#define R_TILEGX_NONE                        0
#define R_TILEGX_64                          1
#define R_TILEGX_32                          2
#define R_TILEGX_16                          3
#define R_TILEGX_8                           4
#define R_TILEGX_64_PCREL                    5
#define R_TILEGX_32_PCREL                    6
#define R_TILEGX_16_PCREL                    7
#define R_TILEGX_8_PCREL                     8
#define R_TILEGX_HW0                         9
#define R_TILEGX_HW1                         10
#define R_TILEGX_HW2                         11
#define R_TILEGX_HW3                         12
#define R_TILEGX_HW0_LAST                    13
#define R_TILEGX_HW1_LAST                    14
#define R_TILEGX_HW2_LAST                    15
#define R_TILEGX_COPY                        16
#define R_TILEGX_GLOB_DAT                    17
#define R_TILEGX_JMP_SLOT                    18
#define R_TILEGX_RELATIVE                    19
#define R_TILEGX_BROFF_X1                    20
#define R_TILEGX_JUMPOFF_X1                  21
#define R_TILEGX_JUMPOFF_X1_PLT              22
#define R_TILEGX_IMM8_X0                     23
#define R_TILEGX_IMM8_Y0                     24
#define R_TILEGX_IMM8_X1                     25
#define R_TILEGX_IMM8_Y1                     26
#define R_TILEGX_DEST_IMM8_X1                27
#define R_TILEGX_MT_IMM14_X1                 28
#define R_TILEGX_MF_IMM14_X1                 29
#define R_TILEGX_MMSTART_X0                  30
#define R_TILEGX_MMEND_X0                    31
#define R_TILEGX_SHAMT_X0                    32
#define R_TILEGX_SHAMT_X1                    33
#define R_TILEGX_SHAMT_Y0                    34
#define R_TILEGX_SHAMT_Y1                    35
#define R_TILEGX_IMM16_X0_HW0                36
#define R_TILEGX_IMM16_X1_HW0                37
#define R_TILEGX_IMM16_X0_HW1                38
#define R_TILEGX_IMM16_X1_HW1                39
#define R_TILEGX_IMM16_X0_HW2                40
#define R_TILEGX_IMM16_X1_HW2                41
#define R_TILEGX_IMM16_X0_HW3                42
#define R_TILEGX_IMM16_X1_HW3                43
#define R_TILEGX_IMM16_X0_HW0_LAST           44
#define R_TILEGX_IMM16_X1_HW0_LAST           45
#define R_TILEGX_IMM16_X0_HW1_LAST           46
#define R_TILEGX_IMM16_X1_HW1_LAST           47
#define R_TILEGX_IMM16_X0_HW2_LAST           48
#define R_TILEGX_IMM16_X1_HW2_LAST           49
#define R_TILEGX_IMM16_X0_HW0_PCREL          50
#define R_TILEGX_IMM16_X1_HW0_PCREL          51
#define R_TILEGX_IMM16_X0_HW1_PCREL          52
#define R_TILEGX_IMM16_X1_HW1_PCREL          53
#define R_TILEGX_IMM16_X0_HW2_PCREL          54
#define R_TILEGX_IMM16_X1_HW2_PCREL          55
#define R_TILEGX_IMM16_X0_HW3_PCREL          56
#define R_TILEGX_IMM16_X1_HW3_PCREL          57
#define R_TILEGX_IMM16_X0_HW0_LAST_PCREL     58
#define R_TILEGX_IMM16_X1_HW0_LAST_PCREL     59
#define R_TILEGX_IMM16_X0_HW1_LAST_PCREL     60
#define R_TILEGX_IMM16_X1_HW1_LAST_PCREL     61
#define R_TILEGX_IMM16_X0_HW2_LAST_PCREL     62
#define R_TILEGX_IMM16_X1_HW2_LAST_PCREL     63
#define R_TILEGX_IMM16_X0_HW0_GOT            64
#define R_TILEGX_IMM16_X1_HW0_GOT            65
#define R_TILEGX_IMM16_X0_HW0_PLT_PCREL      66
#define R_TILEGX_IMM16_X1_HW0_PLT_PCREL      67
#define R_TILEGX_IMM16_X0_HW1_PLT_PCREL      68
#define R_TILEGX_IMM16_X1_HW1_PLT_PCREL      69
#define R_TILEGX_IMM16_X0_HW2_PLT_PCREL      70
#define R_TILEGX_IMM16_X1_HW2_PLT_PCREL      71
#define R_TILEGX_IMM16_X0_HW0_LAST_GOT       72
#define R_TILEGX_IMM16_X1_HW0_LAST_GOT       73
#define R_TILEGX_IMM16_X0_HW1_LAST_GOT       74
#define R_TILEGX_IMM16_X1_HW1_LAST_GOT       75
#define R_TILEGX_IMM16_X0_HW3_PLT_PCREL      76
#define R_TILEGX_IMM16_X1_HW3_PLT_PCREL      77
#define R_TILEGX_IMM16_X0_HW0_TLS_GD         78
#define R_TILEGX_IMM16_X1_HW0_TLS_GD         79
#define R_TILEGX_IMM16_X0_HW0_TLS_LE         80
#define R_TILEGX_IMM16_X1_HW0_TLS_LE         81
#define R_TILEGX_IMM16_X0_HW0_LAST_TLS_LE    82
#define R_TILEGX_IMM16_X1_HW0_LAST_TLS_LE    83
#define R_TILEGX_IMM16_X0_HW1_LAST_TLS_LE    84
#define R_TILEGX_IMM16_X1_HW1_LAST_TLS_LE    85
#define R_TILEGX_IMM16_X0_HW0_LAST_TLS_GD    86
#define R_TILEGX_IMM16_X1_HW0_LAST_TLS_GD    87
#define R_TILEGX_IMM16_X0_HW1_LAST_TLS_GD    88
#define R_TILEGX_IMM16_X1_HW1_LAST_TLS_GD    89
#define R_TILEGX_IMM16_X0_HW0_TLS_IE         92
#define R_TILEGX_IMM16_X1_HW0_TLS_IE         93
#define R_TILEGX_IMM16_X0_HW0_LAST_PLT_PCREL 94
#define R_TILEGX_IMM16_X1_HW0_LAST_PLT_PCREL 95
#define R_TILEGX_IMM16_X0_HW1_LAST_PLT_PCREL 96
#define R_TILEGX_IMM16_X1_HW1_LAST_PLT_PCREL 97
#define R_TILEGX_IMM16_X0_HW2_LAST_PLT_PCREL 98
#define R_TILEGX_IMM16_X1_HW2_LAST_PLT_PCREL 99
#define R_TILEGX_IMM16_X0_HW0_LAST_TLS_IE    100
#define R_TILEGX_IMM16_X1_HW0_LAST_TLS_IE    101
#define R_TILEGX_IMM16_X0_HW1_LAST_TLS_IE    102
#define R_TILEGX_IMM16_X1_HW1_LAST_TLS_IE    103
#define R_TILEGX_TLS_DTPMOD64                106
#define R_TILEGX_TLS_DTPOFF64                107
#define R_TILEGX_TLS_TPOFF64                 108
#define R_TILEGX_TLS_DTPMOD32                109
#define R_TILEGX_TLS_DTPOFF32                110
#define R_TILEGX_TLS_TPOFF32                 111
#define R_TILEGX_TLS_GD_CALL                 112
#define R_TILEGX_IMM8_X0_TLS_GD_ADD          113
#define R_TILEGX_IMM8_X1_TLS_GD_ADD          114
#define R_TILEGX_IMM8_Y0_TLS_GD_ADD          115
#define R_TILEGX_IMM8_Y1_TLS_GD_ADD          116
#define R_TILEGX_TLS_IE_LOAD                 117
#define R_TILEGX_IMM8_X0_TLS_ADD             118
#define R_TILEGX_IMM8_X1_TLS_ADD             119
#define R_TILEGX_IMM8_Y0_TLS_ADD             120
#define R_TILEGX_IMM8_Y1_TLS_ADD             121
#define R_TILEGX_GNU_VTINHERIT               128
#define R_TILEGX_GNU_VTENTRY                 129
#define R_TILEGX_NUM                         130

#define ELF32_ST_TYPE(info)       ((info) & ((unsigned char)0b00001111))
#define ELF64_ST_TYPE(info)       ((info) & ((unsigned char)0b00001111))
#define ELF32_ST_BIND(info)       ((info) >> 4)
#define ELF64_ST_BIND(info)       ((info) >> 4)
#define ELF32_ST_INFO(bind, type) ((type) | ((bind) << 4))
#define ELF64_ST_INFO(bind, type) ((type) | ((bind) << 4))

#define ELF32_ST_VISIBILITY(other) (other)
#define ELF64_ST_VISIBILITY(other) (other)

#define ELF32_R_SYM(val)        ((val) >> 8)
#define ELF32_R_TYPE(val)       ((val) & 0xff)
#define ELF32_R_INFO(sym, type) (((sym) << 8) + ((type) & 0xff))
#define ELF64_R_SYM(i)          ((i) >> 32)
#define ELF64_R_TYPE(i)         ((i) & 0xffffffff)
#define ELF64_R_INFO(sym,type)  ((((Elf64_Xword) (sym)) << 32) + (type))

#define ELF32_M_SYM(info)       ((info) >> 8)
#define ELF32_M_SIZE(info)      ((unsigned char) (info))
#define ELF32_M_INFO(sym, size) (((sym) << 8) + (unsigned char) (size))

#define ELF64_M_SYM(info)       ELF32_M_SYM (info)
#define ELF64_M_SIZE(info)      ELF32_M_SIZE (info)
#define ELF64_M_INFO(sym, size) ELF32_M_INFO (sym, size)

#define PPC64_LOCAL_ENTRY_OFFSET(other) (((1 << (((other) & STO_PPC64_LOCAL_MASK) >> STO_PPC64_LOCAL_BIT)) >> 2) << 2)
#define EF_ARM_EABI_VERSION(flags)  ((flags) & EF_ARM_EABIMASK)

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    Elf32_Addr e_entry;
    Elf32_Off e_phoff;
    Elf32_Off e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf32_Ehdr;

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    Elf64_Addr e_entry;
    Elf64_Off e_phoff;
    Elf64_Off e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

typedef struct {
    uint32_t p_type;
    Elf32_Off p_offset;
    Elf32_Addr p_vaddr;
    Elf32_Addr p_paddr;
    uint32_t p_filesz;
    uint32_t p_memsz;
    uint32_t p_flags;
    uint32_t p_align;
} Elf32_Phdr;

typedef struct {
    uint32_t p_type;
    uint32_t p_flags;
    Elf64_Off p_offset;
    Elf64_Addr p_vaddr;
    Elf64_Addr p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
} Elf64_Phdr;

typedef struct {
    uint32_t sh_name;
    uint32_t sh_type;
    uint32_t sh_flags;
    Elf32_Addr sh_addr;
    Elf32_Off sh_offset;
    uint32_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint32_t sh_addralign;
    uint32_t sh_entsize;
} Elf32_Shdr;

typedef struct {
    uint32_t sh_name;
    uint32_t sh_type;
    uint64_t sh_flags;
    Elf64_Addr sh_addr;
    Elf64_Off sh_offset;
    uint64_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint64_t sh_addralign;
    uint64_t sh_entsize;
} Elf64_Shdr;

typedef struct {
    uint32_t st_name;
    Elf32_Addr st_value;
    uint32_t st_size;
    unsigned char st_info;
    unsigned char st_other;
    uint16_t st_shndx;
} Elf32_Sym;

typedef struct {
    uint32_t st_name;
    unsigned char st_info;
    unsigned char st_other;
    uint16_t st_shndx;
    Elf64_Addr st_value;
    uint64_t st_size;
} Elf64_Sym;

typedef struct {
    Elf32_Half si_boundto;
    Elf32_Half si_flags;
} Elf32_Syminfo;

typedef struct {
    Elf64_Half si_boundto;
    Elf64_Half si_flags;
} Elf64_Syminfo;

typedef struct {
    Elf32_Addr r_offset;
    uint32_t r_info;
} Elf32_Rel;

typedef struct {
    Elf64_Addr r_offset;
    uint64_t r_info;
} Elf64_Rel;

typedef struct {
    Elf32_Addr r_offset;
    uint32_t r_info;
    int32_t r_addend;
} Elf32_Rela;

typedef struct {
    Elf64_Addr r_offset;
    uint64_t r_info;
    int64_t r_addend;
} Elf64_Rela;

typedef struct {
    Elf32_Sword d_tag;
    union {
        Elf32_Word d_val;
        Elf32_Addr d_ptr;
    } d_un;
} Elf32_Dyn;

typedef struct {
    Elf64_Sxword d_tag;
    union {
        Elf64_Xword d_val;
        Elf64_Addr d_ptr;
    } d_un;
} Elf64_Dyn;

typedef struct {
    Elf32_Word ch_type;
    Elf32_Word ch_size;
    Elf32_Word ch_addralign;
} Elf32_Chdr;

typedef struct {
    Elf64_Word ch_type;
    Elf64_Word ch_reserved;
    Elf64_Xword ch_size;
    Elf64_Xword ch_addralign;
} Elf64_Chdr;

typedef struct {
    Elf32_Half vd_version;
    Elf32_Half vd_flags;
    Elf32_Half vd_ndx;
    Elf32_Half vd_cnt;
    Elf32_Word vd_hash;
    Elf32_Word vd_aux;
    Elf32_Word vd_next;
} Elf32_Verdef;

typedef struct {
    Elf64_Half vd_version;
    Elf64_Half vd_flags;
    Elf64_Half vd_ndx;
    Elf64_Half vd_cnt;
    Elf64_Word vd_hash;
    Elf64_Word vd_aux;
    Elf64_Word vd_next;
} Elf64_Verdef;

typedef struct {
    Elf32_Word vda_name;
    Elf32_Word vda_next;
} Elf32_Verdaux;

typedef struct {
    Elf64_Word vda_name;
    Elf64_Word vda_next;
} Elf64_Verdaux;

typedef struct {
    Elf32_Half vn_version;
    Elf32_Half vn_cnt;
    Elf32_Word vn_file;
    Elf32_Word vn_aux;
    Elf32_Word vn_next;
} Elf32_Verneed;

typedef struct {
    Elf64_Half vn_version;
    Elf64_Half vn_cnt;
    Elf64_Word vn_file;
    Elf64_Word vn_aux;
    Elf64_Word vn_next;
} Elf64_Verneed;

typedef struct {
    Elf32_Word vna_hash;
    Elf32_Half vna_flags;
    Elf32_Half vna_other;
    Elf32_Word vna_name;
    Elf32_Word vna_next;
} Elf32_Vernaux;

typedef struct {
    Elf64_Word vna_hash;
    Elf64_Half vna_flags;
    Elf64_Half vna_other;
    Elf64_Word vna_name;
    Elf64_Word vna_next;
} Elf64_Vernaux;

typedef struct {
    uint32_t a_type;
    union {
        uint32_t a_val;
    } a_un;
} Elf32_auxv_t;

typedef struct {
    uint64_t a_type;
    union {
        uint64_t a_val;
    } a_un;
} Elf64_auxv_t;

typedef struct {
    Elf32_Word n_namesz;
    Elf32_Word n_descsz;
    Elf32_Word n_type;
} Elf32_Nhdr;

typedef struct {
    Elf64_Word n_namesz;
    Elf64_Word n_descsz;
    Elf64_Word n_type;
} Elf64_Nhdr;

typedef struct {
    Elf32_Xword m_value;
    Elf32_Word m_info;
    Elf32_Word m_poffset;
    Elf32_Half m_repeat;
    Elf32_Half m_stride;
} Elf32_Move;

typedef struct {
    Elf64_Xword m_value;
    Elf64_Xword m_info;
    Elf64_Xword m_poffset;
    Elf64_Half m_repeat;
    Elf64_Half m_stride;
} Elf64_Move;

typedef union {
    struct {
        Elf32_Word gt_current_g_value;
        Elf32_Word gt_unused;
    } gt_header;
    struct {
        Elf32_Word gt_g_value;
        Elf32_Word gt_bytes;
    } gt_entry;
} Elf32_gptab;

typedef struct {
    Elf32_Word ri_gprmask;
    Elf32_Word ri_cprmask[4];
    Elf32_Sword ri_gp_value;
} Elf32_RegInfo;

typedef struct {
    unsigned char kind;
    unsigned char size;
    Elf32_Section section;
    Elf32_Word info;
} Elf_Options;

typedef struct {
    Elf32_Word hwp_flags1;
    Elf32_Word hwp_flags2;
} Elf_Options_Hw;

typedef struct {
    Elf32_Word l_name;
    Elf32_Word l_time_stamp;
    Elf32_Word l_checksum;
    Elf32_Word l_version;
    Elf32_Word l_flags;
} Elf32_Lib;

typedef struct {
    Elf64_Word l_name;
    Elf64_Word l_time_stamp;
    Elf64_Word l_checksum;
    Elf64_Word l_version;
    Elf64_Word l_flags;
} Elf64_Lib;

typedef Elf32_Addr Elf32_Conflict;

typedef struct {
    Elf32_Half version;
    unsigned char isa_level;
    unsigned char isa_rev;
    unsigned char gpr_size;
    unsigned char cpr1_size;
    unsigned char cpr2_size;
    unsigned char fp_abi;
    Elf32_Word isa_ext;
    Elf32_Word ases;
    Elf32_Word flags1;
    Elf32_Word flags2;
} Elf_MIPS_ABIFlags_v0;

extern Elf64_Dyn _DYNAMIC[];

#endif /* LIBC_ELF_H_ */
