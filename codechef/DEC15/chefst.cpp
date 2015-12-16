#include<math.h>
#include<stdio.h>

long long int findAnswer(long long int a,long long int b,long long int m)
{
	if(m>=a && m>=b)
		return a>b?a-b:b-a;
	if(m<a && m<b)
	{ 
		long long int minab=a<b?a:b;
		long long int D=(2*m+1)*(2*m+1)-8*minab;
		if(D>=0)
		{
			double p=(1+2*m+sqrt((2*m+1)*(2*m+1)-8*minab))/2.0;
			double q=(1+2*m-sqrt((2*m+1)*(2*m+1)-8*minab))/2.0;
			//printf("this is a test :  %lf %lf\n",p,q);
			long long int x=(long long int)p;
			if(x>m) x=(long long int)q;
			if(x<=0) return a+b;
			return findAnswer(a-2*(m*x-(x*(x-1))/2),b-2*(m*x-(x*(x-1))/2),m);
		}
		else
		{
			long long int x=m;
			return a+b-2*(m*x-(x*(x-1))/2);
		}
	}
	return a>b?a-b:b-a;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b,m;
		scanf("%lld%lld%lld",&a,&b,&m);
		printf("%lld\n",findAnswer(a,b,m));
		
	}
	return 0;
}
