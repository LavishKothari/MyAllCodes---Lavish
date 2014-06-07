// creating a thread by implementing Runnable interface

class Alfa implements Runnable
{
	Alfa()
	{
		Thread t =new Thread(this);
		t.start();
	}
	public void run()
	{
		try
		{
	
			for(int i=0;i<20;i+=2)	
			{
				System.out.println("in first  thread : "+i);	
				Thread.sleep(100);
			}
			System.out.println("first thread exiting...");
		}
		catch(InterruptedException e)
		{
			System.out.println("Exception : "+e);
		}
			
	}

}

class Beta implements Runnable
{
	
	public void run()
	{
		try
		{
	
			for(int i=1;i<20;i+=2)	
			{
				System.out.println("in second thread : "+i);	
				Thread.sleep(1000);
			}
			System.out.println("second thread exiting...");
		}
		catch(InterruptedException e)
		{
			System.out.println("Exception : "+e);
		}
			
	}

}


class Main
{
	public static void main(String[]args)	
	{
		Alfa a=new Alfa();
		
		Beta b=new Beta();
		Thread t2=new Thread(b);
		t2.start();
		System.out.println("your main thread is exiting...");
	}
}