package pe70original;

import java.util.LinkedList;

public class pe70 
{
	static LinkedList lst[];
	public static void main(String args[])
	{
		int num=10000000;
		long start=System.currentTimeMillis();
		long numerator,denominator;
		Fraction minFraction=new Fraction(-1,1);
		int mini=0;
		lst=new LinkedList[num+1];
		for(int i=0;i<lst.length;i++)
			lst[i]=new LinkedList<String>();
		System.out.println("started");
		boolean primes[]=new boolean[num+1];
		for(int i=2;i<=num;i++)
			if(!primes[i])
				for(int j=i;j<=num;j+=i)
				{
					primes[j]=true;
					lst[j].add(i+"");
				}
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
			int phiValue=phi(i);
			if(isPermutation(i,phiValue)/* && Fraction.compare(f,minFraction)==-1*/)
			{
				//System.out.println(i+" -> "+phiValue+" ## "+f);
				mini=i;
				minFraction=f;
			}
		}
		System.out.println("Answer = "+mini);
		System.out.println("Execution time = "+((System.currentTimeMillis()-start)/1000.0));
	}
	public static boolean isPermutation(int a,int b)
	{
		int flaga[]=new int[10];
		int flagb[]=new int[10];
		for(int i=0;i<10;i++)
			flaga[i]=flagb[i]=0;
		while(a!=0)
		{
			flaga[a%10]++;
			a/=10;
		}
		while(b!=0)
		{
			flagb[b%10]++;
			b/=10;
		}
		
		for(int i=0;i<10;i++)
			if(flaga[i]!=flagb[i])
				return false;
		return true;
	}
	public static int phi(int n)
	{
		int phivalue=n;
		for(int i=0;i<lst[n].size();i++)
		{
			int temp=Integer.parseInt(lst[n].get(i)+"");
			phivalue/=temp;
			phivalue*=(temp-1);
		}
		return phivalue;
	}
}
