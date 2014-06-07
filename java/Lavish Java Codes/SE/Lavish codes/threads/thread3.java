// creating a thread by extending the Thread class.
class Alfa extends Thread
{
	public void run()
	{
		try
		{
			for(int i=0;i<10;i++)
			{
				System.out.println(i+" Hello Lavish Kothari");
				Thread.sleep(100);
			}
			System.out.println("exiting thread in alfa class");
		}
		catch(InterruptedException e)
		{
			System.out.println("Exception : "+e);
		}
	}	
}

class Main
{
	public static void main(String args[])
	{
		Alfa a=new Alfa();
		Thread t=new Thread(a);
		t.start();
		System.out.println("Main thread is exiting...");
	}
}

