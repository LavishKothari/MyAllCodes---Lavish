#include<stdio.h>
#include<string.h>
int main()
{
	char str[100001];
	int t,len;
	long long int a,b;
	scanf(" %s %d",str,&t);
	len=strlen(str);
	while(t--)
	{
		scanf(" %lld %lld",&a,&b);
		a--;b--;
		a%=len;b%=len;
		if(str[a]==str[b])
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
