#include<stdio.h>
#include<math.h>
#define MAX 1000
typedef long long int ll;
ll answer=0;
int isInteger(double x)
{
	double decimal;
	int intx;
	
	decimal=x-(long long int)x;
	
	if(decimal>0.000001)
		return 0;
	return 1;
}
int isPerfectSquare(ll n)
{
	ll s=(ll)sqrt(n);
	while(1)
	{
		if(s*s==n)
			return 1;
		if(s*s>n)
			return 0;
		s++;
	}
}
int canBeExpressed(ll n)
{
	int k;
	double a,b,c,D,x;
	for(k=1;k*k<=n;k++)
	{
		a=k+1;
		b=k*(k+1);
		c=(k*(k+1)*(2*k+1))/6-n;
		if(b*b-4*a*c < 0)
			continue;
			
		D=sqrt(b*b-4*a*c);
		printf("this is D*D = %lld\n",(ll)b*(ll)b-4*(ll)a*(ll)c);
		//if(isInteger(D))
		if(isPerfectSquare((ll)b*(ll)b-4*(ll)a*(ll)c))
		{
			x=(-b+D)/(2*a);
			printf("this is x = %g %lf %lf %lf \n",x,b,D,a);
			if(isInteger(x) && (x>0))
			{
				printf(" x=%g k=%d\n",x,k);
				return 1;
			}
		}
	}
	return 0;
}
int isPalindrome(long long int n)
{
	long long int rev=0,cn=n;
	while(cn)
	{
		rev=rev*10+cn%10;
		cn/=10;
	}
	return (n==rev);
}
void try1()
{
	int i;
	for(i=1;i<=9;i++)
	{
		if(canBeExpressed(i))
		{
			printf("%d\n",i);
			answer+=i;
		}
	}
}
void try2()
{
	int i,no,j;
	for(i=1;i<=9;i++)
	{
		no=i*10+i;
		if(canBeExpressed(no) && isPalindrome(no))
		{
			printf("%d\n",no);
			answer+=no;
		}
	}
}
void try3()
{
	int i,no,j;
	for(i=1;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			no=i*100+j*10+i;
		
			if(canBeExpressed(no) && isPalindrome(no))
			{
				printf("%d\n",no);
				answer+=no;
			}
		}
	}
}
void try4()
{
	int i,no,j;
	for(i=1;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			no=i*1000+j*100+j*10+i;
		
			if(canBeExpressed(no) && isPalindrome(no))
			{
				printf("%d\n",no);
				answer+=no;
			}
		}
	}
}
void try5()
{
	int i,no,j,k;
	for(i=1;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			for(k=0;k<=9;k++)
			{
				no=i*10000+j*1000+k*100+j*10+i;
		
				if(canBeExpressed(no) && isPalindrome(no))
				{
					printf("%d\n",no);
					answer+=no;
				}
			}
		}
	}
}
void try6()
{
	int i,no,j,k;
	for(i=1;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			for(k=0;k<=9;k++)
			{
				no=i*100000+j*10000+k*1000+k*100+j*10+i;
		
				if(canBeExpressed(no) && isPalindrome(no))
				{
					printf("%d\n",no);
					answer+=no;
				}
			}
		}
	}
}
void try7()
{
	int i,no,j,k,l;
	for(i=1;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			for(k=0;k<=9;k++)
			{
				for(l=0;l<=9;l++)
				{
					no=i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i;
		
					if(canBeExpressed(no) && isPalindrome(no))
					{
						printf("%d\n",no);
						answer+=no;
					}
				}
			}
		}
	}
}
void try8()
{
	int i,no,j,k,l;
	for(i=1;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			for(k=0;k<=9;k++)
			{
				for(l=0;l<=9;l++)
				{
					no=i*10000000+j*1000000+k*100000+l*10000+l*1000+k*100+j*10+i;
		
					if(canBeExpressed(no) && isPalindrome(no))
					{
						printf("%d\n",no);
						answer+=no;
					}
				}
			}
		}
	}
}

int main2()
{
	/*
	ll i,sum=0;
	for(i=1;i<1000;i++)
		if(canBeExpressed(i) && isPalindrome(i))
		{
			printf("%lld ",i);
			sum+=i;
		}
	printf("\nsum = %lld\n",sum);
	*/
	try1();
	try2();
	try3();
	try4();
	try5();
	try6();
	try7();
	try8();
	
	printf("\nfinal Answer = %lld\n",answer);
	return 0;
}
int main1()
{
	ll sq[10001],sum[10001],i,j;
	sq[0]=0;
	for(i=1;i<=10000;i++)
	{
		sq[i]=i*i;
		sum[i]=sq[i]+sum[i-1];
	}
	for(i=0;i<=10000;i++)
	{
		for(j=i+2;j<=10000;j++)
		{
			if(isPalindrome(sum[j]-sum[i]) && sum[j]-sum[i]<100000000)
			{
				printf("%lld\n",sum[j]-sum[i]);
				answer+=sum[j]-sum[i];
			}
		}
	}
	printf("\nanswer = %lld\n",answer);
	return 0;
}
int main()
{
	printf("%d\n",canBeExpressed(20599502));
}
