#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll value(const string &s)
{
	ll answer=0;
	for(int i=0;i<s.size();i++)
		answer+=s[i];
	return answer-('A'-1)*s.size();
}
int main()
{
	int n;
	cin>>n;
	vector<string >v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	map<string,ll>m;
	for(int i=0;i<n;i++)
		m[v[i]]=value(v[i])*(i+1);
	
	int q;
	cin>>q;
	while(q--)
	{
		string temp;
		cin>>temp;
		cout<<m[temp]<<endl;
	}
	return 0;
}
