#include<stdio.h>
int findWithCorrectPosition(int n,int s)
{
	int count=0;
	while(n)
	{
		if(n%10==s%10)
			count++;
		n/=10;
		s/=10;
	}
	return count;
}
int findWithWrongPosition(int n,int s)
{
	int flag1[10]={0},flag2[10]={0},counter=0,i;
	for(i=0;i<10;i++)
	{
		flag1[n%10]++;
		flag2[s%10]++;
		n/=10;
		s/=10;
	}
	for(i=0;i<10;i++)
		if(flag1[i]==flag2[i] && flag1[i]==1)
			counter++;
	return counter;
}
int main()
{
	int n,t,s,a,b;
	scanf("%d%d",&n,&t);
	while(t--)
	{
		scanf("%d",&s);
		a=findWithCorrectPosition(n,s);
		b=findWithWrongPosition(n,s);
		printf("%d-%d ",a,b-a);
	}
	return 0;
}
