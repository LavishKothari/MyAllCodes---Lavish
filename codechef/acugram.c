#include<stdio.h>
#include<string.h>
int c(const void*a,const void*b)
{
	return strcmp((const char*)a,(const char*)b);
}
int main()
{
	int t,i,n;
	char names[100][1001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",names[i]);
		qsort(names,n,1001,c);
		for(i=0;i<n;i++)
			printf("%s\n",names[i]);
	}
	return 0;
}
