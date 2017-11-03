#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int>answer;
int cost(int c,string&s,vector<vector<int> >&h) // a recursive solution that gives TLE
{
	if(c<s.size() && answer[c]!=-1)
		return answer[c]; // memoization (using already computed value)
	if(c>=s.size()-1)
	{
		answer[c]=0;
		return 0;
	}	
	int mini=INT_MAX;
	mini=min(mini,cost(c+1,s,h)+abs(s[c]-s[c+1]));
	for(int i=0;i<h[s[c]-'a'].size();i++)
	{
		int index = h[s[c]-'a'][i];
		if(index<=c)
			continue;
		mini = min(mini,cost(index,s,h));
	}
	isVisited[s[c]-'a']=true;
	answer[c]=mini;
	return mini;
}
class Node
{
	public:
		int dist;
		int number;
		Node(int i,int d=INT_MAX)
		{
			dist=d;
			number=i;
		}
		bool operator<(Node&a)
		{
			if(dist!=a.dist)
				return dist<a.dist;
			else return number<a.number;
		}
};
int solve(string &s,vector<vector<int> >&h)
{
	set<Node>s;
	for(int i=0;i<s.size;s++)
	{
		if(i==0) s.insert(Node(i,0));
		else s.insert(Node(i));
	}
	while(!s.empty())
	{
		Node current = *(s.begin());
		s.erase(s.begin());

		for(int i=0;i<h[current.number].size();i++)
	}
}
int main()
{
	int t;string s;
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		/*
		   answer=vector<int>(s.size(),-1);
		   vector<vector<int> >h(26);
		   for(int i=0;i<s.size();i++)
		   h[s[i]-'a'].push_back(i);
		   printf("%d\n",cost(0,s,h));
		 */
		printf("%d\n",solve(s));
	}
	return 0;
}
