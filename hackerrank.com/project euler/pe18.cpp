#include <bits/stdc++.h>

using namespace std;
int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<vector<int> >v(n);
		for(int i=0;i<n;i++)
		{
			v[i]=vector<int>(i+1);
			for(int j=0;j<i+1;j++)
				cin>>v[i][j];
		}
		int m=v[0][0];
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				if(j-1>=0 && j<v[i-1].size())
					v[i][j]+=max(v[i-1][j],v[i-1][j-1]);
				else if(j<v[i-1].size()) 
					v[i][j]+=v[i-1][j];
				else v[i][j]+=v[i-1][j-1];
				m=max(m,v[i][j]);
			}
		}
		cout<<"++++++++++++++++++++"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<v[i].size();j++)
				cout<<v[i][j]<<" ";
			cout<<endl;
		}
		cout<<"++++++++++++++++++++"<<endl;
		cout<<m<<endl;
	}
	return 0;
}
