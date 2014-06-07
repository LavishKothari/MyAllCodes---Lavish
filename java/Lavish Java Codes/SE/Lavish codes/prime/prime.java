class Main
{
	public static void main(String argss[])
	{
		for(int i=100;i<200;i++)
			if(isPrime(i))
				System.out.println(i);
	}
	public static boolean isPrime(int n)
	{
		for(int i=2;i<Math.sqrt(n);i++)
			if(n%i==0)	
				return false;
		return true;
	}
}