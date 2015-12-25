#include<stdio.h>
void rotate(int*arr,int n,int k)
{
	int*narr=new int[n];
	int i;
	for(i=0;i<k;i++)
		narr[i]=arr[n-k+i-1];
	for(int j=0;i<n-k;i++,j++)
		narr[i]=arr[j];
	for(i=0;i<n;i++)
		arr[i]=narr[i];
}
int main()
{
	int n,k,q;
	scanf("%d%d%d",&n,&k,&q);
	k=k%n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	//rotate(arr,n,k);
	while(q--)
	{
		int t;
		scanf("%d",&t);
		int idx=(t-k)%n;
		if(idx<0) idx+=n;
		printf("%d\n",arr[idx]);
	}
	return 0;
}
