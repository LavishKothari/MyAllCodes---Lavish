#include<stdio.h>

#define MAX 10000010

long long int fact[MAX+1]={0};
long long int sum[MAX+1]={0};
int main()
{
	long long int n,m,a,i,answer,p,pc,x,y;
	fact[0]=1;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m && fact[i-1]!=0;++i)
		fact[i]=((i%m)* (fact[i-1]))%m;
	for(i=1;i<=m;i++)
	    fact[i]=(fact[i]*i%m)%m;
	sum[1]=1;
	for(i=2;i<=m;i++)
	    sum[i]=(fact[i]+sum[i-1])%m;
	answer=0;
	while(n--)
	{
		scanf("%lld",&p);
		pc=p%m;
		x=(pc*(pc+1))/2;
		x=x%m;
		x=(x*pc)%m;
        if(p<m)
		    answer=(answer+sum[p]+x)%m;
		else
		    answer=(answer+m-1+x)%m;
	}
	while(answer<0)
	    answer+=m;
	printf("%lld\n",(answer%m));
	return 0;
}
