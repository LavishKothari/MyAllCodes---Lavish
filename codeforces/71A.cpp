#include<bits/stdc++.h>
using namespace std;
string findAnswer(string str)
{
	if(str.size()<=10)
		return str;
	string s="";
	s.push_back(str[0]);
	int n=str.size()-2;
	while(n)
	{
		s.push_back(n%10+'0');
		n/=10;
	}
	s.push_back(str[str.size()-1]);
	reverse(s.begin()+1,s.end()-1);
	return s;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{

		string str;
		cin>>str;
		cout<<findAnswer(str)<<endl;
	}
	return 0;
}
