#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<vector>
#define MAX 5000001
using namespace std;
int level=0,size=0;
int*x;
int*y;
int*z;

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
void populateAnswerArray(int a,int b,int c)
{

	if(size>MAX-100)
		return;
	x[size]=(a*1+b*2+c*2);
	x[size+1]=(a*1+b*2+c*2);
	x[size+2]=(-a*1-b*2-c*2);

	y[size]=(-a*2-b*1-c*2);
	y[size+1]=(a*2+b*1+c*2);
	y[size+2]=(a*2-b*1+c*2);

	z[size]=(a*2+2*b+3*c);
	z[size+1]=(a*2+2*b+3*c);
	z[size+2]=(a*2+2*b+3*c);

	size+=3;

	populateAnswerArray(x[factor],y[factor],z[factor]);
	populateAnswerArray(x[factor+1],y[factor+1],z[factor+1]);
	populateAnswerArray(x[factor+2],y[factor+2],z[factor+2]);
	factor+=3;
}
int main()
{
	int t,n,i,j;
	answerArray=(int*)malloc(sizeof(int)*(MAX+1));
	x=(int*)malloc(sizeof(int)*(MAX+1));
	y=(int*)malloc(sizeof(int)*(MAX+1));
	z=(int*)malloc(sizeof(int)*(MAX+1));
	printf("allocation completed\n");
	x[size]=3;
	y[size]=4;
	z[size]=5;
	size++;
	factor=1;
	populateAnswerArray(3,4,5);
	printf("populating the array is done...\n");
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

