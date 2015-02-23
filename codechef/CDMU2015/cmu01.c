#include<stdio.h>

int findMaxIndex(int arr[],int flag[])
{
	int max=0,i,maxIndex;
	for(i=0;i<10;i++)
	{
		if(flag[i])
		{
			if(arr[i]>max)
			{
				max=arr[i];
				maxIndex=i;
			}
		}
	}
	flag[maxIndex]=0;
	return maxIndex;
}
int findMinIndex(int arr[],int flag[])
{
	int min=100001,i,minIndex;
	for(i=0;i<10;i++)
	{
		if(flag[i])
		{
			if(arr[i]<min)
			{
				min=arr[i];
				minIndex=i;
			}
		}
	}
	flag[minIndex]=0;
	return minIndex;
}
void printIndexedName(int index)
{
	switch(index)
	{
		case 0:printf("Dhaval\n");break;
		case 1:printf("Shivang\n");break;
		case 2:printf("Bhardwaj\n");break;
		case 3:printf("Rishab\n");break;
		case 4:printf("Maji\n");break;
		case 5:printf("Gaurav\n");break;
		case 6:printf("Dhruv\n");break;
		case 7:printf("Nikhil\n");break;
		case 8:printf("Rohan\n");break;
		case 9:printf("Ketan\n");break;
	}
}
int main()
{
	int arr[10],flag[10],i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
		flag[i]=1;
	}
	for(i=0;i<5;i++)
	{
		printIndexedName(findMaxIndex(arr,flag));
		printIndexedName(findMinIndex(arr,flag));
	}
	return 0;
}
