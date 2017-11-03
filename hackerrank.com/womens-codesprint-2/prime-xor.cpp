#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define N 10000
#define MOD 1000000007
bitset<N>isPrime;

void populatePrimes()
{
	isPrime.reset();
	isPrime.flip();

	isPrime[0]=isPrime[1]=0;
	for(int i=2;i*i<N;i++)
		if(isPrime[i])
			for(int j=i*i;j<N;j+=i)
				isPrime[j]=0;
}

vector<ll>result(8192);	 // for storing the result
void countSubsetXOR(vector<int> &arr, int n,vector<int>&countarray)
{
	int ma = INT_MIN;
	for (int i=0; i<n; i++)
		ma=max(ma,arr[i]);
	int m=(1<<(int)(log2(ma)+1))-1;
	ll dp[2][m+1];

	for (int j=0;j<=m;j++)
	{
		dp[0][j]=0;
		dp[1][j]=0;
	}
	dp[0][0]=1;
	dp[1][0]=1;
	int flag=1;
	for (int i=1;i<=n;i++)
	{
		ll taking,nottaking;
		ll cnt=countarray[arr[i-1]];

		if(cnt&1)
		{
			taking=((cnt-1)/2+1+MOD)%MOD;
			nottaking=((cnt-1)/2+1+MOD)%MOD;
		}
		else 
		{
			taking=(cnt/2)%MOD;
			nottaking=(cnt/2+1)%MOD;
		}
		//////////////////////////////////////
		//cout<<"current : ";
		for(int j=0;j<=m;j++)
		{	
			ll x;
			x=(dp[flag^1][j]*nottaking)%MOD;
			//cout<<"*"<<x<<endl;
			ll y=(dp[flag^1][j^arr[i-1]]*taking)%MOD; // taking the element


			dp[flag][j]=(x+y)%MOD;
			//cout<<"i = "<<i<<" "<<dp[flag][j]<<""<<endl;
		}
		flag=flag^1;
	} 
	// updating result.
	for(int i=0;i<=m;i++)
	{
		result[i]=dp[flag^1][i];
		//cout<<result[i];
	}
	//cout<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	populatePrimes();
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int>arr(n);
		vector<int>cnt(4501,0);
		vector<int>uniqueElements;

		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			cnt[arr[i]]++;
			if(cnt[arr[i]]==1)
				uniqueElements.push_back(arr[i]);
		}

		/*
		   cout<<"the unique elements are : "<<endl;
		   for(int i=0;i<uniqueElements.size();i++)
		   cout<<uniqueElements[i]<<endl;
		 */
		countSubsetXOR(uniqueElements,uniqueElements.size(),cnt);

		//cout<<"result = "<<result[11]<<endl;

		ll answer=0;

		for(int i=2;i<8192;i++)
		{
			//cout<<"prime is : "<<i<<" "<<result[i]<<endl;
			if(isPrime[i])
			{
				ll x=result[i];
				//cout<<"yes prime found "<<i<<" and x = "<<x<<endl;

				answer=(answer+x)%MOD;
			}
		}
		cout<<answer<<endl;

	}
	return 0;
} 
