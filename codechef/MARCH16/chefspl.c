#include<stdio.h>
#include<string.h>
int findAnswer(char *str) // returns 1 for YES and 0 for NO
{
	int i,mistake,other,answer,len,something;
	len=strlen(str);
	if(len==1)
		return 0;
	if(len%2==0)
	{
		for(i=0;i<len/2;i++)
			if(str[i]!=str[len/2+i])
				return 0;
		return 1;
	}
	else
	{
		//  i'm planning to remove element from second half.
		other=0;
		mistake=0;
		something=0;
		for(i=0;i<len/2;i++)
		{
			if(str[i]!=str[len/2+i+other])
			{
				if(mistake==0)
				{
					other=1;
					mistake++;
					i--;
				}	
				else
				{
					something=1; // :(
				 	break;
				}
			}	
		}
		if(i==len/2 && something==0)
			return 1;
		
		
		//  i'm planning to remove element from first half.
		other=0;
		mistake=0;
		something=0;
		for(i=0;i<len/2;i++)
		{
			if(str[i+other]!=str[len/2+1+i])
			{
				if(mistake==0)
				{
					other=1;
					mistake++;
					i--;
				}	
				else
				{
					something=1; // :(
					break;
				}
			}	
		}
		if(i==len/2 && something==0)
			return 1;
		
		
		return 0;
	}
}
int main()
{
	int t;
	char str[1000001];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		if(findAnswer(str))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
