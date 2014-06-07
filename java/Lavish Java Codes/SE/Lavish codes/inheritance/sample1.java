// program showing member hiding and the use of super keyword.

class Alfa
{
	int x=90;

}

class Beta extends Alfa
{
	int x=100;

	public void display()
	{
		System.out.println("x of super class is "+super.x);
	}
	
}

class Main
{
	public static void main(String args[])
	{
		Beta b=new Beta();				
		b.display();	
	}
}