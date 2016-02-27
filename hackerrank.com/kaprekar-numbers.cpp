#include<stdio.h>
#include<math.h>
typedef long long int ll;
bool is(ll n)
{
	int len=0;
	ll cn=n*n;
	while(cn)
	{
		len++;
		cn/=10;
	}
	int lenl,lenr;
	lenr=lenl=len/2;
	if(len&1)
		lenl++;
	if((n*n)/(ll)pow(10,lenl)+(n*n)%(ll)pow(10,lenl)==n)
		return true;
	return false;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	bool flag=false;
	for(int i=a;i<=b;i++)
	{
		if(is(i))
		{
			flag=true;
			printf("%d ",i);
		}
	}
	if(!flag)
		printf("INVALID RANGE\n");
	return 0;
}
