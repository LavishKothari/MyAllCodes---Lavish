#include<stdio.h>
int main()
{
	int t,i,temp,n,prevtemp;
	long long int answer;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		prevtemp=answer=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(temp-prevtemp>0)
				answer+=temp-prevtemp;
			prevtemp=temp;
		}
		printf("%lld\n",answer);
	}
	return 0;
}
