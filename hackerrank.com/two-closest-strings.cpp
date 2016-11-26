#include<bits/stdc++.h>
using namespace std;
string findString(string&s,int k)
{
	int myk=0;
	string mys=s;
	if(k==0)
		return mys;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='a')
		{
			myk++;
			mys[i]='a';
		}
		if(myk==k)
			return mys;
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='a')
		{
			myk++;
			mys[i]='b';
		}
		if(myk==k)
			return mys;
	}
	return mys;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		string s;
		cin>>s>>k;
		s=findString(s,k);
		cout<<s<<endl;
	}
	return 0;
}
