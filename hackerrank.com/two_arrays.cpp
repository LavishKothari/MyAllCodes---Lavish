#include<stdio.h>
#include<stdlib.h>
int c1(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int c2(const void*a,const void*b)
{
	return *(int*)b-*(int*)a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int*a=(int*)malloc(sizeof(int)*n);
		int*b=(int*)malloc(sizeof(int)*n);

		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		qsort(a,n,sizeof(int),c1);
		qsort(b,n,sizeof(int),c2);
		int i;
		for(i=0;i<n;i++)
			if(a[i]+b[i]<k)
				break;
		if(i!=n)
			printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
