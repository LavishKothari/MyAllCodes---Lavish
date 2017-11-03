#include<bits/stdc++.h>
using namespace std;
void sol(int n,int k,vector<vector<int> >&v)
{
	{ // for sad
		vector<bool>isc(k,false);
		for(int i=0;i<n;i++)
			for(int j=0;j<v[i].size();j++)
				isc[v[i][j]]=true;
		for(int i=0;i<k;i++)
			if(!isc[i])
			{
				cout<<"sad\n";
				return;
			}
	}

	vector<int>keleset(k,-1),kelecount(k,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			int e=v[i][j];
			keleset[e]=i;
			kelecount[e]++;
		}
	}
	set<int>s;
	for(int i=0;i<k;i++)
		if(kelecount[i]==1)
			s.insert(keleset[i]);
	if(s.size()==n)
		cout<<"all\n";
	else cout<<"some\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<vector<int> >v(n,vector<int>());
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			while(x--)
			{
				int y;cin>>y;y--;
				v[i].push_back(y);
			}
		}
		sol(n,k,v);
	}
	return 0;
}
