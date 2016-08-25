#include<iostream>
#include<map>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	map<string,int>m;
	for(int i=0;i<s.size();i++)
		m[s.substr(i,s.size())]=i;
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
		cout<<it->second<<" ";
	return 0;
}

