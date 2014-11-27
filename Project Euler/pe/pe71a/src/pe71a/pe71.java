package pe71a;
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
		LinkedList lst=new LinkedList();
		for(int i=1;i<=num;i++)
		{
			if(i%100==0)
				System.out.println(i/100);
			
			boolean coPrimeArray[]=new boolean[i];
			lst.add(coPrimeArray);
			for(int j=1;j<i;j++)
				{
					if(Fraction.hcf(i, j)==1)
						coPrimeArray[j]=true;
				}
		}
		System.out.println("completed");
		
		/***********************/
		for(int i=1;i<=num;i++)
		{
			/*
			if(i%100==0)
				System.out.println(i/100);
			*/
			boolean coPrimeArray[]=(boolean[])(lst.get(i-1));
			for(int j=1;j<i;j++)
				if(coPrimeArray[j])
				{
					Fraction f=new Fraction(j,i);
					if(Fraction.compare(new Fraction(3,7),f)==1 && Fraction.compare(f, answerFraction)==1)
						answerFraction=f;
				}
		}
		System.out.println("Answer Fraction = "+answerFraction);
		System.out.println("Execution time = "+(System.currentTimeMillis()-start)/1000.0);
	}
}
