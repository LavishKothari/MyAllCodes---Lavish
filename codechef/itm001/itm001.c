#include<stdio.h>

int main()
{
	long long int q,a,b,c,d,x,y,answer;
	scanf("%lld",&q);
	while(q--)
	{
		answer=a=b=0;
		scanf("%lld%lld",&x,&y);
		if(x%2==0)
			a=1;
		if(y%2==0)
			b=1;
		c=x/2+1;
		d=y/2+1;
		if(!a && x!=1)
			answer=answer-c;
		else if(x==1)
			answer++;
		if(b)
			answer+=d;
		printf("%lld\n",answer);
	}
	return 0;
}
