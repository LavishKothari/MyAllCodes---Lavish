class A
{
	int x,y;
	public void fun()
	{
		System.out.println("in base class A");
	}
}

class B extends A
{
	int p,q;
	public void test()
	{
		System.out.println("in derived class B");
	}
}

class C extends B
{
	int m,n;
	public void display()
	{
		System.out.println("in derived class C");
	}
}

class Main
{
	public static void main(String args[])
	{
		C obj=new C();
		obj.fun();
		obj.test();
		obj.display();
	}
}