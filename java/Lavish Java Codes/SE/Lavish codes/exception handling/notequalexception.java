// user defined exception

// write a exception which is thrown when the value entered by the user is not equal to 3.14

import java.util.Scanner;

class NotEqualException extends Exception
{
	NotEqualException(String str)
	{
		super("Your exception : "+str);
	}	

}

class Main
{
	public static void main(String args[])
	{
		try
		{
			Scanner sc=new Scanner(System.in);
			System.out.print("enter a floating point number : ");		
			float f=sc.nextFloat();
			if(f != 3.14f)
				throw new NotEqualException("you entered a value that is not equal to 3.14 !!!!");
			else
				System.out.println("you entered a value that is equal to 3.14");
		}	
		catch(NotEqualException e)
		{
			System.out.println(e.getMessage());
		}
		System.out.println("program successful!!!");
	}
}