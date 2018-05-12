/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2006 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__XCP_CFG_H__)
#define __XCP_CFG_H__

/*  */ 
//#include "v_inc.h"
/*  */ 

//#define MEMORY_CONST  1024
//#define MEMORY_ROM  1024
#define XCP_CPUTYPE_LITTLEENDIAN    ///////////////////////////////////////////WARNING///////////////////////

/* General settings */ 
#define XCP_ENABLE_PARAMETER_CHECK
#define XCP_ENABLE_SEND_EVENT
#define XCP_DISABLE_TESTMODE
#define XCP_DISABLE_BOOTLOADER_DOWNLOAD
#define XCP_DISABLE_WRITE_PROTECTION
#define XCP_DISABLE_READ_PROTECTION
#define XCP_ENABLE_CONTROL
#define XCP_DISABLE_GET_XCP_DATA_POINTER
#define XCP_DISABLE_OPENCMDIF
#define XCP_ENABLE_MEM_MAPPING
#define XCP_DISABLE_VERSION_INFO_API
/*  */ 
/* EEPROM access */ 
#define XCP_DISABLE_READ_EEPROM
#define XCP_DISABLE_WRITE_EEPROM
/*  */ 
/* Service request message */ 
#define XCP_DISABLE_SERV_TEXT
#define XCP_DISABLE_SERV_TEXT_PUTCHAR
#define XCP_DISABLE_SERV_TEXT_PRINTF
/*  */ 
/* Standard commands */ 
#define XCP_ENABLE_COMM_MODE_INFO
#define XCP_DISABLE_SEED_KEY
#define XCP_ENABLE_MODIFY_BITS
#define XCP_ENABLE_SHORT_DOWNLOAD
#define XCP_ENABLE_USER_COMMAND
#define XCP_DISABLE_VECTOR_MAPNAMES
#define XCP_ENABLE_TL_COMMAND
/*  */ 
/* Block transfer */ 
#define XCP_ENABLE_BLOCK_UPLOAD
#define XCP_ENABLE_BLOCK_DOWNLOAD
/*  */ 
/* Checksum */ 
#define XCP_DISABLE_CHECKSUM
#define XCP_DISABLE_AUTOSAR_CRC_MODULE
#define kXcpChecksumMethod                   XCP_CHECKSUM_TYPE_ADD12
#define kXcpChecksumBlockSize                1024
/*  */ 
/* Synchronous Data Acquisition (DAQ) */ 
#define XCP_ENABLE_DAQ
#define kXcpDaqMemSize                       2048
#define XCP_DISABLE_STIM
#define XCP_DISABLE_UNALIGNED_MEM_ACCESS
#define XCP_ENABLE_SEND_QUEUE
#define kXcpStimOdtCount                     0x04u
#define XCP_ENABLE_DAQ_PRESCALER
#define XCP_ENABLE_DAQ_OVERRUN_INDICATION
#define XCP_ENABLE_WRITE_DAQ_MULTIPLE

#define XCP_DISABLE_DAQ_HDR_ODT_DAQ
#define XCP_DISABLE_ODT_SIZE_WORD

#define XCP_DISABLE_DAQ_RESUME
#define XCP_ENABLE_DAQ_PROCESSOR_INFO
#define XCP_ENABLE_DAQ_RESOLUTION_INFO
/*  */ 
/* Events */ 
#define XCP_DISABLE_DAQ_EVENT_INFO
#define kXcpMaxEvent                         2
/*  */ 
/* DAQ Timestamp */ 
#define XCP_ENABLE_DAQ_TIMESTAMP
#define XCP_DISABLE_DAQ_TIMESTAMP_FIXED
#define kXcpDaqTimestampUnit                 DAQ_TIMESTAMP_UNIT_1MS
#define kXcpDaqTimestampTicksPerUnit         1
#define kXcpDaqTimestampSize DAQ_TIMESTAMP_BYTE
/*  */ 
/* Page switching */ 
#define XCP_ENABLE_CALIBRATION_PAGE
#define kXcpMaxSegment                       1
#define XCP_ENABLE_PAGE_INFO
#define kXcpMaxPages                         2
#define XCP_ENABLE_PAGE_COPY
#define XCP_ENABLE_PAGE_FREEZE
/*  */ 
/* Programming */ 
#define XCP_ENABLE_PROGRAM
#define kXcpProgramMinStPgm                  0
#define kXcpProgramMaxSector                 1
#define XCP_DISABLE_PROGRAM_INFO
/*  */ 
#define CP_XCPDLL_VERSION                    0x0209u
#define CP_XCPDLL_RELEASE_VERSION            0x00u
#define XCP_SEND_QUEUE_SAMPLE_ODT
#define XCP_TRANSPORT_LAYER_TYPE_FLEXRAY_ASR

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 2124540520
      #error "The magic number of the generated file <D:\USR\_PROJECTS\Audi\EE-82\D4_MJ09_FR\E50_Verification\XCPonFlexRay\zTsi_XcpOnFlexRay\V85x\GHS\StandardECU_TTXSWV01.12.02\_Demo\DemoXcp\schedule\xcp_cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 2124540520
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __XCP_CFG_H__ */
