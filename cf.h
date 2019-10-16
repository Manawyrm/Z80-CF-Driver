#pragma once
#include "stdint.h"
#include "bit.h"

#define CF_BASE_REG 16
#define CF_DATA     CF_BASE_REG + 0 // IDE Data Port
#define CF_ERROR    CF_BASE_REG + 1 // Error code (read)
#define CF_NUMSECT  CF_BASE_REG + 2 // Numbers of sectors to transfer
#define CF_ADDR0    CF_BASE_REG + 3 // Sector address LBA 0 (0:7)
#define CF_ADDR1    CF_BASE_REG + 4 // Sector address LBA 1 (8:15)
#define CF_ADDR2    CF_BASE_REG + 5 // Sector address LBA 2 (16:23)
#define CF_ADDR3    CF_BASE_REG + 6 // Sector address LBA 3 (24:27)
#define CF_STATUS   CF_BASE_REG + 7 // Status (read)
#define CF_COMMAND  CF_BASE_REG + 7 // Command (write)

#define ERR_AMNF	1   // DAM not found
#define ERR_TKNONF	2   // Track 000 not found
#define ERR_ABRT	4   // Command aborted
#define ERR_MCR		8   // Media change requested
#define ERR_IDNF	16  // ID not found
#define	ERR_MC		32  // Media changed
#define ERR_UNC		64  // Uncorrectable ECC error
#define ERR_BADB    128 // Bad block detected

#define READ_ERR	1   // Previous command ended in an error
#define READ_IDX	2   // 
#define READ_CORR	4   // 
#define READ_DRQ	8   // Data Request Ready
#define READ_DSC	16  // 
#define	READ_DF 	32  // Write Fault
#define READ_RDY    64  // Ready for command
#define READ_BUSY	128 // Controller is busy executing a command.

#define IDE_CMD_CALIB		0x10 
#define IDE_CMD_READ		0x20 // Read sectors with retry
#define IDE_CMD_READ_NR		0x21
#define IDE_CMD_WRITE		0x30 // Write sectors with retry
#define IDE_CMD_WRITE_NR	0x31
#define IDE_CMD_VERIFY		0x40
#define IDE_CMD_VERIFY_NR	0x41
#define IDE_CMD_SEEK		0x70
#define IDE_CMD_EDD		    0x90
#define IDE_CMD_INTPARAMS	0x91
#define IDE_CMD_IDENTIFY	0xEC // Identify drive
#define IDE_CMD_SETFEATURES	0xEF

void delayCycles(uint32_t sleep);
