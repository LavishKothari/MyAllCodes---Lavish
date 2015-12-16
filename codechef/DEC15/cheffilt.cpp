#include<stdio.h>
#include<stdlib.h>
#include<set>
#define MOD 1000000007
using namespace std;
int**table;
long long int power(int a,int b)
{
	if(b<=0)
		return 1;
	if(b==1)
		return a;
	long long int t=power(a,b/2);
	if(b&1)
		return (((t*t)%MOD)*a)%MOD;
	return (t*t)%MOD;
}
long long int filament(long long int a)
{
	return a/2+1;
}
long long int findAnswer(int*arr,int n,int target,int *count,int m)
{
	int max_value=1<<10;
	table=(int**)malloc(sizeof(int*)*(n+1));
	for(int i=0;i<=n;i++)
		table[i]=(int*)malloc(sizeof(int)*(max_value+1));
	for(int i=0;i<=max_value;i++)
		table[0][i]=0;
	table[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=max_value;j++)
		{
			//printf("(i,j) = (%d,%d) and access = (%d,%d)\n",i,j,i-1,j^arr[i-1]);
			table[i][j]=((long long int)table[i-1][j]+table[i-1][j^arr[i-1]])%MOD;	
			if(i==n && j==target)
				return table[n][target];
		}
	}
	/*
	printf("this is a check at the end: %d %d \n",n,target);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<max_value;j++)
			printf("arr[%d][%d] = %d\n",i,j,table[i][j]);
		printf("\n\n");
	}
	*/
	long long int answer=table[n][target];
	for(int i=0;i<=n;i++)
		free(table[i]);
	free(table);
	return (answer)%MOD;
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
		for(int i=0;str[i];i++)
		{
			if(str[i]=='w')
				n=(n|(1<<(9-i)));
		}
		int m;
		scanf("%d",&m);
		int *count=(int*)malloc(sizeof(int)*1024);
		for(int i=0;i<1024;i++)
			count[i]=0;
		set<int>f;
		for(int i=0;i<m;i++)
		{
			int number=0;
			scanf(" %s",str);
			for(int j=0;str[j];j++)
			{
				if(str[j]=='+')
					number=(number|(1<<(9-j)));
			}
			count[number]++;
			f.insert(number);
		}
		long long int tempanswer=1;
		set<int>::iterator ze=f.find(0);
		if(ze!=f.end())
		{
			tempanswer=power(2,count[0]);
			f.erase(ze);
			count[0]=0;
		}
		int*arr=(int*)malloc(sizeof(int)*f.size());
		int i;
		set<int>::iterator it;
		for(i=0,it=f.begin();i<f.size();i++,it++)
			arr[i]=(*it);
		
		long long int answer=(findAnswer(arr,f.size(),n,count,m)*tempanswer)%MOD;
		long long int other=1;
		for(i=0;i<1024;i++)
		{
			other=(other*power(2,count[i]-1))%MOD;
		}		
		answer=(answer*other)%MOD;
		printf("%lld\n",answer);
		
		free(count);
		f.erase(f.begin(),f.end());
		free(arr);
	}
	return 0;
}
