#include<stdio.h>

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int t,i,a,b,c,d;
	scanf("%d",&t);
	i=0;
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		d=gcd(a,b);
		i++;
		if(c%d==0)
			printf("Case %d: Yes\n",i);
		else
			printf("Case %d: No\n",i);
	}
	return 0;
}
