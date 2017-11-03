#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

bitset<MAX+1>isPrime;
vector<int>lpd(MAX+1,-1);

void populatePrimes()
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	lpd[0]=lpd[1]=1;
	for(int i=2;i*i<=MAX;i++)
	{
		if(isPrime[i])
		{
			lpd[i]=i;
			for(int j=i*i;j<=MAX;j+=i)
			{
				isPrime[j]=0;
				if(lpd[j]==-1)
					lpd[j]=i;
			}
		}
	}
	for(int i=0;i<=MAX;i++)
	{
		if(isPrime[i])
			lpd[i]=i;
		//cout<<i<<"->"<<lpd[i]<<"->"<<isPrime[i]<<endl;
	}
}
int main()
{
	int t;
	populatePrimes();
	//return 0;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int>a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		int type,l,r;
		for(int i=0;i<m;i++)
		{
			cin>>type>>l>>r;
			l--;r--;
			if(type==0)
			{
				for(int j=l;j<=r;j++)
				{
					a[j]=a[j]/lpd[a[j]];
				}
			}
			else if(type==1)
			{
				int max_lpd=1;
				for(int j=l;j<=r;j++)
					max_lpd=max(lpd[a[j]],max_lpd);
				cout<<max_lpd<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
