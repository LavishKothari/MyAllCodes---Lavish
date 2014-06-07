// illustration of how you can pass any type of argument in java
// whether it be a primitive data type or let it be an object.
class Complex
{
	double r,i;
	Complex(){}
	Complex(double r,double i)
	{	
		this.r=r;
		this.i=i;
	}
	
	public static void test(int a,int b)
	{
		a+=5;
		b+=10;
	}

	public static void swap(Complex c)
	{
		double tmp;
		tmp=c.r;
		c.r=c.i;
		c.i=tmp;
	}	
	
	public String toString()
	{	
		String s=new String(this.r+" + i "+this.i);
		return s;
	}
}


class Main
{
	public static void main(String []args)
	{
		
		int x=90,y=89;
		Complex.test(x,y);
		System.out.println("x,y = "+x+","+y);
		
		Complex c=new Complex(5,3);
		Complex.swap(c);		
		System.out.println(c);
	}
}	