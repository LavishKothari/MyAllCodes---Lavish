#include<stdio.h>

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int*arr,*allocated,*pre;
	arr=new int[n];
	allocated=new int[n];
	pre=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int answer=0,counter=0;
	int pages=0,i;
	for(int chapter=0;chapter<n;chapter++)
	{
		int q=arr[chapter];
		for(i=0;i<q/k;i++)
		{
			pre[pages]=k*i+1;
			printf("This is a test %d= %d\n",pages,pre[pages]);
			allocated[pages++]=k*(i+1);
		}
		if(pages-1<0 || allocated[pages-1]!=q)
		{
			pre[pages]=k*(i)+1;
			printf("This is a test %d= %d\n",pages,pre[pages]);
			allocated[pages++]=q;
		}
	}
	for(i=0;i<pages;i++)
		printf("%d = (%d,%d)\n",i,pre[i],allocated[i]);
	return 0;
}
