package codeabbey;

import static org.junit.jupiter.api.Assertions.*;

import java.math.BigInteger;
import java.text.Bidi;

import org.junit.jupiter.api.Test;

class Solution174Test {

	@Test
	void sqrtTest() {
		BigInteger bi = new BigInteger("546546546465465465412654654654126546546541265465465464654654654");
		BigInteger s = Solution174.calSqrt(bi);
		BigInteger s1 = s.add(BigInteger.ONE);
		System.out.println(s);
		assertEquals(true,s.multiply(s).compareTo(bi)<=0 && s1.multiply(s1).compareTo(bi)>0);
	}

}
