#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll power(ll a,ll b,ll mod) // function for calculating power
{
	if(b==0) return 1;
	if(b==1) return a;
	ll temp=power(a,b/2,mod);
	ll t=(temp*temp)%mod;
	if(b&1)
		return (t*a)%mod;
	return t;
}

ll calculateE(ll n,ll p,ll pe) { // brute force for finding e
	ll e;
	for(e=0;e<n;e++)
	{
		if(power(p,e,n)==pe)
			return e;
	}
	return 0;
}
ll inv(ll a,ll b) // extended euclidean theorem
{
	ll cx,cy,px,py,pr,cr;
	cx=1;px=0;cy=0;py=1;cr=a;pr=b;
	while(pr!=1)
	{
		ll q=cr/pr;
		
		ll nr=cr-q*pr;
		ll nx=cx-q*px;
		ll ny=cy-q*py;
		
		cx=px;
		cy=py;
		cr=pr;
		
		px=nx;
		py=ny;
		pr=nr;
	}
	return (py+a)%a;
}
string convertToString(ll x)
{
	int d=x%31;
	x/=31;
	int c=x%31;
	x/=31;
	int b=x%31;
	x/=31;
	int a=x%31;
	
	string s;
	s.push_back(a+'a');
	s.push_back(b+'a');
	s.push_back(c+'a');
	s.push_back(d+'a');
	return s;
}
int main(){
	ll t,n,p,pe,e;
	cin>>t>>n>>p>>pe;
	e=calculateE(n,p,pe);
	
	while(t--)
	{
		ll c,pk;
		cin>>pk>>c;
		cout<<convertToString((c*inv(n,power(pk,e,n)))%n)<<" ";
	}
	return 0;
}
