#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		char s1[100001],s2[100001];
		scanf(" %s %s",s1,s2);
		bool flag1[26],flag2[26];
		for(int i=0;i<26;i++)
			flag1[i]=flag2[i]=false;
		for(int i=0;s1[i];i++)
			flag1[s1[i]-'a']=true;
		for(int i=0;s2[i];i++)
			flag2[s2[i]-'a']=true;
		bool answer=false;
		for(int i=0;i<26;i++)
			if(flag1[i] && flag2[i])
			{
				answer=true;
				break;
			}
		if(answer)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
