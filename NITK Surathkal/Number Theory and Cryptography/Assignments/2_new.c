#include<stdio.h>
#include<string.h>
#define MAX 10000

void mul(char*s1,char*s2)
{
	
}

void add(char*s1,char*s2) // adding binary numbers assuming both are of same length.
{
	int length=0,ans[MAX],c=0,i,j,k,len1,len2,newarr[100];
	len1=strlen(s1);
	len2=strlen(s2);
	for(i=len1-1,j=len2-1,k=MAX-1;i>=0 && j>=0;i--,j--,k--)
	{
		length++;
		if(c==0)
		{
			if(s1[i]=='0' && s2[j]=='0')
				ans[k]=0;
			else if(s1[i]=='1' && s2[j]=='0')
				ans[k]=1;
			else if(s1[i]=='0' && s2[j]=='1')
				ans[k]=1;
			else if(s1[i]=='1' && s2[j]=='1')
			{
				c=1;
				ans[k]=0;
			}
		}	
		else
		{
			if(s1[i]=='0' && s2[j]=='0')
			{
				c=0;
				ans[k]=1;
			}
			else if(s1[i]=='1' && s2[j]=='0')
			{
				c=1;
				ans[k]=0;
			}
			else if(s1[i]=='0' && s2[j]=='1')
			{
				c=1;
				ans[k]=0;
			}
			else if(s1[i]=='1' && s2[j]=='1')
			{
				c=1;
				ans[k]=1;
			}
		}
	}
	counter=0;
	if(c==1)
	{
		newarr[counter++]=1;
		printf("1");
	}
	for(i=MAX-length;i<MAX;i++)
	{
		newarr[counter++]=ans[i];
		printf("%d",ans[i]);
	}
	printf("\n");
}

int main()
{
	char s1[MAX],s2[MAX];
	printf("Enter the first binary number : ");
	scanf(" %s",s1);
	printf("Enter the second binary number : ");
	scanf(" %s",s2);
	
	add(s1,s2);
	
	return 0;
}
