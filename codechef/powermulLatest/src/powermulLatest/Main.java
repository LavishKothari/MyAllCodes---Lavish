package powermulLatest;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main 
{
	static int primeArray[]=new int[9592];
	/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
	static long modularMultiplicativeInverse(int n, int MOD)
	{
	    return pow(n,MOD-2,MOD);
	}

	/* This function calculates (a^b)%MOD */
	/*
	static long pow(int a, int b, int MOD)
	{
		
		long x=1,y=a; 
	    while(b>0)
	    {
	        if(b%2==1)
	        {
	            x=(x*y);
	            if(x>MOD)
	            	x%=MOD;
	        }
	        y=(y*y);
	        if(y>MOD) 
	        	y%=MOD; 
	        b/=2;
	    }
	    return x;
	}
	*/
	static long pow(int base, int exp, int modulus) 
	{
		base %= modulus;
		long result = 1;
		while (exp > 0) 
		{
			if ((exp & 1) !=0) 
				result = (result * base) % modulus;
			base = (int)((base * (long)base) % modulus);
		    exp >>= 1;
		}
		return result;
	}
	
	static public long findAnswer(int n,int m,int r) 
	{
		int f[]=new int[n+1];
		f[0]=f[1]=1;
		int partition,smallPartition;
		if(r>n-r)
		{
			smallPartition=n-r+1;
			partition=r+1;
		}
		else 
		{
			smallPartition=r+1;
			partition=n-r+1;
		}
		f[partition]=(int)pow(partition,partition,m);
		for (int i=partition+1;i<=n;i++)
	        f[i]=(int)((f[i-1]*pow(i,i,m))%m);
		for(int i=2;i<smallPartition;i++)
			f[i]=(int)((f[i-1]*pow(i,i,m))%m);
		return (f[n]*modularMultiplicativeInverse(f[smallPartition-1], m))%m;
	}
	
	public static void main(String[] args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int test=Integer.parseInt(br.readLine());
			for(int j=0;j<test;j++)
			{
				StringTokenizer stz=new StringTokenizer(br.readLine());
				int n=Integer.parseInt(stz.nextToken());
				int m=Integer.parseInt(stz.nextToken());
				int q=Integer.parseInt(stz.nextToken());
				for(int i=0;i<q;i++)
				{
					int r=Integer.parseInt(br.readLine());
					System.out.println(findAnswer(n,m,r));
				}
			}
		}
		catch(Exception e)
		{
			
		}
	}
}
