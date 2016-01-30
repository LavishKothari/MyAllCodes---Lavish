#include<stdio.h>
#include<set>
typedef long long int ll;
#define MAX 10000000000000000L
#define TEST 200
using namespace std;
set<ll>g;

void dowork()
{
	for(ll i=2;i<TEST;i++)
	{
		//printf("i = %lld\n",i);
		ll ci=i;
		while(ci<MAX)
		{
			g.insert(ci);
			ci*=i;
		}
	}
}
int DS(ll n)
{
	int sum=0;
	while(n)
	{
		sum+=n%10;
		n/=10;
	}
	return sum;
}
bool check(ll n)
{
	int sum=DS(n);
	if(sum==1)
		return false;
	while(n!=1)
	{
		if(n%sum==0)
			n/=sum;
		else return false;
	}
	return true;
}
int main()
{
	dowork();
	printf("Work done!!\n");
	int count=0;
	for(set<ll>::iterator it=g.begin();it!=g.end();it++)
	{
		if(check(*it)) 
		{
			count++;
			printf("a%d = %lld\n",count,*(it));
		}
	}
	return 0;
}
