#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;
#define MOD 1000000007
int**table;

map<long long int,long long int>g;

long long int findAnswer(int*arr,int n,int target)
{
	int max_value=1<<10;
	if(g.find((long long int)n*max_value+target)!=g.end())
		return g[(long long int)n*max_value+target];
	g[(long long int)n*max_value+target]=(findAnswer(arr,n-1,target)+findAnswer(arr,n-1,target^arr[n-1]))%MOD;
	return g[(long long int)n*max_value+target];
}

int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[11];
		scanf(" %s",str);
		int n=0;
		for(int i=0;str[i];++i)
		{
			if(str[i]=='w')
				n=(n|(1<<(9-i)));
		}
		int m;
		scanf("%d",&m);
		int*arr=(int*)malloc(sizeof(int)*m);
		for(int i=0;i<m;++i)
		{
			scanf(" %s",str);
			arr[i]=0;
			for(int j=0;str[j];++j)
			{
				if(str[j]=='+')
					arr[i]=(arr[i]|(1<<(9-j)));
			}
		}
		g.erase(g.begin(),g.end());
		for(int i=0;i<(1<<10);i++)
			g[i]=0;
		g[0]=1;
		printf("%lld\n",findAnswer(arr,m,n));
		free(arr);
	}
	return 0;
}
