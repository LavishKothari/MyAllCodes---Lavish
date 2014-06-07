// program shoing the implementation of charAt() method of String class
// prototype --> char charAt(int index)
// Returns the char value at the specified index.

import java.util.Scanner;
import java.io.*;
class Main
{
	public static void main(String[]args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			
			System.out.print("Enter the String : ");
			String s=br.readLine();
			System.out.print("Enter the position : ");
			int n=Integer.parseInt(br.readLine());
			System.out.println("Character at "+n+" = "+s.charAt(n));	
		}
		catch(Exception e)
		{
			System.out.println("Your Exception : "+e);
		}
		System.out.println("The program completed successfully...!");
	}
}