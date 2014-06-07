import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int a,b;
		a=sc.nextInt();
		b=sc.nextInt();
		try
		{
			int div=a/b;
			System.out.println("div = "+div);
		}
		
		catch(Exception e)
		{
			System.out.println("divide by zero error...! \n"+e.getMessage());
		}
	}
}