#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		if(str.size()==1)
			cout<<"Yes\n";
		else
		{
			int c1,c0;
			c1=c0=0;
			for(int i=0;i<str.size();i++)
				if(str[i]=='1')
					c1++;
				else c0++;
			(c1==1 || c0==1)?cout<<"Yes\n":cout<<"No\n";
		}
	}
}
