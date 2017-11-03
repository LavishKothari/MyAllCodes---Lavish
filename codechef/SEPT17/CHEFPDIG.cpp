#include<bits/stdc++.h>
using namespace std;
void sol(string &str)
{
	int count[10]={0};
	for(int i=0;i<str.size();i++)
		count[str[i]-'0']++;
	bool flag[26]={0};
	for(int i='A';i<='Z';i++)
	{
		int x=i%10,y=i/10;
		if(x==y)
		{
			if(count[x]>1)
				flag[i-'A']=true;
		}
		else
		{
			if(count[x] && count[y])
				flag[i-'A']=true;
		}
	}
	for(int i=0;i<26;i++)
		if(flag[i])
			cout<<(char)(i+'A');
	cout<<endl;
}
int main()
{
	int t;
	scanf("%d",&t);
	string str;
	while(t--)
	{
		cin>>str;
		sol(str);
	}
	return 0;
}

