#include<stdio.h>
#include<stdlib.h>

int cfun (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int findNumberOfUnique(int arr[],int a,int b)
{
	int prevElement,i,j,count=0;
	int *newArr;
	newArr=(int*)malloc(sizeof(int)*(b-a+1));
	for(i=0;i<(b-a+1);i++)
	    newArr[i]=arr[i+a];
	qsort(newArr, (b-a+1), sizeof(int), cfun);
	count=1;
	prevElement=newArr[0];
	for(i=0;i<(b-a+1);i++)
	{
	    while(i<b-a+1 && newArr[i]==prevElement)
	        i++;
	    if(i!=b-a+1)
	    {
	        count++;
	        prevElement=newArr[i];
	    }
	}
	free(newArr);
	return count;
}

int main()
{
	int n,*arr,i,q,a,b,answer;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&q);
	answer=0;
	while(q--)
	{
		scanf("%d%d",&a,&b);
		a--;b--;
		a+=answer;
		answer=findNumberOfUnique(arr,a,b);
		printf("%d\n",answer);
	}
	return 0;
}
