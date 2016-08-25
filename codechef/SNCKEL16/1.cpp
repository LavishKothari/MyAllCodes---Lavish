#include<iostream>
#include<vector>
#include<algorithm>
typedef long long int ll;
using namespace std;

bool find(ll a,ll b,ll c,ll d)
{
	if(b==0 || a==0)
		return false;
	if(c%a==0 && d%a==0 && c+d==a*b)
		return true;
	if(c%b==0 && d%b==0 && c+d==a*b)
		return true;
	return false;
}

bool findAnswer(ll a,ll b,ll c,ll d,ll e)
{
	bool p=false;
	if(c%a==0)
	{
		int x=c/a;
		p= p || find(a,b-x,d,e);
	}
	if(d%a==0)
	{
		int x=d/a;
		p = p || find(a,b-x,c,e);
	}
	if(e%a==0)
	{
		int x=e/a;
		p = p || find(a,b-x,d,c);
	}
	
	if(c%b==0)
	{
		int x=c/b;
		p = p || find(b,a-x,d,e);
	}
	if(d%b==0)
	{
		int x=d/b;
		p = p || find(b,a-x,c,e);	
	}
	if(e%b==0)
	{
		int x=e/b;
		p = p || find(b,a-x,d,c);		
	}
	return p;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		bool x=findAnswer(a,b,c,d,e);
		if((c+d+e)==(a*b) && x)
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
