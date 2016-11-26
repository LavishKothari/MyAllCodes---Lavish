#include<bits/stdc++.h>
using namespace std;
int findMinCap(string &s)
{
	int prev=-1,flag=0;
	int mini=0;
	int i;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y')
		{
			int diff=i-prev;
			if(mini<diff)
				mini=diff;
			flag=1;
			prev=i;
		}
	}

	if(flag)
	{
		int diff=i-prev;
		if(mini<diff)
			mini=diff;
		return mini;
	}
	return s.size()+1;
}
int main()
{
	string s;
	cin>>s;
	cout<<findMinCap(s)<<endl;
	return 0;
}
