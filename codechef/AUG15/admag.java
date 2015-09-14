import java.math.*;
import java.io.*;
class Main
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t-->0)
		{
			long n=Long.parseLong(br.readLine());
			if(n==1)
				System.out.print("1\n");
			else
			{
				BigInteger b=new BigInteger(""+n);
				Double d=(Math.log10(b.doubleValue()*Math.sqrt(5)+0.5)/Math.log10((1+Math.sqrt(5))/2)) - 1;
				System.out.println(d.intValue());
			}
			//printf("%d\n",(int)(log2(n)+1));
		}
	}
}
