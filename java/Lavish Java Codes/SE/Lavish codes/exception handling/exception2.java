//mannual exception generation and mannual handling

import java.util.Scanner;

class Main
{
	public static void main(String []args)	
	{
		Scanner sc=new Scanner(System.in);
		int i=sc.nextInt();
		int j=sc.nextInt();
		try
		{

			if(i>j)
				throw new ArrayIndexOutOfBoundsException();
			if(j>i)	
				throw new ArithmeticException();				
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println(e);
		}
		catch(ArithmeticException e)
		{
			System.out.println(e);
		}
	}
}