#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
int dist2(int a,int b,int c,int d)
{
	return (c-a)*(c-a) + (d-b)*(d-b);
}


bool isRectangle(double x1, double y1,
		double x2, double y2,
		double x3, double y3,
		double x4, double y4)
{
	double cx,cy;
	double dd1,dd2,dd3,dd4;

	cx=(x1+x2+x3+x4)/4;
	cy=(y1+y2+y3+y4)/4;

	dd1=sqr(cx-x1)+sqr(cy-y1);
	dd2=sqr(cx-x2)+sqr(cy-y2);
	dd3=sqr(cx-x3)+sqr(cy-y3);
	dd4=sqr(cx-x4)+sqr(cy-y4);
	return dd1==dd2 && dd1==dd3 && dd1==dd4;
}


void sol(int a,int b,int c,int d,int e,int f,int g,int h)
{
	if(isRectangle(a,b,c,d,e,f,g,h))
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";

	}



}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d,e,f,g,h;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
		sol(a,b,c,d,e,f,g,h);
	}
	return 0;
}
