#include<stdio.h>

int main()
{
	int n,a,b,i,temp;
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	if(b>a)
	{
		temp=b;
		b=a;
		a=temp;
	}
	for(i=0;i<n-2;i++)
	{
		scanf("%d",&temp);
		if(temp>a)
		{
			b=a;
			a=temp;
		}
	}
	printf("%d %d\n",a,b);
	return 0;
}