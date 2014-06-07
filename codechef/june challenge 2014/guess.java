import java.io.*;
import java.util.*;
class Main
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		for(int i=0;i<t;i++)
		{
			StringTokenizer stz=new StringTokenizer(br.readLine());
			int a=Integer.parseInt((String)stz.nextElement());
			int b=Integer.parseInt((String)stz.nextElement());
			
			long numerator=numberOfOdd(a)*numberOfEven(b)+numberOfOdd(b)*numberOfEven(a);
			long denominator=(long)a*b;
	
			long HCF=numerator>denominator?hcf(numerator,denominator):hcf(denominator,numerator);
			String answer=(numerator/HCF)+"/"+(denominator/HCF);
			System.out.println(answer);		 
		}
	}
	public static long hcf(long a,long b)
	{
		if(b==0)
            return a;
        return hcf(b,a%b);
	}
	
	public static long numberOfOdd(int n)
	{
		if(n%2==0)
			return (n/2);
		return (n/2+1);
	}
	public static long numberOfEven(int n)
	{
		return (n-numberOfOdd(n));
	}
}
