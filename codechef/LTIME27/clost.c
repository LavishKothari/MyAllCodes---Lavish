#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *arr;
	int t,i,k,n,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		arr=(char*)malloc(sizeof(char)*n);
		for(i=0;i<n;i++)
			arr[i]='a';
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&a,&b);
			arr[a]='(';
			arr[b]=')';
		}
		for(i=0;i<n;i++)
			printf("%c",arr[i]);
		free(arr);
		printf("\n");
	}
	return 0;
}
