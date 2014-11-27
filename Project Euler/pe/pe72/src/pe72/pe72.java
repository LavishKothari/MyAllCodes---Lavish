package pe72;
import java.util.LinkedList;
public class pe72 
{
	public static void main(String args[])
	{
		long start=System.currentTimeMillis();
		int num=1000000; 
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
		long answer=0;
		for(int i=2;i<=num;i++)
		{
			long temp=i;
			for(int j=0;j<lst[i].size();j++)
			{
				int t=Integer.parseInt(lst[i].get(j)+"");
				temp=(temp*(t-1))/t;
			}
			answer+=temp;
		}
		System.out.println("Answer = "+answer);
		System.out.println("Execution time = "+(System.currentTimeMillis()-start)/1000.0);
	}
}
