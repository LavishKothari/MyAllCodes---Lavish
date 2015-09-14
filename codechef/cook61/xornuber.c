#include<stdio.h>
int count(int n)
{
	int counter=0;
	while(n)
	{
		if((n&1)==1)
			counter++;
		n=n>>1;
	}
	return counter;
}
int findAnswer(int n)
{
	if(count(n+1)==1)
		return n/2;
	else
		return -1;
}
int findAnswer1(int n)
{
	int i;
	for(i=0;i<(1<<30);i++)
	{
		if((i^(i+1))==n)
			return i;
	}
	return -1;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
			printf("2\n");
		else
			printf("%d\n",findAnswer(n));
	}
	return 0;
}
