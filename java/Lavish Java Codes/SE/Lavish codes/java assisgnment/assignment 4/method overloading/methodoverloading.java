class Demo
{
	int a,b;
	public void fun()
	{
		System.out.println("in function with no arguments");
	}
	public void fun(int a)
	{
		System.out.println("in function with one arguments");
	}
	public void fun(int a,int b)
	{
		System.out.println("in function with two arguments");
	}
}

class Main
{
	public static void main(String args[])
	{
		Demo d=new Demo();
		d.fun();
		d.fun(1);
		d.fun(1,2);
	}
}