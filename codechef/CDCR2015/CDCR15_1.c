#include<stdio.h>

int main()
{
	int test,n,k,i,count,max;
	char str[100001];
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",str);
		count=max=0;
		for(i=0;str[i];i++)
		{
			if(str[i]=='#')
				count++;
			else
				count=0;
			if(count>max)
				max=count;
		}
		if(max>=k)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
