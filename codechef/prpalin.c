#include<stdio.h>

int isPalindrome(int);
int isPrime(int);

int main()
{
	int n;
	scanf("%d",&n);
 			
	while(1)
	{
		if(isPalindrome(n))
			if(isPrime(n))
			{
				printf("%d",n);
				break;
			}
		n++;
	}
	return 0;
}

int isPalindrome(int n)
{
	int tmp,rev=0;
	tmp=n;
	while(tmp)	
	{
		rev=rev*10+tmp%10;
		tmp/=10;
	}
	if(n==rev)
		return 1;
	return 0;
}		 

int isPrime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	if(n!=1)
		return 1;
	return 0;
}		

