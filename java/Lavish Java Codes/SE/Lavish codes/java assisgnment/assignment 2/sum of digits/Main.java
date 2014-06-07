import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		int sum=0;
		System.out.print("enter a number : ");
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		while(n!=0)
		{
			sum+=n%10;
			n/=10;
		}
		System.out.println("sum = "+sum);
	}
}