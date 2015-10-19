import java.io.*;
import java.util.*;

class Main
{
	public static void main(String arggs[])
	{	
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());
			
			for(int i=0;i<t;i++)
			{
				int answer=0;
				String str=br.readLine();
				StringTokenizer st=new StringTokenizer(str);
				
				int a=Integer.parseInt(""+st.nextElement());
				int b=Integer.parseInt(""+st.nextElement());
				int c=Integer.parseInt(""+st.nextElement());
				int d=Integer.parseInt(""+st.nextElement());
				
				
				str=br.readLine();
				st=new StringTokenizer(str);
				
				int p=Integer.parseInt(""+st.nextElement());
				int q=Integer.parseInt(""+st.nextElement());
				int r=Integer.parseInt(""+st.nextElement());
				int s=Integer.parseInt(""+st.nextElement());
				
				answer=(c-a)*(d-b)+(r-p)*(s-q);
				
				if(p>=a && p<=c && q<=d && q>=b)
					answer-=(c-p)*(d-q);
				if(r>=a && r<=c && q>=b && q<=d)
					answer-=(r-a)*(d-q);
				if(p>=a && a<=c && s>=b && s<=d)
					answer-=
				System.out.println(answer);
			}
		}
		catch(Exception e)
		{}
	}
}
				