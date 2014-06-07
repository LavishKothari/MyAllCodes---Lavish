import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		System.out.print("enter a number : ");
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int pro=1;
		for(int i=2;i<=n;i++)
			pro*=i;
		System.out.println("Factorial = "+pro);
	}
}