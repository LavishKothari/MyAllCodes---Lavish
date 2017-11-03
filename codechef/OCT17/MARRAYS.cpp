#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
	template<class T>
T maxv(vector<T>&v)
{
	T mx=v[0];
	for(int i=0;i<v.size();i++)
		if(v[i]>mx)
			mx=v[i];
	return mx;
}
	template<class T>
T minv(vector<T>&v)
{
	T mn=v[0];
	for(int i=0;i<v.size();i++)
		if(v[i]<mn)
			mn=v[i];
	return mn;
}
ll solve(vector<vector<int> >&vv)
{
	int x,y,a,b,i,n=vv.size();
	if(n==2)
		return max(abs(maxv(vv[0])-minv(vv[1])) , abs(maxv(vv[1])-minv(vv[0])));
	else if(n==1)
		return 0;
	vector<ll> dp(vv[0].size(),0),newdp;
	ll answer=0;
	for(i=1;i<n;++i)
	{
		newdp=vector<ll>(vv[i].size(),0);
		for(a=0;a<dp.size();++a)
		{
			for(b=0;b<newdp.size();++b)
			{
				y=vv[i][b];
				x=vv[i-1][(a-1+dp.size())%dp.size()];
				newdp[b]=max(newdp[b],(ll)i*abs(x-y)+dp[a]);
				if(newdp[b]>answer)
					answer=newdp[b];
			}
		}
		dp = std::move(newdp);
	}
	return answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<vector<int> >vv(n);
		for(int i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);
			vv[i]=vector<int>(m);
			for(int j=0;j<m;j++)
				scanf("%d",&vv[i][j]);
		}
		printf("%lld\n",solve(vv));
	}
	return 0;
}
