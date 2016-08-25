#include<stdio.h>
#define MAX 100010
long long int arr;
int main()
{
	long long int sum,max,bad,negno,badno;
	long long int t,n,a,flag1,b,c,d,i;
	scanf("%lld",&t);
	while(t--)
	{
		sum=flag1=negno=badno=0;
		bad=-2147483648;
		max=0;
		scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr);
			if(arr<0)
				negno++;
			if(arr==a || arr==b || arr==c || arr==d)
				badno++;
						
			
			if(arr<0 || arr==a || arr==b || arr==c || arr==d)
				flag1++;
			if(arr<0 && arr>bad)
				bad=arr;
				
			if(arr==a || arr==b || arr==c || arr==d || (sum+arr)<0)
			{
				sum=0;
				continue;
			}
			sum=sum+arr;
			if(sum>max)
				max=sum;
		}
		
		if(badno==n)
			printf("\n");
		else if(negno+badno==n)
			printf("%lld\n",bad);
		else printf("%lld\n",max);
	}
	return 0;
}
