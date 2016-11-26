#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int flag[26]={0};
	
	cin>>s;
	for(int i=0;i<s.size();i++)
		flag[s[i]-'a']=1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string test;
		cin>>test;
		int count=0;
		for(int i=0;i<test.size();i++)
			if(flag[test[i]-'a'])
				count++;
		if(count==test.size())
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
