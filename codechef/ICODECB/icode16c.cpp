#include<stdio.h>
#include<utility>
#define MOD 1000000007
typedef long long int ll;
using namespace std;
ll inc_a[100001],inc_b[100001];
int a,b;
void cc(int t)
{
	if(t<=0)
		a++;
	else if(t==1)
		b++;
	else
	{
		cc(t-1);
		cc(t-2);
		cc(t-3);

	}
}
pair<int,int> c(int t)
{
	if(t<=0)
		return make_pair(1,0);
	else if(t==1)
		return make_pair(0,1);
	if(inc_a[t]!=-1)
		return make_pair(inc_a[t],inc_b[t]);
	pair<int,int>x=c(t-3);
	pair<int,int>y=c(t-2);
	pair<int,int>z=c(t-1);
	return make_pair(((ll)x.first+y.first+z.first)%MOD,((ll)x.second+y.second+z.second)%MOD);
}
void populateinc()
{
	for(int i=0;i<100001;i++)
		inc_a[i]=inc_b[i]=-1;
	for(int i=0;i<100001;i++)
	{
		pair<int,int>x=c(i);
		inc_a[i]=x.first;
		inc_b[i]=x.second;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	populateinc();
	while(t--)
	{
		int time;
		scanf("%d",&time);
		a=0;b=0;
		c(time);//cc(time);
		printf("%lld %lld\n",inc_a[time],inc_b[time]);
	}
	return 0;
}
