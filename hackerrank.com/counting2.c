#include<stdio.h>

int main()
{
	int n,temp,c[100]={0},i;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		c[temp]++;
	}
	for(i=0;i<100;i++)
		while(c[i]--)
			printf("%d ",i);
	return 0;
}
