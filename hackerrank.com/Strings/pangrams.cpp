#include<stdio.h>
#define MAX 1000
int main()
{
	char str[MAX+1];
	bool flag[26];
	int i;
	for(i=0;i<26;i++)
		flag[i]=false;
	scanf("%[^\n]s",str);
	for(i=0;str[i];i++)
		if(str[i]>='A' && str[i]<='Z')
			str[i]=str[i]+'a'-'A';
	for(i=0;str[i];i++)
		if(str[i]!=' ')
			flag[str[i]-'a']=true;
	for(i=0;i<26;i++)
		if(flag[i]==false)
			break;
	if(i!=26)
		printf("not pangram\n");
	else printf("pangram\n");
	return 0;
}

