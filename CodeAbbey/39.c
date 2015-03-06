#include<stdio.h>
#include<math.h>
int main()
{
	int t,arr[14],max,sum,i;
	double mean,sd;
	char str[5];
	scanf("%d",&t);
	while(t--)
	{
		max=sum=0;
		scanf(" %s",str);
		for(i=0;i<14;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
			if(arr[i]>max)
				max=arr[i];
		}
		mean=sum/14.0;
		sd=0.0;
		for(i=0;i<14;i++)
			sd=sd+(arr[i]-mean)*(arr[i]-mean);
		sd/=14.0;
		sd=sqrt(sd); // standard deviation completely calculated here
		if(sd-4*0.01*max>=0.0)
			printf("%s ",str);
	}
}
