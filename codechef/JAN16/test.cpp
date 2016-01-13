#include<stdio.h>
#include<vector>
#include<set>
#include<map>
using namespace std;
int findBlocks(vector<int>x,vector<int>y) // this function finds the number of blocks
{
	map<int,set<int> >graph;
	for(int i=0;i<x.size();i++)
	{
		graph[x[i]].insert(y[i]);
		graph[y[i]].insert(x[i]);
	}
	int degree1=0,degree2=0;
	for(map<int,set<int> >::iterator it=graph.begin();it!=graph.end();it++)
	{
		printf("%d %d\n",it->first,(it->second).size());
		if((it->second).size()==1)
			degree1++;
		else if((it->second).size()==2)
			degree2++;
		else if((it->second).size()>2)
			return -1;
	}
	int blocks=0;
	while(true)
	{
		map<int,set<int> >::iterator it;
		for(it=graph.begin();graph.size()!=0 && it!=graph.end();it++)
		{
			if((it->second).size()==1)
				break;
		}
		if(it==graph.end() || graph.size()==0)
			break;
		else
		{
			// here 'it' is the iterator to the vertex of degree 1
			blocks++;
			while(true)
			{
				
				map<int,set<int> >::iterator nextit=graph.find(*((it->second).begin()));
				if(nextit==graph.end())
					break;
				int key=it->first;
				int temp=*((it->second).begin());
				graph[temp].erase(key);
				graph.erase(it);
				//it=graph.find(temp);
				it=nextit;
				printf("%d-->%d\n",it->first,(it->second).size());
				/*
				if((it->second).size()==0)
				{
					graph.erase(it);
					break;
				}
				*/
			}
			
		}
	}
	if(graph.size()!=0)
		return -1;
	if(blocks==0)
		return -1;
	return blocks;
}

int main1()
{
	vector<int>p,q;
	p.push_back(1);
	p.push_back(2);
	p.push_back(3);
	
	q.push_back(2);
	q.push_back(3);
	q.push_back(4);
	
	printf("this is the number of blocks %d\n",findBlocks(p,q));
	return 0;
}
int main()
{
	int *arr=new int[0];
	
	return 0;
}
