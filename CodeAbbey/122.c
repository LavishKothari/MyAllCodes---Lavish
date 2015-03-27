#include<stdio.h>
#include<stdlib.h>
int partition(int*arr,int left,int right)
{
	int lt,rt,pivot,dir;
	lt=left;
	rt=right;
	dir=1;
	pivot=arr[left];
	while(lt<rt)
	{
		if(dir==1)
		{
			if(arr[rt]>pivot)
				rt--;
			else
			{
				arr[lt]=arr[rt];
				lt++;
				dir=0;
			}
		}
		else
		{
			if(arr[lt]<pivot)
				lt++;
			else
			{
				arr[rt]=arr[lt];
				rt--;
				dir=1;
			}
		}
	}
	arr[lt]=pivot;
	return lt;
}

void quickSort(int*arr,int left,int right)
{
	int pivot_pos=partition(arr,left,right);
	printf("%d-%d ",left,right);
	if(pivot_pos-left>1)
		quickSort(arr,left,pivot_pos-1);
	if(right-pivot_pos>1)
		quickSort(arr,pivot_pos+1,right);
}

int main()
{
	int i,*arr,n;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quickSort(arr,0,n-1);
	//for(i=0;i<n;i++)
	//	printf("%d ",arr[i]);
	return 0;
}
