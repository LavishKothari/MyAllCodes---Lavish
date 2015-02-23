#include<stdio.h>
int isPrime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	int i,t,a,b,counter;
	scanf("%d",&t);
	while(t--)
	{
		counter=0;
		scanf("%d%d",&a,&b);
		if(a==2)
			counter++;
		if((a&1)==0)
			a++;
		for(i=a;i<=b;i+=2)
			if(isPrime(i))
				counter++;
		printf("%d ",counter);
	}
	return 0;
}
