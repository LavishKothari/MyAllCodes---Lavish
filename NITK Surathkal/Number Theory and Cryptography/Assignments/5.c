 /*
	implementation of Seive of Eratosthenes
	and counting the number of bit operations
*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
	long long int bitOperations;
	int n,*arr,i,j;
	printf("Enter a number till which you want to find prime numbers : ");
	scanf("%d",&n);
	
	arr=(int*)malloc(sizeof(int)*(n+1));
	
	/*Initializing the whole array with 1*/
	// initially suppose that every number is prime.
	for(i=0;i<=n;i++)
		arr[i]=1;
	
	arr[0]=arr[1]=0; // because 0 and 1 is not a prime
	
	bitOperations=0;
	for(i=2;i*i<=n;i++)
	{
		bitOperations=bitOperations+((long long int)log2(i)+1)*((long long int)log2(i)+1); // calculating number of bit operations for i*i
		bitOperations=bitOperations+(long long int)log2(i)+1; // calculating number of bit operations for incrementing i
		if(arr[i]==1)
		{
			bitOperations=bitOperations+((long long int)log2(i)+1)*((long long int)log2(i)+1); // calculating number of bit operations for i*i
			for(j=i*i;j<=n;j+=i)
			{
				arr[j]=0;
				bitOperations=bitOperations+(long long int)log2(j)+1; // calculating number of bit operations for incrementing j
			}
		}
	}
	printf("\nThe following is the list of prime numbers <= %d:\n",n);
	for(i=2;i<=n;i++)
		if(arr[i]==1)
			printf("%d ",i);
	
	printf("\n");
	printf("\nThe number of bit operations needed for implementing Seive of Eratosthenes are : %lld\n\n",bitOperations);
	printf("The value of %d * log2(%d) * log2(log2(%d)) = %lf\n\n",n,n,n,(n * log2(n) * log2(log2(n))));
	return 0;
}
