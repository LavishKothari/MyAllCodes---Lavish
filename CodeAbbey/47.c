#include<stdio.h>

int main()
{
	int t,n,k,i;
	char str[10000];
	scanf("%d%d",&n,&k);
	while(n--)
	{
		scanf(" %[^\n]s",str);
		for(i=0;str[i];i++)
		{
			if(str[i]>='A' && str[i]<='Z')
			{
				str[i]=str[i]-k;
				while(str[i]<'A')
					str[i]+=26;
			}
		}
		printf("%s ",str);
	}
	return 0;
}
