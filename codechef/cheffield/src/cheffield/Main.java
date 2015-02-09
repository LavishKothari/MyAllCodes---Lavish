package cheffield;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args)
	{
		try
		{
			// TODO Auto-generated method stub
			boolean primes[]=new boolean[1000001];
			primes[0]=primes[1]=true;
			for(int i=2;i<=1000000;i++)
				if(!primes[i])
					for(int j=2*i;j<=1000000;j+=i)
						primes[j]=true;
			/*
			for(int i=0;i<100;i++)
				if(!primes[i]) // means i is prime
					System.out.println(i);
			*/
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());
			for(int i=0;i<t;i++)
			{
				StringTokenizer stz=new StringTokenizer(br.readLine());
				int l=Integer.parseInt(stz.nextToken());
				int b=Integer.parseInt(stz.nextToken());
				if(!primes[l])
					l--;
				if(!primes[b])
					b--;
				if(!primes[l])
					l--;
				if(!primes[b])
					b--;
				//System.out.println(l+" "+b);
				long area=(long)l*b;
				System.out.println(area);
			}
			
		}
		catch(Exception e)
		{
			
		}
	}

}
