#include<stdio.h>

int main()
{
	int t,i,maxi,max,temp,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxi=0;max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(temp>max)
			{
				max=temp;
				maxi=i;
			}
		}
		printf("%d\n",maxi+1);
	}
	return 0;
}
