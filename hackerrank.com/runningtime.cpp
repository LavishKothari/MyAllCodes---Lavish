#include<stdio.h>
int findAnswer(int*arr,int n)
{
	int shift=0;
	for(int i=1;i<n;i++)
	{
		int val=arr[i];int j;
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>val)
			{
				shift++;
				arr[j+1]=arr[j];
			}
			else break;
		}
		arr[j+1]=val;
	}
	return shift;
}
int main()
{
	int n;
	scanf("%d",&n);
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("%d\n",findAnswer(arr,n));
	return 0;
}
