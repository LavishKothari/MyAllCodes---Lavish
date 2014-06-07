package pkg1;
public class Complex
{
	double r,i;
	Complex()
	{
		System.out.println("Default Constructor called...");
	}
	public Complex(double r,double i)
	{
		this.r=r;
		this.i=i;
		System.out.println("argumeted constructor called...");
	}
	Complex(Complex c)
	{
		System.out.println("Copy constructor called...");
		this.r=c.r;
		this.i=c.i;
	}
	protected void finalize()
	{
		System.out.println("the finalize method has been called.s");
	}
	
	public String toString()
	{
		return String.format(this.r+" + i"+this.i);
	}	
	public Complex add(Complex c)
	{
		return new Complex(this.r+c.r,this.i+c.i);
	}
	
	private void display()
	{
		System.out.println("you are in the display -->private void display() of Complex class");
	}
	protected void display1()
	{
		System.out.println("you are in the display1 --> protected void display1() of Complex class");
	}
	void display2()
	{
		System.out.println("you are in the display2 --> void display2() of Complex class");
	}
	public void display3()
	{
		System.out.println("you are in the display3 --> public void display3() of Complex class");
	}
}
