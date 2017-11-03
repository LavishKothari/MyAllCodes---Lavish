#include<bits/stdc++.h>
using namespace std;
bool is(vector<string>&a,vector<string>&b)
{
	set<string>s;
	for(int i=0;i<a.size();i++)
		s.insert(a[i]);
	int count=0;
	for(int i=0;i<b.size();i++)
	{
		if(s.find(b[i])!=s.end())
		{
			count++;
			s.erase(b[i]);
		}
	}
	return (count>=2);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<string>a(4),b(4);
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		cin>>b[0]>>b[1]>>b[2]>>b[3];

		if(is(a,b))
			cout<<"similar\n";
		else cout<<"dissimilar\n";
	}

	return 0;
}
