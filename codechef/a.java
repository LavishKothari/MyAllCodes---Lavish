import java.io.*;

class Main
{
	public static void main(String args[])
	{	
		int pro;
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());
			for(int i=0;i<t;i++)
			{
				long answer=0;
				int n=Integer.parseInt(br.readLine());
				for(int j=1;j<n;j++)
				{
					pro=(n-j)*j;
					answer+=fun(pro);
				}
				System.out.println(answer);
						
			}	
		}
		catch(Exception e){}
	}
	public static int fun(int n)
	{
		int answer=0;
		for(int i=1;i<n;i++)
			for(int j=1;j<n;j++)
				if(i*j<n)
					answer+=1;
		return answer;
	}
}