#include<stdlib.h>
#include<stdio.h>
#include<time.h>

/*
	MAX represents the maximum value that elements of array can have.
	TOTAL represents the total number of elements in the array.
*/

#define MAX 10000000LL
#define TOTAL 10000LL

void generateTestCases()
{
	FILE *f;
	long long int d,i;
	f=fopen("tests.txt","w");
	srand(time (NULL));
	fprintf(f,"%lld\n",TOTAL);
	for(i=0;i<TOTAL;i++)
	{
		d=random()%MAX+1;
		fprintf(f,"%lld\n",d);
	}
	fclose(f);
}
long long int LIS(long long int*arr,long long int n)
{
	/*
		this function returns the length of Longest Increasing Subsequence
		this function also prints all the numbers in the Longest Increasing Subsequence
		this function also prints sum of all the numbers in the Longest Increasing Subsequence
	*/
	long long int sum;
	long long int *L,i,j,max,cmax,*LIS;
	L=(long long int*)malloc(sizeof(long long int)*n);
	L[0]=1;
	for(i=1;i<n;i++)
	{
		max=1;
		for(j=0;j<i;j++)
			if(arr[j]<arr[i] && max<L[j]+1)
			{
				max=L[j]+1;
			}
		L[i]=max;
	}
	
	/* finding maximum of all the LIS values. */
	max=1;
	for(i=0;i<n;i++)
		if(L[i]>max)
			max=L[i];
	/* 
		here max is the length of longest increasing subsequence. 
		we need to return max.
	*/
	LIS=(long long int*)malloc(sizeof(long long int)*max);
	cmax=max;
	for(i=n-1;i>=0 && cmax;i--)
	{
		if(L[i]==cmax)
		{
			LIS[cmax-1]=arr[i];
			cmax--;
		}
	}
	printf("\nThe longest increasing subsequence is : ");
	sum=0;
	for(i=0;i<max;i++)
	{
		printf("%lld ",LIS[i]);
		sum+=LIS[i];
	}
	printf("\n");
	printf("The sum of elements of Longest Increasing Subsequence is : %lld\n",sum);
	free(L);
	free(LIS);
	return max;
}
int main()
{
	FILE *f;
	clock_t begin,end;
	long long int *arr;
	long long int n,len,i;
	generateTestCases();
	f=fopen("tests.txt","r");
	fscanf(f,"%lld",&n);
	arr=(long long int*)malloc(sizeof(long long int )*n);
	for(i=0;i<n;i++)
		fscanf(f,"%lld",&arr[i]);
	begin=clock();
	len=LIS(arr,n);
	end=clock();
	printf("The length of longest increasing subsequence is : %lld\n",len);
	printf("The time required for execution is : %f\n\n",(end-begin)/(float)CLOCKS_PER_SEC);
	return 0;
}
