package pe70;

public class pe90 
{	
	public static int isPermutation(int a,int b)
	{
	    int flaga[]=new int[10];
	    int flagb[]=new int[10];
	    int i;
	    for(i=0;i<10;i++)
	        flaga[i]=flagb[i]=0;
	    while(a!=0)
	    {
	        flaga[a%10]++;
	        a/=10;
	    }
	    while(b!=0)
	    {
	        flagb[b%10]++;
	        b/=10;
	    }
	    for(i=0;i<10;i++)
	        if(flaga[i]!=flagb[i])
	            return 0;
	    return 1;
	}
	public static int phi(int n)
	{
	    /*
	        this is the implementation of Euler's Totient function.
	    */
		boolean flag=false;
	    int cn,pro=1,i,ccn;
	    cn=n;
	    ccn=n;
	    for(i=2;i<=ccn/2;i++)
	    {
	        if(n%i==0)
	        {
	        	flag=true;
	        	pro=pro*(i-1);
	            cn/=i;
	        }
	        while(n%i==0)
	            n/=i;
	    }
	    if(cn!=n)
	    	pro*=cn;
	    else if(!flag)
	    	pro=cn-1;
	    return pro;
	}
	public static void main(String []args)
	{
		
		int i,n=0,phinteger,upperLimit=10000000;
	    double p,min=Double.MAX_VALUE,ph;
	    for(i=2;i<upperLimit;i++)
	    {
	        if(i%10000==0)
	            System.out.println(i);
	        phinteger=phi(i);
	        ph=(double)phinteger;
	        if(isPermutation(i,phinteger)==1)
	        {
	            p=n/ph;
	            if(Double.compare(min, p)>0)
	            {
	                min=p;
	                n=i;
	            }
	        }
	    }
	    System.out.println("answer = "+n);
		
	}
	
}
