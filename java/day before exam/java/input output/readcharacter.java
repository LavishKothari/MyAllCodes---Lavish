// read a character from the console until it reads 'q'
import java.io.*;
class Main
{
	public static void main(String []args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));	
			while('q'!=(char)br.read());
		}
		catch(IOException e)
		{
			System.out.println("you got an exception : "+e);
		}
	}
}	