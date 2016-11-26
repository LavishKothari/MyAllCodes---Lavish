#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<string>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int i=0;
	for(i=0;i<n;i++)
	{
		if(v[i][0]=='O' && v[i][1]=='O')
		{
			v[i][0]=v[i][1]='+';
			break;	
		}
		else if(v[i][3]=='O' && v[i][4]=='O')
		{
			v[i][3]=v[i][4]='+';
			break;	
		}
	}
	if(i==n)
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int j=0;j<n;j++)
			cout<<v[j]<<endl;
	}
	return 0;
}
