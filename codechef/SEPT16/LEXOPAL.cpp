#include<bits/stdc++.h>
using namespace std;
bool doUpdate(string &str)
{
	int i,j;
	for(i=0,j=str.size()-1;i<=j;i++,j--)
	{
		if(str[i]==str[j] && str[i]=='.')
			str[i]=str[j]='a';
		else if(str[i]!=str[j] && (str[i]=='.' || str[j]=='.'))
		{
			if(str[i]=='.')
				str[i]=str[j];
			else str[j]=str[i];
		}
		else if(str[i]!=str[j])
			return false;
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		doUpdate(str)?cout<<str<<endl:cout<<"-1\n";
	}
}
