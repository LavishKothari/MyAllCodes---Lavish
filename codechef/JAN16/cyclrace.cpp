#include<stdio.h>
typedef long long int ll;
ll update2(ll *dist,ll* speed,int newTime,int currentTime,int n)
{
	int time=newTime-currentTime;
	ll m=0;
	for(int i=0;i<n;i++)
	{
		dist[i]+=(speed[i]*time);
		if(dist[i]>m)
			m=dist[i];
	}
	return m;
}
void update1(ll *dist,ll* speed,int t,int currentTime,int c,int ns,int n)
{
	update2(dist,speed,t,currentTime,n);
	speed[c-1]=ns;
}
int main()
{
	int n,query,q;
	scanf("%d%d",&n,&query);
	ll*dist=new ll[n];
	ll*speed=new ll[n];
	for(int i=0;i<n;i++)
		speed[i]=dist[i]=0;
	int prevTime=1,t;

	while(query--)
	{
		scanf("%d",&q);
		if(q==1)
		{
			int c,ns;
			scanf("%d%d%d",&t,&c,&ns);
			update1(dist,speed,t,prevTime,c,ns,n);	
		}
		else 
		{
			scanf("%d",&t);
			printf("%lld\n",update2(dist,speed,t,prevTime,n));
		}
		prevTime=t;
	}
	delete dist;
	delete speed;
	return 0;
}
