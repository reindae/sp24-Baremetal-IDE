/**
 * @file rv_common.h
 * @brief RISC-V Definitions
 * 
 * This header file provides common definitions and operations for RISC-V core programming.
 * It includes memory register attributes, bit operation definitions, RISC-V specific definitions,
 * and common enumerations for state and status values.
 *
 * The memory register attributes define volatile permissions for read-only, write-only, and read/write access.
 * The bit operation definitions provide macros for setting, clearing, reading, and writing specific bits in a register.
 * The RISC-V specific definitions include macros for reading and writing control and status registers (CSRs),
 * as well as operations to swap, set, and clear specific bits in a CSR.
 * The common definitions include enumerations for state values (such as RESET and SET), and status values (such as OK and ERROR).
 *
 * @note This file should be included to access RISC-V core-specific definitions and perform common operations.
 *
 * @author -T.K.-
 * @date 2023-05-20
 */
 
#ifndef __RV_H
#define __RV_H

#include <stdint.h>
#include <stddef.h>

/* ================ Memory register attributes ================ */
#ifdef __cplusplus
  #define   __I     volatile             /** Defines "read only" permissions */
#else
  #define   __I     volatile const       /** Defines "read only" permissions */
#endif
#define     __O     volatile             /** Defines "write only" permissions */
#define     __IO    volatile             /** Defines "read / write" permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /** Defines "read only" structure member permissions */
#define     __OM     volatile            /** Defines "write only" structure member permissions */
#define     __IOM    volatile            /** Defines "read / write" structure member permissions */


/* ================ Common definitions ================ */
typedef enum {
  RESET = 0UL,
  SET   = !RESET,

  DISABLE = RESET,
  ENABLE  = SET,
  
  LOW   = RESET,
  HIGH  = SET,
} State;

typedef enum {
  OK = 0U,
  ERROR,
  BUSY,
  TIMEOUT
} Status;

#endif /* __RV_H */
