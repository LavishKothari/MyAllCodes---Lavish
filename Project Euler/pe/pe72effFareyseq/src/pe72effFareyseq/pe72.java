package pe72effFareyseq;

import java.util.LinkedList;

public class pe72 
{
	static LinkedList lst[];
	public static long calculatePhi(int n)
	{
		long answer=n;
		for(int i=0;i<lst[n].size();i++)
		{
			int temp=Integer.parseInt(lst[n].get(i)+"");
			answer*=(temp-1);
			answer/=temp;
		}
		return answer;
	}
	public static void main(String[] args) 
	{
		long startTime=System.currentTimeMillis();
		int num=1000000; 
		
		lst=new LinkedList[num+1];
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
		long answer=0;
		for(int i=2;i<=num;i++)
			answer=answer+calculatePhi(i);
		System.out.println("answer is : "+answer);
		System.out.println("Execution time = "+(System.currentTimeMillis()-startTime)/1000.0);
		
	}

}
