class Demo
{
	int a,b;
	int arr[];
	
	Demo()
	{
		System.out.println("Default constructor called...");
		a=2;
		b=a*3;
		arr=null;
	}
}

class Main
{
	public static void main(String args[])
	{
		Demo d=new Demo();
		System.out.println("d.a = "+d.a+"   d.b = "+d.b+"  arr = "+d.arr);
	}
}