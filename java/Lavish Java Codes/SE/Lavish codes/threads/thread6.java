// illustration of Thread priority
// illustration of volatile keyword
// volatile is used to indicate that a variable's value will be modified by different threads.
class Alfa implements Runnable
{
	private volatile boolean running=true;
	int counter=0;
	public void run()
	{
		while(running)
			counter++;
	}
	public void stop()
	{
		running=false;
	}
}

class Beta implements Runnable	
{
	private volatile boolean running=true;
	int counter=0;
	public void run()
	{
		while(running)
			counter++;
	}
	public void stop()
	{
		running=false;
	}
}

class Main
{
	public static void main(String[]args)
	{	
		Alfa a=new Alfa();
		Beta b=new Beta();
		Thread t1=new Thread(a);
		Thread t2=new Thread(b);
		
		t1.setPriority(Thread.NORM_PRIORITY+3);
		t2.setPriority(Thread.NORM_PRIORITY-3);
		System.out.println(t1);
		System.out.println(t2);

		t1.start();	
		t2.start();
		System.out.println("Processing started");
		try
		{
			Thread.sleep(5000);
		}
		catch(InterruptedException e){}
		t1.stop();
		t2.stop();
		System.out.println("first thread counter   = "+a.counter);
		System.out.println("second thread counter  = "+b.counter);		
	}
}	