class Demo
{
	public int a;
	int b;
	private int c;
	
	private void fun1()
	{
		System.out.println("fun1() - private function");
	}
	
	public void fun2()
	{
		System.out.println("fun2() - public function");
		fun1();
	}
}

class Main
{
	public static void main(String []args)
	{
		Demo d=new Demo();
		//d.fun1(); // ERROR private functions are not accessible outside class.
		d.fun2();
	}
}