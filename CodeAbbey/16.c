#include<stdio.h>
int main()
{
	int t,counter,sum,n;
	float avg;
	scanf("%d",&t);
	while(t--)
	{
		counter=0;
		sum=0;
		scanf("%d",&n);
		while(n)
		{
			sum+=n;
			scanf("%d",&n);
			counter++;
		}
		avg=sum/(float)counter;
		if((avg-(int)avg)*10<5)
			avg=(int)avg;
		else
			avg=(int)avg+1;
		printf("%g ",avg);
	}
	return 0;
}
