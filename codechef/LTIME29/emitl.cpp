#include<stdio.h>
#include<string.h>
int main()
{
	int tx;
	char str[101];
	scanf("%d",&tx);
	while(tx--)
	{
		scanf(" %s",str);
		int l,t,i,m,e;
		l=0;t=0;i=0;m=0;e=0;
		if(strlen(str)==9)
		{
			for(int x=0;str[x];x++)
			if(str[x]=='L')
				l++;
			else if(str[x]=='T')
				t++;
			else if(str[x]=='I')
				i++;
			else if(str[x]=='M')
				m++;
			else if(str[x]=='E')
				e++;
			if(l>=2 && t>=2 && i>=2 && m>=2 && e>=1)
				printf("YES\n");
			else printf("NO\n");	
			continue;
		}
		for(int x=0;str[x];x++)
			if(str[x]=='L')
				l++;
			else if(str[x]=='T')
				t++;
			else if(str[x]=='I')
				i++;
			else if(str[x]=='M')
				m++;
			else if(str[x]=='E')
				e++;
		if(l>=2 && t>=2 && i>=2 && m>=2 && e>=2)
			printf("YES\n");
		else printf("NO\n");
	}
}
