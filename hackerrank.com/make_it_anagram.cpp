#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[10001],b[10001];
	scanf(" %s %s",a,b);
	int ca[26],cb[26];
	for(int i=0;i<26;i++)
		ca[i]=cb[i]=0;
	for(int i=0;a[i];i++)
		ca[a[i]-'a']++;
	for(int i=0;b[i];i++)
		cb[b[i]-'a']++;
	int answer=0;
	for(int i=0;i<26;i++)
	{
		//printf("%d %d\n",ca[i],cb[i]);
		answer+=abs(ca[i]-cb[i]);
	}printf("%d\n",answer);
	return 0;
}
