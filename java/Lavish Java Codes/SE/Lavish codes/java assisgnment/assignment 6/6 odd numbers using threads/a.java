class th extends Thread
{
	public void run()
	{
		for(int i=1;i<100;i+=2)
			System.out.println(i);
	}
}

class Main
{
	public static void main(String []args)
	{
		th t1=new th();
		Thread t=new Thread(t1,"Demo threads");
		t.start();
	}
}