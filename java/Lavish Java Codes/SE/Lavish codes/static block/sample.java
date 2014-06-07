//static block is called prior to constructor
//static method and constructor are not called when you just create reference of a class
// non static variables and non static methods cannot be reference from a static context.
class Sample
{
	int a;
	Sample()
	{	
		System.out.println("default constructor called...");
	}

	public static void display()
	{
		System.out.println("display is a static method");
		//System.out.println("a = "+a);
		// non static variable a cannot be reference from a static context.
	}		

	static
	{
		System.out.println("Static block called...");
		// System.out.println("a = "+ a);
		// non static variable a cannot be reference from a static context.
	}
	
}

class Main
{
	public static void main(String args[])
	{
		//Sample s=new Sample();
		Sample.display();
		System.out.println("Program completed successfully...");
	}
}