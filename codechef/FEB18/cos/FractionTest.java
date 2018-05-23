package FEB18.cos;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

class FractionTest {

	Fraction f1 = new Fraction(2,3);
	Fraction f2 = new Fraction(3,9);
	
	
	@Test
	void addTest() {
		assertEquals(Fraction.add(f1, f2),Fraction.FRACTION_ONE);
	}

	@Test
	void subtractTest() {
		assertEquals(Fraction.subtract(f1, f2), f2);
	}

	@Test
	void multiplyTest() {
		assertEquals(Fraction.multiply(f1, f2), new Fraction(2, 9));
	}

	@Test
	void divideTest() {
		assertEquals(Fraction.divide(f1, f2), new Fraction(2));
	}
	
	
}
