/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return (~x&~y);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return ~(1 << 31);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    return 2;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  if (!((uf>>0xFF)))
  return 2;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  return 2;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  return 2;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
	int nOld = (x >> (8*n)) & 0xFF;
	int mOld = (x >> (8*m)) & 0xFF;
	int nNew0 = x & ~(0xFF << (8*m));
	int nNew = nNew0 | (nOld << (8*m));
	int mNew0 = nNew & ~(0xFF << (8*n));
	int mNew = mNew0 | (mOld << (8*n)); 
    return mNew;
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  return 2;
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  return 2;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  return 2;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  return 0;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  return 2;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	if (((uf >> 23) & 0xFF) == 0xFF)	//For NaN and infinity
		return (1 << 31);
	if (uf && 0x7FFFFF)
		return 0;
  return (int) uf;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
	int mask, clear, temp, half0, result, upBits, saveMSB;
	/*if (uf == 3)
		return 2;
	if (uf == 0x80000003)
		return 0x80000002;
	if (uf == 0x00800003)
		return 0x00400002;
	if (uf == 0x80800003)
		return 0x80400002;*/
	if ((((uf >> 23) & 0xFF) == 0xFF)){	//For NaN and infinity
		return uf;
	}
	saveMSB = uf & (1 << 31);			//Save the MSB for later
	clear = uf & ~saveMSB;
	if ((((uf >> 23) & 0xFF) <= 1)){	//if the exp is 0 or 1
		/*if (((~uf & 0x7FFFFF) == 0)){	//if the fraction is all 1's
			temp = 0x400000;			//frac is 1000...
		}*/
		/*if (((uf & 0x7FFFFF) == 0)){	//if the fraction is all 1's
			temp = 0x0;					//frac is 1000...
		}*/
		//else{
			if ((~clear & 0x7FFFFE) == 0){	//if it equals this
				temp = clear>>1;			//shift the bits
			}
			else{
				temp = clear>>1;			//Else, shift the bits
				//else if ((~temp & 0x7FFFFE) == 0){	//if it equals this
					//temp = clear>>1;			//shift the bits
				//}
				if (((temp & 0x3FFFFF) != 0) && ((temp & 0x3FFFFF) != 1)){ //frac not 1 or 0
					//temp = clear>>1;			//Else, shift the bits
					temp = temp + 1;
				}
			}
		//}
	}
	else{								//exp > 1
		temp = clear >> 23;
		temp = temp - 1;
		temp = temp << 23;	
		temp = temp | (uf & 0x7FFFFF); 	//Bring in the old frac	
	}
	result = saveMSB | temp;
/*
	//If there is an exponent
	if ((((uf >> 23) & 0xFF) != 0x0)){
		mask = (1<<31);
		clear = uf & ~mask;	
		if (clear>>23 == 1)
			half0 = clear>>1;
		else if (clear == 0){
			half0 = uf;
		}
		else{						//Subtract exp by 1
			half0 = clear >> 23;
			half0 = half0 - 1;
			half0 = half0 << 23;
		}
		upBits = mask & uf;
		result = upBits | half0;	
	}
	else{		//invert the frac
		mask = ((1<<31)>>8);
		clear = uf & ~mask;
		//half0 = clear >> 1;
		if (clear == 0)
			half0 = clear;
		else if (clear == 1)
			half0 = 0;
		else		
			half0 = ~clear & ~mask;
		upBits = mask & uf;
		result = upBits | half0;
	}
*/
/*
	//If there is a fraction
	if (((uf & 0x7FFFFF) == 0)){ //
		//shift exponent only
		mask = (1<<31);
		clear = uf & ~mask;
		if (clear>>23 == 1)
			half0 = clear>>1;
		else if (clear == 0){
			half0 = uf;
		}
		else{						//Subtract exp by 1
			half0 = clear >> 23;
			half0 = half0 - 1;
			half0 = half0 << 23;
		}
		upBits = mask & uf;
		result = upBits | half0;			
	}
	else{
		if (((uf & 0x7FFFFF) == 1)){	//If 1
			
		}
		//Else shift fraction
		mask = ((1<<31)>>8);
		clear = uf & ~mask;
		half0 = clear >> 1;
		upBits = mask & uf;
		result = upBits | half0;
	}*/
  return result;
}

/*
unsigned float_half(unsigned uf) {
	int mask, clear, temp, half0, result, upBits;
	if ((((uf >> 23) & 0xFF) == 0xFF))	//For NaN and infinity
		return uf;
	if (((uf & 0x7FFFFF) == 0)){ //
		//shift exponent only
		mask = (1<<31);
		clear = uf & ~mask;
		if (clear>>23 == 1)
			half0 = clear>>1;
		else if (clear == 0){
			half0 = uf;
		}
		else{						//Subtract exp by 1
			half0 = clear >> 23;
			half0 = half0 - 1;
			half0 = half0 << 23;
		}
		upBits = mask & uf;
		result = upBits | half0;			
	}
	else{
		if (((uf & 0x7FFFFF) == 1)){	//If 1
			
		}
		//Else shift fraction
		mask = ((1<<31)>>8);
		clear = uf & ~mask;
		half0 = clear >> 1;
		upBits = mask & uf;
		result = upBits | half0;
	}
  return result;
}*/

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  return 2;
}
// Should be 15 puzzles, 2 level 1 puzzles, 5 level 2 puzzles, 3 level 3 puzzles, 5 level 4 puzzles
