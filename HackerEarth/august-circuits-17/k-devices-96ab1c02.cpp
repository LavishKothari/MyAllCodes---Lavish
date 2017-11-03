#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll getAnswer(ll n){
	int x=sqrt(n);
	if(x*x==n)
		return x;
	return x+1;
}
void solve(vector<ll>&x,vector<ll>&y,int k)
{
	vector<ll>dist(x.size());
	for(int i=0;i<dist.size();i++)
		dist[i]=x[i]*x[i]+y[i]*y[i];
	sort(dist.begin(),dist.end());
	printf("%lld\n",getAnswer(dist[k-1]));
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	vector<ll>x(n);
	vector<ll>y(n);


	for(int i=0;i<n;i++)
		scanf("%lld",&x[i]);

	for(int i=0;i<n;i++)
		scanf("%lld",&y[i]);
	solve(x,y,k);
	return 0;
}
