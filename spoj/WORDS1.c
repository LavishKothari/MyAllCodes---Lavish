#include<stdio.h>
#include<string.h>
int isch(char ch,int*first,int*last)
{
	int i;
	for(i=0;i<26;i++)
		if(i!=ch-'a' && (first[i]!=0 || last[i]!=0))
		{
			return 0;
		}
	return 1;
}
int main()
{
	int t,flag,i,n,last[26],first[26];
	char str[100001],ch;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<26;i++)
			last[i]=first[i]=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf(" %s",str);
			first[str[0]-'a']++;
			last[str[strlen(str)-1]-'a']++;
			if(str[0]==str[strlen(str)-1])
				ch=str[0];
		}
		if(isch(ch,first,last) && first[ch-'a']+last[ch-'a']%4!=0)
		{
			printf("Ordering is possible.\n");
			continue;
		}
		flag=0;
		for(i=0;i<26;i++)
		{
			flag+=abs(last[i]-first[i]);
		}
		if(flag>2)
			printf("The door cannot be opened.\n");
		else printf("Ordering is possible.\n");
	}
	return 0;
}
