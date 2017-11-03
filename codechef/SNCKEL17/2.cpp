#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll temp = power(a,b/2);
	if(b&1)
		return (temp*temp*a)%MOD;
	else return (temp*temp)%MOD;
}



ll fun(int n, vector<ll> &a) {


	ll ans = a[0];
	if(n==1)
		return ans;
	ll plus=0,mul=0;

	ll prev = a[0];
	plus = (a[0]+a[1]);
	mul = (a[0]*a[1]);
	int n1= n;
	n=n/2;
	for(int i=2; i<n1; i++) {
		ll temp1 = (plus+a[i])*(n/2);
		ll temp2 = (mul+a[i])*(n/2);
		ll temp3 = (mul*a[i])*(n/2);
		ll temp4 =(prev+a[i]*a[i-1])*(n/2);
		prev = plus+mul;
		plus = temp1+temp2;
		mul = temp3+temp4;
		n = n/2;
	}
	return (plus+mul);
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<ll>arr(n);
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		//cout<<fun(arr.size(),arr)<<endl;
		ll m=power(2,arr.size()-1);
		cout<<sol(2,arr,arr[0]+arr[1],arr[0]*arr[1],arr[0],m/2);
	}
	return 0;
}
