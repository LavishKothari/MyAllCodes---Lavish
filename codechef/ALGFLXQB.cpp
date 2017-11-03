#include<bits/stdc++.h>
using namespace std;
int fa(string &s)
{
	int c=0,m=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
			c=0;
		else
		{
			c++;
			m=max(c,m);
		}
	}
	return m;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		cout<<fa(str)<<endl;
	}
	return 0;
}
