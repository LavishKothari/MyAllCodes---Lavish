import java.util.Scanner;
//import java.util.Math;
class Main
{
	public static void main(String args[])
	{
		System.out.print("enter a number : ");
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int num=n;
		int counter=0;
		while(n!=0)
		{
			counter++;
			n/=10;
		}
		int sum=0;
		n=num;
		while(n!=0)
		{
			sum+=(int)Math.pow(n%10,counter);		
			n/=10;
		}
		if(num==sum)
			System.out.println("the number you entered is an armstrong number...");
		else
			System.out.println("the number you entered is not an armstrong number...");
	}
}