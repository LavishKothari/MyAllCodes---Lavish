//program to find factorial of the function using recursion
// here factorial is not an static function
import java.io.*;

class Main
{
	public static void main(String[]args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("Enter a number : ");
			int n=Integer.parseInt(br.readLine());
			long f=factorial(n);
			System.out.println("factorial of "+n+" = "+f);
		}
		catch(Exception e)
		{
			System.out.println("Exception : "+e);	
		}
	}	
	public long factorial(int n)
	{
		long f;
		if(n==1)
			return n;
		f=n*factorial(n-1);
		return f;
	}
}