#include<stdio.h>
#include<string.h>
int findAnswer(char *str)
{
	int len=strlen(str);
	if(len==1)
		return 2;
	if(str[0]=='W')
		return 1;
	if(str[len-1]=='W')
		return 1;
	int l=0,r=0;
	for(int i=0;i<len;i++)
		if(str[i]=='B')	
			l++;
		else break;
	r=len-l-1;
	if(l==r) return 2; // chef wins
	else return 1; // aleksa wins
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[10001];
		scanf(" %s",str);
		int a=findAnswer(str);
		if(a==1)
			printf("Aleksa\n");
		else printf("Chef\n");
	}
	return 0;
}
