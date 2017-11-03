#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll sol(ll a,ll b)
{
	if(a==1)
		return b-1;
	if(b==1)
		return a-1;
	return 2*a*b-a-b;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,m;
		cin>>n>>m;
		cout<<sol(n,m)<<endl;
	}
	return 0;	
}
