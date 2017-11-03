#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long long int n,k;
	scanf("%lld%lld",&k,&n);
	vector<long long int>radius2(k);

	for(long long int i=0;i<k;i++)
	{
		long long int r;
		scanf("%lld",&r);
		radius2[k-1-i]=r*r;
	}
	long long int answer=0;
	for(long long int i=0;i<n;i++)
	{
		long long int x,y;
		scanf("%lld%lld",&x,&y);
		//printf("this is a test : %d %d  ----->   %d\n",x,y,k+(radius2.begin()-lower_bound(radius2.begin(),radius2.end(),x*x+y*y)));
		answer+=k+(radius2.begin()-lower_bound(radius2.begin(),radius2.end(),x*x+y*y));
	}
	printf("%lld\n",answer);
	return 0;
}
