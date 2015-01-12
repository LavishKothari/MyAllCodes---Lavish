// basics of Thread
// Multi threaded programming
class Main
{
	public static void main(String args[])
	{
		Thread t=Thread.currentThread();
		System.out.println("current thread                         : "+t);
		t.setName("NewThread");
		System.out.println("current thread after changing the name : "+t);

		System.out.println("Name      : "+t.getName());
		System.out.println("priority  : "+t.getPriority());
		System.out.println("isAlive() : "+t.isAlive());		
		System.out.println();
		try
		{
			for(int i=0;i<10;i++)
			{
				System.out.println(i+" Hello Lavish Kothari");
				Thread.sleep(1000);
			}
		}
		catch(InterruptedException e)
		{
			System.out.println("Exception : "+e);
		}
	}
}