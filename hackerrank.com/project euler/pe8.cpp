#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll findAnswer(string str,int n,int k)
{
	ll m=0;
	for(int i=0;i<n && i+k-1<n;i++)
	{
		ll prod=1;
		for(int j=0;j<k;j++)
			prod = prod*(str[i+j]-'0');
		m=max(m,prod);
	}
	return m;
}

int main()
{
	string str;
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>str;
		cout<<findAnswer(str,n,k)<<endl;
	}
	return 0;
}