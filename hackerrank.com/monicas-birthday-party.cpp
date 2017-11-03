/*
   7
   300 300
   0 3 0 0 1 2 0
   3 0 1 2 0 1 0
   0 1 0 1 0 3 0
   0 2 1 0 4 5 0
   1 0 0 4 0 7 0
   2 1 3 5 7 0 0
   0 0 0 0 0 0 0 
 */
#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
ll findAnswer(vector< vector<int> >&graph,int a,int b)
{
	int n=graph.size();

	vector<int>table(n,1);

	for(int x=0;x<min(n/2,min(a,b));x++)
	{
		vector<ll>weight(n,0);	
		for(int i=0;i<n;i++)
			if(table[i]==1)
				for(int j=0;j<n;j++)
					if(table[j]==1)
						weight[i]+=graph[i][j];

		for(int i=0;i<n;i++)
			if(table[i]==1)
				for(int j=0;j<n;j++)
					if(table[j]==2)
						weight[i]-=graph[i][j];
		int current=0,maxi=-1;

		for(int i=0;i<n;i++)
			if(table[i]==1 && maxi<weight[i])
			{
				maxi=weight[i];
				current=i;
			}
		table[current]=2;
	}
	int count1=0,count2=0;
	for(int i=0;i<n;i++)
		if(table[i]==1)
			count1++;
		else count2++;
	if(count1<=a)
	{
		printf("%d\n",count1);
		for(int i=0;i<n;i++)
			if(table[i]==1)
				printf("%d ",i+1);
	}
	else 
	{
		printf("%d\n",count2);
		for(int i=0;i<n;i++)
			if(table[i]==2)
				printf("%d ",i+1);
	}
	printf("\n");
}
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	vector< vector<int> >graph(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&graph[i][j]);
	findAnswer(graph,a,b);
	return 0;
}
