#include<stdio.h>

int main()
{
	int t,i,answer;
	scanf("%d",&t);
	while(t--)
	{
		int flag[676]={0};
		char str[10001];
		scanf("%s",str);
		for(i=0;str[i] && str[i+1];i++)
			flag[(str[i]-'A')*26+(str[i+1]-'A')]=1;
		answer=0;
		for(i=0;i<676;i++)
			if(flag[i])
				answer++;
		printf("%d\n",answer);
	}
}
