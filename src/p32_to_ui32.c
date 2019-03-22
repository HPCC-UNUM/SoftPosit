
/*============================================================================

This C source file is part of the SoftPosit Posit Arithmetic Package
by S. H. Leong (Cerlane) and John Gustafson.

Copyright 2017 2018 A*STAR.  All rights reserved.

This C source file was based on SoftFloat IEEE Floating-Point Arithmetic
Package, Release 3d, by John R. Hauser.

Copyright 2011, 2012, 2013, 2014, 2015, 2016, 2017 The Regents of the
University of California.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions, and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions, and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 3. Neither the name of the University nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/


#include "platform.h"
#include "internals.h"

uint_fast32_t pX2_to_ui32( posit_2_t pA ) {
	posit32_t p32 = {.v = pA.v};
	return p32_to_ui32(p32);
}

uint_fast32_t p32_to_ui32( posit32_t pA ) {

    union ui32_p32 uA;
    uint_fast64_t iZ64, mask, tmp;
    uint_fast32_t iZ, scale = 0, uiA;
    bool bitLast, bitNPlusOne, bitsMore;

    uA.p = pA;
    uiA = uA.ui;

    //NaR
	if (uiA==0x80000000) return uiA;
	//negative
	else if (uiA>0x80000000) return 0;

	if (uiA <= 0x38000000) {                     // 0 <= |pA| <= 1/2 rounds to zero.
		return 0;
	}
	else if (uiA < 0x44000000) {                 // 1/2 < x < 3/2 rounds to 1.
		return 1;
	}
	else if (uiA <= 0x4A000000) {                // 3/2 <= x <= 5/2 rounds to 2.
		return 2;
	}
	//overflow so return max integer value
	else if(uiA>0x7FBFFFFF){
		return 0xFFFFFFFF;
	}
	else {
		uiA -= 0x40000000;
		while (0x20000000 & uiA) {
			scale += 4;
			uiA = (uiA - 0x20000000) << 1;
		}
		uiA <<= 1;  								// Skip over termination bit, which is 0.
		if (0x20000000 & uiA) scale+=2;          	// If first exponent bit is 1, increment the scale.
		if (0x10000000 & uiA) scale++;
		iZ64 = ((uiA | 0x10000000ULL)&0x1FFFFFFFULL) << 34;	// Left-justify fraction in 32-bit result (one left bit padding)

		mask = 0x4000000000000000 >> scale; 	 // Point to the last bit of the integer part.

		bitLast = (iZ64 & mask);               // Extract the bit, without shifting it.
		mask >>= 1;
		tmp = (iZ64 & mask);
		bitNPlusOne = tmp;                   // "True" if nonzero.
		iZ64 ^= tmp;                           // Erase the bit, if it was set.
		tmp = iZ64 & (mask - 1);               // tmp has any remaining bits. // This is bitsMore
		iZ64 ^= tmp;                           // Erase those bits, if any were set.

		if (bitNPlusOne) {                   // logic for round to nearest, tie to even
			if (bitLast | tmp) iZ64 += (mask << 1);
		}
		iZ = iZ64 >> (62 - scale);             // Right-justify the integer.
	}

    return iZ;
}

