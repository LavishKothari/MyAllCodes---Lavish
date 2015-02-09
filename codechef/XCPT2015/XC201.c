#include<stdio.h>

int main()
{
	int t,max,count,i,j,flag[26];
	char s[1001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		max=0;
		for(i=0;s[i];i++)
		{
			count=1;
			for(j=0;j<26;j++)
				flag[j]=0;
			flag[s[i]-'a']++;
			for(j=i+1;s[j];j++)
			{
				if(flag[s[j]-'a']==0)
				{
					count++;
					flag[s[j]-'a']++;
				}
				else
					break;
			}
			if(count>max)
				max=count;
		}
		printf("%d\n",max);
	}
	return 0;
}
