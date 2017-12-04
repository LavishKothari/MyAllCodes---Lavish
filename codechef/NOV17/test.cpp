#include<bits/stdc++.h>
using namespace std;
struct C1
{
	bool operator()(const pair<int,int>&p1,const pair<int,int>&p2)	
	{
		if(p1.first==p2.first)
			return p1.first<p2.first;
		else
			return p1<p2;
	}
};
void insert_cust(set<pair<int,int>,C1 >&s,pair<int,int>&p)
{
	set<pair<int,int> >::iterator it = s.find(p);
	if(it!=s.end())
		s.erase(it);
	s.insert(p);
}
int main()
{
	set<pair<int,int>,C1>s;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);

		pair<int,int>tempP = make_pair(a,b);
		insert_cust(s,tempP);
	}
	cout<<"this is the final output:\n";
	for(auto it=s.begin();it!=s.end();it++)
		cout<<it->first<<" "<<it->second<<endl;


	return 0;
}
