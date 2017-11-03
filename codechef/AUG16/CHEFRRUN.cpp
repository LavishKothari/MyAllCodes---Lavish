#include<bits/stdc++.h>
#define N 1000001
//#define TEST
using namespace std;
void isPartOfCycle(vector<int>&graph,int start,vector<bool>&answer,vector<bool>&globalVisited)
{
	int slow,fast;
	slow=fast=start;
	do
	{
		if(globalVisited[slow])
		{
			while(!globalVisited[start])
			{
				globalVisited[start]=true;
				start=graph[start];
			}
			return;
		}
		slow=graph[slow];
		fast=graph[graph[fast]];
	}while(slow!=fast);

	int current=slow;
	while(!answer[current] && !globalVisited[current])
	{
		globalVisited[current]=true;
		answer[current]=true;
		current=graph[current];
	}
	current=start;
	while(!answer[current] && !globalVisited[current])
	{
		globalVisited[current]=true;
		current=graph[current];
	}
}
int main()
{
	int t;
#ifdef TEST
	FILE*fp=fopen("tc.txt","r");
	fscanf(fp,"%d",&t);
#else
	cin>>t;
#endif
	while(t--)
	{

		int n;

#ifdef TEST
		fscanf(fp,"%d",&n);
#else	
		cin>>n;
#endif

		vector<bool>answer(n,false);
		vector<int>graph(n);
		vector<bool>globalVisited(n,false);

		for(int i=0;i<n;i++)
		{
			int temp;

#ifdef TEST
			fscanf(fp,"%d",&temp);
#else
			cin>>temp;
#endif

			graph[i]=(i+temp+1)%n;
			if(i==graph[i])
				answer[i]=true;
		}

		for(int i=0;i<n;i++)
			if(answer[i]==false && globalVisited[i]==false)
				isPartOfCycle(graph,i,answer,globalVisited);
		int count=0;
		for(int i=0;i<n;i++)
			if(answer[i])
				count++;
		cout<<count<<endl;
	}

	return 0;
}
