#include<bits/stdc++.h>
using namespace std;
bool sol(string &str)
{
	int phase=1;
	for(int i=0;i<str.size();i++)
	{
		if(phase==1 && str[i]=='C')
			continue;
		if(phase==1 && str[i]=='E')
		{
			phase++;
			continue;
		}
		if(phase==1 && str[i]=='S')
		{
			phase+=2;
			continue;
		}
		/////////////////////////////////////////////////
		if(phase==2 && str[i]=='E')
			continue;
		if(phase==2 && str[i]=='S')	
		{
			phase++;
			continue;
		}
		if(phase==3 && str[i]=='S')
			continue;
		return false;

	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		string str;
		cin>>str;
		if(sol(str))
			cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}
