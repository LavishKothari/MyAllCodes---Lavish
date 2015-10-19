#include<stdio.h>
#include<stdlib.h>
int main()
{
	int flag[10],*answer,x,y;
	int n,**arr,i,j,q,a,b,c,d,counter=0;
	for(i=1;i<=10;i++)
		flag[i]=0;
	scanf("%d",&n);
	arr=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		arr[i]=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)	
			scanf("%d",&arr[i][j]);

	scanf("%d",&q);
	answer=(int*)malloc(sizeof(int)*q);
	for(i=0;i<q;i++)
	{
		counter=0;		
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a--;b--;c--;d--;
		for(x=a;x<=c;x++)
			for(y=b;y<=d;y++)
				flag[arr[x][y]]++;

		for(x=1;x<=10;x++)
			if(flag[x]>=1)
			{
				counter++;
				flag[x]=0;
			}

		answer[i]=counter;
	}
	for(i=0;i<q;i++)
		printf("%d\n",answer[i]);

	return 0;
}
