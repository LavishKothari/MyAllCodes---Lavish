#include<stdio.h>
#include<math.h>
#define L -1000000000
#define U 1000000000
typedef long long int ll;
ll max(ll a,ll b)
{
	return a>b?a:b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int maxx=L,maxy=L,minx=U,miny=U;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==0)
		{
			if(miny>y)
				miny=y;
			if(maxy<y)
				maxy=y;
		}
		else if(y==0)
		{
			if(minx>x)
				minx=x;
			if(maxx<x)
				maxx=x;		
		}
	}
	ll d1,d2,d3,d4,d5,d6;
	d1=((ll)maxx-minx)*(maxx-minx);d2=((ll)maxy-miny)*(maxy-miny);
	d3=(ll)maxx*maxx+(ll)maxy*maxy;
	d4=(ll)maxx*maxx+(ll)miny*miny;
	d5=(ll)minx*minx+(ll)miny*miny;
	d6=(ll)minx*minx+(ll)maxy*maxy;
	
	printf("%lf\n",sqrt(max(max(max(max(max(d1,d2),d3),d4),d5),d6)));
	return 0;
}
