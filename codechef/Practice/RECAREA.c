#include<stdio.h>
typedef long long int ll;
int l(int *arr,int n,int i)
{
	int j;
	for(j=i;j+1<n;j++)
		if(arr[j+1]<arr[i])
			return j-i+1;
	return n-i;
}
int r(int *arr,int n,int j)
{
	int i;
	for(i=j;i-1>=0;i--)
		if(arr[i-1]<arr[j])
			return j-i+1;
	return j+1;
}
ll findanswer(int*arr,int n)
{
	ll max=0,i,x,y;
	for(i=0;i<n;i++)
	{
		x=l(arr,n,i);y=r(arr,n,i);
		x=(x+y-1)*(ll)arr[i];
		if(max<x)
			max=x;
	}
	return max;
}
int main()
{
	int n,arr[100001],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("%lld\n",findanswer(arr,n));
	return 0;
}
