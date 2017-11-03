#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll makeNumber(vector<int>&v,int x,int y)
{
	ll answer=0;
	for(int i=x;i<=y;i++)
		answer=answer*10+v[i];
	return answer;
}
set<ll>answerset;
ll split(vector<int>&v)
{
	int n=v.size();
	ll answer=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;v[i]!=1 && v[j]!=1 && j<n;j++)
		{
			ll x=makeNumber(v,0,i);
			ll y=makeNumber(v,i+1,j);
			ll z=makeNumber(v,j+1,n-1);
			if(x*y==z && answerset.find(z)==answerset.end())
			{
				answer+=z;
				answerset.insert(z);
			}
		}
	}
	return answer;
}

ll findAnswer(int n)
{
	vector<int>v(n);
	ll answer=0;
	for(int i=1;i<=n;i++)
		v[i-1]=i;
	do{
		answer+=split(v);
	}
	while(next_permutation(v.begin(),v.end()));
	return answer;
}
int main()
{
	int n;
	cin>>n;
	cout<<findAnswer(n)<<endl;
	return 0;
}
