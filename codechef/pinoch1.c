#include<stdio.h>

int main()
{
	int t,answer,n,i,curr,prev;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		prev=5000001;
		answer=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&curr);
			if(curr>prev)
				answer++;
			prev=curr;
		}
		printf("%d\n",answer);
	}
	return 0;
}
