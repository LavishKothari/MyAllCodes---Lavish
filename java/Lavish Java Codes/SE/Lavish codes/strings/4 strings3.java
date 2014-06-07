//program showing the implementation of format() method of String class
//prototype --> static String 	format(Locale l, String format, Object... args)
//Returns a formatted string using the specified locale, format string, and arguments.

import java.io.*;
class Main
{
	public static void main(String[]args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("Enter first number  : ");	
			int a=Integer.parseInt(br.readLine());
			System.out.print("enter second number : ");
			int b=Integer.parseInt(br.readLine());
			
			String s;
			s=String.format("The first number you entered is : %d",a);
		
			s=s+String.format("\nThe second number you entered is : %d",b);
			System.out.println(s);	
		}
		catch(Exception e)
		{
			System.out.println("Your Exception : "+e);
		}
		System.out.println("The program completed successfully...!");
	}
}