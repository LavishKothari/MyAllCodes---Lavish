package FEB18.cos;
final class NumberUtils {
	private NumberUtils() {

	}

	public static long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	public static FractionWithPower sinntheta(long n, Fraction costheta) {
		if (n == 0)
			return new FractionWithPower(0);
		return FractionWithPower.FRACTION_ONE;

	}

	public static FractionWithPower cosntheta(long n, FractionWithPower costheta) {
		if (n == 0)
			return FractionWithPower.FRACTION_ONE;
		if (n == 1)
			return costheta;
		if (n == 2) {
			FractionWithPower cosSquare = FractionWithPower.square(costheta);
			FractionWithPower twoTimesSquare = FractionWithPower.multiply(cosSquare, FractionWithPower.FRACTION_TWO);
			return FractionWithPower.subtract(twoTimesSquare, FractionWithPower.FRACTION_ONE);
		}
		if (n == 3) {

			Fraction coscube = Fraction.multiply(costheta.getFraction(),
					Fraction.multiply(costheta.getFraction(), costheta.getFraction()));

			FractionWithPower a = new FractionWithPower();
			a.setFraction(Fraction.multiply(new Fraction(4), coscube));

			FractionWithPower b = new FractionWithPower();
			b.setFraction(Fraction.multiply(new Fraction(3), costheta.getFraction()));

			return FractionWithPower.subtract(a, b);
		}
		if (n % 2 == 0) {
			long x = n / 2;
			FractionWithPower cosSquare = FractionWithPower.square(cosntheta(x, costheta));
			FractionWithPower twoTimesSquare = FractionWithPower.multiply(cosSquare, FractionWithPower.FRACTION_TWO);
			return FractionWithPower.subtract(twoTimesSquare, FractionWithPower.FRACTION_ONE);
		} else
			throw new IllegalArgumentException("wrong test case");
	}

	public static long modularInverse(long a, long b) {
		return NumberUtils.power(a, b - 2, b);
		// works only if b is prime
//		if (NumberUtils.isPrime(b)) { // this is very computationally expensive
//			return NumberUtils.power(a, b - 2, b);
//		} else
//			throw new IllegalArgumentException(
//					"modular inverse in this case can be found only if second argument is a prime number");
	}

	public static long power(long a, long b, long m) {
		if (b == 0)
			return 1;
		if (b == 1)
			return a;
		long temp = NumberUtils.power(a, b / 2, m);
		if (b % 2 == 0)
			return (temp * temp) % m;
		return (((temp * temp) % m) * a) % m;
	}

	public static boolean isPrime(long n) {
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}

}