class Demo
{
	int a,b;
	int arr[];
	
	Demo(int a,int b)
	{
		System.out.println("Parametrized constructor called...");
		this.a=a;
		this.b=this.a*b;
		arr=null;
	}
}

class Main
{
	public static void main(String args[])
	{
		Demo d=new Demo(2,3);
		System.out.println("d.a = "+d.a+"   d.b = "+d.b+"  arr = "+d.arr);
	}
}