#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9)+7;
typedef long long int ll;

ll findAnswer(const string &s)
{
	int n=s.size();
	vector<vector<ll> >dp(8,vector<ll>(n,0)); // initializing to 0
	dp[0][0]=1;
	dp[(s[0]-'0')%8][0]++;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<8;j++)
			dp[j][i]=dp[j][i-1];
		int x=(s[i]-'0')%8;
		for(int j=0;j<8;j++)
			dp[(x+j*10)%8][i]=(dp[(x+j*10)%8][i]+dp[j][i-1])%MOD;
	}
	/*
	   for(int i=0;i<dp.size();i++)
	   {
	   for(int j=0;j<dp[i].size();j++)
	   cout<<dp[i][j]<<" ";
	   cout<<endl;
	   }
	 */
	return (dp[0][n-1]-1+MOD)%MOD;
}

int main()
{
	int n;
	string s;
	cin>>n>>s;
	cout<<findAnswer(s)<<endl;
	return 0;
}
