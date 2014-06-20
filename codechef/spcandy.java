import java.io.*;
import java.util.*;
class Main
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer s=new StringTokenizer(br.readLine());
		int t=Integer.parseInt((String)s.nextElement());
		
		for(int i=0;i<t;i++)
		{
			StringTokenizer stz=new StringTokenizer(br.readLine());
			
			//a - candies
			//b - students
			
			long a=Long.parseLong((String)stz.nextElement());
			long b=Long.parseLong((String)stz.nextElement());
			
			if(b==0)
			{
				System.out.println("0 "+a);
				continue;
			}
			if(a==0)
			{
				System.out.println("0 0");
				continue;
			}
			System.out.println((a/b)+" "+(a%b));
		}
	}
}
