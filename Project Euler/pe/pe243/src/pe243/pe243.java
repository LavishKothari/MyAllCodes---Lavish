package pe243;

import java.util.LinkedList;

public class pe243 
{
	public static void main(String[] args) 
	{
		long startTime=System.currentTimeMillis();
		int num=2000000;
		Fraction standardFraction=new Fraction(15499,94744);
		//Fraction standardFraction=new Fraction(4,10);
		boolean primes[]=new boolean[num+1];
		LinkedList mainArray[]=new LinkedList[num+1];
		for(int i=0;i<num;i++)
			mainArray[i]=new LinkedList();
		System.out.println("all linked list made");
		LinkedList ithElementOfMainArray;
		for(int i=2;i<num;i++)
		{
			//if(i%100==0)
				System.out.println(i);
			ithElementOfMainArray=(LinkedList)mainArray[i];
			if(!primes[i])
			{
				/* here the resilence of 'i' will always be 1
				 * because 'i' is prime here.
				 */
				ithElementOfMainArray.add(i+"");
				for(int j=i*2;j<num;j+=i)
				{
					primes[j]=true;
					((LinkedList)mainArray[j]).add(i+"");
					//System.out.println(i+ " is being added to "+j);
				}
			}
			else
			{
				int numerator=i;
				for(int j=0;j<ithElementOfMainArray.size();j++)
				{
					int temp=Integer.parseInt(ithElementOfMainArray.get(j)+"");
					numerator/=temp;
					numerator*=(temp-1);
				}
				//System.out.println("n/d = "+numerator+"/"+(i-1));
				Fraction f=new Fraction(numerator,i-1);
				//System.out.println(i+" -> "+f);
				if(Fraction.compare(f,standardFraction)==-1)
				{
					System.out.println(f);
					System.out.println("answer = "+i);
					break;
				}
			}
			mainArray[i]=null;
		}
		System.out.println("program finished");
		System.out.println("Execution Time : "+(System.currentTimeMillis()-startTime)/1000.0);
	}
}
