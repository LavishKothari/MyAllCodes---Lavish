class Complex
{
	double x,y; // x + iy
	Complex add(Complex c)
	{	
		Complex sum=new Complex();
		sum.x=this.x+c.x;
		sum.y=this.y+c.y;
		return sum;
	}
	void printComplex()
	{
		System.out.println(x+" + i"+y);
	}
}

class Main
{
	public static void main(String args[])
	{
		Complex c1,c2;
		c1=new Complex();
		c2=new Complex();
		c1.x=1;
		c1.y=4;
		
		c2.x=3;
		c2.y=2;
		
		Complex sum=c1.add(c2);
		sum.printComplex();
	}
}