#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		bool flag[676]={0};
		char str[10001];
		scanf("%s",str);
		for(int i=0;str[i] && str[i+1];i++)
			flag[(str[i]-'A')*26+(str[i+1]-'A')]=true;
		int answer=0;
		for(int i=0;i<676;i++)
			if(flag[i])
				answer++;
		printf("%d\n",answer);
	}
}
