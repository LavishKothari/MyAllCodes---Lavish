class NewThread extends Thread
{
	NewThread()
	{
		super("Demo Thread");
		System.out.println("child thread "+this);
		start();
	}

	public void run()
	{
		try
		{
			for(int i=0;i<5;i++)
			{
				System.out.println("child thread "+i);
				Thread.sleep(500);
			}
		}
		catch(InterruptedException e)
		{
			System.out.println("Child thread Interrupted");
		}
		System.out.println("exiting child thread");
	}
}

class Main
{
	public static void main(String args[])
	{
		new NewThread ();
		try
		{
			for(int i=0;i<5;i++)
			{
				System.out.println("main thread "+i);
				Thread.sleep(1000);
			}
		}
		catch(InterruptedException e)
		{
			System.out.println("Main thread Interrupted");
		}
		System.out.println("Main thread exiting");
	}
}