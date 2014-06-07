interface Alfa
{
	int a=90; //variables must be initialized
	void show();
	void display();
}

class Beta implements Alfa
{
	public void show() //functions must be public
	{
		System.out.println("in show() function");
	}
	public void display() //functions must be public
	{
		System.out.println("in display() function");
	}
}

class Main
{
	public static void main(String args[])
	{
		Beta b=new Beta();
		b.show();
		b.display();
	}
}