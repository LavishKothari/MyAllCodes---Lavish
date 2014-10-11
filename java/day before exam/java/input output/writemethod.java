// illustration of write method of PrintStream class.
import java.io.*;
class Main
{
	public static void main(String []args)
	{
		try
		{
			System.out.write('a');

//			System.out.write('\n');
		}			
		catch(Exception e)
		{	
			System.out.println("you got an exception ; "+e);
		}
	}
}