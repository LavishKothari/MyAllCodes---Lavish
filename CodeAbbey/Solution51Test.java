package codeabbey;

import static org.junit.jupiter.api.Assertions.*;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import org.junit.Before;
import org.junit.jupiter.api.Test;

class Solution51Test {

	@Test
	public void nckTest() throws NoSuchMethodException, SecurityException, IllegalAccessException,
	IllegalArgumentException, InvocationTargetException {
		Method nck = Solution51.class.getDeclaredMethod("nck", int.class,int.class);
		nck.setAccessible(true);
		int result = (int) nck.invoke(null, 5,1);
		assertEquals(result,5);
	}
	@Test
	public void factorialTest() throws NoSuchMethodException, SecurityException, IllegalAccessException,
	IllegalArgumentException, InvocationTargetException {
		Method factorial = Solution51.class.getDeclaredMethod("factorial", int.class);
		factorial.setAccessible(true);
		int result = (int) factorial.invoke(null, 0);
		assertEquals(result,1);
	}
	
}
