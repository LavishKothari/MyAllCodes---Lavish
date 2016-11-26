#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector< vector<int> >&mv,vector<int>&v,int current)
{
	if(mv.size()==1)
	{
		for(int i=0;i<v.size();i++)
			if(mv[0][i]!=v[i])
				return false;
		return true;
	}
	if(v.size()==current)
		return true;
	for(int i=0;i<mv.size();i++)
	{
		if(!mv[i].empty() && mv[i][0]==v[current])
		{
			mv[i].erase(mv[i].begin());
			if(isPossible(mv,v,current+1))
				return true;
			mv[i].insert(mv[i].begin(),v[current]);
		}
	}
	return false;
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
		reverse(output.begin(),output.end());
		isPossible(mv,output,0)?printf("Yes\n"):printf("No\n");
	}
	return 0;
}
