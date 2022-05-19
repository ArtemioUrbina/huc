// **************************************************************************
// **************************************************************************
//
// errorcode.c
//
// Global error handling for a program.
//
// Copyright John Brandwood 1994-2022.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// **************************************************************************
// **************************************************************************

#include  "elmer.h"
#include  "errorcode.h"

// Fatal error flag.
//
// Used to signal that the error returned by ErrorCode (see below) is fatal
// and that the program should terminate immediately.

bool g_bFatalError = NO;      // Non-zero if program should abort.

// Global error reporting variables.
//
// Used by all functions to indicate what error has occurred if they signal
// that something has gone wrong.
//
// The different codes used are defined in elmer.hpp

ERRORCODE g_iErrorCode = ERROR_NONE;    // Integer error number < 0 if error.
char g_aErrorMessage[256];      // Error message string.

// String used for printing out variables of type ID2 and ID4.

char ID2String[4];
char ID4String[8];

// FlipTable[] - Index into this table to get bit reversed value of a byte.

uint8_t FlipTable[256] =
{
  0x00, 0x80, 0x40, 0xC0, 0x20, 0xA0, 0x60, 0xE0,
  0x10, 0x90, 0x50, 0xD0, 0x30, 0xB0, 0x70, 0xF0,
  0x08, 0x88, 0x48, 0xC8, 0x28, 0xA8, 0x68, 0xE8,
  0x18, 0x98, 0x58, 0xD8, 0x38, 0xB8, 0x78, 0xF8,
  0x04, 0x84, 0x44, 0xC4, 0x24, 0xA4, 0x64, 0xE4,
  0x14, 0x94, 0x54, 0xD4, 0x34, 0xB4, 0x74, 0xF4,
  0x0C, 0x8C, 0x4C, 0xCC, 0x2C, 0xAC, 0x6C, 0xEC,
  0x1C, 0x9C, 0x5C, 0xDC, 0x3C, 0xBC, 0x7C, 0xFC,
  0x02, 0x82, 0x42, 0xC2, 0x22, 0xA2, 0x62, 0xE2,
  0x12, 0x92, 0x52, 0xD2, 0x32, 0xB2, 0x72, 0xF2,
  0x0A, 0x8A, 0x4A, 0xCA, 0x2A, 0xAA, 0x6A, 0xEA,
  0x1A, 0x9A, 0x5A, 0xDA, 0x3A, 0xBA, 0x7A, 0xFA,
  0x06, 0x86, 0x46, 0xC6, 0x26, 0xA6, 0x66, 0xE6,
  0x16, 0x96, 0x56, 0xD6, 0x36, 0xB6, 0x76, 0xF6,
  0x0E, 0x8E, 0x4E, 0xCE, 0x2E, 0xAE, 0x6E, 0xEE,
  0x1E, 0x9E, 0x5E, 0xDE, 0x3E, 0xBE, 0x7E, 0xFE,
  0x01, 0x81, 0x41, 0xC1, 0x21, 0xA1, 0x61, 0xE1,
  0x11, 0x91, 0x51, 0xD1, 0x31, 0xB1, 0x71, 0xF1,
  0x09, 0x89, 0x49, 0xC9, 0x29, 0xA9, 0x69, 0xE9,
  0x19, 0x99, 0x59, 0xD9, 0x39, 0xB9, 0x79, 0xF9,
  0x05, 0x85, 0x45, 0xC5, 0x25, 0xA5, 0x65, 0xE5,
  0x15, 0x95, 0x55, 0xD5, 0x35, 0xB5, 0x75, 0xF5,
  0x0D, 0x8D, 0x4D, 0xCD, 0x2D, 0xAD, 0x6D, 0xED,
  0x1D, 0x9D, 0x5D, 0xDD, 0x3D, 0xBD, 0x7D, 0xFD,
  0x03, 0x83, 0x43, 0xC3, 0x23, 0xA3, 0x63, 0xE3,
  0x13, 0x93, 0x53, 0xD3, 0x33, 0xB3, 0x73, 0xF3,
  0x0B, 0x8B, 0x4B, 0xCB, 0x2B, 0xAB, 0x6B, 0xEB,
  0x1B, 0x9B, 0x5B, 0xDB, 0x3B, 0xBB, 0x7B, 0xFB,
  0x07, 0x87, 0x47, 0xC7, 0x27, 0xA7, 0x67, 0xE7,
  0x17, 0x97, 0x57, 0xD7, 0x37, 0xB7, 0x77, 0xF7,
  0x0F, 0x8F, 0x4F, 0xCF, 0x2F, 0xAF, 0x6F, 0xEF,
  0x1F, 0x9F, 0x5F, 0xDF, 0x3F, 0xBF, 0x7F, 0xFF
};



// **************************************************************************
// **************************************************************************
//
//  ErrorReset ()
//
//  Usage
//    global void ErrorReset (void)
//
//  Description
//    Reset the error condition flags.
//
//  Return Value
//    None.
//

void ErrorReset (void)

{
  g_iErrorCode = ERROR_NONE;

  *g_aErrorMessage = '\0';
}



// **************************************************************************
// **************************************************************************
//
//  ErrorQualify ()
//
//  Usage
//    global void ErrorQualify (void)
//
//  Description
//    If g_aErrorMessage is blank, then fill it in with a generic error
//    message.
//
//  Return Value
//    None.
//

void ErrorQualify (void)

{
  if (*g_aErrorMessage == '\0') {
    if (g_iErrorCode == ERROR_NONE) {
    }

    else if (g_iErrorCode == ERROR_DIAGNOSTIC) {
      sprintf(g_aErrorMessage,
        "Error : Error during diagnostic printout.\n");
    }

    else if (g_iErrorCode == ERROR_NO_MEMORY) {
      sprintf(g_aErrorMessage,
        "Error : Not enough memory to complete this operation.\n");
    }

    else if (g_iErrorCode == ERROR_NO_FILE) {
      sprintf(g_aErrorMessage,
        "Error : File not found.\n");
    }

    else if (g_iErrorCode == ERROR_IO_EOF) {
      sprintf(g_aErrorMessage,
        "Error : Unexpected end-of-file.\n");
    }

    else if (g_iErrorCode == ERROR_IO_READ) {
      sprintf(g_aErrorMessage,
        "Error : I/O read failure (file corrupted ?).\n");
    }

    else if (g_iErrorCode == ERROR_IO_WRITE) {
      sprintf(g_aErrorMessage,
        "Error : I/O write failure (is the file read-only or not checked-out?).\n");
    }

    else if (g_iErrorCode == ERROR_IO_SEEK) {
      sprintf(g_aErrorMessage,
        "Error : I/O seek failure (file corrupted ?).\n");
    }

    else if (g_iErrorCode == ERROR_PROGRAM) {
      sprintf(g_aErrorMessage,
        "Error : A program error has occurred.\n");
    }

    else {
      sprintf(g_aErrorMessage,
        "Error : Unknown error number.\n");
    }
  }
}
