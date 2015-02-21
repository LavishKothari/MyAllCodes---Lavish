#include<stdio.h>
int isPalindrome(char str[],int len)
{
	int i,j;
	for(i=0,j=len-1;i<j;i++,j--)
		if(str[i]!=str[j])
			return 0;
	return 1;
}
int main()
{
	char str[10000],newStr[10000];
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %[^\n]s",str);
		for(i=0,j=0;str[i];i++)
			if(str[i]>='a' && str[i]<='z')
				newStr[j++]=str[i];
			else if(str[i]>='A' && str[i]<='Z')
				newStr[j++]=str[i]+('a'-'A');
		if(isPalindrome(newStr,j))
			printf("Y ");
		else printf("N ");
	}
	return 0;
}
