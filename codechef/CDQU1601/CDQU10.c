#include<stdio.h>

int main()
{
	char str[101];
	int n,flag,i;
	scanf("%d",&n);
	while(n--)
	{
		scanf(" %s",str);
		flag=0;
		for(i=0;str[i];i++)
			if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u')
			{
				flag=1;
				break;
			}
		if(flag==1)
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
