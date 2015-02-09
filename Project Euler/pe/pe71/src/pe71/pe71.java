package pe71;

import java.util.LinkedList;

public class pe71 
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
		int num=1000000;
		Fraction answerFraction=new Fraction(1,10000);
		System.out.println("started");
		
		/***********************/
		LinkedList lst[]=new LinkedList[num+1];
		for(int i=0;i<lst.length;i++)
			lst[i]=new LinkedList<String>();
		boolean primes[]=new boolean[num+1];
		for(int i=2;i<=num;i++)
			if(!primes[i])
				for(int j=i;j<=num;j+=i)
				{
					primes[j]=true;
					lst[j].add(""+i);
				}
		System.out.println("completed");
		
		/***********************/
		for(int i=1;i<=num;i++)
		{
			if(i%100==0)
				System.out.println(i/100);
			
			boolean coPrimeArray[]=new boolean[i];
			for(int j=0;j<lst[i].size();j++)
				if(!coPrimeArray[j])
					for(int k=Integer.parseInt(""+lst[i].get(j));k<i;k+=Integer.parseInt(""+lst[i].get(j)))
						coPrimeArray[k]=true;
			/*
			System.out.println("for i = "+i);
			for(int j=0;j<coPrimeArray.length;j++)
				System.out.print(j+""+coPrimeArray[j]+" ");
			System.out.println();
			*/
			/*
			 * if coprime[j] is false it means HCF(j,i)=1
			 */
			for(int j=1;j<i;j++)
				if(!coPrimeArray[j])
				{
					Fraction f=new Fraction(j,i);
					if(Fraction.compare(new Fraction(2,5),f)==1 && Fraction.compare(f, answerFraction)==1)
						answerFraction=f;
				}
		}
		System.out.println("Answer Fraction = "+answerFraction);
		System.out.println("Execution time = "+(System.currentTimeMillis()-start)/1000.0);
	}
}
