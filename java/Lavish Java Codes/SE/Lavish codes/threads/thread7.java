// illustration of a synchronized mehtod.

class CallMe
{	
	String msg;
	synchronized public void call(String msg)
	{
		try
		{
			System.out.print("["+msg);
			Thread.sleep(1000);
			System.out.println("]");	
		}
		catch(InterruptedException e){}	
	}
}

class Caller implements Runnable
{	
	Thread t;
	String msg;
	CallMe obj;
	Caller(CallMe obj,String msg)
	{	
		this.msg=msg;
		this.obj=obj;
		t=new Thread(this);
		t.start();
	}
	public void run()
	{
		obj.call(msg);
	}	
}


class Main
{
	public static void main(String args[])
	{
		CallMe o=new CallMe();
		Caller o1=new Caller(o,"Hello");
		Caller o2=new Caller(o,"Lavish");
		Caller o3=new Caller(o,"Kothari");
	}	
}