#include<bits/stdc++.h>
using namespace std;
void sol(string &s)
{
	int answer=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='1' && s[i]!='0')
			continue;
		if(s[i]=='1')
		{
			i++;int flag=0;
			while(i<s.size() && s[i]=='0')
			{
				flag=1;
				i++;
			}
			if(flag && i<s.size() && s[i]=='1')
				answer++;
			if(flag) 
				i--;
			continue;
		}
	}
	printf("%d\n",answer);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		sol(s);
	}
	return 0;
}
