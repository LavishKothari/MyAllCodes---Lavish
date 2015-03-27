#include<string.h>
#include<stdio.h>
int min(int a,int b)
{
	return a>b?b:a;
}
long long int findAnswer(char str[],int a,int b)
{
	int i,j;
	long long int answer=0;
	for(i=0,j=strlen(str)-1;i<j;i++,j--)
	{
		if(str[i]!='/' && str[j]!='/' && str[i]!=str[j])
			return -1;
		else if(str[i]=='/' && str[j]=='/')
			answer+=2*min(a,b);
		else if(str[i]=='/')
		{
			if(str[j]=='a')
				answer+=a;
			else answer+=b;
		}
		else if(str[j]=='/')
		{
			if(str[i]=='a')
				answer+=a;
			else answer+=b;
		}
	}
	return answer;
}
int main()
{
	char str[10001];
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s%d%d",str,&a,&b);
		printf("%lld\n",findAnswer(str,a,b));
	}
	return 0;
}
