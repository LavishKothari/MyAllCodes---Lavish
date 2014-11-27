/*
 * first attempt of the correct answer
 * but the time taken is considerably high
 */
package pe69;

import java.util.LinkedList;
public class pe69 
{
	public static boolean isPrime(long n)
	{
		for(int i=2;i<=(int)Math.sqrt(n);i++)
		{
			if(n%i!=0)
				return false;
		}
		return true;
	}
	public static void main(String args[])
	{
		long start=System.currentTimeMillis();
		int n;
		long numerator,denominator;
		Fraction maxFraction=new Fraction(1,1);
		int maxi=0;
		LinkedList lst[]=new LinkedList[1000001];
		for(int i=0;i<lst.length;i++)
			lst[i]=new LinkedList();
		
		for(int i=2;i<1000001;i++)
		{
			if(isPrime(i))
			{
				lst[i].add(i);
			}
		}
		for(int i=1;i<=1000000;i++)
		{
			if(0==i%10000)
				System.out.println(i/10000);
			numerator=1;
			denominator=1;
			n=i;
			for(int j=2;n!=1;j++)
			{
				if(n%j==0)
				{
					numerator*=j;
					denominator*=(j-1);
					lst[i].add(j);
					
					while(n%j==0)
						n/=j;
				}
			}
			Fraction f=new Fraction(numerator,denominator);
			if(Fraction.compare(f,maxFraction)==1)
			{
				maxi=i;
				maxFraction=f;
				System.out.println(f);
			}
		}
		System.out.println("answer = "+maxi);
		System.out.println((System.currentTimeMillis()-start)/1000.0);
	}
}