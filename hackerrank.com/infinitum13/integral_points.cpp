#include<stdio.h>
#include<stdlib.h>
long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b,c,d,e,f;
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);

		long long int boundaryPoints=gcd(abs(c-a),abs(d-b));
		boundaryPoints+=gcd(abs(e-c),abs(f-d));
		boundaryPoints+=gcd(abs(a-e),abs(b-f));

		long long int area=((a-e)*(d-b)-(a-c)*(f-b));
		if(area<0)
			area=-area;
		printf("%lld\n",(area-boundaryPoints+2)/2);
	}
	return 0;
}
