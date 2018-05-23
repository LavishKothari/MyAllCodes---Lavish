package FEB18.cos;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class NumberUtilsTest {

	private static final FractionWithPower costheta = new FractionWithPower(3,4);
	private static final int MOD = 1000000007;
	
	@Test
	void powerTest() {
		assertEquals(NumberUtils.power(1, 2, MOD), 1);
		assertEquals(NumberUtils.power(10000, 1, MOD), 10000);
		assertEquals(NumberUtils.power(1523, 0, MOD), 1);
		assertEquals(NumberUtils.power(2, 10, MOD), 1024);
		assertEquals(NumberUtils.power(2, 7, MOD),128);
	}
	
	@Test
	void GcdTest() {
		assertEquals(NumberUtils.gcd(5, 3),1);
		assertEquals(NumberUtils.gcd(3, 5),1);
		assertEquals(NumberUtils.gcd(6, 18),6);
		assertEquals(NumberUtils.gcd(15, 25),5);
		assertEquals(NumberUtils.gcd(1, 3),1);
		assertEquals(NumberUtils.gcd(3, 1),1);
		assertEquals(NumberUtils.gcd(123, 123),123);
	}
	
	@Test
	void cosnthetaTest() {
		assertEquals(NumberUtils.cosntheta(0, FractionWithPower.FRACTION_ONE), FractionWithPower.FRACTION_ONE);
		assertEquals(NumberUtils.cosntheta(1, costheta),costheta);
		assertEquals(NumberUtils.cosntheta(2, costheta),new FractionWithPower(1,8));
		assertEquals(NumberUtils.cosntheta(3, costheta),new FractionWithPower(-9,16));
		
	}
	

}
