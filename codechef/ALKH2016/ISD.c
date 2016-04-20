#include<stdio.h>
int main()
{
	int t,answer,current,prev,i,n,increasing;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&prev);
		scanf("%d",&current);
		if(prev>current)
			increasing=0;
		else increasing=1;
		prev=current;
		answer=0;
		for(i=2;i<n;i++)
		{
			scanf("%d",&current);
			if(prev>current && increasing)
			{
				answer++;
				increasing=0;
			}
			if(prev<current && !increasing)
			{
				answer++;
				increasing=1;
			}
			prev=current;
		}
		printf("%d\n",answer);
	}
	return 0;
}
