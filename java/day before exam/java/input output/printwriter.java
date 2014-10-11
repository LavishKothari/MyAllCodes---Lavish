// illustration of write method of PrintStream class.
import java.io.*;
class Main
{
	public static void main(String []args)
	{
		try
		{
			PrintWriter pw=new PrintWriter(System.out,true);
			pw.println("hello lavish kothari how are you?/?//?");
			pw.println("hello rakshit kothari");
		}			
		catch(Exception e)
		{	

		}
	}
}