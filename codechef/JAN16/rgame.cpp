//routh.srinivas@gmail.com
//alok_21@outlook.com
#include<stdio.h>
#define MOD 1000000007
#define N 100010
typedef long long int ll;
ll *power2;
ll findAnswer(int*arr,int n)
{
	ll *tempsum=new ll[n+1];
	tempsum[0]=((ll)2*arr[0])%MOD;
	for(int i=1;i<=n;i++)
		tempsum[i]=(power2[i]*arr[i])%MOD;
	ll *exactsum=new ll[n+1];
	exactsum[0]=tempsum[0];
	for(int i=1;i<=n;i++)
		exactsum[i]=(tempsum[i]+exactsum[i-1])%MOD;
	for(int i=0;i<n;i++)
		exactsum[i]=(exactsum[i]*arr[i+1])%MOD;
	for(int i=0;i<n;i++)
		exactsum[i]=(exactsum[i]*power2[n-i-1])%MOD;
	ll answer=0;
	for(int i=0;i<n;i++)
		answer=(answer+exactsum[i])%MOD;
	delete tempsum;
	delete exactsum;
	return answer;
}

ll findAnswer1(int*a,int n) // Aishya's code
{
	ll sum = (((2 * ( a[0] * a[1])%MOD)%MOD)*power2[n-1])%MOD;
	ll add = (2 * ( a[0] + a[1])%MOD)%MOD;
	for(ll i=2 ; i <= n; i++)
	{
		//sum = sum + ((a[i] * add)%MOD)%MOD;
		sum=(sum+(a[i]*(add*power2[n-i])%MOD)%MOD)%MOD;
		add = (add + ((a[i]*(power2[i])%MOD)%MOD))%MOD;
	}
	return sum;

}


void populatePower()
{
	power2=new ll[N];
	power2[0]=1;
	for(int i=1;i<N;i++)
		power2[i]=(power2[i-1]*2)%MOD;
}
int main()
{
	int t;
	populatePower();
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int *arr=new int[n+1];
		for(int i=0;i<=n;i++)
			scanf("%d",&arr[i]);
		printf("%lld %lld\n",findAnswer(arr,n),findAnswer1(arr,n));
		delete arr;
	}
	return 0;
}
