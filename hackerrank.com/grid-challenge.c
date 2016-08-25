#include<stdio.h>
#include<stdlib.h>
#define MAX 101
char m[MAX][MAX];int n;
int cmp(const void*a, const void*b)
{
	return *(char*)a-*(char*)b;
}
int findAnswer()
{
	int i,j;
	for(i=0;i<n;i++)
		qsort(m[i],n,sizeof(char),cmp);
	for(j=0;j<n;j++)
		for(i=1;i<n;i++)
			if(m[i][j]<m[i-1][j])
				return 0;
	return 1;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf(" %s",m[i]);
		if(findAnswer())
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
