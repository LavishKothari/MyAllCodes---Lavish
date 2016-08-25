#include<stdio.h>
int arr[100001],n;
int findAnswer()
{
	int flag,i,start,max,end;
	if(n==0 || n==1 || n==2)
		return n;
	flag=1;max=2;start=0;end=1;
	for(i=2;i<n;i++)
	{
		if(arr[i]==arr[i-1]+arr[i-2] && flag)
		{
			flag=0;
			start=i-2;
			end=i;
		}
		if(arr[i]==arr[i-1]+arr[i-2])
		{
			end=i;
		}
		if(arr[i]!=arr[i-1]+arr[i-2])
			flag=1;
		if(max<end-start+1)
			max=end-start+1;
	}
	return max;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",arr+i);
		printf("%d\n",findAnswer());
	}
	return 0;
}
