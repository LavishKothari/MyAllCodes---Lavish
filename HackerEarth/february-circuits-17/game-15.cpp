#include<bits/stdc++.h>
using namespace std;
int sol(vector<pair<int,int> >&v,int N)
{
	int n=v.size();
	if(n==0 || n==1 || n==2)
		return N;
	vector<pair<int,int> >vf;

	int prev=v[0].first;
	int number = 1<<v[0].second;
	for(int i=1;i<n;i++)
	{
		int curr=v[i].first;
		if(prev==curr)
			number+=(1<<v[i].second);
		else
		{
			vf.push_back(make_pair(v[i-1].first,number));
			prev=v[i].first;
			number = 1<<v[i].second;
		}
	}
	vf.push_back(make_pair(v[n-1].first,number));
	/*
	   cout<<"This is vf:\n";
	   for(int i=0;i<vf.size();i++)
	   cout<<vf[i].first<<" "<<vf[i].second<<endl;
	   cout<<"vf ends here\n";
	 */
	for(int i=0;i<vf.size();i++)
	{
		if(vf[i].second==7)
			return vf[i].first-1;
		if(i+1<vf.size() && vf[i].first==vf[i+1].first-1 && ((vf[i].second==3 && vf[i+1].second==6) || vf[i].second==6 && vf[i+1].second==3))
			return vf[i].first;
	}
	return N;
}
bool dfs(set<pair<int,int> >&vis,int i,int j,vector<pair<int,int> >&v)
{ 
	if(j==3)
		return true;

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector<pair<int,int> >v;
		for(int i=0;i<q;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v.push_back(make_pair(x,y-1));
		}
		sort(v.begin(),v.end());
		cout<<sol(v,n)<<endl;
	}

	return 0;
}
