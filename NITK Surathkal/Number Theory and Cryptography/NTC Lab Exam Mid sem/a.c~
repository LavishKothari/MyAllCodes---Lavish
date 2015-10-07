#include<stdio.h>
#define MAX 100
int isPrime(long long int n)
{
	long long int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
long long int power(long long int a,long long int b)
{
	long long int t;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	t=power(a,b/2);
	if(b%2==0)
		return t*t;
	else return t*t*a;
}
long long int add(long long int a,long long int b)
{
	//return a+b;
	long long int answer;
	int ans[MAX],counter,carry,x,y,i;
	counter=MAX-1;
	carry=0;
	while(a || b)
	{
		x=(a&1);
		y=(b&1);
		if(carry==0)
		{
			if(x==0 && y==0)
			{
				carry=0;
				ans[counter--]=0;
			}
			else if(x==1 && y==0)
			{
				carry=0;
				ans[counter--]=1;
			}
			else if(x==0 && y==1)
			{
				carry=0;
				ans[counter--]=1;		
			}
			else if(x==1 && y==1)
			{
				carry=1;
				ans[counter--]=0;
			}
		}
		else 
		{
			if(x==0 && y==0)
			{
				carry=0;
				ans[counter--]=1;
			}
			else if(x==1 && y==0)
			{
				carry=1;
				ans[counter--]=0;
			}
			else if(x==0 && y==1)
			{
				carry=1;
				ans[counter--]=0;		
			}
			else if(x==1 && y==1)
			{
				carry=1;
				ans[counter--]=1;
			}		
		}
		a=a>>1;
		b=b>>1;
	}
	if(a)
	{
		while(a)
		{
			x=(a&1);
			if(carry==0 && x==0)
			{
				ans[counter--]=0;
				carry=0;
			}
			if(carry==1 && x==0)
			{
				ans[counter--]=1;
				carry=0;
			}
			if(carry==0 && x==1)
			{
				ans[counter--]=1;
				carry=0;			
			}
			if(carry==1 && x==1)
			{
				ans[counter--]=0;
				carry=1;
			}
			
			a=a>>1;
		}
		
	}
	else if(b)
	{
		while(b)
		{
			printf("this is a check %lld\n",b);
			x=(b&1);
			if(carry==0 && x==0)
			{
				ans[counter--]=0;
				carry=0;
			}
			if(carry==1 && x==0)
			{
				ans[counter--]=1;
				carry=0;
			}
			if(carry==0 && x==1)
			{
				ans[counter--]=1;
				carry=0;			
			}
			if(carry==1 && x==1)
			{
				ans[counter--]=0;
				carry=1;
			}
			
			b=b>>1;
		}
		
	}
	if(carry==1)
		ans[counter--]=1;
		/*
	for(i=counter+1;i<MAX;i++)
		printf("%d",ans[i]);
	*/
	answer=0;
	for(i=counter+1;i<MAX;i++)
		answer=answer*2+ans[i];
	return answer;
}
int main1()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("\n\n%lld\n",add(a,b));
	return 0;
}
int main()
{
	long long int p,po,i,a,b,sum;
	printf("Enter the prime number : ");
	scanf("%lld",&a);
	printf("Enter the power : ");
	scanf("%lld",&b);
	if(isPrime(a))
	{
		po=power(a,b);
		sum=0;
		for(i=1;i<po;i++)
		{
			if(i%a!=0)
			{
				printf("%lld ",i);
				sum=add(sum,i);
			}
		}
		printf("\nThe sum is : %lld\n",sum);
	}
	else printf("the number you entered is not a prime number...!\nexiting\n");
	return 0;
}
