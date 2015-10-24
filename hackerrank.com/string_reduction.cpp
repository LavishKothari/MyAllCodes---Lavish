#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	char str[101];
	while(t--)
	{
		scanf(" %s",str);
		int flag=0;
		int a=0,b=0,c=0;
		for(int i=0;str[i];i++)
		{
			if(i!=0 && str[i]!=str[0])
				flag=1;
			if(str[i]=='a') a++;
			else if(str[i]=='b') b++;
			else c++;
		}
		if(flag==0)
			printf("%d\n",strlen(str));
		else if( (a%2==0 && b%2==0 && c%2==0) || (a%2!=0 && b%2!=0 && c%2!=0) )
			printf("2\n");
		else printf("1\n");
	}
	return 0;
}
