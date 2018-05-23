package FEB18.cos;

class FractionWithPower {
	private Fraction fraction;
	private Fraction power;

	public static final FractionWithPower FRACTION_ONE = new FractionWithPower();
	public static final FractionWithPower FRACTION_TWO = new FractionWithPower(2);

	public Fraction getPower() {
		return power;
	}

	public void setPower(Fraction power) {
		this.power = power;
	}

	public Fraction getFraction() {
		return fraction;
	}

	public void setFraction(Fraction fraction) {
		this.fraction = fraction;
	}

	public FractionWithPower(long numerator, long denominator, Fraction power) {
		super();

		this.fraction = new Fraction(numerator, denominator);
		this.power = power;
		// fraction.reduce();
	}

	public FractionWithPower(long numerator) {
		super();
		this.fraction = new Fraction(numerator, 1);
		this.power = Fraction.FRACTION_ONE;
		// fraction.reduce();
	}

	public FractionWithPower(long numerator, long denominator) {
		super();
		this.fraction = new Fraction(numerator, denominator);
		this.power = Fraction.FRACTION_ONE;
	}

	public FractionWithPower() {
		this.fraction = new Fraction();
		this.power = Fraction.FRACTION_ONE;
	}

	public FractionWithPower(Fraction f) {
		this.fraction = new Fraction(f.numerator, f.denominator);
		this.power = Fraction.FRACTION_ONE;
	}

	public FractionWithPower(Fraction f, Fraction power) {
		this.fraction = new Fraction(f.numerator, f.denominator);
		this.power = power;
	}

	public static FractionWithPower square(FractionWithPower f) {
		if (f.power.equals(Fraction.FRACTION_ONE)) {
			return new FractionWithPower(f.fraction.numerator * f.fraction.numerator,
					f.fraction.denominator * f.fraction.denominator, f.power);
		}
		return new FractionWithPower(f.fraction.numerator, f.fraction.denominator,
				Fraction.multiply(f.fraction, Fraction.FRACTION_TWO));
	}

	public static FractionWithPower multiply(FractionWithPower f1, FractionWithPower f2) {
		if (f1.power.equals(f2.power)) {
			return new FractionWithPower(Fraction.multiply(f1.fraction, f2.fraction), f1.power);
		} else
			throw new IllegalArgumentException(
					"the fractions are not having the same power, so couldn't really multiply");
	}

	public static FractionWithPower subtract(FractionWithPower f1, FractionWithPower f2) {
		if (f1.power.equals(f2.power)) {
			return new FractionWithPower(Fraction.subtract(f1.fraction, f2.fraction), f1.power);
		} else
			throw new IllegalArgumentException(
					"the fractions are not having the same power, so couldn't really multiply");
	}

	@Override
	public String toString() {
		return "FractionWithPower [fraction=" + fraction.numerator + " " + fraction.denominator + ", power=" + power + "]";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((fraction == null) ? 0 : fraction.hashCode());
		result = prime * result + ((power == null) ? 0 : power.hashCode());
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
		FractionWithPower other = (FractionWithPower) obj;
		if (fraction == null) {
			if (other.fraction != null)
				return false;
		} else if (!fraction.equals(other.fraction))
			return false;
		if (power == null) {
			if (other.power != null)
				return false;
		} else if (!power.equals(other.power))
			return false;
		return true;
	}

	
	// public void reduce() {
	// this.fraction.reduce();
	// }
}