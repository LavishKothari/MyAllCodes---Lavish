#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#define N 40

using namespace std;

int runPrims(int**mat)
{
	set<int>S;
	S.insert(0);
	int sum=0;
	for(int i=0;i<N-1;i++)
	{
		int minEdge=2147483647;
		int end,start;
		for(set<int>::iterator it=S.begin();it!=S.end();it++)
		{
			int currentVertex=(*it);
			for(int j=0;j<N;j++)
			{
				if(mat[currentVertex][j]!=0 && minEdge>mat[currentVertex][j] && find(S.begin(),S.end(),j)==S.end())
				{
					minEdge=mat[currentVertex][j];
					end=j;
					start=currentVertex;
				}
			}
		}
		sum+=minEdge;
		S.insert(end);
		printf("choosing %d %d %d\n",start,end,minEdge);
	}
	return sum;
}

int main()
{
	FILE*fp;
	fp=fopen("a.txt","r");
	char str[1000];
	int **mat;
	
	mat=(int**)malloc(sizeof(int*)*N);
	for(int i=0;i<40;i++)
		mat[i]=(int*)malloc(sizeof(int)*N);
		
	for(int i=0;i<N;i++)
	{
		fscanf(fp," %s",str);
		printf("%s\n",str);
		int counter=0;
		for(int j=0;j<N;j++)
		{
			if(str[counter]=='-')
			{
				counter++;
				mat[i][j]=0;
				continue;
			}
			if(str[counter]==',')
			{
				j--;
				counter++;
				continue;
			}
			int sum=0;
			while(str[counter] && str[counter]!=',')
			{
				sum=sum*10+str[counter++]-'0';
			}
			mat[i][j]=sum;
		}
		
	}
	int total_weight=0;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			total_weight+=mat[i][j];
	
	
	printf("%d %d\n",total_weight/2-runPrims(mat),runPrims(mat));
	return 0;
}
