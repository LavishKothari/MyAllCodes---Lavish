class Sample
{
	Sample()
	{	
		System.out.println("hello lavish kothari");
	}
	
	static
	{
		System.out.println("hello rakshit kothari");
	}
}

class Main
{
	public static void main(String []args)
	{
		Sample s=new Sample();		
		Sample a1=new Sample();
	}
}