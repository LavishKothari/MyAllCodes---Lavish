//notice the declaration
//final public static int a=90;
//a variable declared as final should be initialized at the place of its declaration
//static variables and methods can be accessed either by class name or by objects.
//but it is a good convention to use static members using class-name 

class Sample
{
	final public static int a=90;
}

class Main
{
	public static void main(String args[])
	{
		Sample s=new Sample();
		System.out.println("a = "+s.a);
		System.out.println("a = "+Sample.a);
		System.out.println("the program completed successfully");
	}
}