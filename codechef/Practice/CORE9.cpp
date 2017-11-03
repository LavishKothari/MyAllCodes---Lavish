/*
Assumptions: 
There always exists a solution - ie.. the graph formed is always connected.
There is no chain of snakes and ladders.

 */

#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
struct Ladder_Snake
{
	int start,end;
};
class Vertex
{
	public:
		int distance,parent;
		bool isVisited;
		vector<int>adj_list;
		Vertex(){}
		Vertex(int distance,bool isVisited)
		{
			this->distance=distance;
			this->isVisited=isVisited;
		}
};
map<int , Vertex>graph;	// making the graph global
void bfs(int start)
{
	vector<int>q;
	q.push_back(start);

	graph[start].isVisited=true;
	graph[start].distance=0;
	graph[start].parent=0;

	while(q.size()!=0)
	{
		int v=q[0];
		q.erase(q.begin());
		for(int i=0;i<graph[v].adj_list.size();i++)
		{
			int u=graph[v].adj_list[i];
			if(graph[u].isVisited==false)
			{
				q.push_back(u);
				graph[u].parent=v;
				graph[u].isVisited=true;
				graph[u].distance=graph[v].distance+1;
			}
		}
	}
}

int isStart(int x,struct Ladder_Snake *arr,int n)
{
	for(int i=0;i<n;i++)
		if(arr[i].start==x)
			return arr[i].end;
	return -1;
}
void getNumbers(char*str,int *a,int *b)
{
	int flag=0,start=0,end=0;
	for(int j=0;str[j];j++)
	{
		if(str[j]==',')
			flag=1;continue;
		if(flag==0)
			start=start*10+str[j]-'0';
		else
			end=end*10+str[j]-'0';
	}
	(*a)=start;
	(*b)=end;	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ladders,snakes;
		char str[100];
		scanf("%s",str);
		getNumbers(str,&ladders,&snakes);

		struct Ladder_Snake ladder[15];
		for(int i=0;i<ladders;i++)
		{
			scanf(" %s",str);
			getNumbers(str,&(ladder[i].start),&(ladder[i].end));
		}

		struct Ladder_Snake snake[15];
		for(int i=0;i<snakes;i++)
		{
			scanf("%s",str);
			getNumbers(str,&(snake[i].start),&(snake[i].end));
		}

		for(int i=1;i<=100;i++)
		{
			if(isStart(i,snake,snakes)!=-1 || isStart(i,ladder,ladders)!=-1)
				continue;
			graph[i]=Vertex(0,false);
			for(int j=i+1;j<=100 && j<i+7;j++)
			{
				int x,y;
				x=isStart(j,snake,snakes);
				y=isStart(j,ladder,ladders);
				if(x!=-1)
					graph[i].adj_list.push_back(x);
				else if(y!=-1)
					graph[i].adj_list.push_back(y);
				else graph[i].adj_list.push_back(j);
			}
		}
		// graph construction completed here.
		// printing the graph.
		bfs(1);
		/*
		   for(map<int,Vertex> ::iterator it=graph.begin();it!=graph.end();it++)
		   {
		   printf("%d -> ",it->first);
		   Vertex v=it->second;
		   for(int j=0;j<v.adj_list.size();j++)
		   {
		   printf("%d ",v.adj_list[j]);
		   }
		   printf("\t\t%d",v.parent);
		   printf("\n");
		   }
		 */

		printf("%d\n",graph[100].distance);

	}
	return 0;
}
