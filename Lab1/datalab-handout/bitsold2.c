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
	return  ((~x) & (~y));  // DeMorgans
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	return ~(1 << 31); // max int is 0 followed by all ones. Construct 1 followed by all 0's, and invert
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
    int msb;
    msb = x >> 31; // gets either zero of 1, sign extended msb
    x = !!x; // normalize x, if zero -> 0, else -> 1
    return msb + msb + x;
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
	unsigned msb,mask,nancheck;
	mask =  ~(1 << 31);				//Mask to invert sign bit
	msb = uf >> 31;					//Check the MSB (sign bit)
	nancheck = uf >> 22;			//Shift the NaN bits to LSB
	nancheck = nancheck & 0xff; 	//Only check the 8 NaN bits, not the sign bit
	if(!(nancheck ^ 0xff)) 			// check for NAN
	{
		return uf;					//If Nan, return original
	}
	else if(msb == 1)				//If sign bit is 1, negative. Invert bit
		uf = uf & mask;				//Invert sign bit
	return uf;						//Return Absoulte value
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
	return ((x << 31) >> 31); // boom
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
	return !((~x) & 0x55555555);
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
	int nOld,mOld,nNew,mNew,nO,mO;
	nOld = (x >> (8*n) & 0xFF); // It made sense at the time
	mOld = (x >> (8*m) & 0xFF);
	nO = x & ~(0xFF << (8*m));
	nNew = nO | (nOld << (8*m));
	mO = nNew & ~(0xFF << (8*n));
	mNew = mO | (mOld << (8*n));
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
	int b0,b1,b2,b3,res;
	b0 = x & 0xff;
	b1 = (x >> 8) & 0xff;
	b2 = (x >> 16) & 0xff;
	b3 = (x >> 24) & 0xff;
	res = (b0 << 8) + b1;
	res = (res << 8) + b2;
	res = (res << 8) + b3;

	return res;
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
	int t1,t2;
	t1 = 0xffffffff;
	t2 = 0xffffffff;
	t1 = t1 << lowbit;
	t2 = t2 << highbit;
	t2 = t2 << 1; // dont ask me why we can do the shift all at once

	return t1 & ~(t2);
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {

   // there are 2 cases can lead to x < y
   // 1) x < 0 and y >= 0
   // 2) x and y have the same sign,
   //    and x - y is negative
   
  int res,flag1,flag2;
  res = x + (~y + 1); // x - y
  flag1 = x & (~y); // msb, x is neg and y is >= 0
  flag2 = (~(x ^ y)) & res; // checks if msb of x and y are the same(same sign)

  return (flag1 | flag2) >> 31 & 1;
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
	int y, result, bitnum;

	result = 1; // at least one bit
	y = x^(x>>31); 	//make x positive, keep number of bits

	// Check the high 16 bits, add 16 or zero to result
	bitnum = (!(!(y & 0xffff0000))) << 4; // 1 or 0 << 4 
	result += bitnum; // 16 or 0
	y = y >> bitnum; // right shift y by 16 or 0
					 // either going to look at top 16 for more bits, or move on to other bits

	// Check the next 8 bits, add 8 or zero to result
	bitnum = (!!(y & 0xff00)) << 3;  // 1 or 0 << 3
	result += bitnum; // 8 or 0
	y = y >> bitnum;  // right shift y by 8 or 0

	// Check the next 4 bits, add 4 or zero to result
	bitnum = (!!(y & 0xf0)) << 2;  // 1 or 0 << 2
	result += bitnum; // 4 or 0
	y = y >> bitnum;  // right shift y by 4 or 0

	// Check the next 2 bits, add 2 or zero to result
	bitnum = (!!(y & 0xc)) << 1;  // 1 or 0 << 1
	result += bitnum;  // 2 or 0
	y = y >> bitnum;   // right shift y by 2 or 0

	// Check the last bit, add 1 or zero to result
	bitnum = !!(y & 0x2);  // 1 or 0
	result += bitnum;  	// 1 or 0
	y = y >> bitnum;	// right shift y by 1 or 0

	return result + (y&1);
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
	int mask,isPw2,isPos;
	mask = 1 << 31;
	isPw2 = !(x & (x - 1)); // if it was a power of 2, subtracting 1 and & with original, gives 0
	isPos = !((x & mask) | !x); // the !x, checks for the zero case
  return  isPos && isPw2;
}
/* 
 *   float_f2i - Return bit-level equivalent of expression (int) f
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
	unsigned sign,exp,frac,deNormBias,res;

	deNormBias = 0x7F;
	sign = uf >> 31; // sign bit
	exp = (uf >> 23) & 0xFF; // exponent
	frac = (uf & 0x7FFFFF); // fraction

	
	if (exp == 0xFF) // Nan and infinity
		return 0x80000000u;
	if (exp < deNormBias) // denormalized cases
		return 0x0;

	// normalized cases
	exp -= deNormBias;
	if (exp >= 31) // underflow from subtraction 
		return 0x80000000u;
	if (exp > 22) // get integer result after shift corresponding bits
		res = frac << (exp - 23);
	else 
		res = frac >> (23 - exp);
	res += 1 << exp; // add 1 << exp
	if (sign) // if sign = 1, negate result
		res = (~res) + 1;
	return res;
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
	if ((((uf >> 23) & 0xFF) == 0xFF)){	//For NaN and infinity
		return uf;
	}
	saveMSB = uf & (1 << 31);			//Save the MSB for later
	clear = uf & ~saveMSB;
	if ((((uf >> 23) & 0xFF) <= 1)){	//if the exp is 0 or 1
		temp = clear>>1;			//Else, shift the bits
		//temp = temp + 1;
		/*if (((temp & 0x3FFFFF) != 0) && ((temp & 0x3FFFFF) != 1)){ //frac not 1 or 0
			temp = temp + 1;
		}*/
	}
	else{								//exp > 1
		temp = clear >> 23;
		temp = temp - 1;
		temp = temp << 23;	
		temp = temp | (uf & 0x7FFFFF); 	//Bring in the old frac	
	}
	result = saveMSB | temp;
  return result;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
	unsigned y;
	y = x ^ (x >> 1); // basically, if there is a 1 anywhere, 
	y = y ^ (y >> 2); // we want to trap it or combine all the ones into the lsb
	y = y ^ (y >> 4);
	y = y ^ (y >> 8);
	y = y ^ (y >>16);
	return y & 1;
}
// Should be 15 puzzles, 2 level 1 puzzles, 5 level 2 puzzles, 3 level 3 puzzles, 5 level 4 puzzles
