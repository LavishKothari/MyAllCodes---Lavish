#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	return a<b?a:b;
}
void rotate(int **arr,int m,int n,int start,int r)
{
	int len,*a,i,j,counter;
	len=2*(n-2*start)+(m-2-2*start)*2;
	r=r%len;
	a=(int*)malloc(sizeof(int)*len);
	counter=0;
	for(j=start;j<n-start;j++)
		a[counter++]=arr[start][j];
	for(i=start+1;i<m-start;i++)
		a[counter++]=arr[i][n-start-1];
	for(j=n-start-2;j>=start;j--)
		a[counter++]=arr[m-start-1][j];
	for(i=m-start-2;i>start;i--)
		a[counter++]=arr[i][start];
	
	counter=r;
	for(j=start;j<n-start;j++,counter=(counter+1)%len)
		arr[start][j]=a[counter];
	for(i=start+1;i<m-start;i++,counter=(counter+1)%len)
		arr[i][n-start-1]=a[counter];
	for(j=n-start-2;j>=start;j--,counter=(counter+1)%len)
		arr[m-start-1][j]=a[counter];
	for(i=m-start-2;i>start;i--,counter=(counter+1)%len)
		arr[i][start]=a[counter];
	
	free(a);
}
int main()
{
	int m,n,r,i,**arr,j;
	
	scanf("%d%d%d",&m,&n,&r);
	arr=(int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++)
		arr[i]=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	for(i=0;i<min(m,n)/2;i++)
		rotate(arr,m,n,i,r);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
}
