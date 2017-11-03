#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class point
{
	public:
		ll x,y;
		double dist;
};
bool cp(const point&a,const point&b)
{
	return a.dist<b.dist;
}
bool cmp(const double &b,const point&a)
{
	return a.dist<b;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<point>pts(n);
	vector<double>dist(n);
	for(int i=0;i<n;i++)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		pts[i].x=x;
		pts[i].y=y;
		pts[i].dist=sqrt(x*x+y*y);
		dist[i]=pts[i].dist;
	}

	sort(dist.begin(),dist.end());
	/*
	   for(int i=0;i<n;i++)
	   printf("%lld %lld %lf\n",pts[i].x,pts[i].y,pts[i].dist);
	 */
	int q;
	scanf("%d",&q);

	while(q--)
	{
		ll r;
		scanf("%lld",&r);
		int index=upper_bound(dist.begin(),dist.end(),(double)r)-dist.begin();
		printf("%d\n",index);
	}
	return 0;
}
