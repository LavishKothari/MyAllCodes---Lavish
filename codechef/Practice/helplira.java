import java.util.*;
import java.io.*;

class Main
{
	public static void main(String args[])
	{	
		double max=0,min=0;
		int minIndex=0,maxIndex=0;
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());

			for(int i=0;i<t;i++)
			{
				String str=br.readLine();
				StringTokenizer st=new StringTokenizer(str);

				int a=Integer.parseInt(""+st.nextElement());
				int b=Integer.parseInt(""+st.nextElement());
				int c=Integer.parseInt(""+st.nextElement());
				int d=Integer.parseInt(""+st.nextElement());
				int e=Integer.parseInt(""+st.nextElement());
				int f=Integer.parseInt(""+st.nextElement());
				double area=calArea(a,b,c,d,e,f);
				if(i==0)
				{
					maxIndex=minIndex=i+1;
					max=min=area;
				}
				else
				{
					if(area>=max)
					{
						maxIndex=i+1;
						max=area;
					}
					if(area<=min)
					{
						min=area;
						minIndex=i+1;
					}
				}
			}
			System.out.println(minIndex+" "+maxIndex);
		}
		catch(Exception e){}
	}
	public static double calArea(int a,int b,int c,int d, int e, int f)
	{
		double side1,side2,side3;
		side1=Math.sqrt((a-c)*(a-c)+(b-d)*(b-d));
		side2=Math.sqrt((a-e)*(a-e)+(b-f)*(b-f));
		side3=Math.sqrt((c-e)*(c-e)+(d-f)*(d-f));

		double semiPerimeter=(side1+side2+side3)/2;

		return Math.sqrt((semiPerimeter-side1)*(semiPerimeter-side2)*(semiPerimeter-side3)*semiPerimeter);
	}
}
