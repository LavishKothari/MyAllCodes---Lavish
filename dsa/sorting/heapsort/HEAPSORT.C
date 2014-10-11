#include<stdio.h>
#include<conio.h>

void heapsort(int *,int);
void buildheap(int*,int,int,int);

int main()
{
	int i,n,*arr;


	printf("enter the maximum number of elements");
	scanf("%d",&n);

	printf("enter the data of array:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);

	heapsort(arr,n);

	printf("\nthe sorted array is as follows:\n");
	for(i=1;i<=n;i++)
		printf("%d\t",arr[i]);


	getch();
	return 1;
}

void heapsort(int*arr,int n)
{
	int tmp,i;
	for(i=n/2;i>0;i--)
		buildheap(arr,arr[i],i,n);

	for(i=n;;i--)
	{
		tmp=arr[i];
		arr[i]=arr[1];
		arr[1]=tmp;
		if(i<=2)
			break;
		buildheap(arr,tmp,1,i-1);
	}
}

//function for building the heap
void buildheap(int*arr,int val,int pos, int limit)
{
	int child;
	child=pos*2;
	if((arr[child]<arr[child+1])&&(child+1)<=limit)
		child++;
	while(child<=limit)
	{
		if(val>arr[child])
			break;
		arr[pos]=arr[child];
		pos=child;
		child=pos*2;
		if((arr[child]<arr[child+1])&&(child+1)<=limit)
			child++;
	}
	arr[pos]=val;
}
