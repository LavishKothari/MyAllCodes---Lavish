#include<stdio.h>

int main()
{
	int t,max,n,i,curr,prev,continous;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		continous=max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&curr);
			if(i==0)
			{
				prev=curr;
				continue;
			}
			if(prev==curr)
			{
				continous++;
				if(continous>max)
					max=continous;
			}
			else
			{
				continous=0;
			}
			prev=curr;
		}
		printf("%d\n",max);
	}
	return 0;
}
