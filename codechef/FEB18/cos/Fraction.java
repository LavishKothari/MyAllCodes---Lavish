package FEB18.cos;
class Fraction {

	protected final long numerator, denominator;
	public static final Fraction FRACTION_ONE = new Fraction();
	public static final Fraction FRACTION_TWO = new Fraction(2);

	public long getNumerator() {
		return numerator;
	}

	// public void setNumerator(long numerator) {
	// this.numerator = numerator;
	// }

	public long getDenominator() {
		return denominator;
	}

	// public void setDenominator(long denominator) {
	// this.denominator = denominator;
	// }

	public Fraction(long numerator, long denominator) {
		long gcd = NumberUtils.gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;

		this.numerator = numerator;
		this.denominator = denominator;
	}

	public Fraction(long numerator) {
		this.numerator = numerator;
		this.denominator = 1;
	}

	public Fraction() {
		this.numerator = 1;
		this.denominator = 1;
	}

	public static Fraction add(Fraction f1, Fraction f2) {
		Fraction tempFraction = new Fraction(f1.numerator * f2.denominator + f2.numerator * f1.denominator,
				f1.denominator * f2.denominator);
		// tempFraction.reduce();
		return tempFraction;
	}

	public static Fraction subtract(Fraction f1, Fraction f2) {
		Fraction tempFraction = new Fraction(f1.numerator * f2.denominator - f2.numerator * f1.denominator,
				f1.denominator * f2.denominator);
		// tempFraction.reduce();
		return tempFraction;
	}

	public static Fraction multiply(Fraction f1, Fraction f2) {
		Fraction tempFraction = new Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
		// tempFraction.reduce();
		return tempFraction;
	}

	public static Fraction reciprocal(Fraction f) {
		if (f.numerator == 0)
			throw new ArithmeticException("denominator of a fraction can't be zero!!");
		Fraction tempFraction = new Fraction(f.denominator, f.numerator);
		// tempFraction.reduce();
		return tempFraction;

	}

	public static Fraction divide(Fraction f1, Fraction f2) {
		return Fraction.multiply(f1, Fraction.reciprocal(f2));
	}

	public static Fraction square(Fraction f) {
		return new Fraction(f.numerator * f.numerator, f.denominator * f.denominator);
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + (int) (denominator ^ (denominator >>> 32));
		result = prime * result + (int) (numerator ^ (numerator >>> 32));
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Fraction other = (Fraction) obj;
		// reduce();
		// other.reduce();
		if (denominator != other.denominator)
			return false;
		if (numerator != other.numerator)
			return false;
		return true;
	}

	// public void reduce() {
	// long gcd = NumberUtils.gcd(this.numerator, this.denominator);
	// this.numerator /= gcd;
	// this.denominator /= gcd;
	// }

}
