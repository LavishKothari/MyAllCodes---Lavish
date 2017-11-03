#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n,d;
	cin>>n>>d;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n;i++)
		cout<<v[(i+d)%n]<<" ";
	cout<<endl;
	return 0;
}
