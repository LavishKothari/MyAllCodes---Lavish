import java.util.*;
import java.io.*;
class Main
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		for(int i=0;i<t;i++)
		{
			long answer=0;
			StringTokenizer stz=new StringTokenizer(br.readLine());
		
			int N=Integer.parseInt((String)stz.nextElement());
			int A=Integer.parseInt((String)stz.nextElement());
			int B=Integer.parseInt((String)stz.nextElement());
			int C=Integer.parseInt((String)stz.nextElement());
		
			for(int a=0;a<=N;a++)
			{
				for(int b=0;a+b<=N;b++)
				{
					int temp=N-(a+b);
					if(temp>C)
						answer+=C+1;
					else
						answer+=temp+1;
				}
			}
			System.out.println(answer);
		}
	}
}
