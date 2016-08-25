#include<string.h>
#include<stdio.h>
int min3(int a,int b,int c)
{
	return a<b?(a<c?a:c):(b<c?b:c);
}
int findAnswer(char*a,char*b)
{
	int lena=strlen(a),lenb=strlen(b),i,j;
	int T[lena+1][lenb+1];
	for(i=0;i<=lena;i++)
	{
		for(j=0;j<=lenb;j++)
		{
			if(i==0 || j==0)
				T[i][j]=i+j;
			else
				T[i][j]=min3(1+T[i-1][j],1+T[i][j-1],(!(a[i-1]==b[j-1]))+T[i-1][j-1]);
		}
	}
	return T[lena][lenb];
}
int main()
{
	char a[10000],b[10000];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s%s",a,b);
		printf("%d ",findAnswer(a,b));
	}
	return 0;
}
