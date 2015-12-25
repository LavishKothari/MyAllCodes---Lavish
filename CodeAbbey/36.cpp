#include<stdio.h>
#define N 4
int findSame(int a,int b)
{
	int counter=0;
	for(int i=0;i<N;i++)
	{
		if((b%10)==(a%10))
			counter++;
		a/=10;
		b/=10;
	}
	return counter;
}
int main()
{
	int n;
	scanf("%d",&n);
	int*arr,*c;
	arr=new int[n];
	c=new int[n];
	for(int i=0;i<n;i++)
	{	
		scanf("%d%d",&arr[i],&c[i]);
	}
	for(int i=1000;i<=9999;i++)
	{
		int counter=0;
		for(int j=0;j<n;j++)
		{
			if(findSame(arr[j],i)==c[j])
				counter++;
		}
		
		if(counter==n)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
