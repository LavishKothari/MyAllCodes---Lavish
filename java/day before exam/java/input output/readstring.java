//read the line from console until you receive stop.
import java.io.*;

class Main
{
	public static void main(String[]args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String str;
			do
			{
				str=br.readLine();
				System.out.println(str);
			}while(!str.equals("stop"));			

		}
		catch(IOException e)
		{
			System.out.println("you got an exception : "+e);
		}
	}
}