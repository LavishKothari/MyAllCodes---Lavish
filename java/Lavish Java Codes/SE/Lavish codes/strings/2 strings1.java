//program shoing the implementation of compareTo() method of String class
//prototype --> int compareTo(String anotherString)
//Compares two strings lexicographically.
// it is a bit complicated
//study well about the value it returns
import java.io.*;
class Main
{
	public static void main(String[]args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			
			System.out.print("Enter first String  : ");
			String s1=br.readLine();
			System.out.print("Enter second String : ");
			String s2=br.readLine();
			System.out.println(s1.compareTo(s2));	
		}
		catch(Exception e)
		{
			System.out.println("Your Exception : "+e);
		}
		System.out.println("The program completed successfully...!");
	}
}