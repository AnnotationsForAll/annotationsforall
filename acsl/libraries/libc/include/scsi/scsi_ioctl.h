/*
 * scsi_ioctl.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SCSI_SCSI_IOCTL_H_
#define LIBC_SCSI_SCSI_IOCTL_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#define SCSI_IOCTL_SEND_COMMAND      1
#define SCSI_IOCTL_TEST_UNIT_READY   2
#define SCSI_IOCTL_BENCHMARK_COMMAND 3
#define SCSI_IOCTL_SYNC              4
#define SCSI_IOCTL_START_UNIT        5
#define SCSI_IOCTL_STOP_UNIT         6
#define SCSI_IOCTL_DOORLOCK          0x5380
#define SCSI_IOCTL_DOORUNLOCK        0x5381

#endif /* LIBC_SCSI_SCSI_IOCTL_H_ */
