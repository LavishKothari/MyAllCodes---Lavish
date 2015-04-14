#include<stdio.h>

int main()
{
	int t,counter,i;
	char str[100001];
	scanf("%d",&t);
	while(t--)
	{
		counter=0;
		scanf(" %s",str);
		for(i=0;str[i] && str[i+1];i++)
		{
			if(str[i]=='0' && str[i+1]=='1')
				counter++;
		}
		printf("%d\n",counter);
	}
	return 0;
}
