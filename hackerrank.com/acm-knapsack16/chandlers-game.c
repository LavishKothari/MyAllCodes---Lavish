#include<stdio.h>
#include<math.h>
int main()
{
	int t,counter,b,cb,i,x;
	double sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&b);
		counter=1;
		sum=0.0;
		cb=b/2;
		x=(int)log2(b);
		for(i=0;i<x;i++)
		{
			sum+=(double)b/(1<<(1+counter));
			cb=cb/(1<<counter);
			counter++;
		}
		printf("%g\n",sum);
	}
	return 0;	
}
