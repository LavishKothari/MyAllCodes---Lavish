#include<stdio.h>
#define INF -2147483648
int arr[1001];
int findAnswer(int *arr,int a,int b,int n)
{
	int start,i;
	if(a>=n || b>=n)
		return 0;
	if(a==b && arr[a]%2==0)
		return 0;
	if(a==b && arr[a]%2==1)
		return INF;
	start=a;
	for(i=a;i<=b;i++)
		if(arr[i]%2==0)
			start++;
		else break;
	if(start!=a)
		return findAnswer(arr,start,b,n);
	arr[a+1]++;
	return 2+findAnswer(arr,a+1,b,n);
}
int main()
{
	int n,i,answer;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	answer=findAnswer(arr,0,n-1,n);
	if(answer<0)
		printf("NO\n");
	else printf("%d\n",answer);
	return 0;
}
