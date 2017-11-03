#include<bits/stdc++.h>
using namespace std;
int sol(string &s)
{
	vector<pair<int,int> >vp(26);
	for(int i=0;i<26;i++)
		vp[i]=make_pair(-1,-1);
	for(int i=0;i<s.size();i++)
	{
		int ind=s[i]-'a';
		if(vp[ind].first==-1)
			vp[ind].first=i;
		else vp[ind].second=i;
	}
	int m=-1;
	for(int i=0;i<26;i++)
		if(vp[i].first!=-1 && vp[i].second!=-1)
			m=max(m,vp[i].second-vp[i].first);
	if(m!=-1)
		return m-1;
	return m;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		cout<<sol(s)<<endl;
	}
	return 0;
}
