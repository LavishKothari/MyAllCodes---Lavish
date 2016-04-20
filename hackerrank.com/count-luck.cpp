#include<stdio.h>
#include<vector>
using namespace std;
class vertex
{
	public :
	vector<int>adjlist;
	int number;
	int parent;
	int isvisited;
	vertex(int number,int isvisited)
	{
		this->number=number;
		this->isvisited=isvisited;
	}
};

int dfs(vector<vertex>graph,int start,int end)
{
	vector<int>stack;
	int i,answer=0;
	stack.push_back(start);
	
	graph[start].parent=-1;
	graph[start].isvisited=1;
	//printf("pusing %d\n",start);
	
	while(stack.size()!=0)
	{
		int current=*(stack.end()-1);
		//printf("poping %d\n",current);
		stack.erase(stack.end()-1);
		for(i=0;i<graph[current].adjlist.size();i++)
		{
			int v=graph[current].adjlist[i];
			if(graph[v].isvisited==0)
			{
				stack.push_back(v);
				//printf("pushing %d\n",v);
				graph[v].isvisited=1;
				graph[v].parent=current;
			}
		}
	}
	/*
	for(i=0;i<graph.size();i++)
		printf("%d : %d\n",i,graph[i].parent);
	*/
	while(end!=start)
	{
		if(graph[end].parent==start)
			break;
		if(graph[graph[end].parent].adjlist.size()>2)
			answer++;
		end=graph[end].parent;
	}
	if(graph[start].adjlist.size()>1)
		answer++;
	//printf("%d\n",answer);
	return answer;
}

int main()
{
	int t,i,j,n,m,start,end,k;
	char forest[100][101];
	scanf("%d",&t);
	while(t--)
	{
		vector<vertex>graph;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s",forest[i]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(forest[i][j]=='M')
				{
					start=i*m+j;
					forest[i][j]='.';
				}
				if(forest[i][j]=='*')
				{
					end=i*m+j;
					forest[i][j]='.';
				}
				
			}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				//if(forest[i][j]!='X')
				{
					graph.push_back(vertex(i*m+j,0));
					int current=i*m+j;
					if(i+1<n && forest[i+1][j]=='.') graph[current].adjlist.push_back((i+1)*m+j);
					if(i-1>=0 && forest[i-1][j]=='.') graph[current].adjlist.push_back((i-1)*m+j);
					if(j+1<m && forest[i][j+1]=='.') graph[current].adjlist.push_back((i)*m+j+1);
					if(j-1>=0 && forest[i][j-1]=='.') graph[current].adjlist.push_back((i)*m+j-1);
				}
			}
		}
		/*
		for(i=0;i<graph.size();i++)
		{
			printf("%d: ",i);
			for(j=0;j<graph[i].adjlist.size();j++)
				printf("%d ",graph[i].adjlist[j]);
			printf("\n");
		}
		*/
		scanf("%d",&k);
		if(k==dfs(graph,start,end))
			printf("Impressed\n");
		else printf("Oops!\n");
	}
	return 0;
}
