#include<stdio.h>
int cm(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
void insertionSort(int*arr,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(temp<arr[j])
				arr[j+1]=arr[j];
			else break;
		}
		arr[j+1]=temp;
	}
}
int check(int*arr,int *newArr,int n)
{
	int i;
	if(n==1 || n==2)
		return 1;
	if(arr[0]==newArr[0] || arr[0]==newArr[1]){}
	else return 0;
	if(arr[n-1]==newArr[n-1] || arr[n-1]==newArr[n-2]){}
	else return 0;
	
	for(i=1;i<n-1;i++)
	{
		if(arr[i]==newArr[i-1] || arr[i]==newArr[i] || arr[i]==newArr[i+1]){}
		else return 0;
	}
	return 1;
}
int main()
{
	int t,arr[1000001],answer,newArr[1000001],n,i;
	scanf("%d",&t);
	while(t--)
	{	
		answer=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			if(i>=2 && arr[0]>arr[i])
				answer=0;
			if(i>=3 && arr[1]>arr[i])
				answer=0;
			newArr[i]=arr[i];
		}
		if(answer==0) printf("NO\n");
		else
		{
			insertionSort(newArr,n);
			if(check(arr,newArr,n))
				printf("YES\n");
			else printf("NO\n");
		}
	}
}
