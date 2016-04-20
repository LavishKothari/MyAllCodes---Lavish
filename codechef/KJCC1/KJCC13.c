#include<stdio.h>
int c(int n)
{
	if(n==0)
		return 1;
	while(n)
	{
		if(n%10==0)
			return 1;
		n/=10;
	}
	return 0;
}
int main()
{
	int t,i,count,a,b,d;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d%d",&a,&b);
		d=b-a+1;
		for(i=a;i<=b;i++)
			if(c(i)==1)
				count++;
		printf("%d/%d\n",count,d);
	}
	return 0;
}
