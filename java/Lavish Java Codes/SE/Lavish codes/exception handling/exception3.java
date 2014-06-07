//user defined exception
import java.util.Scanner;
class MyException extends Exception
{
	private String msg="";
	MyException()
	{
		msg="Unknown Exception";
	}
	MyException(String s)
	{		
		msg=msg+s;
	}
	public String toString()
	{
		return msg;
	}
}

class Main
{	
	public static void main(String args[])
	{
		try
		{
			Scanner s=new Scanner(System.in);
			int i=s.nextInt();
			if(i>10)
				throw new MyException();
		}
		catch(MyException e)
		{
			System.out.println("your Exception : "+e);
		}
	}
}	