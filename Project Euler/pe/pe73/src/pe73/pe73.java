package pe73;
import java.util.LinkedList;

public class pe73 
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
		int num=12000;
		long answer=0;
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
			if(i%100==0)
				System.out.println(i/100);
			
			boolean coPrimeArray[]=(boolean[])(lst.get(i-1));
			for(int j=1;j<i;j++)
				if(coPrimeArray[j])
				{
					Fraction f=new Fraction(j,i);
					if(Fraction.compare(new Fraction(1,2),f)==1 && Fraction.compare(f, new Fraction(1,3))==1)
					{
						//System.out.println(f);
						answer++;
					}
				}
		}
		System.out.println("Answer = "+answer);
		System.out.println("Execution time = "+(System.currentTimeMillis()-start)/1000.0);
	}

}
