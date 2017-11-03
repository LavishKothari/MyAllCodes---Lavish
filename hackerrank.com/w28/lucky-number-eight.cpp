#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int ll;

ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll temp = power(a,b/2);
	if(b&1)
		return (((temp*temp)%MOD)*a)%MOD;
	return (temp*temp)%MOD;
}

ll findAnswer(string &str)
{
	int n=str.size();
	ll answer=0;

	for(int i=0;i<n;i++)
		if(str[i]=='8' || str[i]=='0')
			answer=(answer+1)%MOD;

	for(int i=n-1;i>=0;i--)
	{
		if((str[i]-'0')&1)
			continue;
		for(int j=i-1;j>=0;j--)
		{
			if(((str[j]-'0')*10 + (str[i]-'0'))%8==0)
			{
				answer=(answer+1)%MOD;
			}
		}
	}


	for(int i=n-1;i>=0;i--)
	{
		if((str[i]-'0')&1)
			continue;
		for(int j=i-1;j>=0;j--)
		{
			if((((str[j]-'0')*10 + (str[i]-'0'))%4!=0))
				continue;
			for(int k=j-1;k>=0;k--)
			{
				int num = (str[k]-'0')*100 + (str[j]-'0')*10 + (str[i]-'0');
				if(num%8 == 0)
				{
					answer = (answer+power(2,k))%MOD;
				}
			}
		}
	}
	return answer;
}

int main()
{
	int n;
	scanf("%d",&n);
	string str;
	cin>>str;
	cout<<findAnswer(str)<<endl;
	return 0;
}
