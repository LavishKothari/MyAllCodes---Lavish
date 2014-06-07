//concat()

import java.io.*;
class Main
{
	public static void main(String[]args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String s1,s2;
			System.out.print("Enter first string  : ");
			s1=br.readLine();
			System.out.print("Enter second string : ");
			s2=br.readLine();
	
			String c=s1.concat(s2);
			
			System.out.println(c);
		}
		catch(Exception e)
		{
			System.out.println("Exception : "+e);
		}
	}
}
			