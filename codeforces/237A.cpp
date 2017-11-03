#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>count(23+59*60+1,0);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		count[b*60+a]++;
	}
	cout<<*max_element(count.begin(),count.end())<<endl;
	return 0;
}
