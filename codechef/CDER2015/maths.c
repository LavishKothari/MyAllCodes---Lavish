#include<string.h>
#include<stdio.h>
long long int findIntermediateResult(long long int a,char o,long long int b)
{
	switch(o)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
	}
}
long long int findAnswer(char str[])
{
	int i;
	long long int answer=0;
	i=strlen(str)-1;
	answer=findIntermediateResult(str[i]-'0',str[i-1],str[i-2]-'0');
	for(i=i-4;i>=0;i-=2)
	{
		answer=findIntermediateResult(answer,str[i+1],str[i]-'0');
	}
	return answer;
}
int main()
{
	char str[10000];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		printf("%lld",findAnswer(str));
	}
	return 0;
}
