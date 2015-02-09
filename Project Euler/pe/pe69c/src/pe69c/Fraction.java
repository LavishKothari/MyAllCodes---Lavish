package pe69c;

public class Fraction 
{
	public long n,d;
	public Fraction(long n,long d)
	{
		this.n=n;
		this.d=d;
		simplifyFraction();
	}
	
	public void simplifyFraction()
	{
		long h=hcf(Math.abs(n),Math.abs(d));
		n/=h;
		d/=h;
		if(d<0 && n<0)
		{
			d=-d;
			n=-n;
		}
	}
	
	public static long hcf(long a,long b)
	{
		if(b==0)
			return a;
		return hcf(b,a%b);
	}
	
	public static long lcm(long a,long b)
	{
		return (a*b)/hcf(a,b);
	}
	
	public boolean equals(Fraction f)
	{
		if((this.n==f.n && f.n==0) || (this.n==f.n && this.d==f.d))
			return true;
		return false;
	}
	
	public static int compare(Fraction a,Fraction b)
	{
		long l=lcm(a.d,b.d);
		
		if((l/a.d * a.n) > (l/b.d * b.n))
			return 1;
		else if((l/a.d * a.n) == (l/b.d * b.n))
			return 0;
		else
			return -1;
	}
	public String toString()
	{
		return this.n+"/"+this.d;
	}
}
