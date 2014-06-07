// program illustraing stop() method in Multi-threading

class Alfa implements Runnable
{
	public void run()
	{
		try
		{
			for(int i=0;i<10;i++)
			{
				if(i==5)
					Thread.currentThread().stop();
				System.out.println("1 --> "+i+"--> Hello Lavish Kothari");
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
			for(int i=0;i<10;i++)
			{
				System.out.println("2 --> "+i+"--> Hello Rakshit Kothari");
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
		{

			Alfa a=new Alfa();
			Beta b=new Beta();
			Thread t1=new Thread(a);
			Thread t2=new Thread(b);
			t1.start();
			t2.start();
		
						

			System.out.println("0 --> Main Thread exiting");
		}
	}
}