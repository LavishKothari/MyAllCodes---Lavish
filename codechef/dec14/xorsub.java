
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Main
{
	public static int calculateLength(int n) throws Exception
	{
		if(n<=0)
			return 1;
		else
			return (int)(Math.log(n)/Math.log(2))+1;
	}
	public static void main(String args[])
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());
			while(t-->0)
			{
				StringTokenizer stz=new StringTokenizer(br.readLine());
				int n=Integer.parseInt(stz.nextToken());
				int k=Integer.parseInt(stz.nextToken());
				int arr[]=new int[n];
				stz=new StringTokenizer(br.readLine());
				for(int i=0;i<n;i++)
					arr[i]=Integer.parseInt(stz.nextToken());
				LinkedList list[]=new LinkedList[11];
				for(int i=0;i<list.length;i++)
					list[i]=new LinkedList<Integer>();
				for(int i=0;i<n;i++)
					list[calculateLength(arr[i])].add(new Integer(arr[i]));
				// Gaussian Elimination
				LinkedList newList[]=new LinkedList[11];
				for(int i=0;i<newList.length;i++)
					newList[i]=new LinkedList<Integer>();
				for(int i=10;i>1;i--)
				{
					if(!(list[i].isEmpty()))
					{
						int xelement=(Integer)list[i].get(0);
						newList[i].add(new Integer(xelement));
						list[i].removeFirst();
						int element=((Integer)(newList[i].get(0))).intValue();
						while(!list[i].isEmpty())
						{
							int oldElement=((Integer)list[i].get(0)).intValue();
							list[i].removeFirst();
							int len=calculateLength(element^oldElement);
							if(len>0)
								list[len].add(new Integer(element^oldElement));
						}
					}
				}
				int x=k;
				if(!(list[1].isEmpty()))
					newList[1].add((Integer)(list[1].get(0)));
				for(int i=10;i>=1;i--)
				{
					//System.out.println("i="+i+" x="+x);
					if(!newList[i].isEmpty())
					{
						int element=((Integer)newList[i].get(0)).intValue();
						if((x^element) > x)
							x=(x^element);
					}
				}
				System.out.println(x);
			}
		}
		catch(Exception e)
		{

		}
	}
}
