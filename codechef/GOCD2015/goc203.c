#include<stdio.h>
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int i,c,t,a,b;
	scanf("%d",&t);
	i=1;
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c); 
		if((c%gcd(a,b))==0)
			printf("Case %d: Yes\n",i);
		else printf("Case %d: No\n",i);
		i++;
	}
	return 0;
}
