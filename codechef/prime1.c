#include<stdio.h>
#include<math.h>

int isPrime(long);

int main()
{
    int *primes,arrlen,isp;
	long t,i,m,n,j;
	scanf("%ld",&t);
	while(t--)
	{
	    scanf("%ld %ld",&m,&n);
		arrlen=n-m+1;
		primes=(int*)malloc(sizeof(int)*arrlen);
		for(i=0;i<arrlen;i++)
            primes[i]=1;
		for(j=0;j<arrlen;j++)
		{
		    if(m==1&& j==0)
                continue;
		    if(primes[m+j]==1)
            {
                isp=isPrime(m+j);
                if(!isp) // means j is prime
                {
                    for(i=j;i<arrlen;i+=(m+j))
                        primes[i]=0;
                    printf("%ld\n",j);
                }
                else
                    for(i=j;i<arrlen;i+=isp)
                        primes[i]=0;
            }
		}
		printf("\n");
	}
	return 0;
}

int isPrime(long n) // if number is prime then it returns 0
{
	int i;
	if(n==1)
		return 1;
	for(i=2;i<=sqrt((double)n);i++)
		if(n%i==0)
			return i;
	return 0;
}
