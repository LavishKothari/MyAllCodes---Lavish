#include<stdio.h>
#include<stdlib.h>
int len1=0,len2=0,fullLen=0;
void printArray(int *arr,int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d",arr[i]);
	printf("\n");
}
int *correctMultiply(long long int a,long long int b)
{
	int num,arr[30]={0},*answer,counter,i,n,j;
	counter=29;
	answer=(int*)malloc(sizeof(int)*30);
	while(a)
	{
		arr[counter--]=a%10;
		a/=10;
	}
	num=0;
	while(b)
	{
		n=b%10;
		counter=29-num;
		num++;
		for(i=29,j=counter;j>=0;j--,i--)
		{
			
			{
				answer[counter--]+=n*arr[i];
			}
		}
		b/=10;
	}
	for(i=29;i>0;i--)
	{
		n=answer[i]/10;
		answer[i]=answer[i]%10;
		answer[i-1]+=n;
	}
	for(i=0;i<30 && answer[i]==0;i++);
	len1=30-i;
	//printf("in correct multiply len2=")
	return answer+i;
}
int* wrongMultiply(long long int a,long long b)
{
	int num,arr[30]={0},*answer,counter,i,n,j;
	counter=29;
	answer=(int*)malloc(sizeof(int)*30);
	while(a)
	{
		arr[counter--]=a%10;
		a/=10;
	}
	num=0;
	while(b)
	{
		n=b%10;
		counter=29-num;
		num++;
		for(i=29,j=counter;j>=0;j--,i--)
		{
			if(arr[i]==n)
			{
				answer[counter--]+=2*n;
			}
			else
			{
				answer[counter--]+=n*arr[i];
			}
		}
		b/=10;
	}
	for(i=29;i>0;i--)
	{
		n=answer[i]/10;
		answer[i]=answer[i]%10;
		answer[i-1]+=n;
	}
	for(i=0;i<30 && answer[i]==0;i++);
	len2=30-i;
	return answer+i;
}
int*add(int *a,int *b)
{
	int *answer,len,i,j,counter,n;
	len=(len1>len2?len1:len2);
	counter=len-1;
	answer=(int*)malloc(sizeof(int)*len);
	for(i=len1-1,j=len2-1;i>=0 || j>=0;j--,i--)
	{
		if(i>=0 && j>=0)
		{
			answer[counter--]=a[i]+b[j];
		}
		else if(i>=0)
			answer[counter--]=a[i];
		else if(j>=0)
			answer[counter--]=b[j];
	}
	for(i=len-1;i>0;i--)
	{
		n=answer[i]/10;
		answer[i]=answer[i]%10;
		answer[i-1]+=n;
	}
	fullLen=len;
	return answer;
}

int main()
{
	int t,*arr,i;
	long long int a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
			
		arr=add(correctMultiply(a,b),wrongMultiply(a,b));
		printArray(arr,fullLen);
	}
	return 0;
}
