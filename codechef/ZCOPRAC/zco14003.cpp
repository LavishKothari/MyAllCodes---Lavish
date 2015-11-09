#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<long long int>arr(n);
	for(int i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	sort(arr.begin(),arr.end());
	long long int max=0;
	for(int i=0;i<n;i++)
	{
		if(max<arr[i]*(n-i))
			max=arr[i]*(n-i);
	}
	printf("%lld\n",max);
	return 0;
}
