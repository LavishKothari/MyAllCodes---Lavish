// basics about constructors and multi level inheritance

// constructor calling order 	---> from sub-class to the super-class
// execution order		---> from super-class to the sub-class

class Alfa
{
	Alfa()
	{	
		System.out.println("in the constructor of alfa");
	}
}

class Beta extends Alfa
{
	Beta()
	{
		System.out.println("in the constructor of Beta");
	}
}

class Main
{
	public static void main(String args[])
	{	
		Beta b=new Beta();
	}
}