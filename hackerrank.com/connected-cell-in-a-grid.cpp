#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<list>
using namespace std;
class vertex
{
	public:
	int color,value,number;
	vector<int>adjacencyList;
	vertex(int color,int value,int number)
	{
		this->color=color;
		this->value=value;
		this->number=number;
	}
};
vector<vertex>vertexArray;
vector<int>stack;
int findAnswer()
{
	int max=0;
	for(int x=0;x<vertexArray.size();x++)
	{
		if(vertexArray[x].color==0 && vertexArray[x].value==1)	
		{	
			stack.push_back(x);
			//printf("pushing = %d\n",x);
			int count=0;
			while(stack.size()!=0)
			{
				count++;
				//printf("poping = %d\n",*(stack.end()-1));
				int current=*(stack.end()-1);
				stack.erase(stack.end()-1);
				vertexArray[current].color=1;
				for(int i=0;i<vertexArray[current].adjacencyList.size();i++)
				{
					int v=vertexArray[current].adjacencyList[i];
					if(vertexArray[v].color==0)
					{
						stack.push_back(v);
						vertexArray[v].color=1;
						//printf("pushing = %d\n",v);
					}
				}
			}
			if(count>max)
				max=count;
		}
	}
	return max;
}

int main()
{
	int m,n,temp;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&temp);
			vertexArray.push_back(vertex(0,temp,i*n+j));
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i+1<n && vertexArray[(i+1)*n+j].value==1) vertexArray[i*n+j].adjacencyList.push_back((i+1)*n+j);
			if(i-1>=0 && vertexArray[(i-1)*n+j].value==1) vertexArray[i*n+j].adjacencyList.push_back((i-1)*n+j);
			if(j+1<m && vertexArray[(i)*n+j+1].value==1) vertexArray[i*n+j].adjacencyList.push_back((i)*n+j+1);
			if(j-1>=0 && vertexArray[(i)*n+j-1].value==1) vertexArray[i*n+j].adjacencyList.push_back((i)*n+j-1);
			
			if(i+1<m && j+1<n && vertexArray[(i+1)*n+j+1].value==1) vertexArray[i*n+j].adjacencyList.push_back((i+1)*n+j+1);
			if(i+1<m && j-1>=0 && vertexArray[(i+1)*n+j-1].value==1) vertexArray[i*n+j].adjacencyList.push_back((i+1)*n+j-1);
			if(i-1>=0 && j+1<n && vertexArray[(i-1)*n+j+1].value==1) vertexArray[i*n+j].adjacencyList.push_back((i-1)*n+j+1);
			if(i-1>=0 && j-1>=0 && vertexArray[(i-1)*n+j-1].value==1) vertexArray[i*n+j].adjacencyList.push_back((i-1)*n+j-1);
			
		}
	}
	printf("%d\n",findAnswer());
	return 0;
}
