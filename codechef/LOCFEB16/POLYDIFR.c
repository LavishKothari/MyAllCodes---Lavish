#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;

struct O
{
	ll a,p;
};
int cmc(const void *x,const void*y)
{
	return ((struct O*)y)->p - ((struct O*)x)->p;
}
int main()
{
	struct O ob[10001];
	ll t,i,n,a,p,pii;int flag;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&a,&p);
			if(p==0)
				ob[i].a=0;ob[i].p=0;
			else 
				ob[i].a=a*p;ob[i].p=p-1;
		}
		qsort(ob,n,sizeof(struct O),cmc);
		flag=0;
		for(i=0;i<n;i++)
		{
			if(ob[i].a!=0)
			{
				flag=1;
				if(i!=0)
					printf(" + ");
				if(ob[i].p!=0)
					printf("%lldx^%lld",ob[i].a,ob[i].p);
				else printf("%lld",ob[i].a);
			}
		}
		if(flag==0)
			printf("0");
		printf("\n");
	}
	return 0;
}
