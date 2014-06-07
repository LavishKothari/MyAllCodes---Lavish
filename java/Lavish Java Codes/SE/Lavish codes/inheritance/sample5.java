// for preventing method over-riding
// as display is final so it cannot be over-ridden in any sub class.

class Alfa
{
	final public void display()
	{
		System.out.println("in the display of Alfa class");
	}
}

class Beta extends Alfa
{
	public void display()
	{
		System.out.println("in the display of Beta class");
	}
}

class Main
{
	public static void main(String[]args)
	{
		System.out.println("this is the ending of the program");
	}
}