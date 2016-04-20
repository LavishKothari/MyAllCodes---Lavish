#include<stdio.h>
#include<string.h>
int findAnswer(char*str)
{
	int len,i,j;
	len=strlen(str);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		if(str[i]!=str[j])
		{
			// either i has to be removed or j has to be removed.
			if(i+1<len && str[i+1]==str[j] && i+2<len && j-1>=0 && str[i+2]==str[j-1])
				return i;
			else if(j-1>=0 && str[j-1]==str[i])
				return j;
		}
	}
	return -1;
}
int main()
{
	char str[100006];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		printf("%d\n",findAnswer(str));
	}
	return 0;
}
