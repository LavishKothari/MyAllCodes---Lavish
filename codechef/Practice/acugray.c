#include<stdio.h>

int main()
{
	int t,i;
	char str[1001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		printf("%c",str[0]);
		for(i=1;str[i];i++)
		{
			printf("%d",(str[i]-'0')^(str[i-1]-'0'));
		}
		printf("\n");
	}
	return 0;
}
