#include<stdio.h>
#include<vector>
#define MAX 200010
using namespace std;

int queue[MAX];
int start,end;

void enqueue(int val)
{
	if(start==end && start==-1)
	{
		start++;end++;
		queue[start]=val;
		return;
	}

	end++;
	queue[end]=val;
}	

int dequeue()
{
	if(start==end)
	{
		int temp=queue[start];
		start=end=-1;
		return temp;
	}
	int temp=queue[end];
	end--;
	return temp;
}

int main()
{
	int n,a,b,i,j;
	scanf("%d",&n);
	vector< vector<int> >graph;
	for(i=0;i<n;i++)
	{
		vector<int>tempvector;
		graph.push_back(tempvector);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		graph[a-1].push_back(b-1);
	}
	/*
	   for(i=0;i<n;i++)
	   {
	   for(j=0;j<graph[i].size();j++)
	   printf("%d ",graph[i][j]);
	   printf("\n");
	   }
	 */
	start=end=-1;

	enqueue(0);
	while(true)
	{
		int current=dequeue();
		for(i=0;i<graph[current].size();i++)
		{
			enqueue(graph[current][i]);
		}
		enqueue(-1);
	}


	return 0;
}
