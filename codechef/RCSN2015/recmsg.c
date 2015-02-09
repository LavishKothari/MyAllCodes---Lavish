#include<stdio.h>

int main()
{
	int t,answer,i;
	char str[1001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		answer=0;
		for(i=0;str[i];i++)
			answer+=str[i]-'a'+1;
		printf("%d\n",answer);
	}
	return 0;
}
