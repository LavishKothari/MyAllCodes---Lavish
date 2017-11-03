import java.io.*;
import java.util.*;
class Main
{
	public static void main(String args[])
	{
		try
		{	
			String str;
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());
			for(int i=0;i<t;i++)
			{

				str=(br.readLine());
				StringTokenizer st=new StringTokenizer(str);
				int n=Integer.parseInt(""+st.nextElement());
				int c=Integer.parseInt(""+st.nextElement());
				int sum=0;

				str=(br.readLine());
				st=new StringTokenizer(str);
				for(int j=0;j<n;j++)
				{
					sum+=Integer.parseInt(""+st.nextElement());
				}
				if(sum>c)
					System.out.println("No");
				else
					System.out.println("Yes");
			}
		}
		catch(Exception e){}
	}
}

