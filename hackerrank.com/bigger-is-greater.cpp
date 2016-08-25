#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		vector<char>v;
		for(int i=0;i<str.size();i++)
			v.push_back(str[i]);
		if(next_permutation(v.begin(),v.end()))
			for(int i=0;i<str.size();i++)
				cout<<v[i];
		else cout<<"no answer";
		cout<<endl;	
	}
	return 0;
}
