// basics about constructors and single inheritance

// constructor calling order 	---> from sub-class to the super-class
// execution order		---> from super-class to the sub-class

class Alfa
{
	Alfa()
	{
		System.out.println("in the constructor of Alfa");
	}
	public void display0()
	{
		System.out.println("in the public display()");
	}
	void display1()
	{
		System.out.println("in the display()");	
	}
	protected void display2()
	{
		System.out.println("in the protected display()");	
	}
	private void display3()
	{
		System.out.println("in the private display()");		
	}
}

class Beta extends Alfa
{
	Beta()
	{
		//super();
		System.out.println("in the constructor of Beta");
	}	

}
	
class Main
{
	public static void main(String args[])
	{
		Beta b=new Beta();
		b.display0();
		b.display1();
		b.display2();
		// b.display3();
	}
}	