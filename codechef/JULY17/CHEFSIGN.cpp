#include<bits/stdc++.h>
using namespace std;
int findContigous(string str,int start)
{	
	int i;
	for(i=start+1;i<str.size() && str[i]==str[start];i++);
	return i-1;
}
int solve(string &s)
{
	if(s.size()==0)
		return 1;
	int mx=INT_MIN;
	for(int i=0;i<s.size();)
	{
		int len=findContigous(s,i)-i+1;
		mx=max(len,mx);
		i+=len;
	}
	return mx+1;
}
int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		string str,s;
		cin>>str;
		for(int i=0;i<str.size();i++)
			if(str[i]!='=')
				s.push_back(str[i]);
		printf("%d\n",solve(s));
	}
	return 0;
}
