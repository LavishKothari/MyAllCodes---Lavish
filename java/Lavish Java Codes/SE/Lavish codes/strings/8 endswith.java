import java.io.*;

class Main
{
	public static void main(String []args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("Enter first string  : ");
			String s1=br.readLine();
			System.out.print("Enter second string : ");
			String s2=br.readLine();
			
			System.out.println(s1.endsWith(s2));
		}
		catch(Exception e)
		{
			System.out.println("Exception : "+e);
		}
	}
}