#include<stdio.h>

int main()
{
	int t,flag[26],i,maxi,max;
	char str[100001];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<26;i++)
			flag[i]=0;
		scanf(" %[^\n]s",str);
		for(i=0;str[i];i++)
		{
			if(str[i]>='a' && str[i]<='z')
				flag[str[i]-'a']++;
			if(str[i]>='A' && str[i]<='Z')
				flag[str[i]-'A']++;
		}
		max=0;
		for(i=0;i<26;i++)
			if(flag[i]>=max)
			{
				max=flag[i];
				maxi=i;
			}
		printf("%c\n",(maxi+'a'));
	}
	return 0;
}

