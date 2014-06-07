import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		System.out.print("enter a number : ");
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int rev=0;
		int cnum=n;
		while(n!=0)
		{
			rev=rev*10+n%10;
			n/=10;
		}
		if(cnum==rev)
			System.out.println("the number you entered is a palindrome number...");
		else
			System.out.println("the number you entered is not a palindrome number...");
	}
}