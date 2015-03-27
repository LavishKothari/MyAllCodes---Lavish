#include<stdio.h>
long long int power(int a,int b)
{
	int i;
	long long int p=1;
	for(i=0;i<b;i++)
		p*=a;
	return p;
}
int min(int a,int b)
{
	return a<b?a:b;
}
calsin(int s,int c,int k)
{
	long long int answers;
	if(s!=0 && k<=s)
		answers=power(2,s-k+1)+1;
	else
		answers=0;
	return answers;
}
calcos(int s,int c,int k)
{
	long long int answerc;
	if(k==1)
		answerc=2*(power(2,c)-1);
	else
		answerc=0;
	return answerc;
}
long long int findAnswer(int s,int c,int k)
{
	counter=1;
	while(1)
	{
		
	}
}
int main()
{
	int s,c,k;
	int t;
	long long int totalAnswer;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&s,&c,&k);
		printf("%lld\n",findAnswer(s,c,k));
	}
	return 0;
}
