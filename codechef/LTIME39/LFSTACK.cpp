#include<bits/stdc++.h>
using namespace std;
int find(vector<int>&v,vector<bool>&isVisited,int value,int start,int end)
{
	for(int i=end-1;i>=start;i--)
	{
		if(v[i]==value && isVisited[i]==false)
			return i;
	}
	return -1;
}
bool isPossible(vector< vector<int> >&mv,vector<int>&v)
{
	vector<bool>isVisited(v.size(),false);
	for(int i=0;i<mv.size();i++)
	{
		int previndex=-1;
		int start=0,end=v.size();
		for(int j=mv[i].size()-1;j>=0;j--)	
		{
			int index=find(v,isVisited,mv[i][j],start,end);
			if(index==-1)
				return false;
			if(previndex>=index)
				return false;
			start=index+1;
			isVisited[index]=true;
		}
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n; // number of threads
		vector< vector<int> >mv;
		int total_ele=0;
		for(int i=0;i<n;i++)
		{
			int ai;
			cin>>ai; // elements in ith thread
			total_ele+=ai;
			mv.push_back(vector<int>(ai));
			for(int j=0;j<ai;j++)
				cin>>mv[i][j];
		}
		vector<int>output(total_ele);
		for(int i=0;i<total_ele;i++)
			cin>>output[i];
		isPossible(mv,output)?printf("Yes\n"):printf("No\n");
	}
	return 0;
}
