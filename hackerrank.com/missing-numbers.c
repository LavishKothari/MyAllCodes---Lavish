#include<stdio.h>
int main()
{
	int a,b,temp,i;
	int f1[1000011]={0},f2[1000011]={0};
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&temp);
		f1[temp]++;	
	}
	scanf("%d",&b);
	for(i=0;i<b;i++)
	{
		scanf("%d",&temp);
		f2[temp]++;	
	}
	for(i=0;i<1000011;i++)
		if(f1[i]!=f2[i])
			printf("%d ",i);
	return 0;
}
