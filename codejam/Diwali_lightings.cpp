#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll till(string &s,ll a)
{
	ll count=0;
	for(int i=0;i<=a && i<s.size();i++)
		if(s[i]=='B')
			count++;
	return count;
}
ll from(string &s,ll a)
{
	ll count=0;
	for(int i=a;i<s.size();i++)
		if(s[i]=='B')
			count++;
	return count;
}
ll between(string&s,ll a,ll b)
{
	ll count=0;
	for(int i=a;i<=b && i<s.size();i++)
		if(s[i]=='B')
			count++;
	return count;
}
ll findAnswer(string &s,ll a,ll b)
{
	int n=s.size();
	if(a/n == b/n)
		return between(s,a%n,b%n);
	ll answer = from(s,a%n) + till(s,b%n);
	ll x = b/n+1 - (a/n+1) -1;	
	return x*till(s,n-1)+answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	int i=0;
	while(t--)
	{
		string str;ll a,b;
		cin>>str>>a>>b;
		cout<<"Case #"<<i+1<<": "<<findAnswer(str,a-1,b-1)<<endl;
		i++;
	}
	return 0;
}
