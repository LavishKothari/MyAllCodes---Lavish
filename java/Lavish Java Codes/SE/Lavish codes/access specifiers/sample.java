class Sample
{
	private void display()
	{
		System.out.println("display is private...");
	}
	protected void display1()
	{
		System.out.println("display1 is protected...");
	}
	void display2()
	{
		System.out.println("display2 is default");
	}
	public void display3()
	{	
		System.out.println("display3 is public");
	}
}

class Main
{
	public static void main(String args[])
	{
		Sample s=new Sample();
		//s.display();
		s.display1();
		s.display2();
		s.display3();
	}
}
				