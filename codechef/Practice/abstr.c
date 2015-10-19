#include<stdio.h>
#include<string.h>
int findLengthOfLongestPrefixSubstring(char*str)
{
	int i,j;
	int len=strlen(str);
	for(i=0,j=len-1;i<len;i++,j--)
	{
		if(str[i]!=str[j])
		{
			if(i==0)
				return -1;
			return i+1;
		}
	}	
	return i;
}

int main()
{
	char str[100001];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		printf("%d\n",findLengthOfLongestPrefixSubstring(str));
	}
	return 0;
}
