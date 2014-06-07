// custom exception handler

import java.util.Scanner;

class MyExcep extends Exception
{
	private String msg="My exception : ";

	MyExcep()
	{
		msg=msg+"Unknown Exception";
	}

	MyExcep(String s)
	{
		msg=msg+s;
	}

	public String toString()
	{
		return msg;
	}
}

class Main
	{
	public static void main(String args[])
	{
		int x,y;
		double res;
		Scanner sc=new Scanner(System.in);

		System.out.println("enter the numerator : ");
		x=sc.nextInt();
		System.out.println("enter the denominator : ");
		y=sc.nextInt();

		try
		{
			if(y==0)
				throw new ArithmeticException();
			if(y>x)
				throw new MyExcep("the denominator is greater than the numerator");
			res=x/y;
			System.out.println("operation successful : "+res);
		}
		catch (ArithmeticException e)
		{
			System.out.println(e);
			res=0;
		}
		catch (MyExcep e)
		{
			System.out.println(e);
			res=-1;
		}
		
		System.out.println("the result of operation : "+res);
	}
}