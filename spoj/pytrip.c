#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#define MAX 50001
int *answerArray;
int isInt(double d)
{
	if(d-(int)d<0.000001)
		return 1;
	return 0;
}

int isPrime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int findAnswer(int n)
{
	int x;
	if(n<5)
		return 0;
	if(isInt(sqrt(n-1)))
		return 1;
	if((n-1)%4==0 && isPrime(n)==1)
		return 1;
	for(x=1;x<n;x++)
	{
		if(isInt(sqrt(n*n-x*x)))
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int t,n,i,j;
	answerArray=(int*)malloc(sizeof(int)*(MAX+1));
	for(i=0;i<MAX;i++)
		answerArray[i]=-1;
	/*
	for(i=5;i<MAX;i++)
		if(answerArray[i]==-1)
		{
			//printf("%d \n",i);
			answerArray[i]=findAnswer(i);
			if(answerArray[i]==1)
				for(j=i;j<MAX;j+=i)
					answerArray[j]=answerArray[i];
		}
	*/
	//printf("Enter the number of test cases : ");
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(answerArray[n]==-1)
		{
			answerArray[n]=findAnswer(n);
			if(answerArray[n]==1)
				for(i=n;i<=MAX;i+=n)
					answerArray[i]=1;
		}
		if(answerArray[n]==1)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

