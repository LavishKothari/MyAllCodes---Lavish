#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)	
{
	if(n<=1)
		return false;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<vector<int> >v(n,vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&v[i][j]);
	int answer=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int t=0;
			if(i-1>=0) t+=v[i-1][j];
			if(j-1>=0) t+=v[i][j-1];
			if(i+1<n) t+=v[i+1][j];
			if(j+1<n) t+=v[i][j+1];
			if(isPrime(t))
				answer++;
		}
	printf("%d\n",answer);
	return 0;
}
