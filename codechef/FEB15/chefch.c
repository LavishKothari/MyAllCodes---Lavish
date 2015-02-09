#include<stdio.h>

int main()
{
	char str[100001];
	int test,answer,i;
	scanf("%d",&test);
	while(test--)
	{
		answer=0;
		scanf("%s",str);
		for(i=0;str[i] && str[i+1];i+=2)
		{
			if(str[i]==str[i+1])
			{
				if(str[i]=='+')
					str[i+1]='-';
				else str[i+1]='+';
				answer++;
			}
		}
		printf("%d\n",answer);
	}
	return 0;
}
