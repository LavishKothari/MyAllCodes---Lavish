package powermul;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main 
{
	public static int hcf(int a,int b)
	{
		if(b==0)
			return a;
		return hcf(b,a%b);
	}
	static public boolean isNonZeroPresentInbp(int bp[])
	{
		for(int i=0;i<bp.length;i++)
			if(bp[i]!=0)
				return true;
		return false;
	}
	static public int findAnswer(int n,int m,int r)
	{
		int ap[]=new int[n+1];
		int bp[]=new int[n+1];
		int partition,smallPartition;
		if(r>n-r)
		{
			smallPartition=n-r+1;
			partition=r+1;
		}
		else 
		{
			smallPartition=r+1;
			partition=n-r+1;
		}

		for(int i=0;i<=n;i++)
		{
			if(i<smallPartition)
				bp[i]=i;
			else
				bp[i]=0;
			if(i<partition)
				ap[i]=0;
			else
				ap[i]=i;
		}
		ap[1]=bp[1]=0;
		while(isNonZeroPresentInbp(bp))
		{
			for(int i=1;i<=n;i++)
			{
				while(bp[i]!=0)
				{
					for(int j=1;j<=n;j++)
					{
						if(ap[j]!=0)
						{
							int h=hcf(j,i);
							if(h!=1)
							{
								if(bp[i]<ap[j])
								{
									ap[j/h]+=bp[i];
									bp[i/h]+=bp[i];
									ap[j]-=bp[i];
									bp[i]=0;
								}
								else
								{
									ap[j/h]+=ap[j];
									bp[i/h]+=ap[j];
									bp[i]-=ap[j];
									ap[j]=0;
								}
							}
						}
					}
					ap[1]=bp[1]=0;
				}
			}
		}

		int answer=1;
		ap[1]=bp[1]=0;
		for(int i=1;i<=n;i++)
		{
			while(ap[i]!=0)
			{
				answer=(answer*i)%m;
				ap[i]--;
			}
		}
		return answer;
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int test=Integer.parseInt(br.readLine());
		for(int j=0;j<test;j++)
		{
			StringTokenizer stz=new StringTokenizer(br.readLine());
			int n=Integer.parseInt(stz.nextToken());
			int m=Integer.parseInt(stz.nextToken());
			int q=Integer.parseInt(stz.nextToken());
			for(int i=0;i<q;i++)
			{
				int r=Integer.parseInt(br.readLine());
				System.out.println(findAnswer(n,m,r));
			}
		}
	}
}
