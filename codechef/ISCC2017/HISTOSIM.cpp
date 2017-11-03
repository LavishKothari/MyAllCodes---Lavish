#include<bits/stdc++.h>
using namespace std;
bool containsAll(string &a)
{
	int flag[26]={0};
	for(int i=0;i<a.size();i++)
		flag[a[i]-'a']=1;
	int answer=0;
	for(int i=0;i<a.size();i++)
		answer+=flag[a[i]-'a'];
	if(answer==26)
		return true;
	return false;
}
bool check(string &a,string &b)
{
	map<int,int>m;
	for(int i=0;i<26;i++)
		m[i]=-1;
	for(int i=0;i<a.size();i++)
	{
		if(m[a[i]-'a']==-1)
			m[a[i]-'a']=b[i]-'a';
		else
		{
			if(b[i]-'a'!=m[a[i]-'a'])
				return false;
		}
	}
	return true;
}
bool solve(string &a,string &b)
{
	if(!check(a,b) ||  !check(b,a))
		return false;
	if(containsAll(a))
		return false;
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	string a,b;
	while(t--)
	{
		cin>>a>>b;
		if(solve(a,b))
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
