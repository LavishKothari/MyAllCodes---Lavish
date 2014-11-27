package pe70new;

public class pe70new 
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
	
	public static void main(String[] args) 
	{
		int max=10000000;
		//int primeArray[]=new int[] 
	}

}
