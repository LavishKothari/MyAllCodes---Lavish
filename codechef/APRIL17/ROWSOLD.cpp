#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll sol1(string &str)
{
	int z=0;ll answer=0;
	for(int i=str.size();i>=0;i--)
		if(str[i]=='0')
			z++;
		else answer+=z;
	int tc=0;
	for(int i=0;i<str.size()-1;i++)
		if(str[i]=='1' && str[i+1]=='0')
			tc++;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='1')
			answer+=tc;
		if(i+1<str.size() && str[i+1]=='0' && str[i]=='1')
			tc--;
	}
	return answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		printf("%lld\n",sol1(str));
	}
	return 0;
}
