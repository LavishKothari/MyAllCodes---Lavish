import pkg1.* ;

class Main
{
	public static void main(String args[])
	{
		Complex c=new Complex(5.0,3.0);
		System.out.println(c);
		//c.display(); 	//invalid
		//c.display1();	//invalid
		//c.display2();	//invalid
		c.display3();
	}
}		
