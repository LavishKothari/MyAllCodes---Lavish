#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	int *arr;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int answer=0;
		for(int i=0;i<n;)
		{
			if(i+1<n && i+2<n && arr[i]==0 && arr[i+1]==0 && arr[i+2]==0)
			{
				i+=2;
				answer+=1;
			}
			else if(i+1<n && arr[i]==0 && arr[i+1]==0)
			{
				i++;
				answer+=1;
			}
			else i++;
		}
		printf("%d\n",answer);
		free(arr);
	}
}
