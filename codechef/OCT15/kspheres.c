#include<stdio.h>
#define MAX 100000
#define MAXOTHER 1000
int min(int a,int b){return a<b?a:b;}
int main()
{
	int t,n,m,c,u[MAX+1],l[MAX+1],answerArray[MAXOTHER+1],found[MAX+1];
	{
		for(i=0;i<=MAXOTHER;i++)
			answerArray=0;
		for(i=0;i<=MAX;i++)
			u[i]=l[i]=0;
		scanf("%d%d%d",&n,&m,&c);
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			u[temp]++;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&temp);
			l[temp]++;
		}
		for(i=0;i<=MAX;i++)
			found[i]=min(u[i],l[i]);
		sum[0]=!(!(found[0]));
		for(i=1;i<n;i++)
			if(found[i])
				sum[i]=sum[i-1]+1;
		for(i=0;i<=MAX;i++)
		{
			if(found[i])
			{
				for(j=0;j<=c;j++)
					answerArray[j]+=sum
			}
		}
	}
	return 0;
}
