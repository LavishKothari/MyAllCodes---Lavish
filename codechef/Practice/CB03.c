#include<stdio.h>
#include<string.h>

long long int countPalindromicSubsequences(char *str)
{
	int len=strlen(str),i,j,l,x,k;
	long long int T[len][len];
	
	for(i=0;i<len;i++)
		T[i][i]=1;
	
	for(l=2;l<=len;l++)
	{
		for(i=0;i<len;i++)
		{
			j=l+i-1;
			if(j<len)
			{
				if(l==2 && str[i]==str[j])
					T[i][j]=3;
				else
				{
					x=0;
					if(i+1<len && i+1<=j)
					{
						x=T[i+1][j]+1;
						for(k=i+1;k<=j;k++)
							if(str[k]==str[i])
							{
								if(i+1<=k-1)
									x+=T[i+1][k-1]+1;
								else x+=1;
							}
					}
					T[i][j]=x;
				}
			}
		}
	}
	/*
	printf("this is the matrix\n");
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
			if(i>j)
				printf("0 ");
			else printf("%lld ",T[i][j]);
		printf("\n");
	}
	*/
	return T[0][len-1];
}
int main()
{
	int t;char str[1000];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		printf("%lld\n",countPalindromicSubsequences(str));
	}
	return 0;
}
