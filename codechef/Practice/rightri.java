import java.io.*;
import java.util.*;

class Main
{
	static int side1,side2,side3;

	public static void main(String args[])
	{
		int answer=0;
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

			int n=Integer.parseInt(br.readLine());

			for(int i=0;i<n;i++)
			{
				String str=br.readLine();
				StringTokenizer st=new StringTokenizer(str);

				int a=Integer.parseInt(""+st.nextElement());
				int b=Integer.parseInt(""+st.nextElement());
				int c=Integer.parseInt(""+st.nextElement());
				int d=Integer.parseInt(""+st.nextElement());
				int e=Integer.parseInt(""+st.nextElement());
				int f=Integer.parseInt(""+st.nextElement());

				calSides(a,b,c,d,e,f);
				//answer=0;
				if(side3==side1+side2)
					answer++;
				else if(side2==side1+side3)
					answer++;
				else if(side1==side3+side2)
					answer++;

			}
		}
		catch(Exception e)
		{}
		System.out.println(answer);
	}
	public static void calSides(int a,int b,int c,int d,int e,int f)
	{
		side1=((a-c)*(a-c)+(b-d)*(b-d));
		side2=((a-e)*(a-e)+(b-f)*(b-f));
		side3=((c-e)*(c-e)+(d-f)*(d-f));
	}
}
