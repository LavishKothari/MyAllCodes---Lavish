#include<stdio.h>
#define MOD 1000000007
int find(long long int n)
{
	int answer=0;
	while(n)
	{
		if((n&1)==1)
			answer++;
		n=(n>>1);
	}
	return answer;
}
int main()
{	
	long long int i,t,arr[100001],n;
	arr[0]=0;
	arr[1]=1;
	arr[2]=2;
	for(i=3;i<100001;i++)
		arr[i]=(arr[i-1]+arr[i-2])%MOD;
	/*
	for(i=0;i<20;i++)
		printf("a=a %lld\n",arr[i]);
	*/
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%d\n",find(arr[n]));
	}
	return 0;
}
/*
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",find(n));
	return 0;
}
*/
