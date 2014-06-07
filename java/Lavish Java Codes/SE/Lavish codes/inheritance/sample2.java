// program showing method over-riding 
// use of super keyword to access super class method.

class Alfa
{
	int x=90;
	void show()
	{
		System.out.println("you are in the show of Alfa");
	}
}

class Beta extends Alfa
{
	int x=100;

	public void display()
	{
		System.out.println("x of super class is "+super.x);
	}
	void show()	
	{	
		System.out.println("you are in the show of Beta");
		super.show();
	}	
}

class Main
{
	public static void main(String args[])
	{
		Beta b=new Beta();				
		b.show();	
	}
}