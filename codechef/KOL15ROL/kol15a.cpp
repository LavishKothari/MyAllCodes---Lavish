#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[1001];
		int answer=0;
		scanf(" %s",str);
		for(int i=0;str[i];i++)
			if(str[i]>='0' && str[i]<='9')
				answer+=str[i]-'0';
		printf("%d\n",answer);
	}
	return 0;
}
