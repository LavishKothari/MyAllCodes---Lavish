#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int b,w,x,y,z,answer=0;
		scanf("%lld%lld",&b,&w);
		scanf("%lld%lld%lld",&x,&y,&z);
		if(x<y)
		{	
			answer+=x*b;
			if(y<x+z)
				answer+=y*w;
			else
				answer+=(x+z)*w;
		}
		else
		{
			answer+=y*w;
			if(x<y+z)
				answer+=x*b;
			else
				answer+=(y+z)*b;
		}
		printf("%lld\n",answer);
	}
	return 0;
}
