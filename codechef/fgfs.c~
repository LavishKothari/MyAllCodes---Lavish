
#include<stdlib.h>
#include<stdio.h>
struct Job
{
	int s,f,number,p;
};

int cmpfunc(const void*a,const void*b)
{
	return (*((struct Job*)a)).f-(*((struct Job*)b)).f;
}

int main()
{
	struct Job *jobs;
	int n,i,k,t,answer=0,prevf;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(n==0)
		{
			printf("0\n");
			continue;
		}jobs=(struct Job*)malloc(sizeof(struct Job)*n);
		for(i=0;i<n;i++)
		{
			jobs[i].number=i;
			scanf("%d%d%d",&jobs[i].s,&jobs[i].f,&jobs[i].p);
		}
		qsort(jobs,n,sizeof(struct Job),cmpfunc);
		answer=1;
		prevf=jobs[0].f;
		for(i=1;i<n;i++)
		{
			if(jobs[i].s>=prevf)
			{
				answer++;
				//printf("%d ",jobs[i].number);
				prevf=jobs[i].f;
			}
		}	
		printf("%d\n",answer);
	}
	
	
	return 0;
}
