#include<stdio.h>
#include<stdlib.h>
struct job
{
	int s,f;
};
int cmp(const void*a,const void*b)
{
	struct job x,y;
	x=*(struct job*)a;
	y=*(struct job*)b;
	return x.f-y.f;
}
int main()
{
	struct job*jobs;
	int t,pfinish,i,n,counter;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		jobs=(struct job*)malloc(sizeof(struct job)*n);
		for(i=0;i<n;i++)
			scanf("%d%d",&jobs[i].s,&jobs[i].f);
		qsort(jobs,n,sizeof(struct job),cmp);
		counter=1;
		pfinish=jobs[0].f;
		
		for(i=1;i<n;i++)
		{
			if(jobs[i].s>=pfinish)
			{
				counter++;
				pfinish=jobs[i].f;
			}
		}
		printf("%d\n",counter);
	}
	return 0;
}
