
#include<stdio.h>
#include<string.h>
int isPalin(char*str,int a,int b)
{
	int i,j;
	for(i=a,j=b;i<j;i++,j--)
		if(str[i]!=str[j])
			return 0;
	return 1;
}
int main()
{
	int t,i,j,max,maxi,maxj,len;
	char str[21];
	scanf("%d",&t);
	while(t--)
	{
		max=maxi=maxj=0;
		scanf("%s",str);
		len=strlen(str);
		for(i=0;i<len;i++)
		{
			for(j=i;j<len;j++)
			{
				if(isPalin(str,i,j) && max<j-i)
				{
					max=j-i;
					maxi=i;
					maxj=j;
				}
					
			}
		}
		for(i=maxi;i<=maxj;i++)
			printf("%c",str[i]);
		printf("\n");
	}
	return 0;
}
