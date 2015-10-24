#include<stdio.h>
#include<stdlib.h>
struct Number
{
	int value,index;
};
int cmp(const void*a,const void*b)
{
	struct Number x=*(struct Number*)a;
	struct Number y=*(struct Number*)b;
	return x.value-y.value;
}
int binarySearch(struct Number *arr,int a,int b,int sval)
{
	int mid;
	while(a<=b)
	{
		mid=(a+b)/2;
		if(arr[mid].value==sval)
			return mid;
		if(arr[mid].value>sval)
			b=mid-1;
		else 
			a=mid+1;
	}
	return -1;
}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		struct Number*arr;
		scanf("%d%d",&k,&n);
		arr=(struct Number*)malloc(sizeof(struct Number)*n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&(arr[i].value));
			arr[i].index=i;
		}
		qsort(arr,n,sizeof(struct Number),cmp);
		int counter=0;
		for(int i=0;i<n-1;i++)
		{
			int a=binarySearch(arr,i+1,n-1,k-arr[i].value);
			if(a!=-1)
			{
				printf("%d %d\n",min(arr[i].index+1,arr[a].index+1),max(arr[i].index+1,arr[a].index+1));
				break;
			}
		}
		delete(arr);
	}
	return 0;
}
