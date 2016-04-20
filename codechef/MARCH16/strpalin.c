#include<stdio.h>

int main()
{
	int f1[26],f2[26];
	int t,i,flag;
	char a[1001],b[1001];
	scanf("%d",&t);
	
	while(t--)
	{
		scanf(" %s%s",a,b);
		for(i=0;i<26;i++)
			f1[i]=f2[i]=0;
		for(i=0;a[i];i++)
			f1[a[i]-'a']++;
		for(i=0;b[i];i++)
			f2[b[i]-'a']++;
		flag=0;
		for(i=0;i<26;i++)
		{
			if(f1[i] && f2[i])
			{
				printf("Yes\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("No\n");
	}
	return 0;
}
