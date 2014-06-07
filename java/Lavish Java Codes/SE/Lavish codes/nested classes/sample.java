// concept of inner class...
// non-static nested classes are called inner classes.
// inner classes cannot have static declarations

class a
{
	a()
	{
		System.out.println("in the constructor of a");
	}		
	int x;
	class b
	{
		//static int z;			--> error	
		//inner classes cannot have static declarations
		b()
		{
			System.out.println("in the constructor of b");
		}		
	
		int y;
	}
}

class Main
{
	public static void main(String args[])
	{
		a a1=new a();
		a.b b1=a1.new b();
		a.b b2=a1.new b();
		a.b b3=a1.new b();
		a.b b4=a1.new b();
		a.b b5=a1.new b();

		a1.x=100;
		b1.y=10;
		b2.y=20;
		b3.y=30;
		b4.y=40;
		b5.y=50;

		System.out.println(a1.x);
		System.out.println(b1.y);
		System.out.println(b2.y);
		System.out.println(b3.y);
		System.out.println(b4.y);
		System.out.println(b5.y);
		
		System.out.println("the program completed successfully");
	}
}