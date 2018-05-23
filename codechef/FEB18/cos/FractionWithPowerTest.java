package FEB18.cos;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class FractionWithPowerTest {

	@Test
	void test() {
		assertEquals(FractionWithPower.square(new FractionWithPower()),FractionWithPower.FRACTION_ONE);
		assertEquals(FractionWithPower.square(new FractionWithPower(2,3)),new FractionWithPower(4,9));
		assertEquals(FractionWithPower.square(new FractionWithPower(0)),new FractionWithPower(0));
		
	}

}
