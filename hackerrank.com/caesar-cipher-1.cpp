#include<stdio.h>

int main()
{
	int n,k;
	char str[101];
	scanf("%d%s%d",&n,str,&k);
	for(int i=0;str[i];i++)
	{
		if((str[i]>='a' && str[i]<='z'))
		{
			str[i]=(str[i]-'a'+k)%26+'a';
		}
		else if((str[i]>='A' && str[i]<='Z'))
		{
			str[i]=(str[i]-'A'+k)%26+'A';
		}
	}
	printf("%s\n",str);
	return 0;
}
