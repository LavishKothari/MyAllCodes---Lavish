import java.io.*;
class Main
{
	public static void main(String[]args)
	{
		try
		{
		
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter first string  : ");
			String s=br.readLine();
			
			int n=Integer.parseInt(br.readLine());
			System.out.println(s.substring(n));
		}
		catch(Exception e)	
		{
			System.out.println("Exception : "+e);
		}
	}
}
			