/*
 * second attempt for the correct answer
 * The Execution time got down to around 18 seconds
 */
package pe69b;
import java.util.LinkedList;
public class pe69 
{
	public static boolean isPrime(long n)
	{
		for(int i=2;i<=(int)Math.sqrt(n);i++)
			if(n%i==0)
				return false;
		return true;
	}
	public static void main(String args[])
	{
		int num=1000000;
		long start=System.currentTimeMillis();
		long numerator,denominator;
		Fraction maxFraction=new Fraction(1,1);
		int maxi=0;
		LinkedList lst[]=new LinkedList[num+1];
		for(int i=0;i<lst.length;i++)
			lst[i]=new LinkedList<String>();
		System.out.println("started");
		for(int i=2;i<=num;i++)
			if(isPrime(i))
				for(int j=i;j<=num;j+=i)
					lst[j].add(i+"");
		System.out.println("completed");
		System.out.println("Execution time = "+((System.currentTimeMillis()-start)/1000.0));
		
		for(int i=1;i<=num;i++)
		{
			numerator=1;
			denominator=1;
			for(int j=0;j<lst[i].size();j++)
			{
				int temp=Integer.parseInt(lst[i].get(j)+"");
				numerator*=temp;
				denominator*=(temp-1);	
			}
			
			Fraction f=new Fraction(numerator,denominator);
			if(Fraction.compare(f,maxFraction)==1)
			{
				maxi=i;
				maxFraction=f;
			}
		}
		System.out.println("Answer = "+maxi);
		System.out.println("Execution time = "+((System.currentTimeMillis()-start)/1000.0));
	}
}