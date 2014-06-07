import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		System.out.print("enter a number : ");
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a=0,b=1,c;
		System.out.print("0\t1\t");
		for(int i=0;i<n-2;i++)
		{
			c=a+b;
			System.out.print(c+"\t");
			a=b;
			b=c;
		}
	}
}
			