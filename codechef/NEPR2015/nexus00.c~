#include<stdio.h>

int main()
{
	int n,a,k,i;
	char s[100001];
	scanf("%d",&n);
	while(n--)
	{
		scanf(" %[^\n]s",s);
		scanf("%d",&k);
		for(i=0;s[i];i++)
		{
			if(s[i]>='a' && s[i]<='z')
			{
				//printf("hello lavish kothari\n");
				if((s[i]-'a'-k)%26<0)
					a=(s[i]-'a'-k)%26+26;
				else a=(s[i]-'a'-k)%26;
				a+='a';
				printf("%c",a);
			}
			else if(s[i]>='A' && s[i]<='Z')
			{
				if((s[i]-'A'-k)%26<0)
					a=(s[i]-'A'-k)%26+26;
				else a=(s[i]-'A'-k)%26;
				a+='A';
				printf("%c",a);
			}
			else printf("%c",s[i]);
		}
		printf("\n");
	}
}
