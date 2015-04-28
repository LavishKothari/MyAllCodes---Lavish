#include<stdio.h>

int main()
{
	int t,n,i,temp,min,max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		max=0;
		min=1000000001;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(temp>max)
				max=temp;
			if(temp<min)
				min=temp;
		}
		if(max-min>=2)
			printf("BAD\n");
		else
			printf("GOOD\n");
	}
	return 0;
}
