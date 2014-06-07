// access control in same package.
class Sample
{
	int a,b;

	private void display()
	{
		System.out.println("you are in the display -->private void display() of Sample class");
	}

	protected void display1()
	{
		System.out.println("you are in the display1 --> protected void display1() of Sample class");
	}

	void display2()
	{
		System.out.println("you are in the display2 --> void display2() of Sample class");
	}
}

class Main
{
	public static void main(String args[])
	{
		Sample s=new Sample();
		// s.display();   this calling is invalid as display() is a private method
		s.display1();		// valid calling
		s.display2();		// valid calling
	}
}

		