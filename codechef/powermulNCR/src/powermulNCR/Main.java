package powermulNCR;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main 
{
	static int ishcfnm1;
	static int primeArray[]=new int[9592];
	
	static boolean isMPrime=false;
	public static boolean isPrime(int n)
	{
		for(int i=2;i<=Math.sqrt(n);i++)
			if(n%i==0)
				return false;
		return true;
	}
	
	static long modularMultiplicativeInverse(int n, int MOD)
	{
	    return pow(n,MOD-2,MOD);
	}
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
	static public void reduceArrayToPrimes(int arr[],int startingIndex)
	{
		int j;
		for(int i=startingIndex;i<arr.length;i++)
		{
			for(j=0;arr[i]!=0 && j<primeArray.length && arr[i]!=1;j++)
			{
				if(i==primeArray[j])
					break;
				int counter=0;
				while(arr[i]%primeArray[j]==0)
				{
					counter++;
					arr[i]/=primeArray[j];
				}
				arr[primeArray[j]]+=(counter*i);
			}
		}
	}
	static int hcf(int a,int b)
	{
		if(b==0)
			return a;
		return hcf(b,a%b);
	}
	public static int findAnswer(int n,int m,int r)
	{
		try
		{
			if(ishcfnm1==1)
			{
				// this case is true when n and m are coprime and m is a prime number.
				int f[]=new int[n+1];
				int mult[]=new int[n+1];
				f[0]=f[1]=mult[1]=mult[0]=1;
				for (int i=2;i<=n;i++)
				{
					f[i]=(int)((f[i-1]*(long)i)%m);
					mult[i]=(int)((mult[i-1]*(long)f[i])%m);
				}
				
				int answer1=1,answer2=1,answer3=1;
				answer1=(int)((pow(f[n],n,m)*modularMultiplicativeInverse(mult[n-1],m))%m);
				answer2=(int)((pow(f[r],r,m)*modularMultiplicativeInverse(mult[r-1],m))%m);
				answer3=(int)((pow(f[n-r],n-r,m)*modularMultiplicativeInverse(mult[n-r-1],m))%m);
				
				return (int)((((((answer1*modularMultiplicativeInverse(answer2, m))%m))%m)*modularMultiplicativeInverse(answer3, m))%m);
			}
			else
			{
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
				
				int ap[]=new int[n+1];
				int bp[]=new int[smallPartition];
				
				for(int i=0;i<smallPartition;i++)
					bp[i]=i;
				for(int i=partition;i<=n;i++)
					ap[i]=i;
				
				ap[1]=bp[1]=0;
				reduceArrayToPrimes(ap,partition);
				reduceArrayToPrimes(bp,2);
				
				long answer=1;
				ap[1]=bp[1]=0;
				
				for(int i=0;i<primeArray.length && n>=primeArray[i];i++)
				{
					int temp=primeArray[i];
					if(temp<smallPartition)
						ap[temp]-=bp[temp];
					
					answer=(answer*pow(temp,ap[temp],m))%m;
				}
				return (int)answer;
			}
		}
		catch(Exception e)
		{
			
		}
		return 0;
	}
	public static void main(String[] args)
	{
		try
		{
			int j=0;
			for(int i=2;i<=100000;i++)
				if(isPrime(i))
					primeArray[j++]=i;
			
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int test=Integer.parseInt(br.readLine());
			for(j=0;j<test;j++)
			{
				StringTokenizer stz=new StringTokenizer(br.readLine());
				int n=Integer.parseInt(stz.nextToken());
				int m=Integer.parseInt(stz.nextToken());
				int q=Integer.parseInt(stz.nextToken());
				ishcfnm1=hcf(n,m);
				for(int i=0;i<q;i++)
				{
					int r=Integer.parseInt(br.readLine());
					System.out.println(findAnswer(n,m,r));
				}
			}
		}
		catch(Exception e)
		{
			System.out.println("There is some exception");
			e.printStackTrace();
		}
	}
}
