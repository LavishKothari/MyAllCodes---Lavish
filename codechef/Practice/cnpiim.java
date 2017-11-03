class Main
{
	public static void main(String args[])
	{	
		int pro;
		try
		{
			java.io.BufferedReader br=new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());
			long answer;
			int j;
			for(int i=0;i<t;i++)
			{
				answer=0;
				int n=Integer.parseInt(br.readLine());
				for(j=1;j<=n/2;j++)
				{
					pro=(n-j)*j;

					if(j!=n/2.0)
						answer=answer+2*fun(pro,max(n-j,j));
					else
						answer+=fun(pro,max(n-j,j));
				}

				System.out.println(answer);

			}	
		}
		catch(Exception e){}

	}
	public static int max(int a,int b)
	{	
		if(a>b)
			return a;
		return b;
	}
	public static int fun(int n,int maxx)
	{
		if(maxx<Math.sqrt(n))
			return 0;
		int answer=0;
		for(int i=1;i<Math.sqrt(n);i++)
			if(n%i==0)
				answer=answer+n/i-i-1;
			else
				answer=answer+n/i-i;
		answer*=2;

		if((int)Math.sqrt(n)*(int)Math.sqrt(n)==n)
		{
			answer+=Math.sqrt(n)-1;
		}
		else 
			answer+=Math.sqrt(n);

		return answer;
	}
}
