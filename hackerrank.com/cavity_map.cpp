#include<stdio.h>
#include<malloc.h>
int main()
{
	int n;
	scanf("%d",&n);
	char **arr,**newArr;
	
	arr=(char**)malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++)
		arr[i]=(char*)malloc(sizeof(char)*n);
	
	newArr=(char**)malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++)
		newArr[i]=(char*)malloc(sizeof(char)*n);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf(" %c",&arr[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==0 || j==0 || i==n-1 || j==n-1)
				newArr[i][j]=arr[i][j];
			else if(arr[i][j]>arr[i+1][j] && arr[i][j]>arr[i][j+1] && arr[i][j]>arr[i-1][j] && arr[i][j]>arr[i][j-1])
				newArr[i][j]='X';
			else newArr[i][j]=arr[i][j];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%c",newArr[i][j]);
		printf("\n");
	}
	return 0;
}
