// thread basics

class Main
{
	public static void main(String args[])
	{
		Thread t=Thread.currentThread();
		System.out.println(t);

		System.out.println("thread name       : "+t.getName());
		System.out.println("thread priority   : "+t.getPriority());
		System.out.println("thread Group      : "+t.getThreadGroup());
	}
}