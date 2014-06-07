class Complex
{
	int a[]=new int [100000];
	double r,i;
	Complex()
	{
		System.out.println("Default Constructor called...");
	}
	Complex(double r,double i)
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
		System.out.println("Hello Lavish Kothari");
	}
}

class Main
{
	public static void main(String args[])
	{		
		Complex c1=new Complex();
		Complex c2=new Complex(5,3);
		Complex c3=new Complex(c2);
		for(int i=0;i<10;i++)
		{
			Complex c=new Complex();	
		}

	}
}