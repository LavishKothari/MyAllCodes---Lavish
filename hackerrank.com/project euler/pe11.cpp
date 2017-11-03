#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll findAnswer(vector<vector<ll> >&v)
{
	int n=v.size();
	ll answer=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j+3<n)
				answer = max(answer,v[i][j]*v[i][j+1]*v[i][j+2]*v[i][j+3]);
			if(i+3<n)
				answer = max(answer,v[i][j]*v[i+1][j]*v[i+2][j]*v[i+3][j]);
			if(i+3<n && j+3<n)
				answer = max(answer,v[i][j]*v[i+1][j+1]*v[i+2][j+2]*v[i+3][j+3]);
			if(i-3>=0 && j+3<n)
				answer = max(answer,v[i][j]*v[i-1][j+1]*v[i-2][j+2]*v[i-3][j+3]);
		}
	}
	return answer;
}
int main()
{
	int n=20;
	vector<vector<ll> >m(n,vector<ll>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>m[i][j];
	cout<<findAnswer(m)<<endl;
	return 0;

}