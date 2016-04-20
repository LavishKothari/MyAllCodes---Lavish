#include<stdio.h>
#define MAX 200001
#define INT_MAX 2147483647

int n,arr[MAX];
int min2(int a,int b){return a<b?a:b;}
int min3(int a,int b,int c){ return min2(min2(a,b),c); }
int findAnswer()
{
	int temp[MAX],temp_index,arr_index;
	if(n==1)
		return arr[0];
	if(n==2)
		return min2(arr[0],arr[1]);
	temp[0]=arr[0];
	temp[1]=arr[1];
	temp[2]=arr[2];
	
	temp_index=3;
	arr_index=3;
	while(arr_index<n)
	{
		temp[temp_index]=arr[arr_index]+min3(temp[temp_index-1],temp[temp_index-2],temp[temp_index-3]);
		arr_index++;temp_index++;
	}
	return min3(temp[n-1],temp[n-2],temp[n-3]);
}
int main()
{
	int i,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	printf("%d\n",sum-findAnswer());
	return 0;
}
