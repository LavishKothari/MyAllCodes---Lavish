#include<stdio.h>
#include<math.h>
int main()
{
	int test,n;
	long long int s,sumd;
	double d;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%lld",&n,&s);
		d=((sqrtl(1+8*s)-1)/2);
		if((d-(int)d)==0 && n!=(int)d)
			d--;
		sumd=(long long int)d*((long long int)d+1)/2;
		while(s-sumd<n-(int)d)
		{
			d--;
			sumd=(long long int)d*((long long int)d+1)/2;
		}
		printf("%d\n",(n-(int)d));
	}
	return 0;
}
