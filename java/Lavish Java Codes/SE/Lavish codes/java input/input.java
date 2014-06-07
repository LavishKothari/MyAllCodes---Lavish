/*
simple program in java illustrating input output operation in java 
using BufferedReader class
*/
import java.io.*;
class Main
{
	public static void main(String []args)
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		try
		{
			int n=Integer.parseInt(br.readLine());
			n++;
			System.out.println("n+1 = "+n);
		}
		catch(IOException e)
		{
			System.out.println(e.getMessage());
		}
		catch(NumberFormatException ne)
		{
			System.out.println("not a valid number...enter a vlid number ! "+ne.getMessage());	
		}
		System.out.println("hello Lavish Kothari");
	}
}