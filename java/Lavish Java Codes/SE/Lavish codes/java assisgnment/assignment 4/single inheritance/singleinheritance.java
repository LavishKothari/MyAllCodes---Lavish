class A
{
	int x,y;
	public void fun()
	{
		System.out.println("in base class");
	}
}

class B extends A
{
	int p,q;
	public void test()
	{
		System.out.println("in derived class");
	}
}

class Main
{
	public static void main(String args[])
	{
		B obj=new B();
		obj.fun();
		obj.test();
	}
}