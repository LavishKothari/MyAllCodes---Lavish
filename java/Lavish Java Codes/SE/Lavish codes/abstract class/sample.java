// abstract class cannot be instantiated.

abstract class Sample
{
	int a,b;
}

class sub extends Sample
{
}

class Main
{
	public static void main(String args[])
	{
		Sample s=new Sample();
	}
}		
	
