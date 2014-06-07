class Demo
{
	int a,b;
	Demo(int a,int b)
	{
		this.a=a;
		this.b=b;
	}
}

class Main
{
 	public static void main(String args[])
	{
		Demo d=new Demo(4,3);
		System.out.println("d.a = "+d.a+"   d.b = "+d.b);
	}
}