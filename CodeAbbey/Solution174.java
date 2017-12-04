package codeabbey;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Solution174 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {

		StringTokenizer stz = new StringTokenizer(br.readLine());
		int k = Integer.parseInt(stz.nextToken());
		int steps = Integer.parseInt(stz.nextToken());

		String radiusStr = "1";
		for (int i = 0; i < k; i++)
			radiusStr = radiusStr + "0";

		BigInteger radius = new BigInteger(radiusStr);
		BigInteger sideLength = new BigInteger(radiusStr);
		BigInteger sides = new BigInteger("6");
		for (int i = 0; i < steps; i++) {
			BigInteger d = sideLength.divide(BigInteger.valueOf(2));
			BigInteger R2 = radius.multiply(radius);
			BigInteger d2 = d.multiply(d);

			BigInteger h = calSqrt(R2.subtract(d2));
			BigInteger temp = radius.subtract(h);
			BigInteger temp2 = temp.multiply(temp);

			sideLength = calSqrt(d2.add(temp2));

			sides = sides.multiply(BigInteger.valueOf(2));

			// System.out.println(d+" "+h+" "+sideLength+" for "+sides+"sides");
		}

		System.out.println(sideLength.multiply(sides).divide(BigInteger.valueOf(2)));
	}

	public static BigInteger calSqrt(BigInteger n) {

		BigInteger start = BigInteger.ONE;
		BigInteger end = n.subtract(BigInteger.valueOf(1));
		return calSqrt(n, start, end);

	}

	private static BigInteger calSqrt(BigInteger n, BigInteger start, BigInteger end) {

		// System.out.println(n+" "+start+" "+end);
		while (start.compareTo(end) <= 0) {
			BigInteger mid = start.add(end).divide(BigInteger.valueOf(2));
			BigInteger mid2 = mid.multiply(mid);
			BigInteger mid21 = mid2.add(BigInteger.ONE);
			if (mid2.compareTo(n) == 0)
				return mid;
			if (mid2.compareTo(n) <= 0 && mid21.compareTo(n) > 0)
				return mid;
			if (mid2.compareTo(n) < 0)
				return calSqrt(n, mid.add(BigInteger.ONE), end);
			return calSqrt(n, start, mid.subtract(BigInteger.ONE));
		}
		if (end.multiply(end).compareTo(n) <= 0 && start.multiply(start).compareTo(n) > 0)
			return end;
		return null;
	}

}
