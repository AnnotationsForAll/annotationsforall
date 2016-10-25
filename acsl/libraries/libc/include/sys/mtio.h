/*
 * mtio.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_MTIO_H_
#define LIBC_SYS_MTIO_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_caddr_t.h"
#include "ioctl.h"

#define MTRESET        0
#define MTFSF          1
#define MTBSF          2
#define MTFSR          3
#define MTBSR          4
#define MTWEOF         5
#define MTREW          6
#define MTOFFL         7
#define MTNOP          8
#define MTRETEN        9
#define MTBSFM         10
#define MTFSFM         11
#define MTEOM          12
#define MTERASE        13
#define MTRAS1         14
#define MTRAS2         15
#define MTRAS3         16
#define MTSETBLK       20
#define MTSETDENSITY   21
#define MTSEEK         22
#define MTTELL         23
#define MTSETDRVBUFFER 24
#define MTFSS          25
#define MTBSS          26
#define MTWSM          27
#define MTLOCK         28
#define MTUNLOCK       29
#define MTLOAD         30
#define MTUNLOAD       31
#define MTCOMPRESSION  32
#define MTSETPART      33
#define MTMKPART       34

#define MT_ISUNKNOWN            0
#define MT_ISQIC02              1
#define MT_ISWT5150             2
#define MT_ISARCHIVE_5945L2     3
#define MT_ISCMSJ500            4
#define MT_ISTDC3610            5
#define MT_ISARCHIVE_VP60I      6
#define MT_ISARCHIVE_2150L      7
#define MT_ISARCHIVE_2060L      8
#define MT_ISARCHIVESC499       9
#define MT_ISQIC02_ALL_FEATURES 10
#define MT_ISWT5099EEN24        11
#define MT_ISTEAC_MT2ST         12
#define MT_ISEVEREX_FT40A       13
#define MT_ISDDS1               14
#define MT_ISDDS2               15
#define MT_ISSCSI1              16
#define MT_ISSCSI2              17

#define MT_ISFTAPE_UNKNOWN 0x800000
#define MT_ISFTAPE_FLAG    0x800000

#define MTIOCTOP _IOW('m', 1, struct mtop)
#define MTIOCGET _IOR('m', 2, struct mtget)
#define MTIOCPOS _IOR('m', 3, struct mtpos)

#define MTIOCGETCONFIG _IOR('m', 4, struct mtconfiginfo)
#define MTIOCSETCONFIG _IOW('m', 5, struct mtconfiginfo)

#define GMT_EOF(x)       ((x) & 0x80000000)
#define GMT_BOT(x)       ((x) & 0x40000000)
#define GMT_EOT(x)       ((x) & 0x20000000)
#define GMT_SM(x)        ((x) & 0x10000000)
#define GMT_EOD(x)       ((x) & 0x08000000)
#define GMT_WR_PROT(x)   ((x) & 0x04000000)
#define GMT_ONLINE(x)    ((x) & 0x01000000)
#define GMT_D_6250(x)    ((x) & 0x00800000)
#define GMT_D_1600(x)    ((x) & 0x00400000)
#define GMT_D_800(x)     ((x) & 0x00200000)
#define GMT_DR_OPEN(x)   ((x) & 0x00040000)
#define GMT_IM_REP_EN(x) ((x) & 0x00010000)

#define MT_ST_BLKSIZE_SHIFT 0
#define MT_ST_BLKSIZE_MASK  0xffffff
#define MT_ST_DENSITY_SHIFT 24
#define MT_ST_DENSITY_MASK  0xff000000

#define MT_ST_SOFTERR_SHIFT 0
#define MT_ST_SOFTERR_MASK  0xffff

#define MT_ST_OPTIONS         0xf0000000
#define MT_ST_BOOLEANS        0x10000000
#define MT_ST_SETBOOLEANS     0x30000000
#define MT_ST_CLEARBOOLEANS   0x40000000
#define MT_ST_WRITE_THRESHOLD 0x20000000
#define MT_ST_DEF_BLKSIZE     0x50000000
#define MT_ST_DEF_OPTIONS     0x60000000

#define MT_ST_BUFFER_WRITES  (1 << 0)
#define MT_ST_ASYNC_WRITES   (1 << 1)
#define MT_ST_READ_AHEAD     (1 << 2)
#define MT_ST_DEBUGGING      (1 << 3)
#define MT_ST_TWO_FM         (1 << 4)
#define MT_ST_FAST_MTEOM     (1 << 5)
#define MT_ST_AUTO_LOCK      (1 << 6)
#define MT_ST_DEF_WRITES     (1 << 7)
#define MT_ST_CAN_BSR        (1 << 8)
#define MT_ST_NO_BLKLIMS     (1 << 9)
#define MT_ST_CAN_PARTITIONS (1 << 10)
#define MT_ST_SCSI2LOGICAL   (1 << 11)

#define MT_ST_CLEAR_DEFAULT   0xfffff
#define MT_ST_DEF_DENSITY     (MT_ST_DEF_OPTIONS | 0x100000)
#define MT_ST_DEF_COMPRESSION (MT_ST_DEF_OPTIONS | 0x200000)
#define MT_ST_DEF_DRVBUFFER   (MT_ST_DEF_OPTIONS | 0x300000)

#define MT_ST_HPLOADER_OFFSET 10000

#ifndef DEFTAPE
# define DEFTAPE "/dev/tape"
#endif

#define MT_TAPE_INFO \
  {                                       \
    {MT_ISUNKNOWN,      "Unknown type of tape device"},           \
    {MT_ISQIC02,        "Generic QIC-02 tape streamer"},          \
    {MT_ISWT5150,       "Wangtek 5150, QIC-150"},             \
    {MT_ISARCHIVE_5945L2,   "Archive 5945L-2"},               \
    {MT_ISCMSJ500,      "CMS Jumbo 500"},                 \
    {MT_ISTDC3610,      "Tandberg TDC 3610, QIC-24"},             \
    {MT_ISARCHIVE_VP60I,    "Archive VP60i, QIC-02"},             \
    {MT_ISARCHIVE_2150L,    "Archive Viper 2150L"},               \
    {MT_ISARCHIVE_2060L,    "Archive Viper 2060L"},               \
    {MT_ISARCHIVESC499, "Archive SC-499 QIC-36 controller"},          \
    {MT_ISQIC02_ALL_FEATURES, "Generic QIC-02 tape, all features"},       \
    {MT_ISWT5099EEN24,  "Wangtek 5099-een24, 60MB"},              \
    {MT_ISTEAC_MT2ST,   "Teac MT-2ST 155mb data cassette drive"},     \
    {MT_ISEVEREX_FT40A, "Everex FT40A, QIC-40"},              \
    {MT_ISSCSI1,        "Generic SCSI-1 tape"},               \
    {MT_ISSCSI2,        "Generic SCSI-2 tape"},               \
    {0, NULL}                                 \
  }

struct mtop {
    short int mt_op;
    int mt_count;
};

struct mtget {
    long int mt_type;
    long int mt_resid;
    long int mt_dsreg;
    long int mt_gstat;
    long int mt_erreg;
    daddr_t mt_fileno;
    daddr_t mt_blkno;
};

struct mt_tape_info {
    long int t_type;
    char *t_name;
};

struct mtpos {
    long int mt_blkno;
};

struct mtconfiginfo {
    long int mt_type;
    long int ifc_type;
    unsigned short int irqnr;
    unsigned short int dmanr;
    unsigned short int port;
    unsigned long int debug;
    unsigned have_dens :1;
    unsigned have_bsf :1;
    unsigned have_fsr :1;
    unsigned have_bsr :1;
    unsigned have_eod :1;
    unsigned have_seek :1;
    unsigned have_tell :1;
    unsigned have_ras1 :1;
    unsigned have_ras2 :1;
    unsigned have_ras3 :1;
    unsigned have_qfa :1;
    unsigned pad1 :5;
    char reserved[10];
};

#endif /* LIBC_SYS_MTIO_H_ */
