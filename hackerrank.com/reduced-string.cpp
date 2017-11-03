#include <bits/stdc++.h>
using namespace std;
void reduceall(string &s)
{

	int n=s.size();
	for(int i=0;i<n;i++)
		for(int j=1;j<s.size();j++)
			if(s[j-1]==s[j])
				s.erase(s.begin()+j-1,s.begin()+j+1);
	if(s.size()==0)
		cout<<"Empty String"<<endl;
	else cout<<s<<endl;
}
int main()
{
	string s;
	cin>>s;
	reduceall(s);
	return 0;
}
