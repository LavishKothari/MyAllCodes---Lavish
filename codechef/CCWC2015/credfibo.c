#include<stdio.h>
#define MAX 100001
#define MOD 4
int power(int a,int b)
{
	int t;
	if(b==0)
		return 1;
	if(b==1)
		return a%MOD;
	if(b%2==0)
	{
		t=power(a,b/2);
		return (t*t)%MOD;
	}
	else
	{
		t=power(a,b/2);
		return (((t*t)%MOD)*a)%MOD;
	}
}
int main()
{
	int i,l,r,sum,t,fib[MAX];
	int flag[MAX];
	for(i=0;i<MAX;i++)
		flag[i]=0;
	fib[0]=fib[1]=1;
	fib[2]=1;
	for(i=3;i<MAX;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%MOD;
		if((fib[i-1]+fib[i-2])%MOD==3)
			flag[i]++;
	}
	sum=0;
	for(i=0;i<MAX;i++)
	{
		if(flag[i]!=0)
			sum++;
		flag[i]=sum;
		
	}
	/*
	for(i=0;i<20;i++)
	{
		printf("This is a check => flag[%d] = %d\n",i,flag[i]);
	}
	*/
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		//l--;
		//r--;
		
		printf("%d\n",power(3,flag[r]-flag[l-1]));
	}
	return 0;
}
