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
			StringTokenizer stz=new StringTokenizer(br.readLine());
			long a=Long.parseLong((String)stz.nextElement());
			long b=Long.parseLong((String)stz.nextElement());
			
			if(a%2==0 && b%2==0)
				System.out.println("A");
			else if(a%2!=0 && b%2!=0)
				System.out.println("B");
			else if((a%2==0 && b%2!=0)||(a%2!=0 && b%2==0))
				System.out.println("A");
		}
	}
}
