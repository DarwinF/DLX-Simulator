#ifndef dlx_dlx_sim_h_
#define dlx_dlx_sim_h_

/*************************************************************************************************/
// Instruction Format
// 
// R-Type								        I-Type								            J-Type
//	Bits								         Bits								                Bits
//		31-26	Ocode (Always 0)        31-26	Opcode						          31-26	Opcode
//		25-21	Register Source 1			  25-21	Register Source 1			      25-0	Value
//		20-16	Register Source 2			  20-16	Register Destination
//		15-11	Register Destination		15-0	Immediate Value
//		10-6	Unused
//		5-0		Function Code
//
// Example Instructions
//		R-Type:		ADD		r5 = r1 + r2
//		R-Type:		000000 00001 00010 00101 00000 100000
//
//		I-Type:		ADDI	r5 = r1 + 10
//		I-Type:		001000 00001 00101 0000000000001010
//
//		J-Type:		JUMP	8
//		J-Type:		000010 11111111111111111111111000
// 
//		Extend()  - Immediate values are padded by left-most bit
//				      - Otherwise, pad left with 0
//
/*************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "errors.h"
#include "logger.h"

typedef uint16_t HWORD;
typedef uint32_t WORD;
typedef uint64_t DWORD;

#endif
