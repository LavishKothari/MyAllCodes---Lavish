import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class Solution 
{
	public static void main(String []args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int n=Integer.parseInt(br.readLine());
			LinkedList<Integer> list[]=new LinkedList[n];
			for(int i=0;i<n;i++)
				list[i]=new LinkedList<Integer>();
			for(int i=0;i<n;i++)
			{
				StringTokenizer stz=new StringTokenizer(br.readLine());
				int k=Integer.parseInt(stz.nextToken());
				while(stz.hasMoreElements())
				{
					list[i].add(new Integer(Integer.parseInt(stz.nextToken())));
				}
			}
			
			LinkedList<Integer> answerList=new LinkedList<Integer>();
			//for(int i=0;i<max;i++)
			int i=0;
			
			//for(int z=0;z<max;z++)
			outer:while(true)
			{
				int min=Integer.MAX_VALUE;
				int minj=0,mini=0,flag=0;
				for(int j=0;j<n;j++)
				{
					if(i<list[j].size())
					{
						flag=1;
						if(min>list[j].get(i).intValue())
						{
							min=list[j].get(i).intValue();
							minj=j;
							mini=i;
						}
					}
				}
				if(flag==0)
					break outer;
				// delete ith element from the jth list.
				// and insert this element in the answerlist
				answerList.add(list[minj].get(mini));
				int newElement=list[minj].get(mini).intValue();
				list[minj].remove(list[minj].get(mini));
				for(int j=0;j<n;j++)
				{
					// deleting all the occurrences of newly inserted node in answerList i.e.. newElement.
					for(int z=0;z<list[j].size();z++)
					{
						if(list[j].get(z).intValue()==newElement)
							list[j].remove(z);
					}
				}
			}
			for(i=0;i<answerList.size();i++)
				System.out.print(answerList.get(i)+" ");
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
