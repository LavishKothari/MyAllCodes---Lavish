#include<stdio.h>

int main()
{
	int t,n,prev,answer,i,temp,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&prev);count=1;
		answer=0;
		for(i=1;i<n;i++)
		{
			scanf("%d",&temp);
			if(temp==prev)
				count++;
			else 
			{
				prev=temp;
				count=1;
			}
			if(count==3)
				answer=1;
		}
		if(answer)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
