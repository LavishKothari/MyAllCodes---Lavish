#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void sol(vector<ll>&v)
{
	ll n=v.size();
	ll firstIndex = -1;
	ll answer=0;
	sort(v.begin(),v.end());
	ll counter=0;
	int flag=1;
	for(int i=0;i<v.size();i++)
		if(v[i]>=0)
		{
			if(flag)
			{
				flag=0;
				firstIndex=i;
			}
			counter++;
			answer+=v[i];
		}
	ll sum = answer;
	ll ns=0;
	for(int i=0;i<n;i++)
		if(v[i]<0)
			ns+=v[i];
	for(int i=firstIndex-1;i>=0;i--)
	{
		ll prevanswer = sum*counter+ns;
		ll currentanswer=(sum+v[i])*(counter+1)+ns-v[i];
		if(currentanswer > prevanswer)
		{
			sum += v[i];
			counter++;
			ns = ns-v[i];
		}
	}
	printf("%lld\n",sum*counter+ns);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<ll>v(n);
		for(int i=0;i<n;i++)
			scanf("%lld",&v[i]);
		sol(v);
	}

	return 0;
}
