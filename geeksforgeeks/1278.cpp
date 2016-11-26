/*
	problem link : http://www.practice.geeksforgeeks.org/problem-page.php?pid=1278
*/
#include <bits/stdc++.h>

using namespace std;
vector<string>result;
void printall(string current,int start,vector< vector<int> >&graph,string &s)
{
	if(start==graph.size()-1)
		result.push_back(current.substr(0,current.size()-1));
	else 
		for(int i=0;i<graph[start].size();i++)
			printall(current+s.substr(start+1,graph[start][i]-start)+" ",graph[start][i],graph,s);
		
}
void printAllPossible(string &s,set<string>&dict)
{
	vector< vector<int> >table(s.size(),vector<int>());
	for(int i=0;i<s.size();i++)
	{
		if(/*table[i].size()==0 && */dict.find(s.substr(0,i+1))!=dict.end())
			table[i].push_back(-1);
		if(table[i].size()!=0)
			for(int j=i+1;j<s.size();j++)
				if(dict.find(s.substr(i+1,j-i))!=dict.end())
					table[j].push_back(i);
	}
	
	if(table[s.size()-1].size()==0)
	{
		cout<<"Empty"<<endl;
		return;
	}

	// constructing the complement of the graph.
	vector< vector<int> >graph(s.size(),vector<int>());
	vector<int> start;
	for(int i=0;i<s.size();i++)
		for(int j=0;j<table[i].size();j++)
			if(table[i][j]!=-1)
				graph[table[i][j]].push_back(i);
			else start.push_back(i);

	for(int i=0;i<start.size();i++)
		printall(s.substr(0,start[i]+1)+" ",start[i],graph,s);
	sort(result.begin(),result.end());
	for(int i=0;i<result.size();i++)
		cout
		<<"("<<result[i]<<")";
	cout<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		result.erase(result.begin(),result.end());
		int n;
		scanf("%d",&n);
		set<string>dict;
		for(int i=0;i<n;i++)
		{
			string temp;
			cin>>temp;
			dict.insert(temp);
		}
		string str;
		cin>>str;
		printAllPossible(str,dict);
	}
	return 0;
}

/*
Input:
9
x
i
like
man
go
mango
easy
mangoeasy
likemangoeasyx
ilikemangoeasyx

Output:
(i like man go easy x)
(i like mango easy x)
(i like mangoeasy x)
(i likemangoeasyx)

/////////////////////////////////////////////
Input:
4
qscdx mowfr qscdxmowfr jy 
qscdxmowfrqscdxmowfrqscdxmowfrmowfrqscdxmowfr

Output: (in one single line)
(qscdx mowfr qscdx mowfr qscdx mowfr mowfr qscdx mowfr)
(qscdx mowfr qscdx mowfr qscdx mowfr mowfr qscdxmowfr)
(qscdx mowfr qscdx mowfr qscdxmowfr mowfr qscdx mowfr)
(qscdx mowfr qscdx mowfr qscdxmowfr mowfr qscdxmowfr)
(qscdx mowfr qscdxmowfr qscdx mowfr mowfr qscdx mowfr)
(qscdx mowfr qscdxmowfr qscdx mowfr mowfr qscdxmowfr)
(qscdx mowfr qscdxmowfr qscdxmowfr mowfr qscdx mowfr)
(qscdx mowfr qscdxmowfr qscdxmowfr mowfr qscdxmowfr)
(qscdxmowfr qscdx mowfr qscdx mowfr mowfr qscdx mowfr)
(qscdxmowfr qscdx mowfr qscdx mowfr mowfr qscdxmowfr)
(qscdxmowfr qscdx mowfr qscdxmowfr mowfr qscdx mowfr)
(qscdxmowfr qscdx mowfr qscdxmowfr mowfr qscdxmowfr)
(qscdxmowfr qscdxmowfr qscdx mowfr mowfr qscdx mowfr)
(qscdxmowfr qscdxmowfr qscdx mowfr mowfr qscdxmowfr)
(qscdxmowfr qscdxmowfr qscdxmowfr mowfr qscdx mowfr)
(qscdxmowfr qscdxmowfr qscdxmowfr mowfr qscdxmowfr)

*/
