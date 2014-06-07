// program illustraing join() method in Multi-threading

class Alfa implements Runnable
{
	public void run()
	{
		try
		{
			for(int i=0;i<5;i++)
			{
				System.out.println("1 --> Hello Lavish Kothari");
				Thread.sleep(100);
			}
		}
		catch(InterruptedException e){}
		System.out.println("first thread exiting");	
	}	
}

class Beta implements Runnable
{
	public void run()
	{
		try
		{
			for(int i=0;i<5;i++)
			{
				System.out.println("2 --> Hello Rakshit Kothari");
				Thread.sleep(100);
			}
		}
		catch(InterruptedException e){}
		System.out.println("second thread exiting");	
	}
}

class Main
{
	public static void main(String []args)
	{
		try
		{

			Alfa a=new Alfa();
			Beta b=new Beta();
			Thread t1=new Thread(a);
			Thread t2=new Thread(b);
			t1.start();
			t2.start();
			t1.join();	
			t2.join();
			System.out.println("0 --> Main Thread exiting");
		}
		catch(InterruptedException e){}
	}
}