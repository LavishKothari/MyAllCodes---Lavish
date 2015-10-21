#include<stdio.h>
int main()
{
	int n,answer=0,temp,v,i;
	scanf("%d%d",&v,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp==v)
			answer=i;
	}
	printf("%d\n",answer);
	return 0;
}
