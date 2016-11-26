#include <bits/stdc++.h>

using namespace std;

int isPossible(string &s,set<string>&dict)
{
	vector<bool>table(s.size(),false);
	for(int i=0;i<s.size();i++)
	{
		if(table[i]==false && dict.find(s.substr(0,i+1))!=dict.end())
			table[i]=true;
		if(table[i])
			for(int j=i+1;j<s.size();j++)
				if(dict.find(s.substr(i+1,j-i))!=dict.end())
					table[j]=true;
	}
	for(int i=0;i<s.size();i++)
		cout<<"i = "<<i<<" and dp[i] = "<<table[i]<<endl;
	return (int)table[s.size()-1];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		set<string>dict;
		for(int i=0;i<n;i++)
		{
			string temp;
			cin>>temp;
			dict.insert(temp);
		}
		string str;
		cin>>str;
		cout<<isPossible(str,dict)<<endl;
	}
	return 0;
}

/*
	11
	a
	ab
	abc
	defg
	defgh
	defghi
	defghijkl
	defghij
	defghijk
	abcde
	fghijklzz
	abcdefghijklzz
*/