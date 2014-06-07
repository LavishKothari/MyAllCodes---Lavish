#include<stdio.h>
#include<conio.h>
#include<time.h>
long lcm(long, long );

void main()
{
	long upperlimit=20;
	long ans=1;
	long i;
	for(i=1;i<=upperlimit;i++)
	{
		ans=lcm(i,ans);
	}

	printf("%ld\n",ans);
	printf("EXECUTION TIME = %f",clock()/(float)CLK_TCK);
	system("pause");
}


long lcm(long a, long b)
{
	long min,max,i;
	min=(a>b)?b:a;
	max=(a<b)?b:a;
		
	for(i=max;i<=min*max;i++)
	{
		if(i%max==0&&i%min==0)
			return i;

	}
}