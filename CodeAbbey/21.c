#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n,*arr,num,i;
	scanf("%d%d",&m,&n);
	arr=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<=n;i++)
		arr[i]=0;
	while(m--)
	{
		scanf("%d",&num);
		arr[num]++;
	}
	for(i=1;i<=n;i++)
		printf("%d ",arr[i]);
	return 0;
}
