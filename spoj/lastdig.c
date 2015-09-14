#include<stdio.h>
#define MOD 10
int findLast(int a,int b)
{
	int t;
	if(b==0)
		return 1;
	else if(b==1)
		return a%MOD;
	t=findLast(a,b/2);
	if(b%2==0)
		return (t*t)%MOD;
	else return (t*t*a)%MOD;
}
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",findLast(a,b));
	}
	return 0;
}
