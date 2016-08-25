#include<stdio.h>
#define MAX 100010
typedef long long int ll;

ll findsum(ll *arr,ll start,ll end)
{
	ll sum=0,flag=0,max=-100000000000000000,i,bad=-100000000000000000;
	if(end<start)
		return -100000000000000000;
	if(start<0 || end<0)
		return 0;
	for(i=start;i<=end;i++)
	{
		if(arr[i]<0)
			flag++;
		if(arr[i]<0 && arr[i]>bad)
			bad=arr[i];
		if(sum<0)
		{
			sum=0;
			continue;
		}
		sum+=arr[i];
		if(sum>max)
			max=sum;
	}
	if(flag==end-start+1)
	{
		return bad;
	}
	return max;
}

int main()
{
	ll temp,i,max,badword,t,a,b,c,d,n,arr[MAX];
	scanf("%lld",&t);
	while(t--)
	{
		badword=0;
		scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
		for(i=0;i<n;i++)
		{
			scanf("%lld",arr+i);
			if(arr[i]==a || arr[i]==b || arr[i]==c || arr[i]==d)
			{
				badword++;
			}
		}
		int start=0;
		max=-100000000000000000;
		for(i=0;i<n;i++)
		{
			if(arr[i]==a || arr[i]==b || arr[i]==c || arr[i]==d)
			{
				temp=findsum(arr,start,i-1);
				if(temp>max)
					max=temp;
				start=i+1;
			}
		}
		temp=findsum(arr,start,n-1);
		if(temp>max)
			max=temp;
		if(badword==n)
			printf("0\n");
		else		
			printf("%lld\n",max);
	}
	return 0;
}
