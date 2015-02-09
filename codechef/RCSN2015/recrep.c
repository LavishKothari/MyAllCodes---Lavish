#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,n;
	char names[1001][101],name[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",names[i]);
		scanf("%s",name);
		for(i=0;i<n;i++)
		{
			if(strcmp(names[i],name)==0)
			{
				printf("yes\n");
				break;
			}
		}
		if(i==n)
			printf("no\n");
	}
	return 0;
}

