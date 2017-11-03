#include<bits/stdc++.h>
using namespace std;
double interior_angle(int n)
{
	return 180.0/n*(n-2);
}
double angle(int a,int b,int c,int n)
{
	return ( 360.0/n * (b-a) ) /2;
}
void solve(int n,int a)
{
	if(n==3)
	{
		printf("%d %d %d\n",1,2,3);
		return;
	}
	a=a*2;
	int mi;
	if((n*a)%360==0)
	{
		// the multiple here is an integer.
		mi=(n*a)%360;
	}
	else
	{
		double x=360.0/n;
		double m=a/x;
		mi=(int)m;
		if(abs(x*mi-a)>abs(x*(mi+1)-a))
			mi++;
	}
	a/=2;
	int flag=0;
	//if(angle_by 123 > angle makde by mi)
	//printf("interior_angle=%lf\n",interior_angle(n));
	//printf("other_angle   =%lf\n",angle(1,mi+1,mi+2,n));
	//printf("mi = %d\n",mi);

	//printf("abs(interior_angle(n)-a) = %lf\n",abs(interior_angle(n)-a));
	//printf("abs(angle(1,mi+1,mi+2)-a) = %lf\n",abs(angle(1,mi+1,mi+2,n)-a));
	if(abs(interior_angle(n)-a) < abs(angle(1,mi+1,mi+2,n)-a))
		flag=1;
	//printf("flag = %d\n",flag);

	if(mi<n && flag==0)
		printf("%d %d %d\n",1,mi+2,mi+1);
	else printf("1 2 3\n");
}
int main()
{
	int n,a;
	scanf("%d%d",&n,&a);
	solve(n,a);
	return 0;
}
