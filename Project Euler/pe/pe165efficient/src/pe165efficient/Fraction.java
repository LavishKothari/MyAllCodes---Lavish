package pe165efficient;
public class Fraction 
{
	public long n,d;
	double value;
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
		if(d<0)
		{
			d=-d;
			n=-n;
		}
		value=(double)n/(double)d;
	}
	
	public long hcf(long a,long b)
	{
		if(b==0)
			return a;
		return hcf(b,a%b);
	}
	
	public boolean equals(Fraction f)
	{
		if((this.n==f.n && f.n==0) || (this.n==f.n && this.d==f.d))
			return true;
		return false;
	}
}

