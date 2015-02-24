#include<stdio.h>

int main()
{
	int t;
	long long int min,x,y,n,i,j,max;
	scanf("%d",&t);
	while(t--)
	{
		min=2147483647;
		scanf("%lld%lld%lld",&x,&y,&n);
		for(i=0,j=n;i<=n;i++,j--)
		{
			max=i*x>j*y?i*x:j*y;
			if(max<min)
				min=max;
		}
		printf("%lld ",min);
	}
	return 0;
}
