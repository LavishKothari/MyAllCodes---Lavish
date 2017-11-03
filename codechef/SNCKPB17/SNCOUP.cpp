#include<bits/stdc++.h>
using namespace std;
void sol(vector<string>&s)
{
	bool flag1=false,flag2=false;
	for(int i=0;i<s[0].size();i++)
	{
		if(s[0][i]=='*')
			flag1=true;
		if(s[1][i]=='*')
			flag2=true;
	}
	int answer=0;
	if(flag1 && flag2)
		answer=1;
	flag1=flag2=false;
	bool drawline=false;
	for(int i=0;i<s[1].size();i++)
	{
		if(drawline && (s[0][i]=='*' || s[1][i]=='*'))
		{
			answer++;

			drawline=flag1=flag2=false;
			if(s[0][i]=='*')
				flag1=true;
			if(s[1][i]=='*')
				flag2=true;
		}

		if(flag1==true && s[0][i]=='*')
		{
			answer++;
			flag2=false;
			drawline=false;
			continue;
		}
		if(flag2==true && s[0][i]=='*')
		{
			answer++;
			flag1=false;
			drawline=false;
			continue;
		}

		if(s[0][i]=='*')
			flag1=1;
		if(s[1][i]=='*')
			flag2=1;
		if(flag1 && flag2)
			drawline=true;
	}
	cout<<answer<<endl;
}
int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<string> s(2);
		cin>>s[0];
		cin>>s[1];

		sol(s);
	}

	return 0;
}
