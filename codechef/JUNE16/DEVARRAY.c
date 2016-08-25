#include<stdio.h>
int main()
{
	int n,q,min=2147483647,temp,max=0;
	scanf("%d",&n);
	scanf("%d",&q);
	while(n--)
	{
		scanf("%d",&temp);
		if(temp>max)
			max=temp;
		if(temp<min)
			min=temp;
	}
	while(q--)
	{
		scanf("%d",&temp);
		if(temp>=min && temp<=max)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
